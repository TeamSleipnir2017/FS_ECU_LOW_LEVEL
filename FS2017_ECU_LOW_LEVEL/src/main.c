/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include "global.h"

int main (void)
{
	/* Initialize the SAM system. Using ASF */
	sysclk_init();
	board_init();
	
	/* Enable peripheral clock controller */
	PMC->PMC_PCER0			= ID_PIOA;
	PMC->PMC_PCER0			= ID_PIOC;
	
	/* Initialize ignition outputs */
	ignition_init();
	
	/* Initialize crankshaft signal input */
	cranksignal_init();
	
	/* Initialize UART */
	uart_init();
	
	/* Initialize timer */
	timers_init();
	
	
	// Enable ignition
	PIOC->PIO_SODR			= IGN1;
	// Disable ignition
	PIOC->PIO_CODR			= IGN1;
	
	uart_transfer('t');
	while (1)
	{
		
	}
	
		
}
/* Crankshaft signal and Camshaft signal handler */
void PIOA_Handler(void)
{
	/* Pio controller pin data status register */
	if (PIOA->PIO_PDSR & CRANKSIGNAL)
	{
		uart_transfer('a');
		if (PIOA->PIO_PDSR & IGN1)
		{
			uart_transfer('b');
			// Disable ignition
			PIOC->PIO_CODR			= IGN1;
		}
		else
		{
			uart_transfer('c');
			// Enable ignition
			PIOC->PIO_SODR			= IGN1;
		}
	}
}

void TC0_Handler(void)
{
	/* TC Staturs Register */
	/************************************************************************/
	/* By reading the register is every bit in it cleared
	      COVFS: Counter Overflow Status
		  CPAS: RA Compare Status
		  CPBS: RB Compare Status 
		  CPCS: RC Compare Status                                                              */
	/************************************************************************/
	uint32_t tc_status_register = TC0->TC_CHANNEL[0].TC_SR;
	if (tc_status_register & TC_SR_CPAS)
	{
		uart_transfer('a');
	}
	if (tc_status_register & TC_SR_COVFS)
	{
		uart_transfer('o');
	}
	PIOC->PIO_SODR			= IGN1;
	
}