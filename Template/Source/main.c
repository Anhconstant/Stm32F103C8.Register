//#include "stm32f10x.h"
#include "stm32_gpio.h"
#include "stm32_rcc.h"

int main(void)
	{
	
		Clock_Enable_GPIOB();
		GPIO_Init(GPIOB,GPIO_PIN_2,General_Output_PP_2mhz);
		while(1){
			ToggleGPIO(GPIOB,GPIO_PIN_2);
			for(int i=1 ; i<2000000;i++);
		
		}
}
