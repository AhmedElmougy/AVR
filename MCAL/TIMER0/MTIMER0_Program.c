#include "LSTD_Types.h"
#include "LUTILS.h"
#include "MDIO_Interface.h"
#include "MTIMER0_Private.h"
#include "MTIMER0_Interface.h"
#include "MTIMER0_Config.h"


//----------------------------------------------------------------
//Timer0 ISR
void __vector_10 (void) __attribute__ ((signal,used));
void __vector_11 (void) __attribute__ ((signal,used));


static void (*MTIMER0_SWPWMCallBackPointer)(void);
static void (*MTIMER0_TIMER0OverFlowCallBackPointer)(void);
static void (*MTIMER0_CallBackPointer3)(void);

static volatile u32 MTIMER0_u32OverFlowNo   = 0;
static u8           MTIMER0_u8TCCR0Value    = 0;
static u8           MTIMER0_u8TCNT0Preload  = 0;
static u16          MTIMER0_u16Prescaler    = 1;

static u32 MTIMER0_u32SWPWMTime=0;
static u32 MTIMER0_u32SWPWMOnTime=0;


void MTIMER0_voidINIT(void)
{
	//TCCR0 Prescaler value is stored temporarily in this variable
	MTIMER0_u8TCCR0Value &= 0xf8;                //Reset first 3 BITS
	MTIMER0_u8TCCR0Value |= MTIMER0_PRESCALER;   //Mask Prescaler value 
	
	//--------------------------------------------------------------------------------
	//calculate Prescaler value that will be used later in equations
	MTIMER0_u16Prescaler = 1; 
	if (MTIMER0_PRESCALER==No_Prescaller)
	{
		MTIMER0_u16Prescaler=1;
	} 
	else if (MTIMER0_PRESCALER==Prescaller_8)
	{
		MTIMER0_u16Prescaler=8;
	}
	else if (MTIMER0_PRESCALER>Prescaller_8 && MTIMER0_PRESCALER<=Prescaller_1024)
	{	
		//caclulate prescaler = 2^(2*Prescaller)
		for (u8 i=0;i<(MTIMER0_PRESCALER*2);i++)
		{
			MTIMER0_u16Prescaler *= 2;
		}
	}
	//--------------------------------------------------------------------------------
	//Choose Mode
	if (MTIMER0_MODE==MTIMER0_NORMAL_MODE)
	{
		//Choose normal mode
		CLEAR_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM00);
		CLEAR_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM01);
		//enable Global interrupt
		SET_BIT(MTIMER0_SREG,MTIMER0_SREG_I);
		//enable Timer0 Overflow interrupt
		SET_BIT(MTIMER0_TIMSK,MTIMER0_TOIE0);
		
	}
	else if(MTIMER0_MODE==MTIMER0_PHASE_CORCT_MODE)
	{
		//Choose Phase correct mode
		SET_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM00);
		CLEAR_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM01);
		//enable Global interrupt
		SET_BIT(MTIMER0_SREG,MTIMER0_SREG_I);
		//enable Timer0 OCIE interrupt
		SET_BIT(MTIMER0_TIMSK,MTIMER0_OCIE0);
		//enable Timer0 Overflow interrupt
		SET_BIT(MTIMER0_TIMSK,MTIMER0_TOIE0);
	}
	else if(MTIMER0_MODE==MTIMER0_CTC_MODE)
	{
		//Choose CTC mode
		CLEAR_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM00);
		SET_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM01);
		//enable Global interrupt
		SET_BIT(MTIMER0_SREG,MTIMER0_SREG_I);
		//enable Timer0 OCIE interrupt
		SET_BIT(MTIMER0_TIMSK,MTIMER0_OCIE0);
		//Set OCR0 value
		MTIMER0_OCR0 = MTIMER0_T_OCR	;
	}
	else if(MTIMER0_MODE==MTIMER0_FAST_PWM_MODE)
	{
		//Choose Fast PWM mode
		SET_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM00);
		SET_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM01);
		//enable Global interrupt
		SET_BIT(MTIMER0_SREG,MTIMER0_SREG_I);
		//enable Timer0 OCIE interrupt
		SET_BIT(MTIMER0_TIMSK,MTIMER0_OCIE0);
		//enable Timer0 Overflow interrupt
		SET_BIT(MTIMER0_TIMSK,MTIMER0_TOIE0);
	}
	
	//--------------------------------------------------------------------------------
	//Timer0 Initial state
	if (MTIMER0_INITIAL_STATE==MTIMER0_ENABLED)
	{
		MTIMER0_voidStartTimer(); //start timer
	} 
	else if(MTIMER0_INITIAL_STATE==MTIMER0_DISABLED)
	{
		MTIMER0_voidStopTimer(); //stop timer
	}
	else
	{
		/*Error*/
	}
}

