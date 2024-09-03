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
#ifndef R_OSTM_REG_H
#define R_OSTM_REG_H

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define OSTM0            0xFFBF0000UL
#define OSTM1            0xFFBF0100UL
#define OSTM2            0xFFBF0200UL
#define OSTM3            0xFFBF0300UL
#define OSTM4            0xFFBF0400UL
#define OSTM5            0xFFBF0500UL
#define OSTM6            0xFFBF0600UL
#define OSTM7            0xFFBF0700UL
#define OSTM8            0xFFBF0800UL
#define OSTM9            0xFFBF0900UL

#define CMP(n)           REG32((n) + 0x00UL)
#define CNT(n)           REG32((n) + 0x04UL)
#define TO(n)            REG08((n) + 0x08UL)
#define TOE(n)           REG08((n) + 0x0CUL)
#define TE(n)            REG08((n) + 0x10UL)
#define TS(n)            REG08((n) + 0x14UL)
#define TT(n)            REG08((n) + 0x18UL)
#define CTL(n)           REG08((n) + 0x20UL)
#define IC0CKSEL8        REG16(0xFFBF08C0UL)
#define IC0CKSEL9        REG16(0xFFBF09C0UL)

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global functions
 *****************************************************************************/

#endif  /* R_OSTM_REG_H */
