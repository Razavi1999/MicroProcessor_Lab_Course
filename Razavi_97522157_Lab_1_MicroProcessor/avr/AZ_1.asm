.include "M32DEF.INC"

;=================Name and Student Id ========================
;		Sayed Mohammad Mahdi Razavi
;		97522157
;=============================================================

.org 0
		LDI	R16 , HIGH(RAMEND)
		OUT	SPH , R16
		LDI	R16 , LOW(RAMEND)
		OUT	SPL , R16
		LDI	R16 , 0xFF
		OUT	DDRB , R16

LABEL4:	LDI 	R16 , 0b00000001

LABEL1:	OUT	PORTB , R16
		LSL	R16
		CALL	DELAY
		CPI	R16 , 0
		BRNE	LABEL1
		LDI 	R16 , 1
		RJMP	LABEL2

LABEL2:	LDI	R16 , 0b10000000


LABEL3:	OUT	PORTB , R16
		LSR	R16
		CALL	DELAYSUBROUTINE
		CPI	R16 , 0
		BRNE	LEABEL3
		LDI	R16 , 1
		RJMP	SUBROUTINE4

DELAYSUBROUTINE:  LDI 	R20 , 0xFF

L1:		LDI 	R21 , 0xFF

L2:		IN	R22 , PINA

L3:		DEC	R22
		NOP
		BRNE	L3
		DEC 	R21
		BRNE 	L2
		DEC	R20
		BRNE	L1
		RET
