/*
 * File        : LMath_Interface.h
 * Description : This file includes Math modules implementations
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 23/6/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#include "LSTD_Types.h"

/*
 * Description : module that calculate exponential value for a given base and exponent numbers   
 * Argument    : exponent, base
 * return      : exponential value
 */
u32 LMATH_u32GetExponential(u8 Copy_u8LBase, u8 Copy_u8LExponent)
{
    u32 Local_u32Result = 1;
    for(u8 i =0; i<Copy_u8LExponent;i++)
    {
        Local_u32Result *= Copy_u8LBase;
    }
    return Local_u32Result;
}

