/*
 * timer_interface.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_TIMER_INTERFACE_H_
#define MCAL_TIMER_INTERFACE_H_


void TIMER0_vInit(void);
void TIMER0_vEnableInturrupt(u8 A_u8InterruptSource);
void TIMER0_vDisableInturrupt(u8 A_u8InterruptSource);

void TIMER0_vStartTimer(u8 A_u8TimerId);
void TIMER0_vStopTimer(u8 A_u8TimerId);
void TIMER0_vSetCallback(void (*fptr)(void));

void TIMER0_vSetCompareMatchValue(u8 A_u8OctValue);

#endif /* MCAL_TIMER_INTERFACE_H_ */
