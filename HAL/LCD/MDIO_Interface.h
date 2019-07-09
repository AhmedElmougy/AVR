#ifndef __MDIO_Interface_H__
#define __MDIO_Interface_H__

#define OUTPUT 1
#define INPUT 0
#define HIGH 1
#define LOW 0
#define ON 1
#define OFF 0

//define ports
#define PORTA 1
#define PORTB 2
#define PORTC 3
#define PORTD 4

//PORTA PINS
#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

//PORTB PINS
#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

//PORTC PINS
#define PC0 0
#define PC1 1
#define PC2 2
#define PC3 3
#define PC4 4
#define PC5 5
#define PC6 6
#define PC7 7

//PORTD PINS
#define PD0 0
#define PD1 1
#define PD2 2
#define PD3 3
#define PD4 4
#define PD5 5
#define PD6 6
#define PD7 7

//Direction
void MDIO_SetDirection_Reg(u8 REG,u8 STATUS);        // Set direction of the whole register
void MDIO_SetDirection_Bit(u8 REG,u8 BIT,u8 STATUS); // Set direction of one bit of a register

//Write
void MDIO_Write_Reg(u8 REG,u8 VALUE);        // write o/p to  the whole register
void MDIO_Write_Bit(u8 REG,u8 BIT,u8 VALUE); // write o/p to  the whole register
void MDIO_Toggle_Bit(u8 REG,u8 BIT);         //Toggle bit
void MDIO_Toggle_Reg(u8 REG);                //Toggle Reg  
//Read
u8 MDIO_Read_Reg(u8 REG);                    // Read i/p of  the whole register
u8 MDIO_Read_Bit(u8 REG,u8 BIT) ;            // Read one bit of the register

//enable pull up
void MDIO_EnPullupReg(u8 REG);               //enable pull up res for the whole register
void MDIO_EnPullupBit(u8 REG,u8 BIT);        //enable pull up res for one bit in reg register

#endif