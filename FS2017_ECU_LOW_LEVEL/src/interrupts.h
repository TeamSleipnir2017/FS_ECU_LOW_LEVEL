/*
 * interrupts.h
 *
 * Created: 7.12.2016 14:32:06
 *  Author: jbbja
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include <asf.h>
#include "global.h"

/************************************************************************/
/* INTERRUPT PRIORITY QUEUE
	0. PIOA_Handler: Crank-, camshaft input
	1. TC0_Handler: Cylinder 1, Ign and Inj
	2. TC1_Handler: Cylinder 2, Ign and Inj
	3. TC2_Handler: Cylinder 3, Ign and Inj
	4. TC3_Handler: Cylinder 4, Ign and Inj
	5. TC4_Handler: Cylinder 5, Ign and Inj
	6. TC5_Handler: Cylinder 6, Ign and Inj
	7. TC6_Handler: Cylinder 7, Ign and Inj
	8. TC7_Handler: Cylinder 8, Ign and Inj
	9. TC8_Handler: Crank signal, cam signal, almenn klukka
	10. ADC_Handler: Analog to digital
	11. PIOD_Handler: Speed sensor input
	12. UOTGHS_Handler: USB comm.
	13. CAN0_Handler: Can bus comm.
	14. USART1_Handler: Telemetry
	15. TWI0_Handler: I2C
                                                                        */
/************************************************************************/

void enable_interrupt_vector(uint32_t irqn, uint32_t priority);

#endif /* INTERRUPTS_H_ */