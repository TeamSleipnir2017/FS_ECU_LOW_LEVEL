/*
 * sensors.c
 *
 * Created: 7.12.2016 13:53:33
 *  Author: jbbja
 */ 

#include "sensors.h"

void cranksignal_init(void)
{
	/* PIO Enable register */
	PIOA->PIO_PER			= CRANK_SIGNAL;
	/* PIO Disable Output register */
	PIOA->PIO_ODR			= CRANK_SIGNAL;
	/* Enable interrupt */
	PIOA->PIO_IER			= CRANK_SIGNAL;
	/* Enable Interrupts */
	NVIC_EnableIRQ(PIOA_IRQn);
	// ATH seinna
	//NVIC_SetPriority(PIOA_IRQn, 0);
}