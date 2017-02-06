/*
 * ADC.c
 *
 * Created: 8.12.2016 14:33:07
 *  Author: jbbja
 */

#include "ADC.h" 

/* A global Analog to Digital Controller initialization function */
void adc_initialize(void)
{
	adc_init(ADC, sysclk_get_main_hz(), ADC_FREQ_MAX, ADC_STARTUP_TIME_4);
	
}
// void adc_init(void)
// {
// 	// Enable ADC peripheral clock
// 	PMC->PMC_PCER1 = (1 << (ID_ADC-32));
// 	
// 	// Reset the ADC simulating, hardware reset
// 	ADC->ADC_CR = ADC_CR_SWRST;
// 	
// 	// Configure ADC prescaler
// 	ADC->ADC_MR = ADC_MR_TRANSFER(1) | ADC_MR_TRACKTIM(1) | ADC_MR_PRESCAL(1) | ADC_MR_STARTUP_SUT24 | ADC_MR_SETTLING_AST17 | ADC_MR_ANACH_ALLOWED;
// 	ADC->ADC_MR &= ADC_MR_FREERUN_OFF;
// 	// Turn internal temperature sensor on
// 	//ADC->ADC_ACR = ADC_ACR_TSON;
// 	
// 	// All gains set to 1 
// 	ADC->ADC_CGR = 0;
// 	
// 	// Every offset set to 0 
// 	ADC->ADC_COR = 0;
// 	
// 	// Includes channel number in the last converted data register (ADC_LCDR)
// 	// This is used in the interrupt routine
// 	ADC->ADC_EMR |=  ADC_EMR_TAG;
// 	
// 	// Initialize variables
// 	AdcFlag = 0;
// 	for (int i = 0; i < NR_OF_ACTIVE_ADC_CHANNELS; i++)
// 		AdcData[i] = 0;
// }
// 
// /* A global turn on ADC channel function */
// void adc_turn_on_channel (uint16_t channel_number)
// {
// 	// Use definitions from ADC.h, ADC_CH0-15 
// 	ADC->ADC_CHER = (1 << channel_number);
// }
// 
// /* A global turn on ADC channels function, remember to define how many channels are used */
// void adc_turn_on_multiple_channels (uint8_t channel_number[NR_OF_ACTIVE_ADC_CHANNELS], uint8_t enable_adc_interrupt, uint8_t adc_interrupt_priority)
// {
// 	for (int i = 0; i < NR_OF_ACTIVE_ADC_CHANNELS; i++){
// 		// Turn on each described channel
// 		adc_turn_on_channel(channel_number[i]);
// 		// Store the channel numbers for interrupts
// 		uart_print_string("Channel: "); uart_print_int(channel_number[i]);uart_new_line();
// 		AdcChannels[i] = channel_number[i];
// 		if (enable_adc_interrupt)
// 			adc_interrupt_enable(adc_interrupt_priority, channel_number[i]);
// 	}
// }
// 
// /* A global ADC start function */
// void adc_start (void)
// {
// 	// Begin the ADC conversion (ADC control register)
// 	ADC->ADC_CR = ADC_CR_START;
// }
// 
// /* A global ADC interrupt enable function */
// void adc_interrupt_enable (uint32_t priority, uint16_t channel_number)
// {
// 	// Nested vector interrupt enable 
// 	enable_interrupt_vector(ADC_IRQn, priority);
// 	// Choose channel number, ADC_CH0-15 
// 	ADC->ADC_IER = (1 << channel_number);	
// }
// 
// /* A global ADC read function for a specific channel */
// uint16_t adc_read(uint16_t channel_number)
// {
// 	// Start ADC conversion
// 	adc_start ();
// 	// Wait for ADC conversion to complete, not time efficient
// 	while(!(ADC->ADC_ISR & (1 << channel_number)));
// 	// Return the ADC value
// 	return ADC->ADC_CDR[channel_number];
// }

void ADC_Handler(void)
{
	uint32_t status = ADC->ADC_ISR;
	uint16_t Result = ADC->ADC_LCDR; //Last converted data register
	uint16_t ChannelNumber = ((Result & 0xF000) >> 11);
	
	//uart_print_int(ChannelNumber);
// 	for (int i = 0; i < NR_OF_ACTIVE_ADC_CHANNELS; i++)
// 	{
// 		if (status & (1 << AdcChannels[i]))
// 		{
// 			AdcData[i] = ADC->ADC_CDR[i];
// 		}
// 	}
}