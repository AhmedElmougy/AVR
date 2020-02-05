/*
 * File        : LDELAY_Program.c
 * Description : This file includes delay service implementations for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 23/6/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#include "LSTD_Types.h"
#include "LDELAY_Interface.h"
#include "LDELAY_Private.h"



/* 
 * Prototype   : void LDelay_voidDelay_ms(u32 Copy_u32Time_ms);
 * Description : create time delay in milliseconds
 * Arguments   : time in milliseconds                   
 * return      : void  
 */
void LDelay_voidDelay_ms(u32 Copy_u32Time_ms)
{
	/*calculate net time(minus time spent in calculation processing)*/
	Copy_u32Time_ms = (Copy_u32Time_ms * 100000)-(LDELAY_CalculationTime + LDELAY_ContextSwitch);
	/*calculate number of iterations in busy loop*/
	u32 Local_u32NoLoops = Copy_u32Time_ms/LDELAY_LoopTime;
	
	/*crate busy loop*/
	for(u32 i=0;i<Local_u32NoLoops;i++)
	{
		/*no operation assembly line*/
		asm("NOP");
	}/*end of busy loop*/
	
}/*end of LDelay_voidDelay_ms()*/

/* 
 * Prototype   : void LDelay_voidDelay_ms(u32 Copy_u32Time_ms);
 * Description : create time delay in microseconds
 * Arguments   : time in microseconds                   
 * return      : void  
 */
void LDelay_voidDelay_us(u32 Copy_u32Time_us)
{
	/*calculate net time(minus time spent in calculation processing)*/
	Copy_u32Time_us = (Copy_u32Time_us * 100) - LDELAY_CalculationTime - LDELAY_ContextSwitch;
	/*calculate number of iterations in busy loop*/
	u32 Local_u32NoLoops = Copy_u32Time_us / LDELAY_LoopTime;
	/*crate busy loop*/
	for(u32 i=0;i<Local_u32NoLoops;i++)
	{
		/*no operation assembly line*/
		asm("NOP");
		
	}/*end of LDelay_voidDelay_us()*/
	
}/*end of LDelay_voidDelay_us()*/

/*==============================================================================================================================================
 * EOF 
 *==============================================================================================================================================*/