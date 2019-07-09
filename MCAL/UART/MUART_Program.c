#include "LSTD_Types.h"
#include "LUTILS.h"
#include "MUART_Private.h"
#include "MUART_Interface.h"
#include "MUART_Config.h"


u8 MUART_u8UCSRC_Value =0;

void MUART_voidInitialization(void)
{
	//Receive enable config
	if (MUART_RIECEVE_ENABLE == MUART_ENABLED)
	{
		SET_BIT(MUART_UCSRB,MUART_RXEN);  //Enable RXEN
	} 
	else if (MUART_RIECEVE_ENABLE == MUART_DISABLED)
	{
		CLEAR_BIT(MUART_UCSRB,MUART_RXEN);  //Disable RXEN
	}
	//Send enable config
	if (MUART_SEND_ENABLE == MUART_ENABLED)
	{
		SET_BIT(MUART_UCSRB,MUART_TXEN);  //Enable TXEN
	}
	else if (MUART_RIECEVE_ENABLE == MUART_DISABLED)
	{
		CLEAR_BIT(MUART_UCSRB,MUART_TXEN);  //Disable TXEN
	}
	//Send interrupt enable config
	if (MUART_TX_INTERRUPT_ENABLE == MUART_ENABLED)
	{
		SET_BIT(MUART_UCSRB,MUART_TXCIE);  //Enable Send interrupt
	}
	else if (MUART_TX_INTERRUPT_ENABLE == MUART_DISABLED)
	{
		CLEAR_BIT(MUART_UCSRB,MUART_TXCIE); //Disable send interrupt
	}
	//Receive interrupt enable config
	if (MUART_RX_INTERRUPT_ENABLE == MUART_ENABLED)
	{
		SET_BIT(MUART_UCSRB,MUART_RXCIE);  //Enable Receive interrupt
	}
	else if (MUART_RX_INTERRUPT_ENABLE == MUART_DISABLED)
	{
		CLEAR_BIT(MUART_UCSRB,MUART_RXCIE); //Disable Receive interrupt
	}
	//UDR Empty interrupt enable config
	if (MUART_UDR_INTERRUPT_ENABLE == MUART_ENABLED)
	{
		SET_BIT(MUART_UCSRB,MUART_UDRIE);  //Enable UDR interrupt
	}
	else if (MUART_UDR_INTERRUPT_ENABLE == MUART_DISABLED)
	{
		CLEAR_BIT(MUART_UCSRB,MUART_UDRIE); //Disable UDR interrupt
	}
	//Mode select config
	if (MUART_MODE_SELECT == MUART_SYNCHRONOUS)
	{
		SET_BIT(MUART_u8UCSRC_Value,MUART_UMSEL);  
	}
	else if (MUART_MODE_SELECT == MUART_ASYNCHRONOUS)
	{
		CLEAR_BIT(MUART_u8UCSRC_Value,MUART_UMSEL);  
	}
	//Parity Mode config
	MUART_u8UCSRC_Value|=(MUART_PARITY_MODE<<4);
	//Character size config
	if (MUART_CHAR_SIZE != MUART_9_BITS)
	{
		MUART_u8UCSRC_Value|=(MUART_CHAR_SIZE<<1);
	} 
	else if (MUART_CHAR_SIZE == MUART_9_BITS)
	{
		MUART_u8UCSRC_Value|=(MUART_8_BITS<<1);
		SET_BIT(MUART_UCSRB,MUART_UCSZ2);
	}
	//Clock polarity config
	if (MUART_CLOCK_POLARITY == MUART_SAMPLE_RISING_EDGE)
	{
		SET_BIT(MUART_u8UCSRC_Value,MUART_UCPOL);
	}
	else if (MUART_CLOCK_POLARITY == MUART_SAMPLE_FALLING_EDGE)
	{
		CLEAR_BIT(MUART_u8UCSRC_Value,MUART_UCPOL);
	}
	//Stop Bits config
	if (MUART_STOP_BIT_NO == MUART_2_STOP_BIT)
	{
		SET_BIT(MUART_u8UCSRC_Value,MUART_USBS);
	}
	else if (MUART_STOP_BIT_NO == MUART_1_STOP_BIT)
	{
		CLEAR_BIT(MUART_u8UCSRC_Value,MUART_USBS);
	}
	//Set URSEL to access UCSRC Reg
	SET_BIT(MUART_u8UCSRC_Value,7);
	//Load value of UCSRC
	MUART_UCSRC = MUART_u8UCSRC_Value ;
	//Baud Rate Value Config
	MUART_UBRRH = 0;
	MUART_UBRRL = MUART_BAUD_RATE;
	
}
void MUART_voidSendByte(u8 Copy_Byte)
{
	while ((GET_BIT(MUART_UCSRA,MUART_UDRE))==0);
	MUART_UDR = Copy_Byte;
}
u8 MUART_voidRecieveByte(void)
{
	while((GET_BIT(MUART_UCSRA,MUART_RXC))==0);
	return MUART_UDR;	
}