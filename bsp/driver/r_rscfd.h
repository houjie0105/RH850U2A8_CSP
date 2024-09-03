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
#ifndef R_RSCFD_H
#define R_RSCFD_H

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define RSCFD_TSRST          R_LSH(1UL, 16U)
#define RSCFD_CMPOFIE        R_LSH(1UL, 11U) 
#define RSCFD_THLEIE         R_LSH(1UL, 10U)
#define RSCFD_MEIE           R_LSH(1UL, 9U)
#define RSCFD_DEIE           R_LSH(1UL, 8U)

#define RSCFD_ITRCP(n)       R_LSH((n), 16U)
#define RSCFD_TSBTCS(n)      R_LSH((n), 13U)
#define RSCFD_TSSS           R_LSH(1UL, 12U)
#define RSCFD_TSP(n)         R_LSH((n), 8U)
#define RSCFD_CMPOC          R_LSH(1UL, 5U)
#define RSCFD_DCS            R_LSH(1UL, 4U)
#define RSCFD_MME            R_LSH(1UL, 3U)
#define RSCFD_DRE            R_LSH(1UL, 2U)
#define RSCFD_DCE            R_LSH(1UL, 1U)
#define RSCFD_TPRI           R_LSH(1UL, 0U)

#define RSCFD_TSCCFG(n)      R_LSH((n), 8U)
#define RSCFD_RPED           R_LSH(1UL, 0U)

#define RSCFD_RMPLS(n)       R_LSH((n), 8U)
#define RSCFD_NRXMB(n)       R_LSH((n), 0U)

#define RSCFD_ROM            R_LSH(1UL, 31U)
#define RSCFD_CRCT           R_LSH(1UL, 30U)
#define RSCFD_CTMS(n)        R_LSH((n), 25U)
#define RSCFD_CTME           R_LSH(1UL, 24U)
#define RSCFD_ERRD           R_LSH(1UL, 23U)
#define RSCFD_BOM(n)         R_LSH((n), 21U)
#define RSCFD_TDCVFIE        R_LSH(1UL, 19U)
#define RSCFD_SOCOIE         R_LSH(1UL, 18U)
#define RSCFD_EOCOIE         R_LSH(1UL, 17U)
#define RSCFD_TAIE           R_LSH(1UL, 16U)
#define RSCFD_ALIE           R_LSH(1UL, 15U)
#define RSCFD_BLIE           R_LSH(1UL, 14U)
#define RSCFD_OLIE           R_LSH(1UL, 13U)
#define RSCFD_BORIE          R_LSH(1UL, 12U)
#define RSCFD_BOEIE          R_LSH(1UL, 11U)
#define RSCFD_EPIE           R_LSH(1UL, 10U)
#define RSCFD_EWIE           R_LSH(1UL, 9U)
#define RSCFD_BEIE           R_LSH(1UL, 8U)
#define RSCFD_RTBO           R_LSH(1UL, 3U)

#define RSCFD_REFE           R_LSH(1UL, 29U)
#define RSCFD_FDOE           R_LSH(1UL, 28U)
#define RSCFD_TMME           R_LSH(1UL, 27U)
#define RSCFD_GWBRS          R_LSH(1UL, 26U)
#define RSCFD_GWFDF          R_LSH(1UL, 25U)
#define RSCFD_GWEN           R_LSH(1UL, 24U)
#define RSCFD_TDCO(n)        R_LSH((n), 16U)
#define RSCFD_ESIC           R_LSH(1UL, 10U)
#define RSCFD_TDCE           R_LSH(1UL, 9U)
#define RSCFD_TDCOC          R_LSH(1UL, 8U)
#define RSCFD_EOCCFG(n)      R_LSH((n), 0U)

#define RSCFD_NTSEG2(n)      R_LSH((n), 25U)
#define RSCFD_NTSEG1(n)      R_LSH((n), 17U)
#define RSCFD_NSJW(n)        R_LSH((n), 10U)
#define RSCFD_NBRP(n)        R_LSH((n), 0U)

#define RSCFD_DSJW(n)        R_LSH((n), 24U)
#define RSCFD_DTSEG2(n)      R_LSH((n), 16U)
#define RSCFD_DTSEG1(n)      R_LSH((n), 8U)
#define RSCFD_DBRP(n)        R_LSH((n), 0U)

#define RSCFD_TMIDE          R_LSH(1UL, 31U)
#define RSCFD_TMRTR          R_LSH(1UL, 20U)
#define RSCFD_THLEN          R_LSH(1UL, 29U)
#define RSCFD_TMID(n)        R_LSH((n), 0U)

#define RSCFD_TMDLC(n)       R_LSH((n), 28U)
#define RSCFD_TMPTR(n)       R_LSH((n), 16U)

#define RSCFD_TMFDF          R_LSH(1UL, 2U)
#define RSCFD_TMBRS          R_LSH(1UL, 1U)
#define RSCFD_TMESI          R_LSH(1UL, 0U)

#define RSCFD_TMOM           R_LSH(1UL, 2U)
#define RSCFD_TMTAR          R_LSH(1UL, 1U)
#define RSCFD_TMTR           R_LSH(1UL, 0U)

#define GAFLIDE              R_LSH(1UL, 31U)
#define GAFLRTR              R_LSH(1UL, 30U)
#define GAFLLB               R_LSH(1UL, 29U)
#define GAFLID(n)            R_LSH((n), 0U)

#define GAFLIDEM             R_LSH(1UL, 31U)
#define GAFLRTRM             R_LSH(1UL, 30U)
#define GAFLIDM(n)           R_LSH((n), 0U)

