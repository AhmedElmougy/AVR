
#include "LSTD_Types.h"
#include "LUTILS.h"
#include "MDIO_Private.h"
#include "MDIO_Interface.h"

//Direction
void MDIO_SetDirection_Reg(u8 REG,u8 STATUS) // Set direction of the whole register
{
	if (REG==PORTA)
	{
		if (STATUS==OUTPUT)
		{
			MDIO_DDRA=0xff; //set port o/p
		}
		else if(STATUS==INPUT)
		{
			MDIO_DDRA=0x00; //set port i/p
		}
		else
		{
			MDIO_DDRA=STATUS;
		}
	}
	else if(REG==PORTB)
	{
		if (STATUS==OUTPUT)
		{
			MDIO_DDRB=0xff; //set port o/p
		}
		else if(STATUS==INPUT)
		{
			MDIO_DDRB=0x00; //set port i/p
		}
		else
		{
			MDIO_DDRB=STATUS;
		}
	}
	else if(REG==PORTC)
	{
		if (STATUS==OUTPUT)
		{
			MDIO_DDRC=0xff; //set port o/p
		}
		else if(STATUS==INPUT)
		{
			MDIO_DDRC=0x00; //set port i/p
		}
		else
		{
			MDIO_DDRC=STATUS;
		}
	}
	else if(REG==PORTD)
	{
		if (STATUS==OUTPUT)
		{
			MDIO_DDRD=0xff; //set port o/p
		}
		else if(STATUS==INPUT)
		{
			MDIO_DDRD=0x00; //set port i/p
		}
		else
		{
			MDIO_DDRD=STATUS;
		}
	}
	return;
}

void MDIO_SetDirection_Bit(u8 REG,u8 BIT,u8 STATUS) // Set direction of one bit of a register
{
	
	if (REG==PORTA)
	{
		if(STATUS==OUTPUT)
		{
			SET_BIT(MDIO_DDRA,BIT);	//set BIT with 1 make it o/p
		}
		else if (STATUS==INPUT)
		{
			CLEAR_BIT(MDIO_DDRA,BIT); //clear BIT with 0 make it i/p
		}
	}
	else if(REG==PORTB)
	{
		if(STATUS==OUTPUT)
		{
			SET_BIT(MDIO_DDRB,BIT);	//set BIT with 1 make it o/p
		}
		else if (STATUS==INPUT)
		{
			CLEAR_BIT(MDIO_DDRB,BIT); //clear BIT with 0 make it i/p
		}
	}
	else if(REG==PORTC)
	{
		if(STATUS==OUTPUT)
		{
			SET_BIT(MDIO_DDRC,BIT);	//set BIT with 1 make it o/p
		}
		else if (STATUS==INPUT)
		{
			CLEAR_BIT(MDIO_DDRC,BIT); //clear BIT with 0 make it i/p
		}
	}
	else if(REG==PORTD)
	{
		if(STATUS==OUTPUT)
		{
			SET_BIT(MDIO_DDRD,BIT);	//set BIT with 1 make it o/p
		}
		else if (STATUS==INPUT)
		{
			CLEAR_BIT(MDIO_DDRD,BIT); //clear BIT with 0 make it i/p
		}
	}
	return;
}

