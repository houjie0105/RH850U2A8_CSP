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
#include "r_port.h"

#include "r_port_reg.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define PKCPROT_ENABLE          0xA5A5A501UL
#define PKCPROT_DISABLE         0xA5A5A500UL
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
 * Declaration : void R_PORT_EnablePort(void)
 * Description : Enable port.
 * Parameters  : None
 * Return      : None
 *****************************************************************************/
void R_PORT_EnablePort(void)
{
    PKCPROT = PKCPROT_ENABLE;
    PWE = 0xFFFFFFFFUL;
    PKCPROT = PKCPROT_DISABLE;
}

/*****************************************************************************
 * Declaration : void R_PORT_DisablePort(void)
 * Description : Disable port.
 * Parameters  : None
 * Return      : None
 *****************************************************************************/
void R_PORT_DisablePort(void)
{
    PKCPROT = PKCPROT_ENABLE;
    PWE = 0x00UL;
    PKCPROT = PKCPROT_DISABLE;
}

/*****************************************************************************
 * Declaration : void R_PORT_Init(uint8 Pu1Port, uint8 Pu1Pin, uint32 Pu4Setting)
 * Description : IO Initialize.
 * Parameters  : Pu1Port    - Port
 *               Pu1Pin     - Pin
 *               Pu4Setting - Setting
 * Return      : None
 *****************************************************************************/
void R_PORT_Init(uint8 Pu1Port, uint8 Pu1Pin, uint32 Pu4Setting)
{
    PCR(Pu1Port, Pu1Pin) = Pu4Setting;
}

/*****************************************************************************
 * Declaration : uint32 R_PORT_ReadPin(uint8 Pu1Port, uint8 Pu1Pin)
 * Description : IO read pin.
 * Parameters  : Pu1Port    - Port
 *               Pu1Pin     - Pin
 * Return      : Pin state
 *****************************************************************************/
uint32 R_PORT_ReadPin(uint8 Pu1Port, uint8 Pu1Pin)
{
    return !!((PCR(Pu1Port, Pu1Pin) & PORT_PPR)) ;
}

/*****************************************************************************
 * Declaration : void R_PORT_WritePin(uint8 Pu1Port, uint8 Pu1Pin, uint8 Pu1State)
 * Description : IO write pin.
 * Parameters  : Pu1Port    - Port
 *               Pu1Pin     - Pin
 *               Pu1State   - State
 * Return      : None
 *****************************************************************************/
void R_PORT_WritePin(uint8 Pu1Port, uint8 Pu1Pin, uint8 Pu1State)
{
    uint32 Lu4PCRValue = PCR(Pu1Port, Pu1Pin);
    if (Pu1State)
    {
        Lu4PCRValue |= PORT_P;
    }
    else
    {
        Lu4PCRValue &= ~PORT_P;
    }
    PCR(Pu1Port, Pu1Pin) = Lu4PCRValue;
}

/*****************************************************************************
 * Declaration : void R_PORT_FlipPin(uint8 Pu1Port, uint8 Pu1Pin)
 * Description : IO flip pin.
 * Parameters  : Pu1Port    - Port
 *               Pu1Pin     - Pin
 * Return      : None
 *****************************************************************************/
void R_PORT_FlipPin(uint8 Pu1Port, uint8 Pu1Pin)
{
    uint32 Lu4PCRValue = PCR(Pu1Port, Pu1Pin);
    if (Lu4PCRValue &= PORT_PINV)
    {
        Lu4PCRValue &= ~PORT_PINV;
    }
    else
    {
        Lu4PCRValue |= PORT_PINV;
    }
    PCR(Pu1Port, Pu1Pin) = Lu4PCRValue;
}

/*****************************************************************************
--------------------- Static functions --------------------------------------
 *****************************************************************************/
