/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef __DISP_DTS_GPIO_H__
#define __DISP_DTS_GPIO_H__

/*
 * This module helps you to set GPIO pin according to linux device tree (DTS).
 * To use this module, you MUST init this module once before any operation.
 */

#include <linux/platform_device.h>	/* struct platform_device */

#ifndef VENDOR_EDIT
/* LiPing-m@PSW.MM.Display.LCD.Machine, 2017/11/03, Add for porting 17331 lcd driver */
/* LiPing-m@PSW.MM.Display.LCD.Machine, 2017/12/27, Add for porting 17197 lcd driver */

/* DTS state */
enum DTS_GPIO_STATE {
	DTS_GPIO_STATE_TE_MODE_GPIO = 0,/* mode_te_gpio */
	DTS_GPIO_STATE_TE_MODE_TE,	/* mode_te_te */
	DTS_GPIO_STATE_TE1_MODE_TE,	/* mode_te1_te */
	DTS_GPIO_STATE_LCM_RST_OUT0,
	DTS_GPIO_STATE_LCM_RST_OUT1,
	DTS_GPIO_STATE_LCM1_RST_OUT0,
	DTS_GPIO_STATE_LCM1_RST_OUT1,
	DTS_GPIO_STATE_LCD_BIAS_ENN,
	DTS_GPIO_STATE_LCD_BIAS_ENP,
	DTS_GPIO_STATE_MAX,		/* for array size */
};
#else /* VENDOR_EDIT */
enum DTS_GPIO_STATE {
	DTS_GPIO_STATE_TE_MODE_GPIO = 0,	/* mode_te_gpio */
	DTS_GPIO_STATE_TE_MODE_TE,	/* mode_te_te */
	DTS_GPIO_STATE_LCM_RST_OUT0,
	DTS_GPIO_STATE_LCM_RST_OUT1,
	DTS_GPIO_STATE_LCD_BIAS_ENP0,
	DTS_GPIO_STATE_LCD_BIAS_ENP1,
	DTS_GPIO_STATE_LCD_BIAS_ENN0,
	DTS_GPIO_STATE_LCD_BIAS_ENN1,
	DTS_GPIO_STATE_LCD_BL_EN0,
	DTS_GPIO_STATE_LCD_BL_EN1,
	DTS_GPIO_STATE_LCD_1P8_EN0,
	DTS_GPIO_STATE_LCD_1P8_EN1,
	DTS_GPIO_STATE_TE1_MODE_TE,
	DTS_GPIO_STATE_LCM1_RST_OUT0,
	DTS_GPIO_STATE_LCM1_RST_OUT1,
	DTS_GPIO_STATE_LCD_VCI_EN0,
	DTS_GPIO_STATE_LCD_VCI_EN1,
	DTS_GPIO_STATE_LCD_VPOC_EN0,
	DTS_GPIO_STATE_LCD_VPOC_EN1,
	DTS_GPIO_STATE_LCD_MIPI_ERR_EN0,
	DTS_GPIO_STATE_LCD_MIPI_ERR_EN1,
	DTS_GPIO_STATE_SPI_CSN_EN0,
	DTS_GPIO_STATE_SPI_CSN_EN1,
	DTS_GPIO_STATE_MAX,	/* for array size */
};
#endif /* VENDOR_EDIT */

/* this function MUST be called in mtkfb_probe.
 *  @param *pdev    - reference of struct platform_device which contains pinctrl
 *                    state information of GPIO
 *  @return         - 0 for OK, otherwise returns PTR_ERR(pdev).
 */
long disp_dts_gpio_init(struct platform_device *pdev);

/**
 * set gpio according sepcified DTS state.
 *  @notice         - to call this function, you MUST init this module first.
 *                    If not, we will trigger BUG_ON(0).
 *  @param s        - state which describes GPIO statement.
 *  @return         - 0 for OK, otherwise returns PTR_ERR(pdev).
 */
long disp_dts_gpio_select_state(enum DTS_GPIO_STATE s);

/* repo of initialization */
#ifdef CONFIG_MTK_LEGACY
#define disp_dts_gpio_init_repo(x)  (0)
#else
#define disp_dts_gpio_init_repo(x)  (disp_dts_gpio_init(x))
#endif

#endif /* __DISP_DTS_GPIO_H__ */
