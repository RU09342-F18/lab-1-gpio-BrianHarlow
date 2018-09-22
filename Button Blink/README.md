# Brian Harlow's Button Blink

## Program Purpose
This program was designed to blink an LED on an MSP430 development board with the push of a button.

## Functionality
After the desired LED pin is set to GPIO output, and the desired button pin is set to GPIO input, an infinitely looping while loop is initiated. This while loop uses a nested if statement to constantly check if the desired button is being pressed. If the button is being pressed, the LED is turned on with an AND operation. If the button is not being pressed, the LED is turned off with an OR operation. 

## Microcontrollers Used
* MSP430G2553 - The button used is S1 (P1.3) and the LED used is D1 (P1.0).
* MSPF5529 - The button used is S2 (P1.1) and the LED used is LED1(P1.0). The only difference with this microcontroller's code is that it only required one line to set the pins to GPIO.
