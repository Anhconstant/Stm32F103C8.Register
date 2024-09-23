/*
@author - github : Anhconstant
- MCU : stm32f103c8
PERIPHERAL : I2C
*/
/* Decription I2C



----------------------------------------
    PIN I2C1:
        SDA :   PB7
        SCL :   PB6
        SMBAI:  PB5
    PIN I2C2:
        SDA :   PB11
        SCL :   PB10
        SMBAI:  PB12
*/

#ifndef __I2C_H__
#define __I2C_H__
#include "stm32f10x.h"

#define I2C_Master_Mode 
#define I2C_Slave_Mode 
#define I2C_Slave_Address           (0b001011)  /*  DEFAULT ADDRESS DEVICE  */  
#define I2C_Slave_Address_Lenght    (7)         /*  7 or 10 bit address , 7 is default */
#define ACK_enable  (1<<10)
#define ACK_disable 0

typedef enum{
    I2C_Transmit_Write   =   0   ,
    I2C_Transmit_Read    =   !I2C_Transmit_Write   
}I2C_Transmit_type;

void I2C_Init(I2C_TypeDef* I2C, uint32_t ACK_select )   ;
void I2C_Enable(I2C_TypeDef* I2C)   ;
void I2C_Disable(I2C_TypeDef* I2C)  ;
void I2C_Write(I2C_TypeDef* I2C,uint8_t address,uint8_t u8data) ;
void I2C_Send(I2C_TypeDef* I2C,uint8_t address,uint8_t u8data[],uint8_t size) ;
void I2C_Int_Enable(void)   ;
void I2C_Send7bit_Address(I2C_TypeDef* I2C, uint8_t address, I2C_Transmit_type type_trans)  ;
void I2C_Start(I2C_TypeDef* I2C)    ;
void I2C_Stop(I2C_TypeDef* I2C)     ;




#endif
