#ifndef __HLCD_CONFIG_h__
#define __HLCD_CONFIG_h__


//8Bit or 4Bit Mode
#define HLCD_MODE HLCD_4BIT
//Define Register selector pin  
#define HLCD_RS 2
//Define Register selector pin  
#define HLCD_RW 1
//Define Register selector pin  
#define HLCD_EN 0 

//control pins register
#define ContREG PORTD
//Data pins register (Note: in 4 bit Mode register Higher 4 bits of Data reg is used (Pin 4 ~ Pin7))
#define DataREG PORTD

//Custom made characters
const u8 CUST1[8]= {0b00000000,
				    0b00000000,
				    0b00000000,
				    0b00000000,
				    0b00000000,
				    0b00000000,
				    0b00000000,
				    0b00000000};

const u8 CUST2[8]= {0b00000000,
				    0b00000000,
				    0b00000000,
				    0b00000000,
				    0b00000000,
				    0b00000000,
				    0b00000000,
				    0b00000000};
				   				   
const u8 CUST3[8]= {0b00000000,
					0b00000000,
					0b00000000,
					0b00000000,
					0b00000000,
					0b00000000,
					0b00000000,
					0b00000000};

const u8 CUST4[8]= {0b00000000,
					0b00000000,
					0b00000000,
					0b00000000,
					0b00000000,
					0b00000000,
					0b00000000,
					0b00000000};


#endif
