//sketch.c*
//Created on: Nov 03, 2024
//Author: Natan, Kamil*/

#include "main.h"
#include "motor.h"
#include "simpleSensor.h"


void setup(void) {

}
extern motor_t hmot;

extern simpleSensor_t sensorL;
extern simpleSensor_t sensorC;
extern simpleSensor_t sensorR;


extern volatile uint16_t adcReadout[5];



void startLoop(void) {


  uint16_t sensorValueLeft = adcReadout[0];
  uint16_t sensorValueRight = adcReadout[1];


    if ((sensorValueLeft < 3300) || (sensorValueRight) < 3300) {


        motorSetDirection(&hmot, MOTOR_BACKWARD);
        motorSetPWM(&hmot, 200);
return;

    }



    else if (simpleSensorGetState(&sensorC)) {

        motorSetDirection(&hmot, MOTOR_FORWARD);
        motorSetPWM(&hmot, 255);
    }
    else if (simpleSensorGetState(&sensorL)) {

        motorSetDirection(&hmot, MOTOR_LEFT);
        motorSetPWM(&hmot, 150);
    }
    else if (simpleSensorGetState(&sensorR)) {

        motorSetDirection(&hmot, MOTOR_RIGHT);
        motorSetPWM(&hmot, 150);
    }
    else {

        motorSetDirection(&hmot, MOTOR_RIGHT);
        motorSetPWM(&hmot, 150);
    }
}
