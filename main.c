#include <msp430.h> 
#include "movement.h"

/*
 * main.c
 */


int main(void) {
	initTimer();

	  while (1) {
//		  RobotMovement(FORWARD);
//		  __delay_cycles(1000000);
//		  RobotMovement(REVERSE);
//		  __delay_cycles(1000000);
//		  RobotMovement(LEFT);
//		  __delay_cycles(10000);
//		  RobotMovement(SHARPLEFT);
//		  RobotMovement(RIGHT);
//		  __delay_cycles(10000);
//		  RobotMovement(LEFT);
//		  __delay_cycles(100000);
		  RobotMovement(RIGHT);
		  __delay_cycles(100000);
//		  RobotMovement(SHARPRIGHT);
	      }
}
