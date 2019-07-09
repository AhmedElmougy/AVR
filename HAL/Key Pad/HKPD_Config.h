#ifndef __HKPD_Config_h__
#define __HKPD_Config_h__

#define KPD_REG PORTA
 //pin connections on keypad register
 
#define C1 3
#define C2 2
#define C3 1
#define C4 0
#define R1 4
#define R2 5
#define R3 6
#define R4 7

 

const u8 KeyPadArr[4][4]={{1,   2,  3,  'A'},
					      {4,   5,  6,  'B'},
					      {7,   8,  9,  'C'},
					      {'#', 0, '*', 'D'}};
							  
#endif