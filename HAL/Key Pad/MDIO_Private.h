/*
 * File        : MDIO_Private.h
 * Description : This File includes DIO Driver private macros and declarations for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 23/6/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */ 
 

#ifndef __MDIO_Private_H__
#define __MDIO_Private_H__

/*DIO Registers macros*/

/*PORTA*/ 
#define DIO_PORTA  (*(volatile u8 *)(0x3B)) /*PORTA Macro Definition*/
#define MDIO_DDRA  (*(volatile u8 *)(0x3A)) /*DDRA  Macro Definition*/
#define MDIO_PINA  (*(volatile u8 *)(0x39)) /*PINA  Macro Definition*/

/*PORTB*/
#define DIO_PORTB  (*(volatile u8 *)(0x38)) /*PORTB Macro Definition*/
#define MDIO_DDRB  (*(volatile u8 *)(0x37)) /*DDRB  Macro Definition*/
#define MDIO_PINB  (*(volatile u8 *)(0x36)) /*PINB  Macro Definition*/


/*PORTC*/
#define DIO_PORTC  (*(volatile u8 *)(0x35)) /*PORTC Macro Definition*/
#define MDIO_DDRC  (*(volatile u8 *)(0x34)) /*DDRC  Macro Definition*/
#define MDIO_PINC  (*(volatile u8 *)(0x33)) /*PINC  Macro Definition*/

/*PORTD*/
#define DIO_PORTD  (*(volatile u8 *)(0x32)) /*PORTD Macro Definition*/
#define MDIO_DDRD  (*(volatile u8 *)(0x31)) /*DDRD  Macro Definition*/
#define MDIO_PIND  (*(volatile u8 *)(0x30)) /*PIND  Macro Definition*/



#endif