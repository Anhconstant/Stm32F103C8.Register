// #ifndef __REG_RCC_H__
// #define __REG_RCC_H__

/* TypeDef stuct RCC start         */

typedef struct
{
    struct
    {
        unsigned long HSION     :   1   ;
        unsigned long HSIRDY    :   1   ;
        unsigned long _RES_1    :   1   ;
        unsigned long HSITRIM   :   5   ;

        unsigned long HSICAL    :   8   ;

        unsigned long HSEON     :   1   ;
        unsigned long HSERDY    :   1   ;
        unsigned long HSEBYP    :   1   ;
        unsigned long CSSON     :   1   ;
        unsigned long _RES_2    :   4   ;

        unsigned long PLLON     :   1   ;
        unsigned long PLLRDY    :   1   ;
        unsigned long PLL2ON    :   1   ;
        unsigned long PLL2RDY   :   1   ;
        unsigned long PLL3ON    :   1   ;
        unsigned long PLL3RDY   :   1   ;
        unsigned long _RES_3    :   2   ;

    } CR    ;

    struct
    {
        unsigned long SW        :   2   ;
        unsigned long SWS       :   2   ;
        unsigned long HPRE      :   4   ;

        unsigned long HPRE1     :   3   ;
        unsigned long HPRE2     :   3   ;
        unsigned long ADCPRE    :   2   ;

        unsigned long PLLSRC    :   1   ;
        unsigned long PLLXTPRE  :   1   ;
        unsigned long PLLMUL    :   4   ;
        unsigned long OTGFSPRE  :   1   ;
        unsigned long _RES_1    :   1   ;

        unsigned long MCO       :   4   ;
        unsigned long _RES_2    :   4   ;

    } CFGR  ;

    struct
    {
        unsigned long LSIRDYF   :   1   ;
        unsigned long LSERDYF   :   1   ;
        unsigned long HSIRDYF   :   1   ;
        unsigned long HSERDYF   :   1   ;
        unsigned long PLLRDYF   :   1   ;
        unsigned long PLL2RDYF  :   1   ;
        unsigned long PLL3RDYF  :   1   ;
        unsigned long CSSF      :   1   ;

        unsigned long LSIRDYIE  :   1   ;
        unsigned long LSERDYIE  :   1   ;
        unsigned long HSIRDYIE  :   1   ;
        unsigned long HSERDYIE  :   1   ;
        unsigned long PLLRDYIE  :   1   ;
        unsigned long PLL2RDYIE :   1   ;
        unsigned long PLL3RDYIE :   1   ;
        unsigned long _RES_1    :   1   ;

        unsigned long LSIRDYC   :   1   ;
        unsigned long LSERDYC   :   1   ;
        unsigned long HSIRDYC   :   1   ;
        unsigned long HSERDYC   :   1   ;
        unsigned long PLLRDYC   :   1   ;
        unsigned long PLL2RDYC  :   1   ;
        unsigned long PLL3RDYC  :   1   ;
        unsigned long CSSC      :   1   ;

        unsigned long _RES_2    :   8   ;

    } CIR   ;

    struct
    {
        unsigned long AFIORST   :   1   ;
        unsigned long _RES_1    :   1   ;
        unsigned long IOPARST   :   1   ;
        unsigned long IOPBRST   :   1   ;
        unsigned long IOPCRST   :   1   ;
        unsigned long IOPDRST   :   1   ;
        unsigned long IOPERST   :   1   ;
        unsigned long _RES_2    :   2   ;

        unsigned long ADC1RST   :   1   ;
        unsigned long ADC2RST   :   1   ;
        unsigned long TIM1RST   :   1   ;
        unsigned long SPI1RST   :   1   ;
        unsigned long _RES_3    :   1   ;
        unsigned long USART1RST :   1   ;
        unsigned long _RES_4    :   17  ;

    } APB2RSTR  ;

    struct
    {
        unsigned long TIM2RST   :   1   ;
        unsigned long TIM3RST   :   1   ;
        unsigned long TIM4RST   :   1   ;
        unsigned long TIM5RST   :   1   ;
        unsigned long TIM6RST   :   1   ;
        unsigned long TIM7RST   :   1   ;
        unsigned long _RES_1    :   5   ;
        unsigned long WWDGRST   :   1   ;
        unsigned long _RES_2    :   2   ;
        unsigned long SPI2RST   :   1   ;
        unsigned long SPI3RST   :   1   ;

        unsigned long _RES_3    :   1   ;
        unsigned long USART2RST :   1   ;
        unsigned long USART3RST :   1   ;
        unsigned long UART4RST  :   1   ;
        unsigned long UART5RST  :   1   ;
        unsigned long I2C1RST   :   1   ;
        unsigned long I2C2RST   :   1   ;
        unsigned long _RES_4    :   2   ;
        unsigned long CAN1RST   :   1   ;
        unsigned long CAN2RST   :   1   ;
        unsigned long BKPRST    :   1   ;
        unsigned long PWRRST    :   1   ;
        unsigned long DACRST    :   1   ;
        unsigned long _RES_5    :   2   ;

    } APB1RSTR  ;

    struct
    {
        unsigned long DM1AEN    :   1   ;
        unsigned long DM2AEN    :   1   ;
        unsigned long SRAMEN    :   1   ;
        unsigned long _RES_1    :   1   ;
        unsigned long FLITFEN   :   1   ;
        unsigned long _RES_2    :   1   ;
        unsigned long CRCEN     :   1   ;
        unsigned long _RES_3    :   5   ;
        unsigned long OTGFSEB   :   1   ;
        unsigned long _RES_4    :   1   ;
        unsigned long ETHMACEN  :   1   ;
        unsigned long ETHMACTXEN:   1   ;

        unsigned long ETHMACRXEN:   1   ;
        unsigned long _RES_5    :   15  ;

    } AHBENR    ;

    struct
    {
        unsigned long AFIOEN    :   1   ;
        unsigned long _RES_1    :   1   ;
        unsigned long IOPAEN    :   1   ;
        unsigned long IOPBEN    :   1   ;
        unsigned long IOPCEN    :   1   ;
        unsigned long IOPDEN    :   1   ;
        unsigned long IOPEEN    :   1   ;
        unsigned long _RES_2    :   2   ;

        unsigned long ADC1EN    :   1   ;
        unsigned long ADC2EN    :   1   ;
        unsigned long TIM1EN    :   1   ;
        unsigned long SPI1EN    :   1   ;
        unsigned long _RES_3    :   1   ;
        unsigned long USART1EN  :   1   ;
        unsigned long _RES_4    :   17  ;

    } APB2ENR;

    struct
    {
        unsigned long TIM2EN    :   1   ;
        unsigned long TIM3EN    :   1   ;
        unsigned long TIM4EN    :   1   ;
        unsigned long TIM5EN    :   1   ;
        unsigned long TIM6EN    :   1   ;
        unsigned long TIM7EN    :   1   ;
        unsigned long _RES_1    :   5   ;
        unsigned long WWDGEN    :   1   ;
        unsigned long _RES_2    :   2   ;
        unsigned long SPI2EN    :   1   ;
        unsigned long SPI3EN    :   1   ;

        unsigned long _RES_3    :   1   ;
        unsigned long USART2EN  :   1   ;
        unsigned long USART3EN  :   1   ;
        unsigned long UART4EN   :   1   ;
        unsigned long UART5EN   :   1   ;
        unsigned long I2C1EN    :   1   ;
        unsigned long I2C2EN    :   1   ;
        unsigned long _RES_4    :   2   ;
        unsigned long CAN1EN    :   1   ;
        unsigned long CAN2EN    :   1   ;
        unsigned long BKPEN     :   1   ;
        unsigned long PWREN     :   1   ;
        unsigned long DACEN     :   1   ;
        unsigned long _RES_5    :   2   ;

    } APB1ENR;

    struct
    {
        unsigned long LSEON     :   1   ;
        unsigned long LSERDY    :   1   ;
        unsigned long LSEBYP    :   1   ;
        unsigned long _RES_1    :   5   ;

        unsigned long RTCSEL    :   2   ;
        unsigned long _RES_2    :   5   ;
        unsigned long RTCEN     :   1   ;

        unsigned long BDRST     :   1   ;
        unsigned long _RST_3    :   15  ;

    } BDCR  ;

    struct
    {
        unsigned long LSION     :   1   ;
        unsigned long LSIRDY    :   1   ;
        unsigned long _RES_1    :   22  ;

        unsigned long RMVF      :   1   ;
        unsigned long _RES_2    :   1   ;
        unsigned long PINRSTF   :   1   ;
        unsigned long PORRSTF   :   1   ;
        unsigned long SFTRSTF   :   1   ;
        unsigned long IWDGRSTF  :   1   ;
        unsigned long WWDGRSTF  :   1   ;
        unsigned long LPWRSTF   :   1   ;

    } CSR   ;

    struct
    {
        unsigned long _RES_1    :   12  ;
        unsigned long OTGFSRST  :   1   ;
        unsigned long _RES_2    :   1   ;
        unsigned long ETHMACRST :   1   ;
        unsigned long _RES_3    :   17  ;

    } AHBSTR;

    struct
    {
        unsigned long PREDIV1   :   4   ;
        unsigned long PREDIV2   :   4   ;

        unsigned long PLL2MUL   :   4   ;
        unsigned long PLL3MUL   :   4   ;

        unsigned long PREDIV1SRC:   1   ;
        unsigned long I2S2SRC   :   1   ;
        unsigned long I2S3SRC   :   1   ;
        unsigned long _RES      :   13  ;   

    } CFGR2 ;

} reg_RCC_TypeDef;

/* TypeDef stuct RCC end             */

/* Define RCC address register start         */

#define reg_RCC     ((reg_RCC_TypeDef *)0x40021000UL    )

/* Define RCC address register end           */

/* Declare Type start                        */

typedef enum
{
    HSE_OK = 0u,
    HSE_NOTOK
} reg_HSE_Status;

typedef enum
{
    HSI_OK = 0u,
    HSI_NOTOK
} reg_HSI_Status;
/* Declare Type end                        */

/* Declare Function start                   */

reg_HSE_Status reg_HSE_Detect(void)     ;

reg_HSE_Status reg_HSE_Ready(void)      ;

reg_HSE_Status reg_HSE_On(void)         ;

reg_HSI_Status reg_HSI_Ready(void)      ;

reg_HSI_Status reg_HSI_On(void)         ;

void reg_Clock_Enable_GPIOA(void)       ;

void reg_Clock_Enable_GPIOB(void)       ;

void reg_Clock_Enable_GPIOC(void)       ;

void reg_Clock_Enable_GPIOD(void)       ;

void reg_Clock_Enable_GPIOE(void)       ;

/* Declare Function end                   */

// #endif
