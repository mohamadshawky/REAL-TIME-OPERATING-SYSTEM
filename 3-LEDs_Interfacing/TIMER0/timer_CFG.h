/*
 * timer_CFG.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_TIMER_CFG_H_
#define MCAL_TIMER_CFG_H_
/*
 * Prescaler Options for TIMER0:
 *  				PS_NOCLK
 * 					PS_1
 *					PS_8
 *					PS_64
 *					PS_256
 * 					PS_1024
 */
#define TIMER0_PRESCALER				PS_64
/* select preload value for TIMER0..2 @ OV or CTC Modes */
#define TIMER0_COMPARE_MATCH_VALUE		125

/*
 * Prescaler Options for TIMER1:
 *  				PS_NOCLK
 * 					PS_1
 *					PS_8
 *					PS_64
 *					PS_256
 * 					PS_1024
 */
#define TIMER1_PRESCALER	PS_256

#endif /* MCAL_TIMER_CFG_H_ */
