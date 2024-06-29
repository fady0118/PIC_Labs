subtitle "Microchip MPLAB XC8 C Compiler v2.46 (Free license) build 20240104201356 Og1 "

pagewidth 120

	opt flic

	processor	16F877A
include "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\16f877a.cgen.inc"
getbyte	macro	val,pos
	(((val) >> (8 * pos)) and 0xff)
endm
byte0	macro	val
	(getbyte(val,0))
endm
byte1	macro	val
	(getbyte(val,1))
endm
byte2	macro	val
	(getbyte(val,2))
endm
byte3	macro	val
	(getbyte(val,3))
endm
byte4	macro	val
	(getbyte(val,4))
endm
byte5	macro	val
	(getbyte(val,5))
endm
byte6	macro	val
	(getbyte(val,6))
endm
byte7	macro	val
	(getbyte(val,7))
endm
getword	macro	val,pos
	(((val) >> (8 * pos)) and 0xffff)
endm
word0	macro	val
	(getword(val,0))
endm
word1	macro	val
	(getword(val,2))
endm
word2	macro	val
	(getword(val,4))
endm
word3	macro	val
	(getword(val,6))
endm
gettword	macro	val,pos
	(((val) >> (8 * pos)) and 0xffffff)
endm
tword0	macro	val
	(gettword(val,0))
endm
tword1	macro	val
	(gettword(val,3))
endm
tword2	macro	val
	(gettword(val,6))
endm
getdword	macro	val,pos
	(((val) >> (8 * pos)) and 0xffffffff)
endm
dword0	macro	val
	(getdword(val,0))
endm
dword1	macro	val
	(getdword(val,4))
endm
clrc	macro
	bcf	3,0
	endm
clrz	macro
	bcf	3,2
	endm
setc	macro
	bsf	3,0
	endm
setz	macro
	bsf	3,2
	endm
skipc	macro
	btfss	3,0
	endm
skipz	macro
	btfss	3,2
	endm
skipnc	macro
	btfsc	3,0
	endm
skipnz	macro
	btfsc	3,2
	endm
