/*
 * TIMERS_reg.h
 *
 *  Created on: Jun 23, 2024
 *      Author: Nour Zaghloul
 */

#ifndef TIMERS_REG_H_
#define TIMERS_REG_H_

#define TCCR0	*((volatile uint8*)0x53)
#define TIMSK	*((volatile uint8*)0x59)
#define TCNT0	*((volatile uint8*)0x52)



#endif /* TIMERS_REG_H_ */
