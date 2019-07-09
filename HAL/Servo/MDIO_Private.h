#ifndef __MDIO_Private_H__
#define __MDIO_Private_H__

//PORTA 
#define MDIO_PORTA (*(volatile u8 *)(0x3B)) //PORTA Definition
#define MDIO_DDRA (*(volatile u8 *)(0x3A)) //DDRA Definition
#define MDIO_PINA (*(volatile u8 *)(0x39)) //PINA Definition

//PORTB
#define MDIO_PORTB *((volatile u8 *)(0x38)) //PORTB Definition
#define MDIO_DDRB *((volatile u8 *)(0x37)) //DDRB Definition
#define MDIO_PINB *((volatile u8 *)(0x36)) //PINB Definition


//PORTC
#define MDIO_PORTC (*(volatile u8 *)(0x35)) //PORTC Definition
#define MDIO_DDRC (*(volatile u8 *)(0x34)) //DDRC Definition
#define MDIO_PINC (*(volatile u8 *)(0x33)) //PINC Definition

//PORTD
#define MDIO_PORTD (*(volatile u8 *)(0x32)) //PORTD Definition
#define MDIO_DDRD (*(volatile u8 *)(0x31)) //DDRD Definition
#define MDIO_PIND (*(volatile u8 *)(0x30)) //PIND Definition



#endif