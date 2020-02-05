/*
 * File        : LCD_Program.c
 * Description : This file includes LCD Driver implementations for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 5/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */


#include "LSTD_Types.h"
#include "LUTILS.h"
#include "LMath_Interface.h"
#include "LDELAY_Interface.h"
#include "MDIO_Interface.h"
#include "HLCD_Privte.h"
#include "HLCD_Config.h"
#include "HLCD_Interface.h"


/*==============================================================================================================================================
 * Global variables
 *==============================================================================================================================================*/

/*Initialize display with cursor and display enabled*/
u8 DisplayAndCursorCommand  = 0b00001111;
/*initialize font size with 7 Dot size, 2 lines and, 4Bit Modes */
u8 FontSizeAndLineCommand   = 0b00101000;  



/*==============================================================================================================================================
 * Private Modules
 *==============================================================================================================================================*/

static void HLCD_voidWriteCommand(u8 Copy_u8Command);
static void HLCD_voidWriteData(u8 Copy_u8Data);

/*==============================================================================================================================================
 * Public Modules
 *==============================================================================================================================================*/


/*=================================================================================================
 * 8 Bit Mode 
 *=================================================================================================*/

#if (HLCD_MODE == HLCD_8BIT)
 
 /* 
  * Prototype   : u8 HLCD_voidWriteCommand(u8 Copy_u8Command);
  * Description : write command to LCD
  * Arguments   : u8 Command       
  * return      : void
  */
  void HLCD_voidWriteCommand(u8 Copy_u8Command)
  {
	  /*Set RW pin 0 (Write Mode selected)*/
	  MDIO_u8WriteBit(ContREG,HLCD_RW,MDIO_LOW) ;
	  /*Set RS pin 0 (Instruction register selected)*/
	  MDIO_u8WriteBit(ContREG,HLCD_RS,MDIO_LOW) ;
	  /*output instruction data to Data Bus*/
	  switch(Copy_u8Command)
	  {
		  /*if command value is 1 clear data register and output 1 to it*/
		  case 1  : { MDIO_u8WriteReg(DataREG,MDIO_LOW); MDIO_u8WriteBit(DataREG,HLCD_DATA_REG_PIN0,MDIO_HIGH); } break;
		  /*else output command to data register*/
		  default : { MDIO_u8WriteReg(DataREG,Copy_u8Command); }   
	  
	  }/*end of switch case*/
	  
	  /*Set EN pin 1 (LCD Read data )*/
	  MDIO_u8WriteBit(ContREG,HLCD_EN,MDIO_HIGH);
	  //_delay_ms(2);
	  LDelay_voidDelay_ms(2);
	  /*Set EN pin 0 (LCD Write data to its reg)*/
	  MDIO_u8WriteBit(ContREG,HLCD_EN,MDIO_LOW) ;
 
  }/*end of HLCD_u8WriteCommand()*/
 

/* 
 * Prototype   : void HLCD_voidWriteData(u8 Copy_u8Data);
 * Description : write Data to LCD
 * Arguments   : u8 Data      
 * return      : void
 */
 void HLCD_voidWriteData(u8 Copy_u8Data)
 {
	 /*Set RW pin 0 (Write Mode selected)*/
	 MDIO_u8WriteBit(ContREG,HLCD_RW,MDIO_LOW);
	 /*Set RS pin 1 (Data register selected)*/
	 MDIO_u8WriteBit(ContREG,HLCD_RS,MDIO_HIGH);
	 /*output data to Data Bus*/
	 /*output instruction data to Data Bus*/
	 switch(Copy_u8Data)
	 {
		 /*if Data value is 1 clear data register and output 1 to it*/
		 case 1  : { MDIO_u8WriteReg(DataREG,MDIO_LOW); MDIO_u8WriteBit(DataREG,HLCD_DATA_REG_PIN0,MDIO_HIGH); } break;
		 /*else output Data to data register*/
		 default : { MDIO_u8WriteReg(DataREG,Copy_u8Data); }
		 
	 }/*end of switch case*/
	 
	 /*Set EN pin 1 (LCD Read data )*/
	 MDIO_u8WriteBit(ContREG,HLCD_EN,MDIO_HIGH);
	 //_delay_ms(2);
	 LDelay_voidDelay_ms(2);
	 /*Set EN pin 0 (LCD Write data to its reg)*/
	 MDIO_u8WriteBit(ContREG,HLCD_EN,MDIO_LOW);
 
 }/*end of HLCD_u8WriteData()*/
 

 
