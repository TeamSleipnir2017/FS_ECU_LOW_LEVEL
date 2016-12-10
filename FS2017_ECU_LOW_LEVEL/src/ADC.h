/*
 * ADC.h
 *
 * Created: 8.12.2016 14:33:23
 *  Author: jbbja
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "global.h"
#include <asf.h>

#define ADC_CH0 0
#define ADC_CH1 1
#define ADC_CH2 2
#define ADC_CH3 3
#define ADC_CH4 4
#define ADC_CH5 5
#define ADC_CH6 6
#define ADC_CH7 7
#define ADC_CH8 8
#define ADC_CH9 9
#define ADC_CH10 10
#define ADC_CH11 11
#define ADC_CH12 12
#define ADC_CH13 13
#define ADC_CH14 14
#define ADC_CH15 15
// Channel 15 is temperature sensor

void adc_init(void); 
void adc_turn_on_channel (uint16_t channel_number);
void adc_interrupt_enable (uint32_t priority, uint16_t channel_number);
void adc_start ();
uint16_t adc_read(uint16_t channel_number);

#endif /* ADC_H_ */