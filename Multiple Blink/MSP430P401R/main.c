#include "msp.h"

// Author: Brian Harlow
// Class: Introduction to Embedded Systems
// Section: 3
// Date: 20 September 2018
// Microcontroller: MSP432P401R

// Program Description: This program was designed with the MSP432P401R microcontroller to blink LED1 (P1.0) and LED2 (P2.0) at
//                      different speeds. This is done through the use of infinitely looping while loop which contains individual
//                      if statements for each LED. Each if statement decrements a counting value which determines the rate at
//                      which each LED will blink. The higher the counting value is set, the slower the LED will blink.

#define SPEED1   60000  // Blink rate definition for LED1
#define SPEED2   10000  // Blink rate definition for LED2

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	P1DIR |= BIT0;              // P1.0 set to output
	P2DIR |= BIT0;              // P2.0 set to output
	int i = SPEED1;             // Integer variable definition for blink rate of LED1
	int j = SPEED2;             // Integer variable definition for blink rate of LED2
	while(1)                    // Initiate infinite loop
	{
	    if(i == 0)              // Check condition for if LED1 should be toggled
	    {
	        P1OUT ^= BIT0;      // If check condition is met, LED1 is toggled
	        i = SPEED1;         // Resets integer variable to original blink rate value
	    }
	    else
	    {
	        i = i - 1;          // If check condition is not met, integer variable is decremented
	    }
	    if(j == 0)              // Check condition for if LED2 should be toggled
	    {
	        P2OUT ^= BIT0;      // If check condition is met, LED2 is toggled
	        j = SPEED2;         // Resets integer variable to original blink rate value
	    }
	    else
	    {
	        j--;                // If check condition is not met, integer variable is decremented
	    }
	}
}