/*=================================================================================================
 * 4 Bit Mode 
 *=================================================================================================*/

 #elif (HLCD_MODE == HLCD_4BIT)
 
 
/* 
 * Prototype   : u8 HLCD_voidWriteCommand(u8 Copy_u8Command);
 * Description : write command to LCD
 * Arguments   : u8 Command       
 * return      : void
 */
 void HLCD_voidWriteCommand(u8 Copy_u8Data)
 {
	 /*Set RW pin 0 (Write Mode selected)*/
	 MDIO_u8WriteBit(ContREG,HLCD_RW,MDIO_LOW) ;  
	 /*Set RS pin 0 (Instruction register selected)*/
	 MDIO_u8WriteBit(ContREG,HLCD_RS,MDIO_LOW) ;  
	 /*output first 4 bits instruction data to Data Bus*/
	 for(u8 i=4;i<8;i++)
	 {
		 /*Output value of Instruction bit i at Data Register DIO Pin i*/
		 MDIO_u8WriteBit(DataREG,i,L_UTILS_GET_BIT(Copy_u8Data,i)); 
	 }
	 /*latch sent data*/
	 /*Set EN pin 1 (LCD Read data )*/
	 MDIO_u8WriteBit(ContREG,HLCD_EN,MDIO_HIGH) ; 
	 //_delay_ms(2);
	 LDelay_voidDelay_ms(2);
	 /*Set EN pin 0 (LCD Write data to its reg)*/
	 MDIO_u8WriteBit(ContREG,HLCD_EN,MDIO_LOW) ;  
	 
	 /*output second 4 bits instruction to data bus*/
	 for(u8 i=0;i<4;i++)
	 {
		 /*Output value of Instruction bit i at Data Register DIO Pin i*/
		 MDIO_u8WriteBit(DataREG,i+4,L_UTILS_GET_BIT(Copy_u8Data,i)); 
	 }
	 /*latch sent data*/
	 /*Set EN pin 1 (LCD Read data )*/
	 MDIO_u8WriteBit(ContREG,HLCD_EN,MDIO_HIGH) ; 
	 //_delay_ms(2);
	 LDelay_voidDelay_ms(2);
	 /*Set EN pin 0 (LCD Write data to its reg)*/
	 MDIO_u8WriteBit(ContREG,HLCD_EN,MDIO_LOW) ;  
 }/*end of HLCD_voidWriteCommand()*/
 
 
 /* 
 * Prototype   : void HLCD_voidWriteData(u8 Copy_u8Data);
 * Description : write Data to LCD
 * Arguments   : u8 Data      
 * return      : void
 */
 void HLCD_voidWriteData(u8 Copy_u8Data)
 {
	 /*Set RW pin 0 (Write Mode selected)*/
	 MDIO_u8WriteBit(ContREG,HLCD_RW,MDIO_LOW) ;  
	 /*Set RS pin 1 (Data register selected)*/
	 MDIO_u8WriteBit(ContREG,HLCD_RS,MDIO_HIGH) ;  
	 /*output first 4 Data bits to Data Bus*/
	 for(u8 i=4;i<8;i++)
	 {
		 /*Output value of Data bit i at Data register DIO Pin i*/
		 MDIO_u8WriteBit(DataREG,i,L_UTILS_GET_BIT(Copy_u8Data,i)); 
	 }
	 /*latch sent data*/
	 /*Set EN pin 1 (LCD Read data )*/
	 MDIO_u8WriteBit(ContREG,HLCD_EN,MDIO_HIGH) ; 
	 //_delay_ms(2);
	 LDelay_voidDelay_ms(2);
	 /*Set EN pin 0 (LCD Write data to its reg)*/
	 MDIO_u8WriteBit(ContREG,HLCD_EN,MDIO_LOW) ;  
	 
	 /*output second 4 bits Data to data bus*/
	 for(u8 i=0;i<4;i++)
	 {
		 /*Output value of Data bit i at Data register DIO Pin i*/
		 MDIO_u8WriteBit(DataREG,i+4,L_UTILS_GET_BIT(Copy_u8Data,i)); 
	 }
	 /*latch sent data*/
	 /*Set EN pin 1 (LCD Read data)*/
	 MDIO_u8WriteBit(ContREG,HLCD_EN,MDIO_HIGH) ; 
	 //_delay_ms(2);
	 LDelay_voidDelay_ms(2);
	 /*Set EN pin 0 (LCD Write data to its reg)*/
	 MDIO_u8WriteBit(ContREG,HLCD_EN,MDIO_LOW) ;  

 }/*end of HLCD_voidWriteData()*/
 
 
