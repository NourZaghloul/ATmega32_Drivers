/*
 * LCD_cfg.h
 *
 *  Created on: May 4, 2024
 *      Author: Nour Zaghloul
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/******************** Mode Selection **********************
 * Configure the LCD bit mode, options are :	1- FOUR_BIT
 *												2- EIGHT_BIT
 */
#define CLCD_u8BIT_MODE			FOUR_BIT

/******************** RW Connection ***********************
 * Configure RW pin to DIO or GND, options		1- GND_CONNECTED
 * 												2- DIO_CONNECTED
 */
#define CLCD_u8RW_CONN_STS		GND_CONNECTED

/******************** Control Port *************************/

#define CLCD_u8CTRL_PORT		DIO_u8PORTA

#define CLCD_u8RS_PIN			DIO_u8PIN1

#if CLCD_u8RW_CONN_STS == DIO_CONNECTED
#define CLDC_u8RW_PIN			DIO_u8PIN1
#endif

#define CLCD_u8E_PIN			DIO_u8PIN2

/******************** Data Port ****************************/

#define CLCD_u8DATA_PORT		DIO_u8PORTA

#if CLCD_u8BIT_MODE == FOUR_BIT
#define CLCD_u8D4_PIN			DIO_u8PIN3
#define CLCD_u8D5_PIN			DIO_u8PIN4
#define CLCD_u8D6_PIN			DIO_u8PIN5
#define CLCD_u8D7_PIN			DIO_u8PIN6
#endif

/***********************************************************/
#endif /* LCD_CFG_H_ */
