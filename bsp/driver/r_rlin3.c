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
#include "r_rlin3.h"

#include "r_rlin3_reg.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define RLIN3_RESET          0U
#define RLIN3_WAKE           1U
#define RLIN3_OPS            2U
#define RLIN3_TSET           3U
#define EQUAL_BAND(bits,val)      ((bits)==((val)&(bits)))

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global static variables
 *****************************************************************************/
static uint32 Gsu4Rlin3[] = {
    RLIN30_base,
    RLIN31_base,
    RLIN32_base,
    RLIN33_base,
    RLIN34_base,
    RLIN35_base,
    RLIN36_base,
    RLIN37_base,
    RLIN38_base,
    RLIN39_base,
    RLIN310_base,
    RLIN311_base,
};

static uint32 Gsu4aUart[] = {
    RLIN30_base,
    RLIN31_base,
    RLIN32_base,
    RLIN33_base,
    RLIN34_base,
    RLIN35_base,
    RLIN36_base,
    RLIN37_base,
    RLIN38_base,
    RLIN39_base,
    RLIN310_base,
    RLIN311_base,
};

/*****************************************************************************
 Static functions
 *****************************************************************************/
static void RLIN3_ModeChange(uint8 Pu1Unit, uint8 Pu1Mode);

/*****************************************************************************
--------------------- Global functions --------------------------------------
 *****************************************************************************/
