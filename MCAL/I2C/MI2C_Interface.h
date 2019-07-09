#ifndef _MI2C_INTERFACE_H_
#define _MI2C_INTERFACE_H_

//I2C Expected status
#define MI2C_START_SENT                   0x08
#define MI2C_REPEATED_START_SENT          0x10
#define MI2C_SLA_W_SENT_WITH_ACK          0x18
#define MI2C_SLA_W_SENT_WITHOT_ACK        0x20
#define MI2C_DATA_SENT_WITH_ACK           0x28
#define MI2C_DATA_SENT_WITHOUT_ACK        0x30
#define MI2C_ARBITRATION_LOST             0x38
#define MI2C_SLA_R_RECEIVED_WITH_ACK      0x40
#define MI2C_SLA_R_RECEIVED_WITHOT_ACK    0x48
#define MI2C_DATA_RECEIVED_WITH_ACK       0x50
#define MI2C_DATA_RECEIVED_WITHOUT_ACK    0x58

#define MI2C_WRITE_OP  0
#define MI2C_READ_OP   1

void MI2C_voidInit(void);
void MI2C_voidSendStartCondition(void);
void MI2C_voidSendStopCondition(void);
u8   MI2C_u8CheckStatus(u8 Copy_u8ExpectedStatus);
void MI2C_voidSendSlaveAddress(u8 Copy_u8SlaveAdd,u8 Copy_u8Operation);
void MI2C_voidSendByte(u8 Copy_u8Data);
u8   MI2C_u8ReceiveDataWithNoAck(void);

#endif