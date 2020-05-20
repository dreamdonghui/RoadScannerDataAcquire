/*
 * Hui_SPIPort.c
 *
 * Created: 2020-05-18 10:38:52
 *  Author: TomorrowNeverComes
 * Designed to set up the data receive functions.
 * Take the driver_examples.c as a reference.
 */ 
 
 #include "driver_init.h"
 #include "utils.h"
 #include "Hui_DinPort.h"

 /**
 * Example of using SPI_0 to read the date from AD7779 using the IO abstraction.
 *
 * Since the driver is asynchronous we need to use statically allocated memory for string
 * because driver initiates transfer and then returns before the transmission is completed.
 *
 * Once transfer has been completed the rx_cb function will be called.
 */
 bool callback_indicator = false;
 static void complete_cb_Din_0(const struct spi_s_async_descriptor *const desc)
 {
	 callback_indicator = true;
	 /* Transfer completed */
	 
 }

 void Din_0_example(uint8_t *Din_buff, uint8_t Length)
 {
	 struct io_descriptor *io;
	 spi_s_async_get_io_descriptor(&SPI_0, &io);

	 spi_s_async_register_callback(&SPI_0, SPI_S_CB_RX, (FUNC_PTR)complete_cb_Din_0);
	 spi_s_async_enable(&SPI_0);
	 io_read(io, Din_buff, Length);
 }

