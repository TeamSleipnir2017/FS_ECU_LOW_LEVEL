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

void enable_interrupt_vector(uint32_t irqn, uint32_t priority);

#endif /* INTERRUPTS_H_ */