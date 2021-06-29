#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/ide.h>
#include <linux/io.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/irq.h>
#include <linux/of_irq.h>
#include <linux/delay.h>
#include <linux/input.h>
#include <linux/input/mt.h>
#include <linux/irq.h>
#include <linux/of_irq.h>
#include <linux/kthread.h>

#include "semi_touch_apk.h"
#include "semi_touch_device.h"
#include "semi_touch_function.h"
#include "semi_touch_custom.h"
#include "semi_touch_upgrade.h"

struct sm_touch_dev st_dev = {
    .stc.initialize_ok = false, 
    .stc.ctp_run_status = 0,
    .stc.custom_function_en = 0,
};

// static struct task_struct *int_thread = NULL;
// static DECLARE_WAIT_QUEUE_HEAD(waiter);
// static int int_trigger_flag = 0;

static int input_device_init(struct sm_touch_dev *st_dev)
{
    int ret = 0;
    struct i2c_client *client = st_dev->client;

    st_dev->input = devm_input_allocate_device(&st_dev->client->dev);
    check_return_if_fail(st_dev->input, NULL);

    st_dev->input->name = client->name;
    st_dev->input->id.bustype = BUS_I2C;
    st_dev->input->dev.parent = &client->dev;


    // __set_bit(EV_KEY, st_dev->input->evbit);
    // __set_bit(EV_ABS, st_dev->input->evbit);
    // __set_bit(BTN_TOUCH, st_dev->input->keybit);

    st_dev->input->evbit[0] = BIT_MASK(EV_SYN) | BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
    st_dev->input->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
    __set_bit(INPUT_PROP_DIRECT, st_dev->input->propbit);

    //input_set_abs_params(st_dev->input, ABS_X, 0, SEMI_TOUCH_SOLUTION_X, 0, 0);
    //input_set_abs_params(st_dev->input, ABS_Y, 0, SEMI_TOUCH_SOLUTION_Y, 0, 0);
    input_set_abs_params(st_dev->input, ABS_MT_POSITION_X, 0, SEMI_TOUCH_SOLUTION_X, 0, 0);
    input_set_abs_params(st_dev->input, ABS_MT_POSITION_Y, 0, SEMI_TOUCH_SOLUTION_Y, 0, 0);
    input_set_abs_params(st_dev->input, ABS_MT_WIDTH_MAJOR, 0, 255, 0, 0);
    input_set_abs_params(st_dev->input, ABS_MT_TOUCH_MAJOR, 0, 255, 0, 0);
    

    //ret = input_mt_init_slots(st_dev->input, SEMI_TOUCH_MAX_POINTS, 16/*INPUT_MT_DIRECT*/);
    //check_return_if_fail(ret, NULL);

#if MULTI_PROTOCOL_TYPE_A == MULTI_PROTOCOL_TYPE
    input_set_abs_params(st_dev->input, ABS_MT_TRACKING_ID, 0, 255, 0, 0);
#elif MULTI_PROTOCOL_TYPE_B == MULTI_PROTOCOL_TYPE
    input_mt_init_slots(st_dev->input, SEMI_TOUCH_MAX_POINTS, INPUT_MT_DIRECT /*1*/);
#endif

    ret = input_register_device(st_dev->input);
    check_return_if_fail(ret, NULL);

    ret = semi_touch_i2c_init();
    check_return_if_fail(ret, NULL);

    return 0;
}

static int input_device_deinit(void)
{
    int ret = 0;

    ret = semi_touch_i2c_i2c_exit();

    if(st_dev.input)
    {
        input_unregister_device(st_dev.input);  
    }

    return ret;  
}


