/*
 * File        : HDCMOTOR_Program.c
 * Description : This file includes DC MOTOR Driver implementations for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 10/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#include "LSTD_Types.h"
#include "LUTILS.h"
#include "MDIO_Interface.h"
#include "HDCMOTOR_Private.h"
#include "HDCMOTOR_Config.h"
#include "HDCMOTOR_Interface.h"


/*==============================================================================================================================================
 * Public Modules
 *==============================================================================================================================================*/
 /* 
 * Prototype   : void HDCMOTOR_voidInitializeMotor(u8 Copy_u8MotorNumber,u8 Copy_u8ControlType);;
 * Description : initialize chosen motor
 * Arguments   : void
 * return      : void  
 */
 void HDCMOTOR_voidInitializeMotor(void)
 {
	 /*=====================================================================================================
	  * initialize motors less than 4
	  *=====================================================================================================*/
	 #if   (HDCMOTOR_MOTORS_NUMBER > 0) && (HDCMOTOR_MOTORS_NUMBER <= 4)
	 /*loop all interfaced motors*/
	 for (u8 Local_MotorNumbers = 0 ; Local_MotorNumbers < HDCMOTOR_MOTORS_NUMBER ; Local_MotorNumbers += 2)
	 {
		 /*make motor control pins output*/
		 MDIO_u8SetDirectionBit(HDCMOTOR_PORT1,HDCMOTOR_u8MotorPinsArr[Local_MotorNumbers],MDIO_OUTPUT);
		 MDIO_u8SetDirectionBit(HDCMOTOR_PORT1,HDCMOTOR_u8MotorPinsArr[Local_MotorNumbers+1],MDIO_OUTPUT);

	 }/*end of motors loop*/
	 
	 /*=====================================================================================================
	  * initialize motors more than 4
	  *=====================================================================================================*/
	 #elif (HDCMOTOR_MOTORS_NUMBER > 4) && (HDCMOTOR_MOTORS_NUMBER <= 8)
	 /*loop all interfaced motors*/
	 for (u8 Local_MotorNumbers = 0 ; Local_MotorNumbers < 4 ; Local_MotorNumbers += 2)
	 {
		 /*make first 4 motors control pins output*/
		 MDIO_u8SetDirectionBit(HDCMOTOR_PORT1,HDCMOTOR_u8MotorPinsArr[Local_MotorNumbers],MDIO_OUTPUT);
		 MDIO_u8SetDirectionBit(HDCMOTOR_PORT1,HDCMOTOR_u8MotorPinsArr[Local_MotorNumbers+1],MDIO_OUTPUT);
	 
	 }/*end of first 4 motors loop*/
	 for (u8 Local_MotorNumbers = 4 ; Local_MotorNumbers < HDCMOTOR_MOTORS_NUMBER ; Local_MotorNumbers += 2)
	 {
		 /*make the rest of motors control pins output*/
		 MDIO_u8SetDirectionBit(HDCMOTOR_PORT2,HDCMOTOR_u8MotorPinsArr[Local_MotorNumbers],MDIO_OUTPUT);
		 MDIO_u8SetDirectionBit(HDCMOTOR_PORT2,HDCMOTOR_u8MotorPinsArr[Local_MotorNumbers+1],MDIO_OUTPUT);
	 
	 }/*end of rest of motors loop*/
	 
	 #endif	/*end of motors number check*/ 
 
 }/*end of HDCMOTOR_voidInitializeMotor()*/
 
/* 
 * Prototype   : void HDCMOTOR_voidTurnMotorRight(u8 Copy_u8MotorNumber);
 * Description : Turn chosen motor right full speed
 * Arguments   : Motor number: (HDCMOTOR_MOTOR1-HDCMOTOR_MOTOR2-HDCMOTOR_MOTOR3-HDCMOTOR_MOTOR4
 *								HDCMOTOR_MOTOR5-HDCMOTOR_MOTOR6-HDCMOTOR_MOTOR7-HDCMOTOR_MOTOR8)
 * return      : void  
 */
 void HDCMOTOR_voidTurnMotorRight(u8 Copy_u8MotorNumber)
 {
	 /*temp variable*/
	 u8 Local_u8PinNumber   = 0;
	 /*Motor Pin0 number*/
	 u8 Local_u8Pin0Number  = 0;
	 /*Motor Pin1 number*/
	 u8 Local_u8Pin1Number  = 0;
	 /*Motor Port number*/
	 u8 Local_u8PortNumber  = 0;
	 
	 /*calculate motor port number*/
	 Local_u8PortNumber  = Copy_u8MotorNumber / 4;
	 Local_u8PinNumber   = Copy_u8MotorNumber % 4;
	 /*calculate motor pin0 number*/
	 Local_u8Pin0Number  = HDCMOTOR_u8MotorPinsArr[(Local_u8PinNumber * 2) - 2];
	 /*calculate motor pin1 number*/
	 Local_u8Pin1Number  = HDCMOTOR_u8MotorPinsArr[(Local_u8PinNumber * 2) - 1];
	 
	 /*switch port number*/
	 switch(Local_u8PortNumber)	
	 {
		 case 0 : {Local_u8PortNumber = HDCMOTOR_PORT1; break;} /*make port number Port1*/
		 case 1 : {Local_u8PortNumber = HDCMOTOR_PORT2; break;} /*make port number Port2*/
	 
	 }/*end of port switch case*/
	 
	 /*Set Pin0 high and Pin1 low to turn motor right*/
	 MDIO_u8WriteBit(Local_u8PortNumber,Local_u8Pin0Number,MDIO_HIGH);
	 MDIO_u8WriteBit(Local_u8PortNumber,Local_u8Pin1Number,MDIO_LOW);
 
 }/*end of HDCMOTOR_voidTurnMotorRight()*/

