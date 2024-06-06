/*
 * lcd.h
 *
 *  Created on: May 2, 2024
 *  Author: Nour Zaghloul
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/****************** Function prototypes ***********************/

void CLCD_voidSendCmd(uint8 Copy_u8Cmd);

void CLCD_voidSendData(uint8 Copy_u8Data);

void CLCD_voidInit(void);

uint8 CLCD_u8SendString(const char* Copy_pchString);

void CLCD_VoidSendNumber(sint32 Copy_s32Number);

void CLCD_voidGoToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos);

uint8 CLCD_u8SendSpecialCharacter(uint8 Copy_u8LocationNum, uint8* Copy_pu8Pattern, uint8 Copy_u8XPos, uint8 Copy_u8YPos);

void CLCD_voidCleardisplay(void);

/*************************************************************/

#endif /* LCD_INTERFACE_H_ */