#if MTIMER0_MODE == MTIMER0_NORMAL_MODE

void MTIMER0_voidSetDesiredTime_ms(u32 Copy_Time_ms)
{
	//Timer calculations
	u32 Local_u32TickTime               = (MTIMER0_u16Prescaler*1000000)/MTIMER0_F_CPU ;  //Time in micro second 
	u32 Local_u32OverFlowTime           = Local_u32TickTime * MTIMER0_REG_CAPACITY ;
	u32 Local_u32DesiredTime            = Copy_Time_ms*1000;                              //Time in micro second 
	MTIMER0_u32OverFlowNo               = Local_u32DesiredTime/Local_u32OverFlowTime;			
	u32 MTIMER0_u32OverFlowRemainder    = Local_u32DesiredTime%Local_u32OverFlowTime;
	
	MTIMER0_TCNT0=0; //clear counter
	if (MTIMER0_u32OverFlowRemainder>0)//if there is an initial value
	{
		MTIMER0_u8TCNT0Preload = MTIMER0_REG_CAPACITY - MTIMER0_u32OverFlowRemainder ; 
		MTIMER0_TCNT0 = MTIMER0_u8TCNT0Preload; 
		MTIMER0_u32OverFlowNo++; //increment no of overflows by one
	}
	
	//Start counter by setting TCCR0 value
	MTIMER0_voidStartTimer();
}
void MTIMER0_voidSetDesiredTime_us(u32 Copy_Time_us)
{
	//Timer calculations
	u32 Local_u32TickTime               = (MTIMER0_u16Prescaler*1000000)/MTIMER0_F_CPU ;  //Time in micro second
	u32 Local_u32OverFlowTime           = Local_u32TickTime * MTIMER0_REG_CAPACITY ;
	u32 Local_u32DesiredTime            = Copy_Time_us;                                   //Time in micro second
	MTIMER0_u32OverFlowNo               = Local_u32DesiredTime/Local_u32OverFlowTime;
	u32 MTIMER0_u32OverFlowRemainder    = Local_u32DesiredTime%Local_u32OverFlowTime;
	
	MTIMER0_TCNT0=0; //clear counter
	if (MTIMER0_u32OverFlowRemainder>0)//if there is an initial value
	{
		MTIMER0_u8TCNT0Preload = MTIMER0_REG_CAPACITY - MTIMER0_u32OverFlowRemainder ;
		MTIMER0_TCNT0 = MTIMER0_u8TCNT0Preload;
		MTIMER0_u32OverFlowNo++; //increment no of overflows by one
	}
	
	//Start counter by setting TCCR0 value
	MTIMER0_voidStartTimer();	
}
//-------------------------------------------------------------------------
//S/W PWM 
void MTIMER0_voidSWPWM(u8 Copy_u32PWMDutyCycle,u32 Copy_u32Frequency)
{
	MTIMER0_u32SWPWMTime   = 1000000/Copy_u32Frequency ; //Time in us
	MTIMER0_u32SWPWMOnTime = (Copy_u32PWMDutyCycle*MTIMER0_u32SWPWMTime)/100 ;
}
void MTIMER0_voidSWPWMCallBack(void(*Copy_Ptr)(void))
{
	MTIMER0_SWPWMCallBackPointer = Copy_Ptr;
}
//Timer0 OV Interrupt
void __vector_11(void)
{	
	static u32  Local_u32PWMCounter_us = 0;
	static u32 Local_u32TimerOverFlowCounter = 0;
	Local_u32TimerOverFlowCounter++;
	Local_u32PWMCounter_us++;
	
	if(Local_u32TimerOverFlowCounter == MTIMER0_u32OverFlowNo)
	{
		MTIMER0_TIMER0OverFlowCallBackPointer();
		Local_u32TimerOverFlowCounter = 0;
		MTIMER0_TCNT0 =   MTIMER0_u8TCNT0Preload;
	}
	if (Local_u32PWMCounter_us == MTIMER0_u32SWPWMOnTime)
	{
		MTIMER0_SWPWMCallBackPointer();
	}
	else if (Local_u32PWMCounter_us == MTIMER0_u32SWPWMTime)
	{
		MTIMER0_SWPWMCallBackPointer();
		Local_u32PWMCounter_us = 0;
	}
}
void MTIMER0_voidOverFlowCallBack(void(*Copy_Ptr)(void))
{
	MTIMER0_TIMER0OverFlowCallBackPointer = Copy_Ptr;
}
#endif
//--------------------------------------------------------------------------------------------

