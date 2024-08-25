
#include "stm32_gpio.h"
#include "stm32_rcc.h"
#include "stm32_btim.h"
//#include "stm32_gptim.h"
#include "stm32_delay.h"

void SystemInit(void){}
	

int main(void){
	Clock_72mhz();
	//int counter;
	Clock_Enable_GPIOB();
	GPIO_Init(GPIOB,GPIO_PIN_2,General_Output_PP_2mhz);
	GPIO_Init(GPIOB,GPIO_PIN_1,General_Output_PP_2mhz);
	//TIM7_config();
	//TIM7->CR1.CEN	=	1;
	delay_config();
	
while(1){
	ToggleGPIO(GPIOB,GPIO_PIN_2);
	ToggleGPIO(GPIOB,GPIO_PIN_1);
	delay_ms(1000);
}
}
