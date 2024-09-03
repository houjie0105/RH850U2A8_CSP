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
#include "main.h"

#include "r_compiler.h"

#include "r_clk.h"
#include "r_br.h"
#include "r_stbc.h"
#include "r_intc.h"

#include "r_adcj.h"
#include "r_port.h"
#include "r_ostm.h"
#include "r_rscfd.h"
#include "r_mspi.h"
#include "r_rlin3.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
//#define ADC_TEST
#define CAN_TEST
//#define MSPI_TEST
//#define RLIN_LIN_TEST
#define RLIN_UART_TEST
/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/
extern uint32 Gu4Task_100MsFlag;

/*****************************************************************************
 Global static variables
 *****************************************************************************/
volatile uint8 Gu1PerInitFinished = 1UL;

#define DIM(a) (sizeof(a)/sizeof((a)[0]))

#ifdef CAN_TEST
static uint32 Gsu1aTxDataBuff[16] = {
    0x00010203U, 0x04050607U,
    0x00010203U, 0x04050607U,
    0x00010203U, 0x04050607U,
    0x00010203U, 0x04050607U,
    0x00010203U, 0x04050607U,
    0x00010203U, 0x04050607U,
    0x00010203U, 0x04050607U,
    0x00010203U, 0x04050607U,
};

static const uint8 Gscu1aRxRuleSize[8] = {
    0U, 1U, 0U, 0U, 0U, 0U, 0U, 0U,
};

/* CFDGAFLID */
/* CFDGAFLM */
/* CFDGAFLP0_ */
/* CFDGAFLP1_ */
static const uint32 Gscu4aaCanRecvRule[][4] = {
    {
        GAFLID(0x604UL), 
        GAFLIDM(0x7FFUL),
        0x00000000UL,
        GAFLFDPD(1UL << 0U)
    },
};

/* CFDRFCC */
static const uint32 Gscu4aRxFifoCfg[] = {
    RFIM | RFDC(1UL) | RFPLS(7UL) | RFIE | RFE,
};

/* CFDCFCC */
static const uint32 Gscu4aRxTxFifoCfg[] = {
    0x00000000UL,
};

static const CanGlobalCfg GscstCanGlobal = {
    RSCFD_TSRST,
    RSCFD_ITRCP(1UL) | RSCFD_TSP(0UL),
    RSCFD_TSCCFG(0UL),
    RSCFD_RMPLS(0UL) | (RSCFD_NRXMB(2UL)),
    (uint8 *)Gscu1aRxRuleSize,
    (uint32 (*)[4])Gscu4aaCanRecvRule,
    DIM(Gscu4aRxFifoCfg), 
    (uint32 *)Gscu4aRxFifoCfg,
    DIM(Gscu4aRxTxFifoCfg),
    (uint32 *)Gscu4aRxTxFifoCfg,
};

static const Rscfd_CanCfg GscstCanChCfg0 = {
    (CanGlobalCfg *)(&GscstCanGlobal),
    RSCFD_BOM(0UL),
    0x00U,
    RSCFD_NTSEG2(5UL) | RSCFD_NTSEG1(12UL) | RSCFD_NSJW(0UL) | RSCFD_NBRP(7UL),
    RSCFD_DSJW(0UL) | RSCFD_DTSEG2(1UL) | RSCFD_DTSEG1(1UL) | RSCFD_DBRP(7UL),
};

static const Rscfd_TxBuffData GscstSendBuff[] = {
    {
        0U,
        0U,
        RSCFD_TMID(0x605UL),
        RSCFD_TMDLC(0x08UL),
        0x00,
        RSCFD_TMTR,
        (uint32*)(Gsu1aTxDataBuff),
    },
    {
        0U,
        0U,
        RSCFD_TMID(0x7B3UL),
        RSCFD_TMDLC(0x08UL),
        0x00,
        RSCFD_TMTR,
        (uint32*)(Gsu1aTxDataBuff),
    },
};
#endif

