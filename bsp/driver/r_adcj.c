/******************************************************************************* 
* DISCLAIMER 
* This software is supplied by Renesas Electronics Corporation and is only  
* intended for use with Renesas products. No other uses are authorized. This  
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE  
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. 
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS  
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE  
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software. By using this software, 
* you agree to the additional terms and conditions found by accessing the  
* following link: 
* http://www.renesas.com/disclaimer 
* 
* Copyright (C) 2012, 2014 Renesas Electronics Corporation. All rights reserved.     
*******************************************************************************/
/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include    "r_adcj.h" 
#include    "r_adcj_reg.h" 
/*****************************************************************************
 Macro definitions
 *****************************************************************************/   
/*****************************************************************************
 Typedef definitions
 *****************************************************************************/  


/*****************************************************************************
 Global variables
 *****************************************************************************/
static uint32 Gsu4Adcj[3] = {
    ADCJ0_base,
    ADCJ1_base,
    ADCJ2_base
};
/*****************************************************************************
 Global static variables
 *****************************************************************************/
static uint16 Gu1ReadAdcValue[32] = {0};

/*****************************************************************************
 Static functions
 *****************************************************************************/

static void R_ADC_ScanGroupInit(uint8 Pu1Adc)
{
    /* 1.1.1 Disable SGx triggers */
    /* Disable A/D conversion start trigger input to scan group */
    ADCJ_SGSTCR(Gsu4Adcj[Pu1Adc], 0) = 0x00;
    ADCJ_SGSTCR(Gsu4Adcj[Pu1Adc], 1) = 0x00;
    ADCJ_SGSTCR(Gsu4Adcj[Pu1Adc], 2) = 0x00;
    ADCJ_SGSTCR(Gsu4Adcj[Pu1Adc], 3) = 0x00;
    ADCJ_SGSTCR(Gsu4Adcj[Pu1Adc], 4) = 0x00;

    /* 1.1.2 Halt all the scan groups, A/D conversions, and A/D timers */
    ADCJ_ADHALTR(Gsu4Adcj[Pu1Adc]) = 0x01;
}

static inline void R_ADC_VRChannel_Bind(uint8 Pu1Adc, uint8 Pu1VrCh, uint8 Pu1HwCh)
{
    ADCJ_VCR(Gsu4Adcj[Pu1Adc], Pu1VrCh) = 0x00000000 | Pu1HwCh;
}

static void R_ADC_SCanGroup_Bind(uint8 Pu1Adc, uint8 Pu1SG, uint8 Pu1VrChStart, uint8 Pu1VrChEnd)
{
    ADCJ_SGVCPR(Gsu4Adcj[Pu1Adc], Pu1SG) = (Pu1VrChStart) | (Pu1VrChEnd<<8);
    ADCJ_SGMCYCR(Gsu4Adcj[Pu1Adc], Pu1SG) = 0x00U;
}

static inline void R_ADC_ScanGroup_Start(uint8 Pu1Adc, uint8 Pu1SG)
{
    ADCJ_SGSTCR(Gsu4Adcj[Pu1Adc], Pu1SG) = 0x01U;
}

void R_ADCJ0_Init(void)
{
    /* 1 A/D conversion stop settings */
    R_ADC_ScanGroupInit(0);

    /* 2 Bind Vr/Hw Channel */
    R_ADC_VRChannel_Bind(0, 0, 0);
    R_ADC_VRChannel_Bind(0, 1, 1);
    R_ADC_VRChannel_Bind(0, 2, 2);
    R_ADC_VRChannel_Bind(0, 3, 3);

    /* 3 Bind SG and Vr Channel */
    R_ADC_SCanGroup_Bind(0, 0, 0, 3);

    /* 4 Set the read and clear enable */
    ADCJ_SFTCR(Gsu4Adcj[0]) = 0x10U;

    /* 5 Enable the output of the scan group x end interrupt signal ADInx */
    ADCJ_SGCR(Gsu4Adcj[0], 0) = 0x11U;
}

void R_ADCJ1_Init(void)
{
}

void R_ADCJ2_Init(void)
{
}

void R_ADCJ_ScanGroup_OperationOn(uint8 Pu1ADC, uint8 Pu1SGNum)
{
    R_ADC_ScanGroup_Start(Pu1ADC, Pu1SGNum);
}

void R_Drv_ADC_UpdateValue(uint8 Pu1ADC, uint8 Pu1SGNum)
{
    switch (Pu1SGNum)
    {
    case 0:
        {
            uint32 Lu4ADC_DR0 = ADCJ_DR(Gsu4Adcj[Pu1ADC], 0);
            uint32 Lu4ADC_DR1 = ADCJ_DR(Gsu4Adcj[Pu1ADC], 2);
            Gu1ReadAdcValue[0] = (uint16)Lu4ADC_DR0;
            Gu1ReadAdcValue[1] = (uint16)(Lu4ADC_DR0>>16);
            Gu1ReadAdcValue[2] = (uint16)Lu4ADC_DR1;
            Gu1ReadAdcValue[3] = (uint16)(Lu4ADC_DR1>>16);
        }
        break;
    
    default:
        break;
    }
}