static irqreturn_t semi_touch_irq_handler_imp(int irq, void *p)
{
    bool pointed = 0;
    int  index = 0, pointNum = 0/*, ioLevel = 0*/;
    union rpt_point_t* ppt;
    static unsigned char readbuffer[84];
    const unsigned char report_size = ((SEMI_TOUCH_MAX_POINTS * 5 + 2) + 3) & 0xfc;

    //kernel_log_d("st_dev.stc.ctp_run_status = 0x%x\n", st_dev.stc.ctp_run_status);

    //ioLevel = semi_io_pin_level(st_dev.int_pin);
    //if(1 == ioLevel) return IRQ_RETVAL(IRQ_HANDLED);

    if(!ack_pointing_action(st_dev.stc.ctp_run_status)) return IRQ_RETVAL(IRQ_HANDLED);

    if((int)read_and_report_touch_points(readbuffer, report_size) >= 0)
    {
        //int & iic is ok, dog feed
        semi_touch_watch_dog_feed(st_dev.stc.dog_feed_flag);

        pointNum = (readbuffer[1] & 0x0f);
        ppt = (union rpt_point_t*)&readbuffer[2];

        if(0xFD == readbuffer[0]) 
        {
            //firmware report heatbeat packet
            return IRQ_RETVAL(IRQ_HANDLED);
        }
        else if(0xFC == readbuffer[0])
        {
            return semi_touch_proximity_report(readbuffer[1]);
        }
        else if(0xFE == readbuffer[0])
        {
            return semi_touch_gesture_report(readbuffer[1]);
        }
        else if(0 == pointNum)
        {
            return semi_touch_clear_report();
        }

#if MULTI_PROTOCOL_TYPE_A == MULTI_PROTOCOL_TYPE
        for(index = 0; index < SEMI_TOUCH_MAX_POINTS; index++)
        { 
            pointed = (0x08 == ppt->rp.event) ? true : false;

            if(ppt->rp.id != 0x0f)
            {
                if(pointed)
                {
                    input_report_key(st_dev.input, BTN_TOUCH, 1);
                    input_report_abs(st_dev.input, ABS_MT_POSITION_X, (unsigned int)(ppt->rp.x_h4 << 8) | ppt->rp.x_l8);
                    input_report_abs(st_dev.input, ABS_MT_POSITION_Y, (unsigned int)(ppt->rp.y_h4 << 8) | ppt->rp.y_l8);
                    input_report_abs(st_dev.input, ABS_MT_TOUCH_MAJOR, ppt->rp.z);
                    input_report_abs(st_dev.input, ABS_MT_WIDTH_MAJOR, ppt->rp.z);
                    input_report_abs(st_dev.input, ABS_MT_TRACKING_ID, ppt->rp.id);
                    input_mt_sync(st_dev.input);
                }
                else
                {
                }
            }
            ppt++;
        }
#elif MULTI_PROTOCOL_TYPE_B == MULTI_PROTOCOL_TYPE
        for(index = 0; index < SEMI_TOUCH_MAX_POINTS; index++)
        { 
            pointed = (0x08 == ppt->rp.event) ? true : false;

            if(ppt->rp.id != 0x0f)
            {
                input_mt_slot(st_dev.input, ppt->rp.id);
                input_mt_report_slot_state(st_dev.input, MT_TOOL_FINGER, pointed);
                if(pointed)
                {
                    input_report_abs(st_dev.input, ABS_MT_POSITION_X, (unsigned int)(ppt->rp.x_h4 << 8) | ppt->rp.x_l8);
                    input_report_abs(st_dev.input, ABS_MT_POSITION_Y, (unsigned int)(ppt->rp.y_h4 << 8) | ppt->rp.y_l8);
                    input_report_abs(st_dev.input, ABS_MT_TOUCH_MAJOR, ppt->rp.z);
                    input_report_abs(st_dev.input, ABS_MT_WIDTH_MAJOR, ppt->rp.z);
                    input_report_key(st_dev.input, BTN_TOUCH, 1);
                }
                else
                {
                }
            }
            ppt++;
        }
#endif
    }
    //input_mt_report_pointer_emulation(st_dev.input, true);
    input_sync(st_dev.input);

    return IRQ_RETVAL(IRQ_HANDLED);
}

#if SEMI_TOUCH_IRQ_VAR_QUEUE
static void semi_touch_irq_work_fun(struct work_struct *work)
{
    semi_touch_irq_handler_imp(st_dev.client->irq, &st_dev);
}

static irqreturn_t semi_touch_irq_handler(int irq, void *p)
{
    semi_touch_queue_asyn_work(work_queue_interrupt, semi_touch_irq_work_fun);

    return IRQ_RETVAL(IRQ_HANDLED);
}
#endif

irqreturn_t semi_touch_clear_report(void)
{
#if MULTI_PROTOCOL_TYPE_A == MULTI_PROTOCOL_TYPE
    input_report_key(st_dev.input, BTN_TOUCH, 0);
    input_mt_sync(st_dev.input);
    input_sync(st_dev.input);
#elif MULTI_PROTOCOL_TYPE_B == MULTI_PROTOCOL_TYPE
    int index = 0;
    for(index = 0; index < SEMI_TOUCH_MAX_POINTS; index++)
    {
        input_mt_slot(st_dev.input, index);
        input_mt_report_slot_state(st_dev.input, MT_TOOL_FINGER, false);
        
    }
    input_report_key(st_dev.input, BTN_TOUCH, 0);
    input_sync(st_dev.input);
#endif
    
    return IRQ_RETVAL(IRQ_HANDLED);
}

