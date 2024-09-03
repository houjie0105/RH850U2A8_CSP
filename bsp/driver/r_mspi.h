
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
#ifndef R_MSPI_H
#define R_MSPI_H

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define TXE  (0x02<<28)
#define RXE  (0x01<<28)
#define TRXE (0x03<<28)

#define MODE_DIRECT_MEM (0<<24)
#define MODE_FIXED_BUFF (1<<24)
#define MODE_FIXED_FIFO (1<<24)

#define IERE (1<<3)
#define IFEE (1<<2)
#define IRXE (1<<1)
#define ITXE (1<<0)


#define CSS0 (1<<0)
#define CSS1 (1<<1)
#define CSS2 (1<<2)
#define CSS3 (1<<3)
#define CSS4 (1<<4)
#define CSS5 (1<<5)
#define CSS6 (1<<6)
#define CSS7 (1<<7)

#define CHENS (0x01)
#define ACTFS (0x02)

#define CSRI_INACTIVE (1 << 16)
#define CSRI_ACTIVE   (0 << 16)

#define CPHA  (1<<24)
#define CPOL  (1<<25)


/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/
typedef struct STag_SpiChannelCfgType
{
    uint32 u4CFG0;
    uint32 u4CFG1;
    uint16 u2CFG2;
    uint16 u2CFG3;
    uint32 u4CFG4;
    uint16 u2SEUP;
    uint16 u2HOLD;
    uint16 u2IDLE;
    uint16 u2INDA;
    uint16 u2CFSET;
    uint16 u2SSEL;
}SpiChannelCfg;
/*****************************************************************************
 Global functions
 *****************************************************************************/
void R_MSPI_Global_Init(uint8 Pu1Unit);
void R_MSPI_Channel_Init(uint8 Pu1Unit, uint8 Pu1Css, SpiChannelCfg PuStChCfg);
void R_MSPI_Write(uint8 Pu1Unit, uint8 Pu1Css, uint32* const Pu4TxBuff, uint32* Pu4RxBuff, const uint16 Pu2Len);

#endif  /* R_MSPI_H */