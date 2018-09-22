#include <msp430.h> 

// Author: Brian Harlow
// Class: Introduction to Embedded Systems
// Section: 3
// Date: 20 September 2018
// Microcontroller: MSP430G2553

// Program Description: This program was designed with the MSP430G2553 microcontroller to blink D1 (P1.0) and D2 (P1.6) at
//                      different speeds. This is done through the use of infinitely looping while loop which contains individual
//                      if statements for each LED. Each if statement decrements a counting value which determines the rate at
//                      which each LED will blink. The higher the counting value is set, the slower the LED will blink.

#define SPEED1   100000 // Blink rate definition for D1
#define SPEED2   10000  // Blink rate definition for D2

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1SEL &= ~0x41;             // P1.6 and P1.0 set to GPIO
	P1SEL2 &= ~0x41;            // P1.6 and P1.0 set to GPIO
	P1DIR |= 0x41;              // P1.6 and P1.0 set to output
	long i = SPEED1;            // Long variable definition for blink rate of D1
	long j = SPEED2;            // Long variable definition for blink rate of D2
	while(1)                    // Initiate infinite loop
	{
	    if(j == 0)              // Check condition for if D2 should be toggled
	    {
	        P1OUT ^= BIT6;      // If check condition is met, D2 is toggled
	        j = SPEED2;         // Resets long variable to original blink rate
	    }
	    else
	    {
	        j--;                // If check condition is not met, long variable is decremented
	    }
	    if(i == 0)              // Check condition for if D1 should be toggled
	    {
	        P1OUT ^= BIT0;      // If check condition is met, D1 is toggled
	        i = SPEED1;         // Resets long variable to original blink rate
	    }
	    else
	    {
	        i--;                // If check condition is not met, long variable is decremented
	    }
	}
	return 0;
}