static int semi_touch_irq_init(struct sm_touch_dev *st_dev)
{
    int ret = 0;
    struct i2c_client *client = st_dev->client;

    client->irq = semi_touch_get_irq(st_dev->int_pin);
    check_return_if_fail(client->irq, NULL);

    semi_touch_create_work_queue(work_queue_custom_work, typename(work_queue_custom_work));

#if SEMI_TOUCH_IRQ_VAR_QUEUE
    semi_touch_create_work_queue(work_queue_interrupt, typename(work_queue_interrupt));
    ret = request_irq(client->irq, semi_touch_irq_handler, IRQF_TRIGGER_FALLING | IRQF_ONESHOT, client->name, st_dev);
#else
    ret = devm_request_threaded_irq(&client->dev, client->irq, NULL, semi_touch_irq_handler_imp, IRQF_TRIGGER_FALLING | IRQF_ONESHOT, client->name, st_dev);
#endif
    check_return_if_fail(ret, NULL);

    return 0;
}

int semi_touch_resolution_adaption(struct sm_touch_dev *st_dev)
{
    int ret = -SEMI_DRV_ERR_HAL_IO;
    unsigned char readbuffer[0x0c] = {0};

    ret = semi_touch_read_bytes(0x20000080, readbuffer, sizeof(readbuffer));
    check_return_if_fail(ret, NULL);

    //pix 
    input_set_abs_params(st_dev->input, ABS_MT_POSITION_X, 0, (unsigned short)((readbuffer[0x07] << 8) + readbuffer[0x06]), 0, 0);
    input_set_abs_params(st_dev->input, ABS_MT_POSITION_Y, 0, (unsigned short)((readbuffer[0x09] << 8) + readbuffer[0x08]), 0, 0);

    kernel_log_d("resolution = (%d, %d)\n", (unsigned short)((readbuffer[0x07] << 8) + readbuffer[0x06]), (unsigned short)((readbuffer[0x09] << 8) + readbuffer[0x08]));

    return ret;
}

int semi_touch_init(struct i2c_client *client)
{
    int ret = 0;
    memset(&st_dev, 0, sizeof(st_dev));
    st_dev.client = client;

    st_dev.int_pin = semi_touch_get_int();
    check_return_if_fail(st_dev.int_pin, NULL);
    st_dev.rst_pin = semi_touch_get_rst();
    check_return_if_fail(st_dev.rst_pin, NULL);

    semi_io_direction_in(st_dev.int_pin);
    semi_io_direction_out(st_dev.rst_pin, 1);

    mutex_init(&st_dev.hal.bus_lock);

    st_dev.hal.hal_write_fun = i2c_write_bytes;
    st_dev.hal.hal_read_fun = i2c_read_bytes;
    st_dev.hal.hal_param = client;

    ret = input_device_init(&st_dev);
    check_return_if_fail(ret, NULL);

	ret = semi_touch_device_prob();
	check_return_if_fail(ret, NULL);

	ret = semi_touch_bootup_update_check();
	check_return_if_fail(ret, NULL);

    ret = semi_touch_mode_init(&st_dev);
    check_return_if_fail(ret, NULL);

    ret = semi_touch_resolution_adaption(&st_dev);
    check_return_if_fail(ret, NULL);

    ret = semi_touch_create_apk_proc(&st_dev);
    check_return_if_fail(ret, NULL);

    ret = semi_touch_irq_init(&st_dev);
    check_return_if_fail(ret, NULL);

    ret = semi_touch_custom_work(&st_dev);
    check_return_if_fail(ret, NULL);

    ret = semi_touch_work_done();
    check_return_if_fail(ret, NULL);

    return ret;
}

int semi_touch_deinit(struct i2c_client *client)
{
    int ret = 0;

    ret = semi_touch_custom_clean_up();
    check_return_if_fail(ret, NULL);

    ret = semi_touch_destroy_work_queue();
    check_return_if_fail(ret, NULL);

    ret = semi_touch_remove_apk_proc(&st_dev);
    check_return_if_fail(ret, NULL);

    input_device_deinit();

    semi_touch_resource_release();

    return ret;
}