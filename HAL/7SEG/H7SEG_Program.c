#include "L_STD_Types.h"
#include "L_UTILS.h"
#include "MDIO_Interface.h"
#include "H7SEG_Private.h"
#include "H7SEG_Interface.h"

void H7SEG_INIT(u8 REG) //initialize 7Seg in a given port
{
	MDIO_SetDirection_Reg(REG,OUTPUT); //initialize whole port as o/p
}
void H7SEG_Disp_Num(u8 REG,u8 NUMBER) // display a number from 0 to 9
{
	MDIO_Write_Reg(REG,Seven_seg[NUMBER]);
}