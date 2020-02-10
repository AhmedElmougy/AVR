/*
 * File        : HDCMOTOR_Config.h
 * Description : This File includes DC MOTOR Driver config macros and declarations for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 10/2/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */ 
 

#ifndef __HDCMOTOR_CONFIG_H__
#define __HDCMOTOR_CONFIG_H__

/*number of motors to interface*/
#define HDCMOTOR_MOTORS_NUMBER			1

#define HDCMOTOR_PORT1					MDIO_PORTA
/*for interfacing more than 4 motors*/
#define HDCMOTOR_PORT2					MDIO_PORTB

#define		HDCMOTOR_MOTOR1_P0			2
#define		HDCMOTOR_MOTOR1_P1			3
#define		HDCMOTOR_MOTOR2_P0			2
#define		HDCMOTOR_MOTOR2_P1			3
#define		HDCMOTOR_MOTOR3_P0			4
#define		HDCMOTOR_MOTOR3_P1			5
#define		HDCMOTOR_MOTOR4_P0			6
#define		HDCMOTOR_MOTOR4_P1			7
#define		HDCMOTOR_MOTOR5_P0			0
#define		HDCMOTOR_MOTOR5_P1			1
#define		HDCMOTOR_MOTOR6_P0			2
#define		HDCMOTOR_MOTOR6_P1			3
#define		HDCMOTOR_MOTOR7_P0			4
#define		HDCMOTOR_MOTOR7_P1			5
#define		HDCMOTOR_MOTOR8_P0			6
#define		HDCMOTOR_MOTOR8_P1			7




u8 HDCMOTOR_u8MotorPinsArr[16] = {HDCMOTOR_MOTOR1_P0,HDCMOTOR_MOTOR1_P1,HDCMOTOR_MOTOR2_P0,HDCMOTOR_MOTOR2_P1,HDCMOTOR_MOTOR3_P0,HDCMOTOR_MOTOR3_P1,
								  HDCMOTOR_MOTOR4_P0,HDCMOTOR_MOTOR4_P1,HDCMOTOR_MOTOR5_P0,HDCMOTOR_MOTOR5_P1,HDCMOTOR_MOTOR6_P0,HDCMOTOR_MOTOR6_P1,
							      HDCMOTOR_MOTOR7_P0,HDCMOTOR_MOTOR7_P1,HDCMOTOR_MOTOR8_P0,HDCMOTOR_MOTOR8_P1};

#endif

/*==============================================================================================================================================
 * EOF 
 *==============================================================================================================================================*/