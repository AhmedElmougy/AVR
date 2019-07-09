#include "LSTD_Types.h"
#include "LUTILS.h"
#include "HLED_Private.h"
#include "HLED_Interface.h"
#include "MDIO_Interface.h"

void HLED_InitLED(u8 REG,u8 BIT) //initialize LED on specific port and bit
{
	MDIO_SetDirection_Bit(REG,BIT,OUTPUT);
}
void HLED_ON(u8 REG,u8 BIT) // set led on
{
	MDIO_Write_Bit(REG,BIT,HIGH);
}
void HLED_OFF(u8 REG,u8 BIT) //set led off
{
	MDIO_Write_Bit(REG,BIT,LOW);
}