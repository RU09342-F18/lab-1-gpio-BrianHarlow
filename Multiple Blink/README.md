# Brian Harlow's Multiple Blink

## Program Purpose
This program was designed to blink two LEDs on an MSP430 development board at differing rates.

## Functionality
After setting both GPIOs to be outputs, an infinitely looping while loop is initiated. This while loop contains two individual if statements, one for each of the LEDs. Each if statement runs off of a counting variable which decrements to 0. Once the variable hits zero, the status of the LED is toggled with an XOR operation. After the LED is toggled, the counting variable is reset. Each LED is reset to a different value counting variable so that the LEDs blink at different rates. By default, the program will blink one LED five times faster than the other.

## Microcontrollers Used
* MSP430G2553 - Blinks D1 (P1.0) and D2 (P1.6)
* MSP432P401R - Blinks LED1 (P1.0) and LED2 (P2.0). The only differing code for this microcontroller is that the port for the second LED is not the same.

