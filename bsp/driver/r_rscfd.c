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
#include "r_rscfd.h"
#include "r_rscfd_reg.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define CAN_MAX_NUM 1
#define EQUAL_BAND(bits,val)      ((bits)==((val)&(bits)))

#define GM_STOP               0xFFU
#define GM_OPS                0U
#define GM_RESET              1U
#define GM_TEST               2U

#define CM_STOP               0xFFU
#define CM_COMMU              0U
#define CM_RESET              1U
#define CM_HALT               2U

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global static variables
 *****************************************************************************/
static uint32 Gsu4Rscfd[CAN_MAX_NUM] = {
    RSCFD0_base,
};

static uint8 Gsu1aDlcTbl[16] = {
    0U,  1U,  2U,  3U,  4U,  5U,  6U,  7U,
    8U,  12U, 16U, 20U, 24U, 32U, 48U, 64U,
};
static uint8 Gsu1GlobalCfgInit = 0U;
static uint8 Gsu1GlobalMode = GM_STOP;
/*****************************************************************************
 Static functions
 *****************************************************************************/

/*****************************************************************************
--------------------- Global functions --------------------------------------
 *****************************************************************************/

static void RSCFD_RxFifoIinit(uint8 Pu1Unit, Rscfd_CanCfg PstCfg)
{
    uint8 Lu1Loop;
    for (Lu1Loop = 0U; Lu1Loop < PstCfg.stpGCFG->u4RxFifoSize; Lu1Loop++)
    {
        CFDRFCC(Gsu4Rscfd[Pu1Unit], Lu1Loop) = PstCfg.stpGCFG->u4pRxFifo[Lu1Loop];
    }
}

static void RSCFD_RxTxFifoIinit(uint8 Pu1Unit, Rscfd_CanCfg PstCfg)
{
    uint8 Lu1Loop;
    for (Lu1Loop = 0U; Lu1Loop < PstCfg.stpGCFG->u4RxTxFifoSize; Lu1Loop++)
    {
        CFDCFCC(Gsu4Rscfd[Pu1Unit], Lu1Loop) = PstCfg.stpGCFG->u4pRxTxFifo[Lu1Loop];
    }
}

static void RSCFD_ChangeMode(uint8 Pu1Unit, uint8 Pu1Mode)
{
    switch (Pu1Mode)
    {
        case GM_STOP:
            if (!EQUAL_BAND(0x04UL, CFDGCTR(Gsu4Rscfd[Pu1Unit])))
            {
                CFDGCTR(Gsu4Rscfd[Pu1Unit]) = (CFDGCTR(Gsu4Rscfd[Pu1Unit]) & 0xFFFFFFFCUL) | 0x01UL;
                CFDGCTR(Gsu4Rscfd[Pu1Unit]) |= 0x04UL;
            }
            break;
        case GM_OPS:
            if (EQUAL_BAND(0x04UL, CFDGCTR(Gsu4Rscfd[Pu1Unit])))
            {
                CFDGCTR(Gsu4Rscfd[Pu1Unit]) &= 0xFFFFFFFBUL;
            }
            CFDGCTR(Gsu4Rscfd[Pu1Unit]) &= 0xFFFFFFFCUL;
            break;
        case GM_RESET:
            if (EQUAL_BAND(0x04UL, CFDGCTR(Gsu4Rscfd[Pu1Unit])))
            {
                CFDGCTR(Gsu4Rscfd[Pu1Unit]) &= 0xFFFFFFFBUL;
            }
            CFDGCTR(Gsu4Rscfd[Pu1Unit]) = (CFDGCTR(Gsu4Rscfd[Pu1Unit]) & 0xFFFFFFFCUL) | 0x01UL;
            break;
        case GM_TEST:
            if (EQUAL_BAND(0x04UL, CFDGCTR(Gsu4Rscfd[Pu1Unit])))
            {
                CFDGCTR(Gsu4Rscfd[Pu1Unit]) &= 0xFFFFFFFBUL;
            }
            CFDGCTR(Gsu4Rscfd[Pu1Unit]) = (CFDGCTR(Gsu4Rscfd[Pu1Unit]) & 0xFFFFFFFCUL) | 0x02UL;
            break;
        default:
            break;
    }
}

