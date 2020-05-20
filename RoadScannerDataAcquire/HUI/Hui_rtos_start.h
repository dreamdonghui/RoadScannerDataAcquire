/*
 * Hui_rtos_start.h
 *
 * Created: 2020-05-13 10:42:30
 *  Author: TomorrowNeverComes
 */ 


#ifndef HUI_RTOS_START_H_
#define HUI_RTOS_START_H_


#ifdef __cplusplus
extern "C" {
	#endif /* __cplusplus */

	#include <FreeRTOS.h>
	#include <task.h>
	#include <semphr.h>
	#include <hal_rtos.h>

	void Hui_FREERTOS_V1000_0_example(void);

	#ifdef __cplusplus
}
#endif /* __cplusplus */



#endif /* HUI_RTOS_START_H_ */