# 54 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
INDF equ 00h ;# 
# 61 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TMR0 equ 01h ;# 
# 68 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PCL equ 02h ;# 
# 75 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
STATUS equ 03h ;# 
# 161 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
FSR equ 04h ;# 
# 168 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PORTA equ 05h ;# 
# 218 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PORTB equ 06h ;# 
# 280 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PORTC equ 07h ;# 
# 342 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PORTD equ 08h ;# 
# 404 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PORTE equ 09h ;# 
# 436 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PCLATH equ 0Ah ;# 
# 456 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
INTCON equ 0Bh ;# 
# 534 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PIR1 equ 0Ch ;# 
# 596 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PIR2 equ 0Dh ;# 
# 636 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TMR1 equ 0Eh ;# 
# 643 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TMR1L equ 0Eh ;# 
# 650 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TMR1H equ 0Fh ;# 
# 657 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
T1CON equ 010h ;# 
# 732 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TMR2 equ 011h ;# 
# 739 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
T2CON equ 012h ;# 
# 810 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
SSPBUF equ 013h ;# 
# 817 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
SSPCON equ 014h ;# 
# 887 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CCPR1 equ 015h ;# 
# 894 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CCPR1L equ 015h ;# 
# 901 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CCPR1H equ 016h ;# 
# 908 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CCP1CON equ 017h ;# 
# 966 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
RCSTA equ 018h ;# 
# 1061 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TXREG equ 019h ;# 
# 1068 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
RCREG equ 01Ah ;# 
# 1075 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CCPR2 equ 01Bh ;# 
# 1082 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CCPR2L equ 01Bh ;# 
# 1089 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CCPR2H equ 01Ch ;# 
# 1096 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CCP2CON equ 01Dh ;# 
# 1154 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
ADRESH equ 01Eh ;# 
# 1161 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
ADCON0 equ 01Fh ;# 
# 1257 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
OPTION_REG equ 081h ;# 
# 1327 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TRISA equ 085h ;# 
# 1377 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TRISB equ 086h ;# 
# 1439 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TRISC equ 087h ;# 
# 1501 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TRISD equ 088h ;# 
# 1563 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TRISE equ 089h ;# 
# 1620 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PIE1 equ 08Ch ;# 
# 1682 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PIE2 equ 08Dh ;# 
# 1722 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PCON equ 08Eh ;# 
# 1756 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
SSPCON2 equ 091h ;# 
# 1818 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PR2 equ 092h ;# 
# 1825 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
SSPADD equ 093h ;# 
# 1832 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
SSPSTAT equ 094h ;# 
# 2001 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TXSTA equ 098h ;# 
# 2082 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
SPBRG equ 099h ;# 
# 2089 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CMCON equ 09Ch ;# 
# 2159 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CVRCON equ 09Dh ;# 
# 2224 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
ADRESL equ 09Eh ;# 
# 2231 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
ADCON1 equ 09Fh ;# 
# 2290 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
EEDATA equ 010Ch ;# 
# 2297 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
EEADR equ 010Dh ;# 
# 2304 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
EEDATH equ 010Eh ;# 
# 2311 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
EEADRH equ 010Fh ;# 
# 2318 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
EECON1 equ 018Ch ;# 
# 2363 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
EECON2 equ 018Dh ;# 
# 54 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
INDF equ 00h ;# 
# 61 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TMR0 equ 01h ;# 
# 68 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PCL equ 02h ;# 
# 75 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
STATUS equ 03h ;# 
# 161 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
FSR equ 04h ;# 
# 168 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PORTA equ 05h ;# 
# 218 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PORTB equ 06h ;# 
# 280 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PORTC equ 07h ;# 
# 342 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PORTD equ 08h ;# 
# 404 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PORTE equ 09h ;# 
# 436 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PCLATH equ 0Ah ;# 
# 456 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
INTCON equ 0Bh ;# 
# 534 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PIR1 equ 0Ch ;# 
# 596 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PIR2 equ 0Dh ;# 
# 636 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TMR1 equ 0Eh ;# 
# 643 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TMR1L equ 0Eh ;# 
# 650 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TMR1H equ 0Fh ;# 
# 657 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
T1CON equ 010h ;# 
# 732 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TMR2 equ 011h ;# 
# 739 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
T2CON equ 012h ;# 
# 810 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
SSPBUF equ 013h ;# 
# 817 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
SSPCON equ 014h ;# 
# 887 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CCPR1 equ 015h ;# 
# 894 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CCPR1L equ 015h ;# 
# 901 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CCPR1H equ 016h ;# 
# 908 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CCP1CON equ 017h ;# 
# 966 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
RCSTA equ 018h ;# 
# 1061 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TXREG equ 019h ;# 
# 1068 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
RCREG equ 01Ah ;# 
# 1075 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CCPR2 equ 01Bh ;# 
# 1082 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CCPR2L equ 01Bh ;# 
# 1089 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CCPR2H equ 01Ch ;# 
# 1096 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CCP2CON equ 01Dh ;# 
# 1154 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
ADRESH equ 01Eh ;# 
# 1161 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
ADCON0 equ 01Fh ;# 
# 1257 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
OPTION_REG equ 081h ;# 
# 1327 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TRISA equ 085h ;# 
# 1377 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TRISB equ 086h ;# 
# 1439 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TRISC equ 087h ;# 
# 1501 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TRISD equ 088h ;# 
# 1563 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TRISE equ 089h ;# 
# 1620 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PIE1 equ 08Ch ;# 
# 1682 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PIE2 equ 08Dh ;# 
# 1722 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PCON equ 08Eh ;# 
# 1756 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
SSPCON2 equ 091h ;# 
# 1818 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
PR2 equ 092h ;# 
# 1825 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
SSPADD equ 093h ;# 
# 1832 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
SSPSTAT equ 094h ;# 
# 2001 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
TXSTA equ 098h ;# 
# 2082 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
SPBRG equ 099h ;# 
# 2089 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CMCON equ 09Ch ;# 
# 2159 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
CVRCON equ 09Dh ;# 
# 2224 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
ADRESL equ 09Eh ;# 
# 2231 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
ADCON1 equ 09Fh ;# 
# 2290 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
EEDATA equ 010Ch ;# 
# 2297 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
EEADR equ 010Dh ;# 
# 2304 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
EEDATH equ 010Eh ;# 
# 2311 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
EEADRH equ 010Fh ;# 
# 2318 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
EECON1 equ 018Ch ;# 
# 2363 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8\pic\include\proc\pic16f877a.h"
EECON2 equ 018Dh ;# 
	debug_source C
	FNCALL	_main,_Timer1_Init
	FNROOT	_main
	FNCALL	intlevel1,_ISR
	global	intlevel1
	FNROOT	intlevel1
	global	_data
	global	_State
	global	_TMR1
_TMR1	set	0xE
	global	_PORTB
_PORTB	set	0x6
	global	_T1CON
