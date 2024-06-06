/*
 * KPD_prog.c
 *
 *  Created on: Jun 6, 2024
 *      Author: Nour Zaghloul
 */
#include "STD_TYPES.h"
#include "ErrType.h"

#include "Dio_interface.h"

#include "KPD_interface.h"
#include "KPD_prv.h"
#include "KPD_cfg.h"

uint8 KPD_u8GetPressedKey(void)
{
	uint8 Local_u8ColIndex, Local_u8RowIndex, Local_u8PinState, Local_u8PressedKey=KPD_u8NO_PRESSED_KEY_VAL;

	uint8 Local_au8ColArr[COL_NUM] = {KPD_u8COL0_PIN, KPD_u8COL1_PIN, KPD_u8COL2_PIN, KPD_u8COL3_PIN};

	uint8 Local_au8RowArr[ROW_NUM] = {KPD_u8ROW0_PIN, KPD_u8ROW1_PIN, KPD_u8ROW2_PIN, KPD_u8ROW3_PIN};

	uint8 Local_au8KPDArr[ROW_NUM][COL_NUM] = KPD_au8_BUTTON_ARR;

	/*Activate COL Pins*/
	for(Local_u8ColIndex=0u; Local_u8ColIndex < COL_NUM; Local_u8ColIndex++)
	{
		/*Activate the Current Pins*/
		DIO_u8SetPinValue(KPD_u8COL_PORT, Local_au8ColArr[Local_u8ColIndex], DIO_u8PIN_LOW);

		/*Read the Row Pins*/
		for(Local_u8RowIndex=0u; Local_u8RowIndex<ROW_NUM; Local_u8RowIndex++)
		{
			/*Read the current row*/
			DIO_u8ReadPinValue(KPD_u8ROW_PORT, Local_au8RowArr[Local_u8RowIndex], &Local_u8PinState);

			if(Local_u8PinState == DIO_u8PIN_LOW)
			{
				Local_u8PressedKey = Local_au8KPDArr[Local_u8RowIndex][Local_u8ColIndex];

				/*Polling with blocking until the key is released*/
				while(Local_u8PinState == DIO_u8PIN_LOW)
				{
					DIO_u8ReadPinValue(KPD_u8ROW_PORT, Local_au8RowArr[Local_u8RowIndex], &Local_u8PinState);
				}

				return Local_u8PressedKey;
			}
		}
		/*Deactivate the current column*/
		DIO_u8SetPinValue(KPD_u8COL_PORT, Local_au8ColArr[Local_u8ColIndex], DIO_u8PIN_HIGH);
	}

	return Local_u8PressedKey;
	}
