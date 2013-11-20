/*
 * movement.c
 *
 *  Created on: Nov 19, 2013
 *      Author: C15Noel.Nicolas
 */
#include <msp430.h>
#include "movement.h"



//P2.1 red right, P2.0 black right, P1.2 red left, P1.1 black left

void initTimerA(){

	WDTCTL = WDTPW|WDTHOLD;
	P1DIR |= BIT2;                // TA0CCR1 on P1.2
	P1SEL |= BIT2;                // TA0CCR1 on P1.2

	P1DIR |= BIT1;
	P1SEL |= BIT1;

	P2DIR |= BIT1;                // TA0CCR1 on P2.1
	P2SEL |= BIT1;                // TA0CCR1 on P2.1

	P2DIR |= BIT0;
	P2SEL |= BIT0;

	TA0CTL &= ~MC1|MC0;            // stop timer A0
	TA1CTL &= ~MC1|MC0;            // stop timer A1

	TA0CTL |= TACLR;                // clear timer A0
	TA1CTL |= TACLR;                // clear timer A1

	TA0CTL |= TASSEL1;           // configure for SMCLK
	TA1CTL |= TASSEL1;           // configure for SMCLK

	TA0CCR0 = 100;				// set signal period to 100 clock cycles (~100 microseconds)
	TA0CCR1 = 60;				// set duty cycle to 75/100 (75%)

	TA1CCR0 = 100;				// set signal period to 100 clock cycles (~100 microseconds)
	TA1CCR1 = 60;				// set duty cycle to 75/100 (75%)


	TA0CCTL0 |= OUTMOD_5;
	TA0CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode

	TA1CCTL0 |= OUTMOD_5;
	TA1CCTL1 |= OUTMOD_7;

	TA0CTL |= MC0;                // count up
	TA1CTL |= MC0;                // count up
}

// Mod 7 is 75% Mod 4 is 37.5 Mod 5 is reset

//void moveLeft(){
//
//TACCTL1 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
//TACCTL1 |= OUTMOD_7;
//TACCTL0 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
//TACCTL0 |= OUTMOD_5;
//
//}

void RobotMovement(unsigned char direction)
{
        switch (direction) {
        case LEFT:
        	TA1CCR1 = 0;
			TA0CCR1 = 0;
			__delay_cycles(10000);


			TA0CCTL0 &= ~OUTMOD_5;
        	TA0CCTL0 |= OUTMOD_5;
        	TA0CCTL1 &= ~OUTMOD_7;
        	TA0CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode

        	TA1CCTL0 &= ~OUTMOD_5;
        	TA1CCTL0 |= OUTMOD_5;
        	TA1CCTL1 &= ~OUTMOD_7;
        	TA1CCTL1 |= OUTMOD_7;

        	TA1CCR1 = 0;
        	TA0CCR1 = 70;
        	__delay_cycles(5000);

		 break;

         case SHARPLEFT:
         	TA1CCR1 = 0;
 			TA0CCR1 = 0;
 			__delay_cycles(10000);

 			TA0CCTL0 &= ~OUTMOD_5;
         	TA0CCTL0 |= OUTMOD_5;
         	TA0CCTL1 &= ~OUTMOD_7;
         	TA0CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode

         	TA1CCTL0 &= ~OUTMOD_7;
         	TA1CCTL0 |= OUTMOD_7;
         	TA1CCTL1 &= ~OUTMOD_5;
         	TA1CCTL1 |= OUTMOD_5;

         	TA0CCR1 = 60;
         	TA1CCR1 = 60;
         	__delay_cycles(10000);

       	 break;

         case RIGHT:
         	TA1CCR1 = 0;
 			TA0CCR1 = 0;
 			__delay_cycles(10000);


 			TA0CCTL0 &= ~OUTMOD_5;
			TA0CCTL0 |= OUTMOD_5;
			TA0CCTL1 &= ~OUTMOD_7;
			TA0CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode

			TA1CCTL0 &= ~OUTMOD_5;
			TA1CCTL0 |= OUTMOD_5;
			TA1CCTL1 &= ~OUTMOD_7;
			TA1CCTL1 |= OUTMOD_7;

        	 TA0CCR1 = 0;
        	 TA1CCR1 = 70;
        	 __delay_cycles(5000);

		break;
        case SHARPRIGHT:
        	TA1CCR1 = 0;
			TA0CCR1 = 0;
			__delay_cycles(10000);


			TA0CCTL0 &= ~OUTMOD_7;
         	TA0CCTL0 |= OUTMOD_7;
         	TA0CCTL1 &= ~OUTMOD_5;
         	TA0CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode

         	TA1CCTL0 &= ~OUTMOD_5;
         	TA1CCTL0 |= OUTMOD_5;
         	TA1CCTL1 &= ~OUTMOD_7;
         	TA1CCTL1 |= OUTMOD_7;

         	TA0CCR1 = 60;
         	TA1CCR1 = 60;
         	__delay_cycles(1000000);

       	break;

        case FORWARD:
        	TA1CCR1 = 0;
			TA0CCR1 = 0;
			__delay_cycles(10000);

			TA0CCTL0 &= ~OUTMOD_5;
        	TA0CCTL0 |= OUTMOD_5;
        	TA0CCTL1 &= ~OUTMOD_7;
        	TA0CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode

        	TA1CCTL0 &= ~OUTMOD_5;
        	TA1CCTL0 |= OUTMOD_5;
        	TA1CCTL1 &= ~OUTMOD_7;
        	TA1CCTL1 |= OUTMOD_7;

        	TA1CCR1 = 60;
        	TA0CCR1 = 60;
        	__delay_cycles(1000000);

		break;

        case REVERSE:
        	TA1CCR1 = 0;
			TA0CCR1 = 0;
			__delay_cycles(10000);

			TA0CCTL0 &= ~OUTMOD_7;
        	TA0CCTL0 |= OUTMOD_7;
        	TA0CCTL1 &= ~OUTMOD_7;
        	TA0CCTL1 |= OUTMOD_5;

        	TA1CCTL0 &= ~OUTMOD_7;
        	TA1CCTL0 |= OUTMOD_7;
        	TA1CCTL1 &= ~OUTMOD_7;
        	TA1CCTL1 |= OUTMOD_5;

        	TA1CCR1 = 50;
        	TA0CCR1 = 50;
        	__delay_cycles(100000000);

		break;



        }

}



