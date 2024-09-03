/**************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
*
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2017 Renesas Electronics Corporation. All rights reserved.
***************************************************************************/

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_ostm.h"

#include "r_ostm_reg.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define OSTM_NUM                        10UL
#define CKSEL_NUM                       2UL

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global static variables
 *****************************************************************************/
static uint32 Gsu4Ostm[OSTM_NUM] = {
    OSTM0,
    OSTM1,
    OSTM2,
    OSTM3,
    OSTM4,
    OSTM5,
    OSTM6,
    OSTM7,
    OSTM8,
    OSTM9,
};

static uint32 Gsu4CkSel[CKSEL_NUM] = {
    0xFFBF08C0UL,
    0xFFBF09C0UL
};

/*****************************************************************************
 Static functions
 *****************************************************************************/

/*****************************************************************************
--------------------- Global functions --------------------------------------
 *****************************************************************************/
/*****************************************************************************
 * Declaration : void R_OSTM_InitCtl(uint8 Pu1Ostm, uint8 Pu1Cfg)
 * Description : OSTM Initialize.
 * Parameters  : Pu1Ostm - OSTM
 *               Pu1Cfg  - OSTM configuration
 * Return      : None
 *****************************************************************************/
void R_OSTM_InitCtl(uint8 Pu1Ostm, uint8 Pu1Cfg)
{
    do {
        CTL(Gsu4Ostm[Pu1Ostm]) = Pu1Cfg;
    } while (Pu1Cfg != CTL(Gsu4Ostm[Pu1Ostm]));  
}

/*****************************************************************************
 * Declaration : void R_OSTM_SetCmp(uint8 Pu1Ostm, uint32 Pu4CmpVal)
 * Description : Set OSTM Compare value.
 * Parameters  : Pu1Ostm   - OSTM
 *               Pu4CmpVal - Compare value 
 * Return      : None
 *****************************************************************************/
void R_OSTM_SetCmp(uint8 Pu1Ostm, uint32 Pu4CmpVal)
{
    CMP(Gsu4Ostm[Pu1Ostm]) = Pu4CmpVal;
}

/*****************************************************************************
 * Declaration : void R_OSTM_Start(uint8 Pu1Ostm)
 * Description : Start OSTM.
 * Parameters  : Pu1Ostm - OSTM
 * Return      : None
 *****************************************************************************/
void R_OSTM_Start(uint8 Pu1Ostm)
{
    TS(Gsu4Ostm[Pu1Ostm]) = 0x01U;
}

/*****************************************************************************
 * Declaration : void R_OSTM_Stop(uint8 Pu1Ostm)
 * Description : Stop OSTM.
 * Parameters  : Pu1Ostm - OSTM
 * Return      : None
 *****************************************************************************/
void R_OSTM_Stop(uint8 Pu1Ostm)
{
    TT(Gsu4Ostm[Pu1Ostm]) = 0x01U;
}

/*****************************************************************************
 * Declaration : void R_OSTM_SetClkSel(uint8 Pu1Ostm, uint16 Pu2Cfg)
 * Description : Set OSTM8/9 clock.
 * Parameters  : Pu1Ostm - OSTM
 *               Pu2Cfg  - OSTM clock configuration
 * Return      : None
 *****************************************************************************/
void R_OSTM_SetClkSel(uint8 Pu1Ostm, uint16 Pu2Cfg)
{
    REG16(Gsu4CkSel[Pu1Ostm]) = Pu2Cfg;
}

/*****************************************************************************
--------------------- Static functions --------------------------------------
 *****************************************************************************/
