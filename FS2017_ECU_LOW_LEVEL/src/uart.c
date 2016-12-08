/*
 * uart.c
 *
 * Created: 7.12.2016 15:17:39
 *  Author: jbbja
 */ 

#include "uart.h"

//#define CONSOLE_UART               UART
//#define CONSOLE_UART_ID            ID_UART
void uart_init(void)
{
	/* Configure peripheral clock UART. */
	PMC->PMC_PCER0 = ID_UART;
	/* Enable receiver and transmitter */
	UART->UART_CR = UART_CR_RXEN | UART_CR_TXEN;
	/* Turn parity mode off */
	UART->UART_MR = UART_MR_PAR_NO;	
	/* Baud rate generator register */
	UART->UART_BRGR = CLOCKDIVISION;
	
	/* FUTURE WORK */
	// Transmission interrupt enable to minimize calculation downtime
	//UART->UART_IER = UART_IER_ENDTX;
	// viljum 2 bit stop bits 8 bit data, asynchronous mode, parity mode off,
}

void uart_transfer(uint8_t transmit)
{
	while (!(UART->UART_SR & UART_SR_TXRDY));
	UART->UART_THR = transmit;
}