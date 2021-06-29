/***************************************************
 * File:nvt_limit.h
 * VENDOR_EDIT
 * Copyright (c)  2017 - 2030  Oppo Mobile communication Corp.ltd.
 * Description:
 *             nova nt36525b test limit data
 * Version:1.0:
 * Date created:2017-09-15
 * Author: Cong.Dai@Bsp.Driver
 * TAG: BSP.TP.Init
 * *
 * -------------- Revision History: -----------------
 *  <author >  <data>  <version>  <desc>
 ***************************************************/

#ifndef NVT_H_LIMIT_NOFLASH
#define NVT_H_LIMIT_NOFLASH

//---Screen on test---
static uint32_t Doze_X_Channel = 2;
/*Doze FW Rawdata Test*/
static int32_t PS_Config_Lmt_Doze_Rawdata_P = 1000;
static int32_t PS_Config_Lmt_Doze_Rawdata_N = 200;
static int32_t PS_Config_Doze_Noise_Test_Frame = 50;
/*Doze Noise Test*/
static int32_t PS_Config_Lmt_Doze_Diff_P = 500;
static int32_t PS_Config_Lmt_Doze_Diff_N = -500;
/*FW cc data test*/
static int32_t PS_Config_Lmt_FW_CC_P = 100;
static int32_t PS_Config_Lmt_FW_CC_N = 70;
/*Noise Test*/
static int32_t PS_Config_Lmt_FW_Diff_P = 60;
static int32_t PS_Config_Lmt_FW_Diff_N = -60;
/*Short Test*/
static int32_t PS_Config_Lmt_Short_Rawdata_N = 11000;
static int32_t PS_Config_Lmt_Short_Rawdata_P = 14000;
static int32_t PS_Config_Diff_Test_Frame = 50;

//---LPWGModeTest---
static int32_t PS_Config_Lmt_LPWG_Rawdata_P = 1300;
static int32_t PS_Config_Lmt_LPWG_Rawdata_N = 500;
static int32_t PS_Config_Lmt_LPWG_Diff_P = 60;
static int32_t PS_Config_Lmt_LPWG_Diff_N = -60;

static uint8_t AIN_X[40] = {17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
static uint8_t AIN_Y[40] = {31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

/*FW Rawdata Test*/
static int32_t PS_Config_Lmt_FW_Rawdata_P[40 * 40] = {
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
    1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,
};

static int32_t PS_Config_Lmt_FW_Rawdata_N[40 * 40] = {
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,
};

/*Open Test*/
static int32_t PS_Config_Lmt_Open_Rawdata_P[40 * 40] = {
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
        13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,
};

static int32_t PS_Config_Lmt_Open_Rawdata_N[40 * 40] = {
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
        6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,6500,
};

#endif
