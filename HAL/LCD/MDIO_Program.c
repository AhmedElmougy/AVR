/*
 * File        : MDIO_Program.c
 * Description : This file includes DIO Driver implementations for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 23/6/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#include "LSTD_Types.h"
#include "LUTILS.h"
#include "MDIO_Private.h"
#include "MDIO_Interface.h"


/*==============================================================================================================================================
 * Direction modules
 *==============================================================================================================================================*/

/*
 * Prototype   : u8 MDIO_u8SetDirectionReg(u8 Copy_u8Reg,u8 Copy_u8Status);
 * Description : Set direction of the whole register
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD 
 *               Status  : takes INPUT sets whole reg i/p,OUTPUT sets whole reg o/p, or Custom -(0-255)values- DDRx values
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 MDIO_u8SetDirectionReg(u8 Copy_u8Reg,u8 Copy_u8Status)
{
	u8 Local_u8DirectionValue = 0;

	/*value type check condition*/
	if (Copy_u8Status==MDIO_OUTPUT)
	{
		/*set the whole port o/p*/
		Local_u8DirectionValue = 0xff;
	}
	else if(Copy_u8Status==MDIO_INPUT)
	{
		/*set the whole port i/p*/
		Local_u8DirectionValue = 0x00;
	}
	else
	{
		/*set custom direction configuration*/
		Local_u8DirectionValue = Copy_u8Status;

	}/*end of value type check condition*/

	/*register switch case*/
	switch (Copy_u8Reg)
	{
		/*Set DDR register value with inputed status value (Local_u8DirectionValue)*/
		case MDIO_PORTA : { MDIO_DDRA = Local_u8DirectionValue; return 0; } break;
		case MDIO_PORTB : { MDIO_DDRB = Local_u8DirectionValue; return 0; } break;
		case MDIO_PORTC : { MDIO_DDRC = Local_u8DirectionValue; return 0; } break;
		case MDIO_PORTD : { MDIO_DDRD = Local_u8DirectionValue; return 0; } break;
		default         : return 1; /*error Undefined PORT*/
			
	}/*end of register switch case*/

}/*end of MDIO_u8SetDirectionReg()*/

/*
 * Prototype   : u8 MDIO_u8SetDirectionBit(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8Status);
 * Description : Set direction of one bit of the register
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               bit     : takes only MDIO_Px0,MDIO_Px1,MDIO_Px2,MDIO_Px3,MDIO_Px4,MDIO_Px5,MDIO_Px6,MDIO_Px7 ex: MDIO_PA0,MDIO_PB6,MDIO_PD2....
 * 			     Status  : takes only INPUT,OUTPUT 
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range, (3) means status value out of range
 */
u8 MDIO_u8SetDirectionBit(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8Status)
{
	/*bit number check condition*/
	if( (Copy_u8Bit >= 0) && (Copy_u8Bit < 8) )
	{
		/*Status value check condition*/
		if ( (0 == Copy_u8Status) || (1 == Copy_u8Status) )
		{
			/*register switch case*/
			switch (Copy_u8Reg)
			{
				/*set bit corresponding DDR reg value with status value*/
				case MDIO_PORTA : {MDIO_DDRA = L_UTILS_SET_BIT_VALUE(MDIO_DDRA,Copy_u8Bit,Copy_u8Status); return 0;} break;
				case MDIO_PORTB : {MDIO_DDRB = L_UTILS_SET_BIT_VALUE(MDIO_DDRB,Copy_u8Bit,Copy_u8Status); return 0;} break;
				case MDIO_PORTC : {MDIO_DDRC = L_UTILS_SET_BIT_VALUE(MDIO_DDRC,Copy_u8Bit,Copy_u8Status); return 0;} break;
				case MDIO_PORTD : {MDIO_DDRD = L_UTILS_SET_BIT_VALUE(MDIO_DDRD,Copy_u8Bit,Copy_u8Status); return 0;} break;
				default         : return 1;   /*error Undefined Port*/
				
			}/*end of Register switch case*/

		} 
		else
		{
			/*Report Status value out of range error*/
			return 3;  
			
		}/*end of Status value check condition*/
	}
	else
	{
		/*Report Bit number out of range error*/
		return 2;

	}/*end of bit number check condition*/ 

}/*end of MDIO_u8SetDirectionBit()*/

/*==============================================================================================================================================
 * Write modules
 *==============================================================================================================================================*/

