#ifndef drive_h
#define drive_h

#include "Arduino.h"
#include <AccelStepper.h>

class step
{
private:


	int step_distance1 = 0;
	int step_distance2 = 0;
	int step_distance3 = 0;
	int step_distance4 = 0;

	//microstep value save
	uint8_t microstep_1;
	uint8_t microstep_2;
	uint8_t microstep_3;
	uint8_t microstep_4;

	int step_speed1 = 0;
	int step_speed2 = 0;
	int step_speed3 = 0;
	int step_speed4 = 0;


public:


	//variables of general functions
	int d;
	int* dir = &d;

	//General fucntion
	void g_microstepping(int a);
	void g_direction(int c);
  void g_left_micro(int a);
  void g_right_micro(int a);

	//Normal mode of drive
	void n_speed(int s);
	void n_distance_step(int distance); // rotation of wheel
	void n_distance_mm(double distance); // DRIVE MM
	void n_run();
	void n_run(int s, int distance);


	//Acceleration mode
	void a_setparameter(uint16_t acceleration, uint16_t max_speed, AccelStepper& stepper_motor1, AccelStepper& stepper_motor2, AccelStepper& stepper_motor3, AccelStepper& stepper_motor4);
	void a_run(int distance, AccelStepper& stepper_motor1, AccelStepper& stepper_motor2, AccelStepper& stepper_motor3, AccelStepper& stepper_motor4);


	//PWM mode
	void change_frequency(int f);
	void p_run();
	void p_stop();

};


#endif
