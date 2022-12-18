/*
 * timer_program.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Mohamed
 */

#include "../Utils/STD_TYPES.h"
#include "../Utils/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "timer_interface.h"
#include "timer_private.h"
#include "timer_CFG.h"

static void (*TIMER0_CTC_Callback)(void);

void TIMER0_vInit(void){
	/* CTC Mode */
	CLR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);

	/* OC0 disconnected */
	CLR_BIT(TCCR0, COM00);
	CLR_BIT(TCCR0, COM01);

	/* Set Compare match preload value */
	OCR0 = TIMER0_COMPARE_MATCH_VALUE;

	/* set prescaler divided by 64 */
	TCCR0 &= TIMER0_PRESCALER_MASK;
	TCCR0 |= TIMER0_PRESCALER;

	/* Enable interrupt */
	SET_BIT(TIMSK, OCIE0);
}

void TIMER0_vEnableInturrupt(u8 A_u8InterruptSource){
	SET_BIT(TIMSK, TOIE0);
	SET_BIT(TIMSK, OCIE0);
}

void TIMER0_vDisableInturrupt(u8 A_u8InterruptSource){
	CLR_BIT(TIMSK, TOIE0);
	CLR_BIT(TIMSK, OCIE0);
}

void TIMER0_vStartTimer(u8 A_u8TimerId){
	TCNT0 = 0;
	TCCR0 = ((TCCR0 & ~(0b111)) | TIMER0_PRESCALER);
}

void TIMER0_vStopTimer(u8 A_u8TimerId){
	TCCR0 = ((TCCR0 & ~(0b111)) | PS_NOCLK);
}

void TIMER0_vSetCallback(void (*fptr)(void)){
	TIMER0_CTC_Callback=  fptr;
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void){
	if (TIMER0_CTC_Callback != NULL)
		TIMER0_CTC_Callback();
}

void TIMER0_vSetCompareMatchValue(u8 A_u8OctValue){
	OCR0 = A_u8OctValue;
}




