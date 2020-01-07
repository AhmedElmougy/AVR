/*
 * File        : HLED_Interface.h
 * Description : This interface file includes LED Driver prototypes and declarations for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 23/6/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#ifndef __HLED_Interface_h__ 
#define __HLED_Interface_h__



#define HLED_ON     MDIO_ON
#define HLED_OFF    MDIO_OFF

/*
 * Prototype   : u8 HLED_u8InitOneLed(u8 Copy_u8Reg,u8 Copy_u8Bit);
 * Description : Initialize one LED on specific port and bit
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               bit     : takes only MDIO_Px0,MDIO_Px1,MDIO_Px2,MDIO_Px3,MDIO_Px4,MDIO_Px5,MDIO_Px6,MDIO_Px7 ex: MDIO_PA0,MDIO_PB6,MDIO_PD2....
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range
 */
u8 HLED_u8InitOneLed(u8 Copy_u8Reg,u8 Copy_u8Bit);

/*
 * Prototype   : u8 HLED_u8InitLedString(u8 Copy_u8Reg);
 * Description : Initialize string of 8 LEDs on specific port
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 HLED_u8InitLedString(u8 Copy_u8Reg);

/*
 * Prototype   : u8 HLED_u8LedOnOff(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8State);
 * Description : Turn one Led on and off 
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               bit     : takes only MDIO_Px0,MDIO_Px1,MDIO_Px2,MDIO_Px3,MDIO_Px4,MDIO_Px5,MDIO_Px6,MDIO_Px7 ex: MDIO_PA0,MDIO_PB6,MDIO_PD2....
 *               State   : takes only ON OFF
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range, (3) means Bit value out of range
 */
u8 HLED_u8LedOnOff(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8State);

/*
 * Prototype   : u8 HLED_u8LedStringOnOff(u8 Copy_u8Reg,u8 Copy_u8Value);
 * Description : Turn string of 8 Leds on and off 
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               Value   : takes only ON OFF or custom value
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 HLED_u8LedStringOnOff(u8 Copy_u8Reg,u8 Copy_u8Value);

#endif
