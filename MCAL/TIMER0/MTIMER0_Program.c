/*
 * File        : MTIMER0_Program.c
 * Description : This file includes TIMER0 Driver implementations for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 23/6/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#include "LSTD_Types.h"
#include "LUTILS.h"
#include "MTIMER0_Private.h"
#include "MTIMER0_Config.h"
#include "MTIMER0_Interface.h"



/*====================================================================
 * Timer0 Interrupt ISRs
 *====================================================================*/
void __vector_10 (void) __attribute__ ((signal,used));
void __vector_11 (void) __attribute__ ((signal,used));

/*====================================================================
 * Call back pointers 
 *====================================================================*/
static void (*MTIMER0_OverFlowCallBackPointer)(void);
static void (*MTIMER0_CTCCallBackPointer)(void);

/*====================================================================
 * Global Variables
 *====================================================================*/
static volatile u32 MTIMER0_u32OverFlowNo   = 0;
static u8           MTIMER0_u8TCCR0Value    = 0;
static u8           MTIMER0_u8TCNT0Preload  = 0;
static u16          MTIMER0_u16Prescaler    = 1;


/*==================================================================================================================
 * Timer0 Modules
 *==================================================================================================================*/

/* 
 * Prototype   : void MTIMER0_voidStartTimer(void);
 * Description : Start Timer0 counter register
 * Arguments   : void
 * return      : void  
 */
 void MTIMER0_voidStartTimer(void)
 {
	 /*Start TCNT0 Reg counting by loading it's value*/
	 MTIMER0_TCCR0 = MTIMER0_u8TCCR0Value;          
 }
 
/* 
 * Prototype   : void MTIMER0_voidStopTimer(void);
 * Description : Stop Timer0 counter register
 * Arguments   : void
 * return      : void  
 */
 void MTIMER0_voidStopTimer(void)
 {
	 /*Stop TCNT0 Reg counting by loading zeros in CS00,CS01,CS02*/
 	 MTIMER0_TCCR0 = MTIMER0_u8TCCR0Value & MTIMER0_STOP_MASK; 
 }


