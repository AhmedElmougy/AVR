#include "LSTD_Types.h"
#include "MTIMER0_Interface.h"
#include "OS_Private.h"
#include "OS_Interface.h"
#include "OS_Config.h"

Task SysTasks[NO_OF_TASKS] = {0};
//u32  Tick_Count = 0;



void OS_Init(void)
{
	MTIMER0_voidINIT();
}
void OS_Start(void)
{
	MTIMER0_voidSetDesiredTime_ms(OS_TICK_TIME);
}
void OS_Scheduler(void)
{
	//Tick_Count++;
    for (u32 i = 0; i < NO_OF_TASKS; i++)
    {
		if(SysTasks[i].Periodicity != 0)/*Task Exists*/
		{
			if(SysTasks[i].State == OS_TASK_READY)/*if Task is running not suspended*/
			{
				SysTasks[i].FirstDelay-- ;
				if (SysTasks[i].FirstDelay == 0)
				{
					(SysTasks[i].TaskHandler)(); //Run task
					SysTasks[i].FirstDelay = SysTasks[i].Periodicity; 
				}
			}	
		}
		/*
		*Code before applying First delay concept
        if((Tick_Count % SysTasks[i].Periodicity)==0)
        {
            (SysTasks[i].TaskHandler)();
        }
		*/
    }	
}
u8 OS_CreateTask(void(*Copy_TaskHandler)(void), u32 Copy_Periodicity, u32 Copy_Priority, u32 Copy_State, u32 Copy_FirstDelay)
{
	if ((SysTasks[Copy_Priority].Periodicity) == 0) /*if queue slot is available*/
	{
		if(Copy_Priority<NO_OF_TASKS)
		{
			SysTasks[Copy_Priority].Periodicity = Copy_Periodicity;
			SysTasks[Copy_Priority].TaskHandler = Copy_TaskHandler;
			SysTasks[Copy_Priority].FirstDelay  = Copy_FirstDelay;
			SysTasks[Copy_Priority].State       = Copy_State;
			return 0; // operation is OK
		}
		else
		{
			/*Report queue slot is out of range*/
			return 1; //Slot out of range
		}
	}
	else
	{
		/*Report queue slot is not available*/
		return 2; //slot not available
	}
}
u8 OS_DeleteTask(u32 Copy_Priority)
{
	if(Copy_Priority<NO_OF_TASKS)
	{
		SysTasks[Copy_Priority].Periodicity = 0;
		return 0; //operation is OK	
	}
	else
	{
		/*Report task to delete is out of range*/
		return 1; //operation is not OK
	}
}
u8 OS_SuspendTask(u32 Copy_Priority)
{
	if(Copy_Priority<NO_OF_TASKS)
	{
		SysTasks[Copy_Priority].State = OS_TASK_SUSPENDED;
		return 0; //operation is OK	
	}
	else
	{
		/*Report task to Suspend is out of range*/
		return 1; //operation is not OK
	}	
}
u8 OS_ResumeTask(u32 Copy_Priority)
{
	if(Copy_Priority<NO_OF_TASKS)
	{
		SysTasks[Copy_Priority].State = OS_TASK_READY;
		return 0; //operation is OK
	}
	else
	{
		/*Report task to Resume is out of range*/
		return 1; //operation is Not OK
	}
}