_T1CON	set	0x10
	global	_GIE
_GIE	set	0x5F
	global	_PEIE
_PEIE	set	0x5E
	global	_TMR1IF
_TMR1IF	set	0x60
	global	_T1OSCEN
_T1OSCEN	set	0x83
	global	_TMR1CS
_TMR1CS	set	0x81
	global	_TMR1ON
_TMR1ON	set	0x80
	global	_TRISB
_TRISB	set	0x86
	global	_TMR1IE
_TMR1IE	set	0x460
; #config settings
	config pad_punits      = on
	config apply_mask      = off
	config ignore_cmsgs    = off
	config default_configs = off
	config default_idlocs  = off
	config FOSC = "XT"
	config WDTE = "OFF"
	config PWRTE = "ON"
	config BOREN = "ON"
	config LVP = "OFF"
	config CPD = "OFF"
	config WRT = "OFF"
	config CP = "OFF"
	file	"dist/default/production\Triangular_Waveform_Out_DAC_using_Timer.X.production.s"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

global __initialization
__initialization:
psect	bssCOMMON,class=COMMON,space=1,noexec
global __pbssCOMMON
__pbssCOMMON:
_counter:
       ds      1

_data:
       ds      1

_State:
       ds      1

	file	"dist/default/production\Triangular_Waveform_Out_DAC_using_Timer.X.production.s"
	line	#
; Clear objects allocated to COMMON
psect cinit,class=CODE,delta=2,merge=1
	clrf	((__pbssCOMMON)+0)&07Fh
	clrf	((__pbssCOMMON)+1)&07Fh
	clrf	((__pbssCOMMON)+2)&07Fh
psect cinit,class=CODE,delta=2,merge=1
global end_of_initialization,__end_of__initialization

;End of C runtime variable initialization code

end_of_initialization:
__end_of__initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1,noexec
global __pcstackCOMMON
__pcstackCOMMON:
?_Timer1_Init:	; 1 bytes @ 0x0
?_main:	; 1 bytes @ 0x0
?_ISR:	; 1 bytes @ 0x0
??_ISR:	; 1 bytes @ 0x0
	ds	6
??_Timer1_Init:	; 1 bytes @ 0x6
??_main:	; 1 bytes @ 0x6
;!
;!Data Sizes:
;!    Strings     0
;!    Constant    0
;!    Data        0
;!    BSS         3
;!    Persistent  0
;!    Stack       0
;!
;!Auto Spaces:
;!    Space          Size  Autos    Used
;!    COMMON           14      6       9
;!    BANK0            80      0       0
;!    BANK1            80      0       0
;!    BANK3            96      0       0
;!    BANK2            96      0       0

;!
;!Pointer List with Targets:
;!
;!    None.


;!
;!Critical Paths under _main in COMMON
;!
;!    None.
;!
;!Critical Paths under _ISR in COMMON
;!
;!    None.
;!
;!Critical Paths under _main in BANK0
;!
;!    None.
;!
;!Critical Paths under _ISR in BANK0
;!
;!    None.
;!
;!Critical Paths under _main in BANK1
;!
;!    None.
;!
;!Critical Paths under _ISR in BANK1
;!
;!    None.
;!
;!Critical Paths under _main in BANK3
;!
;!    None.
;!
;!Critical Paths under _ISR in BANK3
;!
;!    None.
;!
;!Critical Paths under _main in BANK2
;!
;!    None.
;!
;!Critical Paths under _ISR in BANK2
;!
;!    None.

;;
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;!
;!Call Graph Tables:
;!
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (0) _main                                                 0     0      0       0
;!                        _Timer1_Init
;! ---------------------------------------------------------------------------------
;! (1) _Timer1_Init                                          0     0      0       0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 1
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (2) _ISR                                                  6     6      0       0
;!                                              0 COMMON     6     6      0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 2
;! ---------------------------------------------------------------------------------
;!
;! Call Graph Graphs:
;!
;! _main (ROOT)
;!   _Timer1_Init
;!
;! _ISR (ROOT)
;!

;! Address spaces:

