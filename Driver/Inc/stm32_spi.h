/*
@author - github: Anhconstant
- MCU : stm32f103c8
PERIPHERAL : SPI
*/

/*  
    (Decription): 
    MOSI    : Master out slave in
    MISO    : Master in slave out    
    SCK     : clock
    NSS     : chip select
/----------------------------------------------------------------------/
    CPOL    : Idle to start     : 1 - HIGH -> LOW ( 0: LOW t0 HIGH  )
    CPHA    : Synchronous data  : 1 : Phase 1 ( 0: Phase 2  )
*/
/*  PIN: SPI1:
        NSS     :   PA4
        SCK     :   PA5
        MISO    :   PA6
        MOSI    :   PA7
    PIN: SPI2:
        NSS     :   PB12
        SCK     :   PB13
        MISO    :   PB14
        MOSI    :   PB15
*/
#ifndef __SPI_H__
#define __SPI_H__
#include "stm32f10x.h"

#define size_data   unsigned char
#define size_buffer     (32)
#define SPI_MSB_Transfer    ((uint8_t) 0u)
#define SPI_LSB_Transfer    ((uint8_t) 1u)

typedef struct 
{
    size_data  buffer[size_buffer] ;    /*  buffer  */
    uint8_t size            ;           /*  size    */
    uint8_t triggle :   1   ;           /*  triggle */
}   SPI_data_RX ;

typedef enum{
    MODE_CPOL0_CPHA0    =   0   ,   /*  CPOL = 0    CPHA = 0   */
    MODE_CPOL0_CPHA1    =   1   ,   /*  CPOL = 0    CPHA = 1   */
    MODE_CPOL1_CPHA0    =   2   ,   /*  CPOL = 1    CPHA = 0   */
    MODE_CPOL1_CPHA1    =   3       /*  CPOL = 1    CPHA = 1   */
}SPI_MODE   ;   /*  CPOL    CPHA  */

typedef enum{
    Master  =   1<<2   ,   /*  Device is Master    */
    Slave   =   0<<2       /*  Device is Slave     */
}Master_Slave   ;

typedef enum{
    SPI_Baudrate_PCLK_2     =   0<<3   ,
    SPI_Baudrate_PCLK_4     =   1<<3   , 
    SPI_Baudrate_PCLK_8     =   2<<3   ,
    SPI_Baudrate_PCLK_16    =   3<<3   ,
    SPI_Baudrate_PCLK_32    =   4<<3   ,
    SPI_Baudrate_PCLK_64    =   5<<3   ,
    SPI_Baudrate_PCLK_128   =   6<<3   ,
    SPI_Baudrate_PCLK_256   =   7<<3   
}SPI_Baudrate;


void SPI_Init(SPI_TypeDef* SPI, SPI_MODE MODE,uint8_t MSB_LSB,SPI_Baudrate baudrate,Master_Slave select)     ;
void SPI_Write(SPI_TypeDef* SPI,uint8_t u8data)     ;
void SPI_Send(SPI_TypeDef* SPI,uint8_t u8data[], long size)     ;
void SPI_Enable(SPI_TypeDef* SPI)   ;
void SPI_Disable(SPI_TypeDef* SPI)   ;
void SPI_Int_Enable(SPI_TypeDef* SPI,uint16_t interrupt)   ;
void SPI_ChipSelect(GPIO_TypeDef* GPIO,uint32_t GPIO_PIN)   ;



#endif