/*
 * File        : OS_Interface.h
 * Description : This interface file includes OS Service prototypes and definitions
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 18/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#ifndef _OS_INTERFACE_H_
#define _OS_INTERFACE_H_

/*
 *Task Initial States
 */
#define OS_TASK_SUSPENDED  0
#define OS_TASK_READY      1


/* 
 * Prototype   : void OS_voidInitializeOS(void);
 * Description : initialize OS (Sys tick of Timer0) with pre configured Timer0 config parameters 
 * Arguments   : void
 * return      : void  
 */
 void OS_voidInitializeOS(void);

/* 
 * Prototype   : void OS_voidStartOS(void);
 * Description : Start  OS Sys tick  
 * Arguments   : void
 * return      : void  
 */
 void OS_voidStartOS(void);
 
/* 
 * Prototype   : u8   OS_voidCreateTask(void(*Copy_TaskHandler)(void), u32 Copy_u32Periodicity, u32 Copy_32Priority, u32 Copy_u32State, u32 Copy_u32FirstDelay);
 * Description : Create task in task queue 
 * Arguments   : TaskHandler      : pointer to task code  
 *				 Task Periodicity : task periodicity in ticks 
 *				 Task Priority    : task priority in task queue
 *				 Task State		  : task state (OS_TASK_SUSPENDED , OS_TASK_READY)
 *				 Task FirstDelay  : task first delay in ticks 
 * return      : u8 variable for error handling  
 */
 u8   OS_voidCreateTask(void(*Copy_TaskHandler)(void), u32 Copy_u32Periodicity, u32 Copy_u32Priority, u32 Copy_u32State, u32 Copy_u32FirstDelay);

/* 
 * Prototype   : u8   OS_u8DeleteTask(u32 Copy_32Priority);
 * Description : remove task from task queue  
 * Arguments   : Task priority in task queue
 * return      : u8 variable for error handling   
 */
 u8   OS_u8DeleteTask(u32 Copy_u32Priority);

/* 
 * Prototype   : u8   OS_u8SuspendTask(u32 Copy_u32Priority);
 * Description : suspend task execution (task still in queue but not active)  
 * Arguments   : Task priority in task queue
 * return      : u8 variable for error handling 
 */
 u8   OS_u8SuspendTask(u32 Copy_u32Priority);

/* 
 * Prototype   : void OS_voidStartOS(void);
 * Description : resume task execution (make task active again)    
 * Arguments   : Task priority in task queue
 * return      : u8 variable for error handling 
 */
 u8   OS_u8ResumeTask(u32 Copy_u32Priority);
 
 
 /* 
 * Prototype   : void OS_voidScheduler(void);
 * Description : scheduler algorithm    
 * Arguments   : void
 * return      : void 
 */
 void OS_voidScheduler(void);

#endif


/*=================================================================================*
 * EOF
 *=================================================================================*/
