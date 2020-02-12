/*
 * File        : MUART_Program.c
 * Description : This file includes UART Driver implementations for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 12/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#include "LSTD_Types.h"
#include "LUTILS.h"
#include "MUART_Private.h"
#include "MUART_Interface.h"
#include "MUART_Config.h"

/*==============================================================================================================================================
 * Global Variables
 *==============================================================================================================================================*/
u8 MUART_u8UCSRC_Value =0;


/*==============================================================================================================================================
 * Driver Modules implementations
 *==============================================================================================================================================*/

/* 
 * Prototype   : void MUART_voidInitializeUART(void);
 * Description : initialize UART with pre configured parameter
 * Arguments   : void
 * return      : void  
 */
 void MUART_voidInitializeUART(void)
 {
	 /*Receive enable config*/
	 L_UTILS_SET_BIT_VALUE(MUART_UCSRB,MUART_RXEN,MUART_RIECEVE_ENABLE);
	
	 /*Send enable config*/
	 L_UTILS_SET_BIT_VALUE(MUART_UCSRB,MUART_TXEN,MUART_SEND_ENABLE);
	
	 /*Send interrupt enable config*/
	 L_UTILS_SET_BIT_VALUE(MUART_UCSRB,MUART_TXCIE,MUART_TX_INTERRUPT_ENABLE);
	
	 /*Receive interrupt enable config*/
	 L_UTILS_SET_BIT_VALUE(MUART_UCSRB,MUART_RXCIE,MUART_RX_INTERRUPT_ENABLE);
	 
	 /*UDR empty interrupt enable config*/
	 L_UTILS_SET_BIT_VALUE(MUART_UCSRB,MUART_UDRIE,MUART_UDR_INTERRUPT_ENABLE);
	
	 /*Mode config (Asynchronous-Synchronous)*/
	 L_UTILS_SET_BIT_VALUE(MUART_u8UCSRC_Value,MUART_UMSEL,MUART_MODE_SELECT);
	
	 /*Parity Mode config*/
	 MUART_u8UCSRC_Value|=(MUART_PARITY_MODE<<4);
	 
	 /*Clock polarity config*/
	 L_UTILS_SET_BIT_VALUE(MUART_u8UCSRC_Value,MUART_UCPOL,MUART_CLOCK_POLARITY);
	 
	 /*Stop Bits config*/
	 L_UTILS_SET_BIT_VALUE(MUART_u8UCSRC_Value,MUART_USBS,MUART_STOP_BIT_NO);
	 
	 /*Character size config*/
	 if (MUART_CHAR_SIZE != MUART_9_BITS)
	 {
		 /*config char size(5,6,7,8)*/
		 MUART_u8UCSRC_Value |= (MUART_CHAR_SIZE<<1);
	 } 
	 else if (MUART_CHAR_SIZE == MUART_9_BITS)
	 {
		 /*9 bit Mode*/
		 MUART_u8UCSRC_Value |= (MUART_8_BITS<<1);
		 L_UTILS_SET_BIT(MUART_UCSRB,MUART_UCSZ2);
	 
	 }/*end of char size check*/
	 
	 /*Load configuration values in UCSrC Register*/
	 /*Set URSEL to access UCSRC Reg*/
	 L_UTILS_SET_BIT(MUART_u8UCSRC_Value,7);
	 /*Load value of UCSRC*/
	 MUART_UCSRC = MUART_u8UCSRC_Value ;
	 
	 /*Baud Rate Value Config*/
	 MUART_UBRRH = 0;
	 MUART_UBRRL = MUART_BAUD_RATE;
	
 }/*end of MUART_voidInitializeUART()*/
 
/* 
 * Prototype   : void MUART_voidSendByteSynch(u8 Copy_u8Byte);
 * Description : send 1 byte over UART
 * Arguments   : void
 * return      : void  
 */
 void MUART_voidSendByteSynch(u8 Copy_u8Byte)
 {
	 /*wait while previous sending is complete*/
	 while ((L_UTILS_GET_BIT(MUART_UCSRA,MUART_UDRE))==0);
	 /*send byte*/
	 MUART_UDR = Copy_u8Byte;
 
 }/*end of MUART_voidSendByteSynch()*/

/* 
 * Prototype   : u8 MUART_voidRecieveByteSynch(u16 Copy_u16Timeout);
 * Description : synchronous function that receive 1 byte over UART with desired timeout  
 * Arguments   : u16 timeout 
 * return      : u8 received byte  
 */
 u8 MUART_voidRecieveByteSynch(u16 Copy_u16Timeout)
 {
	 /*wait for incoming byte for Timeout period*/
	 do
	 {
		 /*if a byte received return received byte*/
		 if ( (L_UTILS_GET_BIT(MUART_UCSRA,MUART_RXC)) == 1) return MUART_UDR;
		 
	 }while(--Copy_u16Timeout);
	 
	 /*if no data received return 0*/
	 return 0;
	 
 }/*end of MUART_voidRecieveByteSynch()*/

