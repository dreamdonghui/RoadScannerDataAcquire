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
	//�����е�PC������Ϊ�����
	REG_PORT_DIRSET2 = 0xffffffff;
	//�����е�PC����Ϊ�͵�ƽ�Ե���LED����LED��һ��Ϊ3.3V��
	REG_PORT_OUTCLR2 = 0xffffffff;
    while (1) 
    {

    }
}