;!Name               Size   Autos  Total    Cost      Usage
;!BITCOMMON            E      0       0       0        0.0%
;!EEDATA             100      0       0       0        0.0%
;!NULL                 0      0       0       0        0.0%
;!CODE                 0      0       0       0        0.0%
;!COMMON               E      6       9       1       64.3%
;!BITSFR0              0      0       0       1        0.0%
;!SFR0                 0      0       0       1        0.0%
;!BITSFR1              0      0       0       2        0.0%
;!SFR1                 0      0       0       2        0.0%
;!STACK                0      0       0       2        0.0%
;!ABS                  0      0       9       3        0.0%
;!BITBANK0            50      0       0       4        0.0%
;!BITSFR3              0      0       0       4        0.0%
;!SFR3                 0      0       0       4        0.0%
;!BANK0               50      0       0       5        0.0%
;!BITSFR2              0      0       0       5        0.0%
;!SFR2                 0      0       0       5        0.0%
;!BITBANK1            50      0       0       6        0.0%
;!BANK1               50      0       0       7        0.0%
;!BITBANK3            60      0       0       8        0.0%
;!BANK3               60      0       0       9        0.0%
;!BITBANK2            60      0       0      10        0.0%
;!BANK2               60      0       0      11        0.0%
;!DATA                 0      0       9      12        0.0%

	global	_main

;; *************** function _main *****************
;; Defined at:
;;		line 38 in file "main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0, btemp+1, pclath, cstack
;; Tracked objects:
;;		On entry : B00/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called: 2
;; This function calls:
;;		_Timer1_Init
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext,global,class=CODE,delta=2,split=1,group=0
	file	"main.c"
	line	38
global __pmaintext
__pmaintext:	;psect for function _main
psect	maintext
	file	"main.c"
	line	38
	
_main:	
;incstack = 0
	callstack 6
; Regs used in _main: [wreg+status,2+status,0+btemp+1+pclath+cstack]
	line	39
	
l612:	
;main.c: 39:     TRISB = 0x00;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	clrf	(134)^080h	;volatile
	line	40
;main.c: 40:     PORTB = 0x00;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	clrf	(6)	;volatile
	line	41
	
l614:	
;main.c: 41:     Timer1_Init();
	fcall	_Timer1_Init
	line	42
;main.c: 42:     while(1){
	
l36:	
	line	44
;main.c: 44:     }
	
l37:	
	goto	l36
	global	start
	ljmp	start
	callstack 0
	line	46
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,89
	global	_Timer1_Init

;; *************** function _Timer1_Init *****************
;; Defined at:
;;		line 25 in file "main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0, btemp+1
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used: 1
;; Hardware stack levels required when called: 1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text1,local,class=CODE,delta=2,merge=1,group=0
	line	25
global __ptext1
__ptext1:	;psect for function _Timer1_Init
psect	text1
	file	"main.c"
	line	25
	
_Timer1_Init:	
;incstack = 0
	callstack 6
; Regs used in _Timer1_Init: [wreg+status,2+status,0+btemp+1]
	line	26
	
l596:	
;main.c: 26: TMR1ON=0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(128/8),(128)&7	;volatile
	line	27
;main.c: 27: TMR1CS=0;
	bcf	(129/8),(129)&7	;volatile
	line	28
;main.c: 28: T1OSCEN=1;
	bsf	(131/8),(131)&7	;volatile
	line	29
	
l598:	
;main.c: 29: T1CON&=~0x30;
	movlw	low(0CFh)
	movwf	btemp+1
	movf	btemp+1,w
	andwf	(16),f	;volatile
	line	30
	
l600:	
;main.c: 30: TMR1ON=1;
	bsf	(128/8),(128)&7	;volatile
	line	31
	
l602:	
;main.c: 31: TMR1IE=1;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	bsf	(1120/8)^080h,(1120)&7	;volatile
	line	32
	
l604:	
;main.c: 32: TMR1IF = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(96/8),(96)&7	;volatile
	line	33
	
l606:	
;main.c: 33: PEIE = 1;
	bsf	(94/8),(94)&7	;volatile
	line	34
	
l608:	
;main.c: 34: GIE = 1;
	bsf	(95/8),(95)&7	;volatile
	line	35
	
l610:	
;main.c: 35: TMR1=65400;
	movlw	0FFh
	movwf	(14+1)	;volatile
	movlw	078h
	movwf	(14)	;volatile
	line	36
	
l31:	
	return
	callstack 0
GLOBAL	__end_of_Timer1_Init
	__end_of_Timer1_Init:
	signat	_Timer1_Init,89
	global	_ISR

;; *************** function _ISR *****************
;; Defined at:
;;		line 57 in file "main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, btemp+1
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          6       0       0       0       0
;;      Totals:         6       0       0       0       0
;;Total ram usage:        6 bytes
;; Hardware stack levels used: 1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Interrupt level 1
;; This function uses a non-reentrant model
;;
psect	text2,local,class=CODE,delta=2,merge=1,group=0
	line	57
