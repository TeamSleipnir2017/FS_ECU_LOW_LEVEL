/*
 * ADC.c
 *
 * Created: 8.12.2016 14:33:07
 *  Author: jbbja
 */

#include "ADC.h" 

void adc_init(void)
{
	/* Enable ADC peripheral clock */
	PMC->PMC_PCER1 = (1 << (ID_ADC-32));
	
	/* Reset the ADC simulating, hardware reset */
	ADC->ADC_CR = ADC_CR_SWRST;
	
	/* Configure ADC prescaler */
	ADC->ADC_MR = ADC_MR_TRANSFER(1) | ADC_MR_TRACKTIM(1) | ADC_MR_PRESCAL(1) | ADC_MR_STARTUP_SUT24 | ADC_MR_SETTLING_AST17 | ADC_MR_ANACH_ALLOWED;
	
	/* Turn internal temperature sensor on */
	ADC->ADC_ACR = ADC_ACR_TSON;
	
	/* All gains set to 1 */
	ADC->ADC_CGR = 0;
	
	/* Every offset set to 0 */
	ADC->ADC_COR = 0;
}

void adc_turn_on_channel (uint16_t channel_number)
{
	/* CHx: Channel x Enable (ADC_CHER_CH0-15)
	0 = No effect.
	1 = Enables the corresponding channel. */
	ADC->ADC_CHER = (1 << channel_number);
}


void adc_start (void)
{
	/* Begin the ADC conversion (ADC control register)*/
	ADC->ADC_CR = ADC_CR_START;
}

void adc_interrupt_enable (uint32_t priority, uint16_t channel_number)
{
	/* Nested vector interrupt enable */
	enable_interrupt_vector(ADC_IRQn, priority);
	/* Choose channel number
		ADC_IER_EOC0-15 */
	ADC->ADC_IER = (1 << channel_number);	
}


uint16_t adc_read(uint16_t channel_number)
{
	adc_start ();
	while(!(ADC->ADC_ISR & (1 << channel_number)));//channel_number));
	return ADC->ADC_CDR[channel_number];
}