#if MTIMER0_MODE == MTIMER0_CTC_MODE
//OCR0 Interrupt
void __vector_10(void)
{
	static u8   Local_u8TimerCounter_us = 0;
	static u32  Local_u32TimerCounter_ms = 0;
	//calculate 1ms
	if(Local_u8TimerCounter_us == 10)
	{
		Local_u8TimerCounter_us = 0;
		Local_u32TimerCounter_ms++;
	}
}
#endif

//--------------------------------------------------------------------------------------------
#if (MTIMER0_MODE == MTIMER0_FAST_PWM_MODE) 
void MTIMER0_voidFastPWM(u8 Copy_u8DutyCycle,u8 Copy_u8PWMMode)
{
	MTIMER0_OCR0 = (Copy_u8DutyCycle*MTIMER0_REG_CAPACITY)/100;
	//Choose OC0 Mode 
	MTIMER0_u8TCCR0Value &= 0b11001111;          //mask COM00,COM01 bits with zeros
	MTIMER0_u8TCCR0Value |= (Copy_u8PWMMode<<4) ; //Put mode in COM00,COM01 bits
	MTIMER0_voidStartTimer();
}
#endif
#if MTIMER0_MODE == MTIMER0_PHASE_CORCT_MODE
void MTIMER0_voidPhaseCorrectPWM(u8 Copy_u8DutyCycle,u8 Copy_u8PWMMode)
{
	MTIMER0_OCR0 = (Copy_u8DutyCycle*(MTIMER0_REG_CAPACITY-1))/100;
	//Choose OC0 Mode
	MTIMER0_u8TCCR0Value &= 0b11001111;          //mask COM00,COM01 bits with zeros
	MTIMER0_u8TCCR0Value |= (Copy_u8PWMMode<<4) ; //Put mode in COM00,COM01 bits
	MTIMER0_voidStartTimer();
}
#endif
//---------------------------------------------------------------------------------------------
void MTIMER0_voidStartTimer(void)
{
	MTIMER0_TCCR0 = MTIMER0_u8TCCR0Value;          //Start TCNT0 Reg counting by loading it's value 
}
void MTIMER0_voidStopTimer(void)
{
	MTIMER0_TCCR0 = MTIMER0_u8TCCR0Value & (0xf8); //Stop TCNT0 Reg counting by loading zeros in CS00,CS01,CS02
}