/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_RLIN3_Init(uint8 Pu1Uint, Rlin3_Cfg PstCfg)
{
    RLIN3_ModeChange(Pu1Uint, RLIN3_RESET);
    LWBR(Gsu4Rlin3[Pu1Uint]) = PstCfg.u1LWBR;
    LBRP0(Gsu4Rlin3[Pu1Uint]) = PstCfg.u1LBRP0;
    LBRP1(Gsu4Rlin3[Pu1Uint]) = PstCfg.u1LBRP1;
    LMD(Gsu4Rlin3[Pu1Uint]) = PstCfg.u1LMD;
    LBFC(Gsu4Rlin3[Pu1Uint]) = PstCfg.u1LBFC;
    LSC(Gsu4Rlin3[Pu1Uint]) = PstCfg.u1LSC;
    LWUP(Gsu4Rlin3[Pu1Uint]) = PstCfg.u1LWUP;
    LIE(Gsu4Rlin3[Pu1Uint]) = PstCfg.u1LIE;
    LEDE(Gsu4Rlin3[Pu1Uint]) = PstCfg.u1LEDE;
    RLIN3_ModeChange(Pu1Uint, RLIN3_OPS);
    return R_OK;
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_RLIN3_Transmit(uint8 Pu1Uint, Rlin3_TxData PstData)
{
    uint8 Lu1Loop;
    LIDB(Gsu4Rlin3[Pu1Uint]) = PstData.u1LIDB;
    LDFC(Gsu4Rlin3[Pu1Uint]) = PstData.u1LDFC;
    if (EQUAL_BAND(0x10U, PstData.u1LDFC))
    {
        for (Lu1Loop = 0U; Lu1Loop < (PstData.u1LDFC & 0x0FU); Lu1Loop++)
        {
            LDBR(Gsu4Rlin3[Pu1Uint], Lu1Loop + 1U) = PstData.u1LDBR[Lu1Loop];
        }
    }

    LTRC(Gsu4Rlin3[Pu1Uint]) = PstData.u1LTRC;
    return R_OK;
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_RLIN3_GetTransmitStatus(uint8 Pu1Uint)
{
    return (!LST(Gsu4Rlin3[Pu1Uint]) & 0xFEU);
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_RLIN3_Receive(uint8 Pu1Uint, Rlin3_RxData *PstpData)
{
    uint8 Lu1Rtn = R_OK;
    uint8 Lu1Loop;
    if (EQUAL_BAND(0x02U, LST(Gsu4Rlin3[Pu1Uint])) && (!EQUAL_BAND(0x10U, LDFC(Gsu4Rlin3[Pu1Uint]))))
    {
        PstpData->u1LIDB = LIDB(Gsu4Rlin3[Pu1Uint]);
        PstpData->u1LDFC = LDFC(Gsu4Rlin3[Pu1Uint]);
        PstpData->u1LCBR = LCBR(Gsu4Rlin3[Pu1Uint]);
        for (Lu1Loop = 0U; Lu1Loop < (PstpData->u1LDFC & 0x0FU); Lu1Loop++)
        {
            PstpData->u1LDBR[Lu1Loop] = LDBR(Gsu4Rlin3[Pu1Uint], Lu1Loop + 1U);
        }
    }
    else
    {
        Lu1Rtn = ERR00;
    }

    return Lu1Rtn;
}

/*****************************************************************************
--------------------- Static functions --------------------------------------
 *****************************************************************************/
/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
static void RLIN3_ModeChange(uint8 Pu1Unit, uint8 Pu1Mode)
{
    switch (Pu1Mode)
    {
        case RLIN3_RESET:
            LCUC(Gsu4Rlin3[Pu1Unit]) = LCUC(Gsu4Rlin3[Pu1Unit]) & 0xFEU;
            while (0U != (LMST(Gsu4Rlin3[Pu1Unit]) & 0xFEU));
            break;
        case RLIN3_WAKE:
            LCUC(Gsu4Rlin3[Pu1Unit]) = LCUC(Gsu4Rlin3[Pu1Unit]) & 0xFDU | 0x01U;
            while (0x01U != LMST(Gsu4Rlin3[Pu1Unit]));
            break;
        case RLIN3_OPS:
            LCUC(Gsu4Rlin3[Pu1Unit]) = LCUC(Gsu4Rlin3[Pu1Unit]) | 0x03U;
            while (0x02U != LMST(Gsu4Rlin3[Pu1Unit]));
            break;
        case RLIN3_TSET:
            break;
        default:
            break;
    }
}


uint8 R_UART_Init(uint8 Pu1Unit,uint32 Pu4Band, uint8 Pu1Format)
{
    uint16 Lu2Timeout = 0xFFFFU;
    uint8 Lu1Error = 0;
    /*Reset Mode*/
    UART_LCUC(Gsu4aUart[Pu1Unit]) = 0x00U;
    while((Lu2Timeout--)&&(UART_LMST(Gsu4aUart[Pu1Unit])!=0x00U));
    Lu1Error = Lu2Timeout?0:1;
    /*Prescaler Reset*/
    UART_LWBR(Gsu4aUart[Pu1Unit]) &= 0x00;
    /*Baud Rate Configure for 10Mhz clock source*/
    switch(Pu4Band)
    {
        case 19200: UART_LWBR(Gsu4aUart[Pu1Unit]) |= 0x80;  UART_LBRP01(Gsu4aUart[Pu1Unit])= 0x1CE; break;
        case 115200: UART_LWBR(Gsu4aUart[Pu1Unit]) |= 0x60;  UART_LBRP01(Gsu4aUart[Pu1Unit])= 0x62;  break;
        default:Lu1Error=1; break;
    }


    /*Enable Noise Filter*/
    UART_LMD(Gsu4aUart[Pu1Unit]) &= ~(0x1U<<5);

    /*Set Data Format*/
    UART_LBFC(Gsu4aUart[Pu1Unit]) = Pu1Format;
    /*Set Interrupt Generation Timing:Transmission Completion*/
    UART_LUOR1(Gsu4aUart[Pu1Unit]) |= (0x1U<<3);
    
    /*Uart Mode*/
    UART_LMD(Gsu4aUart[Pu1Unit]) = 0x01U;
    UART_LCUC(Gsu4aUart[Pu1Unit]) = 0x01U;
    Lu2Timeout = 0xFFFFU;
    while((Lu2Timeout--)&&(UART_LMST(Gsu4aUart[Pu1Unit])!=0x01U));
    Lu1Error = Lu2Timeout?0:1;

    return Lu1Error;

}
/*****************************************************************************
 * Declaration : void R_UART_Start(uint8 Pu1Unit)
 * Description : Enable receive and transmit 
 * Parameters  : Pu1Unit - Hardware unit
 * Return      : None
 *****************************************************************************/

void R_UART_Start(uint8 Pu1Unit)
{
    /*Enable recption/transmission*/
    UART_LUOER(Gsu4aUart[Pu1Unit]) |= 0x03;

}
/*****************************************************************************
 * Declaration : void R_UART_Stop(uint8 Pu1Unit)
 * Description : Disable receive and transmit
 * Parameters  : Pu1Unit - Hardware unit
 * Return      : None
 *****************************************************************************/
void R_UART_Stop(uint8 Pu1Unit)
{
    /*Disable recption/transmission*/
    UART_LUOER(Gsu4aUart[Pu1Unit]) &= 0xFC;

}
/*****************************************************************************
 * Declaration : void R_UART_Transmit(uint8 Pu1Unit,uint8 Pu1TxByte)
 * Description : Transmit a byte
 * Parameters  : Pu1Unit - Hardware unit
 *               Pu1TxByte - Data to Transmit
 * Return      : None
 *****************************************************************************/

void R_UART_Transmit(uint8 Pu1Unit,uint8 Pu1TxByte)
{
    uint8 Lu1value;
    /*Wait for last transmission complete*/
    do
    {
        Lu1value = (UART_LST(Gsu4aUart[Pu1Unit]) & 0x10) >> 4;
    }while (Lu1value != 0);
    /*Transmit data*/
    UART_LUTDR(Gsu4aUart[Pu1Unit]) = (uint16)Pu1TxByte;   
}
/*****************************************************************************
 * Declaration : uint8 R_UART_GetChar(uint8 Pu1Unit,uint8* Pu1pRxCh)
 * Description : Get char by UART
 * Parameters  : Pu1Unit - Hardware unit
 *               Pu1pRxCh - Pointer of received char value
 * Return      : 0 - Received Complete.
 *               1 - Received Failed.
 *****************************************************************************/
uint8 R_UART_GetChar(uint8 Pu1Unit,uint8* Pu1pRxCh)
{
    uint8 Lu1Rtn = 0;

    /* Check if error detected */
    if ((UART_LUTDR(Gsu4aUart[Pu1Unit]  & 0x08) != 0x00))
    {
        /*Clear Errro Flag*/
        UART_LUTDR(Gsu4aUart[Pu1Unit]) = 0x00;
    }
    return Lu1Rtn;
}
/*****************************************************************************
 * Declaration : void R_UART_PutDebugChar(uint8 Pu1Unit,uint8 Pu1Ch)
 * Description : Send a byte 
 * Parameters  : Pu1Unit - Hardware unit
 *               Pu1Ch - Data to Transmit
 * Return      : None
 *****************************************************************************/
void R_UART_PutDebugChar(uint8 Pu1Unit,uint8 Pu1Ch)
{
    R_UART_Transmit(Pu1Unit,Pu1Ch);
}
/*****************************************************************************
 * Declaration : void R_UART_PutChar(uint8 Pu1Unit,uint8 Pu1Ch)
 * Description : Send a byte 
 * Parameters  : Pu1Unit - Hardware unit
 *               Pu1Ch - Data to Transmit
 * Return      : None
 *****************************************************************************/
void R_UART_PutChar(uint8 Pu1Unit,uint8 Pu1Ch)
{
    {
        R_UART_PutDebugChar(Pu1Unit,Pu1Ch);
    }  
}

/*****************************************************************************
 * Declaration : void R_UART_PutNum(uint8 Pu1Unit,uint32 Pu4Num)
 * Description : Send a number 
 * Parameters  : Pu1Unit - Hardware unit
 *               Pu4Num - Number to Transmit
 * Return      : None
 *****************************************************************************/
void R_UART_PutNum(uint8 Pu1Unit,uint32 Pu4Num)
{
    uint32 Pu4Count = 0;
    uint8 Pu1Str[11] = {0};
    
    while(Pu4Num != 0)
    {
    Pu1Str[9-Pu4Count] = Pu4Num % 10 + 48;
    Pu4Num /= 10;
    Pu4Count++;
    }
    
    Pu1Str[10] = 0;
    
    while(Pu4Count-->0)
    R_UART_PutChar(Pu1Unit,Pu1Str[9-Pu4Count]);   

}

/*****************************************************************************
 * Declaration : void R_UART_ReceiveInterrupt_Handler(uint8 Pu1Unit)
 * Description : Process receive interrupt
 * Parameters  : Pu1Unit - Hardware unit
 * Return      : None
 *****************************************************************************/
void R_UART_ReceiveInterrupt_Handler(uint8 Pu1Unit)
{
    uint8 Lu1Data =  (uint8)(UART_LURDR(Gsu4aUart[Pu1Unit]));
}
/*****************************************************************************
 * Declaration : void R_UART_TransmitInterrupt_Handler(uint8 Pu1Unit)
 * Description : Process transmit interrupt
 * Parameters  : Pu1Unit - Hardware unit
 * Return      : None
 *****************************************************************************/
void R_UART_TransmitInterrupt_Handler(uint8 Pu1Unit)
{
    
}
/*****************************************************************************
 * Declaration : void R_UART_ErrorInterrupt_Handler(uint8 Pu1Unit)
 * Description : Process error interrupt
 * Parameters  : Pu1Unit - Hardware unit
 * Return      : None
 *****************************************************************************/
void R_UART_ErrorInterrupt_Handler(uint8 Pu1Unit)
{
    
}

