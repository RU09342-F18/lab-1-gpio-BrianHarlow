#include <msp430.h> 

// Author: Brian Harlow
// Class: Introduction to Embedded Systems
// Section: 3
// Date: 20 September 2018
// Microcontroller: MSP430F5529

// Program Description: This program is designed to turn on LED1 (P1.0) when S2 (P1.1) is pressed. This is done by using an
//                      infinitely looping while loop to constantly check if S2 is pressed. If it is pressed, LED1 will light up.
//                      If it is not pressed, LED1 will be turned off.

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1SEL &= ~0x03;             // P1.0 and P1.1 set to GPIO
	P1DIR |= BIT0;              // P1.0 set to output
	P1DIR &= ~BIT1;             // P1.1 set to input
	P1REN |= BIT1;              // Pull-up/Pull-down resistor enabled for P1.1
	P1OUT |= BIT1;              // Pull-up/Pull-down resistor set to pull-down for P1.1
	while(1)                    // Initiate infinite loop
	{
	    if (P1IN & BIT1)        // Check condition for if button at P1.1 is pushed
	        P1OUT &= 0xFE;      // Turns on LED1 (P1.0) if check condition is met
	    else
	        P1OUT |= BIT0;      // If check condition is not met, LED1 is turned off
	}
	return 0;
}
