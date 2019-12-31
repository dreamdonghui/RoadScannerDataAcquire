#include <atmel_start.h>
#include <driver_examples.h>

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	/* Replace with your application code */
	while (1) {
	USART_On_USBPort_example();
	delay_ms(1000);
	}
}
