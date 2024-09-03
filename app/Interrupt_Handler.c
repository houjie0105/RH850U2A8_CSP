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
#include "r_compiler.h"

#include "r_rscfd.h"
#include "r_adcj.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/
extern uint32 Gu4Task_100MsFlag = 0;

/*****************************************************************************
 Global static variables
 *****************************************************************************/
 /* 64 is databyte length */
#define DIM2(a) (sizeof(a)/64U)
static uint32 Gsu4aaRxDataFIFO[][16] = {
    { 0x00010203UL, 0x04050607UL, 0x00010203UL, 0x04050607UL, \
      0x00010203UL, 0x04050607UL, 0x00010203UL, 0x04050607UL, \
      0x00010203UL, 0x04050607UL, 0x00010203UL, 0x04050607UL, \
      0x00010203UL, 0x04050607UL, 0x00010203UL, 0x04050607UL},
    { 0x00010203UL, 0x04050607UL, 0x00010203UL, 0x04050607UL, \
      0x00010203UL, 0x04050607UL, 0x00010203UL, 0x04050607UL, \
      0x00010203UL, 0x04050607UL, 0x00010203UL, 0x04050607UL, \
      0x00010203UL, 0x04050607UL, 0x00010203UL, 0x04050607UL},
    { 0x00010203UL, 0x04050607UL, 0x00010203UL, 0x04050607UL, \
      0x00010203UL, 0x04050607UL, 0x00010203UL, 0x04050607UL, \
      0x00010203UL, 0x04050607UL, 0x00010203UL, 0x04050607UL, \
      0x00010203UL, 0x04050607UL, 0x00010203UL, 0x04050607UL},
};
static Rscfd_RxFifoData GsstRxFIFO[] = {
    {
        0U, 
        0U,
        0U,
        0U,
        (uint32*)(&Gsu4aaRxDataFIFO[0][0]),
    },
    {
        1U, 
        0U,
        0U,
        0U,
        (uint32*)(&Gsu4aaRxDataFIFO[1][0]),
    },
    {
        2U, 
        0U,
        0U,
        0U,
        (uint32*)(&Gsu4aaRxDataFIFO[2][0]),
    },
};


/*****************************************************************************
 Static functions
 *****************************************************************************/

/*****************************************************************************
--------------------- Global functions --------------------------------------
 *****************************************************************************/
/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      :  
 *****************************************************************************/
#pragma interrupt Ostm_O2_100ms_Handler
void Ostm_O2_100ms_Handler(void)
{
    R_PORT_FlipPin(10, 0);
    Gu4Task_100MsFlag = 1;
}

void CanIf_RxIndication(const Can_HwType *Mailbox, const PduInfoType *PduInfoPtr)
{

}


#pragma interrupt CAN_ReceiveFIFO_Interrupt
void CAN_ReceiveFIFO_Interrupt(void)
{
    uint8 Lu1HrhIdx;
    PduInfoType LstPduInfo;
    Can_HwType LstMailbox;
    for (Lu1HrhIdx = 0U; Lu1HrhIdx < DIM2(Gsu4aaRxDataFIFO); Lu1HrhIdx++)
    {
        if (R_OK == R_RSCFD_ReadRxFifo(0U, 0U, &GsstRxFIFO[Lu1HrhIdx]))
        {
            LstMailbox.Hoh = Lu1HrhIdx;
            LstMailbox.ControllerId = 0U;
            LstMailbox.CanId = GsstRxFIFO[Lu1HrhIdx].u4CFDRFID;
            LstPduInfo.SduDataPtr = (uint8*)GsstRxFIFO[Lu1HrhIdx].u4pCFDRFDF;
            LstPduInfo.SduLength = GsstRxFIFO[Lu1HrhIdx].u4CFDRFPTR >> 28U;
            CanIf_RxIndication(&LstMailbox, &LstPduInfo);
        }
    }
}

#pragma interrupt R_Drv_ADCJ0_SG0_Interrupt
void R_Drv_ADCJ0_SG0_Interrupt(void)
{
    R_Drv_ADC_UpdateValue(0, 0);
}

/*****************************************************************************
--------------------- Static functions --------------------------------------
 *****************************************************************************/

