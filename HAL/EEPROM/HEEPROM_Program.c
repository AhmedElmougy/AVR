/*
 * HEEPROM_Program.c
 *
 *  Created on: Jun 27, 2019
 *      Author: engin
 */

#include "LSTD_TYPES.h"
#include "LUTILS.h"
#include "MDIO_Interface.h"
#include "MI2C_Interface.h"
#include "HEEPROM_Interface.h"


void HEEPROM_voidInit(void)
{
	MTIMER1_voidInitialize();
}

void HEEPROM_voidWriteByte(u16 location, u8 byte)
{
	u8 loc = (u8)location;
	u8 SLA = 0b01010000 | ((location & 0x300) >> 8);

	MTWI_voidSendStart();

	if (MTWI_u8CheckStatus(START_CONDITION_HAS_BEEN_TRANSIMTTED) == 0)
	{
		return;
	}

	MTWI_voidSendSlaveAddress(SLA, TWI_WRITE);

	if (MTWI_u8CheckStatus(0x18) == 0)
	{
		return;
	}

	MTWI_voidSendData(loc);

	if (MTWI_u8CheckStatus(0x28) == 0)
	{
		return;
	}

	MTWI_voidSendData(byte);

	if (MTWI_u8CheckStatus(0x28) == 0)
	{
		return;
	}

	MTWI_voidSendStop();

}

void HEEPROM_voidReadByte(u16 location, u8 *data)
{
	u8 loc = (u8)location;
	u8 SLA = 0b01010000 | ((location & 0x300) >> 8);

	MTWI_voidSendStart();

	if (MTWI_u8CheckStatus(START_CONDITION_HAS_BEEN_TRANSIMTTED) == 0)
	{
		return;
	}

	MTWI_voidSendSlaveAddress(SLA, TWI_WRITE);

	if (MTWI_u8CheckStatus(0x18) == 0)
	{
		return;
	}

	MTWI_voidSendData(loc);

	if (MTWI_u8CheckStatus(0x28) == 0)
	{
		return;
	}

	MTWI_voidSendStart();

	if (MTWI_u8CheckStatus(0x10) == 0)
	{
		return;
	}

	MTWI_voidSendSlaveAddress(SLA, TWI_READ);

	if (MTWI_u8CheckStatus(0x40) == 0)
	{
		return;
	}

	*data = MTWI_u8ReceiveDataWithNoAck();

	MTWI_voidSendStop();

}
