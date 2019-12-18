#define F_CPU 8000000UL
#include <util/delay.h>

#include "LSTD_Types.h"
#include "LUTILS.h"
#include "MDIO_Interface.h"
#include "HLCD_Privte.h"
#include "HLCD_Interface.h"
#include "HLCD_Config.h"
#include "Lib.h"

void HLCD_Write_CMD(u8 Cont_REG,u8 Data_REG,u8 DATA)
{
	MDIO_Write_Bit(Cont_REG,HLCD_RW,LOW) ;  //Set RW pin 0 (Write Mode selected)
	MDIO_Write_Bit(Cont_REG,HLCD_RS,LOW) ;  //Set RS pin 0 (Instruction register selected)
	MDIO_Write_Reg(Data_REG,DATA);          //output instruction data to Data Bus
	MDIO_Write_Bit(Cont_REG,HLCD_EN,HIGH) ; //Set EN pin 1 (LCD Read data )
	_delay_ms(2);
	MDIO_Write_Bit(Cont_REG,HLCD_EN,LOW) ;  //Set EN pin 0 (LCD Write data to its reg)
}
void HLCD_Write_Data(u8 Cont_REG,u8 Data_REG,u8 DATA)
{
	MDIO_Write_Bit(Cont_REG,HLCD_RW,LOW) ;   //Set RW pin 0 (Write Mode selected)
	MDIO_Write_Bit(Cont_REG,HLCD_RS,HIGH) ;  //Set RS pin 1 (Data register selected)
	MDIO_Write_Reg(Data_REG,DATA);           //output data to Data Bus
	MDIO_Write_Bit(Cont_REG,HLCD_EN,HIGH) ;  //Set EN pin 1 (LCD Read data )
	_delay_ms(2);
	MDIO_Write_Bit(Cont_REG,HLCD_EN,LOW) ;   //Set EN pin 0 (LCD Write data to its reg)
}

#if (HLCD_MODE == HLCD_8BIT)

void HLCD_INIT(void)
{
	MDIO_SetDirection_Bit(ContREG,HLCD_RS,OUTPUT);      //RS Pin o/p
	MDIO_SetDirection_Bit(ContREG,HLCD_RW,OUTPUT);      //RW Pin o/p
	MDIO_SetDirection_Bit(ContREG,HLCD_EN,OUTPUT);      //EN Pin o/p
	MDIO_SetDirection_Reg(DataREG,OUTPUT);              //Data register o/p
	_delay_ms(50);
	HLCD_Write_CMD(ContREG,DataREG,FN_SET);             //send Function set instruction
	_delay_ms(1);
	HLCD_Write_CMD(ContREG,DataREG,Disp_ON_OFF);        //send Display ON OFF instruction
	_delay_ms(1);
	HLCD_Write_CMD(ContREG,DataREG,Disp_CLEAR);         //send Display clear instruction
	_delay_ms(2);
	HLCD_Write_CMD(ContREG,DataREG,ENTRY_MODE);         //send ENTRY MODE set instruction
	_delay_ms(2);
	
	
	//put custom made character 1 in GCRAM 0x00
	HLCD_Write_CMD(ContREG,DataREG,0x40);
	for (u8 i=0;i<8;i++)
	{
		HLCD_Write_Data(ContREG,DataREG,CUST1[i]);
	}
	//put custom made character 2 in GCRAM 0x01
	for (u8 i=0;i<8;i++)
	{
		HLCD_Write_Data(ContREG,DataREG,CUST2[i]);
	}
	//put custom made character 3 in GCRAM 0x02
	for (u8 i=0;i<8;i++)
	{
		HLCD_Write_Data(ContREG,DataREG,CUST3[i]);
	}
	//put custom made character 3 in GCRAM 0x03
	for (u8 i=0;i<8;i++)
	{
		HLCD_Write_Data(ContREG,DataREG,CUST4[i]);
	}
	//return to DDRAM address 1
	HLCD_Write_CMD(ContREG,DataREG,DDRAM_ADD1); 
}