#endif /*end of Mode select*/


/* 
 * Prototype   : void HLCD_voidInitializeLCD(void);
 * Description : Initialize LCD in a desired data and control registers
 *               in 4 bit mode control and data register must be the same register 
 * Arguments   : void                   
 * return      : void  
 */
 void HLCD_voidInitializeLCD(void)
 {
	 /*==============================================================
	  * Configure LCD pins direction
	  *==============================================================*/
	 /*Configure RS Pin output*/
	 MDIO_u8SetDirectionBit(ContREG,HLCD_RS,MDIO_OUTPUT);      
	 /*Configure RW Pin output*/
	 MDIO_u8SetDirectionBit(ContREG,HLCD_RW,MDIO_OUTPUT);      
	 /*Configure EN Pin output*/
	 MDIO_u8SetDirectionBit(ContREG,HLCD_EN,MDIO_OUTPUT);      
	 /*Configure Data register output*/
	 MDIO_u8SetDirectionReg(DataREG,MDIO_OUTPUT);              
	 //_delay_ms(50);
	 LDelay_voidDelay_ms(50);
	 
	 /*==============================================================
	  * Choose font size and number of lines
	  *==============================================================*/
	 /*Set Font size value 5*7 dots or 5*10 dots*/
	  L_UTILS_SET_BIT_VALUE(FontSizeAndLineCommand,HLCD_FONT_BIT,HLCD_FONT_SIZE);
	 /*Set number of lines 1 or 2*/
	  L_UTILS_SET_BIT_VALUE(FontSizeAndLineCommand,HLCD_LINE_BIT,HLCD_LINE_MODE);
	  
	 /*==============================================================
	  * LCD initialization sequence
	  *==============================================================
	  * 8Bit Mode initialization
	  *====================================*/
	 #if (HLCD_MODE == HLCD_8BIT)
	    /*Choose 8Bit mode in function set instruction*/
		L_UTILS_SET_BIT(FontSizeAndLineCommand,HLCD_DATALENGTH_BIT);
		/*send Function set instruction*/
		HLCD_voidWriteCommand(FontSizeAndLineCommand);
		//_delay_ms(1);
		LDelay_voidDelay_ms(1);
	 /*====================================
	  * 4Bit Mode initialization
	  *====================================*/
     #elif (HLCD_MODE == HLCD_4BIT)
		/*send 4BIT Function set instruction two times*/
		HLCD_voidWriteCommand(HLCD_FN_SET_4BIT);
		/*send Function set instruction for font and number of lines*/  
		HLCD_voidWriteCommand(FontSizeAndLineCommand);       
		//_delay_ms(1);
		LDelay_voidDelay_ms(1);
	 #endif
	 
	 /*send Display ON OFF instruction*/
	 HLCD_voidWriteCommand(DisplayAndCursorCommand);
	 //_delay_ms(1);
	 LDelay_voidDelay_ms(1);
	 /*send Display clear instruction*/
	 HLCD_voidWriteCommand(HLCD_DISP_CLEAR);
	 //_delay_ms(2);
	 LDelay_voidDelay_ms(2);
	 /*send ENTRY MODE set instruction*/
	 HLCD_voidWriteCommand(HLCD_ENTRY_MODE);
	 //_delay_ms(2);
	 LDelay_voidDelay_ms(2);
	 
	 /*=============================================================================
	  * Initialize custom made characters with pre-configured arrays' values
	  *=============================================================================*/
	 /*jump to CGRAM address*/
	 HLCD_voidWriteCommand(HLCD_CGRAM_ADDRESS);
	 
	 /*fill GCRAM with HLCD_u8CustomCharArray values*/
	 for (u8 i = 0 ; i < 8 ; i++)
	 {
		 for (u8 j = 0 ; j < 8 ; j++)
		 {
			 HLCD_voidWriteData(HLCD_u8CustomCharArray[i][j]);
		 
		 }/*end of j loop*/
	 
	 }/*end of i loop*/
	 
	 /*return to DDRAM address 1*/
	 HLCD_voidWriteCommand(HLCD_DDRAM_ADD1); 
			 
 }/*end of HLCD_u8InitializeLCD()*/


 /* 
  * Prototype   : void HLCD_voidClearLCD(void);
  * Description : clear LCD and return cursor to first position
  * Arguments   : void
  * return      : void
  */
  void HLCD_voidClearLCD(void)
  {
	  /*send Display clear instruction*/
	  HLCD_voidWriteCommand(HLCD_DISP_CLEAR);      
	  
  }/*end of HLCD_voidClearLCD()*/

 /* 
  * Prototype   : void HLCD_voidReturnHome(void);
  * Description : return cursor to first position LCD content doesn't affect
  * Arguments   : void
  * return      : void
  */
  void HLCD_voidReturnHome(void)
  {
	  /*send Return home instruction*/
	  HLCD_voidWriteCommand(HLCD_RET_HOME);
	  
  }/*end of HLCD_voidReturnHome()*/

 /* 
  * Prototype   : void HLCD_voidSelectLine(u8 Copy_u8Line);
  * Description : Select line 1 or 2 in LCD
  * Arguments   : choose line from (HLCD_LINE1 or HLCD_LINE2)
  * return      : void
  */
  void HLCD_voidSelectLine(u8 Copy_u8Line)
  {
	  /*choose line*/
	  switch(Copy_u8Line)
	  {
		  case HLCD_LINE1 : {  HLCD_voidWriteCommand(HLCD_DDRAM_ADD1); } break;
		  case HLCD_LINE2 : {  HLCD_voidWriteCommand(HLCD_DDRAM_ADD2); } break;
		  
	  }/*end of line switch case*/
	 
  }/*end of HLCD_voidSelectLine()*/
 
 /* 
  * Prototype   : void HLCD_voidSetCursorPosition(u8 Copy_u8Line,u8 Copy_u8Position);
  * Description : set cursor in specific position (choose line and position in line from 1 to 16)
  * Arguments   : line HLCD_LINE1 or HLCD_LINE2
  *               Position from 1 to 16
  * return      : void
  */
  void HLCD_voidSetCursorPosition(u8 Copy_u8Line,u8 Copy_u8Position)
  {
	  /*choose line*/
	  switch(Copy_u8Line)
	  {
		  case HLCD_LINE1 : { HLCD_voidWriteCommand(HLCD_DDRAM_ADD1+ Copy_u8Position -1); } break;
		  case HLCD_LINE2 : { HLCD_voidWriteCommand(HLCD_DDRAM_ADD2+ Copy_u8Position -1); } break;
	  
	  }/*end of line switch case*/
	    
  }/*end of HLCD_voidSetCursorPosition()*/

 /* 
  * Prototype   : void HLCD_voidDisplayChar(u8 Copy_u8CharData);
  * Description : Output character to current cursor position
  * Arguments   : Char_Data : Character to be displayed a number (0-9) or a character
  * return      : void
  */
  void HLCD_voidDisplayChar(u8 Copy_u8CharData)
  {
	  /*check character type*/
	  if( (Copy_u8CharData >= 0) && (Copy_u8CharData < 10) )
	  {
		  /*if character is number*/
		  HLCD_voidWriteData((Copy_u8CharData+'0')); 
		  
	  }
	  else
	  {
		  /*if character is char*/
		  HLCD_voidWriteData(Copy_u8CharData);
		 
	  }/*end of character type check*/
	  
	  
  }/*end of HLCD_voidDisplayChar*/
 
 /* 
  * Prototype   : void HLCD_voidDisplayChar(u8 Copy_u8CharData);
  * Description : Output String or a number to LCD at current cursor position
  * Arguments   : DataPointer: pointer to data stream to be displayed it could be 
  *               - Number of type u32 but function can handle up to 10 digit number (0,1,...,4294967296)
  *               - u8 character string
  *			      Data type: HLCD_NUMBER or HLCD_STRING 
  * return      : void
  */
  void HLCD_voidDisplayString(u32 *Copy_u32StringDataPtr,u8 Copy_u8DataType) 
  {
	  /*String pointer*/
	  u8 *Local_u8StringData = (u8 *)Copy_u32StringDataPtr;
	  /*single digit*/
	  u8  Local_u8Digit        = 0;
	  /*number value*/
	  u32 Local_u32NumberValue = 0;
	  /*remainder used in number display calculations*/
	  u32 Local_u32Remainder   = 0;
	  
	  /*check data type*/
	  if (Copy_u8DataType == HLCD_NUMBER) /*number type check*/
	  {
		  /*store number value to be displayed*/
		  Local_u32NumberValue = *Copy_u32StringDataPtr;
		  
		  
		  /*if number is zero*/
		  if (Local_u32NumberValue == 0)
		  {
			  /*display zero*/
			  HLCD_voidDisplayChar(Local_u8Digit);
			  
		  }
		  else
		  {
			  /*loop each digit in number*/
			  for (u8 i=0;i<10;i++)
			  {
				  /*check if that digit 10^i exists starting from 10th digit until first existent digit reached*/
				  if ( (Local_u32NumberValue / LMATH_u32GetExponential( 10 , (9-i))) != 0)
				  {
					  /*if first digit found loop number digits*/
					  for (u8 j=i;j<10;j++)
					  {
						  /*get current value and display it*/
						  /*calculate remaining digits to be displayed*/
						  Local_u32Remainder   = Local_u32NumberValue % LMATH_u32GetExponential(10,(9-j));
						  /*calculate current digit*/
						  Local_u8Digit        = Local_u32NumberValue / LMATH_u32GetExponential(10,(9-j));
						  /*prepare number value with remaining digits*/
						  Local_u32NumberValue = Local_u32Remainder;
						  /*display current digit*/
						  HLCD_voidDisplayChar(Local_u8Digit);
						  
					  }/*end of number digits for loop*/
						
					  break; /*exit loop*/
						
				  }/*end of digits existence check*/
						
		      }/*end of digits loop*/  
			  
		  }/*end of zero check*/
		  
		  
		  
	  }
	  else if(Copy_u8DataType == HLCD_STRING)/*string type check*/
	  {
		  /*check if null char reached*/
		  while(*Local_u8StringData!='\0')
		  {
			  /*display current char in string*/
			  HLCD_voidDisplayChar(*Local_u8StringData++);
		  
		  }/*end of string loop*/
	  
	  }/*end of type check*/
	  
 }/*end of */
 
 /* 
  * Prototype   : void HLCD_voidShiftRight(void);
  * Description : Shift all display right one step
  * Arguments   : void
  * return      : void  
  */
  void HLCD_voidShiftRight(void)
  {
	  /*send shift right instruction*/
	  HLCD_voidWriteCommand(HLCD_DISP_SHIFT_RIGHT); 
	  
  }/*end of HLCD_voidShiftRight()*/

 /* 
  * Prototype   : void HLCD_voidShiftLeft(void);
  * Description : Shift all display left one step
  * Arguments   : void
  * return      : void  
  */
  void HLCD_voidShiftLeft(void) 
  {
	 /*send shift left instruction*/ 
	 HLCD_voidWriteCommand(HLCD_DISP_SHIFT_LEFT); 
	 
  }/*end of HLCD_voidShiftLeft()*/
 
 /* 
  * Prototype   : void HLCD_voidCursorShiftRight(u8 Copy_u8Steps);
  * Description : shift cursor position number of steps right
  * Arguments   : Number of Steps
  * return      : void  
  */
  void HLCD_voidCursorShiftRight(u8 Copy_u8Steps) 
  {
	  /*loop steps*/
	  for(u8 i = 0 ; i < Copy_u8Steps ; i++)
	  {
		  /*Shift cursor one step right instruction*/
		  HLCD_voidWriteCommand(HLCD_CURSOR_SHIFT_RIGHT); 
		  
	  }/*end of steps for loop*/
	  
  }/*end of HLCD_voidCursorShiftRight()*/

 /* 
  * Prototype   : void HLCD_voidCursorShiftLeft(u8 Copy_u8Steps);
  * Description : shift cursor position number of steps Left
  * Arguments   : Number of Steps
  * return      : void  
  */
  void HLCD_voidCursorShiftLeft(u8 Copy_u8Steps) 
  {
	  /*loop steps*/
	  for(u8 i = 0 ; i < Copy_u8Steps ; i++)
	  {
		  /*Shift cursor one step Left instruction*/
		  HLCD_voidWriteCommand(HLCD_CURSOR_SHIFT_LEFT); 
		  
	  }/*end of steps for loop*/
	  
  }/*end of HLCD_voidCursorShiftLeft()*/

 /* 
  * Prototype   : void HLCD_voidCursorDisplayOnOff(u8 Copy_u8Status);
  * Description : set cursor display on and off
  * Arguments   : Status : HLCD_ON or HLCD_OFF
  * return      : void  
  */
  void HLCD_voidCursorDisplayOnOff(u8 Copy_u8Status)
  {
	  /*Set Display status value (on or off)*/
	  L_UTILS_SET_BIT_VALUE(DisplayAndCursorCommand,HLCD_CURSOR_BIT,Copy_u8Status);
	  /*Send command*/
	  HLCD_voidWriteCommand(DisplayAndCursorCommand);
	 
  }/*end of HLCD_voidCursorDisplayOnOff()*/

 /* 
  * Prototype   : void HLCD_voidCursorBlinkOnOff(u8 Copy_u8Status);
  * Description : set cursor blinking on and off
  * Arguments   : Status : HLCD_ON or HLCD_OFF
  * return      : void  
  */
  void HLCD_voidCursorBlinkOnOff(u8 Copy_u8Status) 
  {
	  /*Set Cursor status value (on or off)*/
	  L_UTILS_SET_BIT_VALUE(DisplayAndCursorCommand,HLCD_BLINK_BIT,Copy_u8Status);
	  /*Send command*/
	  HLCD_voidWriteCommand(DisplayAndCursorCommand);
	  
  }/*end of HLCD_voidCursorBlinkOnOff()*/
 
 
 /* 
  * Prototype   : void HLCD_voidScreenDisplayOnOff(u8 Copy_u8Status);
  * Description : set Whole display on & off
  * Arguments   : Status : HLCD_ON or HLCD_OFF
  * return      : void  
  */
  void HLCD_voidScreenDisplayOnOff(u8 Copy_u8Status) 
  {
	  /*Set Display status value (on or off)*/
	  L_UTILS_SET_BIT_VALUE(DisplayAndCursorCommand,HLCD_DISP_BIT,Copy_u8Status);
	  /*Send command*/
	  HLCD_voidWriteCommand(DisplayAndCursorCommand);
	  
  }/*end of HLCD_voidDisplayOnOff()*/

 /* 
  * Prototype   : void HLCD_voidDisplayCustomChar(u8 Copy_SlotNumber);
  * Description : use custom character from CGRAM
  * Arguments   : slot number : from (HLCD_CUST_CHAR_1, HLCD_CUST_CHAR_2,...HLCD_CUST_CHAR_8)
  * return      : void  
  */
  void HLCD_voidDisplayCustomChar(u8 Copy_SlotNumber)
  {
	  /*slot in range check*/
	  if ( (Copy_SlotNumber >= 0) && (Copy_SlotNumber<8) )
	  {
		  /*Display Custom character in that slot*/
		  HLCD_voidWriteData(Copy_SlotNumber);
		
	  }/*end of slot number range check*/
	  
  }/*end of HLCD_voidDisplayCustomChar()*/



/*==============================================================================================================================================
 * EOF 
 *==============================================================================================================================================*/
