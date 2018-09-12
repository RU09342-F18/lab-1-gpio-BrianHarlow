#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 &= ~LOCKLPM5;
	P1DIR |= BIT0;              // Sets GPIO to be output
	while(1)
	{
	    P1OUT ^= BIT0;
	    __delay_cycles(250000);
	}
	return 0;
}
