/**********************************************************************************************************************
    Program Name    : Sample program for Renesas Flash Driver (RFD28F)
    
    File Name       : sample_control_codeflash.c
    Program Version : V1.00
    File Revision   : $Rev: 675 $
    File Date       : $Date:: 2019-03-29 18:08:31 +0900#$
    Device(s)       : RV28 Flash based RH850 microcontroller
    Description     : Sample application for Renesas Flash Driver (RFD28F)
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
 *   Rule         : MISRA-C 2012 rule 11.4 / QAC message 0303
 *   Message      : Cast between a pointer to volatile object and an integral type.
 *   Reason       : For effective embedded programming, integer to pointer conversions are used.
 *   Verification : The converted addresses are essential for complete code execution.
 *                  Incorrect conversion would result in test fails.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *   Rule         : MISRA-C 2012 rule 3.1 / QAC message 3108
 *   Message      : Nested comments are not recognized in the ISO standard.
 *   Reason       : Description "//" is a part of URL, so This does not apply.
 *   Verification : No violation.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *   Rule         : MISRA-C 2012 rule 8.4 / QAC message 3408
 *   Message      : '%s' has external linkage and is being defined without any previous declaration.
 *   Reason       : The corresponding point is not declared for access from multiple components. 
 *                  This is "version information" to be placed in the const attribute area and is declared so
 *                  as to acquire it directly from the corresponding area.
 *   Verification : Incorrect declaration would result in compilation fails.
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
 *   Rule         : No MISRA-C 2012 rule / QAC message 3120
 *   Message      : Hard-coded 'magic' integer constant, '%s'.
 *   Reason       : This is sample program for user, in order to clearly indicate what should be specified,
 *                  this program is daringly using the magic number.
 *   Verification : This information is a kind of advice and there is no problem in operation even if it does not
 *                  correspond.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *   Rule         : CERT-C rule DCL00 / QAC message 3204
 *   Message      : The variable '%s' is only set once and so it could be declared with the 'const' qualifier.
 *   Reason       : The relevant part can be declared with const, but since it is easier to read
 *                  if it is implemented with code equivalent to the similar part, we will leave it as it is.
 *   Verification : No violation.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *   Rule         : CERT-C rule DCL00 / QAC message 3227
 *   Message      : The parameter '%s' is never modified and so it could be declared with the 'const' qualifier.
 *   Reason       : This function is an API and is a user I/F. In other words, since the user set parameters,
 *                  it cannot be limited to the const type.
 *   Verification : No violation.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *   Rule         : CERT-C rule INT02 / QAC message 2100,2101
 *   Message      : Understand integer conversion rules.
 *   Reason       : Since it can be confirmed that the corresponding operation result does not exceed the specified
 *                  type range, the correct operation result can be acquired without conversion to integer type.
 *                  So, there is no problem.
 *   Verification : Incorrect conversion would result in test fails.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *   Rule         : CERT-C rule INT30 / QAC message 3383
 *   Message      : Cannot identify wraparound guard for unsigned arithmetic expression.
 *   Reason       : The corresponding operation result counts the number of FACIs present, and the increment result
 *                  cannot exceed the specified type range. So, there is no problem.
 *   Verification : Incorrect conversion would result in test fails.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *   Rule         : CERT-C rule 5002
 *   Message      : The header '%s' file name shadows a previously included header.
 *   Reason       : The header file of the RFD28F starts with "r_rfd", and in the case of a component-specific
 *                  header file is given a component name to improve identification.
 *                  It is intentional and there is no problem.
 *   Verification : Incorrect processing would result in test fails.
 *********************************************************************************************************************/

