#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"

#include "ADC_reg.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"
#include "ADC_interface.h"

void ADC_voidInit(void)
{
	/*Set AVCC as reference voltage*/
	SET_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);

	/*Select left or Right adjust according to resolution configuration*/
#if ADC_u8Resolution   == 	EIGHT_BITS
	SET_BIT(ADMUX, ADMUX_ADLAR);
#elif ADC_u8Resolution == 	TEN_BITS
	CLR_BIT(ADMUX, ADMUX_ADLAR);
#else
#error Wrong ADC_u8Resolution configuration option
#endif

	/*Disable Auto Trigger mode*/
	CLR_BIT(ADCSRA, ADCSRA_ADATE);

	/*Disable Interrupt*/
	CLR_BIT(ADCSRA, ADCSRA_ADIE);

	/*Enable ADC*/
	SET_BIT(ADCSRA, ADCSRA_ADEN);

	/*Configure the pre-scaler devision factor*/
	ADCSRA &= PRESCALER_BIT_MASK;
	ADCSRA |= ADC_u8PRESCALER_DIVISION_FACTOR << PRESCALER_BIT_POS;
}

uint16 ADC_u8GetChannelReading(uint8 Copy_u8Channel)
{
	/*Set the input channel*/
	ADMUX &= CHANNEL_BIT_MASK;		/*Clear the channel selection bits*/
	ADMUX |= Copy_u8Channel;

	/*Start conversion*/
	SET_BIT(ADCSRA, ADCSRA_ADSC);

	/*Polling on conversion complete flag*/
	while(!(GET_BIT(ADCSRA, ADCSRA_ADIF)));

	/*Clear conversion complete*/
	SET_BIT(ADCSRA, ADCSRA_ADIF);

	/*Get the Conversion result*/
#if ADC_u8Resolution   == 	EIGHT_BITS
	return ADCH;
#elif ADC_u8Resolution == 	TEN_BITS
	return ADC;
#endif
}
