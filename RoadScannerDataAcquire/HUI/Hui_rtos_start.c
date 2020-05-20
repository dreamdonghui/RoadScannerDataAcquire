/*
 * Hui_rtos_start.c
 *
 * Created: 2020-05-13 10:28:05
 *  Author: TomorrowNeverComes
 */ 
#include "atmel_start.h"
#include "Hui_rtos_start.h"
#include "Hui_USBPort.h"
#include "Hui_DinPort.h"

#define TASK_EXAMPLE_STACK_SIZE (128 / sizeof(portSTACK_TYPE))
#define TASK_EXAMPLE_STACK_PRIORITY (tskIDLE_PRIORITY + 1)
static TaskHandle_t      xCreatedExampleTask;
static SemaphoreHandle_t disp_mutex;

/**
 * OS example task
 *
 * \param[in] p The void pointer for OS task Standard model.
 *
 */
static void example_task(void *p)
{
	(void)p;
	while (1) {
		if (xSemaphoreTake(disp_mutex, ~0)) {
			/* add your code */
			static uint8_t example_USART_On_USBPort[ ] = "He00000o World!";

				USART_On_USBPort_Output(example_USART_On_USBPort,sizeof(example_USART_On_USBPort)/sizeof(uint8_t));
			static uint8_t buff[100 ];

//Din_0_example(buff,100);
//				USART_On_USBPort_Output(buff,sizeof(buff)/sizeof(uint8_t));
			xSemaphoreGive(disp_mutex);
		}
		os_sleep(1000);
	}
}

/*
 * Example
 */
void Hui_FREERTOS_V1000_0_example(void)
{
	disp_mutex = xSemaphoreCreateMutex();

	if (disp_mutex == NULL) {
		while (1) {
			;
		}
	}

	if (xTaskCreate(
	        example_task, "USBPORT", TASK_EXAMPLE_STACK_SIZE, NULL, TASK_EXAMPLE_STACK_PRIORITY, xCreatedExampleTask)
	    != pdPASS) {
		while (1) {
			;
		}
	}

	vTaskStartScheduler();

	return;
}
