/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

/**
 * Example of using USART_On_USBPort to write "Hello World" using the IO abstraction.
 *
 * Since the driver is asynchronous we need to use statically allocated memory for string
 * because driver initiates transfer and then returns before the transmission is completed.
 *
 * Once transfer has been completed the tx_cb function will be called.
 */

static uint8_t example_USART_On_USBPort[12] = "Hello World!";

static void tx_cb_USART_On_USBPort(const struct usart_async_descriptor *const io_descr)
{
	/* Transfer completed */
}

void USART_On_USBPort_example(void)
{
	struct io_descriptor *io;

	usart_async_register_callback(&USART_On_USBPort, USART_ASYNC_TXC_CB, tx_cb_USART_On_USBPort);
	/*usart_async_register_callback(&USART_On_USBPort, USART_ASYNC_RXC_CB, rx_cb);
	usart_async_register_callback(&USART_On_USBPort, USART_ASYNC_ERROR_CB, err_cb);*/
	usart_async_get_io_descriptor(&USART_On_USBPort, &io);
	usart_async_enable(&USART_On_USBPort);

	io_write(io, example_USART_On_USBPort, 12);
}

/**
 * Example of using SPI_0 to write "Hello World" using the IO abstraction.
 *
 * Since the driver is asynchronous we need to use statically allocated memory for string
 * because driver initiates transfer and then returns before the transmission is completed.
 *
 * Once transfer has been completed the tx_cb function will be called.
 */

static uint8_t example_SPI_0[12] = "Hello World!";

static void complete_cb_SPI_0(const struct spi_s_async_descriptor *const desc)
{
	/* Transfer completed */
}

void SPI_0_example(void)
{
	struct io_descriptor *io;
	spi_s_async_get_io_descriptor(&SPI_0, &io);

	spi_s_async_register_callback(&SPI_0, SPI_S_CB_TX, (FUNC_PTR)complete_cb_SPI_0);
	spi_s_async_enable(&SPI_0);
	io_write(io, example_SPI_0, 12);
}

void delay_example(void)
{
	delay_ms(5000);
}
