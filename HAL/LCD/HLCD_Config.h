/*
 * File        : HLCD_Config.h
 * Description : This file includes LCD configuration definitions for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 5/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */


#ifndef __HLCD_CONFIG_h__
#define __HLCD_CONFIG_h__

/* 
 * Choose LCD Data length Mode :
 * HLCD_8BIT or HLCD_4BIT
 */
 #define HLCD_MODE		  HLCD_4BIT

/* 
 * Choose LCD Number of lines :
 * HLCD_ONE_LINE or HLCD_TWO_LINES
 */
 #define HLCD_LINE_MODE   HLCD_TWO_LINES
 
 /* 
 * Choose LCD Font size:
 * HLCD_7_DOTS or HLCD_10_DOTS
 * 10 dots size ONLY work with one line mode 
 */
 #define HLCD_FONT_SIZE   HLCD_7_DOTS

/*============================================================================
 * LCD Connections
 *============================================================================
 * in 4Bit mode:
 * - Control  and data registers must be the same
 * - Data bits are connected D4->Bit4 D5->Bit5 D6->Bit6 D7->Bit7
 */
#define ContREG  MDIO_PORTB
#define DataREG  MDIO_PORTB

/*Define Register selector pin*/  
#define HLCD_RS 2
/*Define Register selector pin*/ 
#define HLCD_RW 1
/*Define Register selector pin*/  
#define HLCD_EN 0 


/* 
 * Custom made characters arrays
 * you can add new custom char by assigning new value for array 
 * there are 8 available custom char slots 
 * ex: custom made arrow at first custom made slot 
 * const u8 HLCD_u8Custom_Char1[8] = {0b00010000,
 *									  0b00111000,
 *									  0b01111100,
 *									  0b11010110,
 *									  0b10010001,
 * 									  0b10010001,
 *									  0b00010000,
 *									  0b00000000}; 
 */
const u8 HLCD_u8CustomCharArray[8][8] =

/*HLCD_u8Custom_Char1*/			  {{0b00000000,
								    0b00001010,
									0b00011111,
									0b00011111,
									0b00001110,
									0b00000100,
									0b00000000,
									0b00000000},

/*HLCD_u8Custom_Char2*/			   {0b00000100,
									0b00001110,
									0b00010101,
									0b00010101,
									0b00000100,
									0b00000100,
									0b00000000,
									0b00000000},
				   				   
/*HLCD_u8Custom_Char3*/			   {0b00001110,
									0b00011111,
									0b00011111,
									0b00011111,
									0b00000000,
									0b00001110,
									0b00000000,
									0b00000000},

/*HLCD_u8Custom_Char4*/			   {0b00000000,
									0b00000100,
									0b00001110,
									0b00011111,
									0b00001110,
									0b00000100,
									0b00000000,
									0b00000000},

/*HLCD_u8Custom_Char5*/			   {0b00000100,
									0b00001110,
									0b00011111,
									0b00011011,
									0b00010001,
									0b00000000,
									0b00000000,
									0b00000000},

/*HLCD_u8Custom_Char6*/			   {0b00010001,
									0b00011011,
									0b00001110,
									0b00000100,
									0b00001110,
									0b00011011,
									0b00010001,
									0b00000000},

/*HLCD_u8Custom_Char7*/			   {0b00011111,
									0b00010101,
									0b00010101,
									0b00011111,
									0b00010101,
									0b00010101,
									0b00011111,
									0b00000000},

/*HLCD_u8Custom_Char8*/			   {0b00001110,
									0b00011101,
									0b00011001,
									0b00011111,
									0b00001110,
									0b00000000,
									0b00011111,
									0b00000000}};


#endif


/*==============================================================================================================================================
 * EOF 
 *==============================================================================================================================================*/