#include "LSTD_Types.h"
#include "LDELAY_Interface.h"
#include "LDELAY_Private.h"


void LDelay_voidms(u32 Copy_u32Time_ms)
{
	
	Copy_u32Time_ms = (Copy_u32Time_ms * 100000)-(LDELAY_CalculationTime + LDELAY_ContextSwitch);
	u32 Local_u32NoLoops = Copy_u32Time_ms/LDELAY_LoopTime;
	for(u32 i=0;i<Local_u32NoLoops;i++)
	{
		asm("NOP");
	}
	
}

void LDelay_voidus(u32 Copy_u32Time_us)
{
	Copy_u32Time_us = Copy_u32Time_us-(LDELAY_CalculationTime/1000)-(LDELAY_ContextSwitch/1000);
	u32 Local_u32NoLoops = (Copy_u32Time_us*1000)/LDELAY_LoopTime;
	for(u32 i=0;i<Local_u32NoLoops;i++)
	{
		asm("NOP");
	}
}