/*
 * Prototype   : u8 MDIO_u8WriteReg(u8 Copy_u8Reg,u8 Copy_u8Value);
 * Description : write o/p to  the whole register
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD 
 *               Value   : takes MDIO_HIGH sets whole reg high,MDIO_LOW sets whole reg low, or Custom -(0-255)values- PORTx values
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument 
 */ 
u8 MDIO_u8WriteReg(u8 Copy_u8Reg,u8 Copy_u8Value)
{
	u8 Local_u8RegValue = 0;
	
	/*value type check condition*/
	if (Copy_u8Value==MDIO_HIGH)
	{
		/*set the whle reg hight*/
		Local_u8RegValue = 0xff;
	}
	else if(Copy_u8Value==MDIO_LOW)
	{
		/*set the whle reg low*/
		Local_u8RegValue = 0x00;
	}
	else
	{
		/*set reg with custom value*/
		Local_u8RegValue = Copy_u8Value;

	}/*end of value type check condition*/

	/*register switch case*/
	switch (Copy_u8Reg)
	{
		/*Set PORTx register value with inputed Reg value (Local_u8RegValue)*/
		case MDIO_PORTA : {DIO_PORTA = Local_u8RegValue; return 0;}  break;
		case MDIO_PORTB : {DIO_PORTB = Local_u8RegValue; return 0;}  break;
		case MDIO_PORTC : {DIO_PORTC = Local_u8RegValue; return 0;}  break;
		case MDIO_PORTD : {DIO_PORTD = Local_u8RegValue; return 0;}  break;
		default         : return 1;   /*error Undefined Port*/

	}/*end of register switch case*/

}/*end of MDIO_u8WriteReg()*/


/*
 * Prototype   : u8 MDIO_u8WriteBit(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8Value);
 * Description : Write value of one bit of the register
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               bit     : takes only MDIO_Px0,MDIO_Px1,MDIO_Px2,MDIO_Px3,MDIO_Px4,MDIO_Px5,MDIO_Px6,MDIO_Px7 ex: MDIO_PA0,MDIO_PB6,MDIO_PD2....
 * 			     Status  : takes only HIGH,LOW 
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range, (3) means Bit value out of range
 */
u8 MDIO_u8WriteBit(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8Value)
{

	/*bit number check condition*/
	if( (Copy_u8Bit >= 0) && (Copy_u8Bit < 8) )
	{
		/*Register value check condition*/
		if ((0 == Copy_u8Value) || (1 == Copy_u8Value))
		{
			/*register switch case*/
			switch (Copy_u8Reg)
			{
				/*set bit corresponding PORTx reg value with inputed bit value(Copy_u8Value)*/
				case MDIO_PORTA : {L_UTILS_SET_BIT_VALUE(DIO_PORTA,Copy_u8Bit,Copy_u8Value); return 0;} break;
				case MDIO_PORTB : {L_UTILS_SET_BIT_VALUE(DIO_PORTB,Copy_u8Bit,Copy_u8Value); return 0;} break;
				case MDIO_PORTC : {L_UTILS_SET_BIT_VALUE(DIO_PORTC,Copy_u8Bit,Copy_u8Value); return 0;} break;
				case MDIO_PORTD : {L_UTILS_SET_BIT_VALUE(DIO_PORTD,Copy_u8Bit,Copy_u8Value); return 0;} break;
				default         : return 1; /*error Undefined Port*/
				
			}/*end of Register switch case*/	
		} 
		else
		{
			/*Report Register value out of range error*/
			return 3; 
			
		}/*end of Register value check condition*/
	}
	else
	{
		/*Report Bit number out of range error*/
		return 2; 

	}/*end of bit number check condition*/

}/*end of MDIO_u8WriteBit()*/



/*
 * Prototype   : u8 MDIO_u8ToggleReg(u8 Copy_u8Reg);
 * Description : Toggles pin values of the whole register
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD 
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */ 
u8 MDIO_u8ToggleReg(u8 Copy_u8Reg)
{
	/*register switch case*/
	switch (Copy_u8Reg)
	{
		/*Toggle PORTx reg value*/
		case MDIO_PORTA : {DIO_PORTA ^= 0xff; return 0;} break;
		case MDIO_PORTB : {DIO_PORTB ^= 0xff; return 0;} break;
		case MDIO_PORTC : {DIO_PORTC ^= 0xff; return 0;} break;
		case MDIO_PORTD : {DIO_PORTD ^= 0xff; return 0;} break;
		default         : return 1;  /*error Undefined Port*/
	
	}/*end of Register switch case*/

}/*end of MDIO_u8ToggleReg()*/

