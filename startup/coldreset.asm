;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Module      = coldreset.850
;; Version     = CN1.00
;;               manually created  
;;               
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                                  COPYRIGHT
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Copyright (c) 2014 by Renesas Electronics Europe GmbH,
;;               a company of the Renesas Electronics Corporation
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Purpose:      Startup Code
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Warranty Disclaimer
;;
;; Because the Product(s) is licensed free of charge, there is no warranty
;; of any kind whatsoever and expressly disclaimed and excluded by Renesas,
;; either expressed or implied, including but not limited to those for
;; non;infringement of intellectual property, merchantability and/or
;; fitness for the particular purpose.
;; Renesas shall not have any obligation to maintain, service or provide bug
;; fixes for the supplied Product(s) and/or the Application.
;;
;; Each User is solely responsible for determining the appropriateness of
;; using the Product(s) and assumes all risks associated with its exercise
;; of rights under this Agreement, including, but not limited to the risks
;; and costs of program errors, compliance with applicable laws, damage to
;; or loss of data, programs or equipment, and unavailability or
;; interruption of operations.
;;
;; Limitation of Liability
;;
;; In no event shall Renesas be liable to the User for any incidental,
;; consequential, indirect, or punitive damage (including but not limited
;; to lost profits) regardless of whether such liability is based on breach
;; of contract, tort, strict liability, breach of warranties, failure of
;; essential purpose or otherwise and even if advised of the possibility of
;; such damages. Renesas shall not be liable for any services or products
;; provided by third party vendors, developers or consultants identified or
;; referred to the User by Renesas in connection with the Product(s) and/or
;; the Application.
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Environment:
;;              Device:         RH850U2A 
;;              IDE:            CS+
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Revision Control History:
;; CN1.00 : 2020;12;02  : Initial Version

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

  CRAM0S      .set 0xFE000000
  CRAM2S      .set 0xFE400000
  CRAM3S      .set 0xFE800000
  CRAM0E      .set 0xFE07FFFF
  CRAM2E      .set 0xFE4FFFFF
  CRAM3E      .set 0xFE81FFFF
  LRAMS       .set 0xFDE00000
  LRAME       .set 0xFDE0FFFF

  BOOTCTRL    .set 0xFFFB2000
  CUx_EBV     .set 0x00038000

  BR0INIT     .set 0xFFFB8000
  BR0EN       .set 0xFFFB8004

  .public _unused_isr
  .public _ram_init
  .public _RESET
  .public _com_init

  .extern __ex_entry
  .extern _IntVectors

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  system stack
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
STACKSIZE  .set  0x1000
  .section  ".stack.bss", bss
  .align  4
  .ds  (STACKSIZE)
  .align  4
