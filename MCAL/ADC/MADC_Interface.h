/*
 * File        : MADC_Interface.h
 * Description : This interface file includes ADC Driver prototypes and definitions for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 9/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#ifndef _MADC_INTERFACE_H_
#define _MADC_INTERFACE_H_

/*ADC Channels*/
#define MADC_ADC0	0
#define MADC_ADC1	1
#define MADC_ADC2	2
#define MADC_ADC3	3
#define MADC_ADC4	4
#define MADC_ADC5	5
#define MADC_ADC6	6
#define MADC_ADC7	7

/*=========================================================================================
 * ADC Modules
 *=========================================================================================*/

/* 
 * Prototype   : void MADC_voidInitializeADC(void);
 * Description : Initialize ADC with configured parameters
 * Arguments   : void
 * return      : void 
 */
 void MADC_voidInitializeADC(void);

/* 
 * Prototype   : u32  MADC_u16GetAnalogValueSynch(u8 Copy_ADChannel);
 * Description : get ADC value for specific ADC channel
 * Arguments   : desired ADC channel
 * return      : u32 converted analog value 
 */
 u32  MADC_u32GetAnalogValueSynch(u8 Copy_ADChannel);

#endif

/*=========================================================================================
 * EOF
 *=========================================================================================*/