/*
@author: Tran Tuan Anh 
@github: Anhconstant
- MCU : stm32f103c8
*/

#ifndef __DELAY_H__
#define __DELAY_H__

#include "stm32_gptim.h"

#define	FreqMhz		(8U )
#define PRESCALER	(FreqMhz - 1 )
#define Freq    	(72000000 )        
/*  72Mhz   */
/*  Use basic timer 7 of stm32f103c8    */

void us_delay( int times )  ;

void ms_delay( int times )  ;

void m1s_delay( void )      ; 

void delay_ms( int times ) ;

void delay_config(void);



#endif