_stacktop:

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  section initialize table
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  .section  ".INIT_DSEC.const", const
  .align  4
  .dw  #__s.data,  #__e.data,  #__s.data.R
  .dw  #__s.R_RFD_RODATA_EXTRA.const,  #__e.R_RFD_RODATA_EXTRA.const,  #__s.R_RFD_RODATA_EXTRA.const.R
  .dw  #__s.R_RFD_CODE_COMMON.text,  #__e.R_RFD_CODE_COMMON.text,  #__s.R_RFD_CODE_COMMON.text.R
  .dw  #__s.R_RFD_CODE_COMMON_RAM_NO_BGO.text,  #__e.R_RFD_CODE_COMMON_RAM_NO_BGO.text,  #__s.R_RFD_CODE_COMMON_RAM_NO_BGO.text.R
  .dw  #__s.R_RFD_CODE_USEROWN_COMMON.text,  #__e.R_RFD_CODE_USEROWN_COMMON.text,  #__s.R_RFD_CODE_USEROWN_COMMON.text.R
  .dw  #__s.R_RFD_CODE_DF.text,  #__e.R_RFD_CODE_DF.text,  #__s.R_RFD_CODE_DF.text.R
  .dw  #__s.R_RFD_CODE_CF.text,  #__e.R_RFD_CODE_CF.text,  #__s.R_RFD_CODE_CF.text.R
  .dw  #__s.R_RFD_CODE_CF_RAM_NO_BGO.text,  #__e.R_RFD_CODE_CF_RAM_NO_BGO.text,  #__s.R_RFD_CODE_CF_RAM_NO_BGO.text.R
  .dw  #__s.R_RFD_CODE_EXTRA.text,  #__e.R_RFD_CODE_EXTRA.text,  #__s.R_RFD_CODE_EXTRA.text.R
  .dw  #__s.R_RFD_RODATA_VERSION_DF.const,  #__e.R_RFD_RODATA_VERSION_DF.const,  #__s.R_RFD_RODATA_VERSION_DF.const.R
  .dw  #__s.R_RFD_RODATA_VERSION_CF.const,  #__e.R_RFD_RODATA_VERSION_CF.const,  #__s.R_RFD_RODATA_VERSION_CF.const.R
  .dw  #__s.R_RFD_RODATA_VERSION_COMMON.const,  #__e.R_RFD_RODATA_VERSION_COMMON.const,  #__s.R_RFD_RODATA_VERSION_COMMON.const.R
  .dw  #__s.R_RFD_CODE_COMMON_API.text,  #__e.R_RFD_CODE_COMMON_API.text,  #__s.R_RFD_CODE_COMMON_API.text.R

  .section  ".INIT_BSEC.const", const
  .align  4
  .dw  #__s.bss,  #__e.bss

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;  Basic Initialisation of the controller
;;;;;;;;;;;;;  User modifiable section
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  .section ".text", text
_RESET:
  ;; CPU function group program registers initialization
  mov   r0, r2
  mov   r0, r3
  mov   r0, r4
  mov   r0, r5
  mov   r0, r6
  mov   r0, r7
  mov   r0, r8
  mov   r0, r9
  mov   r0, r10
  mov   r0, r11
  mov   r0, r12
  mov   r0, r13
  mov   r0, r14
  mov   r0, r15
  mov   r0, r16
  mov   r0, r17
  mov   r0, r18
  mov   r0, r19
  mov   r0, r20
  mov   r0, r21
  mov   r0, r22
  mov   r0, r23
  mov   r0, r24
  mov   r0, r25
  mov   r0, r26
  mov   r0, r27
  mov   r0, r28
  mov   r0, r29
  mov   r0, r30
  mov   r0, r31

  ;; CPU function group system registers initialization
  ldsr  r0,         0,  0
  ldsr  r0,         1, 0
  ldsr  r0,         2,  0
  ldsr  r0,         3, 0
  mov   0x00000020, r6
  ldsr  r6,         5,   0
  ldsr  r0,         13,  0
  ldsr  r0,         14,  0
  ldsr  r0,         16,  0
  ldsr  r0,         17, 0
  ldsr  r0,         20,  0
  ldsr  r0,         28,  0
  ldsr  r0,         29,  0
  ldsr  r0,         2, 1
  ldsr  r0,         3, 1
  ldsr  r0,         4, 1
  ldsr  r0,         11, 1
  ldsr  r0,         12,  1
  ldsr  r0,         6,   2
  ldsr  r0,         8,   2

  ;; Don't Initialize registers list
  ;; Following registers is't set by this startup routine
  ;; SNZCFG, SPID, SPIDLIST, MCTL, PID, SVLOCK,
  ;; PEID, BMID, RBCR0, RBCR1, RBNR, RBIP

  ;; Local RAM Initialize
  mov LRAMS, r6
  mov LRAME, r7
  jarl _ram_init, lp

  ;; Get PEID
  stsr 0, r2, 2
  andi 0x7, r2, r2

  cmp 0, r2
  bne _com_init
  ;; PE0 Initialize
  synci
  ;; Cluster RAM Initialize

  mov BR0INIT, r8
  mov 0x01, r9
  st.b r9, 0[r8]
  mov BR0EN, r8
  mov 0xFF, r9
  st.b r9, 0[r8]

  mov CRAM0S, r6
  mov CRAM0E, r7
  jarl _ram_init, lp
  mov CRAM2S, r6
  mov CRAM2E, r7
  jarl _ram_init, lp
  mov CRAM3S, r6
  mov CRAM3E, r7
  jarl _ram_init, lp
  mov  #__s.INIT_DSEC.const, r6
  mov  #__e.INIT_DSEC.const, r7
  mov  #__s.INIT_BSEC.const, r8
  mov  #__e.INIT_BSEC.const, r9
  jarl __INITSCT_RH, lp  ;  initialize RAM area
  ;; Open other cores
  mov BOOTCTRL, r8
  mov 0x03, r9
  st.w r9, 0[r8]
_com_init:
  mov  #_stacktop, sp    ;  set sp register
  mov  #__gp_data, gp    ;  set gp register
  mov  #__ep_data, ep    ;  set ep register

  ;; Initialization of the interrupt base pointer
  mov #_IntVectors, r2
  ldsr r2, 4, 1

  ;; First set EBASE register address
  mov #__ex_entry, r10
  ldsr r10, 3, 1

  ;; then set 1 to PSW.EBV ;> RBASE!=EBASE
  ;; then set 1 to PSW.CU0 and CU1
  stsr 5, r10, 0
  mov CUx_EBV, r11
  or r11, r10
  ldsr r10, 5, 0

  jr _main

_unused_isr:
    br _unused_isr

_ram_init:
  br _ram_init_2
_ram_init_1:
  st.w r0, 0[r6]
  add 4, r6
_ram_init_2:
  cmp r6, r7
  bh _ram_init_1
  jmp [lp]

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  dummy section
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  .section  ".data", data
.L.dummy.data:
  .section  ".bss", bss
.L.dummy.bss:
  .section  ".const", const
.L.dummy.const:
  .section  ".text", text
.L.dummy.text:


