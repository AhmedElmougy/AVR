/*
 * File        : OS_Program.c
 * Description : This file includes OS Service modules implementations
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 18/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#include "LSTD_Types.h"
#include "MTIMER0_Interface.h"
#include "OS_Private.h"
#include "OS_Interface.h"
#include "OS_Config.h"

/*=================================================================================*
 * Global Variables
 *=================================================================================*/
Task SysTasks[NO_OF_TASKS] = {0};

/*
 * No first delay concept implementation
 * u32  Tick_Count = 0;
 */




/* 
 * Prototype   : void OS_voidInitializeOS(void);
 * Description : initialize OS (Sys tick of Timer0) with pre configured Timer0 config parameters 
 * Arguments   : void
 * return      : void  
 */
 void OS_voidInitializeOS(void)
 {
	 /*Initialize Timer 0*/
	 MTIMER0_voidInitializeTimer0();

 }/*end of OS_voidInitializeOS()*/

/* 
 * Prototype   : void OS_voidStartOS(void);
 * Description : Start  OS Sys tick  
 * Arguments   : void
 * return      : void  
 */
 void OS_voidStartOS(void)
 {
	 /*Start Timer0 and enter Timer0 ISR every Tick time*/
	 MTIMER0_voidSetDesiredTime_ms(OS_TICK_TIME);
 
 }/*end of OS_voidStartOS()*/
 
/* 
 * Prototype   : u8   OS_voidCreateTask(void(*Copy_TaskHandler)(void), u32 Copy_u32Periodicity, u32 Copy_32Priority, u32 Copy_32State, u32 Copy_32FirstDelay);
 * Description : Create task in task queue 
 * Arguments   : TaskHandler      : pointer to task code  
 *				 Task Periodicity : task periodicity in ticks 
 *				 Task Priority    : task priority in task queue
 *				 Task State		  : task state (OS_TASK_SUSPENDED , OS_TASK_READY)
 *				 Task FirstDelay  : task first delay in ticks 
 * return      : u8 variable for error handling  
 */
 u8   OS_voidCreateTask(void(*Copy_TaskHandler)(void), u32 Copy_u32Periodicity, u32 Copy_u32Priority, u32 Copy_u32State, u32 Copy_u32FirstDelay)
 {
	 /*if queue slot is available*/
	 if ((SysTasks[Copy_u32Priority].Periodicity) == 0) 
	 {
		 /*if task priority in range*/
		 if(Copy_u32Priority<NO_OF_TASKS)
		 {
			 SysTasks[Copy_u32Priority].Periodicity = Copy_u32Periodicity;
			 SysTasks[Copy_u32Priority].TaskHandler = Copy_TaskHandler;
			 SysTasks[Copy_u32Priority].FirstDelay  = Copy_u32FirstDelay;
			 SysTasks[Copy_u32Priority].State       = Copy_u32State;
			 return 0; /* operation is OK*/
		 }
		 else
		 {
			 /*Report queue slot is out of range*/
			 return 1; 
		 
		 }/*end of priority check*/
	 }
	 else
	 {
		 /*Report queue slot is not available*/
		 return 2; 
	 
	 }/*end of queue slot availability check*/
 
 }/*end of OS_voidCreateTask*/

/* 
 * Prototype   : u8   OS_u8DeleteTask(u32 Copy_32Priority);
 * Description : remove task from task queue  
 * Arguments   : Task priority in task queue
 * return      : u8 variable for error handling   
 */
 u8   OS_u8DeleteTask(u32 Copy_u32Priority)
 {
	 /*task priority in range check*/
	 if(Copy_u32Priority<NO_OF_TASKS)
	 {
		 /*Delete task*/
		 SysTasks[Copy_u32Priority].Periodicity = 0;
		 return 0; /*operation is OK*/
	 }
	 else
	 {
		 /*Report task to delete is out of range*/
		 return 1; /*operation is not OK*/
	 
	 }/*end of priority check*/
 
 }/*end of OS_u8DeleteTask()*/

/* 
 * Prototype   : u8   OS_u8SuspendTask(u32 Copy_u32Priority);
 * Description : suspend task execution (task still in queue but not active)  
 * Arguments   : Task priority in task queue
 * return      : u8 variable for error handling 
 */
 u8   OS_u8SuspendTask(u32 Copy_u32Priority)
 {
	 /*task priority in range check*/
	 if(Copy_u32Priority<NO_OF_TASKS)
	 {
		 /*suspend task*/
		 SysTasks[Copy_u32Priority].State = OS_TASK_SUSPENDED;
		 return 0; /*operation is OK*/
	 }
	 else
	 {
		 /*Report task to Suspend is out of range*/
		 return 1; /*operation is not OK*/
	 
	 }/*end of priority check*/
 
 }/*end of OS_u8SuspendTask()*/

/* 
 * Prototype   : void OS_voidStartOS(void);
 * Description : resume task execution (make task active again)    
 * Arguments   : Task priority in task queue
 * return      : u8 variable for error handling 
 */
 u8   OS_u8ResumeTask(u32 Copy_u32Priority)
 {
	 /*task priority in range check*/
	 if(Copy_u32Priority<NO_OF_TASKS)
	 {
		 /*Resume task execution*/
		 SysTasks[Copy_u32Priority].State = OS_TASK_READY;
		 return 0; /*operation is OK*/
	 }
	 else
	 {
		 /*Report task to Resume is out of range*/
		 return 1; /*operation is Not OK*/
	 
	 }/*end of priority check*/
 
 }/*end of OS_u8ResumeTask()*/

/* 
 * Prototype   : void OS_voidScheduler(void);
 * Description : scheduler algorithm    
 * Arguments   : void
 * return      : void 
 */
 void OS_voidScheduler(void)
 {
	 /*Code before applying First delay concept*/
 	 /*Tick_Count++;*/
	  
	 /*Loop all tasks in queue*/
     for (u32 i = 0; i < NO_OF_TASKS; i++)
     {
		 /*Task exists check*/
		 if(SysTasks[i].Periodicity != 0)
		 {
			 /*Check task state*/
			 if(SysTasks[i].State == OS_TASK_READY)/*if Task is running not suspended*/
			 {
				 /*decrement task first delay*/
				 SysTasks[i].FirstDelay-- ;
				 /*when it reaches 0 task time to execute*/
				 if (SysTasks[i].FirstDelay == 0)
				 {
					 /*execute task using task handler*/
					 (SysTasks[i].TaskHandler)(); 
					 /*Reinitialize task first delay again*/
					 SysTasks[i].FirstDelay = SysTasks[i].Periodicity; 
				 
				 }/*end  of first delay zero check */
			 
			 }/*end of task state check*/	
		 
		 }/*end of task exists check*/
		 
		 /*
		    Code before applying First delay concept
            if((Tick_Count % SysTasks[i].Periodicity)==0)
            {
               (SysTasks[i].TaskHandler)();
            }
		  */
		 
     }/*end of task queue loop*/	
 
 }/*end of OS_voidScheduler()*/



/*=================================================================================*
 * EOF
 *=================================================================================*/
