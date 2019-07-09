#ifndef __MEXTI_Interface_h__
#define __MEXTI_Interface_h__

void __vector_1 (void) __attribute__ ((signal,__INTR_ATTRS));
void __vector_2 (void) __attribute__ ((signal,__INTR_ATTRS));
void __vector_3 (void) __attribute__ ((signal,__INTR_ATTRS));


//Interrupt modes
#define MEXTI_LOW_SGNL  1
#define MEXTI_LOG_CHNG  2
#define MEXTI_FAL_EDGE  3
#define MEXTI_RAIS_EDGE 4

//Interrupt names
#define MEXTI_INT0 6
#define MEXTI_INT1 7
#define MEXTI_INT2 5


void MEXTI_EN(u8 INT,u8 MODE);    //Enable specific interrupt 
void MEXTI_DISBL(u8 INT);         //Disable specific interrupt

u8 MEXTI_ChechIntFlag(u8 INT);    //check if  specific interrupt flag is up

void MEXTI_FnCallBack_INT0(void(*ptr)(void)); //send function to INT0 routine
void MEXTI_FnCallBack_INT1(void(*ptr)(void)); //send function to INT1 routine
void MEXTI_FnCallBack_INT2(void(*ptr)(void)); //send function to INT2 routine

#endif