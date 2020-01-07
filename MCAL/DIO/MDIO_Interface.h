/*
 * File        : MDIO_Interface.h
 * Description : This interface file includes DIO Driver prototypes and difinitions for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 23/6/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */


#ifndef __MDIO_Interface_H__
#define __MDIO_Interface_H__


/*==============================================================================================================================================
 * macros used with I/O
 *==============================================================================================================================================*/

#define MDIO_EN_PULL_UP_RES     1
#define MDIO_DIS_PULL_UP_RES    0

#define MDIO_OUTPUT  1
#define MDIO_INPUT   0
#define MDIO_HIGH    1
#define MDIO_LOW     0
#define MDIO_ON      1
#define MDIO_OFF     0


/*define ports*/
#define MDIO_PORTA   1
#define MDIO_PORTB   2
#define MDIO_PORTC   3
#define MDIO_PORTD   4

/*PORTA PINS*/
#define MDIO_PA0     0
#define MDIO_PA1     1
#define MDIO_PA2     2
#define MDIO_PA3     3
#define MDIO_PA4     4
#define MDIO_PA5     5
#define MDIO_PA6     6
#define MDIO_PA7     7

/*PORTB PINS*/
#define MDIO_PB0     0
#define MDIO_PB1     1
#define MDIO_PB2     2
#define MDIO_PB3     3
#define MDIO_PB4     4
#define MDIO_PB5     5
#define MDIO_PB6     6
#define MDIO_PB7     7

/*PORTC PINS*/
#define MDIO_PC0     0
#define MDIO_PC1     1
#define MDIO_PC2     2
#define MDIO_PC3     3
#define MDIO_PC4     4
#define MDIO_PC5     5
#define MDIO_PC6     6
#define MDIO_PC7     7

/*PORTD PINS*/
#define MDIO_PD0     0
#define MDIO_PD1     1
#define MDIO_PD2     2
#define MDIO_PD3     3
#define MDIO_PD4     4
#define MDIO_PD5     5
#define MDIO_PD6     6
#define MDIO_PD7     7

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
u8 MDIO_u8SetDirectionReg(u8 Copy_u8Reg,u8 Copy_u8Status);

/*
 * Prototype   : u8 MDIO_u8SetDirectionBit(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8Status);
 * Description : Set direction of one bit of the register
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               bit     : takes only MDIO_Px0,MDIO_Px1,MDIO_Px2,MDIO_Px3,MDIO_Px4,MDIO_Px5,MDIO_Px6,MDIO_Px7 ex: MDIO_PA0,MDIO_PB6,MDIO_PD2....
 * 			     Status  : takes only INPUT,OUTPUT 
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range, (3) means status value out of range
 */
u8 MDIO_u8SetDirectionBit(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8Status);

/*==============================================================================================================================================
 * Write modules
 *==============================================================================================================================================*/

/*
 * Prototype   : u8 MDIO_u8WriteReg(u8 Copy_u8Reg,u8 Copy_u8Value);
 * Description : write o/p to  the whole register
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD 
 *               Value  : takes HIGH sets whole reg high,LOW sets whole reg low, or Custom -(0-255)values- PORTx values
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 MDIO_u8WriteReg(u8 Copy_u8Reg,u8 Copy_u8Value);

/*
 * Prototype   : u8 MDIO_u8WriteBit(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8Value);
 * Description : Write value of one bit of the register
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               bit     : takes only MDIO_Px0,MDIO_Px1,MDIO_Px2,MDIO_Px3,MDIO_Px4,MDIO_Px5,MDIO_Px6,MDIO_Px7 ex: MDIO_PA0,MDIO_PB6,MDIO_PD2....
 * 			     Status  : takes only HIGH,LOW 
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range, (3) means Bit value out of range
 */
u8 MDIO_u8WriteBit(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8Value);

/*
 * Prototype   : u8 MDIO_u8ToggleReg(u8 Copy_u8Reg);
 * Description : Toggles pin values of the whole register
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD 
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument
 */
u8 MDIO_u8ToggleReg(u8 Copy_u8Reg);

/*
 * Prototype   : u8 MDIO_u8ToggleBit(u8 Copy_u8Reg,u8 Copy_u8Bit);
 * Description : Toggle pin value of one bit of the register
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               Bit     : takes only MDIO_Px0,MDIO_Px1,MDIO_Px2,MDIO_Px3,MDIO_Px4,MDIO_Px5,MDIO_Px6,MDIO_Px7 ex: MDIO_PA0,MDIO_PB6,MDIO_PD2....
 * return      : u8 number used for error handling
 *			     (0) means no error,(1) means Undefined PORT Argument, (2) means Bit number out of range
 */
u8 MDIO_u8ToggleBit(u8 Copy_u8Reg,u8 Copy_u8Bit);


/*==============================================================================================================================================
 * Read modules
 *==============================================================================================================================================
 */

/*
 * Prototype   : u8 MDIO_u8ReadReg(u8 Copy_u8Reg);
 * Description : Read i/p of the whole register
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD 
 * return      : Register reading of type u8, it will always return 240(0xAA)(0b10101010) in case of Undefined Port error 
 *               whatever the actual reading is
 */
u8 MDIO_u8ReadReg(u8 Copy_u8Reg);

/*
 * Prototype   : u8 MDIO_u8ReadBit(u8 Copy_u8Reg,u8 Copy_u8Bit);
 * Description : Read pin value of one bit of the register
 * Arguments   : Register: takes only MDIO_PORTA,MDIO_PORTB,MDIO_PORTC,MDIO_PORTD
 *               Bit     : takes only MDIO_Px0,MDIO_Px1,MDIO_Px2,MDIO_Px3,MDIO_Px4,MDIO_Px5,MDIO_Px6,MDIO_Px7 ex: MDIO_PA0,MDIO_PB6,MDIO_PD2....
 * return      : u8 actual reading (0 or 1) or number used for error handling
 *			     (2) means Undefined PORT Argument, (3) means Bit number out of range
 */
u8 MDIO_u8ReadBit(u8 Copy_u8Reg,u8 Copy_u8Bit);

 
/*==============================================================================================================================================
 * enable pullup res modules
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
u8 MDIO_u8ConfigPullupReg(u8 Copy_u8Reg,u8 Copy_u8PullUpResStatus);

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
u8 MDIO_u8ConfigPullupBit(u8 Copy_u8Reg,u8 Copy_u8Bit,u8 Copy_u8PullUpResStatus);

#endif
