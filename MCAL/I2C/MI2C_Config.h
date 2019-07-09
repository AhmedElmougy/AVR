#ifndef _MI2C_CONFIG_H_
#define _MI2C_CONFIG_H_

/*To calculate SCL use Equation:
 * SCL = CPU CLOCK /(16 + (2*TWBR*(4^TWPS)))
 *to config SCL 100 KHz TWBR =8, TWPS =1
 */
#define MI2C_TWPS_VALUE            MI2C_TWPS_1  
#define MI2C_TWBR_VALUE            8

#define MI2C_GENERAL_CALL_MODE     MI2C_DISABLE_GENERAL_CALL
//Put Micro controller slave address 
#define MI2C_SLAVE_ADDRESS         1
#endif