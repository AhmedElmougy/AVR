#include "LSTD_Types.h"
#include "LUTILS.h"
#include "MDIO_Interface.h"
#include "HSTPR_Private.h"
#include "HSTPR_Interface.h"



void HSTPR_INIT(void)
{
	MDIO_SetDirection_Reg(HSTPR_PORT,OUTPUT);
}
void HSTPR_FullStep_Right(u8 speed)
{
	//full step
	MDIO_Write_Reg(HSTPR_PORT,0x01); //activate coil 1
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x02); //activate coil 2
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x04); //activate coil 3
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x08); //activate coil 4
	_delay_ms(speed);
}
void HSTPR_FullStep_Left(u8 speed)
{
	//full step
	
	MDIO_Write_Reg(HSTPR_PORT,0x08); //activate coil 4
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x04); //activate coil 3
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x02); //activate coil 2
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x01); //activate coil 1
	_delay_ms(speed);
}
void HSTPR_HalfStep_Right(u8 speed)
{
	//half step
	MDIO_Write_Reg(HSTPR_PORT,0x09); //activate coil 1,4
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x01); //activate coil 1
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x03); //activate coil 1,2
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x02); //activate coil 2
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x06); //activate coil 2,3
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x04); //activate coil 3
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x0C); //activate coil 3,4
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x08); //activate coil 4
	_delay_ms(speed);
}
void HSTPR_HalfStep_Left(u8 Speed)
{
	//half step
	MDIO_Write_Reg(HSTPR_PORT,0x08); //activate coil 4
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x0C); //activate coil 3,4
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x04); //activate coil 3
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x06); //activate coil 2,3
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x02); //activate coil 2
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x03); //activate coil 1,2
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x01); //activate coil 1
	_delay_ms(speed);
	MDIO_Write_Reg(HSTPR_PORT,0x09); //activate coil 1,4
	_delay_ms(speed);
}
void HSTPR_Stop(void)
{
	MDIO_Write_Reg(HSTPR_PORT,0x00); //disable all coils
	
}