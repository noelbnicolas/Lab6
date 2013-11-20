#include <msp430.h> 
#include "movement.h"

/*
 * main.c
 */


int main(void) {
	initTimerA();

	  while (1) {
		  RobotMovement(FORWARD);
		  RobotMovement(REVERSE);
		  RobotMovement(LEFT);
		  RobotMovement(SHARPLEFT);
		  RobotMovement(RIGHT);
		  RobotMovement(SHARPRIGHT);
	      }

}
