#include <atmel_start.h>
#include <driver_examples.h>
#include "rtos_start.h"

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	FREERTOS_V1000_0_example();

	/* Replace with your application code */
	while (1) {
	USART_On_USBPort_example();
	delay_ms(1000);
	}
}
