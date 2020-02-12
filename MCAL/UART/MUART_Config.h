/*
 * File        : MUART_Config.h
 * Description : This file includes UART configuration definitions for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 12/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#ifndef __MUART_CONFIG_H__
#define __MUART_CONFIG_H__

/*
 * Baud rate config (MUART_BAUDRATE_2400,MUART_BAUDRATE_4800,MUART_BAUDRATE_9600)
 */
 #define MUART_BAUD_RATE               MUART_BAUDRATE_9600

/*
 * Receive enable config (MUART_DISABLED - MUART_ENABLED)
 */
 #define MUART_RIECEVE_ENABLE          MUART_ENABLED

/*
 * Send enable config (MUART_DISABLED - MUART_ENABLED)
 */
 #define MUART_SEND_ENABLE             MUART_ENABLED

/*
 * Mode select config (MUART_ASYNCHRONOUS - MUART_SYNCHRONOUS)
 */
 #define MUART_MODE_SELECT             MUART_ASYNCHRONOUS

/*
 * Character size config (MUART_5_BITS,MUART_6_BITS,MUART_7_BITS,MUART_8_BITS,MUART_9_BITS)
 */
 #define MUART_CHAR_SIZE               MUART_8_BITS

/*
 * receive interrupt enable config (MUART_DISABLED - MUART_ENABLED)
 */
 #define MUART_RX_INTERRUPT_ENABLE     MUART_DISABLED

/*
 * Send interrupt enable config (MUART_DISABLED - MUART_ENABLED)
 */
 #define MUART_TX_INTERRUPT_ENABLE     MUART_DISABLED

/*
 * UDR empty interrupt enable config (MUART_DISABLED - MUART_ENABLED)
 */
 #define MUART_UDR_INTERRUPT_ENABLE    MUART_DISABLED

/*
 * Parity Mode enable config (MUART_DISABLED,MUART_EVEN_PARITY,MUART_ODD_PARITY)
 */
 #define MUART_PARITY_MODE             MUART_DISABLED

/*
 * Number of stop bits config (MUART_1_STOP_BIT - MUART_2_STOP_BIT)
 */
 #define MUART_STOP_BIT_NO             MUART_1_STOP_BIT

/*
 * Clock polarity config (MUART_SAMPLE_FALLING_EDGE,MUART_SAMPLE_RISING_EDGE)
 */
 #define MUART_CLOCK_POLARITY          MUART_SAMPLE_FALLING_EDGE

#endif