/* 
 * Prototype   : void MTIMER0_voidInitializeTimer0(void);
 * Description : Initialize Timer0 with pre configured values in cofig file
 * Arguments   : void
 * return      : void  
 */
 void MTIMER0_voidInitializeTimer0(void)
 {
	

	/*TCCR0 Prescaler value is stored temporarily in MTIMER0_u8TCCR0Value variable*/
	/*Initialize TCCR0 value*/
	/*Reset first 3 BITS*/
	MTIMER0_u8TCCR0Value &= MTIMER0_TCCR0_MASK;
	/*Mask Prescaler value*/                
	MTIMER0_u8TCCR0Value |= MTIMER0_PRESCALER;    
	
	
	/*====================================================================
	 * calculate Prescaler value that will be used later in equations
	 *====================================================================*/
	MTIMER0_u16Prescaler = 1; 
	#if (MTIMER0_PRESCALER==No_Prescaller)
		/* set prescaler vale with a value higher than prescaler value 
		 * because in calculation when dividing value will be zero (no flaut point calculation)*/
		MTIMER0_u16Prescaler = MTIMER0_F_CPU/1000000;
 
	#elif (MTIMER0_PRESCALER==Prescaller_8)
	
		MTIMER0_u16Prescaler = 8;
	
	#elif (MTIMER0_PRESCALER>Prescaller_8 && MTIMER0_PRESCALER<=Prescaller_1024)
		
		/*caclulate prescaler = 2^(2*Prescaller)*/
		for (u8 i=0;i<(MTIMER0_PRESCALER*2);i++)
		{
			MTIMER0_u16Prescaler *= 2;
		}
	
	#else
	
		#error "Wrong Prescaller"
	
	#endif
	/*====================================================================
	 * Choose Timer0 Mode
	 *====================================================================*/
	#if (MTIMER0_MODE==MTIMER0_NORMAL_MODE)
	
		//Choose normal mode
		L_UTILS_CLEAR_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM00);
		L_UTILS_CLEAR_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM01);
		
		#if (MTIMER0_INTERRUPT_STATUS == MTIMER0_INT_ENABLED)
		//enable Global interrupt
		L_UTILS_SET_BIT(MTIMER0_SREG,MTIMER0_SREG_I);
		//enable Timer0 Overflow interrupt
		L_UTILS_SET_BIT(MTIMER0_TIMSK,MTIMER0_TOIE0);
		#endif
	
	
	#elif (MTIMER0_MODE==MTIMER0_CTC_MODE)
	
		/*Choose CTC mode*/
		L_UTILS_CLEAR_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM00);
		L_UTILS_SET_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM01);
		
		/*Set OC0 initial value*/
		MTIMER0_OCR0 = MTIMER0_OCR0_VALUE;
		
		#if (MTIMER0_INTERRUPT_STATUS == MTIMER0_INT_ENABLED)
		//enable Global interrupt
		L_UTILS_SET_BIT(MTIMER0_SREG,MTIMER0_SREG_I);
		//enable Timer0 Overflow interrupt
		L_UTILS_SET_BIT(MTIMER0_TIMSK,MTIMER0_OCIE0);
		#endif
	
	
	#elif (MTIMER0_MODE==MTIMER0_PHASE_CORCT_MODE)
	
		/*Choose Phase correct mode*/
		L_UTILS_SET_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM00);
		L_UTILS_CLEAR_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM01);
	
	#elif (MTIMER0_MODE==MTIMER0_FAST_PWM_MODE)
	
		/*Choose Fast PWM mode*/
		L_UTILS_SET_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM00);
		L_UTILS_SET_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM01);
	
	#else
		#error "Wrong Tomer0 Mode"
	#endif
	
	
	/*Choose OC0 Pin Mode*/
	/*mask COM00,COM01 bits with zeros*/
	MTIMER0_u8TCCR0Value &= MTIMER0_COM_MASK;
	/*Put mode in COM00,COM01 bits*/
	MTIMER0_u8TCCR0Value |= (MTIMER0_OC0_MODE<<4) ;
		
	
		
 }/*MTIMER0_voidInitializeTimer0*/

#if MTIMER0_MODE == MTIMER0_NORMAL_MODE

/*==================================================================================================================
 * Timer0 Normal Mode
 *==================================================================================================================*/

/* 
 * Prototype   : void MTIMER0_voidSetDesiredTime_ms(u32 Copy_Time_ms);
 * Description : Calculate Timer0 tick time for desire input time in ms  
 * Arguments   : void
 * return      : void  
 */
void MTIMER0_voidSetDesiredTime_ms(u32 Copy_Time_ms)
{
	/*Timer0 calculations*/
	 
	u32 Local_u32TickTime               = (MTIMER0_u16Prescaler*1000000)/MTIMER0_F_CPU ;  /*Time in micro second*/ 
	u32 Local_u32OverFlowTime           = Local_u32TickTime * MTIMER0_REG_CAPACITY ;
	u32 Local_u32DesiredTime            = Copy_Time_ms*1000;                              /*Time in micro second*/
	
	if (MTIMER0_PRESCALER == No_Prescaller)
	{
		/*Multiply bu the same value multiplied by prescaler*/
		Local_u32DesiredTime = Local_u32DesiredTime * (MTIMER0_F_CPU/1000000);
	}
	/*Number of over flow required*/
	MTIMER0_u32OverFlowNo               = Local_u32DesiredTime/Local_u32OverFlowTime;			
	/*Number of over flaws remainder*/
	u32 MTIMER0_u32OverFlowRemainder    = Local_u32DesiredTime%Local_u32OverFlowTime;
	
	/*clear TCNT0 Register*/
	MTIMER0_TCNT0=0; 
	
	/*if there is initial value*/
	if (MTIMER0_u32OverFlowRemainder>0)
	{
		/*initialize TCNT0 value with pre load value */
		MTIMER0_u8TCNT0Preload = MTIMER0_REG_CAPACITY - MTIMER0_u32OverFlowRemainder ; 
		MTIMER0_TCNT0 = MTIMER0_u8TCNT0Preload; 
		/*increment no of overflows by one*/
		MTIMER0_u32OverFlowNo++; 
	}
	
	/*Start counter by setting TCCR0 value*/
	MTIMER0_voidStartTimer();
	
}/*end of MTIMER0_voidSetDesiredTime_ms()*/