#ifdef MSPI_TEST
static const SpiChannelCfg GscsSpi0CfgCss0 = {
        /* CFG0 */
        TRXE | MODE_DIRECT_MEM,
        /* CFG1 */
        CSRI_INACTIVE | CPOL | CPHA,
        /* CFG2 */
        0x20,
        /* CFG3 */
        0x10A,// 80/4/(A+1) = 1M
        /* CFG4 */
        0x00,
        /* SEUP */
        0x01,
        /* HOLD */
        0x01,
        /* IDLE */
        0x01,
        /* INDA */
        0x01,
        /* CFSET */
        0x01,
        /* SSEL */
        CSS0,
};
#endif

#ifdef RLIN_LIN_TEST
static Rlin3_Cfg GsstRlin3Cfg = {
    /* 19200bps fixed mode */
    0X01U,
    0x02U,
    0x81U,
    RLIN3_LMD(0U),
    0x15U,
    0x17U,
    0x30U,
    0x03U,
    0x00U,
};
static Rlin3_TxData GsstRlin3IdCfg = {
        0x01U,
        0x18U,
        0x00U,
        { 0x01U, 0x02U, 0x03U, 0x04U, 0x05U, 0x06U, 0x07U, 0x08U, },
};
#endif

/*****************************************************************************
 Static functions
 *****************************************************************************/

/*****************************************************************************
--------------------- Global functions --------------------------------------
 *****************************************************************************/
void Main_Init(void)
{
    uint32 Lu4Peid;
    R_BR_SetChk(0U);
    while (!R_BR_GetSync(0U));
    Lu4Peid = GetPEID();
    if (0UL == (Lu4Peid & 0x1FUL))
    {
        R_CLK_Init();

        R_STBC_CfgMsr(MSR_OSTM, 0x00UL);
        R_STBC_CfgMsr(MSR_RSCFD, 0x00UL);
        R_STBC_CfgMsr(MSR_MSPI, 0x00UL);
        R_STBC_CfgMsr(MSR_RLIN3, 0x00UL);
        R_STBC_CfgMsr(MSR_ADCJ_ISO, 0x00UL);
        R_STBC_CfgMsr(MSR_ADCJ_AWO, 0x00UL);

        R_PORT_EnablePort();

        /* GPIO Output */
        R_PORT_Init(10, 0, 0);

        /* CAN1 TX */
        R_PORT_Init(4, 9, PORT_PMC | PORT_APF3);
        /* CAN1 RX */
        R_PORT_Init(4, 10, PORT_PMC | PORT_APF6 | PORT_PM | PORT_PU);

        /* CAN1 STB Set High */
        R_PORT_Init(4, 11, 0x00);


        /* MSPI0SO */
        R_PORT_Init(2, 13, PORT_PMC | PORT_APF3 | PORT_PIPC);
        /* MSPI0SI */
        R_PORT_Init(2, 11, PORT_PMC | PORT_APF3 | PORT_PM);
        /* MSPI0SC */
        R_PORT_Init(2, 12, PORT_PMC | PORT_APF3);
        /* MSPI0CSS0 */
        R_PORT_Init(2, 14, PORT_PMC | PORT_APF3);

        /* RLIN32 TX */
        R_PORT_Init(2, 0, PORT_PMC | PORT_APF4);
        /* RLIN32 RX */
        R_PORT_Init(2, 1, PORT_PMC | PORT_APF4 | PORT_PM);

        R_INTC_Init(201UL, INTC_EITB & INTC_EIMK | INTC_EIP(6UL));
        R_INTC_Bind(201UL, INTC_PEID(0UL) | INTC_GPID(0UL));
        R_OSTM_InitCtl(2U, OSTM_IE);
        R_OSTM_SetCmp(2U, 0x7A1200UL);
        R_OSTM_Start(2U);

        #ifdef ADC_TEST
        R_INTC_Init(227UL, INTC_EITB & INTC_EIMK | INTC_EIP(6UL));
        R_INTC_Bind(227UL, INTC_PEID(0UL));
        R_ADCJ0_Init();
        #endif

        #ifdef CAN_TEST
        R_INTC_Init(297UL, INTC_EITB & INTC_EIMK | INTC_EIP(6UL));
        R_INTC_Bind(297UL, INTC_PEID(0UL) | INTC_GPID(0UL));

        R_RSCFD_Init(0U, 1U, GscstCanChCfg0);
        R_RSCFD_Start(0U, 1U, GscstCanChCfg0);
        #endif

        #ifdef MSPI_TEST
        R_MSPI_Global_Init(0);
        R_MSPI_Channel_Init(0, 0, GscsSpi0CfgCss0);
        #endif


        #ifdef RLIN_LIN_TEST
        R_RLIN3_Init(2, GsstRlin3Cfg);
        #endif
        #ifdef RLIN_UART_TEST
        R_UART_Init(2,115200, R_LENGTH_7BIT|R_PARITY_NONE|R_STOPBIT_1|R_MSB_FIRST);
        R_UART_Start(2);
        #endif

        Gu1PerInitFinished = 0;
    }
    else
    {
        while(Gu1PerInitFinished);
    }
    ENABLE_INTERRUPT();
}

