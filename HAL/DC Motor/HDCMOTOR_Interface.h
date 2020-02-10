/*
 * File        : HDCMOTOR_Interface.h
 * Description : This interface file includes DC MOTOR Driver prototypes and definitions for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 10/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */


#ifndef __HDCMOTOR_Interface_H__
#define __HDCMOTOR_Interface_H__


/*Motor number macros*/
#define HDCMOTOR_MOTOR1			1
#define HDCMOTOR_MOTOR2			2
#define HDCMOTOR_MOTOR3			3
#define HDCMOTOR_MOTOR4			4
#define HDCMOTOR_MOTOR5			5
#define HDCMOTOR_MOTOR6			6
#define HDCMOTOR_MOTOR7			7
#define HDCMOTOR_MOTOR8			8

/*==============================================================================================================================================
 * Public Modules
 *==============================================================================================================================================*/
 /* 
 * Prototype   : void HDCMOTOR_voidInitializeMotor(u8 Copy_u8MotorNumber,u8 Copy_u8ControlType);;
 * Description : initialize chosen motor
 * Arguments   : void
 * return      : void  
 */
 void HDCMOTOR_voidInitializeMotor(void);
 
/* 
 * Prototype   : void HDCMOTOR_voidTurnMotorRight(u8 Copy_u8MotorNumber);
 * Description : Turn chosen motor right full speed
 * Arguments   : Motor number: (HDCMOTOR_MOTOR1-HDCMOTOR_MOTOR2-HDCMOTOR_MOTOR3-HDCMOTOR_MOTOR4
 *								HDCMOTOR_MOTOR5-HDCMOTOR_MOTOR6-HDCMOTOR_MOTOR7-HDCMOTOR_MOTOR8)
 * return      : void  
 */
 void HDCMOTOR_voidTurnMotorRight(u8 Copy_u8MotorNumber);

/* 
 * Prototype   : void HDCMOTOR_voidTurnMotorLeft(u8 Copy_u8MotorNumber);
 * Description : Turn chosen motor Left full speed
 * Arguments   : Motor number: (HDCMOTOR_MOTOR1-HDCMOTOR_MOTOR2-HDCMOTOR_MOTOR3-HDCMOTOR_MOTOR4
 *								HDCMOTOR_MOTOR5-HDCMOTOR_MOTOR6-HDCMOTOR_MOTOR7-HDCMOTOR_MOTOR8)
 * return      : void  
 */
 void HDCMOTOR_voidTurnMotorLeft(u8 Copy_u8MotorNumber);

/* 
 * Prototype   : void HDCMOTOR_voidStopMotor(u8 Copy_u8MotorNumber);
 * Description : stop chosen motor 
 * Arguments   : Motor number: (HDCMOTOR_MOTOR1-HDCMOTOR_MOTOR2-HDCMOTOR_MOTOR3-HDCMOTOR_MOTOR4
 *								HDCMOTOR_MOTOR5-HDCMOTOR_MOTOR6-HDCMOTOR_MOTOR7-HDCMOTOR_MOTOR8)
 * return      : void  
 */
 void HDCMOTOR_voidStopMotor(u8 Copy_u8MotorNumber);

#endif

/*==============================================================================================================================================
 * EOF 
 *==============================================================================================================================================*/