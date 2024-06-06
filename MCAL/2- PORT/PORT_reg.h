/*
 * PORT_reg.h
 *
 *  Created on: Jun 3, 2024
 *      Author: Nour Zaghloul
 */

#ifndef PORT_REG_H_
#define PORT_REG_H_

#define PORTA	*((volatile uint8*)0x3B)
#define DDRA	*((volatile uint8*)0x3A)

#define PORTB	*((volatile uint8*)0x38)
#define DDRB	*((volatile uint8*)0x37)

#define PORTC	*((volatile uint8*)0x35)
#define DDRC	*((volatile uint8*)0x34)

#define PORTD	*((volatile uint8*)0x32)
#define DDRD	*((volatile uint8*)0x31)


#endif /* PORT_REG_H_ */
