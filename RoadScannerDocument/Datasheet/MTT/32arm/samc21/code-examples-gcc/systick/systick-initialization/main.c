/*
 * Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries
 *
 * File:            main.c
 * Project:         systick-initialization
 * Date:            Nov 13, 2018
 * Compiler:        arm-gcc v6.3.1
 * 
 * Simple "GCC Executable" Code Example Project using the SysTick Timer.
 *
 * Configure SysTick to trigger an interrupt every millisecond and toggle LED0
 * every 1000mS.
 * 
 * Hardware Configuration: SAMC21 Xplained PRO (ATSAMC21J18A) 
 *
 */

/** INCLUDES ******************************************************************/

#include "sam.h"
#include "definitions.h"

/** VARIABLES *****************************************************************/

static uint32_t ul_tickcount=0 ;	// Global state variable for tick count

/** LOCAL PROTOTYPES **********************************************************/

void AppInit(void);					// Application Hardware/Software Initialization

/** main() ********************************************************************/

int main(void){	
    
	/* Initialize the SAM system - auto-generated code */
    SystemInit();
	
	/* Application hardware and software initialization */
	AppInit();

    /* Replace with your application code */
    while(1){
    }
}

/*******************************************************************************
 * Function:        void AppInit(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This routine takes care of all of the hardware/software
 *                  initialization that is required.
 *
 * Note:
 *
 ******************************************************************************/
void AppInit(void){
	
	/*	Clock initialization (CPU, AHB, APBx)
		The System RC Oscillator (RCSYS) provides the source for the main clock
		at chip startup. It is set to 4 MHz.
		
		Add code here to change the system clock
	*/
	
	// Assign the LED0 pin as OUTPUT
	PORT->Group[LED0_PORT].DIRSET.reg = LED0_PIN ;
	// Set the LED0 pin level, i.e. put to 3.3V -> this turns off the LED
	PORT->Group[LED0_PORT].OUTSET.reg = LED0_PIN ;

	// Configure SysTick to trigger every millisecond using the CPU Clock
	SysTick->CTRL = 0;					// Disable SysTick
	SysTick->LOAD = 3999UL;				// Set reload register for 1mS interrupts
	NVIC_SetPriority(SysTick_IRQn, 3);	// Set interrupt priority to least urgency
	SysTick->VAL = 0;					// Reset the SysTick counter value
	SysTick->CTRL = 0x00000007;			// Enable SysTick, Enable SysTick Exceptions, Use CPU Clock
	NVIC_EnableIRQ(SysTick_IRQn);		// Enable SysTick Interrupt
	
}

/*******************************************************************************
 * Function:        void SysTick_Handler(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This interrupt handler is called on SysTick timer underflow
 *
 * Note:
 *
 ******************************************************************************/
void SysTick_Handler(void){
	
	ul_tickcount++ ;
	// Toggle LEDs every second (i.e. 1000ms)
	if(ul_tickcount % 1000 == 0){
		// Toggle LED pin output level.
		PORT->Group[LED0_PORT].OUTTGL.reg = LED0_PIN ;
	}
}
