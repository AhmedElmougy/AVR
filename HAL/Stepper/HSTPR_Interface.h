#ifndef __HSTPER_INTERFACE_H__
#define __HSTPER_INTERFACE_H__

#define HSTPR_PORT PORTA

void HSTPR_INIT(void);
void HSTPR_FullStep_Right(u8 speed);
void HSTPR_FullStep_Left(u8 speed);
void HSTPR_HalfStep_Right(u8 speed);
void HSTPR_HalfStep_Left(u8 speed);
void HSTPR_Stop(void);

#endif