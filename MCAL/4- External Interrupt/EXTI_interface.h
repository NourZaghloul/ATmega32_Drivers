/*
 * EXTI_interface.h
 *
 *  Created on: Jun 8, 2024
 *      Author: Nour Zaghloul
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
	INT0,
	INT1,
	INT2
}IntChannel_t;

typedef enum
{
	LOW_LEVEL,
	ON_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}SenseCtr_t;

void EXTI_voidInit(void);

uint8 EXTI_u8SetSenseCtrl(IntChannel_t copy_u8IntCh, SenseCtr_t COPY_SenseCtrl);

uint8 EXTI_u8EnableIntChannel(IntChannel_t Copy_Intch);

uint8 EXTI_u8DisableIntChannel(IntChannel_t Copy_Intch);

uint8 EXTI_u8SetCallBack(IntChannel_t Copy_Intch, void(*Copy_pvCallBackFunc)(void));


#endif /* EXTI_INTERFACE_H_ */
