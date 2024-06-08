/*
 * main.c
 *
 *  Created on: Jun 8, 2024
 *      Author: Nour Zaghloul
 */
#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "util/delay.h"s

int main()
{
	PORT_voidInit();

	EXTI_voidInit();

	GIE_voidEnableGlobal();

	while(1);


}

/*INT0 ISR*/
__attribute__((signal))void __vector_1(void);
void __vector_1 (void)
{
	DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_HIGH);
}


/*INT1 ISR*/
__attribute__((signal))void __vector_2(void);
void __vector_2 (void)
{
	DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_LOW);
}