/* 
 * Prototype   : void MTIMER0_voidSetDesiredTime_us(u32 Copy_Time_us);
 * Description : Calculate Timer0 tick time for desire input time in us  
 * Arguments   : void
 * return      : void  
 */
void MTIMER0_voidSetDesiredTime_us(u32 Copy_Time_us)
{
	
	/*Timer0 calculations*/
	
	u32 Local_u32TickTime               = (MTIMER0_u16Prescaler*1000000)/MTIMER0_F_CPU ;  /*Time in micro second*/
	u32 Local_u32OverFlowTime           = Local_u32TickTime * MTIMER0_REG_CAPACITY ;
	u32 Local_u32DesiredTime            = Copy_Time_us;									  /*Time in micro second*/
	
	if (MTIMER0_PRESCALER == No_Prescaller)
	{
		/*Multiply bu the same value multiplied by prescaler*/
		Local_u32DesiredTime = Local_u32DesiredTime * (MTIMER0_F_CPU/1000000);
	}
	
	MTIMER0_u32OverFlowNo               = Local_u32DesiredTime/Local_u32OverFlowTime;
	u32 MTIMER0_u32OverFlowRemainder    = Local_u32DesiredTime%Local_u32OverFlowTime;
	
	/*clear TCNT0 Register*/
	MTIMER0_TCNT0=0;
	
	/*if there is initial value*/
	if (MTIMER0_u32OverFlowRemainder>0)
	{
		/*initialize TCNT0 value with pre load value */
		MTIMER0_u8TCNT0Preload = MTIMER0_REG_CAPACITY - MTIMER0_u32OverFlowRemainder ;
		MTIMER0_TCNT0 = MTIMER0_u8TCNT0Preload;
		/*increment no of overflows by one*/
		MTIMER0_u32OverFlowNo++;
	}
	
	/*Start counter by setting TCCR0 value*/
	MTIMER0_voidStartTimer();
	
}/*end of MTIMER0_voidSetDesiredTime_us()*/


/*====================================================================
 * Timer0 Over flow Interrupt 
 *====================================================================*/
/* 
 * Prototype   : void MTIMER0_voidOverFlowCallBack(void(*Copy_Ptr)(void));
 * Description : Callback function for Timer0 over flow Interrupt  
 * Arguments   : pointer to function Copy_Ptr 
 * return      : void  
 */
 void MTIMER0_voidOverFlowCallBack(void(*Copy_Ptr)(void))
 {
	 MTIMER0_OverFlowCallBackPointer = Copy_Ptr;
 }

/* 
 * Prototype   : void __vector_11(void);
 * Description : Timer0 over flow ISR  
 * Arguments   : void 
 * return      : void  
 */
