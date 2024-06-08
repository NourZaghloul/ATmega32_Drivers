/*
 * EXTI_reg.h
 *
 *  Created on: Jun 8, 2024
 *      Author: Nour Zaghloul
 */

#ifndef EXTI_REG_H_
#define EXTI_REG_H_

#define GICR			*((volatile uint8*)0x5B)	/*General Interrupt control register*/
#define GICR_INT0		6u							/*Int0 bit*/
#define GICR_INT1		7u							/*Int1 bit*/
#define GICR_INT2		5u							/*Int2 bit*/

#define MCUCR			*((volatile uint8*)0x55)	/*MCU Control Register*/
#define MCUCR_ISC00		0u							/*INT0 sense control bit0*/
#define MCUCR_ISC01		1u							/*INT0 sense control bit0*/
#define MCUCR_ISC10		2u							/*INT1 sense control bit0*/
#define MCUCR_ISC11		3u							/*INT1 sense control bit0*/

#define MCUCSR			*((volatile uint8*)0x54)
#define MCUCSR_ISC2		6u


#endif /* EXTI_REG_H_ */
