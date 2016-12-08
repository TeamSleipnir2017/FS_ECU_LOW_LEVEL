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
	PIOA->PIO_PER			= CRANKSIGNAL;
	/* PIO Disable Output register */
	PIOA->PIO_ODR			= CRANKSIGNAL;
	/* Enable interrupt */
	PIOA->PIO_IER			= CRANKSIGNAL;
	/* Enable Interrupts */
	NVIC_EnableIRQ(PIOA_IRQn);
	// ATH seinna
	//NVIC_SetPriority(PIOA_IRQn, 0);
}