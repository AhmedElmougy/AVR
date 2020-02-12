/*
 * File        : MUART_Interface.h
 * Description : This interface file includes UART Driver prototypes and definitions for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 12/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#ifndef __MUART_INTERFACE_H__
#define __MUART_INTERFACE_H__


/* 
 * Prototype   : void MUART_voidInitializeUART(void);
 * Description : initialize UART with pre configured parameter
 * Arguments   : void
 * return      : void  
 */
 void MUART_voidInitializeUART(void);

/* 
 * Prototype   : void MUART_voidSendByteSynch(u8 Copy_u8Byte);
 * Description : send 1 byte over UART
 * Arguments   : void
 * return      : void  
 */
 void MUART_voidSendByteSynch(u8 Copy_u8Byte);

/* 
 * Prototype   : u8 MUART_voidRecieveByteSynch(u16 Copy_u16Timeout);
 * Description : synchronous function that receive 1 byte over UART with desired timeout  
 * Arguments   : u16 timeout 
 * return      : u8 received byte  
 */
 u8 MUART_voidRecieveByteSynch(u16 Copy_u16Timeout);


#endif