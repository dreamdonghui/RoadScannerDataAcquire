/*
 * Hui_USBPort.c
 *
 * Created: 2020-05-13 14:06:50
 *  Author: TomorrowNeverComes
 */ 

#include "driver_init.h"
#include "utils.h"
#include "Hui_USBPort.h"
/**
 * Example of using USART_On_USBPort to write "Hello World" using the IO abstraction.
 *
 * Since the driver is asynchronous we need to use statically allocated memory for string
 * because driver initiates transfer and then returns before the transmission is completed.
 *
 * Once transfer has been completed the tx_cb function will be called.
 */

static void tx_cb_USART_On_USBPort(const struct usart_async_descriptor *const io_descr)
{
	/* Transfer completed */
}

void USART_On_USBPort_Output(uint8_t Data_USART_On_USBPort[], uint8_t arry_size)
{
	struct io_descriptor *io;

	usart_async_register_callback(&USART_On_USBPort, USART_ASYNC_TXC_CB, tx_cb_USART_On_USBPort);
	/*usart_async_register_callback(&USART_On_USBPort, USART_ASYNC_RXC_CB, rx_cb);
	usart_async_register_callback(&USART_On_USBPort, USART_ASYNC_ERROR_CB, err_cb);*/
	usart_async_get_io_descriptor(&USART_On_USBPort, &io);
	usart_async_enable(&USART_On_USBPort);

	io_write(io, Data_USART_On_USBPort, arry_size);
}