global __ptext2
__ptext2:	;psect for function _ISR
psect	text2
	file	"main.c"
	line	57
	
_ISR:	
;incstack = 0
	callstack 6
; Regs used in _ISR: [wreg-fsr0h+status,2+status,0+btemp+1]
psect	intentry,class=CODE,delta=2
global __pintentry
__pintentry:
global interrupt_function
interrupt_function:
	global saved_w
	saved_w	set	btemp+0
	movwf	saved_w
	swapf	status,w
	movwf	(??_ISR+2)
	movf	fsr0,w
	movwf	(??_ISR+3)
	movf	pclath,w
	movwf	(??_ISR+4)
	movf	btemp+1,w
	movwf	(??_ISR+5)
	ljmp	_ISR
psect	text2
	line	58
	
i1l616:	
;main.c: 58:     if(TMR1IF){
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	btfss	(96/8),(96)&7	;volatile
	goto	u1_21
	goto	u1_20
u1_21:
	goto	i1l52
u1_20:
	line	59
	
i1l618:	
;main.c: 59:         TMR1IF=0;
	bcf	(96/8),(96)&7	;volatile
	line	60
;main.c: 60:   switch(State){
	goto	i1l630
	line	62
	
i1l620:	
;main.c: 62:     PORTB=data++;
	movf	(_data),w
	movwf	(6)	;volatile
	
i1l622:	
	movlw	low(01h)
	movwf	btemp+1
	movf	btemp+1,w
	addwf	(_data),f
	line	63
;main.c: 63:     break;
	goto	i1l632
	line	65
	
i1l624:	
;main.c: 65:     PORTB=data--;
	movf	(_data),w
	movwf	(6)	;volatile
	
i1l626:	
	movlw	01h
	subwf	(_data),f
	line	66
;main.c: 66:     break;
	goto	i1l632
	line	67
	
i1l630:	
	movf	(_State),w
	movwf	(??_ISR+0)+0
	clrf	(??_ISR+0)+0+1
	; Switch on 2 bytes has been partitioned into a top level switch of size 1, and 1 sub-switches
; Switch size 1, requested type "simple"
; Number of cases is 1, Range of values is 0 to 0
; switch strategies available:
; Name         Instructions Cycles
; simple_byte            4     3 (average)
; direct_byte           11     8 (fixed)
; jumptable            260     6 (fixed)
;	Chosen strategy is simple_byte

	movf 1+(??_ISR+0)+0,w
	asmopt push
	asmopt off
	xorlw	0^0	; case 0
	skipnz
	goto	i1l664
	goto	i1l624
	asmopt pop
	
i1l664:	
; Switch size 1, requested type "simple"
; Number of cases is 1, Range of values is 0 to 0
; switch strategies available:
; Name         Instructions Cycles
; simple_byte            4     3 (average)
; direct_byte           11     8 (fixed)
; jumptable            260     6 (fixed)
;	Chosen strategy is simple_byte

	movf 0+(??_ISR+0)+0,w
	asmopt push
	asmopt off
	xorlw	0^0	; case 0
	skipnz
	goto	i1l620
	goto	i1l624
	asmopt pop

	line	69
	
i1l632:	
;main.c: 69:         if(data==255 || data==0){State^=1;}
		incf	((_data)),w
	btfsc	status,2
	goto	u2_21
	goto	u2_20
u2_21:
	goto	i1l636
u2_20:
	
i1l634:	
	movf	((_data)),w
	btfss	status,2
	goto	u3_21
	goto	u3_20
u3_21:
	goto	i1l638
u3_20:
	
i1l636:	
	movlw	01h
	movwf	btemp+1
	movf	btemp+1,w
	xorwf	(_State),f
	line	70
	
i1l638:	
;main.c: 70:         TMR1=65400;
	movlw	0FFh
	movwf	(14+1)	;volatile
	movlw	078h
	movwf	(14)	;volatile
	line	73
	
i1l52:	
	movf	(??_ISR+5),w
	movwf	btemp+1
	movf	(??_ISR+4),w
	movwf	pclath
	movf	(??_ISR+3),w
	movwf	fsr0
	swapf	(??_ISR+2),w
	movwf	status
	swapf	saved_w,f
	swapf	saved_w,w
	retfie
	callstack 0
GLOBAL	__end_of_ISR
	__end_of_ISR:
	signat	_ISR,89
global	___latbits
___latbits	equ	2
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp+0
	end
