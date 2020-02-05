/*
 * File        : LDELAY_Interface.h
 * Description : This interface file includes delay service prototypes and definitions for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 23/6/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#ifndef __LDELAY_INTERFACE_H__
#define __LDELAY_INTERFACE_H__


/* 
 * Prototype   : void LDelay_voidDelay_ms(u32 Copy_u32Time_ms);
 * Description : create time delay in milliseconds
 * Arguments   : time in milliseconds                   
 * return      : void  
 */
void LDelay_voidDelay_ms(u32 Copy_u32Time_ms);

/* 
 * Prototype   : void LDelay_voidDelay_ms(u32 Copy_u32Time_ms);
 * Description : create time delay in microseconds
 * Arguments   : time in microseconds                   
 * return      : void  
 */
void LDelay_voidDelay_us(u32 Copy_u32Time_us); 
 
#endif

/*==============================================================================================================================================
 * EOF 
 *==============================================================================================================================================*/