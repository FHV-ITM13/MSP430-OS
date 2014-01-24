/*
 * ======== Standard MSP430 includes ========
 */
#include <msp430.h>

/*
 * ======== Grace related includes ========
 */
#include <ti/mcu/msp430/Grace.h>

#include "scheduler.h"

#define LED_1 BIT0

void* thread_function_1(void* param) {
	while (1) {
		// if LED is on, turn it off
		if (!(P1OUT & LED_1)) {
			P1OUT ^= LED_1;
		}
	}

	return 0;
}

void* thread_function_2(void* param) {
	while (1) {
		// if LED is on, turn it off
		if (P1OUT & LED_1) {
			P1OUT ^= LED_1;
		}
	}

	return 0;
}

/*
 *  ======== main ========
 */
int main(void) {
	Grace_init();                   // Activate Grace-generated configuration

	// >>>>> Fill-in user code here <<<<<

	// we want to blink led 1
	P1DIR = LED_1;

	schedulerStartThread(&thread_function_1);
	schedulerStartThread(&thread_function_2);

	while (1) {

	}

	return (0);
}
