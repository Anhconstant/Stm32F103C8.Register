/*
@author - github : Anhconstant
- MCU : stm32f103c8
PERIPHERAL : USART/UART
*/
/*  
    (Decription): 
    TX  : Transmitter
    RX  : Receiver
/----------------------------------------------------------------------/
    Baudrate ( bit/s): { 300, 1200, 2400, 4800 , 9600 , 14400 , 19200, 38400,
                        57600, 115200, 230400, 460800, 921600, 1843200 }

*/
/*  PIN: USART1:
        CTS :   PA11
        RTS :   PA12
        TX  :   PA9
        RX  :   PA10
        CK  :   PA8
    PIN: USART2:
        CTS :   PA0
        RTS :   PA1
        TX  :   PA2
        RX  :   PA3
        CK  :   PA4
    PIN: USART3:
        CTS :   PB13
        RTS :   PB14
        TX  :   PB10
        RX  :   PB11
        CK  :   PB12
*/
#ifndef __UART_H__
#define __UART_H__
#include "stm32f10x.h"

typedef enum{
    USART_MODE_RX       =   USART_CR1_RE   ,
    USART_MODE_TX       =   USART_CR1_TE   ,
    USART_MODE_RX_TX    =   USART_CR1_TE | USART_CR1_RE  
}USART_MODE   ;

typedef enum{
    USART_HardwareFlowControl_OFF = 0   ,
    USART_HardwareFlowControl_ON  = 1
}USART_HardwareFlowControl   ;

typedef enum{
    USART_Parity_None =   0   ,                             /*  Parity_Disable    */
    USART_Parity_Odd  =   USART_CR1_PCE | USART_CR1_PS   ,  /*  Parity_Enable and Parity_Odd    */  
    USART_Parity_Even =   USART_CR1_PCE                     /*  Parity_Enable and Parity_Even   */
}USART_ParityType   ;

typedef enum{
    USART_StopBit_0_5   =   USART_CR2_STOP_0   ,
    USART_StopBit_1     =   0   ,
    USART_StopBit_1_5   =   USART_CR2_STOP_1   ,
    USART_StopBit_2     =   USART_CR2_STOP  
}USART_StopBit  ;

typedef enum{
    USART_WordLength_8  =   0   ,
    USART_WordLength_9  =   USART_CR1_M    
}USART_WordLength  ;

typedef enum{
    RX_interrupt = USART_CR1_RXNEIE    
}USART_Interrupt  ;

void USART_Init(USART_TypeDef* USART, USART_MODE Mode, uint32_t baudrate,USART_ParityType Parity, USART_StopBit Stopbit, USART_WordLength Wordlength)    ;
//void USART_Init()       ;
void USART_Enable(USART_TypeDef* UART )  ;
void USART_Disable(USART_TypeDef* UART ) ;
void USART_Write(USART_TypeDef* UART,unsigned char u8data)  ;                       /*  Write 1 byte data       */
void USART_Send(USART_TypeDef* UART,unsigned char u8data[],unsigned long size)  ;   /*  Send n byte data        */
void USART_Int_Enable(USART_TypeDef* UART, USART_Interrupt interrupt) ;             /*  Enable Interrupt UART   */


#endif
