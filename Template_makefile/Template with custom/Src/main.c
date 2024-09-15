#include "stm32_main.h"

#define U32SET      ((unsigned long)0xFFFFFFFFUL)
#define U16SET      ((unsigned long)0x0000FFFFUL)
#define U32RESET    ((unsigned long)0x0UL)

int idex = 0	;
unsigned char data_rx ;

// void USART1_IRQHandler(void){

// 	GPIOA->ODR|= 1<<0	;
// 	GPIOA->ODR&= ~1<<0	;
// 	data_rx = (0x000000FF)&USART1->DR;
// 	// idex++	;
// 	// if(idex == 20) return;
// }

//static int a	=	1	;


int main(void)
{	
	Clock_72mhz();
	Clock_Enable_GPIOB()	;
	Clock_Enable_GPIOC()	;
	GPIO_Init(GPIOB,GPIO_PIN_2,General_Output_PP_2mhz)	;
	GPIO_Init(GPIOC,GPIO_PIN_13,General_Output_PP_2mhz)	;
	delay_config()	;
	Systick_Init()	;
	Clock_Enable_USART1()	;
	USART_Init(USART1,USART_MODE_RX_TX,9600,USART_Parity_None,USART_StopBit_1,USART_WordLength_8);
	USART_Int_Enable(USART1,RX_interrupt)	;
	//NVIC_EnableIRQ(USART1_IRQn);
	USART_Enable(USART1)	;
	//USART_Int_Enable(USART1,RX_interrupt)	;

	unsigned char u8data[3] = {'A','B','C'};
	debug_init();
	char tempp = Get_clock(SYS_Clock)/1000000;
	while(1) {
		USART_Write(USART1,tempp);
		ToggleGPIO(GPIOB,GPIO_PIN_2);
		delay_ms(1000);

	}
}