Can_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType *PduInfo)
{
    uint8 Lu1Loop;
    for (Lu1Loop = 0U; Lu1Loop < 64U; Lu1Loop++)
    {
        ((uint8*)Gsu1aTxDataBuff)[Lu1Loop] = PduInfo->sdu[Lu1Loop];
    }
    return (Can_ReturnType)R_RSCFD_BuffSend(0U, 1U, GscstSendBuff[Hth]);
}

void Main_Idle_Task(void)
{
    uint32 Lu4Peid;
    Lu4Peid = GetPEID();
    if (0UL == (Lu4Peid & 0x1FUL))
    {
        if (Gu4Task_100MsFlag) {
            #ifdef CAN_TEST
            {
                static const uint32 Lscu1aBuff[16] = {
                    0x00010203U, 0x04050607U,
                    0x00010203U, 0x04050607U,
                    0x00010203U, 0x04050607U,
                    0x00010203U, 0x04050607U,
                    0x00010203U, 0x04050607U,
                    0x00010203U, 0x04050607U,
                    0x00010203U, 0x04050607U,
                    0x00010203U, 0x04050607U,
                };
                static Can_PduType LstCanPduType;
                LstCanPduType.length = 0x08U; /* This value does not affect sending */
                LstCanPduType.swPduHandle = 0x02U; /* This value does not affect sending */
                LstCanPduType.id = 0x00UL; /* This value does not affect sending */
                LstCanPduType.sdu = (uint8 *)Lscu1aBuff;
                Can_Write(1U, &LstCanPduType);
            }
            #endif

            #ifdef MSPI_TEST
            {
                uint32 LuTxBuff[2] = {0x01020304, 0x05060708};
                uint32 LuRxBuff[2] = {0};
                R_MSPI_Write(0, 0, LuTxBuff, LuRxBuff, 2);
            }
            #endif

            {
                #ifdef RLIN_LIN_TEST
                R_RLIN3_Transmit(2, GsstRlin3IdCfg);
                #endif
                #ifdef RLIN_UART_TEST
                static uint8 Gu1SendByte = 0xA5;
                R_UART_Transmit(2, Gu1SendByte);
                #endif
            }
            #ifdef ADC_TEST
            {
                R_ADCJ_ScanGroup_OperationOn(0, 0);
            }
            #endif

            Gu4Task_100MsFlag = 0;
        }
    }
}

/*****************************************************************************
--------------------- Static functions --------------------------------------
 *****************************************************************************/
