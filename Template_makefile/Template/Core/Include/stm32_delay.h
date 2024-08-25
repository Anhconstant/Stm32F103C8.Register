/*
@author: Tran Tuan Anh 
@github: Anhconstant
- MCU : stm32f103c8
*/

#ifndef __DELAY_H__
#define __DELAY_H__

#include "stm32_gptim.h"

#define	FreqMhz		(72U ) // ERR IN CLOCK OFF TIMER 4 :  CONFIG WITH 72MHZ BUT IN 36MHZ
#define PRESCALER	(FreqMhz - 1 )
#define Freq    	(72000000 )    
#define delay_s(x)	delay_ms(1000*(x) )
/*  72Mhz   */
/*  Use basic timer4 of stm32f103c8    */

void delay_us( int times )  ;

void delay_ms( int times )  ;

void delay_1ms( void )      ; 

void delay( int times ) ;

void delay_config(void);



#endif
