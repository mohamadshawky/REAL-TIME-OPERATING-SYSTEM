/*
 * RTOS_interface.h
 *
 *  Created on: Oct 30, 2022
 *      Author: Mohamed
 */

#ifndef RTOS_RTOS_INTERFACE_H_
#define RTOS_RTOS_INTERFACE_H_

void RTOS_vStartScheduler(void);
void RTOS_vCreateTask(u8 A_u8Priority, u16 A_u16Periodicity, void (*A_vTaskFunc)(void));

#endif /* RTOS_RTOS_INTERFACE_H_ */
