#ifndef _MI2C_PRIVATE_H_
#define _MI2C_PRIVATE_H_


#define MI2C_TWCR_REG   (*(volatile u8 *)(0x56))
#define MI2C_TWDR_REG   (*(volatile u8 *)(0x23)) 
#define MI2C_TWAR_REG   (*(volatile u8 *)(0x22))
#define MI2C_TWSR_REG   (*(volatile u8 *)(0x21))
#define MI2C_TWBR_REG   (*(volatile u8 *)(0x20))


//TWCR REG
#define MI2C_TWIE_BIT     0
#define MI2C_TWEN_BIT     2
#define MI2C_TWWC_BIT     3
#define MI2C_TWSTO_BIT    4
#define MI2C_TWSTA_BIT    5
#define MI2C_TWEA_BIT     6
#define MI2C_TWINT_BIT    7

#define MI2C_TWPS0_BIT    0
#define MI2C_TWPS1_BIT    1

#define MI2C_TWGCE_BIT    0

//TWPS Values
#define MI2C_TWPS_1   0
#define MI2C_TWPS_4   1
#define MI2C_TWPS_16  2
#define MI2C_TWPS_64  3

#define MI2C_DISABLE_GENERAL_CALL 0
#define MI2C_ENABLE_GENERAL_CALL  1

#define MI2C_TWSR_REG_MASK 0xF8


#endif