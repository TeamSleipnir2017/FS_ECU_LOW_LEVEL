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

//extern volatile struct cylinder cyl[NR_OF_CYL];

void waste_of_time_delay(uint32_t delay)
{
	for (uint32_t i = 0; i < delay; i++)
	{
		for (uint32_t j = 0; j < 1978; j++)
		{
			__asm__("nop");
		}
	}
}

#define TEST ADC_CH11 // Pin A9 Arduino Due

int main (void)
{
	/* Initialize the SAM system. Using ASF */
	sysclk_init();
	board_init();
	
	/* Enable peripheral clock controller */
	PMC->PMC_PCER0			= (1 << ID_PIOA);
	PMC->PMC_PCER0			= (1 << ID_PIOC);
	
	/* Initialize ignition outputs */
	ignition_init();
	
	/* Initialize crankshaft signal input */
	cranksignal_init();
	
	/* Initialize UART */
	uart_init();
	
	/* Initialize timer */
	timers_init();
	
	/* Initialize ADC */
	uart_print_string("Initialize ADC"); uart_new_line();
	adc_init();
	adc_turn_on_channel(TEST);
	uart_print_string("Read ADC"); uart_new_line();
	uint16_t read_adc = adc_read(TEST);
// 	PMC->PMC_PCER1 = (1 << (ID_ADC-32));
// 	
// 	ADC->ADC_CR = ADC_CR_SWRST;
// 	
// 	ADC->ADC_MR = ADC_MR_TRANSFER(1) | ADC_MR_TRACKTIM(0) | ADC_MR_PRESCAL(1) | ADC_MR_STARTUP_SUT24;
// 	
// 	ADC->ADC_CHER = ADC_CHER_CH0;
// 	
	
// 	ADC->ADC_CR = ADC_CR_START;
// 	while(!(ADC->ADC_ISR & ADC_ISR_EOC0));
// 	uint16_t read_adc = ADC->ADC_CDR[0];
/*	uart_print_int(read_adc); uart_new_line();*/
	
	
	// Enable ignition
	PIOC->PIO_SODR			= IGN1;
	// Disable ignition
	PIOC->PIO_CODR			= IGN1;
	

	cylinder_init();
	uart_print_string("Start"); uart_new_line();
	uart_print_string("Number 1: ");
	uart_print_int(cylinder[0].IgnCntTimingOn); uart_new_line();
	uart_print_string("Number 2: ");
	uart_print_int(cylinder[0].InjCntTimingOff); uart_new_line();
	uart_print_string("Start"); uart_new_line();
	uart_print_string("Number 1: ");
	uart_print_int(cylinder[1].IgnCntTimingOn); uart_new_line();
	uart_print_string("Number 2: ");
	uart_print_int(cylinder[1].InjCntTimingOff);
	
	while (1)
	{
		waste_of_time_delay(10000);
		uint16_t read_adc = adc_read(TEST);
		//uart_print_int(read_adc);
	}
	
		
}
/* Crankshaft signal and Camshaft signal handler */
void PIOA_Handler(void)
{
	uint32_t pio_status_register = PIOA->PIO_ISR;
	/* Pio controller pin data status register */
	if (PIOA->PIO_PDSR & CRANK_SIGNAL)
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
		//uart_transfer('a');
	}
	if (tc_status_register & TC_SR_COVFS)
	{
		//uart_transfer('o');
	}
	PIOC->PIO_SODR			= IGN1;
	
}