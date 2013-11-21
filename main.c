#include <msp430.h> 
#include "movement.h"

/*
 * main.c
 */


int main(void) {
	WDTCTL = WDTPW|WDTHOLD;

	initTimer();

	while(1) {
	  RobotMovement(FORWARD);
	  _delay_cycles(1000000);
	  Stop();
	  _delay_cycles(1000000);
	  RobotMovement(REVERSE);
	  _delay_cycles(1000000);
	  Stop();
	  _delay_cycles(1000000);
	  RobotMovement(LEFT);
	  _delay_cycles(1000000);
	  Stop();
	  _delay_cycles(1000000);
	  RobotMovement(RIGHT);
	  _delay_cycles(1000000);
	  Stop();
	  _delay_cycles(1000000);
	}

	return 0 ;
}
