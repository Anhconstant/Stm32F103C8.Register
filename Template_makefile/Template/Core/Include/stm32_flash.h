/*
@author: Tran Tuan Anh 
@github: Anhconstant
- MCU : stm32f103c8
flash
*/
#ifndef __FLASH_H__
#define __FLASH_H__
typedef struct{
	struct{
		unsigned long	LATENCY	:	3		;
		unsigned long HLFCYA	:	1		;
		unsigned long PRFTBE	:	1		;
		unsigned long PRFTBS	:	1		;
		unsigned long _RES		: 26	;
	} ACR		;
	unsigned long KEYR	;
	unsigned long OPTKEYR	;
	unsigned long SR			;
	unsigned long CR			;
	unsigned long AR			;
	unsigned long	_RES		;
	unsigned long OBR			;
	unsigned long	WRPR		;
}	FLASH_TypeDef		;

#define FLASH		((FLASH_TypeDef*)0x40022000UL)
#define FLASH_ACR_LATENCY_Zero	(0u )
#define FLASH_ACR_LATENCY_One		(1u )
#define FLASH_ACR_LATENCY_Two		(2u )
#endif
