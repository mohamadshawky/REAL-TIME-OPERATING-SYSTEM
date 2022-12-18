/*
 * RTOS_program.c
 *
 *  Created on: Oct 30, 2022
 *      Author: Mohamed
 */
/* LIB */
#include "../Utils/STD_TYPES.h"
#include "../Utils/BIT_MATH.h"

/* MCAL */
#include "../GIE/GIE_interface.h"
#include "../TIMER0/timer_interface.h"

/* RTOS */
#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_CFG.h"

volatile xTask_t SystemTasks[TASK_NUMBER] = {{0}};

void RTOS_vStartScheduler(void){
	TIMER0_vSetCallback(&vScheduler);
	MGIE_vEnable();
	TIMER0_vInit();
	while (1);
}

void RTOS_vCreateTask(u8 A_u8Priority, u16 A_u16Periodicity, void (*A_vTaskFunc)(void)){
	SystemTasks[A_u8Priority].Periodicity = A_u16Periodicity;
	SystemTasks[A_u8Priority].vTaskFunc = A_vTaskFunc;
}

static void vScheduler(void){

	static u16 Local_u16TickCounter = 0;
	u8 Local_u8TaskCounter = 0;

	Local_u16TickCounter++;

	for (	;Local_u8TaskCounter < TASK_NUMBER; Local_u8TaskCounter++){
		if ((Local_u16TickCounter % SystemTasks[Local_u8TaskCounter].Periodicity) == 0){	// scheduler call
			if (SystemTasks[Local_u8TaskCounter].vTaskFunc != NULL){
				SystemTasks[Local_u8TaskCounter].vTaskFunc();
			}
			else {
				/* Do nothing */
			}
		}
	}
}
