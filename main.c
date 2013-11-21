#include <msp430.h> 
#include "movement.h"

/*
 * main.c
 */


int main(void) {
	initTimer();

	  while (1) {
		  RobotMovement(FORWARD);
		  Stop();
		  RobotMovement(REVERSE);
		  Stop();
		  RobotMovement(LEFT);
		  Stop();
		  RobotMovement(FORWARD);
		  Stop();
		  RobotMovement(SHARPLEFT);
		  Stop();
		  RobotMovement(FORWARD);
		  Stop();
		  RobotMovement(RIGHT);
		  Stop();
		  RobotMovement(FORWARD);
		  Stop();
		  RobotMovement(SHARPRIGHT);
		  Stop();
		  RobotMovement(FORWARD);
		  Stop();
	      }

}