/*
 * Prototype   : u8 MDIO_u8ToggleBit(u8 Copy_u8Reg,u8 Copy_u8Bit);
 * Description : Toggle pin value of one bit of the register
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               Bit     : takes only MDIO_Px0,MDIO_Px1,MDIO_Px2,MDIO_Px3,MDIO_Px4,MDIO_Px5,MDIO_Px6,MDIO_Px7 ex: MDIO_PA0,MDIO_PB6,MDIO_PD2....
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range
 */
u8 MDIO_u8ToggleBit(u8 Copy_u8Reg,u8 Copy_u8Bit)
{
	/*bit number check condition*/
	if( (Copy_u8Bit >= 0) && (Copy_u8Bit < 8) )
	{
		/*register switch case*/
		switch (Copy_u8Reg)
		{
			/*Toggle Chossen bit value in PORTx reg*/
			case MDIO_PORTA : {L_UTILS_TOGGLE_BIT(DIO_PORTA,Copy_u8Bit); return 0;} break;
			case MDIO_PORTB : {L_UTILS_TOGGLE_BIT(DIO_PORTB,Copy_u8Bit); return 0;} break;
			case MDIO_PORTC : {L_UTILS_TOGGLE_BIT(DIO_PORTC,Copy_u8Bit); return 0;} break;
			case MDIO_PORTD : {L_UTILS_TOGGLE_BIT(DIO_PORTD,Copy_u8Bit); return 0;} break;
			default         : return 1;  /*error Undefined Port*/
		
		}/*end of Register switch case*/
	}
	else
	{
		/*Report Bit number out of range error*/
		return 2; 

	}/*end of bit number check condition*/

}/*end of MDIO_u8ToggleBit()*/

/*==============================================================================================================================================
 * Read modules
 *==============================================================================================================================================*/

/*
 * Prototype   : u8 MDIO_u8ReadReg(u8 Copy_u8Reg);
 * Description : Read i/p of the whole register
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD 
 * return      : Register reading of type u8, it will always return 240(0xAA)(0b10101010) in case of Undefined Port error 
 *               whatever the actual reading is
 */ 
u8 MDIO_u8ReadReg(u8 Copy_u8Reg)
{	
	/*register switch case*/
	switch (Copy_u8Reg)
	{
		/*Read PINx reg value*/
		case MDIO_PORTA : return MDIO_PINA;  break;
		case MDIO_PORTB : return MDIO_PINB;  break;
		case MDIO_PORTC : return MDIO_PINC;  break;
		case MDIO_PORTD : return MDIO_PIND;  break;
		default         : return 170; /*error Undefined Port*/
	
	}/*end of Register switch case*/

}/*end of MDIO_u8ReadReg()*/

/*
 * Prototype   : u8 MDIO_u8ReadBit(u8 Copy_u8Reg,u8 Copy_u8Bit);
 * Description : Read pin value of one bit of the register
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               Bit     : takes only MDIO_Px0,MDIO_Px1,MDIO_Px2,MDIO_Px3,MDIO_Px4,MDIO_Px5,MDIO_Px6,MDIO_Px7 ex: MDIO_PA0,MDIO_PB6,MDIO_PD2....
 * return      : u8 actual reading (0 or 1) or number used for error handling
 *			     (2) means Undefined PORT Argument, (3) means Bit number out of range
 */
u8 MDIO_u8ReadBit(u8 Copy_u8Reg,u8 Copy_u8Bit)
{
	/*bit number check condition*/
	if( (Copy_u8Bit >= 0) && (Copy_u8Bit < 8) )
	{
		/*register switch case*/
		switch (Copy_u8Reg)
		{
			/*Read chossen bit in PINx reg*/
			case MDIO_PORTA : return L_UTILS_GET_BIT(MDIO_PINA,Copy_u8Bit);  break;
			case MDIO_PORTB : return L_UTILS_GET_BIT(MDIO_PINB,Copy_u8Bit);  break;
			case MDIO_PORTC : return L_UTILS_GET_BIT(MDIO_PINC,Copy_u8Bit);  break;
			case MDIO_PORTD : return L_UTILS_GET_BIT(MDIO_PIND,Copy_u8Bit);  break;
			default         : return 2; /*error Undefined Port*/
		
		}/*end of Register switch case*/
	}
	else
	{
		/*Report Bit number out of range error*/
		return 3;  

	}/*end of bit number check condition*/

}/*end of MDIO_u8ReadBit()*/

/*==============================================================================================================================================
 * Configure pullup res modules
 *==============================================================================================================================================*/

