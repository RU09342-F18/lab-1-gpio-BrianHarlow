#include <msp430.h> 

// Author: Brian Harlow
// Class: Introduction to Embedded Systems
// Section: 3
// Date: 20 September 2018
// Microcontroller: MSP430G2553

// Program Description: This program was designed to toggle the status of D1 (P1.0) every 500,000 clock cycles. This is done through
//                      the use of an infinitely looping while loop which uses an XOR to toggle D1 and then delays the desired amount
//                      of clock cycles.

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	    // stop watchdog timer
	P1SEL &= ~BIT0;                 // Sets P1.0 to be GPIO
	P1SEL2 &= ~BIT0;                // Sets P1.0 to be GPIO
	P1DIR |= BIT0;                  // Sets P1.0 to be output
	while(1)                        // Initiate infinite loop
	{
	    P1OUT ^= BIT0;              // Toggle status of D1
	    __delay_cycles(500000);     // Delay
	}
	return 0;
}