#include "sample_common_control.h"
#include "sample_codeflash_control.h"   /* !CERT-C rule 5002 */
#pragma section .R_RFD_CODE_COMMON_API
/**********************************************************************************************************************
**  Function Name   : Sample_CodeFlashControl
**  
**  - Outline
**      Sample of Code Flash Control
**      Erase -> Write
**  - Format
**      T_u4_RFDReturn
**          Sample_ResumePE(
**              T_u4_RfdAddress   i_u4_Start,
**              T_u4_RfdAddress   i_u4_End,
**              T_u4_RfdBuffer    i_pu4_Data
**          );
**  - Input parameter
**      i_u4_Start                : Start address for Target Block
**      i_u4_End                  : End address for Target Block
**      i_pu4_Data                : Buffer address where writing data is stored
**      
**  - Return
**      R_RFD_OK                  : Normal End
**      R_RFD_ERR_ACCESS_ENV      : Illegal Access Error
**      R_RFD_ERR_ERASE           : Erase Error state
**      R_RFD_ERR_FHVE_PROTECT    : FHVE Protect Error
**      R_RFD_ERR_INTERNAL_DATA   : Internal Data Error
**      R_RFD_ERR_INTERNAL_HW     : Internal Hardware error
**      R_RFD_ERR_NOFACI          : Specified FACI is noexistance
**      R_RFD_ERR_WRITE           : Write Error state
**      R_RFD_STS_BUSY            : Busy state
**      R_RFD_STS_ERASE_SUSPENDED : Erasure Suspended state
**      R_RFD_STS_WRITE_SUSPENDED : Programming Suspension state
**  - Preconditions
**      No preconditions
**  
**  - Traceability          : [Covers:ST_01_002] [Covers:ST_01_021] [Covers:ST_01_011] [Covers:ST_01_030]
**********************************************************************************************************************/

/* !CERT-C rule DCL00 (QAC message 3227)     */

