#ifndef __HLCD_Interface_h__
#define __HLCD_Interface_h__


//Data types
#define HLCD_NUMBER   0
#define HLCD_STRING   1

//Custom character names to choose between them
#define HLCD_CUST_CHAR_1 1
#define HLCD_CUST_CHAR_2 2
#define HLCD_CUST_CHAR_3 3
#define HLCD_CUST_CHAR_4 4

//8 Bit -----------------------------------------------------------------------

void HLCD_INIT(void); //Initiate LCD

void HLCD_ClearLCD(void); //clear LCD and return cursor to first position
void HLCD_ReturnHome(void); //return cursor to first position LCD content doesn't affect

void HLCD_SEL_LINE(u8 LINE); //Select line 1 or 2
void HLCD_SET_CURSOR(u8 LINE,u8 POSITION); //set cursor in specific position choose line and position from 1 to 16
/*Disply char and number*/
void HLCD_DisplayChar(u8 Char_Data); //Output character to to specific line LCD
/*Disply String of chars u8 pointer -Casted u8 inside the fn implementation- and a u32 number 10 bit max i/p as a pointer*/
void HLCD_DisplayStr(u32 *Str_Data); //Output String to specific line LCD

void HLCD_ShiftRight(void); //Shift characters right one step
void HLCD_ShiftLeft(void); //Shift characters Left one step
void HLCD_EN_SCRN_ShiftRight(void); //Shift all display right out of screen
void HLCD_EN_SCRN_ShiftLeft(void); //Shift all display Left out of screen
void HLCD_Cursor_ShiftRight(u8 steps); //shift cursor one step right
void HLCD_Cursor_ShiftLeft(u8 steps); //shift cursor one step left

void HLCD_Cursor_ONOFF(u8 STATUS); //set cursor and blinking on & of
void HLCD_Blink_ONOFF(u8 STATUS); //set cursor blinking only on & off
void HLCD_Disp_ONOFF(u8 STATUS); //set Whole display on & off

void HLCD_CUST_CHAR(u8 SLOT_NUM); //create custom character in CGRAM



//4 Bit -----------------------------------------------------------------------

void HLCD_INIT_4BIT(void); //Initiate LCD 4 BIT mode 


void HLCD_ClearLCD_4BIT(void); //clear LCD and return cursor to first position
void HLCD_ReturnHome_4BIT(void); //return cursor to first position LCD content doesn't affect

void HLCD_SEL_LINE_4BIT(u8 LINE); //Select line 1 or 2
void HLCD_SET_CURSOR_4BIT(u8 LINE,u8 POSITION); //Set cursor in specific location

void HLCD_DisplayChar_4BIT(u8 Char_Data); //Output character to to specific line LCD
void HLCD_DisplayStr_4BIT(u32 *Str_Data,u8 DataType); //Output String to specific line LCD

void HLCD_ShiftRight_4BIT(void); //Shift all display right one step
void HLCD_ShiftLeft_4BIT(void); //Shift all display Left one step
void HLCD_EN_SCRN_ShiftRight_4BIT(void); //Shift all display right out of screen
void HLCD_EN_SCRN_ShiftLeft_4BIT(void); //Shift all display Left out of screen
void HLCD_Cursor_ShiftRight_4BIT(u8 steps); //shift cursor one step right
void HLCD_Cursor_ShiftLeft_4BIT(u8 steps); //shift cursor one step left

void HLCD_Cursor_ONOFF_4BIT(u8 STATUS); //set cursor and blinking on & off
void HLCD_Blink_ONOFF_4BIT(u8 STATUS); //set cursor blinking only on & off
void HLCD_Disp_ONOFF_4BIT(u8 STATUS); //set Whole display on & off
void HLCD_CUST_CHAR_4BIT(u8 SLOT_NUM); //create custom character in CGRAM



#endif