
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
#ifndef R_MSPI_REG_H
#define R_MSPI_REG_H

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define MSPI0_base                     0xFFC76000UL
#define MSPI1_base                     0xFFC7E000UL
#define MSPI2_base                     0xFFD80000UL
#define MSPI3_base                     0xFFCC0000UL
#define MSPI4_base                     0xFFD82000UL
#define MSPI5_base                     0xFFCC4000UL


#define MSPI0_INTF_base                0xFFC75740UL
#define MSPI1_INTF_base                0xFFC7C840UL
#define MSPI2_INTF_base                0xFFC75840UL
#define MSPI3_INTF_base                0xFFC7CA40UL
#define MSPI4_INTF_base                0xFFC75940UL
#define MSPI5_INTF_base                0xFFC7CC40UL

#define MSPITG_base                    0xFFC75D00UL

#define MSPI_INTF(n,k)                 REG32((n) + (k*0x30UL))
#define MSPI_INTMSK(n,k)               REG32((n) + (k*0x30UL) + 0x04)
#define MSPI_INTFC(n,k)                REG32((n) + (k*0x30UL) + 0x08)

#define MSPI_CTL0(n)                   REG08((n))
#define MSPI_CTL1(n)                   REG32((n) + 0x04UL)
#define MSPI_CTL2(n)                   REG08((n) + 0x08UL)
#define MSPI_CTR0(n)                   REG08((n) + 0x10UL)

#define MSPI_CFG0(n,m)                 REG32((n) + (0x80*(m+1)) + 0x00UL)
#define MSPI_CFG1(n,m)                 REG32((n) + (0x80*(m+1)) + 0x04UL)
#define MSPI_CFG2(n,m)                 REG16((n) + (0x80*(m+1)) + 0x08UL)
#define MSPI_CFG3(n,m)                 REG16((n) + (0x80*(m+1)) + 0x0CUL)
#define MSPI_CFG4(n,m)                 REG32((n) + (0x80*(m+1)) + 0x10UL)

#define MSPI_SEUP(n,m)                 REG16((n) + (0x80*(m+1)) + 0x18UL)
#define MSPI_HOLD(n,m)                 REG16((n) + (0x80*(m+1)) + 0x1CUL)
#define MSPI_IDLE(n,m)                 REG16((n) + (0x80*(m+1)) + 0x20UL)
#define MSPI_INDA(n,m)                 REG16((n) + (0x80*(m+1)) + 0x24UL)
#define MSPI_RASTAD(n,m)               REG16((n) + (0x80*(m+1)) + 0x28UL)
#define MSPI_CFSET(n,m)                REG16((n) + (0x80*(m+1)) + 0x2CUL)
#define MSPI_SSTX(n,m)                 REG32((n) + (0x80*(m+1)) + 0x30UL)

#define MSPI_CSTS(n,m)                 REG08((n) + 0x34UL + (0x80 * (m+1)))
#define MSPI_CSTC(n,m)                 REG08((n) + 0x38UL + (0x80 * (m+1)))
#define MSPI_SSEL(n,m)                 REG16((n) + 0x3CUL + (0x80 * (m+1)))
#define MSPI_TXDA0(n,m)                REG32((n) + 0x40UL + (0x80 * (m+1)))
#define MSPI_FRERST(n,m)               REG08((n) + 0x4CUL + (0x80 * (m+1)))
#define MSPI_RXDA0(n,m)                REG32((n) + 0x50UL + (0x80 * (m+1)))
#define MSPI_CSTR(n,m)                 REG16((n) + 0x58UL + (0x80 * (m+1)))
#define MSPI_CFCNT(n,m)                REG32((n) + 0x5CUL + (0x80 * (m+1)))
#define MSPI_FSRX(n,m)                 REG32((n) + 0x60UL + (0x80 * (m+1)))
#define MSPI_FRERSTC(n,m)              REG08((n) + 0x64UL + (0x80 * (m+1)))
#define MSPI_CEST(n,m)                 REG08((n) + 0x68UL + (0x80 * (m+1)))
#define MSPI_CESTC(n,m)                REG08((n) + 0x68UL + (0x80 * (m+1)))

#define MSPI_TGCTL(n,m)                REG32((n) + (0x04*m))
#define MSPI_TGDMAALT(n,m)             REG32((n) + 0x28)
#define MSPI_TGDTSALT(n,m)             REG32((n) + 0x2C)
/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global functions
 *****************************************************************************/

#endif  /* R_MSPI_REG_H */