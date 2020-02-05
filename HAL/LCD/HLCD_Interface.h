/*
 * File        : HLCD_Interface.h
 * Description : This interface file includes LCD Driver prototypes and definitions for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 5/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#ifndef __HLCD_Interface_h__
#define __HLCD_Interface_h__

/*=========================================================================*
 * Macros for modules input arguments
 *=========================================================================*/

/*Status*/
#define HLCD_ON       1
#define HLCD_OFF      0

/*Data types*/
#define HLCD_NUMBER   0
#define HLCD_STRING   1

/*LCD lines*/
#define HLCD_LINE1    1
#define HLCD_LINE2    2

/*Custom character names to choose between them*/
#define HLCD_CUST_CHAR_1 0
#define HLCD_CUST_CHAR_2 1
#define HLCD_CUST_CHAR_3 2
#define HLCD_CUST_CHAR_4 3
#define HLCD_CUST_CHAR_5 4
#define HLCD_CUST_CHAR_6 5
#define HLCD_CUST_CHAR_7 6
#define HLCD_CUST_CHAR_8 7





/*==============================================================================================================================================
 * LCD Modules
 *==============================================================================================================================================*/
 

/* 
 * Prototype   : void HLCD_voidInitializeLCD(void);
 * Description : Initialize LCD in a desired data and control registers
 *               in 4 bit mode control and data register must be the same register 
 * Arguments   : void                   
 * return      : void  
 */
 void HLCD_voidInitializeLCD(void);

 /* 
  * Prototype   : void HLCD_voidClearLCD(void);
  * Description : clear LCD and return cursor to first position
  * Arguments   : void
  * return      : void
  */
  void HLCD_voidClearLCD(void);

 /* 
  * Prototype   : void HLCD_voidReturnHome(void);
  * Description : return cursor to first position LCD content doesn't affect
  * Arguments   : void
  * return      : void
  */
  void HLCD_voidReturnHome(void);

 /* 
  * Prototype   : void HLCD_voidSelectLine(u8 Copy_u8Line);
  * Description : Select line 1 or 2 in LCD
  * Arguments   : choose line from (HLCD_LINE1 or HLCD_LINE2)
  * return      : void
  */
  void HLCD_voidSelectLine(u8 Copy_u8Line);
 
 /* 
  * Prototype   : void HLCD_voidSetCursorPosition(u8 Copy_u8Line,u8 Copy_u8Position);
  * Description : set cursor in specific position (choose line and position in line from 1 to 16)
  * Arguments   : line HLCD_LINE1 or HLCD_LINE2
  *               Position from 1 to 16
  * return      : void
  */
  void HLCD_voidSetCursorPosition(u8 Copy_u8Line,u8 Copy_u8Position);

 /* 
  * Prototype   : void HLCD_voidDisplayChar(u8 Copy_u8CharData);
  * Description : Output character to current cursor position
  * Arguments   : Char_Data : Character to be displayed
  * return      : void
  */
  void HLCD_voidDisplayChar(u8 Copy_u8CharData);
 
 /* 
  * Prototype   : void HLCD_voidDisplayChar(u8 Copy_u8CharData);
  * Description : Output String or a number to LCD at current cursor position
  * Arguments   : DataPointer: pointer to data stream to be displayed it could be 
  *               - Number of type u32 but function can handle up to 10 digit number (0,1,...,4294967296)
  *               - u8 character string
  *			      Data type: HLCD_NUMBER or HLCD_STRING 
  * return      : void
  */
  void HLCD_voidDisplayString(u32 *Copy_u32StringDataPtr,u8 Copy_u8DataType); 
 
 /* 
  * Prototype   : void HLCD_voidShiftRight(void);
  * Description : Shift all display right one step
  * Arguments   : void
  * return      : void  
  */
  void HLCD_voidShiftRight(void);

 /* 
  * Prototype   : void HLCD_voidShiftLeft(void);
  * Description : Shift all display left one step
  * Arguments   : void
  * return      : void  
  */
  void HLCD_voidShiftLeft(void); 
  
 /* 
  * Prototype   : void HLCD_voidCursorShiftRight(u8 Copy_u8Steps);
  * Description : shift cursor position right number of steps 
  * Arguments   : Number of Steps
  * return      : void  
  */
  void HLCD_voidCursorShiftRight(u8 Copy_u8Steps); 
 
 /* 
  * Prototype   : void HLCD_voidCursorShiftLeft(u8 Copy_u8Steps);
  * Description : shift cursor position Left number of steps 
  * Arguments   : Number of Steps
  * return      : void  
  */
  void HLCD_voidCursorShiftLeft(u8 Copy_u8Steps);
 
 /* 
  * Prototype   : void HLCD_voidCursorDisplayOnOff(u8 Copy_u8Status);
  * Description : set cursor display on and off
  * Arguments   : Status : HLCD_Disp_ON_OFF or HLCD_CURSOR_OFF
  * return      : void  
  */
  void HLCD_voidCursorDisplayOnOff(u8 Copy_u8Status);
 
 /* 
  * Prototype   : void HLCD_voidCursorBlinkOnOff(u8 Copy_u8Status);
  * Description : set cursor blinking on and off
  * Arguments   : Status : HLCD_Disp_ON_OFF or HLCD_BLINK_OFF
  * return      : void  
  */
  void HLCD_voidCursorBlinkOnOff(u8 Copy_u8Status);
 
 
 /* 
  * Prototype   : void HLCD_voidDisplayOnOff(u8 Copy_u8Status);
  * Description : set Whole display on & off
  * Arguments   : Status :
  *               HLCD_Disp_OFF or HLCD_Disp_ON_OFF
  * return      : void  
  */
  void HLCD_voidScreenDisplayOnOff(u8 Copy_u8Status); 
 
 /* 
  * Prototype   : void HLCD_voidScreenDisplayCustomChar(u8 Copy_SlotNumber);
  * Description : use custom character from CGRAM
  * Arguments   : slot number : from (HLCD_CUST_CHAR_1, HLCD_CUST_CHAR_2,...HLCD_CUST_CHAR_8)
  * return      : void  
  */
  void HLCD_voidDisplayCustomChar(u8 Copy_SlotNumber);
 
#endif

/*==============================================================================================================================================
 * EOF 
 *==============================================================================================================================================*/