/**********************************************************************************************************************
    Program Name    : Renesas Flash Driver (RFD28F)
    
    File Name       : r_rfd_cf_api.h
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

/**********************************************************************************************************************
 *   Rule         : No MISRA-C 2012 or CERT-C rule / QAC message 0776
 *   Message      : External identifier matches other external identifier(s) (e.g. '%s')
 *                  in first 6 characters - program does not conform strictly to ISO:C90.
 *   Reason       : "R_RFD_" is defined as a string necessary to recognize that it is an API of RFD provided
 *                  by Renesas to distinguish it from other APIs. Furthermore, since both the external identifier and
 *                  the internal identifier do not exceed 31 characters, the minimum requirement of valid characters
 *                  is satisfied and it is determined that there is no problem.
 *   Verification : Incorrect API name would result in test fails.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *   Rule         : CERT-C rule 5002
 *   Message      : The header '%s' file name shadows a previously included header.
 *   Reason       : The header file of the RFD28F starts with "r_rfd", and in the case of a component-specific
 *                  header file is given a component name to improve identification.
 *                  It is intentional and there is no problem.
 *   Verification : Incorrect processing would result in test fails.
 *********************************************************************************************************************/

#ifndef R_RFD_CF_API_H
#define R_RFD_CF_API_H

#include "r_rfd_types.h"        /* !CERT-C rule 5002 */
#include "r_rfd_cf_types.h"     /* !CERT-C rule 5002 */

/**********************************************************************************************************************
    For Data Flash Control Component
**********************************************************************************************************************/

/**********************************************************************************************************************
    Prototype declaration
**********************************************************************************************************************/

/* !QAC message 0776 */

extern T_u4_RFDReturn   R_RFD_IDAuth(T_en_IDType i_en_IDType, T_u1* i_pu1_AuthIDData);
extern void             R_RFD_EraseCFRequest(T_u4_RfdAddress i_u4_Start);
extern void             R_RFD_WriteCFRequest(T_u4_RfdAddress i_u4_Start, T_pu4_RfdBuffer i_pu4_Data);
extern void             R_RFD_ErasePropertyRequest(T_u4_RfdAddress i_u4_Start);
extern void             R_RFD_WritePropertyRequest(T_u4_RfdAddress i_u4_Start, T_pu4_RfdBuffer i_pu4_Data);
extern T_u4_RFDReturn   R_RFD_EraseSwitchRequest(void);
extern void             R_RFD_WriteSwitchRequest(T_pu4_RfdBuffer i_pu4_Data);
extern T_u4_RFDReturn   R_RFD_EraseTagRequest(void);
extern T_u4_RFDReturn   R_RFD_UpdateTagRequest(void);
extern void             R_RFD_EraseExtendedDataRequest(T_u4_RfdAddress i_u4_Start);
extern void             R_RFD_WriteExtendedDataRequest(T_u4_RfdAddress i_u4_Start, T_u2 i_u2_Length,
                                                                                        T_pu4_RfdBuffer i_pu4_Data);
extern T_u2_FACI        R_RFD_CFAddressToFaciNumber(T_u4_RfdAddress i_u4_Address);
extern T_u2_FACI        R_RFD_PropertyAddressToFaciNumber(T_u4_RfdAddress i_u4_Address);

#endif  /* R_RFD_CF_API_H */
