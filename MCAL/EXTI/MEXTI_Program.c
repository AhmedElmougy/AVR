#include "LSTD_Types.h"
#include "LUTILS.h"
#include "MEXTI_Private.h"
#include "MEXTI_Interface.h"

//Pointers to functions used in function callback
void (*PF1) (void); //pointer to function for INT0
void (*PF2) (void); //pointer to function for INT1
void (*PF3) (void); //pointer to function for INT2


void MEXTI_EN(u8 INT,u8 MODE)    //Enable specific interrupt
{
	//Enable global interrupt
	SET_BIT(MEXTI_SREG,MEXTI_SREG_I); //enable bit I in SREG REG
	//Enable interrupt
	SET_BIT(MEXTI_GICR,INT); //enable bit INT in GICR REG (INT0 , INT1 ,INT2)
	//Choose mode
	if (INT==MEXTI_INT0)
	{
		
		if (MODE==MEXTI_LOW_SGNL)
		{
			CLEAR_BIT(MEXTI_MCUCR,MEXTI_ISC00);  //Set bit ISC00 0 in MCUCR REG
 			CLEAR_BIT(MEXTI_MCUCR,MEXTI_ISC01);  //Set bit ISC01 0 in MCUCR REG
		}
		else if(MODE==MEXTI_LOG_CHNG)
		{
			SET_BIT(MEXTI_MCUCR,MEXTI_ISC00);  //Set bit ISC00 0 in MCUCR REG
			CLEAR_BIT(MEXTI_MCUCR,MEXTI_ISC01);  //Set bit ISC01 0 in MCUCR REG
		}
		else if(MODE==MEXTI_FAL_EDGE)
		{
			CLEAR_BIT(MEXTI_MCUCR,MEXTI_ISC00);  //Set bit ISC00 0 in MCUCR REG
			SET_BIT(MEXTI_MCUCR,MEXTI_ISC01);  //Set bit ISC01 0 in MCUCR REG
		}
		else if(MODE==MEXTI_RAIS_EDGE)
		{
			SET_BIT(MEXTI_MCUCR,MEXTI_ISC00);  //Set bit ISC00 0 in MCUCR REG
			SET_BIT(MEXTI_MCUCR,MEXTI_ISC01);  //Set bit ISC01 0 in MCUCR REG
		}
	} 
	else if (INT==MEXTI_INT1)
	{
		
		if (MODE==MEXTI_LOW_SGNL)
		{
			CLEAR_BIT(MEXTI_MCUCR,MEXTI_ISC10);  //Set bit ISC00 0 in MCUCR REG
			CLEAR_BIT(MEXTI_MCUCR,MEXTI_ISC11);  //Set bit ISC01 0 in MCUCR REG
		}
		else if(MODE==MEXTI_LOG_CHNG)
		{
			SET_BIT(MEXTI_MCUCR,MEXTI_ISC10);  //Set bit ISC00 0 in MCUCR REG
			CLEAR_BIT(MEXTI_MCUCR,MEXTI_ISC11);  //Set bit ISC01 0 in MCUCR REG
		}
		else if(MODE==MEXTI_FAL_EDGE)
		{
			CLEAR_BIT(MEXTI_MCUCR,MEXTI_ISC10);  //Set bit ISC00 0 in MCUCR REG
			SET_BIT(MEXTI_MCUCR,MEXTI_ISC11);  //Set bit ISC01 0 in MCUCR REG
		}
		else if(MODE==MEXTI_RAIS_EDGE)
		{
			SET_BIT(MEXTI_MCUCR,MEXTI_ISC10);  //Set bit ISC00 0 in MCUCR REG
			SET_BIT(MEXTI_MCUCR,MEXTI_ISC11);  //Set bit ISC01 0 in MCUCR REG
		}
	}
	else if (INT==MEXTI_INT2)
	{
		
		if(MODE==MEXTI_FAL_EDGE)
		{
			CLEAR_BIT(MEXTI_MCUCSR,MEXTI_ISC2);  //Set bit ISC2 0 in MCUCSR REG
		}
		else if(MODE==MEXTI_RAIS_EDGE)
		{
			SET_BIT(MEXTI_MCUCSR,MEXTI_ISC2); //Set bit ISC2 1 in MCUCSR REG
		}
		else
		{
			CLEAR_BIT(MEXTI_MCUCSR,MEXTI_ISC2);  //Set bit ISC2 0 in MCUCSR REG
		}
	}
}


void MEXTI_DISBL(u8 INT) //Disable specific interrupt
{
	//Disable global interrupt
	CLEAR_BIT(MEXTI_SREG,MEXTI_SREG); //Disable bit I in SREG REG
	//Disable interrupt
	CLEAR_BIT(MEXTI_GICR,INT); //Disable bit INT in GICR REG (INT0 , INT1 ,INT2)
}

u8 MEXTI_ChechIntFlag(u8 INT)    //check if  specific interrupt flag is up
{
	if(INT==MEXTI_INT0)
	{
		if (GET_BIT(MEXTI_GIFR,MEXTI_INTF0)==HIGH) 
		{
			return 1 ;
		} 
		else
		{
			return 0;
		}
	} 
	else if(INT==MEXTI_INT1)
	{
		if (GET_BIT(MEXTI_GIFR,MEXTI_INTF1)==HIGH)
		{
			return 1 ;
		}
		else
		{
			return 0;
		}
	}
	else if(INT==MEXTI_INT2)
	{
		if (CLEAR_BIT(MEXTI_GIFR,MEXTI_INTF2)==HIGH)
		{
			return 1 ;
		}
		else
		{
			return 0;
		}
	}
}

//Interrupt functions call back for INT0,INT1,INT2
void MEXTI_FnCallBack_INT0(void(*ptr)(void))
{
	PF1 = ptr;
}
void MEXTI_FnCallBack_INT1(void(*ptr)(void))
{
	PF2 = ptr;
}
void MEXTI_FnCallBack_INT2(void(*ptr)(void))
{
	PF3 = ptr;
}

//actual interrupt routines with pointers to functions existing in main c file  
//INT0 
void __vector_1 (void) 
{
	PF1();
}
//INT1
void __vector_2(void)
{
	PF2();
}
//INT2
void __vector_3(void)
{
	PF3();	
}