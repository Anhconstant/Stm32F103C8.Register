/*
@author - github : Anhconstant
- MCU : stm32f103c8
PERIPHERAL : USART/UART
*/
#ifndef __UART_C__
#define __UART_C__

#include "stm32_uart.h"
void USART_Init(USART_TypeDef* USART, USART_MODE Mode, uint32_t baudrate,USART_ParityType Parity, USART_StopBit Stopbit, USART_WordLength Wordlength){
    unsigned long var_uart = (unsigned long) USART;
    
    switch (var_uart)
    {
    case ((unsigned long)USART1)   :
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN  ;
        GPIOA->CRH &= ~(0x0f<<4)    ;                           /*clear mode and cnf of pin9    */
        GPIOA->CRH |=   GPIO_CRH_MODE9  | GPIO_CRH_CNF9_1   ;   /*  CNF NODE = 1011 :   Alternate_Output_PP_50mhz   */
        GPIOA->CRH &= ~(0x0f<<8)    ;                           /*clear mode and cnf of pin9    */
        GPIOA->CRH |= GPIO_CRH_CNF10_1  ;                /*  CNF NODE = 1000 :   Input_PULL   */
        GPIOA->ODR |= GPIO_ODR_ODR10    ;                       /*  set RX = 1   */
        USART1->CR1 |=  Mode | Parity| Wordlength ;
        USART1->CR2 |= Stopbit          ;

        USART1->BRR |= 468 << 4 | 12    ;

        break;
    case ((unsigned long) USART2)   :

        break;
    case ((unsigned long) USART3)   :

        break;
    }
}
// void USART_Init(){

// }
void USART_Enable(USART_TypeDef* UART ){
    UART->CR1 |= USART_CR1_UE;

}
void USART_Disable(USART_TypeDef* UART ){

}
void USART_Write(USART_TypeDef* UART,unsigned char u8data){
    UART->DR = u8data;
    while(!(UART->SR&USART_SR_TC));
    //UART->SR &= ~USART_SR_TC;
}
void USART_Send(USART_TypeDef* UART,unsigned char u8data[],unsigned long size){
    for(int i=0;i<size;i++){
        USART_Write(UART,u8data[i]);
    }
}

void USART_Int_Enable(USART_TypeDef* UART, USART_Interrupt interrupt){
    __NVIC_EnableIRQ(USART1_IRQn);
    UART->CR1 |= interrupt   ;
}


#endif
