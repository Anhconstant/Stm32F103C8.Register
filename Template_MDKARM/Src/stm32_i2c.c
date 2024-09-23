/*
@author - github : Anhconstant
- MCU : stm32f103c8
PERIPHERAL : I2C
*/
#ifndef __I2C_C__
#define __I2C_C__
#include "stm32_i2c.h"


void I2C_Init(I2C_TypeDef* I2C, uint32_t ACK_select ){
    switch ((uint32_t)I2C)
    {
    case ((uint32_t)I2C1):
            /*  SDA :   PB7
                SCL :   PB6     */
        RCC->APB2ENR|= RCC_APB2ENR_IOPBEN   ;
        GPIOB->CRL  &=~ (GPIO_CRL_CNF6 | GPIO_CRL_MODE6 | GPIO_CRL_CNF7 | GPIO_CRL_MODE7) ; 
            /*  RESET MODE AND CNF OF PORTB7, PORTB6  */
        GPIOB->CRL  |=  GPIO_CRL_CNF6_1 | GPIO_CRL_MODE6  ;
            /*  PB6 Output Alternative function open drain = 50mhz    */
        GPIOB->CRL  |=  GPIO_CRL_CNF7_1 | GPIO_CRL_MODE7  ;   
            /*  PB6 Output Alternative function open drain = 50mhz    */
        GPIOB->BSRR |= GPIO_BSRR_BS6 | GPIO_BSRR_BS7    ;   /* SETPIN PB6,PB7   */
        RCC->APB1ENR |= RCC_APB1ENR_I2C1EN  ;
        break;
     case ((uint32_t)I2C2):
            /*  SDA :   PB11
                SCL :   PB10     */
        RCC->APB2ENR|= RCC_APB2ENR_IOPBEN   ;
        GPIOB->CRH  &=~ (GPIO_CRH_CNF10 | GPIO_CRH_MODE10 | GPIO_CRH_CNF11 | GPIO_CRH_MODE11) ; 
            /*  RESET MODE AND CNF OF PORTB10, PORTB11  */
        GPIOB->CRH  |=  GPIO_CRH_CNF10_1 | GPIO_CRH_MODE10  ;
            /*  PB10 Output Alternative function open drain = 50mhz    */
        GPIOB->CRH  |=  GPIO_CRH_CNF11_1 | GPIO_CRH_MODE11  ;   
            /*  PB11 Output Alternative function open drain = 50mhz    */
        GPIOB->BSRR |= GPIO_BSRR_BS10 | GPIO_BSRR_BS11    ;   /* SETPIN PB10,PB11   */
        break;
    }
    // I2C->CR1    |=  I2C_CR1_SWRST   ;   /*  RESET I2C BUS   */
    // I2C->CR1    &=~ I2C_CR1_SWRST   ;   /*  OUT RESET STATUS    */
    I2C->CR1    |=  ACK_select      ;
    //I2C->CCR    |=  I2C_CCR_DUTY    ;
    I2C->CR2    |=  36      ;
    I2C->CCR    |=  180     ;
    I2C->TRISE  |=  37      ;
    //I2C->OAR1   |= I2C_Slave_Address << 1   ;
}
void I2C_Enable(I2C_TypeDef* I2C){
    I2C->CR1    |= I2C_CR1_PE   ;
}
void I2C_Disable(I2C_TypeDef* I2C){
    I2C->CR1    &=~ I2C_CR1_PE   ;
}
void I2C_Write(I2C_TypeDef* I2C,uint8_t address,uint8_t u8data){
    I2C_Start(I2C)  ;
    I2C_Send7bit_Address(I2C,address,I2C_Transmit_Write)  ;
    I2C->DR = u8data    ;
    while (!(I2C1->SR1 & I2C_SR1_BTF))  ;
    I2C_Stop(I2C) ; 
}
void I2C_Start(I2C_TypeDef* I2C){
    I2C->CR1 |= I2C_CR1_START;
    while (!((I2C->SR1) & (I2C_SR1_SB)))    ;
}
void I2C_Stop(I2C_TypeDef* I2C) {
    I2C->CR1 |= I2C_CR1_STOP   ;
}
void I2C_Send7bit_Address(I2C_TypeDef* I2C, uint8_t address, I2C_Transmit_type type_trans){
    if(type_trans){
        I2C->DR |= address &(~0x01) ;
    }
    else{
        I2C->DR |= address |(0x01) ;
    }
    while (!((I2C1->SR1) & (I2C_SR1_ADDR)));
    uint8_t temp =  I2C1->SR1|I2C1->SR2;    /*Clear ADDR flag*/
}
void I2C_Send(I2C_TypeDef* I2C,uint8_t address,uint8_t u8data[],uint8_t size){
    I2C_Start(I2C)  ;
    I2C_Send7bit_Address(I2C,address,I2C_Transmit_Write)  ;
    for(int i = 0 ; i < size ; i++ ){
        I2C->DR = u8data[i]    ;
        while (!(I2C1->SR1 & I2C_SR1_BTF))  ;
    }
    I2C_Stop(I2C) ; 
}

#endif