/*
 * Prototype   : u8 MDIO_u8ConfigPullupReg(u8 Copy_u8Reg,u8 Copy_u8PullUpResStatus);
 * Description : Configure pullup Res status for the whole register
 * Arguments   : Register    : takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               pull up res : takes only MDIO_EN_PULL_UP_RES (will enable it for the whole reg) or 
 *                             MDIO_DIS_PULL_UP_RES (will disable it for the whole reg) or a custom value
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 MDIO_u8ConfigPullupReg(u8 Copy_u8Reg,u8 Copy_u8PullUpResStatus)
{

	u8 Local_u8PullUpResStatus = 0;

	/*Pull up res status check condition*/
	if ( MDIO_EN_PULL_UP_RES == Copy_u8PullUpResStatus)
	{
		/*Enable pull up res for the whole reg*/
		Local_u8PullUpResStatus = 0xff;  		
	}
	else if(MDIO_DIS_PULL_UP_RES == Copy_u8PullUpResStatus)
	{
		/*Disable pull up res for the whole reg*/
		Local_u8PullUpResStatus = 0x00;
	}
	else
	{
		/*Set custom configuration value for the reg*/
		Local_u8PullUpResStatus = Copy_u8PullUpResStatus;

	}/*end of Pull up res status check condition*/

	/*register switch case*/
	switch (Copy_u8Reg)
	{
		/*Set PORTx reg value with choosen pull up res config (Local_u8PullUpResStatus)*/
		case MDIO_PORTA : {DIO_PORTA = Local_u8PullUpResStatus; return 0;}  break;
		case MDIO_PORTB : {DIO_PORTB = Local_u8PullUpResStatus; return 0;}  break;
		case MDIO_PORTC : {DIO_PORTC = Local_u8PullUpResStatus; return 0;}  break;
		case MDIO_PORTD : {DIO_PORTD = Local_u8PullUpResStatus; return 0;}  break;
		default         : return 1; /*error Undefined Port*/
			
	}/*end of register switch case*/

}/*end of MDIO_u8ConfigPullupReg()*/

/*
 * Prototype   : u8 MDIO_u8ConfigPullupBit(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8PullUpResStatus);
 * Description : Configure pullup Res status for on a given bit and port 
 * Arguments   : Register    : takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD 
 *               Bit         : takes only MDIO_Px0,MDIO_Px1,MDIO_Px2,MDIO_Px3,MDIO_Px4,MDIO_Px5,MDIO_Px6,MDIO_Px7 ex: MDIO_PA0,MDIO_PD2....
 *               pull up res : takes only MDIO_EN_PULL_UP_RES or MDIO_DIS_PULL_UP_RES
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range, (3) means pull up 
 *               resistor status value out of range
 */
u8 MDIO_u8ConfigPullupBit(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8PullUpResStatus)
{
	/*Pull up res status check condition*/
	if( (MDIO_EN_PULL_UP_RES == Copy_u8PullUpResStatus) || (MDIO_DIS_PULL_UP_RES == Copy_u8PullUpResStatus) )
	{
		/*bit number check condition*/
		if( (Copy_u8Bit >= 0) && (Copy_u8Bit < 8) )
		{
			/*register switch case*/
			switch (Copy_u8Reg)
			{
				/*Configure bit value in PORTx reg with choosen pull up res status(Copy_u8PullUpResStatus)*/
				case MDIO_PORTA : {L_UTILS_SET_BIT_VALUE(DIO_PORTA,Copy_u8Bit,Copy_u8PullUpResStatus); return 0;} break;
				case MDIO_PORTB : {L_UTILS_SET_BIT_VALUE(DIO_PORTB,Copy_u8Bit,Copy_u8PullUpResStatus); return 0;} break;
				case MDIO_PORTC : {L_UTILS_SET_BIT_VALUE(DIO_PORTC,Copy_u8Bit,Copy_u8PullUpResStatus); return 0;} break;
				case MDIO_PORTD : {L_UTILS_SET_BIT_VALUE(DIO_PORTD,Copy_u8Bit,Copy_u8PullUpResStatus); return 0;} break;
				default         : return 1;  /*error Undefined Port*/
		
			}/*end of Register switch case*/
		}
		else
		{
			/*Report Bit number out of range error*/
			return 2; 

		}/*end of bit number check condition*/

	}
	else
	{
		/*Report Pull up res status value out of range error*/
		return 3;

	}/*end of Pull up res status check condition*/
	
}/*end of MDIO_u8ConfigPullupBit()*/