static void RSCFD_ChangeChMode(uint8 Pu1Unit, uint8 Pu1Channel, uint8 Pu1Mode)
{
    switch (Pu1Mode)
    {
        case CM_STOP:
            if (!EQUAL_BAND(0x04UL, CFDCCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel)))
            {
                CFDCCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel) = (CFDCCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel) & 0xFFFFFFFCUL) | 0x01UL;
                CFDCCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel) |= 0x04UL;
            }
            break;
        case CM_COMMU:
            if (EQUAL_BAND(0x04UL, CFDCCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel)))
            {
                CFDCCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel) &= 0xFFFFFFFBUL;
            }
            CFDCCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel) &= 0xFFFFFFF8UL;
            break;
        case CM_RESET:
            if (EQUAL_BAND(0x04UL, CFDCCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel)))
            {
                CFDCCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel) &= 0xFFFFFFFBUL;
            }
            CFDCCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel) = (CFDCCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel) & 0xFFFFFFFCUL) | 0x01UL;
            break;
        case CM_HALT:
            if (EQUAL_BAND(0x04UL, CFDCCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel)))
            {
                CFDCCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel) &= 0xFFFFFFFBUL;
            }
            CFDCCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel) = (CFDCCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel) & 0xFFFFFFFCUL) | 0x02UL;
            break;
        default:
            break;
    }
}


static uint8 RSCFD_SetRecvRule(uint8 Pu1Unit, Rscfd_CanCfg PstCfg)
{
    uint8 Lu1Rtn = 0U;
    uint32 Lu4CfdgAflcfg0 = 0UL;
    uint32 Lu2RecvRuleNum = 0U;
    uint16 Lu2RuleIdx = 0U;
    volatile uint32 *Lvu4pRegPtr;


    Lu2RecvRuleNum += PstCfg.stpGCFG->u1pRxRuleSize[0];
    Lu4CfdgAflcfg0 |= (PstCfg.stpGCFG->u1pRxRuleSize[0] << 16U);
    Lu2RecvRuleNum += PstCfg.stpGCFG->u1pRxRuleSize[1];
    Lu4CfdgAflcfg0 |= (PstCfg.stpGCFG->u1pRxRuleSize[1] << 0U);
    CFDGAFLCFG(Gsu4Rscfd[Pu1Unit], 0) = Lu4CfdgAflcfg0;
    Lu4CfdgAflcfg0 = 0;
    Lu2RecvRuleNum += PstCfg.stpGCFG->u1pRxRuleSize[2];
    Lu4CfdgAflcfg0 |= (PstCfg.stpGCFG->u1pRxRuleSize[2] << 16U);
    Lu2RecvRuleNum += PstCfg.stpGCFG->u1pRxRuleSize[3];
    Lu4CfdgAflcfg0 |= (PstCfg.stpGCFG->u1pRxRuleSize[3] << 0U);
    CFDGAFLCFG(Gsu4Rscfd[Pu1Unit], 1) = Lu4CfdgAflcfg0;
    Lu4CfdgAflcfg0 = 0;
    Lu2RecvRuleNum += PstCfg.stpGCFG->u1pRxRuleSize[4];
    Lu4CfdgAflcfg0 |= (PstCfg.stpGCFG->u1pRxRuleSize[4] << 16U);
    Lu2RecvRuleNum += PstCfg.stpGCFG->u1pRxRuleSize[5];
    Lu4CfdgAflcfg0 |= (PstCfg.stpGCFG->u1pRxRuleSize[5] << 0U);
    CFDGAFLCFG(Gsu4Rscfd[Pu1Unit], 2) = Lu4CfdgAflcfg0;
    Lu4CfdgAflcfg0 = 0;
    Lu2RecvRuleNum += PstCfg.stpGCFG->u1pRxRuleSize[6];
    Lu4CfdgAflcfg0 |= (PstCfg.stpGCFG->u1pRxRuleSize[6] << 16U);
    Lu2RecvRuleNum += PstCfg.stpGCFG->u1pRxRuleSize[7];
    Lu4CfdgAflcfg0 |= (PstCfg.stpGCFG->u1pRxRuleSize[7] << 0U);
    CFDGAFLCFG(Gsu4Rscfd[Pu1Unit], 3) = Lu4CfdgAflcfg0;

    CFDGAFLECTR(Gsu4Rscfd[Pu1Unit]) = 0x0100UL;
    Lvu4pRegPtr = &CFDGAFLID(Gsu4Rscfd[Pu1Unit], 0UL);
    for (Lu2RuleIdx = 0U; Lu2RuleIdx < Lu2RecvRuleNum; Lu2RuleIdx++)
    {
        if (0U == (Lu2RuleIdx & 0x0FU))
        {
            CFDGAFLECTR(Gsu4Rscfd[Pu1Unit]) = (0x0100UL | (Lu2RuleIdx >> 4U));
            Lvu4pRegPtr  = &CFDGAFLID(Gsu4Rscfd[Pu1Unit], 0UL);
        }
        *(Lvu4pRegPtr++) = PstCfg.stpGCFG->u4apRxRule[Lu2RuleIdx][0];
        *(Lvu4pRegPtr++) = PstCfg.stpGCFG->u4apRxRule[Lu2RuleIdx][1];
        *(Lvu4pRegPtr++) = PstCfg.stpGCFG->u4apRxRule[Lu2RuleIdx][2];
        *(Lvu4pRegPtr++) = PstCfg.stpGCFG->u4apRxRule[Lu2RuleIdx][3];
    }
    CFDGAFLECTR(Gsu4Rscfd[Pu1Unit]) = 0x0000UL;
    return Lu1Rtn;
}

