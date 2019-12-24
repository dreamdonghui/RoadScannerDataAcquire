/*
 * RoadScannerDataAcquire.c
 *
 * Created: 2019-12-18 15:18:10
 * Author : lenovo
 */ 


#include "sam.h"


/** VARIABLES *****************************************************************/


/** LOCAL PROTOTYPES **********************************************************/


int main(void)
{
    /* Initialize the SAM system */
    SystemInit();


    /* Replace with your application code */
	//将所有的PC口设置为输出。
	REG_PORT_DIRSET2 = 0xffffffff;
	//将所有的PC口置为低电平以点亮LED。（LED另一端为3.3V）
	REG_PORT_OUTCLR2 = 0xffffffff;
    while (1) 
    {

    }
}
