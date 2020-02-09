/*
 * File        : MADC_Private.c
 * Description : This file includes ADC  private macros and declarations for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 9/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#ifndef _MADC_PRIVATE_H_
#define _MADC_PRIVATE_H_

/*=========================================================================================
 * ADC Registers
 *=========================================================================================*/ 
#define MADC_SFIOR_REG     (*(volatile u8 *)(0x50))
#define MADC_ADMUX_REG     (*(volatile u8 *)(0x27))
#define MADC_ADCSRA_REG    (*(volatile u8 *)(0x26)) 
#define MADC_ADCH_REG      (*(volatile u8 *)(0x25))
#define MADC_ADCL_REG      (*(volatile u8 *)(0x24))

/*ADMUX Reg*/
#define MADC_MUX0_BIT       0
#define MADC_MUX1_BIT       1
#define MADC_MUX2_BIT		2     
#define MADC_MUX3_BIT		3
#define MADC_MUX4_BIT		4
#define MADC_ADLAR_BIT		5
#define MADC_REFS0_BIT		6
#define MADC_REFS1_BIT		7

/*ADCSRA Reg*/
#define MADC_ADPS0_BIT      0
#define MADC_ADPS1_BIT      1
#define MADC_ADPS2_BIT		2
#define MADC_ADIE_BIT		3
#define MADC_ADIF_BIT		4
#define MADC_ADATE_BIT		5
#define MADC_ADSC_BIT		6
#define MADC_ADEN_BIT		7  

/*SFIOR Reg*/
#define MADC_ADTS0_BIT		5
#define MADC_ADTS1_BIT		6
#define MADC_ADTS2_BIT		7

/*=========================================================================================
 * Config parameters
 *=========================================================================================*/ 

/*VREF Select*/
#define MADC_AREF		            0
#define MADC_AVCC					1
#define MADC_INTERNAL_VREF			3

/*ADC Adjustment*/
#define MADC_RIGHT_ADJUSTMENT		0
#define MADC_LEFT_ADJUSTMENT		1

/*ADC Interrupt State*/
#define MADC_INT_DISABLED			0
#define MADC_INT_ENABLED			1

/*ADC Input CLK Prescaler*/
#define MADC_PRESCALER_2			1
#define MADC_PRESCALER_4			2
#define MADC_PRESCALER_8			3
#define MADC_PRESCALER_16			4
#define MADC_PRESCALER_32			5
#define MADC_PRESCALER_64			6
#define MADC_PRESCALER_128			7

/*ADC Trigger Sources */
#define MADC_FREE_RUNNING           0
#define MADC_ANALOG_COMPARATOR      1
#define MADC_EXTERNAL_INT           2
#define MADC_TIMER0_COMPARE_MATCH   3
#define MADC_TIMER0_OVER_FLOW       4
#define MADC_TIMERB_COMPARE_MATCH   5
#define MADC_TIMER1_OVER_FLOW       6
#define MADC_TIMER1_CAPTURE_EVENT   7

/*ADC AAuto Trigger State*/
#define MADC_AUTO_TRIGGER_DISABLED  0
#define MADC_AUTO_TRIGGER_ENABLED   1

#endif

/*=========================================================================================
 * EOF
 *=========================================================================================*/