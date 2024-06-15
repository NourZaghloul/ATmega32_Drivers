/*
 * EXTI_cfg.h
 *
 *  Created on: Jun 8, 2024
 *      Author: Nour Zaghloul
 */

#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_

/*Configure the sense ctrl option for INT0 channel, Options:
 * 																1-EXTI_LOW_LEVEL
 * 																2-EXTI_ON_CHANGE
 * 																3-EXTI_FALLING_EDGE
 * 																4-EXTI_RISING_EDGE		*/
#define INT0_SENSE_CTRL					EXTI_FALLING_EDGE

#define INT1_SENSE_CTRL					EXTI_FALLING_EDGE

#define INT2_SENSE_CTRL					EXTI_FALLING_EDGE

/********************************************************************************/
/*Configure the initial state of INT0,1,2 channel, Options are:
 * 																1- ENABLE
 * 														   		2- DISABLE*/
#define INT0_INIT_STATE					ENABLE

#define INT1_INIT_STATE					ENABLE

#define INT2_INIT_STATE					DISABLE


#endif /* EXTI_CFG_H_ */
