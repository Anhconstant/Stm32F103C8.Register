/*
@author - github: Anhconstant
- MCU : stm32f103c8
PERIPHERAL : SPI   (HARDWARE) 
*/
#ifndef __SPI_C__
#define __SPI_C__
#include "stm32_spi.h"

void SPI_Init(SPI_TypeDef* SPI, SPI_MODE MODE,uint8_t MSB_LSB,SPI_Baudrate baudrate,Master_Slave select){
    switch ((unsigned long)SPI)
    {
    case (unsigned long)SPI1:
        RCC->APB2ENR    |= RCC_APB2ENR_SPI1EN   ;
        RCC->APB2ENR    |= RCC_APB2ENR_IOPAEN   ;
        GPIOA->CRL      &=~ ( GPIO_CRL_CNF4 | GPIO_CRL_MODE4)   ;
        GPIOA->CRL      |=  ( GPIO_CRL_CNF4_1|GPIO_CRL_MODE4)   ;
        GPIOA->CRL      &=~ ( GPIO_CRL_CNF5 | GPIO_CRL_MODE5)   ;
        GPIOA->CRL      |=  ( GPIO_CRL_CNF5_1|GPIO_CRL_MODE5)   ;
        GPIOA->CRL      &=~ ( GPIO_CRL_CNF6 | GPIO_CRL_MODE6)   ;
        GPIOA->CRL      |=  ( GPIO_CRL_MODE6_1)   ; 
        GPIOA->CRL      &=~ ( GPIO_CRL_CNF7 | GPIO_CRL_MODE7)   ;
        GPIOA->CRL      |=  ( GPIO_CRL_CNF7_1|GPIO_CRL_MODE7)   ;
        if(MODE&(1<<1)){
            GPIOA->ODR |= GPIO_ODR_ODR5 ;
        }
        else{
            GPIOA->ODR &= ~GPIO_ODR_ODR5 ;
        }


        break;
    case (unsigned long)SPI2:
        RCC->APB1ENR    |= RCC_APB1ENR_SPI2EN   ;
        RCC->APB2ENR    |= RCC_APB2ENR_IOPBEN   ;
        GPIOB->CRH      &=~ ( GPIO_CRH_CNF12 | GPIO_CRH_MODE12)   ;
        GPIOB->CRH      |=  ( GPIO_CRH_CNF12_1|GPIO_CRH_MODE12)   ;
        GPIOB->CRH      &=~ ( GPIO_CRH_CNF13 | GPIO_CRH_MODE13)   ;
        GPIOB->CRH      |=  ( GPIO_CRH_CNF13_1|GPIO_CRH_MODE13)   ;
        GPIOB->CRH      &=~ ( GPIO_CRH_CNF14 | GPIO_CRH_MODE14)   ;
        GPIOB->CRH      |=  ( GPIO_CRH_MODE14_1)   ; 
        GPIOB->CRH      &=~ ( GPIO_CRH_CNF15 | GPIO_CRH_MODE15)   ;
        GPIOB->CRH      |=  ( GPIO_CRH_CNF15_1|GPIO_CRH_MODE15)   ;
        if(MODE&(1<<1)){
            GPIOB->ODR |= GPIO_ODR_ODR13 ;
        }
        else{
            GPIOB->ODR &= ~GPIO_ODR_ODR13 ;
        }
        break;
    }
    SPI->CR1    &= ~SPI_CR1_BIDIMODE    ;      /*  2 line unidirectional data mode */
    SPI->CR1    |=  ((0x01&MSB_LSB)<<7) ;
    SPI->CR1    |=  baudrate            ;
    SPI->CR1    |=  select              ;
    SPI->CR1    |=  MODE                ;       /*  Select CPOL and CPHA    */
    SPI->CR1    &= ~ SPI_CR1_DFF        ;
}
void SPI_Write(SPI_TypeDef* SPI,uint8_t u8data){
    while(!((SPI->SR) & (SPI_SR_TXE)));
    SPI->DR = u8data    ;
    
}
void SPI_Send(SPI_TypeDef* SPI,uint8_t u8data[], long size){
    for(    int i   =  0 ; i < size  ; i++  ){
        SPI_Write(SPI,u8data[i]);
    }
}
void SPI_Enable(SPI_TypeDef* SPI){
    SPI->CR1 |= SPI_CR1_SPE ;
}
void SPI_Disable(SPI_TypeDef* SPI){
    SPI->CR1 &= ~SPI_CR1_SPE ;
}
void SPI_ChipSelect_Init(GPIO_TypeDef* GPIO,uint32_t GPIO_PIN){
    switch ((uint32_t)GPIO)
    {
    case (uint32_t)GPIOA:
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN  ;
        break;
    case (uint32_t)GPIOB:
        RCC->APB2ENR |= RCC_APB2ENR_IOPBEN  ;
        break;
    case (uint32_t)GPIOC:
        RCC->APB2ENR |= RCC_APB2ENR_IOPCEN  ;
        break;

    }
    if(GPIO_PIN & 0x0f){
            for(int i=0;i<8;i++){
                if((GPIO_PIN>>i)&(0x01)){
                    GPIO->CRL &= ~0x0f << (i*4)    ;
                    GPIO->CRL |=  3 << (i*4)    ;
                    GPIO->ODR |= 1<< (i) ;
                }
            }
        }
        else{
            for(int i=0;i<8;i++){
                if((GPIO_PIN>>(i+8))&(0x01)){
                    GPIO->CRH &= ~0x0f << (i*4)    ;
                    GPIO->CRH |=  3 << (i*4)    ;
                    GPIO->ODR |= 1<< (i+8) ;
                }
        }
    }
}
void SPI_ChipSelect_Enable(GPIO_TypeDef* GPIO,uint32_t GPIO_PIN){
    GPIO->BSRR  |=  GPIO_PIN << 16   ;
}
void SPI_ChipSelect_Disable(GPIO_TypeDef* GPIO,uint32_t GPIO_PIN){
    GPIO->BSRR  |=  GPIO_PIN    ;
}
/*  
    Decription - function : SPI_Int_Enable
        SPI_CR2_TXEIE   :   Tx buffer empty interrupt enable
        SPI_CR2_RXNEIE  :   RX buffer not empty interrupt enable
        SPI_CR2_ERRIE   :   Error interrupt enable
*/
void SPI_Int_Enable(SPI_TypeDef* SPI,uint16_t interrupt){
    SPI->CR2    |= interrupt    ;
}
void I2C_Int_Enable(){
}


#endif  /*  End     */
