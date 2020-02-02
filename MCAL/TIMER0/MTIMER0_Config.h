/*
 * File        : MTIMER0_Config.h
 * Description : This file includes Timer0 Driver configurations for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 23/6/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */


#ifndef __MTIMER0_Config_H__
#define __MTIMER0_Config_H__

/*
 * Notes :
 * ======================================
 * - F_CPU and prescaler will determine PWM Frequency configure them accordingly 
 * 
 * - you can configure Timer0 in Normal mode and CTC mode in 2 ways:
 *   using MTIMER0_voidSetDesiredTime_ms() function or by configuring F_CPU and prescaler to set desired time
 *  
 * - in CTC mode using MTIMER0_voidSetDesiredTime_ms() is limited by OCR Max value 256
 *   and Maximun generated time is Tick time * 256 if inputed a larger number fn will not work properly  
 * 
 * - MTIMER0_voidSetDesiredTime_us() acurecy decreas below 200 us
 */

/*MCU Clock frequency*/
#define MTIMER0_F_CPU           8000000UL

/* 
 * Choose prescaler from 
 * No_Prescaller - Prescaller_8 - Prescaller_64 - Prescaller_256 - 
 * Prescaller_1024 - Prescaller_FalExtClk - Prescaller_RaisExtClk
 * Prescaller_FalExtClk - Prescaller_RaisExtClk these two options are used with counter option
 */
#define MTIMER0_PRESCALER       Prescaller_8

/*
 * Choose Mode :
 * MTIMER0_NORMAL_MODE - MTIMER0_CTC_MODE - MTIMER0_FAST_PWM_MODE - MTIMER0_PHASE_CORCT_MODE  
 */
#define MTIMER0_MODE            MTIMER0_NORMAL_MODE

/* 
 * Timers interrupt initial status :
 * MTIMER0_INT_ENABLED MTIMER0_INT_DISABLED
 */
#define MTIMER0_INTERRUPT_STATUS   MTIMER0_INT_ENABLED


 

/* 
 * Choose Timer0 OC0 Mode :
 * with PWM modes:
 * MTIMER0_DISCONNECT_OC0, MTIMER0_PWM_NONINVERTED_OC0, MTIMER0_PWM_INVERTED_OC0   
 * with non PWM Modes: 
 * MTIMER0_DISCONNECT_OC0, MTIMER0_TOGGLE_OC0, MTIMER0_CLEAR_OC0, MTIMER0_SET_OC0 
 */
//#define MTIMER0_OC0_MODE   MTIMER0_PWM_NONINVERTED_OC0
#define MTIMER0_OC0_MODE   MTIMER0_DISCONNECT_OC0


/*OCR0 Initial Value*/
#define MTIMER0_OCR0_VALUE  250

#endif