#ifndef ADC_REG_H_
#define ADC_REG_H_

#define ADMUX					*((volatile uint8*)0x27) /*ADC Multiplexer selection register*/
#define ADMUX_REFS1				7U						 /*Reference selection Bit1*/
#define ADMUX_REFS0				6U						 /*Reference selection Bit0*/
#define ADMUX_ADLAR				5U						 /*Left Adjust result*/

#define ADCSRA					*((volatile uint8*)0x26) /*ASC Control and status register*/
#define ADCSRA_ADEN				7u						 /*Enable*/
#define ADCSRA_ADSC				6u						 /*Start conversion*/
#define ADCSRA_ADATE			5u
#define ADCSRA_ADIF				4u
#define ADCSRA_ADIE				3u

#define ADCH					*((volatile uint8*)0x25)
#define ADCL					*((volatile uint8*)0x24)
#define ADC						*((volatile uint16*)0x24)


#endif