//clear LCD and return cursor to first position
void HLCD_ClearLCD(void) 
{
	HLCD_Write_CMD(ContREG,DataREG,Disp_CLEAR);      //send Display clear instruction
	_delay_ms(0.5);
}
//return cursor to first position LCD content doesn't affect
void HLCD_ReturnHome(void) 
{
	HLCD_Write_CMD(ContREG,DataREG,RET_HOME);        //send Return home instruction
	_delay_ms(0.5);
}
//Select line 1 or 2
void HLCD_SEL_LINE(u8 LINE) 
{
	if (LINE==1)
	{
		HLCD_Write_CMD(ContREG,DataREG,DDRAM_ADD1);  //send set DDRAM address of line 1 instruction
	}
	else if(LINE==2)
	{
		HLCD_Write_CMD(ContREG,DataREG,DDRAM_ADD2);  //send set DDRAM address of line 2 instruction
	}
}
//Select line 1 or 2
void HLCD_SET_CURSOR(u8 LINE,u8 POSITION) 
{
	u8 add=0;
	if (LINE==1)
	{
		add=(DDRAM_ADD1)+POSITION-1;
		HLCD_Write_CMD(ContREG,DataREG,add);         //send set DDRAM address of line 1 and specific position instruction
	}
	else if(LINE==2)
	{
		add=(DDRAM_ADD2)+POSITION-1;
		HLCD_Write_CMD(ContREG,DataREG,add);         //send set DDRAM address of line 1 and specific position instruction
	}
}
void HLCD_DisplayChar(u8 Char_Data)
{
	if((Char_Data>=0)&&(Char_Data<10))
	{
		HLCD_Write_Data(ContREG,DataREG,(Char_Data+'0')); //send Number to LCD
		_delay_ms(1);
	}
	else
	{
		HLCD_Write_Data(ContREG,DataREG,Char_Data); //send Char to LCD
		_delay_ms(1);
	}
}

void HLCD_DisplayStr(u32 *Str_Data,u8 DataType) //Output String to LCD
{
	u8 *Local_u8StringData = (u8 *)Str_Data;
	
	u8  Local_u8Digit = 0;
	u32 Local_u32No = 0;
	u32 Local_u32Remainder =0;
	
	if (DataType == HLCD_NUMBER)
	{
		Local_u32No = *Str_Data;
		for (u8 i=0;i<10;i++)
		{
			if ((Local_u32No / L_u32GetExponential(10,(9-i))) != 0)
			{
				for (u8 j=i;j<10;j++)
				{
					Local_u32Remainder = Local_u32No % L_u32GetExponential(10,(9-j));
					Local_u8Digit      = Local_u32No / L_u32GetExponential(10,(9-j));
					Local_u32No = Local_u32Remainder;
					HLCD_DisplayChar(Local_u8Digit);
				}
				break;
			}
		}
		if (Local_u32No == 0)
		{
			HLCD_DisplayChar(Local_u8Digit);
		}
	}
	else if(DataType == HLCD_STRING)
	{
		while(*Local_u8StringData!='\0')//check if null char reached
		{
			HLCD_DisplayChar(*Local_u8StringData++);
		}
	}
}
//Shift all display right
void HLCD_ShiftRight(void)
{
	HLCD_Write_CMD(ContREG,DataREG,DISP_SHIFT_RIGHT); //send shift right instruction
	_delay_ms(0.5);
}
//Shift all display right
void HLCD_ShiftLeft(void)
{
	HLCD_Write_CMD(ContREG,DataREG,DISP_SHIFT_LEFT); //send shift left instruction
	_delay_ms(0.5);
}
//set cursor on & off
void HLCD_Cursor_ONOFF(u8 STATUS) 
{
	if (STATUS==OFF)
	{
		HLCD_Write_CMD(ContREG,DataREG,CURSOR_OFF); //send Display ON OFF instruction
	}
	else if(STATUS==ON)
	{
		HLCD_Write_CMD(ContREG,DataREG,Disp_ON_OFF); //send Display ON OFF instruction
	}
	_delay_ms(0.5);
}
//set cursor blink on & off
void HLCD_Blink_ONOFF(u8 STATUS) 
{
	if (STATUS==OFF)
	{
		HLCD_Write_CMD(ContREG,DataREG,BLINK_OFF);  //send Display ON OFF instruction
	}
	else if(STATUS==ON)
	{
		HLCD_Write_CMD(ContREG,DataREG,Disp_ON_OFF);//send Display ON OFF instruction
	}
	_delay_ms(0.5);
}
//set Whole display on & off
void HLCD_Disp_ONOFF(u8 STATUS) 
{
	if (STATUS==OFF)
	{
		HLCD_Write_CMD(ContREG,DataREG,Disp_OFF);  //send Display ON OFF instruction
	}
	else if(STATUS==ON)
	{
		HLCD_Write_CMD(ContREG,DataREG,Disp_ON_OFF); //send Display ON OFF instruction
	}
	_delay_ms(0.5);
}
//shift cursor one step right
void HLCD_Cursor_ShiftRight(u8 steps) 
{
	for(u8 i=0;i<steps;i++)
	{
		HLCD_Write_CMD(ContREG,DataREG,CURSOR_SHIFT_RIGHT); //Shift cursor one step right instruction
		_delay_ms(0.5);
	}
}
void HLCD_Cursor_ShiftLeft(u8 steps) //shift cursor one step left
{
	for(u8 i=0;i<steps;i++)
	{
		HLCD_Write_CMD(ContREG,DataREG,CURSOR_SHIFT_LEFT); //Shift cursor one step right instruction
		_delay_ms(0.5);
	}
}

