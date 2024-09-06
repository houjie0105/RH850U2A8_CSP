/**********************************************************************************************************************
    Program Name    : Renesas Flash Driver (RFD28F)
    
    File Name       : r_rfd_cf_error.h
    Program Version : V1.00
    File Revision   : $Rev: 2438 $
    File Date       : $Date:: 2021-06-01 18:30:17 +0900#$
    Device(s)       : RV28 Flash based RH850 microcontroller
    Description     : For RH850/U2Ax
**********************************************************************************************************************/

/* !MISRA-C 2012 dir 1.1 (QAC message 0292) */

/**********************************************************************************************************************
    DISCLAIMER
    This software is supplied by Renesas Electronics Corporation and is only  intended for use with
    Renesas products. No other uses are authorized. This software is owned by Renesas Electronics
    Corporation and is protected under all applicable laws, including copyright laws.
    THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE,
    WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
    TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR
    ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR
    CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
    BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
    Renesas reserves the right, without notice, to make changes to this software and to discontinue the
    availability of this software. By using this software, you agree to the additional terms and conditions
    found by accessing the  following link:
    http://www.renesas.com/disclaimer
    
    Copyright (C) 2021 Renesas Electronics Corporation. All rights reserved.
**********************************************************************************************************************/

/* !MISRA-C 2012 rule 3.1 (QAC message 3108) */

/**********************************************************************************************************************
 *  MISRA-C 2012 Rule Violation
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *   Rule         : MISRA-C 2012 dir 1.1 / QAC message 0292
 *   Message      : Source file '%s' has comments containing one of the characters '$', '@' or '`'.
 *   Reason       : To support automatic insertion of revision by the source revision control system, it is necessary
 *                  to violate this rule, because the system uses non basic characters.
 *   Verification : The character '$' is used in comment only. Therefore, this rule violation is not influence code
 *                  compilation.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *   Rule         : MISRA-C 2012 rule 3.1 / QAC message 3108
 *   Message      : Nested comments are not recognized in the ISO standard.
 *   Reason       : Description "//" is a part of URL, so This does not apply.
 *   Verification : No violation.
 *********************************************************************************************************************/

#ifndef R_RFD_CF_ERROR_H
#define R_RFD_CF_ERROR_H

/**********************************************************************************************************************
    For Data Flash Control Component
    
    - Traceability          : [Covers:DD_55_000]
**********************************************************************************************************************/

/**********************************************************************************************************************
    Return value
**********************************************************************************************************************/

#ifndef R_RFD_COMMON_ERROR_H
    #define R_RFD_OK                            0x00000000UL
    #define R_RFD_ERR_SWITCH_DATA               0x00001007UL
    #define R_RFD_ERR_SECURITY_DATA             0x00001008UL
    #define R_RFD_ERR_BLOCKPROTECTION0_DATA     0x00001009UL
    #define R_RFD_ERR_BLOCKPROTECTION1_DATA     0x0000100aUL
    #define R_RFD_ERR_CONFIGURATION_DATA        0x0000100bUL
#endif

#ifndef R_RFD_DF_ERROR_H
    #define R_RFD_ERR_IDAUTH        0x00000103UL
#endif


#endif  /* R_RFD_CF_ERROR_H */
