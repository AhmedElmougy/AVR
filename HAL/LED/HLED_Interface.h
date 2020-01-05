/* HLED_Inerface.h file:
 * This file includes lib definitions for led module for Atmega32 DIO modules
 * created by Ahmed Elmogy Embedded SW Engineer 
 * Date : 23/6/2019
 * Git account: https://github.com/AhmedElmougy
 * mail: ahmed.m.elmogy@gmil.com 
 */

#ifndef __HLED_Interface_h__ 
#define __HLED_Interface_h__



#define ON     MDIO_ON
#define OFF    MDIO_OFF

/*
 * Initialize one LED on specific port and bit
 * Arguments : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *             bit     : takes only MDIO_Px0,MDIO_Px1,MDIO_Px2,MDIO_Px3,MDIO_Px4,MDIO_Px5,MDIO_Px6,MDIO_Px7 ex: MDIO_PA0,MDIO_PB6,MDIO_PD2....
 * return    : void
*/
void HLED_voidInitOneLed(u8 Copy_u8Reg,u8 Copy_u8Bit);

/*
 * Initialize string of 8 LEDs on specific port
 * Arguments : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 * return    : void
*/
void HLED_voidInitLedString(u8 Copy_u8Reg);

/*
 * Turn one Led on and off 
 * Arguments : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *             bit     : takes only MDIO_Px0,MDIO_Px1,MDIO_Px2,MDIO_Px3,MDIO_Px4,MDIO_Px5,MDIO_Px6,MDIO_Px7 ex: MDIO_PA0,MDIO_PB6,MDIO_PD2....
 *             State   : takes only ON OFF
 * return    : void
*/
void HLED_voidLedOnOff(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8State);

/*
 * Turn string of 8 Leds on and off 
 * Arguments : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *             Value   : takes only ON OFF or custom value
 * return    : void
*/
void HLED_voidLedStringOnOff(u8 Copy_u8Reg,u8 Copy_u8Value);

#endif