void HLCD_EN_SCRN_ShiftRight(void) //Shift all display right out of screen
{
	HLCD_Write_CMD(ContREG,DataREG,WHOLE_SCRN_SHIFT_RIGHT); //Shift cursor one step left instruction
	_delay_ms(0.5);
}
void HLCD_EN_SCRN_ShiftLeft(void) //Shift all display Left out of screen
{
	HLCD_Write_CMD(ContREG,DataREG,WHOLE_SCRN_SHIFT_LEFT); //Shift cursor one step left instruction
	_delay_ms(0.5);
}

void HLCD_CUST_CHAR(u8 SLOT_NUM)//create custom character in CGRAM
{
	if (SLOT_NUM== HLCD_CUST_CHAR_1)
	{
		HLCD_Write_Data(ContREG,DataREG,0x00);
	}
	else if (SLOT_NUM== HLCD_CUST_CHAR_2)
	{
		HLCD_Write_Data(ContREG,DataREG,0x01);
	}
	else if (SLOT_NUM==HLCD_CUST_CHAR_3)
	{
		HLCD_Write_Data(ContREG,DataREG,0x02);
	}
	else if (SLOT_NUM==HLCD_CUST_CHAR_4)
	{
		HLCD_Write_Data(ContREG,DataREG,0x03);
	}
}

