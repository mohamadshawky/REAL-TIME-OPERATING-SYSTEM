/*
 * main.c
 *
 *  Created on: Oct 30, 2022
 *      Author: Mohamed
 */
#include "Utils/STD_TYPES.h"
#include "Utils/BIT_MATH.h"

#include "MCAL/DIO/DIO_interface.h"
#include "RTOS/RTOS_interface.h"

void LEDs_Init(void);
void LED1(void);
void LED2(void);
void LED3(void);

int main(void){

	LEDs_Init();
	RTOS_vCreateTask(0,1000,&LED1);
	RTOS_vCreateTask(1,2000,&LED2);
	RTOS_vCreateTask(2,3000,&LED3);

	RTOS_vStartScheduler();

	return 0;
}
void LEDs_Init(void){
	DIO_SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA, DIO_PIN1, DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA, DIO_PIN2, DIO_OUTPUT);
}

void LED1(void){
	static u8 Local_u8State = 0;
	TOG_BIT(Local_u8State, 0);
	DIO_SetPinValue(DIO_PORTA, DIO_PIN0, Local_u8State);
}

void LED2(void){
	static u8 Local_u8State = 0;
		TOG_BIT(Local_u8State, 0);
		DIO_SetPinValue(DIO_PORTA, DIO_PIN1, Local_u8State);
}

void LED3(void){
	static u8 Local_u8State = 0;
			TOG_BIT(Local_u8State, 0);
			DIO_SetPinValue(DIO_PORTA, DIO_PIN2, Local_u8State);
}
