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
#ifndef R_RLIN3_REG_H
#define R_RLIN3_REG_H

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define RLIN30_base      0xFFD28000UL
#define RLIN31_base      0xFFC7C000UL
#define RLIN32_base      0xFFD28200UL
#define RLIN33_base      0xFFC7C080UL
#define RLIN34_base      0xFFD28400UL
#define RLIN35_base      0xFFC7C100UL
#define RLIN36_base      0xFFD28600UL
#define RLIN37_base      0xFFC7C180UL
#define RLIN38_base      0xFFD28800UL
#define RLIN39_base      0xFFC7C200UL
#define RLIN310_base     0xFFD28A00UL
#define RLIN311_base     0xFFC7C280UL

#define LWBR(n)          REG08((n) + 0x01UL)
#define LBRP0(n)         REG08((n) + 0x02UL)
#define LBRP1(n)         REG08((n) + 0x03UL)
#define LSTC(n)          REG08((n) + 0x04UL) 
#define LMD(n)           REG08((n) + 0x08UL)
#define LBFC(n)          REG08((n) + 0x09UL)
#define LSC(n)           REG08((n) + 0x0AUL)
#define LWUP(n)          REG08((n) + 0x0BUL)
#define LIE(n)           REG08((n) + 0x0CUL)
#define LEDE(n)          REG08((n) + 0x0DUL)
#define LCUC(n)          REG08((n) + 0x0EUL)
#define LTRC(n)          REG08((n) + 0x10UL)
#define LMST(n)          REG08((n) + 0x11UL)
#define LST(n)           REG08((n) + 0x12UL)
#define LEST(n)          REG08((n) + 0x13UL)
#define LDFC(n)          REG08((n) + 0x14UL)
#define LIDB(n)          REG08((n) + 0x15UL)
#define LCBR(n)          REG08((n) + 0x16UL)
#define LDBR(n,x)        REG08((n) + 0x18UL + 0x01UL * (x))


#define UART_LWBR(UART_Base)        REG08((UART_Base)+0x01UL)
#define UART_LBRP01(UART_Base)      REG16((UART_Base)+0x02UL)
#define UART_LMD(UART_Base)         REG08((UART_Base)+0x08UL)
#define UART_LBFC(UART_Base)        REG08((UART_Base)+0x09UL)
#define UART_LSC(UART_Base)         REG08((UART_Base)+0x0AUL)
#define UART_LEDE(UART_Base)        REG08((UART_Base)+0x0DUL)
#define UART_LCUC(UART_Base)        REG08((UART_Base)+0x0EUL)
#define UART_LTRC(UART_Base)        REG08((UART_Base)+0x10UL)
#define UART_LMST(UART_Base)        REG08((UART_Base)+0x11UL)
#define UART_LST(UART_Base)         REG08((UART_Base)+0x12UL)
#define UART_LEST(UART_Base)        REG08((UART_Base)+0x13UL)
#define UART_LDFC(UART_Base)        REG08((UART_Base)+0x14UL)
#define UART_LIDB(UART_Base)        REG08((UART_Base)+0x15UL)
#define UART_LUDB0(UART_Base)       REG08((UART_Base)+0x17UL)
#define UART_LDBRn(UART_Base,n)     REG08((UART_Base)+0x17UL+(n*0x01UL))
#define UART_LUOER(UART_Base)       REG08((UART_Base)+0x20UL)
#define UART_LUOR1(UART_Base)       REG08((UART_Base)+0x21UL)
#define UART_LUTDR(UART_Base)       REG16((UART_Base)+0x24UL)
#define UART_LURDR(UART_Base)       REG16((UART_Base)+0x26UL)
#define UART_LUWTDR(UART_Base)      REG16((UART_Base)+0x28UL)
/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global functions
 *****************************************************************************/

#endif
