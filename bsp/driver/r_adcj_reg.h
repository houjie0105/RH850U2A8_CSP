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
#ifndef _R_ADCJ_REG_H_
#define _R_ADCJ_REG_H_

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define ADCJ0_base                                0xFFCA0000UL
#define ADCJ1_base                                0xFFF20000UL
#define ADCJ2_base                                0xFF9A2000UL


/*****************************************************************************
 Typedef definitions
 *****************************************************************************/


#define ADCJ_VCR(n, m)                            REG32(n + (m*0x04U))
#define ADCJ_DR(n, m)                             REG32(n + 0x1A0U + (m*0x02U))
#define ADCJ_DIR(n, m)                            REG32(n + 0x280U + (m*0x04U))

#define ADCJ_SGSTCR(n, m)                         REG08(n + 0x440U + (m*0x40))
#define ADCJ_SGSTPCR(n, m)                        REG08(n + 0x444U + (m*0x40))
#define ADCJ_SGCR(n, m)                           REG08(n + 0x450U + (m*0x40))
#define ADCJ_SGVCPR(n, m)                         REG16(n + 0x454U + (m*0x40))
#define ADCJ_SGMCYCR(n, m)                        REG08(n + 0x458U + (m*0x40))
#define ADCJ_SGSR(n, m)                           REG08(n + 0x460U + (m*0x40))

#define ADCJ_SGSTR(n)                             REG16(n + 0x600U)
#define ADCJ_ADSYNSTCR(n)                         REG08(n + 0x610U)
#define ADCJ_ADTSYNSTCR(n)                        REG08(n + 0x614U)
#define ADCJ_ADHALTR(n)                           REG08(n + 0x640U)
#define ADCJ_ADCR1(n)                             REG08(n + 0x644U)
#define ADCJ_ADCR2(n)                             REG08(n + 0x648U)
#define ADCJ_SMPCR(n)                             REG32(n + 0x64CU)

#define ADCJ_TDCR(n)                              REG08(n + 0x760U)
#define ADCJ_ODCR(n)                              REG16(n + 0x764U)
#define ADCJ_SFTCR(n)                             REG08(n + 0x770U)
#define ADCJ_TOCCR(n)                             REG08(n + 0x774U)
#define ADCJ_TOCER(n)                             REG08(n + 0x790U)
#define ADCJ_OWER(n)                              REG08(n + 0x79CU)
#define ADCJ_PER(n)                               REG08(n + 0x7A0U)
#define ADCJ_IDER(n)                              REG08(n + 0x7A4U)
#define ADCJ_ECR(n)                               REG16(n + 0x7A8U)

#define ADCJ_VCULLMTBR0(n)                        REG32(n + 0x800U)
#define ADCJ_VCULLMTBR1(n)                        REG32(n + 0x804U)
#define ADCJ_VCULLMTBR2(n)                        REG32(n + 0x808U)
#define ADCJ_VCULLMTBR3(n)                        REG32(n + 0x80CU)
#define ADCJ_VCULLMTBR4(n)                        REG32(n + 0x810U)
#define ADCJ_VCULLMTBR5(n)                        REG32(n + 0x814U)
#define ADCJ_VCULLMTBR6(n)                        REG32(n + 0x818U)
#define ADCJ_VCULLMTBR7(n)                        REG32(n + 0x81CU)
#define ADCJ_VCLMINTER1(n)                        REG32(n + 0x840U)
#define ADCJ_VCLMINTER2(n)                        REG32(n + 0x844U)

#define ADCJ_VCLMSR1(n)                           REG32(n + 0x860U)
#define ADCJ_VCLMSR2(n)                           REG32(n + 0x864U)

#define ADCJ_SGULCR0(n)                           REG16(n + 0x880U)
#define ADCJ_SGULCR1(n)                           REG16(n + 0x884U)
#define ADCJ_SGULCR2(n)                           REG16(n + 0x888U)
#define ADCJ_SGULCR3(n)                           REG16(n + 0x88CU)
#define ADCJ_SGULCR4(n)                           REG16(n + 0x890U)

#define ADCJ_VCLMSCR1(n)                          REG32(n + 0x8A0U)
#define ADCJ_VCLMSCR2(n)                          REG32(n + 0x8A4U)

#define ADCJ_SGULCCR(n)                           REG08(n + 0x8B4U)
#define ADCJ_VCLMASCR(n)                          REG08(n + 0x8B8U)

/*****************************************************************************
 Global variables
 *****************************************************************************/

#endif

