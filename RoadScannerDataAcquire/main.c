#include <atmel_start.h>
#include <driver_examples.h>
#include "Hui_rtos_start.h"

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	Hui_FREERTOS_V1000_0_example();

	/* Replace with your application code */
	while (1) {
// Since we added the FreeRTOS system to manage the task, this loop will never be executed.
	}
}
