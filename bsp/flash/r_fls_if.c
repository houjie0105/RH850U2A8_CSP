/**************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
*
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2017 Renesas Electronics Corporation. All rights reserved.
***************************************************************************/

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_fls_if.h"
#include "sample_flash_control.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define R_RFD_FLMD_BASE             0xFFA00000UL                            /* FLMD base address */
#define R_RFD_REG_FLMD              (*(volatile T_u4 *)R_RFD_FLMD_BASE)
/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global static variables
 *****************************************************************************/

/*****************************************************************************
 Static functions
 *****************************************************************************/

/*****************************************************************************
--------------------- Global functions --------------------------------------
 *****************************************************************************/
uint8 R_FLS_IF_Init(void)
{
    T_u4_RFDReturn  l_bu4_returnValue = R_OK;
    T_u2            l_bu2_faciFequency = 0xFFFFU;
    T_bl            l_bl1_errorFlag = 0;
    T_u4            l_bu4_loopCount = 0;
    T_u1            l_bu1_CUSTIDx[R_RFD_LENGTH_IDAUTH] = {0};
    /* Initialize RFD28F */
    l_bu4_returnValue = R_RFD_Init(l_bu2_faciFequency);
    
    if (l_bu4_returnValue != R_RFD_OK)
    {
        l_bl1_errorFlag = R_RFD_TRUE;
    }
    else
    {
        /* no operation */
    }
    
    if (l_bl1_errorFlag == R_RFD_FALSE)     /* !CERT-C rule INT02 (QAC message 2100) */
    {
        /* FHVE Protect OFF (FACI0) */
        l_bu4_returnValue = R_RFD_SetFHVE(R_RFD_FACI0, R_RFD_FHVE_PROTECT_OFF);
        
        if (l_bu4_returnValue != R_RFD_OK)
        {
            l_bl1_errorFlag = R_RFD_TRUE;
        }
        else
        {
            /* FHVE Protect OFF (FACI1) */
            l_bu4_returnValue = R_RFD_SetFHVE(R_RFD_FACI1, R_RFD_FHVE_PROTECT_OFF);
            
            if (l_bu4_returnValue != R_RFD_OK)
            {
                l_bl1_errorFlag = R_RFD_TRUE;
            }
            else
            {
                /* no operation */
            }
        }
    }
    else
    {
        /* no operation */
    }



    /* Set the value to FLMD due to access to code flash */
    R_RFD_REG_FLMD = 0x00000001UL;      /* !MISRA-C 2012 rule 11.4 (QAC message 0303) */
    
    /* Code Flash Control */
    if (l_bl1_errorFlag == R_RFD_FALSE)     /* !CERT-C rule INT02 (QAC message 2100) */
    {
        /* Authenticate CUSTIDA, CUSTIDB, CUSTIDC                     */
        /* In the case that all CUSTIDA, CUSTIDB and CUSTIDC are 0xFF */
        for (l_bu4_loopCount = 0UL; l_bu4_loopCount < 32UL; l_bu4_loopCount++)
        {
            l_bu1_CUSTIDx[l_bu4_loopCount] = 0xFFU;
        }
        
        /* Check all of CUSTIDA, CUSTIDB and CUSTIDC, and if any one return value */
        /* is not R_RFD_OK, enable error flag.                                    */
        
        /* Authenticate CUSTIDA */
        l_bu4_returnValue = R_RFD_IDAuth(R_RFD_ID_CUSTIDA, l_bu1_CUSTIDx);
        
        /* Check return value */
        if (l_bu4_returnValue != R_RFD_OK)
        {
            l_bl1_errorFlag = R_RFD_TRUE;
        }
        else
        {
            /* no operation */
        }
        
        /* Authenticate CUSTIDB */
        l_bu4_returnValue = R_RFD_IDAuth(R_RFD_ID_CUSTIDB, l_bu1_CUSTIDx);
        
        /* Check return value */
        if (l_bu4_returnValue != R_RFD_OK)
        {
            l_bl1_errorFlag = R_RFD_TRUE;
        }
        else
        {
            /* no operation */
        }
        
        /* Authenticate CUSTIDC */
        l_bu4_returnValue = R_RFD_IDAuth(R_RFD_ID_CUSTIDC, l_bu1_CUSTIDx);
        
        /* Check return value */
        if (l_bu4_returnValue != R_RFD_OK)
        {
            l_bl1_errorFlag = R_RFD_TRUE;
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
    return l_bl1_errorFlag;
}

T_u1  bu1_WriteData[R_RFD_LENGTH_512BYTES] = {0};

uint8 R_FLS_IF_Erase(void)
{
    T_u4            l_bu4_loopCount = 0;
    T_u4_RFDReturn  l_bu4_returnValue = 0;
    T_bl            l_bl1_errorFlag = 0;

    /* Create writing data */
    for (l_bu4_loopCount = 0UL; l_bu4_loopCount < 512UL; l_bu4_loopCount++)
    {
        bu1_WriteData[l_bu4_loopCount] = (T_u1)(l_bu4_loopCount); /* !CERT-C rule INT30 (QAC message 3383) */
    }                                                                      /* !QAC message 3120                     */

    l_bu4_returnValue = Sample_CodeFlashControl((T_u4_RfdAddress)0x00100000,
                                                    (T_u4_RfdAddress)0x00103FFF,
                                                    (T_pu4_RfdBuffer)&bu1_WriteData[0]);
    /* Check return value */
    if (l_bu4_returnValue != R_RFD_OK)
    {
        l_bl1_errorFlag = R_RFD_TRUE;
    }
    else
    {
        /* no operation */
    }
    return l_bl1_errorFlag;
}

uint8 R_FLS_IF_DeInit(void)
{
    T_u4_RFDReturn  l_bu4_returnValue;                  /* Return value for this function        */
    T_bl            l_bl1_errorFlag;                    /* Error flag                            */
    
    l_bl1_errorFlag    = R_RFD_FALSE;

    /* Property Area Control */
    if (l_bl1_errorFlag == R_RFD_FALSE)     /* !CERT-C rule INT02 (QAC message 2100)      s*/
    {
        /****************************************/
        /*  Execute Sample_PropertyAreaControl  */
        /****************************************/
        l_bu4_returnValue = Sample_PropertyAreaControl();
        
        /* Check return value */
        if (l_bu4_returnValue != R_RFD_OK)
        {
            l_bl1_errorFlag = R_RFD_TRUE;
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
    
    if (l_bl1_errorFlag == R_RFD_FALSE)     /* !CERT-C rule INT02 (QAC message 2100) */
    {
        /* FHVE Protect OFF (FACI0) */
        l_bu4_returnValue = R_RFD_SetFHVE(R_RFD_FACI0, R_RFD_FHVE_PROTECT_ON);
        
        if (l_bu4_returnValue != R_RFD_OK)
        {
            l_bl1_errorFlag = R_RFD_TRUE;
        }
        else
        {
            /* FHVE Protect OFF (FACI1) */
            l_bu4_returnValue = R_RFD_SetFHVE(R_RFD_FACI1, R_RFD_FHVE_PROTECT_ON);
            
            if (l_bu4_returnValue != R_RFD_OK)
            {
                l_bl1_errorFlag = R_RFD_TRUE;
            }
            else
            {
                /* no operation */
            }
        }
    }
    else
    {
        /* no operation */
    }
    return l_bl1_errorFlag;
}

/*****************************************************************************
--------------------- Static functions --------------------------------------
 *****************************************************************************/