uint8 R_RSCFD_Init(uint8 Pu1Unit, uint8 Pu1Channel, Rscfd_CanCfg PstCfg)
{
    uint8 Lu1Rtn = 0U;

    if (!Gsu1GlobalCfgInit)
    {
        /* 1. Is the GRAMINIT flag in the RSCFDn(CFD)GSTS register 0? */
        while(EQUAL_BAND(0x08UL, CFDGSTS(Gsu4Rscfd[Pu1Unit])));
        /* 2. Transition from global stop mode to global reset mode (Set GSLPR in 
            the RSCFDn(CFD) GCTR register to 0) */
        RSCFD_ChangeMode(Pu1Unit, GM_RESET);
        /* 3. RSCFDn(CFD)GRMCFG register setting */
    }
    /* 4. Transition from channel stop mode to channel reset mode (Set CSLPR in 
        the RSCFDn(CFD) CnCTR register to 0) */
    RSCFD_ChangeChMode(Pu1Unit, Pu1Channel, CM_RESET);
    if (!Gsu1GlobalCfgInit)
    {
        /* 5. RSCFDn(CFD)GCFG register setting */
        CFDGCFG(Gsu4Rscfd[Pu1Unit]) = PstCfg.stpGCFG->u4CFDGCFG;
    }
    /* 6. RSCFDnCFDCnNCFG register setting*/
    CFDCNCFG(Gsu4Rscfd[Pu1Unit], Pu1Channel) = PstCfg.u4NCFG;
    /* 7. RSCFDnCFDCnDCFG register setting*/
    DCFG(Gsu4Rscfd[Pu1Unit], Pu1Channel) = PstCfg.u4DCFG;
    if (!Gsu1GlobalCfgInit)
    {
        /* 8. Receive rule setting */
        if (NULL != PstCfg.stpGCFG->u1pRxRuleSize)
        {
            Lu1Rtn = RSCFD_SetRecvRule(Pu1Unit, PstCfg);
        }
        /* 9. Buffer setting */
        CFDRMNB(Gsu4Rscfd[Pu1Unit]) = PstCfg.stpGCFG->u4CFDRMNB;
        if (PstCfg.stpGCFG->u4RxFifoSize > 0U)
        {
            RSCFD_RxFifoIinit(Pu1Unit, PstCfg);
        }
        if (PstCfg.stpGCFG->u4RxTxFifoSize > 0U)
        {
            RSCFD_RxTxFifoIinit(Pu1Unit, PstCfg);
        }
        /* 10. RSCFDn(CFD)GCTR register setting - Global interrupt */
        CFDGCTR(Gsu4Rscfd[Pu1Unit]) = (CFDGCTR(Gsu4Rscfd[Pu1Unit]) & 0x7UL) | (PstCfg.stpGCFG->u4CFDGCTR & 0xFFFFFFF8UL);
        CFDGFDCFG(Gsu4Rscfd[Pu1Unit]) = PstCfg.stpGCFG->u4CFDGFDCFG;
    }
    /* 11. RSCFDn(CFD)CmCTR register setting - Channel interrupt, bus off 
           recovery, error indication */
    CFDCCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel) = (CFDCCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel) & 0x7UL) | (PstCfg.u4CTR & 0xFFFFFFF8UL);
    /* 12. RSCFDnCFDCmFDCFG register setting */
    FDCFG(Gsu4Rscfd[Pu1Unit], Pu1Channel) = PstCfg.u4FDCFG;

    Gsu1GlobalCfgInit = 1U;

    return Lu1Rtn;
}

