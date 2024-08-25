/*
@author: Tran Tuan Anh 
@github: Anhconstant
- MCU : stm32f103c8
PERIPHERALS : SYSTEM TICK TIMER
*/

#ifndef __SYSTICK_H__
#define __SYSTICK_H__

typedef struct{
	struct{
		unsigned long 	ENABLE		:	1		;
		unsigned long		TICKINT		:	1		;
		unsigned long 	CLKSOURCE	:	1		;
		unsigned long		_RES_1		:	13	;

		unsigned long		COUNTFLAG	:	1		;
		unsigned long 	_RES_2		: 15	;
		
	}CTRL		;
	struct{
		unsigned long 	RELOAD		: 24	;
		unsigned long		_RES			:	8		;
	}LOAD		;
	struct{
		unsigned long 	CURRENT		:	24	;
		unsigned long   _RES			:	8		;
	}VAL		;
	struct{
		unsigned long		TENMS			:	24	;
		unsigned long		_RES			:	8		;
	}CALIB	;
}SYSTICK_TypeDef;

#define STK	((SYSTICK_TypeDef *)0xE000E010UL	)	

/*Define Systick Interrupt Handle*/
void Systick_Handler(void)					;

#endif
