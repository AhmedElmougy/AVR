#ifndef __HDIP_Interface_h__
#define __HDIP_Interface_h__

void HDIP_INIT(u8 REG); //config dip switch with a certain register
u8 HDIP_Read_REG(u8 REG); //read whole DIP
u8 HDIP_Read_BIT(u8 REG,u8 BIT); // Read one bit

#endif