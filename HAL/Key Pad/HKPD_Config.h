/*
 * File        : HKPD_Config.h
 * Description : This file includes Keypad Driver Configuration parameters for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 9/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */


#ifndef __HKPD_Config_h__
#define __HKPD_Config_h__

/*pin connections on keypad register*/
/*choose keypad port*/
#define KEYPAD_PORT  MDIO_PORTB 
/*Column connections*/
#define C1 4
#define C2 5
#define C3 6
#define C4 7
/*Row connections*/
#define R1 3
#define R2 2
#define R3 1
#define R4 0

 
/*Keypad buttons assigned values array*/
const u8 KeyPadArr[4][4]={{ 1,  2,  3,  'A'},
					      { 4,  5,  6,  'B'},
					      { 7,  8,  9,  'C'},
					      {'#', 0, '*', 'D'}};
							  

#endif

/*===================================================================
 * EOF
 *===================================================================*/