#define GAFLDLC(n)           R_LSH((n), 28U)
#define GAFLPTR(n)           R_LSH((n), 16U)
#define GAFLRMV              R_LSH(1UL, 15U)
#define GAFLRMDP(n)          R_LSH((n), 8U)

#define GAFLFDPU(n)          R_LSH((n), 16U)
#define GAFLFDPD(n)          R_LSH((n), 0U)

#define RFIGCV(n)            R_LSH((n), 13U)
#define RFIM                 R_LSH(1UL, 12U)
#define RFDC(n)              R_LSH((n), 8U)
#define RFPLS(n)             R_LSH((n), 4U)
#define RFIE                 R_LSH(1UL, 1U)
#define RFE                  R_LSH(1UL, 0U)

#define CFITT(n)             R_LSH((n), 24U)
#define CFDC(n)              R_LSH((n), 21U)
#define CFTML(n)             R_LSH((n), 16U)
#define CFIGCV(n)            R_LSH((n), 13U)
#define CFIM                 R_LSH(1UL, 12U)
#define CFITR                R_LSH(1UL, 11U)
#define CFITSS               R_LSH(1UL, 10U)
#define CFM(n)               R_LSH((n), 8U)
#define CFPLS(n)             R_LSH((n), 4U)
#define CFTXIE               R_LSH(1UL, 2U)
#define CFRXIE               R_LSH(1UL, 1U)
#define CFE                  R_LSH(1UL, 0U)

#define GAFLSRD0             R_LSH(1UL, 4U)
#define GAFLSRD1             R_LSH(1UL, 5U)
#define GAFLSRD2             R_LSH(1UL, 6U)

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/
typedef struct STag_CanGlobalCfgType
{
    uint32 u4CFDGCTR;
    uint32 u4CFDGCFG;
    uint32 u4CFDGFDCFG;
    uint32 u4CFDRMNB;
    uint8 *u1pRxRuleSize;
    uint32 (*u4apRxRule)[4];
    uint32 u4RxFifoSize;
    uint32 *u4pRxFifo;
    uint32 u4RxTxFifoSize;
    uint32 *u4pRxTxFifo;
}CanGlobalCfg;

typedef struct STag_Rscfd_CanCfgType
{
    CanGlobalCfg *stpGCFG;
    uint32 u4CTR;
    uint32 u4FDCFG;
    uint32 u4NCFG;
    uint32 u4DCFG;
}Rscfd_CanCfg;

typedef struct STag_Rscfd_TxBuffDataType
{
    uint8 u1BuffId;
    uint8 u1IntSet;
    uint32 u4CFDTMID;
    uint32 u4CFDTMPTR;
    uint32 u4CFDTMFDCTR;
    uint32 u4CFDTMC;
    uint32 *u4pCFDTMDF;
}Rscfd_TxBuffData;

typedef struct STag_Rscfd_RxBuffDataType
{
    uint8 u1BuffId;
    uint32 u4CFDRMID;
    uint32 u4CFDRMPTR;
    uint32 u4CFDRMFDSTS;
    uint32 *u4pCFDRMDF;
}Rscfd_RxBuffData;

typedef struct STag_Rscfd_RxFifoDataType
{
    uint32 u4RxFifoId;
    uint32 u4CFDRFID;
    uint32 u4CFDRFPTR;
    uint32 u4CFDRFFDSTS;
    uint32 *u4pCFDRFDF;
}Rscfd_RxFifoData;
typedef struct STag_Rscfd_RxTxFifoDataType
{
    uint32 u4RxTxFifoId;
    uint32 u4CFDCFID;
    uint32 u4CFDCFPTR;
    uint32 u4CFDCFFDCSTS;
    uint32 *u4pCFDCFDF;
}Rscfd_RxTxFifoData;


typedef uint32 Can_IdType;
typedef uint16 Can_HwHandleType;
typedef uint8 PduIdType;
typedef uint16 PduLengthType;
typedef struct STag_Can_HwType
{
    Can_IdType CanId;
    Can_HwHandleType Hoh;
    uint8 ControllerId;
} Can_HwType;
typedef struct
{
    uint8 *SduDataPtr;
    PduLengthType SduLength;
} PduInfoType;

typedef enum ETag_Can_ReturnType
{
    CAN_OK = 0,
    CAN_NOT_OK,
    CAN_BUSY
} Can_ReturnType;
typedef struct STag_Can_PduType
{
    /* Pointer to L-SDU */
    uint8 *sdu;
    /* CAN-ID */
    Can_IdType id;
    /* swPduHandle */
    PduIdType swPduHandle;
    /* DLC */
    uint8 length;
} Can_PduType;

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global functions
 *****************************************************************************/
uint8 R_RSCFD_Init(uint8 Pu1Unit, uint8 Pu1Channel, Rscfd_CanCfg PstCfg);
uint8 R_RSCFD_Start(uint8 Pu1Unit, uint8 Pu1Channel, Rscfd_CanCfg PstCfg);
uint8 R_RSCFD_BuffSend(uint8 Pu1Unit, uint8 Pu1Channel, Rscfd_TxBuffData PstBuff);
uint8 R_RSCFD_ReadRxFifo(uint8 Pu1Unit, uint8 Pu1Channel, Rscfd_RxFifoData *PstpRxFifo);
uint8 R_RSCFD_ReadRxTxFifo(uint8 Pu1Unit, uint8 Pu1Channel, Rscfd_RxTxFifoData *PstpRxTxFifo);

#endif  /* R_RSCFD_H */
