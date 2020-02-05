/*
 * File        : LDELAY_Private.h
 * Description : This file includes delay service definitions used by driver for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 23/6/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */


#ifndef __LDELAY_PRIVATE_H__
#define __LDELAY_PRIVATE_H__

/*those time parameters are measured by oscilloscope*/

/*one loop iteration time*/
#define LDELAY_LoopTime           137
/*time lost in calculation*/
#define LDELAY_CalculationTime    696
/*time lost in context switching*/
#define LDELAY_ContextSwitch      1710

#endif

/*==============================================================================================================================================
 * EOF 
 *==============================================================================================================================================*/