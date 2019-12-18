#ifndef _OS_PRIVATE_H_
#define _OS_PRIVATE_H_

typedef struct 
{
    void(*TaskHandler)(void);
    u32 Periodicity;
	u32 FirstDelay;
	u8  State ;
}Task;


#endif