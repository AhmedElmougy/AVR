#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define MSPI_SPDR (*(volatile u8 *)(0x2F))  //SPDR Reg
#define MSPI_SPSR (*(volatile u8 *)(0x2E))  //SPSR Reg
#define MSPI_SPCR (*(volatile u8 *)(0x2D))  //SPCR Reg

#endif