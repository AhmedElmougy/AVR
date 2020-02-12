/*
 * File        : MUART_Private.h
 * Description : This File includes UART Driver private macros and declarations for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 12/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#ifndef __MUART_PRIVATE_H__
#define __MUART_PRIVATE_H__

/*=================================================================================
 * UART Registers
 *=================================================================================*/
#define MUART_UDR    (*(volatile u8 *)(0x2C)) 
#define MUART_UCSRA  (*(volatile u8 *)(0x2B)) 
#define MUART_UCSRB  (*(volatile u8 *)(0x2A)) 
#define MUART_UCSRC  (*(volatile u8 *)(0x40)) 
#define MUART_UBRRL  (*(volatile u8 *)(0x29)) 
#define MUART_UBRRH  (*(volatile u8 *)(0x40)) 

/*=================================================================================
 * UART Registers Pins
 *=================================================================================*/
/*UCSRA Register*/
#define MUART_RXC                 7 
#define MUART_TXC                 6
#define MUART_UDRE                5
#define MUART_FE                  4
#define MUART_DOR                 3  
#define MUART_PE                  2		  
#define MUART_U2x                 1
#define MUART_MPCM                0

/*UCSRB Register*/
#define MUART_RXCIE               7
#define MUART_TXCIE               6
#define MUART_UDRIE               5
#define MUART_RXEN                4
#define MUART_TXEN                3
#define MUART_UCSZ2               2
#define MUART_RXB8                1
#define MUART_TXB8                0	

/*UCSRC Register*/
#define MUART_URSEL               7
#define MUART_UMSEL               6
#define MUART_UPM1                5
#define MUART_UPM0                4
#define MUART_USBS                3
#define MUART_UCSZ1               2
#define MUART_UCSZ0               1
#define MUART_UCPOL               0

/*=================================================================================
 * Config macros
 *=================================================================================*/
#define MUART_DISABLED            0
#define MUART_ENABLED             1

#define MUART_ASYNCHRONOUS        0
#define MUART_SYNCHRONOUS         1

#define MUART_EVEN_PARITY         2
#define MUART_ODD_PARITY          3

#define MUART_1_STOP_BIT          0
#define MUART_2_STOP_BIT          1

#define MUART_5_BITS              0
#define MUART_6_BITS              1
#define MUART_7_BITS              2
#define MUART_8_BITS              3
#define MUART_9_BITS              7

#define MUART_BAUDRATE_2400       207
#define MUART_BAUDRATE_4800       103
#define MUART_BAUDRATE_9600       51

#define MUART_SAMPLE_FALLING_EDGE 0
#define MUART_SAMPLE_RISING_EDGE  1


#endif