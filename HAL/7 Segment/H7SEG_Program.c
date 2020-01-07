/*
 * File        : H7SEG_Program.c
 * Description : This interface file includes 7SEG Driver implementations for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 23/6/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#include "LSTD_Types.h"
#include "LUTILS.h"
#include "HLED_Interface.h"
#include "H7SEG_Private.h"
#include "H7SEG_Interface.h"


/*
 * Prototype   : u8 H7SEG_u8Init(u8 Copy_u8Reg);
 * Description : Initialize one 7-Segment of 8 LEDs on specific port
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 H7SEG_u8Init(u8 Copy_u8Reg)
{
	/*initialize 7-segment led string at desired port and return error value*/
	return HLED_u8InitLedString(Copy_u8Reg);

}/*end of H7SEG_u8Init()*/


/*
 * Prototype   : u8 H7SEG_u8DisplayNumber(u8 Copy_u8Reg,u8 Copy_u8DisblayNumber)
 * Description : Display a number on a given 7-segment 
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               Number  : takes only from 0 to 9 
 * return      : u8 number for error handling 
 *               (0) means no error, (1) means Undefined PORT, (2) means Display Number out of range error 
 */
u8 H7SEG_u8DisplayNumber(u8 Copy_u8Reg,u8 Copy_u8DisblayNumber)
{
	/*Disblay Number check condition*/
	if ( (Copy_u8DisblayNumber >= 0) || (Copy_u8DisblayNumber<10) )
	{
		/*Disblay number from seven segment array and return error value*/
		return HLED_u8LedStringOnOff(Copy_u8Reg,H7SEG_u8SevenSegArray[Copy_u8DisblayNumber]);
		
	} 
	else
	{
		/*Disblay Number out of range error*/
		return 2;  
		
	}/*End of Disblay Number check condition*/

}/*end of H7SEG_u8DisplayNumber()*/