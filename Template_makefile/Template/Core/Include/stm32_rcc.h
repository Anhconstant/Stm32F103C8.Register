/*
@author: Tran Tuan Anh 
@github: Anhconstant
- MCU : stm32f103c8
*/

#ifndef __RCC_H__
#define __RCC_H__

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
        unsigned long _RES_3    :   6   ;

    } CR    ;

    struct
    {
        unsigned long SW        :   2   ;
        unsigned long SWS       :   2   ;
        unsigned long HPRE      :   4   ;

        unsigned long PPRE1     :   3   ;
        unsigned long PPRE2     :   3   ;
        unsigned long ADCPRE    :   2   ;

        unsigned long PLLSRC    :   1   ;
        unsigned long PLLXTPRE  :   1   ;
        unsigned long PLLMUL    :   4   ;
        unsigned long USBPRE	  :   1   ;
        unsigned long _RES_1    :   1   ;

        unsigned long MCO       :   3   ;
        unsigned long _RES_2    :   5   ;

    } CFGR  ;

    struct
    {
        unsigned long LSIRDYF   :   1   ;
        unsigned long LSERDYF   :   1   ;
        unsigned long HSIRDYF   :   1   ;
        unsigned long HSERDYF   :   1   ;
        unsigned long PLLRDYF   :   1   ;
        unsigned long _RES_1	  :   2   ;
        unsigned long CSSF      :   1   ;

        unsigned long LSIRDYIE  :   1   ;
        unsigned long LSERDYIE  :   1   ;
        unsigned long HSIRDYIE  :   1   ;
        unsigned long HSERDYIE  :   1   ;
        unsigned long PLLRDYIE  :   1   ;
        unsigned long _RES_2    :   3   ;

        unsigned long LSIRDYC   :   1   ;
        unsigned long LSERDYC   :   1   ;
        unsigned long HSIRDYC   :   1   ;
        unsigned long HSERDYC   :   1   ;
        unsigned long PLLRDYC   :   1   ;
        unsigned long _RES_3	  :   2   ;
        unsigned long CSSC      :   1   ;

        unsigned long _RES_4    :   8   ;

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
        unsigned long IOPFRST   :   1   ;
			
				unsigned long IOPGRST   :   1   ;
        unsigned long ADC1RST   :   1   ;
        unsigned long ADC2RST   :   1   ;
        unsigned long TIM1RST   :   1   ;
        unsigned long SPI1RST   :   1   ;
				unsigned long TIM8RST   :   1   ;
				unsigned long USART1RST :   1   ;
				unsigned long ADC3RST   :   1   ;
			
        unsigned long _RES_2    :   3   ;
				unsigned long TIM9RST   :   1   ;
				unsigned long TIM10RST  :   1   ;
				unsigned long TIM11RST  :   1   ;
        unsigned long _RES_4    :   10  ;

    } APB2RSTR  ;

    struct
    {
        unsigned long TIM2RST   :   1   ;
        unsigned long TIM3RST   :   1   ;
        unsigned long TIM4RST   :   1   ;
        unsigned long TIM5RST   :   1   ;
        unsigned long TIM6RST   :   1   ;
        unsigned long TIM7RST   :   1   ;
				unsigned long TIM12RST  :   1   ;
				unsigned long TIM13RST  :   1   ;
			
				unsigned long TIM14RST  :   1   ;
        unsigned long _RES_1    :   2   ;
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
				unsigned long USBRST	  :   1   ;
				
        unsigned long _RES_4    :   1   ;
        unsigned long CAN1RST   :   1   ;
        unsigned long _RES_5	  :   1   ;
        unsigned long BKPRST    :   1   ;
        unsigned long PWRRST    :   1   ;
        unsigned long DACRST    :   1   ;
        unsigned long _RES_6    :   2   ;

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
        unsigned long _RES_3    :   1   ;
			
        unsigned long FSMCEN   	:   1   ;
        unsigned long _RES_4    :   1   ;
        unsigned long SDIOEN  	:   1   ;
        unsigned long _RES_5    :   21  ;

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
        unsigned long IOPFEN    :   1   ;
			
				unsigned long IOPGEN    :   1   ;
        unsigned long ADC1EN    :   1   ;
        unsigned long ADC2EN    :   1   ;
        unsigned long TIM1EN    :   1   ;
        unsigned long SPI1EN    :   1   ;
        unsigned long TIM8EN    :   1   ;
        unsigned long USART1EN  :   1   ;
				unsigned long ADC3EN    :   1   ;
			
        unsigned long _RES_2    :   3  	;
				unsigned long TIM9EN    :   1   ;
				unsigned long TIM10EN   :   1   ;
				unsigned long TIM11EN   :   1   ;
				unsigned long	_RES_3		:		10	;
			
    } APB2ENR;

    struct
    {
        unsigned long TIM2EN    :   1   ;
        unsigned long TIM3EN    :   1   ;
        unsigned long TIM4EN    :   1   ;
        unsigned long TIM5EN    :   1   ;
        unsigned long TIM6EN    :   1   ;
        unsigned long TIM7EN    :   1   ;
        unsigned long TIM12EN   :   1   ;
				unsigned long TIM13EN   :   1   ;
			
				unsigned long TIM14EN   :   1   ;
        unsigned long _RES_1    :   2   ;
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
				unsigned long USBEN    	:   1   ;
				
        unsigned long _RES_4    :   1   ;
        unsigned long CAN1EN    :   1   ;
        unsigned long _RES_5    :   1   ;
        unsigned long BKPEN     :   1   ;
        unsigned long PWREN     :   1   ;
        unsigned long DACEN     :   1   ;
        unsigned long _RES_6    :   2   ;

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

//    struct
//    {
//        unsigned long _RES_1    :   12  ;
//        unsigned long OTGFSRST  :   1   ;
//        unsigned long _RES_2    :   1   ;
//        unsigned long ETHMACRST :   1   ;
//        unsigned long _RES_3    :   17  ;

//    } AHBSTR;

//    struct
//    {
//        unsigned long PREDIV1   :   4   ;
//        unsigned long PREDIV2   :   4   ;

//        unsigned long PLL2MUL   :   4   ;
//        unsigned long PLL3MUL   :   4   ;

//        unsigned long PREDIV1SRC:   1   ;
//        unsigned long I2S2SRC   :   1   ;
//        unsigned long I2S3SRC   :   1   ;
//        unsigned long _RES      :   13  ;   

//    } CFGR2 ;

} RCC_TypeDef;

