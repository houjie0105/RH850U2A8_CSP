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
#include "r_intc.h"

#include "r_intc_reg.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

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
 * Declaration : void R_INTC_Init(uint16 Pu2IntcX, uint16 Pu2Cfg)
 * Description : INTC Initialize.
 * Parameters  : Pu2IntcX - INTC number
 *               Pu2Cfg   - INTC configuration
 * Return      : None
 *****************************************************************************/
void R_INTC_Init(uint16 Pu2IntcX, uint16 Pu2Cfg)
{
    if (Pu2IntcX > 31UL)
    {
        INTC2_EIC(Pu2IntcX) = Pu2Cfg;
    }
    else
    {
        INTC1_EIC(Pu2IntcX) = Pu2Cfg;
    }
}
/*****************************************************************************
 * Declaration : void R_INTC_Bind(uint16 Pu2IntcX, uint32 Pu4Cfg)
 * Description : INTC Initialize.
 * Parameters  : Pu2IntcX - INTC number
 *               Pu4Cfg   - INTC configuration
 * Return      : None
 *****************************************************************************/
void R_INTC_Bind(uint16 Pu2IntcX, uint32 Pu4Cfg)
{
    if (Pu2IntcX > 31UL)
    {
        INTC2_EIBD(Pu2IntcX) = Pu4Cfg;
    }
    else
    {
        INTC1_EIBD(Pu2IntcX) = Pu4Cfg;
    }
}

/*****************************************************************************
--------------------- Static functions --------------------------------------
 *****************************************************************************/
