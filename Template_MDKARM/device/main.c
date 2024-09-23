
#include "main.h"
void SystemInit(void){}
void delay(void);
void delay(void){
	
for(int i=0;i<0xffff;i++) __nop();


}

int main(void){

	Clock_Enable_GPIOB();
	GPIO_Init(GPIOB,GPIO_PIN_2,General_Output_PP_10mhz);
	
while(1){
	ToggleGPIO(GPIOB,GPIO_PIN_2);
	delay();
	}
}
