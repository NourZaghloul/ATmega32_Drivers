/*
 * TIMER_interface.h
 *
 *  Created on: Jun 23, 2024
 *      Author: Nour Zaghloul
 */

#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

#define TCCR0_WGM00					6u
#define TCCR0_WGM01					3u
#define TIMSK_TOIE0					0u




void Timer0_voidInit(void);

uint8 Timer0_u8SetCallBack(void(*Copy_pvcallBackFunc)(void));

void Timer0_voidSetPreloadValue(uint8 Copy_u8PreloadVal);


#endif /* TIMERS_INTERFACE_H_ */
