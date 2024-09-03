
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
#include "r_mspi.h"
#include "r_mspi_reg.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/
static const uint32 Gscu4Mspi[] = {
    MSPI0_base,
    MSPI1_base,
    MSPI2_base,
    MSPI3_base,
    MSPI4_base,
    MSPI5_base
};

/*****************************************************************************
 Global static variables
 *****************************************************************************/

/*****************************************************************************
 Static functions
 *****************************************************************************/

/*****************************************************************************
--------------------- Global functions --------------------------------------
 *****************************************************************************/
/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
void R_MSPI_Global_Init(uint8 Pu1Unit)
{
    /* Set MSPI0 control setting */
    MSPI_CTL1(Gscu4Mspi[Pu1Unit]) = 0;
    MSPI_CTL2(Gscu4Mspi[Pu1Unit]) = 0;

    /* Enable MSPI operation */
    MSPI_CTL0(Gscu4Mspi[Pu1Unit]) = 0x01;
}
void R_MSPI_Channel_Init(uint8 Pu1Unit, uint8 Pu1Css, SpiChannelCfg PuStChCfg)
{
    /* Set MSPI0 configuration setting */
    MSPI_CFG0(Gscu4Mspi[Pu1Unit],Pu1Css) = PuStChCfg.u4CFG0;

    MSPI_CFG1(Gscu4Mspi[Pu1Unit],Pu1Css) = PuStChCfg.u4CFG1;
    /* seting Length */
    MSPI_CFG2(Gscu4Mspi[Pu1Unit],Pu1Css) = PuStChCfg.u2CFG2;

    MSPI_CFG3(Gscu4Mspi[Pu1Unit],Pu1Css) = PuStChCfg.u2CFG3;

    MSPI_CFG4(Gscu4Mspi[Pu1Unit],Pu1Css) = PuStChCfg.u4CFG4;

    MSPI_SEUP(Gscu4Mspi[Pu1Unit],Pu1Css) = PuStChCfg.u2SEUP;
    MSPI_HOLD(Gscu4Mspi[Pu1Unit],Pu1Css) = PuStChCfg.u2HOLD;
    MSPI_IDLE(Gscu4Mspi[Pu1Unit],Pu1Css) = PuStChCfg.u2IDLE;
    MSPI_INDA(Gscu4Mspi[Pu1Unit],Pu1Css) = PuStChCfg.u2INDA;
    MSPI_CFSET(Gscu4Mspi[Pu1Unit],Pu1Css) = PuStChCfg.u2CFSET;


    MSPI_SSEL(Gscu4Mspi[Pu1Unit],Pu1Css) = PuStChCfg.u2SSEL;
}

void R_MSPI_Write(uint8 Pu1Unit, uint8 Pu1Css, uint32* const Pu4TxBuff, uint32* Pu4RxBuff, const uint16 Pu2Len)
{
    uint16 Lu2Len = 0;
    uint16 Lu2RxReg = 0;
    uint32 Pu4Timeout = 20000;
    for(Lu2Len = 0U; Lu2Len < Pu2Len; Lu2Len += 2U)
    {
        MSPI_CSTS(Gscu4Mspi[Pu1Unit],Pu1Css) = CHENS | ACTFS;
        MSPI_TXDA0(Gscu4Mspi[Pu1Unit],Pu1Css) =  Pu4TxBuff[Lu2Len];
        do {
            Lu2RxReg = MSPI_CSTR(Gscu4Mspi[Pu1Unit],Pu1Css);
        } while ((0x01UL == (Lu2RxReg & 0x01UL)) && (Pu4Timeout--));
        Pu4RxBuff[Lu2Len] = MSPI_RXDA0(Gscu4Mspi[Pu1Unit],Pu1Css);
    }

    MSPI_CSTS(Gscu4Mspi[Pu1Unit],Pu1Css) = CHENS;
}



