#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1SEL &= ~BIT0;
	P1SEL2 &= ~BIT0;
	P1DIR |= BIT0;
	while(1)
	{
	    P1OUT ^= BIT0;
	    __delay_cycles(500000);
	}
	return 0;
}