/* 
 * Prototype   : void HDCMOTOR_voidTurnMotorLeft(u8 Copy_u8MotorNumber);
 * Description : Turn chosen motor Left full speed
 * Arguments   : Motor number: (HDCMOTOR_MOTOR1-HDCMOTOR_MOTOR2-HDCMOTOR_MOTOR3-HDCMOTOR_MOTOR4
 *								HDCMOTOR_MOTOR5-HDCMOTOR_MOTOR6-HDCMOTOR_MOTOR7-HDCMOTOR_MOTOR8)
 * return      : void  
 */
 void HDCMOTOR_voidTurnMotorLeft(u8 Copy_u8MotorNumber)
 {
	 /*temp variable*/
	 u8 Local_u8PinNumber   = 0;
	 /*Motor Pin0 number*/
	 u8 Local_u8Pin0Number  = 0;
	 /*Motor Pin1 number*/
	 u8 Local_u8Pin1Number  = 0;
	 /*Motor Port number*/
	 u8 Local_u8PortNumber  = 0;
	 
	 /*calculate motor port number*/
	 Local_u8PortNumber  = Copy_u8MotorNumber / 4;
	 Local_u8PinNumber   = Copy_u8MotorNumber % 4;
	 /*calculate motor pin0 number*/
	 Local_u8Pin0Number  = HDCMOTOR_u8MotorPinsArr[(Local_u8PinNumber * 2) - 2];
	 /*calculate motor pin1 number*/
	 Local_u8Pin1Number  = HDCMOTOR_u8MotorPinsArr[(Local_u8PinNumber * 2) - 1];
	 
	 /*switch port number*/
	 switch(Local_u8PortNumber)
	 {
		 case 0 : {Local_u8PortNumber = HDCMOTOR_PORT1; break;} /*make port number Port1*/
		 case 1 : {Local_u8PortNumber = HDCMOTOR_PORT2; break;} /*make port number Port2*/
		 
	 }/*end of port switch case*/
		 
	 /*Set Pin0 low and Pin1 High to turn motor left*/
	 MDIO_u8WriteBit(Local_u8PortNumber,Local_u8Pin0Number,MDIO_LOW);
	 MDIO_u8WriteBit(Local_u8PortNumber,Local_u8Pin1Number,MDIO_HIGH);

 }/*end of HDCMOTOR_voidTurnMotorLeft()*/

/* 
 * Prototype   : void HDCMOTOR_voidStopMotor(u8 Copy_u8MotorNumber);
 * Description : stop chosen motor 
 * Arguments   : Motor number: (HDCMOTOR_MOTOR1-HDCMOTOR_MOTOR2-HDCMOTOR_MOTOR3-HDCMOTOR_MOTOR4
 *								HDCMOTOR_MOTOR5-HDCMOTOR_MOTOR6-HDCMOTOR_MOTOR7-HDCMOTOR_MOTOR8)
 * return      : void  
 */
 void HDCMOTOR_voidStopMotor(u8 Copy_u8MotorNumber)
 {
	 /*temp variable*/
	 u8 Local_u8PinNumber   = 0;
	 /*Motor Pin0 number*/
	 u8 Local_u8Pin0Number  = 0;
	 /*Motor Pin1 number*/
	 u8 Local_u8Pin1Number  = 0;
	 /*Motor Port number*/
	 u8 Local_u8PortNumber  = 0;
	 
	 /*calculate motor port number*/
	 Local_u8PortNumber  = Copy_u8MotorNumber / 4;
	 Local_u8PinNumber   = Copy_u8MotorNumber % 4;
	 /*calculate motor pin0 number*/
	 Local_u8Pin0Number  = HDCMOTOR_u8MotorPinsArr[(Local_u8PinNumber * 2) - 2];
	 /*calculate motor pin1 number*/
	 Local_u8Pin1Number  = HDCMOTOR_u8MotorPinsArr[(Local_u8PinNumber * 2) - 1];
	 
	 /*switch port number*/
	 switch(Local_u8PortNumber)
	 {
		 case 0 : {Local_u8PortNumber = HDCMOTOR_PORT1; break;} /*make port number Port1*/
		 case 1 : {Local_u8PortNumber = HDCMOTOR_PORT2; break;} /*make port number Port2*/
		 
	 }/*end of port switch case*/
		 
	 /*Set Pin0 low and Pin1 low to stop motor*/
	 MDIO_u8WriteBit(Local_u8PortNumber,Local_u8Pin0Number,MDIO_LOW);
	 MDIO_u8WriteBit(Local_u8PortNumber,Local_u8Pin1Number,MDIO_LOW);
 
 }/*end of HDCMOTOR_voidStopMotor()*/


/*==============================================================================================================================================
 * EOF 
 *==============================================================================================================================================*/