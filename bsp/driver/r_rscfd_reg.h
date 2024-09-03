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
#ifndef R_RSCFD_REG_H
#define R_RSCFD_REG_H

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define RSCFD0_base      0xFFF50000UL

/* Channel-related registers */
#define CFDCNCFG(n,m)        REG32((n) + 0x0000UL + (0x10UL * (m)))
#define CFDCCTR(n,m)         REG32((n) + 0x0004UL + (0x10UL * (m)))
#define CFDCSTS(n,m)         REG32((n) + 0x0008UL + (0x10UL * (m)))
#define CFDCERFL(n,m)        REG32((n) + 0x000CUL + (0x10UL * (m)))

#define DCFG(n,m)        REG32((n) + 0x1400UL + (0x20UL * (m)))
#define FDCFG(n,m)       REG32((n) + 0x1404UL + (0x20UL * (m)))
#define FDCTR(n,m)       REG32((n) + 0x1408UL + (0x20UL * (m)))
#define FDSTS(n,m)       REG32((n) + 0x140CUL + (0x20UL * (m)))
#define FDCRC(n,m)       REG32((n) + 0x1410UL + (0x20UL * (m)))

/* Global-related registers */
#define CFDGCFG(n)       REG32((n) + 0x0084UL)
#define CFDGCTR(n)       REG32((n) + 0x0088UL)
#define CFDGSTS(n)       REG32((n) + 0x008CUL)
#define CFDGERFL(n)      REG32((n) + 0x0090UL)
#define CFDGTSC(n)       REG32((n) + 0x0094UL)
#define CFDGTINTSTS(n,z) REG32((n) + 0x1300UL + (0x04 * z))
#define CFDGFDCFG(n)     REG32((n) + 0x1314UL)

/* Receive buffer-related registers */
#define CFDRMNB(n)         REG32((n) + 0x00ACUL)
#define CFDRMND(n,i)       REG32((n) + 0x00B0UL + (0x04UL * (i)))
#define CFDRMID(n,b,m)     REG32((n) + 0x2000UL + (0x80UL * (b)) + (0x800 * (m)))
#define CFDRMPTR(n,b,m)    REG32((n) + 0x2004UL + (0x80UL * (b)) + (0x800 * (m)))
#define CFDRMFDSTS(n,b,m)  REG32((n) + 0x2008UL + (0x80UL * (b)) + (0x800 * (m)))
#define CFDRMDF(n,b,m,p)   REG32((n) + 0x200CUL + (0x80UL * (b)) + (0x800 * (m)) + (0x04 * (p)))

/* Transmit buffer-related registers */
#define CFDTMC(n,p)        REG08((n) + 0x02D0UL + (0x01UL * (p)))
#define CFDTMSTS(n,p)      REG08((n) + 0x07D0UL + (0x01UL * (p)))
#define CFDTMID(n,m,b)     REG32((n) + 0x10000UL + (0x80UL * (b)) + (0x2000UL * (m)))
#define CFDTMPTR(n,m,b)    REG32((n) + 0x10004UL + (0x80UL * (b)) + (0x2000UL * (m)))
#define CFDTMFDCTR(n,m,b)  REG32((n) + 0x10008UL + (0x80UL * (b)) + (0x2000UL * (m)))
#define CFDTMDF(n,m,b,p)   REG32((n) + 0x1000CUL + (0x80UL * (b)) + (0x2000UL * (m)) + (0x04 * (p)))

#define CFDRFCC(n,m)       REG32((n) + 0xC0UL + (0x04 * (m)))
#define CFDCFCC(n,m)       REG32((n) + 0x120UL + (0x04 * (m)))

#define CFDGAFLCFG(n,m)    REG32((n) + 0x9CUL + (0x04 * (m)))
#define CFDGAFLECTR(n)     REG32((n) + 0x98UL)
#define CFDGAFLID(n,j)     REG32((n) + 0x1800UL + (0x10 * (j)))

#define CFDRFSTS(n,j)      REG32((n) + 0xE0UL + (0x04 * (j)))
#define CFDRFID(n,b)       REG32((n) + 0x6000 + (0x80 * (b)))
#define CFDRFPTR(n,b)      REG32((n) + 0x6004 + (0x80 * (b)))
#define CFDRFFDSTS(n,b)    REG32((n) + 0x6008 + (0x80 * (b)))
#define CFDRFDF(n,p,b)     REG32((n) + 0x600C + (0x80 * (b)) + (0x04 * (p)))

#define CFDRFPCTR(n,j)     REG32((n) + 0x100 + (0x04 * (j)))

#define CFDCFSTS(n,k)      REG32((n) + 0x1E0 + (0x04 * (k)))
#define CFDCFID(n,b)       REG32((n) + 0x6400 + (0x80 * (b)))
#define CFDCFPTR(n,b)      REG32((n) + 0x6404 + (0x80 * (b)))
#define CFDCFFDSTS(n,b)    REG32((n) + 0x6408 + (0x80 * (b)))
#define CFDCFDF(n,p,b)     REG32((n) + 0x640C + (0x80 * (b)) + (0x04 * (p)))

#define CFDCFPCTR(n,k)     REG32((n) + 0x240 + (0x04 * (k)))

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
