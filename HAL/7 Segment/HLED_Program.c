/*
 * File        : HLED_Program.c
 * Description : This file includes LED Driver implementations for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 23/6/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */


#include "LSTD_Types.h"
#include "LUTILS.h"
#include "MDIO_Interface.h"
#include "HLED_Private.h"
#include "HLED_Interface.h"


/*
 * Prototype   : u8 HLED_u8InitOneLed(u8 Copy_u8Reg,u8 Copy_u8Bit);
 * Description : Initialize one LED on specific port and bit
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               bit     : takes only MDIO_Px0,MDIO_Px1,MDIO_Px2,MDIO_Px3,MDIO_Px4,MDIO_Px5,MDIO_Px6,MDIO_Px7 ex: MDIO_PA0,MDIO_PB6,MDIO_PD2....
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range
 */
u8 HLED_u8InitOneLed(u8 Copy_u8Reg,u8 Copy_u8Bit)
{
	/*initialize desired bit as putput and return error value*/
	return MDIO_u8SetDirectionBit(Copy_u8Reg,Copy_u8Bit,MDIO_OUTPUT);

}/*end of HLED_u8InitOneLed()*/

/*
 * Prototype   : u8 HLED_u8InitLedString(u8 Copy_u8Reg);
 * Description : Initialize string of 8 LEDs on specific port
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 HLED_u8InitLedString(u8 Copy_u8Reg)
{
	/*initialize desired port  as output and return error value*/
	return MDIO_u8SetDirectionReg(Copy_u8Reg,MDIO_OUTPUT);

}/*end of HLED_u8InitLedString*/

/*
 * Prototype   : u8 HLED_u8LedOnOff(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8State);
 * Description : Turn one Led on and off 
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               bit     : takes only MDIO_Px0,MDIO_Px1,MDIO_Px2,MDIO_Px3,MDIO_Px4,MDIO_Px5,MDIO_Px6,MDIO_Px7 ex: MDIO_PA0,MDIO_PB6,MDIO_PD2....
 *               State   : takes only ON OFF
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range, (3) means Bit value out of range
 */
u8 HLED_u8LedOnOff(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8State)
{
	/*write led value on desired bit and return error value*/
	return MDIO_u8WriteBit(Copy_u8Reg,Copy_u8Bit,Copy_u8State);

}/*end of HLED_u8LedOnOff*/

/*
 * Prototype   : u8 HLED_u8LedStringOnOff(u8 Copy_u8Reg,u8 Copy_u8Value);
 * Description : Turn string of 8 Leds on and off 
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               Value   : takes only ON OFF or custom value
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 HLED_u8LedStringOnOff(u8 Copy_u8Reg,u8 Copy_u8Value)
{
	/*write led values on Register and return error value*/
	return MDIO_u8WriteReg(Copy_u8Reg,Copy_u8Value);

}/*end of HLED_u8LedStringOnOff()*/