void __vector_11(void) /*Timer0 over flow ISR*/
{
	static u32 Local_u32Counter = 0;
	Local_u32Counter++;
	if(Local_u32Counter == MTIMER0_u32OverFlowNo)
	{
		/*Run call back function for Timer0 over flow interrupt*/
		MTIMER0_OverFlowCallBackPointer();
		
		Local_u32Counter = 0;
		MTIMER0_TCNT0 =   MTIMER0_u8TCNT0Preload;
	}
		
	
}/*end of __vector_11()*/


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
 void MTIMER0_voidSetDesiredTime_ms(u32 Copy_Time_ms)
 {
 	 /*Timer0 calculations*/
	 u32 Local_u32TickTime    = (MTIMER0_u16Prescaler * 1000000) / MTIMER0_F_CPU ;  /*Time in micro second*/ 
	 u32 Local_u32DesiredTime = Copy_Time_ms * 1000;                                /*Time in micro second*/
	 if (MTIMER0_PRESCALER == No_Prescaller)
	 {
		 /*Multiply bu the same value multiplied by prescaler*/
		 Local_u32DesiredTime = Local_u32DesiredTime * (MTIMER0_F_CPU/1000000);
	 }
	 
	 /*set OCR0 value*/
	 MTIMER0_OCR0    = Local_u32DesiredTime / Local_u32TickTime; 
	
	 /*Start counter by setting TCCR0 value*/
	 MTIMER0_voidStartTimer();
	
 }/*end of MTIMER0_voidSetDesiredTime_ms()*/

/* 
 * Prototype   : void MTIMER0_voidSetDesiredTime_us(u32 Copy_Time_us);
 * Description : Calculate Timer0 tick time for desire input time in us  
 * Arguments   : void
 * return      : void  
 */
 void MTIMER0_voidSetDesiredTime_us(u32 Copy_Time_us)
 {
  	 /*Timer0 calculations*/
	 u32 Local_u32TickTime    = (MTIMER0_u16Prescaler * 1000000) / MTIMER0_F_CPU ;  /*Time in micro second*/
	 u32 Local_u32DesiredTime = Copy_Time_us;                                       /*Time in micro second*/
	 if (MTIMER0_PRESCALER == No_Prescaller)
	 {
		 /*Multiply bu the same value multiplied by prescaler*/
		 Local_u32DesiredTime = Local_u32DesiredTime * (MTIMER0_F_CPU/1000000);
	 }
	
	 /*set OCR0 value*/
	 MTIMER0_OCR0    = Local_u32DesiredTime / Local_u32TickTime;
	
	 /*Start counter by setting TCCR0 value*/
	 MTIMER0_voidStartTimer();
	
 }/*end of MTIMER0_voidSetDesiredTime_us()*/

 /* 
 * Prototype   : void MTIMER0_voidCTCCallBackfunction(void(*Copy_Ptr)(void));
 * Description : Call back function  
 * Arguments   : void
 * return      : Pointer to function Copy_Ptr  
 */
 void MTIMER0_voidCTCCallBackfunction(void(*Copy_Ptr)(void))
 {
	 //save function address in global pointer to function
 	 MTIMER0_CTCCallBackPointer = Copy_Ptr;
	  
 }/*end of MTIMER0_voidCTCCallBackfn()*/

 /* 
 * Prototype   : void __vector_10(void);
 * Description : Timer0 output compare match ISR 
 * Arguments   : void
 * return      : void  
 */
 void __vector_10(void)/*Timer0 CTC ISR*/
 {
 	 /*Run call back function*/
	 MTIMER0_CTCCallBackPointer();

 }/*end of __vector_10()*/


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
 void MTIMER0_voidFastPWM(u8 Copy_u8DutyCycle)
 {
	 /*configure PWM Duty Cycle*/
	 MTIMER0_OCR0 = (Copy_u8DutyCycle*MTIMER0_REG_CAPACITY)/100;
	 /*Start PWM*/ 
	 MTIMER0_voidStartTimer();
	 
 }/*end of MTIMER0_voidFastPWM()*/
 
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
 void MTIMER0_voidPhaseCorrectPWM(u8 Copy_u8DutyCycle)
 {
	/*configure PWM Duty Cycle*/
 	MTIMER0_OCR0 = (Copy_u8DutyCycle*(MTIMER0_REG_CAPACITY-1))/100;
 	/*Start PWM*/
	MTIMER0_voidStartTimer();
	 
 }/*end of MTIMER0_voidPhaseCorrectPWM()*/
 
 /*==================================================================================================================
  * EOF 
  *==================================================================================================================*/

 #endif
