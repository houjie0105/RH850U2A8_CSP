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
#ifndef R_STBC_REG_H
#define R_STBC_REG_H

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
/* #define MSR_RSCFD        REG32(0xFF981000UL) */
/* #define MSR_FLXA         REG32(0xFF981010UL) */
/* #define MSR_GTM          REG32(0xFF981020UL) */
/* #define MSR_ETNB         REG32(0xFF981030UL) */
/* #define MSR_RSENT        REG32(0xFF981040UL) */
/* #define MSR_MSPI         REG32(0xFF981050UL) */
/* #define MSR_RLIN3        REG32(0xFF981060UL) */
/* #define MSR_ADCJ_ISO     REG32(0xFF981070UL) */
/* #define MSR_CXPI         REG32(0xFF981080UL) */
/* #define MSR_MMCA         REG32(0xFF981090UL) */
/* #define MSR_ENCA         REG32(0xFF9810A0UL) */
/* #define MSR_PSI5         REG32(0xFF9810B0UL) */
/* #define MSR_PSI5S        REG32(0xFF9810C0UL) */
/* #define MSR_PWMD         REG32(0xFF9810D0UL) */
/* #define MSR_RHSIF        REG32(0xFF9810E0UL) */
/* #define MSR_RIIC         REG32(0xFF9810F0UL) */
/* #define MSR_SCI3         REG32(0xFF981100UL) */
/* #define MSR_TAPA         REG32(0xFF981120UL) */
/* #define MSR_TAUD         REG32(0xFF981130UL) */
/* #define MSR_TAUJ_ISO     REG32(0xFF981140UL) */
/* #define MSR_TPBA         REG32(0xFF981150UL) */
/* #define MSR_TSG3         REG32(0xFF981160UL) */
/* #define MSR_OSTM         REG32(0xFF981180UL) */
/* #define STBCKCPROT       REG32(0xFF981700UL) */
/* #define MSRKCPROT        REG32(0xFF981710UL) */
/* #define STBC0PSC         REG32(0xFF988C00UL) */
/* #define STBC0STPT        REG32(0xFF988C04UL) */
/* #define PWRGD_CNT        REG32(0xFF988C08UL) */
/* #define IOHOLD0          REG32(0xFF988D00UL) */
/* #define IOHOLD2          REG32(0xFF988D08UL) */
/* #define MSR_ADCJ_AW      REG32(0xFF988E00UL) */
/* #define MSR_RTCA         REG32(0xFF988E10UL) */
/* #define MSR_TAUJ_AWO     REG32(0xFF988E20UL) */
/* #define MSR_WDTB_AW      REG32(0xFF988E30UL) */
/* #define WUF0_A0          REG32(0xFF98E000UL) */
/* #define WUF0_A1          REG32(0xFF98E010UL) */
/* #define WUF0_A2          REG32(0xFF98E020UL) */
/* #define WUF1_A0          REG32(0xFF98E120UL) */
/* #define WUF1_A1          REG32(0xFF98E130UL) */
/* #define WUF1_A2          REG32(0xFF98E140UL) */
/* #define WUF0_I0          REG32(0xFF98E200UL) */
/* #define WUF0_I1          REG32(0xFF98E210UL) */
/* #define WUF1_I0          REG32(0xFF98E320UL) */
/* #define WUF1_I1          REG32(0xFF98E330UL) */
/* #define WUFMSK0_A0       REG32(0xFF98E004UL) */
/* #define WUFMSK0_A1       REG32(0xFF98E014UL) */
/* #define WUFMSK0_A2       REG32(0xFF98E024UL) */
/* #define WUFMSK1_A0       REG32(0xFF98E124UL) */
/* #define WUFMSK1_A1       REG32(0xFF98E134UL) */
/* #define WUFMSK1_A2       REG32(0xFF98E144UL) */
/* #define WUFMSK0_I0       REG32(0xFF98E204UL) */
/* #define WUFMSK0_I1       REG32(0xFF98E214UL) */
/* #define WUFMSK1_I0       REG32(0xFF98E324UL) */
/* #define WUFMSK1_I1       REG32(0xFF98E334UL) */
/* #define WUFC0_A0         REG32(0xFF98E008UL) */
/* #define WUFC0_A1         REG32(0xFF98E018UL) */
/* #define WUFC0_A2         REG32(0xFF98E028UL) */
/* #define WUFC1_A0         REG32(0xFF98E128UL) */
/* #define WUFC1_A1         REG32(0xFF98E138UL) */
/* #define WUFC1_A2         REG32(0xFF98E148UL) */
/* #define WUFC0_I0         REG32(0xFF98E208UL) */
/* #define WUFC0_I1         REG32(0xFF98E218UL) */
/* #define WUFC1_I0         REG32(0xFF98E328UL) */
/* #define WUFC1_I1         REG32(0xFF98E338UL) */
/* #define WUFMON           REG32(0xFF98E1A0UL) */

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global functions
 *****************************************************************************/

#endif  /* R_STBC_REG_H */
