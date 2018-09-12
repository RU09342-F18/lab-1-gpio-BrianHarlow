#include "msp.h"


#define SPEED1   50000
#define SPEED2   10000

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	P1DIR |= BIT0;
	P2DIR |= BIT0;
	int i = SPEED1;
	int j = SPEED2;
	while(1)
	{
	    if(i == 0)
	    {
	        P1OUT ^= BIT0;
	        i = SPEED1;
	    }
	    else
	    {
	        i = i - 1;
	    }
	    if(j == 0)
	    {
	        P2OUT ^= BIT0;
	        j = SPEED2;
	    }
	    else
	    {
	        j--;
	    }
	}
}
