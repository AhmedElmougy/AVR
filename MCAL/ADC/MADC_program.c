/*
 * File        : ADC_Program.c
 * Description : This file includes ADC Driver implementations for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 9/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#include "LSTD_Types.h"
#include "LUTILS.h"
#include "MADC_Private.h"
#include "MADC_Interface.h"
#include "MADC_Config.h"


/*V reference VREF configuration*/
#if	  MADC_VREF == MADC_AVCC
	#define VREF  5000
#elif MADC_VREF == MADC_INTERNAL_VREF
	#define VREF  2560
#elif MADC_VREF == MADC_AREF
	#define VREF  MADC_AREF_VALUE
#endif

/*=========================================================================================
 * ADC Private Modules
 *=========================================================================================*/ 
 /* 
  * Prototype   : static void MADC_voidStartConersion(void);
  * Description : start ADC conversion
  * Arguments   : void
  * return      : void 
  */
  static void MADC_voidStartConersion(void)
  {
 	  /*Start Conversion*/
	  L_UTILS_SET_BIT(MADC_ADCSRA_REG,MADC_ADSC_BIT);
 
  }/*end of MADC_voidStartConersion()*/

/*=========================================================================================
 * ADC Public Modules
 *=========================================================================================*/

/* 
 * Prototype   : void MADC_voidInitializeADC(void);
 * Description : Initialize ADC with configured parameters
 * Arguments   : void
 * return      : void 
 */
 void MADC_voidInitializeADC(void)
 {
	/*Clear ADCSRA Reg*/
	MADC_ADCSRA_REG = 0;
	
	/*Choose ADC Prescaler*/
	MADC_ADCSRA_REG = MADC_PRESCALER_VALUE ;
	
	/*Enable ADC*/
	L_UTILS_SET_BIT(MADC_ADCSRA_REG,MADC_ADEN_BIT);
	
	/*Choose Trigger State*/
	L_UTILS_SET_BIT_VALUE(MADC_ADCSRA_REG,MADC_ADATE_BIT,MADC_AUTO_TRIGGER_STATUS);
	
	/*Choose ADC Interrupt State*/
	L_UTILS_SET_BIT_VALUE(MADC_ADCSRA_REG,MADC_ADIE_BIT,MADC_ADC_INT_STATUS);
	
	/*Choose V ref*/
	MADC_ADMUX_REG = 0;
	MADC_ADMUX_REG = (MADC_VREF<<6);
	
	/*Choose ADC Register Adjustment*/
	L_UTILS_SET_BIT_VALUE(MADC_ADMUX_REG,MADC_ADLAR_BIT,MADC_REG_ADJUSTMENT);
	
	/*Choose trigger Source if trigger is enabled*/
	#if MADC_AUTO_TRIGGER_STATUS == MADC_AUTO_TRIGGER_ENABLED 
	MADC_SFIOR_REG = (MADC_TRIGGER_SOURCE<<5);	
	#endif
 
 }/*end of MADC_voidInitializeADC()*/
 
/* 
 * Prototype   : u32  MADC_u16GetAnalogValueSynch(u8 Copy_ADChannel);
 * Description : get ADC value for specific ADC channel synchronous(wait until conversion is complete)
 * Arguments   : desired ADC channel
 * return      : u32 converted analog value 
 */
 u32  MADC_u32GetAnalogValueSynch(u8 Copy_ADChannel)
 {
	 /*local variables*/
	 volatile u16 Local_u16ADCDigitalValue = 0;
	 volatile u32 Local_u32ADCAnalogValue  = 0;
	 
	 /*Choose Channel*/
	 MADC_ADMUX_REG &= 0xf8;
	 MADC_ADMUX_REG |= Copy_ADChannel;
	 
	 /*start conversion*/
	 MADC_voidStartConersion();
	 
	 /*wait until conversion is complete*/
	 while(L_UTILS_GET_BIT(MADC_ADCSRA_REG,MADC_ADSC_BIT));
	 
	 /*Right adjustment calculations*/
	 #if   MADC_REG_ADJUSTMENT == MADC_LEFT_ADJUSTMENT
		Local_u16ADCDigitalValue  = (MADC_ADCL_REG >> 6) + (MADC_ADCH_REG << 2);
	 /*Left adjustment calculations*/
	 #elif MADC_REG_ADJUSTMENT == MADC_RIGHT_ADJUSTMENT
		Local_u16ADCDigitalValue  =  (MADC_ADCL_REG) + (MADC_ADCH_REG << 8);
	 #endif
	 
	 /*Calculate Analog value*/
	 Local_u32ADCAnalogValue   = (((u32) Local_u16ADCDigitalValue )* 5000)/1024;
	 
	 /*return analog value*/
	 return Local_u32ADCAnalogValue;
  
  }/*end of MADC_u32GetAnalogValueSynch()*/



/*=========================================================================================
 * EOF
 *=========================================================================================*/