/*LED driver
 *created by ahmed elmogy 15/4/2019
 *you can turn led on, off and initialize
 */

#ifndef __HLED_Interface_h__ 
#define __HLED_Interface_h__

void HLED_InitLED(u8 REG,u8 BIT); //initialize LED on specific port and bit
void HLED_ON(u8 REG,u8 BIT); //set led on
void HLED_OFF(u8 REG,u8 BIT); //set led off

#endif
