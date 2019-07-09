#include "LSTD_Types.h"
#include "LUTILS.h"
#include "MI2C_Private.h"
#include "MI2C_Interface.h"
#include "MI2C_Config.h"

void MI2C_voidInit(void)
{
	SET_BIT(MI2C_TWCR_REG,MI2C_TWEN_BIT);     //Enable TWI
	MI2C_TWBR_REG = MI2C_TWBR_VALUE;          //Set TWBR = 8
	//Prepare TWSR for masking TWPS0,TWPS1
	SET_BIT(MI2C_TWSR_REG,MI2C_TWPS0_BIT);
	SET_BIT(MI2C_TWSR_REG,MI2C_TWPS1_BIT);
	//Put MI2C TWPS Value in Reg TWSR                        
	MI2C_TWSR_REG &= ((MI2C_TWPS_VALUE)|(MI2C_TWSR_REG_MASK)) ;        
	// Set My slave address
	MI2C_TWAR_REG = (MI2C_SLAVE_ADDRESS<<1);
	//general call
	if (MI2C_GENERAL_CALL_MODE == MI2C_ENABLE_GENERAL_CALL)
	{
		SET_BIT(MI2C_TWAR_REG,MI2C_TWGCE_BIT);
	}
}
void MI2C_voidSendStartCondition(void)
{
	MI2C_TWCR_REG = (1<<MI2C_TWINT_BIT)|(1<<MI2C_TWSTA_BIT)|(1<<MI2C_TWEN_BIT);  //Send Start condition + clear TWINT flag to start TWI operation
	while(GET_BIT(MI2C_TWCR_REG,MI2C_TWINT_BIT)==0);                             //wait until start is transmitted
	MI2C_TWCR_REG = (1<<MI2C_TWEN_BIT);                                          //clear start bit and all bits except enable
}
void MI2C_voidSendStopCondition(void)
{
	MI2C_TWCR_REG = (1<<MI2C_TWINT_BIT)|(1<<MI2C_TWSTO_BIT)|(1<<MI2C_TWEN_BIT);  //Send Stop condition + clear TWINT flag to start TWI operation
	while(GET_BIT(MI2C_TWCR_REG,MI2C_TWINT_BIT)==0);                             //wait until stop is transmitted
}
u8   MI2C_u8CheckStatus(u8 Copy_u8ExpectedStatus)
{
	if ((MI2C_TWSR_REG & MI2C_TWSR_REG_MASK) == Copy_u8ExpectedStatus)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void MI2C_voidSendSlaveAddress(u8 Copy_u8SlaveAdd,u8 Copy_u8Operation)
{
	MI2C_TWDR_REG = (Copy_u8SlaveAdd<<1)|(Copy_u8Operation);  //Put address and operation in TWDR Reg
	MI2C_TWCR_REG = (1<<MI2C_TWINT_BIT)|(1<<MI2C_TWEN_BIT);   // reset flag Start sending address and operation
	while((GET_BIT(MI2C_TWCR_REG,MI2C_TWINT_BIT))==0);        //wait until operation complete
}
void MI2C_voidSendByte(u8 Copy_u8Data)
{
	MI2C_TWDR_REG = Copy_u8Data;
	MI2C_TWCR_REG = (1<<MI2C_TWINT_BIT)|(1<<MI2C_TWEN_BIT);   // reset flag Start sending Data
	while((GET_BIT(MI2C_TWCR_REG,MI2C_TWINT_BIT))==0);        //wait until operation complete
}
u8   MI2C_u8ReceiveDataWithNoAck(void)
{
	MI2C_TWCR_REG = (1<<MI2C_TWINT_BIT)|(1<<MI2C_TWEN_BIT);   // reset flag Start Receiving data
	while((GET_BIT(MI2C_TWCR_REG,MI2C_TWINT_BIT))==0);        //wait until operation complete
	return 	MI2C_TWDR_REG;
}