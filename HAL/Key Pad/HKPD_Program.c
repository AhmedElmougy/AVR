#include "LSTD_Types.h"
#include "LUTILS.h"
#include "MDIO_Interface.h"
#include "HKPD_Private.h"
#include "HKPD_Interface.h"
#include "HKPD_Config.h"


void HKPD_INIT(void) //Initiate keypad
{
	MDIO_SetDirection_Reg(KPD_REG,0x0f);   // set first four bits(PC0~PC3) o/p(CONNECT Columns)	
	                                       // set second four bits(PC4~PC7) i/p(CONNECT ROWS)
	MDIO_EnPullupBit(KPD_REG,R1);          //enable pull up res for BIT4
	MDIO_EnPullupBit(KPD_REG,R2);          //enable pull up res for BIT5
	MDIO_EnPullupBit(KPD_REG,R3);          //enable pull up res for BIT6
	MDIO_EnPullupBit(KPD_REG,R4);          //enable pull up res for BIT7
}
u8 HKPD_GetKey(void) //Get pushed key
{
	//Check on column 1
	MDIO_Write_Bit(KPD_REG,C1,LOW);
	MDIO_Write_Bit(KPD_REG,C2,HIGH);
	MDIO_Write_Bit(KPD_REG,C3,HIGH);
	MDIO_Write_Bit(KPD_REG,C4,HIGH);
	if (MDIO_Read_Bit(KPD_REG,R1)==LOW)
	{
		return KeyPadArr[0][0];
	}
	else if (MDIO_Read_Bit(KPD_REG,R2)==LOW)
	{
		return KeyPadArr[1][0];
	}
	else if (MDIO_Read_Bit(KPD_REG,R3)==LOW)
	{
		return KeyPadArr[2][0];
	}
	else if (MDIO_Read_Bit(KPD_REG,R4)==LOW)
	{
		return KeyPadArr[3][0];
	}
	
	//Check on column 2
	MDIO_Write_Bit(KPD_REG,C1,HIGH);
	MDIO_Write_Bit(KPD_REG,C2,LOW);
	MDIO_Write_Bit(KPD_REG,C3,HIGH);
	MDIO_Write_Bit(KPD_REG,C4,HIGH);
	if (MDIO_Read_Bit(KPD_REG,R1)==LOW)
	{
		return KeyPadArr[0][1];
	}
	else if (MDIO_Read_Bit(KPD_REG,R2)==LOW)
	{
		return KeyPadArr[1][1];
	}
	else if (MDIO_Read_Bit(KPD_REG,R3)==LOW)
	{
		return KeyPadArr[2][1];
	}
	else if (MDIO_Read_Bit(KPD_REG,R4)==LOW)
	{
		return KeyPadArr[3][1];
	}
	
	//Check on column 3
	MDIO_Write_Bit(KPD_REG,C1,HIGH);
	MDIO_Write_Bit(KPD_REG,C2,HIGH);
	MDIO_Write_Bit(KPD_REG,C3,LOW);
	MDIO_Write_Bit(KPD_REG,C4,HIGH);
	if (MDIO_Read_Bit(KPD_REG,R1)==LOW)
	{
		return KeyPadArr[0][2];
	}
	else if (MDIO_Read_Bit(KPD_REG,R2)==LOW)
	{
		return KeyPadArr[1][2];
	}
	else if (MDIO_Read_Bit(KPD_REG,R3)==LOW)
	{
		return KeyPadArr[2][2];
	}
	else if (MDIO_Read_Bit(KPD_REG,R4)==LOW)
	{
		return KeyPadArr[3][2];
	}
	
	//Check on column 4
	MDIO_Write_Bit(KPD_REG,C1,HIGH);
	MDIO_Write_Bit(KPD_REG,C2,HIGH);
	MDIO_Write_Bit(KPD_REG,C3,HIGH);
	MDIO_Write_Bit(KPD_REG,C4,LOW);
	
	if (MDIO_Read_Bit(KPD_REG,R1)==LOW)
	{
		return KeyPadArr[0][3];
	}
	else if (MDIO_Read_Bit(KPD_REG,R2)==LOW)
	{
		return KeyPadArr[1][3];
	}
	else if (MDIO_Read_Bit(KPD_REG,R3)==LOW)
	{
		return KeyPadArr[2][3];
	}
	else if (MDIO_Read_Bit(KPD_REG,R4)==LOW)
	{
		return KeyPadArr[3][3];
	}
	return '?';	
}
