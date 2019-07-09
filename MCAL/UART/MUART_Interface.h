#ifndef __MUART_INTERFACE_H__
#define __MUART_INTERFACE_H__


/**********************
 *Function Description : The function is to initialize 
 *UART Peripheral 
 *
 *Input Parameter  : Void
 *Output Parameter : Void
 */
void MUART_voidInitialization(void);

/**********************
 *Function Description : The function Send 8 bit frame
 *using UART 
 *
 *Input Parameter  : Void
 *Output Parameter : Void
 */
void MUART_voidSendByte(u8 Copy_Byte);
/**********************
 *Function Description : The function Receive 8 bit frame 
 *using UART 
 *
 *Input Parameter  : Void
 *Output Parameter : Void
 */
u8 MUART_voidRecieveByte(void);


#endif