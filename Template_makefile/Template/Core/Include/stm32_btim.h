/*
@author: Tran Tuan Anh 
@github: Anhconstant
- MCU : stm32f103c8
PERIPHERALS : BASIC TIMER (TIM6 AND TIM7) (__) APB1 BUS
*/

#ifndef __BTIM_H__
#define __BTIM_H__

/*      MEMORY MAPING   */


typedef struct 
{		
	struct
	{
		unsigned long CEN		:		1		;
		unsigned long UDIS	:		1		;
		unsigned long URS		:		1		;
		unsigned long	OPM		:		1		;
		
		unsigned long _RES1	:		3		;
		unsigned long ARPE	:		1		;
		
		unsigned long	_RES2	:		24	;
			
	} CR1     ;
	
    unsigned long   CR2     ;
    unsigned long   _res1   ;
    unsigned long   DIER    ;
    unsigned long   SR      ;
    unsigned long   EGR     ;
    unsigned long   _res2   ;
    unsigned long   _res3   ;
    unsigned long   _res4   ;
    unsigned long   CNT     ;
    unsigned long   PSC     ;
    unsigned long   ARR     ;

} BTIM_TypeDef   ;

#define     TIM6    ((BTIM_TypeDef *)0x40001000UL   )
#define     TIM7    ((BTIM_TypeDef *)0x40001400UL   )

/*	Define value	*/




// typedef enum 
// {
//     Auto_reload_preload,
    
// } BTIM_Mode     ;


#endif