uint8 R_RSCFD_Start(uint8 Pu1Unit, uint8 Pu1Channel, Rscfd_CanCfg PstCfg)
{
    uint8 Lu1Rtn = 0U;
    if (GM_OPS != Gsu1GlobalMode)
    {
        /* 13. Transition to global operating mode (Set GMDC[1:0] in the 
            RSCFDn(CFD)GCTR register to 00B)  */
        RSCFD_ChangeMode(Pu1Unit, GM_OPS);
        Gsu1GlobalMode = GM_OPS;
    }
    /* 14. Transition to channel communication mode (Set CHMDC[1:0] in the 
           RSCFDn(CFD)CmCTR register to 00B) */
    RSCFD_ChangeChMode(Pu1Unit, Pu1Channel, CM_COMMU);
    if (PstCfg.stpGCFG->u4RxFifoSize > 0U)
    {
        RSCFD_RxFifoIinit(Pu1Unit, PstCfg);
    }
    if (PstCfg.stpGCFG->u4RxTxFifoSize > 0U)
    {
        RSCFD_RxTxFifoIinit(Pu1Unit, PstCfg);
    }
    return Lu1Rtn;
}


uint8 R_RSCFD_BuffSend(uint8 Pu1Unit, uint8 Pu1Channel, Rscfd_TxBuffData PstBuff)
{
    uint8 Lu1Rtn = 0U;
    uint8 Lu1SetDlc;
    uint8 Lu1Loop;

    if (((CFDTMSTS(Gsu4Rscfd[Pu1Unit], Pu1Channel * 64U + PstBuff.u1BuffId) >> 1U) & 0x03UL) > 0U)
    {
        CFDTMSTS(Gsu4Rscfd[Pu1Unit], Pu1Channel * 64U + PstBuff.u1BuffId) = 0x00UL;
    }
    else if(EQUAL_BAND(0x01UL, CFDTMSTS(Gsu4Rscfd[Pu1Unit], Pu1Channel * 64U + PstBuff.u1BuffId)))
    {
        Lu1Rtn = ERR00;
        return Lu1Rtn;
    }

    CFDTMID(Gsu4Rscfd[Pu1Unit], Pu1Channel, PstBuff.u1BuffId) = PstBuff.u4CFDTMID;
    CFDTMPTR(Gsu4Rscfd[Pu1Unit], Pu1Channel, PstBuff.u1BuffId) = PstBuff.u4CFDTMPTR;
    CFDTMFDCTR(Gsu4Rscfd[Pu1Unit], Pu1Channel, PstBuff.u1BuffId) = PstBuff.u4CFDTMFDCTR;
    Lu1SetDlc = (Gsu1aDlcTbl[PstBuff.u4CFDTMPTR >> 28] % 4U) ? (Gsu1aDlcTbl[PstBuff.u4CFDTMPTR >> 28] / 4U + 1) : (Gsu1aDlcTbl[PstBuff.u4CFDTMPTR >> 28] / 4U);

    for (Lu1Loop = 0U; Lu1Loop < Lu1SetDlc; Lu1Loop++)
    {
        CFDTMDF(Gsu4Rscfd[Pu1Unit], Pu1Channel, PstBuff.u1BuffId, Lu1Loop) = PstBuff.u4pCFDTMDF[Lu1Loop];
    }

    if (R_OK == Lu1Rtn)
    {
        CFDTMC(Gsu4Rscfd[Pu1Unit], Pu1Channel * 64U + PstBuff.u1BuffId) = PstBuff.u4CFDTMC;
    }

    return Lu1Rtn;
}

uint8 R_RSCFD_Stop(uint8 Pu1Unit, uint8 Pu1Channel)
{
    uint8 Lu1Rtn = 0U;
    if (GM_OPS != Gsu1GlobalMode)
    {
        /* 13. Transition to global operating mode (Set GMDC[1:0] in the 
            RSCFDn(CFD)GCTR register to 00B)  */
        RSCFD_ChangeMode(Pu1Unit, GM_OPS);
        Gsu1GlobalMode = GM_OPS;
    }
    /* 14. Transition to channel communication mode (Set CHMDC[1:0] in the 
           RSCFDn(CFD)CmCTR register to 00B) */
    RSCFD_ChangeChMode(Pu1Unit, Pu1Channel, CM_STOP);
    return Lu1Rtn;
}

uint8 R_RSCFD_DeInit(uint8 Pu1Unit, uint8 Pu1Channel)
{
    uint8 Lu1Rtn = 0U;
    RSCFD_ChangeChMode(Pu1Unit, Pu1Channel, CM_STOP);
    RSCFD_ChangeMode(Pu1Unit, GM_STOP);
    Gsu1GlobalMode = GM_STOP;
    Gsu1GlobalCfgInit = 0U;
    return Lu1Rtn;
}


