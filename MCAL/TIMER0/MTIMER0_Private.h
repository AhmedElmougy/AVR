#ifndef __MTIMER0_PRIVATE_H__
#define __MTIMER0_PRIVATE_H__

//-------------------------------------------------------------------------------
//Timer0 Register Resolution
#define MTIMER0_REG_CAPACITY 256
//-------------------------------------------------------------------------------
//Prescaler
#define No_Prescaller             1
#define Prescaller_8              2
#define Prescaller_64             3
#define Prescaller_256            4
#define Prescaller_1024           5
#define Prescaller_FalExtClk      6
#define Prescaller_RaisExtClk     7
//-----------------------------------------
//Timer Modes
#define MTIMER0_NORMAL_MODE       0
#define MTIMER0_CTC_MODE          1
#define MTIMER0_FAST_PWM_MODE     2
#define MTIMER0_PHASE_CORCT_MODE  3


// Time0 Registers Pins
//TCCR0
#define MTIMER0_WGM00     6
#define MTIMER0_WGM01     3
//TIMSK
#define MTIMER0_TOIE0     0
#define MTIMER0_OCIE0     1
//SREG
#define MTIMER0_SREG_I    7
//--------------------------------------------------------------------------------
//Initial state
#define MTIMER0_ENABLED   0
#define MTIMER0_DISABLED  1

//-------------------------------------------------------------------------------
//Timer0 Registers
#define MTIMER0_SREG  (*(volatile u8 *)(0x5F)) //Global Status Reg
#define MTIMER0_TIMSK (*(volatile u8 *)(0x59)) //Timer interrupt control Reg
#define MTIMER0_TCCR0 (*(volatile u8 *)(0x53)) //Register TCCR0 (Timer0 Control Reg)
#define MTIMER0_TCNT0 (*(volatile u8 *)(0x52)) //Register TCNT0 (Timer 0 Reg)
#define MTIMER0_OCR0  (*(volatile u8 *)(0x5C)) //Register OCR0  (Output compare 0 Reg)
#define MTIMER0_TIFR  (*(volatile u8 *)(0x58)) //Register TIFR  (Flag Reg)
//--------------------------------------------------------------------------------

#endif