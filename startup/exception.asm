;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Module      = exception.850
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
  .extern _RESET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;  Add section ".intvect" to your linker command file
;;;;;;;;;;;;;  at address 0x0000
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.section ".intvect", text

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;  Initializing of interrupt vector table
;;;;;;;;;;;;;  Please don't modify this section
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  .public __ex_entry
  .extern _unused_isr
__ex_entry:
  .offset 0x0000
    jr _RESET
    synci

  .offset 0x0010
    jr _unused_isr

  .offset 0x0020
    jr _unused_isr

  .offset 0x0030
    jr _unused_isr

  .offset 0x0040
    jr _unused_isr

  .offset 0x0050
    jr _unused_isr

  .offset 0x0060
    jr _unused_isr

  .offset 0x0080
    jr _unused_isr

  .offset 0x0090
    jr _unused_isr

  .offset 0x00A0
    jr _unused_isr

  .offset 0x00C0
    jr _unused_isr

  .offset 0x00E0
    jr _unused_isr

  .offset 0x00F0
    jr _unused_isr

  .offset 0x0100
    jr _unused_isr

  .offset 0x0110
    jr _unused_isr

  .offset 0x0120
    jr _unused_isr

  .offset 0x0130
    jr _unused_isr

  .offset 0x0140
    jr _unused_isr

  .offset 0x0150
    jr _unused_isr

  .offset 0x0160
    jr _unused_isr

  .offset 0x0170
    jr _unused_isr

  .offset 0x0180
    jr _unused_isr

  .offset 0x0190
    jr _unused_isr

  .offset 0x01A0
    jr _unused_isr

  .offset 0x01B0
    jr _unused_isr

  .offset 0x01C0
    jr _unused_isr

  .offset 0x01D0
    jr _unused_isr

  .offset 0x01E0
    jr _unused_isr

  .offset 0x01F0
    jr _unused_isr
    