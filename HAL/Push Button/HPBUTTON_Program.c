/*
 * File        : HPBUTTON_Program.c
 * Description : This file includes push button Driver implementations for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 23/6/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#include "L_STD_Types.h"
#include "L_UTILS.h"
#include "MDIO_Interface.h"
#include "HPBUTTON_Private.h"
#include "HPBUTTON_Interface.h"



/* 
 * Prototype   : u8 HPBUTTON_u8InitOneButton(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8PullUpResStatus);
 * Description : Initialize one push button on specific port and bit with optional pull up resistor
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               bit     : takes only MDIO_Px0,MDIO_Px1,MDIO_Px2,MDIO_Px3,MDIO_Px4,MDIO_Px5,MDIO_Px6,MDIO_Px7 ex: MDIO_PA0,MDIO_PB6,MDIO_PD2....
 *               Pull up : takes only HPBUTTON_ENABLE_PULL_UP_RES or HPBUTTON_DISABLE_PULL_UP_RES 
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range, (3) means pull up 
 *               resistor status value out of range  
 */
u8 HPBUTTON_u8InitOneButton(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8PullUpResStatus)
{
	/*set desired bit as input*/
	MDIO_u8SetDirectionBit(Copy_u8Reg,Copy_u8Bit,MDIO_INPUT);
	/*Configure bit pull up resistor status and return error value*/
	return MDIO_u8ConfigPullupBit(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8PullUpResStatus);

}/*end of HPBUTTON_u8InitOneButton()*/

/*
 * Prototype   : u8 HPBUTTON_u8InitStringOfButtons(u8 Copy_u8Reg,u8 Copy_u8PullUpResStatus);
 * Description : Initialize string of 8 push buttons on specific port with optional pull up resistor
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD 
 *               pull up res : takes only MDIO_EN_PULL_UP_RES (will enable it for the whole reg) or 
 *                             MDIO_DIS_PULL_UP_RES (will disable it for the whole reg) or a custom value 
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument  
 */
u8 HPBUTTON_u8InitStringOfButtons(u8 Copy_u8Reg,u8 Copy_u8PullUpResStatus)
{
	/*set desired Reg as input*/
	MDIO_u8SetDirectionReg(Copy_u8Reg,MDIO_INPUT);
	/*Configure Reg pull up resistor status and return error value*/
	return MDIO_u8ConfigPullupReg(u8 Copy_u8Reg,u8 Copy_u8PullUpResStatus);

}/*end of HPBUTTON_u8InitStringOfButtons()*/

/*
 * Prototype   : u8 HPBUTTON_u8ReadOneButton(u8 Copy_u8Reg,u8 Copy_u8Bit);
 * Description : Read one push button value in a specific port and bit
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               Bit     : takes only MDIO_Px0,MDIO_Px1,MDIO_Px2,MDIO_Px3,MDIO_Px4,MDIO_Px5,MDIO_Px6,MDIO_Px7 ex: MDIO_PA0,MDIO_PB6,MDIO_PD2....
 * return      : u8 actual reading (0 or 1) or number used for error handling
 *			     (2) means Undefined PORT Argument, (3) means Bit number out of range
 */
u8 HPBUTTON_u8ReadOneButton(u8 Copy_u8Reg,u8 Copy_u8Bit)
{
	/*return desired bit value or error value if there is one*/
	return MDIO_u8ReadBit(Copy_u8Reg,Copy_u8Bit);

}/*end of HPBUTTON_u8ReadOneButton()*/

/*
 * Prototype   : u8 HPBUTTON_u8ReadStringOfButtons(u8 Copy_u8Reg);
 * Description : Read String of 8 push buttons value in a given port
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD 
 * return      : Register reading of type u8, and it will always return 240(0xAA)(0b10101010) in case of Undefined Port error 
 *               whatever the actual reading is
 */
u8 HPBUTTON_u8ReadStringOfButtons(u8 Copy_u8Reg)
{
	/*return desired Reg value or error value if there is one*/
	return MDIO_u8ReadReg(Copy_u8Reg,Copy_u8Bit);

}/*end of HPBUTTON_u8ReadStringOfButtons()*/