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
#ifndef R_RLIN3_H
#define R_RLIN3_H

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define RLIN3_LWBR0                     R_LSH(1UL, 0U)
#define RLIN3_LCKS(n)                   R_LSH((n), 2U)
#define RLIN3_BDT(n)                    R_LSH((n), 4U)
#define RLIN3_BLT(n)                    R_LSH((n), 0U)
#define RLIN3_IBS(n)                    R_LSH((n), 4U)
#define RLIN3_IBHS(n)                   R_LSH((n), 0U)
#define RLIN3_WUTL(n)                   R_LSH((n), 4U)
#define RLIN3_ERRIE                     R_LSH(1UL, 2U)
#define RLIN3_FRCIE                     R_LSH(1UL, 1U)
#define RLIN3_FTCIE                     R_LSH(1UL, 0U)
#define RLIN3_FERE                      R_LSH(1UL, 3U)
#define RLIN3_FTERE                     R_LSH(1UL, 2U)
#define RLIN3_PBERE                     R_LSH(1UL, 1U)
#define RLIN3_BERE                      R_LSH(1UL, 0U)
#define RLIN3_RTS                       R_LSH(1UL, 1U)
#define RLIN3_FTS                       R_LSH(1UL, 0U)
#define RLIN3_FSM                       R_LSH(1UL, 6U)
#define RLIN3_CSM                       R_LSH(1UL, 5U)
#define RLIN3_RFT                       R_LSH(1UL, 4U)
#define RLIN3_RFDL(n)                   R_LSH((n), 0U)
#define RLIN3_IDP1                      R_LSH(1UL, 7U)
#define RLIN3_IDP0                      R_LSH(1UL, 6U)
#define RLIN3_ID(n)                     R_LSH((n), 0U)
#define RLIN3_NSPB(n)                   R_LSH((n), 4U)
#define RLIN3_LPRS(n)                   R_LSH((n), 1U)
#define RLIN3_LRDNFS                    R_LSH(1UL, 5U)
#define RLIN3_LIOS                      R_LSH(1UL, 4U)
#define RLIN3_LMD(n)                    R_LSH((n), 0U)
#define RLIN3_LBLT                      R_LSH(1UL, 0U)
#define RLIN3_IBS(n)                    R_LSH((n), 4U)
#define RLIN3_IBHS(n)                   R_LSH((n), 0U)
#define RLIN3_SHIE                      R_LSH(1UL, 3U)
#define RLIN3_ERRIE                     R_LSH(1UL, 2U)
#define RLIN3_FRCIE                     R_LSH(1UL, 1U)
#define RLIN3_FTCIE                     R_LSH(1UL, 0U)
#define RLIN3_LTES                      R_LSH(1UL, 7U)
#define RLIN3_IPERE                     R_LSH(1UL, 6U)
#define RLIN3_SFERE                     R_LSH(1UL, 4U)
#define RLIN3_FERE                      R_LSH(1UL, 3U)
#define RLIN3_TERE                      R_LSH(1UL, 2U)
#define RLIN3_BERE                      R_LSH(1UL, 0U)
#define RLIN3_LNRR                      R_LSH(1UL, 2U)
#define RLIN3_RTS                       R_LSH(1UL, 1U)
#define RLIN3_FTS                       R_LSH(1UL, 0U)
#define RLIN3_LSS                       R_LSH(1UL, 7U)
#define RLIN3_LCS                       R_LSH(1UL, 5U)
#define RLIN3_RCDS                      R_LSH(1UL, 4U)
#define RLIN3_RFDL(n)                   R_LSH((n), 0U)
#define RLIN3_IDP1                      R_LSH(1UL, 7U)
#define RLIN3_IDP0                      R_LSH(1UL, 6U)
#define RLIN3_ID(n)                     R_LSH((n), 0U)

#define R_PARITY_NONE   0x00U
#define R_PARITY_EVEN   0x08U
#define R_PARITY_ZERO   0x10U
#define R_PARITY_ODD    0x18U
#define R_STOPBIT_1     0x00U
#define R_STOPBIT_2     0x04U
#define R_LSB_FIRST     0x00U
#define R_MSB_FIRST     0x02U
#define R_LENGTH_8BIT   0x00U
#define R_LENGTH_7BIT   0x01U

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/
typedef struct STag_Rlin3_CfgType
{
    uint8 u1LWBR;
    uint8 u1LBRP0;
    uint8 u1LBRP1;
    uint8 u1LMD;
    uint8 u1LBFC;
    uint8 u1LSC;
    uint8 u1LWUP;
    uint8 u1LIE;
    uint8 u1LEDE;
}Rlin3_Cfg;

typedef struct STag_Rlin3_TxDataType
{
    uint8 u1LTRC;
    uint8 u1LDFC;
    uint8 u1LIDB;
    uint8 u1LDBR[8];
}Rlin3_TxData;

typedef struct STag_Rlin3_RxDataType
{
    uint8 u1LDFC;
    uint8 u1LIDB;
    uint8 u1LCBR;
    uint8 u1LDBR[8];
}Rlin3_RxData;

typedef struct STag_Rlin3_RxIdCfgType
{
    uint8 u1LIDB;
    uint8 u1LDFC;
    uint8 u1Status;
    uint8 u1aTrBuff[8];
}Rlin3_RxIdCfg;

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global functions
 *****************************************************************************/
/* Common API */
extern uint8 R_RLIN3_Init(uint8 Pu1Uint, Rlin3_Cfg PstCfg);
/* For master mode */
extern uint8 R_RLIN3_Transmit(uint8 Pu1Uint, Rlin3_TxData PstData);
extern uint8 R_RLIN3_GetTransmitStatus(uint8 Pu1Uint);
extern uint8 R_RLIN3_Receive(uint8 Pu1Uint, Rlin3_RxData *PstpData);
/* For slave mode */
extern uint8 R_RLIN3_SlaveStartReceive(uint8 Pu1Uint);
extern uint8 R_RLIN3_SlaveIntHandler(uint8 Pu1Uint, Rlin3_RxIdCfg *PstpIdCfg, uint8 Pu1Num);
/* For Uart mode */
extern uint8 R_UART_Init(uint8 Pu1Unit,uint32 Pu4Band, uint8 Pu1Format);
extern void R_UART_Start(uint8 Pu1Unit);
extern void R_UART_Stop(uint8 Pu1Unit);
extern void R_UART_Transmit(uint8 Pu1Unit,uint8 Pu1TxByte);
extern uint8 R_UART_GetChar(uint8 Pu1Unit,uint8* Pu1pRxCh);
extern void R_UART_PutDebugChar(uint8 Pu1Unit,uint8 Pu1Ch);
extern void R_UART_PutChar(uint8 Pu1Unit,uint8 Pu1Ch);
extern void R_UART_PutNum(uint8 Pu1Unit,uint32 Pu4Num);

extern void R_UART_ReceiveInterrupt_Handler(uint8 Pu1Unit);
extern void R_UART_TransmitInterrupt_Handler(uint8 Pu1Unit);
extern void R_UART_ErrorInterrupt_Handler(uint8 Pu1Unit);
#endif  /* R_RLIN3_H */
