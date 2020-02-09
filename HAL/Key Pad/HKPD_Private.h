/*
 * File        : HKPD_Private.h
 * Description : This File includes Keypad Driver private macros and declarations for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 9/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */ 
 

#ifndef __HKPD_Private_h__
#define __HKPD_Private_h__

/*private macros*/
#define UNDEFINED_PORT_ERROR      1
#define UNDEFINED_BIT_ERROR       2
#define UNDEFINED_COL_BIT_ERROR   2
#define UNDEFINED_ROW_BIT_ERROR   3

/*column array pins that stores each column pin number*/
u8 HKPD_u8ColumnArray[4] = {C1,C2,C3,C4};
/*Row array pins that stores each Row pin number*/
u8 HKPD_u8RowArray[4]    = {R1,R2,R3,R4};

#endif

/*===================================================================
 * EOF
 *===================================================================*/