uint8 R_RSCFD_ReadRxFifo(uint8 Pu1Unit, uint8 Pu1Channel, Rscfd_RxFifoData *PstpRxFifo)
{
    uint8 Lu1Rtn = 0U;
    uint8 Lu1SetDlc;
    uint8 Lu1Loop;
    if (!(CFDRFSTS(Gsu4Rscfd[Pu1Unit], PstpRxFifo->u4RxFifoId) & 0x01UL))
    {
        PstpRxFifo->u4CFDRFID = CFDRFID(Gsu4Rscfd[Pu1Unit], PstpRxFifo->u4RxFifoId);
        PstpRxFifo->u4CFDRFPTR = CFDRFPTR(Gsu4Rscfd[Pu1Unit], PstpRxFifo->u4RxFifoId);
        PstpRxFifo->u4CFDRFFDSTS = CFDRFFDSTS(Gsu4Rscfd[Pu1Unit], PstpRxFifo->u4RxFifoId);

        Lu1SetDlc = (Gsu1aDlcTbl[CFDRFPTR(Gsu4Rscfd[Pu1Unit], PstpRxFifo->u4RxFifoId) >> 28] % 4U) ? (Gsu1aDlcTbl[CFDRFPTR(Gsu4Rscfd[Pu1Unit], PstpRxFifo->u4RxFifoId) >> 28] / 4U + 1) : (Gsu1aDlcTbl[CFDRFPTR(Gsu4Rscfd[Pu1Unit], PstpRxFifo->u4RxFifoId) >> 28] / 4U);
   
        for (Lu1Loop = 0U; Lu1Loop < Lu1SetDlc; Lu1Loop++)
        {
            PstpRxFifo->u4pCFDRFDF[Lu1Loop] = CFDRFDF(Gsu4Rscfd[Pu1Unit], Lu1Loop, PstpRxFifo->u4RxFifoId);
        }

        CFDRFPCTR(Gsu4Rscfd[Pu1Unit], PstpRxFifo->u4RxFifoId) = 0xFFUL;
        CFDRFSTS(Gsu4Rscfd[Pu1Unit], PstpRxFifo->u4RxFifoId) = 0x00UL;
    }
    else
    {
        Lu1Rtn = ERR00;
    }
    return Lu1Rtn;
}

uint8 R_RSCFD_ReadRxTxFifo(uint8 Pu1Unit, uint8 Pu1Channel, Rscfd_RxTxFifoData *PstpRxTxFifo)
{
    uint8 Lu1Rtn = 0U;
    uint8 Lu1SetDlc;
    uint8 Lu1Loop;
    if (!(CFDCFSTS(Gsu4Rscfd[Pu1Unit], PstpRxTxFifo->u4RxTxFifoId + (Pu1Channel * 3U)) & 0x01UL))
    {
        PstpRxTxFifo->u4CFDCFID = CFDCFID(Gsu4Rscfd[Pu1Unit], PstpRxTxFifo->u4RxTxFifoId + Pu1Channel * 3U);
        PstpRxTxFifo->u4CFDCFPTR = CFDCFPTR(Gsu4Rscfd[Pu1Unit], PstpRxTxFifo->u4RxTxFifoId + Pu1Channel * 3U);
        PstpRxTxFifo->u4CFDCFFDCSTS = CFDCFFDSTS(Gsu4Rscfd[Pu1Unit], PstpRxTxFifo->u4RxTxFifoId + Pu1Channel * 3U);

        Lu1SetDlc = (Gsu1aDlcTbl[CFDCFPTR(Gsu4Rscfd[Pu1Unit], PstpRxTxFifo->u4RxTxFifoId) >> 28] % 4U) ? (Gsu1aDlcTbl[CFDCFPTR(Gsu4Rscfd[Pu1Unit], PstpRxTxFifo->u4RxTxFifoId) >> 28] / 4U + 1) : (Gsu1aDlcTbl[CFDCFPTR(Gsu4Rscfd[Pu1Unit], PstpRxTxFifo->u4RxTxFifoId) >> 28] / 4U);

        for (Lu1Loop = 0U; Lu1Loop < Lu1SetDlc; Lu1Loop++)
        {
            PstpRxTxFifo->u4pCFDCFDF[Lu1Loop] = CFDCFDF(Gsu4Rscfd[Pu1Unit], Lu1Loop, PstpRxTxFifo->u4RxTxFifoId + Pu1Channel * 3U);
        }

        CFDCFPCTR(Gsu4Rscfd[Pu1Unit], PstpRxTxFifo->u4RxTxFifoId + Pu1Channel * 3U) = 0xFFUL;
        CFDCFSTS(Gsu4Rscfd[Pu1Unit], PstpRxTxFifo->u4RxTxFifoId + Pu1Channel * 3U) = 0x00UL;
    }
    else
    {
        Lu1Rtn = ERR00;
    }
    return Lu1Rtn;
}

