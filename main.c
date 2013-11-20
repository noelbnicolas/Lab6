#include <msp430.h> 
#include "movement.h"

/*
 * main.c
 */


int main(void) {
	initTimerA();

	  while (1) {
		  RobotMovement(FORWARD); //goes forward
//		  RobotMovement(REVERSE); //goes left
//		  RobotMovement(LEFT); //goes left
//		  RobotMovement(SHARPLEFT); //goes sharp left
//		  RobotMovement(RIGHT); //goes left
//		  RobotMovement(SHARPRIGHT); //goes right
	      }

}
