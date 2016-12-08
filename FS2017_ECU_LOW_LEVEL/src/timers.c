/*
 * timers.c
 *
 * Created: 7.12.2016 18:27:39
 *  Author: jbbja
 */ 

#include "timers.h"

void timers_init(void)
{
	/* Enable timer peripheral clock */
	PMC->PMC_PCER0 = (1 << ID_TC0);
	
	/* Initialize nested vector interrupts */
	/* Enable interrupt controller */
	/************************************************************************/
	/*
	TC  Chan    NVIC "irq"  IRQ handler    function PMC id
	TC0    0    TC0_IRQn    TC0_Handler    ID_TC0
	TC0    1    TC1_IRQn    TC1_Handler    ID_TC1
	TC0    2    TC2_IRQn    TC2_Handler    ID_TC2
	TC1    0    TC3_IRQn    TC3_Handler    ID_TC3
	TC1    1    TC4_IRQn    TC4_Handler    ID_TC4
	TC1    2    TC5_IRQn    TC5_Handler    ID_TC5
	TC2    0    TC6_IRQn    TC6_Handler    ID_TC6
	TC2    1    TC7_IRQn    TC7_Handler    ID_TC7
	TC2    2    TC8_IRQn    TC8_Handler    ID_TC8                                                                      */
	/************************************************************************/
	NVIC_DisableIRQ(TC0_IRQn);
	NVIC_ClearPendingIRQ(TC0_IRQn);
	NVIC_SetPriority(TC0_IRQn, 0); // ATHUGA SEINNA !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	NVIC_EnableIRQ(TC0_IRQn);
	
	/* TC interrupt Enable register */
	/************************************************************************/
	/* 
	COVFS: Counter Overflow
	CPAS: RA Compare
	CPBS: RB Compare
	CPCS: RC Compare
	                                                                     */
	/************************************************************************/
	TC0->TC_CHANNEL[0].TC_IER = TC_IER_COVFS;
	
	/************************************************************************/
	/*  
	TIMER_CLOCK1 Clock selected: internal MCK/2 clock signal (from PMC)
	TIMER_CLOCK2 Clock selected: internal MCK/8 clock signal (from PMC)
	TIMER_CLOCK3 Clock selected: internal MCK/32 clock signal (from PMC)
	TIMER_CLOCK4 Clock selected: internal MCK/128 clock signal (from PMC)
	TIMER_CLOCK5 Clock selected: internal SLCK clock signal (from PMC)  
	XC0 Clock selected: XC0
	XC1 Clock selected: XC1
	XC2 Clock selected: XC2                                                                  */
	/************************************************************************/
	/* TC Channel mode register (MCK / 2) */
	TC0->TC_CHANNEL[0].TC_CMR = TC_CMR_TCCLKS_TIMER_CLOCK1;
	
	/* TC channel control register, enable counter */
	TC0->TC_CHANNEL[0].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;
}