/* TypeDef stuct RCC end             */

/* Define RCC address register start         */

#define RCC     ((RCC_TypeDef *)0x40021000UL    )

/* Define RCC address register end           */

/* Define Value start           */

#define RCC_CR_HSEBYP_BYPASS    (1u )
#define RCC_CR_HSEBYP_NOTBYPASS (0u )

#define RCC_CR_HSE_OFF          (0u )
#define RCC_CR_HSE_ON           (1u ) 

#define RCC_CR_PLLOFF           (0u )
#define RCC_CR_PLLON            (1u )

#define RCC_CFGR_HPRE_SYSCLK_NOT_DIVIDED    (0u )
#define RCC_CFGR_HPRE_SYSCLK_DIVIDED_2      (8u )
#define RCC_CFGR_HPRE_SYSCLK_DIVIDED_4      (9u )
#define RCC_CFGR_HPRE_SYSCLK_DIVIDED_8      (10u)
#define RCC_CFGR_HPRE_SYSCLK_DIVIDED_16     (11u )
#define RCC_CFGR_HPRE_SYSCLK_DIVIDED_64     (12u )
#define RCC_CFGR_HPRE_SYSCLK_DIVIDED_128    (13u )
#define RCC_CFGR_HPRE_SYSCLK_DIVIDED_256    (14u )
#define RCC_CFGR_HPRE_SYSCLK_DIVIDED_512    (15u )

#define RCC_CFGR_PPRE1_HCLR_NOT_DIVIDED     (0u )
#define RCC_CFGR_PPRE1_HCLR_DIVIDED_2       (4u )
#define RCC_CFGR_PPRE1_HCLR_DIVIDED_4       (5u )
#define RCC_CFGR_PPRE1_HCLR_DIVIDED_8       (6u )
#define RCC_CFGR_PPRE1_HCLR_DIVIDED_16      (7u )

#define RCC_CFGR_PPRE2_HCLR_NOT_DIVIDED     (0u )
#define RCC_CFGR_PPRE2_HCLR_DIVIDED_2       (4u )
#define RCC_CFGR_PPRE2_HCLR_DIVIDED_4       (5u )
#define RCC_CFGR_PPRE2_HCLR_DIVIDED_8       (6u )
#define RCC_CFGR_PPRE2_HCLR_DIVIDED_16      (7u )

