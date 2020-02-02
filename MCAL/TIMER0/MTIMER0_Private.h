/*
 * File        : MTIMER0_Private.h
 * Description : This file includes Timer0 Private Macros for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 23/6/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#ifndef __MTIMER0_PRIVATE_H__
#define __MTIMER0_PRIVATE_H__



/*===============================================================================
 * Timer0 Private Macros
 *===============================================================================
 * Timer0 Initial state
 *======================================================*/
 #define MTIMER0_TIMER_START           1
 #define MTIMER0_TIMER_STOP            0
 /*======================================================
 *  Timer0 Enable Interrupt
 *======================================================*/
  #define MTIMER0_INT_ENABLED      1
  #define MTIMER0_INT_DISABLED     0
/*======================================================
 *  Timer0 Register Resolution
 *======================================================*/
 #define MTIMER0_REG_CAPACITY      256
/*======================================================
 *Prescaler Macros
 *======================================================*/
 #define No_Prescaller             1
 #define Prescaller_8              2
 #define Prescaller_64             3
 #define Prescaller_256            4
 #define Prescaller_1024           5
 #define Prescaller_FalExtClk      6
 #define Prescaller_RaisExtClk     7
/*======================================================
 * Timer0 Modes
 *======================================================*/
 #define MTIMER0_NORMAL_MODE       0
 #define MTIMER0_CTC_MODE          1
 #define MTIMER0_FAST_PWM_MODE     2
 #define MTIMER0_PHASE_CORCT_MODE  3


/*===============================================================================*/
/* Time0 Registers Pins*/
/*===============================================================================
 * TCCR0 Register pins
 *======================================================*/
 #define MTIMER0_WGM00			   6
 #define MTIMER0_WGM01             3
/*======================================================
 * TIMSK
 *======================================================*/
 #define MTIMER0_TOIE0             0
 #define MTIMER0_OCIE0             1
/*======================================================
 * SREG
 *======================================================*/
 #define MTIMER0_SREG_I            7

/*value to be masked with TCNT0 to stop register counting
 *===============================================================================*/
#define MTIMER0_STOP_MASK          0xf8
/*value to be masked with COM Bits 
 *===============================================================================*/
#define MTIMER0_COM_MASK           0b11001111
/*value to be masked with TCCR0 Reg to clear first 3 bits 
 *===============================================================================*/
#define MTIMER0_TCCR0_MASK         0xf8



/*===============================================================*/
/*OC0 Non PWM Modes*/
/*===============================================================*/

#define MTIMER0_DISCONNECT_OC0      0
#define MTIMER0_TOGGLE_OC0          1
#define MTIMER0_CLEAR_OC0           2
#define MTIMER0_SET_OC0             3

/*===============================================================*/
/*OC0 PWM Modes*/
/*===============================================================*/

#define MTIMER0_PWM_NONINVERTED_OC0 2
#define MTIMER0_PWM_INVERTED_OC0    3


/*===============================================================================
* Timer0 Registers Addresses
*===============================================================================*/
#define MTIMER0_SREG  (*(volatile u8 *)(0x5F)) /*Global Status Reg*/
#define MTIMER0_TIMSK (*(volatile u8 *)(0x59)) /*Timer interrupt control Reg*/
#define MTIMER0_TCCR0 (*(volatile u8 *)(0x53)) /*Register TCCR0 (Timer0 Control Reg)*/
#define MTIMER0_TCNT0 (*(volatile u8 *)(0x52)) /*Register TCNT0 (Timer 0 Reg)*/
#define MTIMER0_OCR0  (*(volatile u8 *)(0x5C)) /*Register OCR0  (Output compare 0 Reg)*/
#define MTIMER0_TIFR  (*(volatile u8 *)(0x58)) /*Register TIFR  (Flag Reg)*/

/*===============================================================================*
 * EOF
 *===============================================================================*/

#endif