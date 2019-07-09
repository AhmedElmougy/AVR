#include "LSTD_Types.h"
#include "LUTILS.h"
#include "MSPI_Private.h"
#include "MSPI_Interface.h"
#include "MSPI_Config.h"

void MSPI_voidMasterInit(void)
{
	SET_BIT(MSPI_SPCR,6); //Enable SPI Module
	CLEAR_BIT(MSPI_SPCR,5); // Send MSB First
	SET_BIT(MSPI_SPCR,4); //Set MSTR to Master Mode
	SET_BIT(MSPI_SPCR,3); //Set CPOL to hight State
	SET_BIT(MSPI_SPCR,2); //Set CPHA to Setup First
	CLEAR_BIT(MSPI_SPSR,0); // Clear SPI2X
	SET_BIT(MSPI_SPCR,1); //Set Bit rate to Fosc/128
	SET_BIT(MSPI_SPCR,0); //Set Bit rate to Fosc/128
	
}

void MSPI_voidSlaeInit(void)
{
	SET_BIT(MSPI_SPCR,6); //Enable SPI Module
	CLEAR_BIT(MSPI_SPCR,5); // Send MSB First
	CLEAR_BIT(MSPI_SPCR,4); //Set MSTR to Slave Mode
	SET_BIT(MSPI_SPCR,3); //Set CPOL to hight State
	SET_BIT(MSPI_SPCR,2); //Set CPOL to CPHA to Setup First
	CLEAR_BIT(MSPI_SPSR,0); // Clear SPI2X
	SET_BIT(MSPI_SPCR,1); //Set Bit rate to Fosc/128
	SET_BIT(MSPI_SPCR,0); //Set Bit rate to Fosc/128

}
u8 SPI_u8Transfer(u8 Copy_Byte)
{
	MSPI_SPDR= Copy_Byte;
	
	while((GET_BIT(MSPI_SPSR,7))==0); //wit transfer completion
	return MSPI_SPDR ;	
}