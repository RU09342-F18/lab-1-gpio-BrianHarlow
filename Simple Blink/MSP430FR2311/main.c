#include <msp430.h> 

// Author: Brian Harlow
// Class: Introduction to Embedded Systems
// Section: 3
// Date: 20 September 2018
// Microcontroller: MSP430FR2311

// Program Description: This program was designed to toggle the status of LED1 (P1.0) every 250,000 clock cycles. This is done through
//                      the use of an infinitely looping while loop which uses an XOR to toggle LED1 and then delays the desired amount
//                      of clock cycles. This program runs the same as the simple blink for the MSP430G2553 microcontroller; however,
//                      this microcontroller requires that the port registers be unlocked to be changed by the code.

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	    // stop watchdog timer
	PM5CTL0 &= ~LOCKLPM5;           // Allows changes to port registers
	P1DIR |= BIT0;                  // Sets GPIO to be output
	while(1)                        // Initiate infinite loop
	{
	    P1OUT ^= BIT0;              // Toggle status of LED1
	    __delay_cycles(250000);     // Delay
	}
	return 0;
}
