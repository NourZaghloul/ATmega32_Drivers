/*
 * TIMERS_prog.c
 *
 *  Created on: Jun 23, 2024
 *      Author: Nour Zaghloul
 */
#include "STD_TYPES.h"
#include "ErrType.h"
#include "BIT_MATH.h"

#include "TIMERS_interface.h"
#include "TIMERS_cfg.h"
#include "TIMERS_prv.h"
#include "TIMERS_reg.h"


static void (*Timer0_pvCallBackFunc)(void)= NULL;

void Timer0_voidInit(void)
{
	/*Set normal mode*/
	CLR_BIT(TCCR0, TCCR0_WGM00);
	CLR_BIT(TCCR0, TCCR0_WGM01);

	/*Clear prescaler bits*/
	TCCR0 &= 0b11111000;

	/*Set prescaler to divide by 256*/
	TCCR0 |= 0b100;

	/*Set preload value*/
	TCNT0 = 220;

	/*Enable overflow interrupt*/
	SET_BIT(TIMSK, TIMSK_TOIE0);
}

uint8 Timer0_u8SetCallBack(void(*Copy_pvcallBackFunc)(void))
{
	uint8 Local_u8ErrorState = OK;
	if(Copy_pvcallBackFunc != NULL)
	{

	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}


void Timer0_voidSetPreloadValue(uint8 Copy_u8PreloadVal)
{
	TCNT0 = Copy_u8PreloadVal;
}

/*Timer0 overflow ISR*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if(Timer0_pvCallBackFunc != NULL)
	{
		Timer0_pvCallBackFunc();
	}
}
