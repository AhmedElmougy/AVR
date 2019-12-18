#ifndef _OS_INTERFACE_H_
#define _OS_INTERFACE_H_

/*
 *Task Initial States
 */
#define OS_TASK_SUSPENDED  0
#define OS_TASK_READY      1

void OS_Init(void);
void OS_Start(void);
void OS_Scheduler(void);
u8   OS_CreateTask(void(*Copy_TaskHandler)(void), u32 Copy_Periodicity, u32 Copy_Priority, u32 Copy_State, u32 Copy_FirstDelay);
u8   OS_DeleteTask(u32 Copy_Priority);
u8   OS_SuspendTask(u32 Copy_Priority);
u8   OS_ResumeTask(u32 Copy_Priority);

#endif