//Write
void MDIO_Write_Reg(u8 REG,u8 VALUE) // write o/p to  the whole register
{
	
	if (REG==PORTA)
	{
		if (VALUE==HIGH)
		{
			MDIO_PORTA=0xff; //set port o/p
		}
		else if(VALUE==LOW)
		{
			MDIO_PORTA=0x00; //set port i/p
		}
		else
		{
			MDIO_PORTA=VALUE;
		}
	}
	if (REG==PORTB)
	{
		if (VALUE==HIGH)
		{
			MDIO_PORTB=0xff; //set port o/p
		}
		else if(VALUE==LOW)
		{
			MDIO_PORTB=0x00; //set port i/p
		}
		else
		{
			MDIO_PORTB=VALUE;
		}
	}
	if (REG==PORTC)
	{
		if (VALUE==HIGH)
		{
			MDIO_PORTC=0xff; //set port o/p
		}
		else if(VALUE==LOW)
		{
			MDIO_PORTC=0x00; //set port i/p
		}
		else
		{
			MDIO_PORTC=VALUE;
		}
	}
	if (REG==PORTD)
	{
		if (VALUE==HIGH)
		{
			MDIO_PORTD=0xff; //set port o/p
		}
		else if(VALUE==LOW)
		{
			MDIO_PORTD=0x00; //set port i/p
		}
		else
		{
			MDIO_PORTD=VALUE;
		}
	}
	return;
}
void MDIO_Write_Bit(u8 REG,u8 BIT,u8 VALUE) // write o/p to  the whole register
{
	if (REG==PORTA)
	{
		if(VALUE==HIGH)
		{
			SET_BIT(MDIO_PORTA,BIT);	//Output high on bit
		}
		else if (VALUE==LOW)
		{
			CLEAR_BIT(MDIO_PORTA,BIT); //output low on bit
		}
	}
	else if(REG==PORTB)
	{
		if(VALUE==HIGH)
		{
			SET_BIT(MDIO_PORTB,BIT);	//Output high on bit
		}
		else if (VALUE==LOW)
		{
			CLEAR_BIT(MDIO_PORTB,BIT); //output low on bit
		}
	}
	else if(REG==PORTC)
	{
		if(VALUE==HIGH)
		{
			SET_BIT(MDIO_PORTC,BIT);	//Output high on bit
		}
		else if (VALUE==LOW)
		{
			CLEAR_BIT(MDIO_PORTC,BIT); //output low on bit
		}
	}
	else if(REG==PORTD)
	{
		if(VALUE==HIGH)
		{
			SET_BIT(MDIO_PORTD,BIT);	//Output high on bit
		}
		else if (VALUE==LOW)
		{
			CLEAR_BIT(MDIO_PORTD,BIT); //output low on bit
		}
	}
	return;
}
//Toggle Bit
void MDIO_Toggle_Bit(u8 REG,u8 BIT)
{
	if (REG==PORTA)
	{
		TOGGLE_BIT(MDIO_PORTA,BIT);	//Toggle bit
	}
	else if (REG==PORTB)
	{
		TOGGLE_BIT(MDIO_PORTB,BIT);	//Toggle bit
	}
	else if (REG==PORTC)
	{
		TOGGLE_BIT(MDIO_PORTC,BIT);	//Toggle bit
	}
	else if (REG==PORTD)
	{
		TOGGLE_BIT(MDIO_PORTD,BIT);	//Toggle bit
	}
}
//Toggle Reg
void MDIO_Toggle_Reg(u8 REG)
{
	if (REG==PORTA)
	{
		MDIO_PORTA^=0xff ;	//Toggle Reg
	}
	else if (REG==PORTB)
	{
		MDIO_PORTB^=0xff ;	//Toggle Reg	
	}
	else if (REG==PORTC)
	{
		MDIO_PORTC^=0xff ;	//Toggle Reg
	}
	else if (REG==PORTD)
	{
		MDIO_PORTD^=0xff ;	//Toggle Reg
	}
}

//Read
u8 MDIO_Read_Reg(u8 REG) // Read i/p of  the whole register
{	
	if (REG==PORTA)
	{
		return MDIO_PINA;
	}
	else if(REG==PORTB)
	{
		return MDIO_PINB;
	}
	else if(REG==PORTC)
	{
		return MDIO_PINC;
	}
	else if(REG==PORTD)
	{
		return MDIO_PIND;
	}
	return ;
}
u8 MDIO_Read_Bit(u8 REG,u8 BIT) // Read one bit of the register
{
	if (REG==PORTA)
	{
		return  GET_BIT(MDIO_PINA,BIT);
	}
	else if(REG==PORTB)
	{
		return  GET_BIT(MDIO_PINB,BIT);
	}
	else if(REG==PORTC)
	{
		return  GET_BIT(MDIO_PINC,BIT);
	}
	else if(REG==PORTD)
	{
		return  GET_BIT(MDIO_PIND,BIT);
	}
	return ;
}

//enable pull up
void MDIO_EnPullupReg(u8 REG) //enable pull up res for the whole register
{
	if (REG==PORTA)
	{
		MDIO_PORTA=0xff;
	}
	else if(REG==PORTB)
	{
		MDIO_PORTB=0xff;
	}
	else if(REG==PORTC)
	{
		MDIO_PORTC=0xff;
	}
	else if(REG==PORTD)
	{
		MDIO_PORTD=0xff;
	}
}
void MDIO_EnPullupBit(u8 REG,u8 BIT) //enable pull up res for one bit in reg register
{
	if (REG==PORTA)
	{
		SET_BIT(MDIO_PORTA,BIT);	//Output high on bit
	}
	else if(REG==PORTB)
	{
		SET_BIT(MDIO_PORTB,BIT);	//Output high on bit
	}
	else if(REG==PORTC)
	{
		SET_BIT(MDIO_PORTC,BIT);	//Output high on bit
	}
	else if(REG==PORTD)
	{
		SET_BIT(MDIO_PORTD,BIT);	//Output high on bit
	}
}
