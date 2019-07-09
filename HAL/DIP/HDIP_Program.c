#include "L_STD_Types.h"
#include "L_UTILS.h"
#include "MDIO_Interface.h"
#include "HDIP_Private.h"
#include "HDIP_Interface.h"

void HDIP_INIT(u8 REG) //config dip switch with a certain register
{
	MDIO_SetDirection_Reg(REG,INPUT); //set whole reg i/p
	MDIO_EnPullupReg(REG); 
}
u8 HDIP_Read_REG(u8 REG) //read whole DIP
{
	return MDIO_Read_Reg(REG); 
}
u8 HDIP_Read_BIT(u8 REG,u8 BIT) // Read one bit
{
	return MDIO_Read_Bit(REG,BIT);
}