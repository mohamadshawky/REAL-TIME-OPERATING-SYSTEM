/*
  * RTOS_private.h
 *
 *  Created on: Oct 30, 2022
 *      Author: Mohamed
 */

#ifndef RTOS_RTOS_PRIVATE_H_
#define RTOS_RTOS_PRIVATE_H_

typedef struct {
	u16 Periodicity;
	void (*vTaskFunc)(void);
}xTask_t;

static void vScheduler(void);

#endif /* RTOS_RTOS_PRIVATE_H_ */