#elif (HLCD_MODE == HLCD_4BIT)
/*-------------4 BIT-----------------------------------------*/
void HLCD_Write_CMD_4BIT(u8 Cont_REG,u8 Data_REG,u8 DATA)
{
	
	MDIO_Write_Bit(Cont_REG,HLCD_RW,LOW) ;  //Set RW pin 0 (Write Mode selected)
	MDIO_Write_Bit(Cont_REG,HLCD_RS,LOW) ;  //Set RS pin 0 (Instruction register selected)
	//output first 4 bits instruction data to Data Bus
	for(u8 i=4;i<8;i++)
	{
		MDIO_Write_Bit(Data_REG,i,GET_BIT(DATA,i)); //Output value of Instruction bit i at Data Register DIO Pin i
	}
	//latch sent data
	MDIO_Write_Bit(Cont_REG,HLCD_EN,HIGH) ; //Set EN pin 1 (LCD Read data )
	_delay_ms(2);
	MDIO_Write_Bit(Cont_REG,HLCD_EN,LOW) ;  //Set EN pin 0 (LCD Write data to its reg)
	
	//output second 4 bits instruction to data bus
	for(u8 i=0;i<4;i++)
	{
		MDIO_Write_Bit(Data_REG,i+4,GET_BIT(DATA,i)); //Output value of Instruction bit i at Data Register DIO Pin i
	}
	//latch sent data
	MDIO_Write_Bit(Cont_REG,HLCD_EN,HIGH) ; //Set EN pin 1 (LCD Read data )
	_delay_ms(2);
	MDIO_Write_Bit(Cont_REG,HLCD_EN,LOW) ;  //Set EN pin 0 (LCD Write data to its reg)
}
void HLCD_Write_Data_4BIT(u8 Cont_REG,u8 Data_REG,u8 DATA)
{
	
	MDIO_Write_Bit(Cont_REG,HLCD_RW,LOW) ;  //Set RW pin 0 (Write Mode selected)
	MDIO_Write_Bit(Cont_REG,HLCD_RS,HIGH) ;  //Set RS pin 1 (Data register selected)
	//output first 4 Data bits to Data Bus
	for(u8 i=4;i<8;i++)
	{
		MDIO_Write_Bit(Data_REG,i,GET_BIT(DATA,i)); //Output value of Data bit i at Data register DIO Pin i
	}
	//latch sent data
	MDIO_Write_Bit(Cont_REG,HLCD_EN,HIGH) ; //Set EN pin 1 (LCD Read data )
	_delay_ms(2);
	MDIO_Write_Bit(Cont_REG,HLCD_EN,LOW) ;  //Set EN pin 0 (LCD Write data to its reg)
	
	//output second 4 bits Data to data bus
	for(u8 i=0;i<4;i++)
	{
		MDIO_Write_Bit(Data_REG,i+4,GET_BIT(DATA,i)); //Output value of Data bit i at Data register DIO Pin i
	}
	//latch sent data
	MDIO_Write_Bit(Cont_REG,HLCD_EN,HIGH) ; //Set EN pin 1 (LCD Read data )
	_delay_ms(2);
	MDIO_Write_Bit(Cont_REG,HLCD_EN,LOW) ;  //Set EN pin 0 (LCD Write data to its reg)
}
void HLCD_INIT_4BIT(void)
{
	MDIO_SetDirection_Bit(ContREG,HLCD_RS,OUTPUT);      //RS Pin o/p
	MDIO_SetDirection_Bit(ContREG,HLCD_RW,OUTPUT);      //RW Pin o/p
	MDIO_SetDirection_Bit(ContREG,HLCD_EN,OUTPUT);      //EN Pin o/p
	
	MDIO_SetDirection_Bit(DataREG,7,OUTPUT);            //Data register Pin 7 o/p
	MDIO_SetDirection_Bit(DataREG,6,OUTPUT);            //Data register Pin 6 o/p
	MDIO_SetDirection_Bit(DataREG,5,OUTPUT);            //Data register Pin 5 o/p
	MDIO_SetDirection_Bit(DataREG,4,OUTPUT);            //Data register Pin 4 o/p
	
	_delay_ms(50);
	HLCD_Write_CMD_4BIT(ContREG,DataREG,FN_SET_4BIT1);  //send 4BIT Function set instruction two times
	HLCD_Write_CMD(ContREG,DataREG,FN_SET_4BIT2);       //send Function set instruction for font and number of lines
	_delay_ms(1);
	HLCD_Write_CMD_4BIT(ContREG,DataREG,Disp_ON_OFF);   //send Display ON OFF instruction
	_delay_ms(1);
	HLCD_Write_CMD_4BIT(ContREG,DataREG,Disp_CLEAR);    //send Display clear instruction
	_delay_ms(2);
	HLCD_Write_CMD_4BIT(ContREG,DataREG,ENTRY_MODE);    //send ENTRY MODE set instruction
	_delay_ms(2);
	
	//put custom made character 1 in GCRAM 0x00
 	HLCD_Write_CMD_4BIT(ContREG,DataREG,0x40); 
	for (u8 i=0;i<8;i++)
	{
		HLCD_Write_Data_4BIT(ContREG,DataREG,CUST1[i]);
	}
	//put custom made character 2 in GCRAM 0x01
	for (u8 i=0;i<8;i++)
	{
		HLCD_Write_Data_4BIT(ContREG,DataREG,CUST2[i]);
	}
	//put custom made character 3 in GCRAM 0x02
	for (u8 i=0;i<8;i++)
	{
		HLCD_Write_Data_4BIT(ContREG,DataREG,CUST3[i]);
	}
	//put custom made character 1 in GCRAM 0x03
	for (u8 i=0;i<8;i++)
	{
		HLCD_Write_Data_4BIT(ContREG,DataREG,CUST4[i]);
	}
	//return to DDRAM address 1
	HLCD_Write_CMD_4BIT(ContREG,DataREG,DDRAM_ADD1); 
}

