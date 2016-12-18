/*
 * uart.h
 *
 * Created: 7.12.2016 15:17:54
 *  Author: jbbja
 */ 


#ifndef UART_H_
#define UART_H_

#define BAUDRATE 115200
#define CLOCKDIVISION ATSAM3X8E_MCK/(BAUDRATE*16)
#define PARITYTYPE UART_MR_PAR_NO



#include "global.h"

void uart_init(void);
void uart_transfer(uint8_t transmit);
void uart_print_int(uint32_t data);
void uart_new_line(void);
void uart_print_string(char * data);

#endif /* UART_H_ */