T_u4_RFDReturn
Sample_CodeFlashControl(
    T_u4_RfdAddress i_u4_Start,
    T_u4_RfdAddress i_u4_End,
    T_pu4_RfdBuffer i_pu4_Data)
{
    
    T_u4_RFDReturn      l_bu4_returnValue;       /* Return value for this function           */
    T_u4_RFDReturn      l_bu4_returnInternal;    /* Return value for calling function        */
    T_u4                l_bu4_timeout;           /* For timeout count                        */
    T_bl                l_bl1_timeoutFlag;       /* Timeout error flag                       */
    T_bl                l_bl1_errorFlag;         /* Error flag                               */
    T_u4                l_bu4_startInternal;     /* Start address for write                  */
    T_u2                l_bu2_Length;            /* Data for writing length                  */
                                                 /* !CERT-C rule DCL00 (QAC message 3204)    */
    T_u2_FACI           l_u2_TargetFACI;         /* FACI number                              */
    
    /* Local variables initialization  */
    l_bu4_returnValue   = R_RFD_OK;
    l_bu4_timeout       = 0U;
    l_bl1_timeoutFlag   = R_RFD_FALSE;
    l_bl1_errorFlag     = R_RFD_FALSE;
    l_bu4_startInternal = 0U;
    l_bu2_Length        = ((T_u2)R_RFD_LENGTH_512BYTES);    /* Size of writing data */
    l_u2_TargetFACI     = R_RFD_INVALID_FACI;
    
        
    /* Acquire the target of FACI */
    l_u2_TargetFACI     = R_RFD_CFAddressToFaciNumber(i_u4_Start);
    
    if (l_bu4_returnValue == R_RFD_INVALID_FACI)    /* !CERT-C rule INT02 (QAC message 2101) */
    {
        l_bl1_errorFlag = R_RFD_TRUE;     /* Specified FACI is noexistance */
    }
    else
    {
        /* no operation */
    }
    
    /******************************************************************************************************************
     *  Shift to P/E mode
     *****************************************************************************************************************/
    
    if (l_bl1_errorFlag == R_RFD_FALSE)     /* !CERT-C rule INT02 (QAC message 2100) */
    {
        l_bu4_returnValue = R_RFD_ShiftToPEMode(l_u2_TargetFACI, R_RFD_MODE_CFPE);
        
        /* Set the timeout value for checking P/E mode */
        l_bu4_timeout = 200000UL;     /* !QAC message 3120 */
        
        /* Mode has not already R_RFD_MODE_CFPE */
        if (l_bu4_returnValue == R_RFD_STS_BUSY)
        {
            /* Check whether the mode shift to CF P/E mode */
            do
            {
                l_bu4_returnValue = R_RFD_CheckPEMode(l_u2_TargetFACI, R_RFD_MODE_CFPE);
                l_bu4_timeout--;    /* !CERT-C rule INT30 (QAC message 3383) */
                
                /* Check timeout */
                if (l_bu4_timeout == 0UL)
                {
                    /* Timeout */
                    l_bl1_timeoutFlag = R_RFD_TRUE;   /* Timeout occured */
                    break;
                }
                else
                {
                    /* no operation */
                }
            } while (l_bu4_returnValue == R_RFD_STS_BUSY);
            
            /* If the mode does not shift to P/E mode */
            if (l_bu4_returnValue != R_RFD_OK)
            {
                l_bl1_errorFlag   = R_RFD_TRUE;     /* Error occurred */
                
                /* Shift to Read mode */
                l_bu4_returnValue = R_RFD_ShiftToReadMode(l_u2_TargetFACI);
                
                if (l_bu4_returnValue != R_RFD_ERR_INTERNAL_HW)
                {
                    l_bu4_returnValue = R_RFD_ERR_TIMEOUT;  /* Set return value */
                }
                else
                {
                    /* no operation */
                }
            }
            else
            {
                /* no operation */
            }
        }
        else if (l_bu4_returnValue == R_RFD_ERR_NOFACI)
        {
            l_bl1_errorFlag = R_RFD_TRUE;   /* Error occurred */
        }
        else
        {
            /* no operation */
        }
    }
    else
    {
        /* no operation */
    }
    
    /******************************************************************************************************************
     *  Erase the contents of the code flash memory
     *****************************************************************************************************************/
    
    if ((l_bl1_errorFlag == R_RFD_FALSE)&&(l_bl1_timeoutFlag == R_RFD_FALSE))
    {                                                               /* !CERT-C rule INT02 (QAC message 2100) */
        l_bu4_returnValue = Sample_EraseCF(i_u4_Start);
        
        /* Return value of Sample_EraseCF is R_RFD_OK */
        if (l_bu4_returnValue == R_RFD_OK)
        {
            /* Sample of Suspending and Resumption */
            l_bu4_returnValue = Sample_SuspendResume(l_u2_TargetFACI);
            
            if (l_bu4_returnValue == R_RFD_ERR_TIMEOUT)
            {
                l_bl1_timeoutFlag = R_RFD_TRUE;
            }
            else
            {
                if (l_bu4_returnValue == R_RFD_OK)
                {
                    /* no operation */
                }
                else
                {
                    l_bl1_errorFlag = R_RFD_TRUE;   /* Error occurred */
                }
            }
            
            /* Suspending and Resumption was not timeout */
            if ((l_bl1_errorFlag == R_RFD_FALSE)&&(l_bl1_timeoutFlag == R_RFD_FALSE))
            {                                                           /* !CERT-C rule INT02 (QAC message 2100) */
                /* Set the timeout value for checking erasure complete */
                l_bu4_timeout = 200000UL;             /* !QAC message 3120 */
                
                /* Check whether the erasure is completed */
                do
                {
                    l_bu4_returnValue = Sample_CheckFaciStatus(l_u2_TargetFACI);
                    l_bu4_timeout--;                /* !CERT-C rule INT30 (QAC message 3383) */
                    
                    /* Check timeout */
                    if (l_bu4_timeout == 0UL)
                    {
                        l_bl1_timeoutFlag = R_RFD_TRUE; /* Timeout occured */
                        break;
                    }
                    else
                    {
                        /* no operation */
                    }
                } while (l_bu4_returnValue == R_RFD_STS_BUSY);
                
                /* Check the FACI status */
                if (l_bu4_returnValue == R_RFD_OK)
                {
                    /* no operation */
                }
                else
                {
                    l_bl1_errorFlag = R_RFD_TRUE;   /* Error occurred */
                }
            }
            else
            {
                /* no operation */
            }
        }
        /* Return value of Sample_EraseCF is not R_RFD_OK */
        else
        {
            /* Return value of Sample_EraseCF is "R_RFD_ERR_NOFACI" or "R_RFD_ERR_INTERNAL_HW" */
            l_bl1_errorFlag = R_RFD_TRUE;
        }
    }
    else
    {
        /* no operation */
    }
    
    
    /******************************************************************************************************************
     *  If necessary, Check whether there is free space in the codedata flash memory
     *****************************************************************************************************************/
    
    
    /******************************************************************************************************************
     *  Write the data to the data flash memory
     *****************************************************************************************************************/
    
    if ((l_bl1_errorFlag == R_RFD_FALSE)&&(l_bl1_timeoutFlag == R_RFD_FALSE))
    {                                                               /* !CERT-C rule INT02 (QAC message 2100) */
        l_bu4_startInternal = i_u4_Start;
        
        
        /* Writing per 512bytes */
        while ((l_bu4_startInternal < i_u4_End)&&(l_bl1_errorFlag != R_RFD_TRUE))
        {                                                           /* !CERT-C rule INT02 (QAC message 2100) */
            l_bu4_returnValue = Sample_WriteCF(l_bu4_startInternal, i_pu4_Data);
            
            if (l_bu4_returnValue == R_RFD_OK)
            {
                /* Set the timeout value for checking erasure complete */
                l_bu4_timeout = 200000UL;             /* !QAC message 3120 */
                
                /* Check whether the erasure is completed */
                do
                {
                    l_bu4_returnValue = Sample_CheckFaciStatus(l_u2_TargetFACI);
                    l_bu4_timeout--;                /* !CERT-C rule INT30 (QAC message 3383) */
                    
                    /* Check timeout */
                    if (l_bu4_timeout == 0UL)
                    {
                        l_bl1_timeoutFlag = R_RFD_TRUE; /* Timeout occured */
                        break;
                    }
                    else
                    {
                        /* no operation */
                    }
                } while (l_bu4_returnValue == R_RFD_STS_BUSY);
                
                /* If the timeout is not occured  */
                if (l_bu4_returnValue == R_RFD_OK)
                {
                    /* no operation */
                }
                else
                {
                    l_bl1_errorFlag = R_RFD_TRUE; /* Error occurred */
                }
            }
            /* Return value of Sample_WriteCF is not R_RFD_OK */
            else
            {
                /* Return value of Sample_WriteCF is "R_RFD_ERR_NOFACI" or "R_RFD_ERR_INTERNAL_HW" */
                l_bl1_errorFlag = R_RFD_TRUE; /* Error occurred */
            }
            l_bu4_startInternal += (T_u4)l_bu2_Length;  /* !CERT-C rule INT30 (QAC message 3383) */
            
        } /* while ((l_bu4_startInternal < i_u4_End)&&(l_bl1_errorFlag != R_RFD_TRUE)) */
        
    }
    else
    {
        /* no operation */
    }
    
    
    
    /******************************************************************************************************************
     *  Check the area for writing data
     *****************************************************************************************************************/
    
    
    
    /******************************************************************************************************************
     *  When timeout error occured
     *****************************************************************************************************************/
    
    if (l_bl1_timeoutFlag == R_RFD_TRUE)    /* !CERT-C rule INT02 (QAC message 2100) */
    {
        l_bu4_returnInternal = R_RFD_ForcedStopAndErrorClear(l_u2_TargetFACI);
        
        if (l_bu4_returnInternal == R_RFD_OK)
        {
            l_bu4_returnInternal = R_RFD_ShiftToReadMode(l_u2_TargetFACI);
            
            if ( l_bu4_returnInternal != R_RFD_OK )
            {
                l_bu4_returnValue = l_bu4_returnInternal;
            }
            else
            {
                /* no operation */
            }
        }
        else
        {
            l_bu4_returnValue = l_bu4_returnInternal;
        }
    }
    else
    {
        /* no operation */
    }
    
    /******************************************************************************************************************
     *  Shift to read mode
     *****************************************************************************************************************/
    
    if (l_bl1_timeoutFlag == R_RFD_FALSE)        /* !CERT-C rule INT02 (QAC message 2100) */
    {
        if (l_bu4_returnValue != R_RFD_OK)
        {
            /* Release command lock */
            l_bu4_returnInternal = Sample_ReleaseCommandLock(l_u2_TargetFACI);
            
            if (l_bu4_returnInternal != R_RFD_OK)
            {
                l_bu4_returnValue = l_bu4_returnInternal;
                l_bu4_returnInternal = R_RFD_ShiftToReadMode(l_u2_TargetFACI);
            }
            else
            {
                l_bu4_returnValue = R_RFD_ShiftToReadMode(l_u2_TargetFACI);
            }
        }
        else
        {
            /* Shift to read mode */
            l_bu4_returnValue = R_RFD_ShiftToReadMode(l_u2_TargetFACI);
        }
    }
    else
    {
        /* no operation */
    }
    
    return (l_bu4_returnValue);
    
}
#pragma section default