/*
@author - github: Anhconstant
- MCU : stm32f103c8
LIBRATY : DEFINE
*/
#ifndef __DEFINE_H__
#define __DEFINE_H__

#define U32SET              ((unsigned long)0xFFFFFFFFUL)
#define U16SET              ((unsigned long)0x0000FFFFUL)
#define U8SET               ((unsigned long)0x000000FFUL)
#define U32RESET            ((unsigned long)0x0UL)
#define SET(REG,BIT)        (REG|BIT)
#define RESET(REG,BIT)      (REG&(~BIT))
#define BIT(X)              (1<<X)
#define BIT0    0
#define BIT1    1<<1
#define BIT2    1<<2
#define BIT3    1<<3
#define BIT4    1<<4
#define BIT5    1<<5
#define BIT6    1<<6
#define BIT7    1<<7
#define BIT8    1<<8
#define BIT9    1<<9
#define BIT10   1<<10
#define BIT11   1<<11
#define BIT12   1<<12
#define BIT13   1<<13
#define BIT14   1<<14
#define BIT15   1<<15
#define BIT16   1<<16
#define BIT17   1<<17
#define BIT18   1<<18
#define BIT19   1<<19
#define BIT20   1<<20
#define BIT21   1<<21
#define BIT22   1<<22
#define BIT23   1<<23
#define BIT24   1<<24
#define BIT25   1<<25
#define BIT26   1<<26
#define BIT27   1<<27
#define BIT28   1<<28
#define BIT29   1<<29
#define BIT30   1<<30
#define BIT31   1<<31



#endif