void HLCD_ClearLCD_4BIT(void) //clear LCD and return cursor to first position
{
	HLCD_Write_CMD_4BIT(ContREG,DataREG,Disp_CLEAR); //send Display clear instruction
	_delay_ms(1);
}
void HLCD_ReturnHome_4BIT(void) //return cursor to first position LCD content doesn't affect
{
	HLCD_Write_CMD_4BIT(ContREG,DataREG,RET_HOME); //send Return home instruction
	_delay_ms(1);
}

void HLCD_SEL_LINE_4BIT(u8 LINE) //Select line 1 or 2
{
	if (LINE==1)
	{
		HLCD_Write_CMD_4BIT(ContREG,DataREG,DDRAM_ADD1); //send set DDRAM address of line 1 instruction
	}
	else if(LINE==2)
	{
		HLCD_Write_CMD_4BIT(ContREG,DataREG,DDRAM_ADD2); //send set DDRAM address of line 2 instruction
	}
}
void HLCD_DisplayChar_4BIT(u8 Char_Data)
{
	if((Char_Data>=0)&&(Char_Data<10))
	{
		HLCD_Write_Data_4BIT(ContREG,DataREG,(Char_Data+'0')); //send Number to LCD
		_delay_ms(1);
	}
	else
	{
		HLCD_Write_Data_4BIT(ContREG,DataREG,Char_Data); //send Char to LCD
		_delay_ms(1);	
	}
}