#define RCC_CFGR_ADCPRE_PCLR2_DIVIDED_2     (0u )
#define RCC_CFGR_ADCPRE_PCLR2_DIVIDED_4     (1u )
#define RCC_CFGR_ADCPRE_PCLR2_DIVIDED_6     (2u )
#define RCC_CFGR_ADCPRE_PCLR2_DIVIDED_8     (3u )

#define RCC_CFGR_USBPRE_48mhz             	(1u )
#define RCC_CFGR_USBPRE_72mhz             	(0u )

#define RCC_CFGR_PLLXTPRE_PRE_DIVIDED_1     (0u )
#define RCC_CFGR_PLLXTPRE_PRE_DIVIDED_2     (1u )

#define RCC_CFGR_PLLSRC_HSI_DIV2            (0u )
#define RCC_CFGR_PLLSRC_HSE                 (1u )

#define RCC_CFGR_PLLMUL_MUL_2               (0u )   /*reserved*/
#define RCC_CFGR_PLLMUL_MUL_3               (1u )   /*reserved*/
#define RCC_CFGR_PLLMUL_MUL_4               (2u )   
#define RCC_CFGR_PLLMUL_MUL_5               (3u )
#define RCC_CFGR_PLLMUL_MUL_6               (4u )
#define RCC_CFGR_PLLMUL_MUL_7               (5u )
#define RCC_CFGR_PLLMUL_MUL_8               (6u )
#define RCC_CFGR_PLLMUL_MUL_9               (7u )
#define RCC_CFGR_PLLMUL_MUL_10              (8u )   /*reserved*/
#define RCC_CFGR_PLLMUL_MUL_11              (9u )   /*reserved*/
#define RCC_CFGR_PLLMUL_MUL_12              (10u )  /*reserved*/
#define RCC_CFGR_PLLMUL_MUL_13              (11u )  /*reserved*/    
#define RCC_CFGR_PLLMUL_MUL_14              (12u )  /*reserved*/
#define RCC_CFGR_PLLMUL_MUL_15              (13u )  /*clock x 6.5*/
#define RCC_CFGR_PLLMUL_MUL_16              (14u )  /*reserved*/
#define RCC_CFGR_PLLMUL_MUL_16_2            (15u )  /*reserved*/

#define RCC_CFGR_SW_HSI_SELECTED            (0u )
#define RCC_CFGR_SW_HSE_SELECTED            (1u )
#define RCC_CFGR_SW_PLL_SELECTED            (2u )
#define RCC_CFGR_SW_NOT_ALLOWED             (3u )

#define RCC_CFGR_SWS_HSI                    (0u )
#define RCC_CFGR_SWS_HSE                    (1u )                        
#define RCC_CFGR_SWS_PLL                    (2u )                    
#define RCC_CFGR_SWS_NOT_APPLI              (3u )

/* Define Value end           */
/* Declare Type start                        */

typedef enum
{
    HSE_OK = 0u,
    HSE_NOTOK
} HSE_Status;

typedef enum
{
    HSI_OK = 0u,
    HSI_NOTOK
} HSI_Status;
//typedef enum
//{
//    clock_8mhz      = 1 ,
//    clock_16mhz     = 2 ,
//    clock_32mhz     = 3 ,
//    clock_36mhz     = 4 ,
//    Clock_72mhz     = 5 
//} CLOCK_FREQ;
/* Declare Type end                        */

/* Declare Function start                   */

HSE_Status HSE_Detect(void)     ;

HSE_Status HSE_Ready(void)      ;

HSE_Status HSE_On(void)         ;

HSI_Status HSI_Ready(void)      ;

HSI_Status HSI_On(void)         ;

void Clock_Enable_GPIOA(void)   ;

void Clock_Enable_GPIOB(void)   ;

void Clock_Enable_GPIOC(void)   ;

void Clock_Enable_GPIOD(void)   ;

void Clock_Enable_GPIOE(void)   ;

void Clock_Enable_TIM7(void)		;

void Clock_Enable_TIM4(void)		;

void Clock_72mhz(void)          ;

void Clock_64mhz(void)					;

unsigned long check_clock(void) ;


/* Declare Function end                   */

#endif
