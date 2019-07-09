#ifndef __MTIMER0_INTERFACE_H__
#define __MTIMER0_INTERFACE_H__


//-----------------------------------------
//OC0 Non PWM Modes
#define MTIMER0_DISCONNECT_OC0      0
#define MTIMER0_TOGGLE_OC0          1
#define MTIMER0_CLEAR_OC0           2
#define MTIMER0_SET_OC0             3
//OC0 PWM Modes
#define MTIMER0_DISCONNECT_OC0      0
#define MTIMER0_PWM_NONINVERTED_OC0 2
#define MTIMER0_PWM_INVERTED_OC0    3

//----------------------------------------------------------------
//APIs
void MTIMER0_voidINIT(void);   //Initialize Timer0
/*
 *the following APIs is used only in normal mode
 */
#if MTIMER0_MODE == MTIMER0_NORMAL_MODE
void MTIMER0_voidSetDesiredTime_ms(u32 Copy_Time_ms);
void MTIMER0_voidSetDesiredTime_us(u32 Copy_Time_us);
void MTIMER0_voidOverFlowCallBack(void(*Copy_Ptr)(void));
void MTIMER0_voidSWPWM(u8 Copy_u16PWMDutyCycle,u32 Copy_u32Frequency);
void MTIMER0_voidSWPWMCallBack(void(*Copy_Ptr)(void));
#endif
#if MTIMER0_MODE == MTIMER0_FAST_PWM_MODE
void MTIMER0_voidFastPWM(u8 Copy_u8DutyCycle,u8 Copy_u8PWMMode);
#endif
#if MTIMER0_MODE == MTIMER0_PHASE_CORCT_MODE
void MTIMER0_voidPhaseCorrectPWM(u8 Copy_u8DutyCycle,u8 Copy_u8PWMMode);
#endif

void MTIMER0_voidStartTimer(void);
void MTIMER0_voidStopTimer(void);





#endif