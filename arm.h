//#pragma once

#ifndef arm_h
#define arm_h

#include "Arduino.h"
#include <Servo.h>

class robot_arm
{
public:
	//basic definition
	void servo_speed(unsigned int speed_1, unsigned int speed_2, unsigned int speed_3, unsigned int speed_4);

	//Function used to move Claw
	void grip_auto(int grip, Servo& servo4);
	void grip_manual(int dist, Servo& servo4);

	//Function to move Robot arm.
	void angle_mode(int servo1_input, int servo2_input, int servo3_input, Servo& servo1, Servo& servo2, Servo& servo3);
	int height_mode(double height, Servo& servo1, Servo& servo2, Servo& servo3);

private:

	unsigned int pos;

	unsigned int servo_speed_1 = 500;// Default speed of the servo1
	unsigned int servo_speed_2 = 500;// Default speed of the servo2
	unsigned int servo_speed_3 = 500;// Default speed of the servo3
	unsigned int servo_speed_4 = 500;// Default speed of the servo4

	unsigned int servo1_angle_P = 1500;// Default location of the servo1
	unsigned int servo2_angle_P = 1500;// Default location of the servo2
	unsigned int servo3_angle_P = 1500;// Default location of the servo3
	unsigned int servo4_angle_P = 1200;// Default location of the servo4


	unsigned int servo1_angle_O = 1500;// Default location of the servo1
	unsigned int servo2_angle_O = 1500;// Default location of the servo2
	unsigned int servo3_angle_O = 1500;// Default location of the servo3
	unsigned int servo4_angle_O = 1500;// Default location of the servo4

};


#endif
