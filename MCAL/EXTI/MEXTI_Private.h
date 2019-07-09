#ifndef __MEXTI_Private_h__
#define __MEXTI_Private_h__

#define MEXTI_SREG   (*(volatile u8 *)(0x5F)) //Global Status  reg Definition

#define MEXTI_GICR   (*(volatile u8 *)(0x5B)) //Global interrupt control reg Definition
#define MEXTI_GIFR   (*(volatile u8 *)(0x5A)) //Global interrupt flag reg Definition
#define MEXTI_MCUCR  (*(volatile u8 *)(0x55)) //Micro controller Unit control reg Definition
#define MEXTI_MCUCSR (*(volatile u8 *)(0x54)) //Micro controller Unit control and status reg Definition

#define MEXTI_INT0_PIN PD2
#define MEXTI_INT1_PIN PD3
#define MEXTI_INT2_PIN PB2

#define MEXTI_INTF0 6
#define MEXTI_INTF1 7
#define MEXTI_INTF2 5


#define MEXTI_ISC00 0
#define MEXTI_ISC01 1
#define MEXTI_ISC10 2
#define MEXTI_ISC11 3

#define MEXTI_ISC2  6

#define MEXTI_SREG_I 7


#endif