/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>

/*! The buffer size for USART */
#define USART_ON_USBPORT_BUFFER_SIZE 16

struct usart_async_descriptor USART_On_USBPort;

static uint8_t USART_On_USBPort_buffer[USART_ON_USBPORT_BUFFER_SIZE];

struct spi_s_async_descriptor SPI_0;
static uint16_t               SPI_0_buf[16];

/**
 * \brief USART Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void USART_On_USBPort_CLOCK_init()
{

	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM4_GCLK_ID_CORE, CONF_GCLK_SERCOM4_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM4_GCLK_ID_SLOW, CONF_GCLK_SERCOM4_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));

	hri_mclk_set_APBCMASK_SERCOM4_bit(MCLK);
}

/**
 * \brief USART pinmux initialization function
 *
 * Set each required pin to USART functionality
 */
void USART_On_USBPort_PORT_init()
{

	gpio_set_pin_function(PB10, PINMUX_PB10D_SERCOM4_PAD2);

	gpio_set_pin_function(PB11, PINMUX_PB11D_SERCOM4_PAD3);
}

/**
 * \brief USART initialization function
 *
 * Enables USART peripheral, clocks and initializes USART driver
 */
void USART_On_USBPort_init(void)
{
	USART_On_USBPort_CLOCK_init();
	usart_async_init(&USART_On_USBPort, SERCOM4, USART_On_USBPort_buffer, USART_ON_USBPORT_BUFFER_SIZE, (void *)NULL);
	USART_On_USBPort_PORT_init();
}

void SPI_0_PORT_init(void)
{

	gpio_set_pin_level(PC12,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PC12, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PC12, PINMUX_PC12C_SERCOM7_PAD0);

	// Set pin direction to input
	gpio_set_pin_direction(PC13, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PC13,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PC13, PINMUX_PC13C_SERCOM7_PAD1);

	// Set pin direction to input
	gpio_set_pin_direction(PC14, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PC14,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PC14, PINMUX_PC14C_SERCOM7_PAD2);

	gpio_set_pin_level(PC11,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PC11, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PC11, PINMUX_PC11D_SERCOM7_PAD3);
}

void SPI_0_CLOCK_init(void)
{
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM7_GCLK_ID_CORE, CONF_GCLK_SERCOM7_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM7_GCLK_ID_SLOW, CONF_GCLK_SERCOM7_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));

	hri_mclk_set_APBDMASK_SERCOM7_bit(MCLK);
}

void SPI_0_init(void)
{
	SPI_0_CLOCK_init();
	spi_s_async_init(&SPI_0, SERCOM7, (uint8_t *)SPI_0_buf, 32);
	SPI_0_PORT_init();
}

void delay_driver_init(void)
{
	delay_init(SysTick);
}

void system_init(void)
{
	init_mcu();

	USART_On_USBPort_init();

	SPI_0_init();

	delay_driver_init();
}
