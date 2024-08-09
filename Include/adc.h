#ifndef __ADC_H__
#define __ADC_H__

typedef struct 
{
    unsigned long ADC_SR        ;

    unsigned long ADC_CR1       ;

    unsigned long ADC_CR2       ;

    unsigned long ADC_SMPR1     ;

    unsigned long ADC_SMPR2     ;

    unsigned long ADC_JOFR1     ;

    unsigned long ADC_JOFR2     ;
    
    unsigned long ADC_JOFR3     ;

    unsigned long ADC_JOFR4     ;

    unsigned long ADC_HTR       ;

    unsigned long ADC_LTR       ;

    unsigned long ADC_SQR1      ;

    unsigned long ADC_SQR2      ;

    unsigned long ADC_SQR3      ;

    unsigned long ADC_JSQR      ;

    unsigned long ADC_JDR1      ;

    unsigned long ADC_JDR2      ;

    unsigned long ADC_JDR3      ;

    unsigned long ADC_JDR4      ;

    unsigned long ADC_DR        ;

} ADC_TypeDef;

#define ADC1    ((ADC_TypeDef *)0x40012C00UL   )
#define ADC2    ((ADC_TypeDef *)0x40012800UL   )
#define ADC3    ((ADC_TypeDef *)0x40013C00UL   )


#endif
