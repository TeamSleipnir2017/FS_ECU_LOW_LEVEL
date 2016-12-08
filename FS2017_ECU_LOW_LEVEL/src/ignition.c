/*
 * ignition.c
 *
 * Created: 7.12.2016 12:50:39
 *  Author: jbbja
 */ 

#include "ignition.h"

void ignition_init(void)
{
	/* PIO Enable register */
	PIOC->PIO_PER			= IGN1;
	/* PIO Output register */
	PIOC->PIO_OER			= IGN1;
	
}