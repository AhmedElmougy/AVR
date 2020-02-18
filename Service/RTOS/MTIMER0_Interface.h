/*
 * File        : MTIMER0_Interface.h
 * Description : This file includes Timer0 Driver prototypes and definitions for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 23/6/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#ifndef __MTIMER0_INTERFACE_H__
#define __MTIMER0_INTERFACE_H__


/*==================================================================================================================
 * Timer0 Modules
 *==================================================================================================================*/


/* 
 * Prototype   : void MTIMER0_voidStartTimer(void);
 * Description : Start Timer0 counter register
 * Arguments   : void
 * return      : void  
 */
 void MTIMER0_voidStartTimer(void);
 
/* 
 * Prototype   : void MTIMER0_voidStopTimer(void);
 * Description : Stop Timer0 counter register
 * Arguments   : void
 * return      : void  
 */
 void MTIMER0_voidStopTimer(void);

/* 
 * Prototype   : void MTIMER0_voidInitializeTimer0(void);
 * Description : Initialize Timer0 with pre configured values in cofig file
 * Arguments   : void
 * return      : void  
 */
 void MTIMER0_voidInitializeTimer0(void);

/*==================================================================================================================
 * Timer0 Normal Mode
 *==================================================================================================================*/
 #if MTIMER0_MODE == MTIMER0_NORMAL_MODE

	/* 
	* Prototype   : void MTIMER0_voidSetDesiredTime_ms(u32 Copy_Time_ms);
	* Description : Calculate Timer0 tick time for desire input time in ms  
	* Arguments   : void
	* return      : void  
	*/
	void MTIMER0_voidSetDesiredTime_ms(u32 Copy_Time_ms);


	/* 
	* Prototype   : void MTIMER0_voidSetDesiredTime_us(u32 Copy_Time_us);
	* Description : Calculate Timer0 tick time for desire input time in us  
	* Arguments   : void
	* return      : void  
	*/
	void MTIMER0_voidSetDesiredTime_us(u32 Copy_Time_us);


   /*====================================================================
	* Timer0 Over flow Interrupt 
	*====================================================================*/
   /* 
	* Prototype   : void MTIMER0_voidOverFlowCallBack(void(*Copy_Ptr)(void));
	* Description : Callback function for Timer0 over flow Interrupt  
	* Arguments   : pointer to function Copy_Ptr 
	* return      : void  
	*/
	void MTIMER0_voidOverFlowCallBack(void(*Copy_Ptr)(void));



/*==================================================================================================================
 * Timer0 CTC Mode
 *==================================================================================================================*/
 #elif MTIMER0_MODE == MTIMER0_CTC_MODE
   
   /* 
	* Prototype   : void MTIMER0_voidSetDesiredTime_ms(u32 Copy_Time_ms);
	* Description : Calculate Timer0 tick time for desire input time in ms  
	* Arguments   : void
	* return      : void  
	*/
	void MTIMER0_voidSetDesiredTime_ms(u32 Copy_Time_ms);

   /* 
	* Prototype   : void MTIMER0_voidSetDesiredTime_us(u32 Copy_Time_us);
	* Description : Calculate Timer0 tick time for desire input time in us  
	* Arguments   : void
	* return      : void  
	*/
	void MTIMER0_voidSetDesiredTime_us(u32 Copy_Time_us);

   /* 
	* Prototype   : void MTIMER0_voidCTCCallBackfunction(void(*Copy_Ptr)(void));
	* Description : Call back function  
	* Arguments   : void
	* return      : Pointer to function Copy_Ptr  
	*/
	void MTIMER0_voidCTCCallBackfunction(void(*Copy_Ptr)(void));


/*==================================================================================================================
 * Timer0 Fast PWM Mode
 *==================================================================================================================*/
 #elif (MTIMER0_MODE == MTIMER0_FAST_PWM_MODE) 
 
   /* 
	* Prototype   : void MTIMER0_voidFastPWM(u8 Copy_u8DutyCycle,u8 Copy_u8PWMMode);
	* Description : output Fast PWM on OC0 pin with duty cycle of Copy_u8DutyCycle 
	* Arguments   : DutyCycle: determine PWM duty cycle from 0 to 100 
	* return      : void  
	*/
	void MTIMER0_voidFastPWM(u8 Copy_u8DutyCycle);
 
 /*==================================================================================================================
 * Timer0 Phase correct PWM Mode
 *==================================================================================================================*/
 #elif MTIMER0_MODE == MTIMER0_PHASE_CORCT_MODE
 
   /* 
	* Prototype   : void MTIMER0_voidPhaseCorrectPWM(u8 Copy_u8DutyCycle);
	* Description : output phase correct PWM on OC0 pin with duty cycle of Copy_u8DutyCycle
	* Arguments   : DutyCycle: determine PWM duty cycle from 0 to 100
	* return      : void  
	*/
	void MTIMER0_voidPhaseCorrectPWM(u8 Copy_u8DutyCycle);

 #endif


#endif