void HLCD_DisplayStr_4BIT(u32 *Str_Data,u8 DataType) //Output String to LCD
{
	u8 *Local_u8StringData = (u8 *)Str_Data;
	
	u8  Local_u8Digit = 0;
	u32 Local_u32No = 0;
	u32 Local_u32Remainder =0;
	
	if (DataType == HLCD_NUMBER)
	{
		Local_u32No = *Str_Data;
		for (u8 i=0;i<10;i++)
		{
			if ((Local_u32No / L_u32GetExponential(10,(9-i))) != 0)
			{
				for (u8 j=i;j<10;j++)
				{
					Local_u32Remainder = Local_u32No % L_u32GetExponential(10,(9-j));
					Local_u8Digit      = Local_u32No / L_u32GetExponential(10,(9-j));
					Local_u32No = Local_u32Remainder;
					HLCD_DisplayChar_4BIT(Local_u8Digit);
				}
				break;
			}
		}
		if (Local_u32No == 0)
		{
			HLCD_DisplayChar_4BIT(Local_u8Digit);
		}	
	} 
	else if(DataType == HLCD_STRING)
	{
		while(*Local_u8StringData!='\0')//check if null char reached
		{
			HLCD_DisplayChar_4BIT(*Local_u8StringData++);
		}	
	}
}
void HLCD_ShiftRight_4BIT(void)//Shift all display right
{
	HLCD_Write_CMD_4BIT(ContREG,DataREG,DISP_SHIFT_RIGHT); //send shift right instruction
	_delay_ms(1);
}
void HLCD_ShiftLeft_4BIT(void)//Shift all display right
{
	HLCD_Write_CMD_4BIT(ContREG,DataREG,DISP_SHIFT_LEFT); //send shift left instruction
	_delay_ms(1);
}
void HLCD_Cursor_ONOFF_4BIT(u8 STATUS) //set cursor on & off
{
	if (STATUS==OFF)
	{
		HLCD_Write_CMD_4BIT(ContREG,DataREG,CURSOR_OFF); //send Display ON OFF instruction
	}
	else if(STATUS==ON)
	{
		HLCD_Write_CMD_4BIT(ContREG,DataREG,Disp_ON_OFF); //send Display ON OFF instruction
	}
	_delay_ms(1);
}
void HLCD_Blink_ONOFF_4BIT(u8 STATUS) //set cursor blink on & off
{
	if (STATUS==OFF)
	{
		HLCD_Write_CMD_4BIT(ContREG,DataREG,BLINK_OFF); //send Display ON OFF instruction
	}
	else if(STATUS==ON)
	{
		HLCD_Write_CMD_4BIT(ContREG,DataREG,Disp_ON_OFF); //send Display ON OFF instruction
	}
	_delay_ms(1);
}
void HLCD_Disp_ONOFF_4BIT(u8 STATUS) //set Whole display on & off
{
	if (STATUS==OFF)
	{
		HLCD_Write_CMD_4BIT(ContREG,DataREG,Disp_OFF); //send Display ON OFF instruction
	}
	else if(STATUS==ON)
	{
		HLCD_Write_CMD_4BIT(ContREG,DataREG,Disp_ON_OFF); //send Display ON OFF instruction
	}
	_delay_ms(1);
}
void HLCD_Cursor_ShiftRight_4BIT(u8 steps) //shift cursor one step right
{
	for (u8 i=0;i<steps;i++)
	{
		HLCD_Write_CMD_4BIT(ContREG,DataREG,CURSOR_SHIFT_RIGHT); //Shift cursor one step right instruction
		_delay_ms(0.5);
	}
}
void HLCD_Cursor_ShiftLeft_4BIT(u8 steps) //shift cursor one step left
{
	for (u8 i=0;i<steps;i++)
	{
		HLCD_Write_CMD_4BIT(ContREG,DataREG,CURSOR_SHIFT_LEFT); //Shift cursor one step right instruction
		_delay_ms(0.5);
	}
}
void HLCD_SET_CURSOR_4BIT(u8 LINE,u8 POSITION) //Set cursor in specific location
{
	u8 add=0;
	if (LINE==1)
	{
		add=(DDRAM_ADD1)+POSITION-1;
		HLCD_Write_CMD_4BIT(ContREG,DataREG,add); //send set DDRAM address of line 1 and specific position instruction
	}
	else if(LINE==2)
	{
		add=(DDRAM_ADD2)+POSITION-1;
		HLCD_Write_CMD_4BIT(ContREG,DataREG,add); //send set DDRAM address of line 1 and specific position instruction
	}
}

void HLCD_EN_SCRN_ShiftRight_4BIT(void) //Shift all display right out of screen
{
	HLCD_Write_CMD(ContREG,DataREG,WHOLE_SCRN_SHIFT_RIGHT); //Shift cursor one step left instruction
	_delay_ms(0.5);
}

void HLCD_EN_SCRN_ShiftLeft_4BIT(void) //Shift all display Left out of screen
{
	HLCD_Write_CMD(ContREG,DataREG,WHOLE_SCRN_SHIFT_LEFT); //Shift cursor one step left instruction
	_delay_ms(0.5);
}

void HLCD_CUST_CHAR_4BIT(u8 SLOT_NUM)//create custom character in CGRAM
{
	if (SLOT_NUM== HLCD_CUST_CHAR_1)
	{
		HLCD_Write_Data_4BIT(ContREG,DataREG,0x00);
	}
	else if (SLOT_NUM== HLCD_CUST_CHAR_2)
	{
		HLCD_Write_Data_4BIT(ContREG,DataREG,0x01);
	}
	else if (SLOT_NUM==HLCD_CUST_CHAR_3)
	{
		HLCD_Write_Data_4BIT(ContREG,DataREG,0x02);
	}
	else if (SLOT_NUM==HLCD_CUST_CHAR_4)
	{
		HLCD_Write_Data_4BIT(ContREG,DataREG,0x03);
	}
}

#endif