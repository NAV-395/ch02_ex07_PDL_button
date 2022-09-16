#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"

int main(void)
{
    cy_rslt_t result;

    /* Initialize the device and board peripherals */
    result = cybsp_init() ;
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    __enable_irq();

    for (;;)
    {
        if(1UL == Cy_GPIO_Read(P0_4_PORT, P0_4_NUM))
        {
        	Cy_GPIO_Write(CYBSP_USER_LED_PORT, CYBSP_USER_LED_NUM,1);
        }
        else
        {
        	Cy_GPIO_Write(CYBSP_USER_LED_PORT, CYBSP_USER_LED_NUM,0);
        }
    }
}


