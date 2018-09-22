#include <msp430.h> 

// Author: Brian Harlow
// Class: Introduction to Embedded Systems
// Section: 3
// Date: 20 September 2018
// Microcontroller: MSP430G2553

// Program Description: This program is designed to turn on D1 (P1.0) when S1 (P1.3) is pressed. This is done by using an
//                      infinitely looping while loop to constantly check if S1 is pressed. If it is pressed, D1 will light up.
//                      If it is not pressed, D1 will be turned off.

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1SEL &= ~0x09;             // Sets P1.1 and P1.3 to GPIO
	P1SEL2 &= ~0x09;            // Sets P1.1 and P1.3 to GPIO
	P1DIR |= BIT0;              // P1.0 set to output
	P1DIR &= ~BIT3;             // P1.3 set to input
	P1REN |= BIT3;              // Pull-up/Pull-down resistor enabled for P1.3
	P1OUT |= BIT3;              // Pull-up/Pull-down resistor set to pull-down for P1.3
	while(1)                    // Initiate infinite loop
	{
	    if (P1IN & BIT3)        // Check condition for if button at P1.3 is pressed
	        P1OUT &= 0xFE;      // If check condition is met, the LED at P1.0 will be turned on
	    else
	        P1OUT |= BIT0;      // If check condition is not met, the LED at P1.0 will be turned off
	}
	return 0;
}
