#ifndef __MTIMER0_Config_H__
#define __MTIMER0_Config_H__

//MCU Clock frequency
#define MTIMER0_F_CPU           8000000
/*Choose prescaler from 
 *No_Prescaller - Prescaller_8 - Prescaller_64 - Prescaller_256 - 
 *Prescaller_1024 - Prescaller_FalExtClk - Prescaller_RaisExtClk
 * Prescaller_FalExtClk - Prescaller_RaisExtClk these two options are used with counter option
*/
#define MTIMER0_PRESCALER       Prescaller_8
/*
*Choose from Modes :
*MTIMER0_NORMAL_MODE - MTIMER0_CTC_MODE - MTIMER0_FAST_PWM_MODE - MTIMER0_PHASE_CORCT_MODE  
*/
#define MTIMER0_MODE            MTIMER0_NORMAL_MODE
//Initial Timer state Enable Or disabled
#define MTIMER0_INITIAL_STATE   MTIMER0_DISABLED
//Initial OCR value with CTC Mode (Only)
#define MTIMER0_T_OCR           1        

#endif