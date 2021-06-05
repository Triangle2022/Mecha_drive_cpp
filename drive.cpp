#include "drive.h"


//general setting
void step::g_left_micro(int a)
{
  switch(a)
  {
  case 1:
  {
    digitalWrite(33, LOW); digitalWrite(35, LOW); digitalWrite(37, LOW); digitalWrite(39, LOW); digitalWrite(41, LOW); digitalWrite(43, LOW);
    break;
  }
  case 2:
  {
    digitalWrite(33, HIGH); digitalWrite(35, LOW); digitalWrite(37, LOW); digitalWrite(39, HIGH); digitalWrite(41, LOW); digitalWrite(43, LOW);
    break;
  }
  case 4:
  {
    digitalWrite(33, LOW); digitalWrite(35, HIGH); digitalWrite(37, LOW); digitalWrite(39, LOW); digitalWrite(41, HIGH); digitalWrite(43, LOW);
    break;
  }
  case 8:
  {
    digitalWrite(33, HIGH); digitalWrite(35, HIGH); digitalWrite(37, LOW); digitalWrite(39, HIGH); digitalWrite(41, HIGH); digitalWrite(43, LOW);
    break;
  }
  case 16:
  {
    digitalWrite(33, HIGH); digitalWrite(35, HIGH); digitalWrite(37, HIGH); digitalWrite(39, HIGH); digitalWrite(41, HIGH); digitalWrite(43, HIGH);
    break;
  }
  }

}

void step::g_right_micro(int a)
{
    switch (a) {
  case 1:
  {
    digitalWrite(32, LOW); digitalWrite(34, LOW); digitalWrite(36, LOW); digitalWrite(38, LOW); digitalWrite(40, LOW); digitalWrite(42, LOW);
    break;
  }
  case 2:
  {
    digitalWrite(32, HIGH); digitalWrite(34, LOW); digitalWrite(36, LOW); digitalWrite(38, HIGH); digitalWrite(40, LOW); digitalWrite(42, LOW);
    break;
  }
  case 4:
  {
    digitalWrite(32, LOW); digitalWrite(34, HIGH); digitalWrite(36, LOW); digitalWrite(38, LOW); digitalWrite(40, HIGH); digitalWrite(42, LOW);
    break;
  }
  case 8:
  {
    digitalWrite(32, HIGH); digitalWrite(34, HIGH); digitalWrite(36, LOW); digitalWrite(38, HIGH); digitalWrite(40, HIGH); digitalWrite(42, LOW);
    break;
  }
  case 16:
  {
    digitalWrite(32, HIGH); digitalWrite(34, HIGH); digitalWrite(36, HIGH); digitalWrite(38, HIGH); digitalWrite(40, HIGH); digitalWrite(42, HIGH);
    break;
  }
}
}

void step::g_microstepping(int a)
{

	switch (a) {
	case 1:
	{
		digitalWrite(33, LOW); digitalWrite(35, LOW); digitalWrite(37, LOW); digitalWrite(39, LOW); digitalWrite(41, LOW); digitalWrite(43, LOW);
		digitalWrite(32, LOW); digitalWrite(34, LOW); digitalWrite(36, LOW); digitalWrite(38, LOW); digitalWrite(40, LOW); digitalWrite(42, LOW);
		break;
	}
	case 2:
	{
		digitalWrite(33, HIGH); digitalWrite(35, LOW); digitalWrite(37, LOW); digitalWrite(39, HIGH); digitalWrite(41, LOW); digitalWrite(43, LOW);
		digitalWrite(32, HIGH); digitalWrite(34, LOW); digitalWrite(36, LOW); digitalWrite(38, HIGH); digitalWrite(40, LOW); digitalWrite(42, LOW);
		break;
	}
	case 4:
	{
		digitalWrite(33, LOW); digitalWrite(35, HIGH); digitalWrite(37, LOW); digitalWrite(39, LOW); digitalWrite(41, HIGH); digitalWrite(43, LOW);
		digitalWrite(32, LOW); digitalWrite(34, HIGH); digitalWrite(36, LOW); digitalWrite(38, LOW); digitalWrite(40, HIGH); digitalWrite(42, LOW);
		break;
	}
	case 8:
	{
		digitalWrite(33, HIGH); digitalWrite(35, HIGH); digitalWrite(37, LOW); digitalWrite(39, HIGH); digitalWrite(41, HIGH); digitalWrite(43, LOW);
		digitalWrite(32, HIGH); digitalWrite(34, HIGH); digitalWrite(36, LOW); digitalWrite(38, HIGH); digitalWrite(40, HIGH); digitalWrite(42, LOW);
		break;
	}
	case 16:
	{
		digitalWrite(33, HIGH); digitalWrite(35, HIGH); digitalWrite(37, HIGH); digitalWrite(39, HIGH); digitalWrite(41, HIGH); digitalWrite(43, HIGH);
		digitalWrite(32, HIGH); digitalWrite(34, HIGH); digitalWrite(36, HIGH); digitalWrite(38, HIGH); digitalWrite(40, HIGH); digitalWrite(42, HIGH);
		break;
	}
	}
}

void step::g_direction(int c)
{
	switch (c) {
	case 0:
		digitalWrite(14, LOW); digitalWrite(15, LOW);
		digitalWrite(17, HIGH); digitalWrite(16, HIGH);
		break;
		*dir = 0;
	case 3:
		digitalWrite(14, LOW); digitalWrite(15, HIGH);
		digitalWrite(17, HIGH); digitalWrite(16, LOW);
		*dir = 3;
		break;
	case 6:
		digitalWrite(14, HIGH); digitalWrite(15, HIGH);
		digitalWrite(17, LOW); digitalWrite(16, LOW);
		*dir = 6;
		break;
	case 9:
		digitalWrite(14, HIGH); digitalWrite(15, LOW);
		digitalWrite(17, LOW); digitalWrite(16, HIGH);
		*dir = 9;
		break;
	case 333:
		digitalWrite(14, LOW); digitalWrite(15, LOW);
		digitalWrite(17, LOW); digitalWrite(16, LOW);
		*dir = 333;
		break;
	case 999:
		digitalWrite(14, HIGH); digitalWrite(15, HIGH);
		digitalWrite(17, HIGH); digitalWrite(16, HIGH);
		*dir = 999;
		break;
	case 15: //motor 2,3 off and Go forward
		digitalWrite(14, LOW); digitalWrite(15, LOW);
		digitalWrite(17, HIGH); digitalWrite(16, HIGH);
		*dir = 15;
		break;

	case 45: // motor 1,4 off and Go backward
		digitalWrite(14, HIGH); digitalWrite(15, HIGH);
		digitalWrite(17, LOW); digitalWrite(16, LOW);
		*dir = 45;
		break;

	case 75: //motor 2,3 off and Go backward
		digitalWrite(14, HIGH); digitalWrite(15, HIGH);
		digitalWrite(17, LOW); digitalWrite(16, LOW);
		*dir = 75;
		break;

	case 105: //motor  1,4, off and Go forward
		digitalWrite(14, LOW); digitalWrite(15, LOW);
		digitalWrite(17, HIGH); digitalWrite(16, HIGH);
		*dir = 105;
		break;

	case 33: //motor  1,4, off and Go forward
		digitalWrite(14, LOW); digitalWrite(15, LOW);
		digitalWrite(17, LOW); digitalWrite(16, LOW);
		*dir = 33;
		break;
	case 99: //motor  1,4, off and Go forward
		digitalWrite(14, HIGH); digitalWrite(15, HIGH);
		digitalWrite(17, HIGH); digitalWrite(16, HIGH);
		*dir = 99;
		break;
	}


}

//normal mode
void step::n_speed(int s)
{
	step_speed1 = s; step_speed2 = s; step_speed3 = s; step_speed4 = s;
}

void step::n_distance_step(int distance)
{
	step_distance1 = distance; step_distance2 = distance; step_distance3 = distance; step_distance4 = distance;
}

void step::n_distance_mm(double distance)
{
	step_distance1 = int(distance * 1.15749);
}

void step::n_run()
{
	switch (*dir)
	{
	case 0:
		for (int i = 0; i < step_distance1; i++)
		{
			digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(10, HIGH); digitalWrite(11, HIGH);
			delayMicroseconds(step_speed1);
			digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(10, LOW); digitalWrite(11, LOW);
			delayMicroseconds(step_speed1);
		}
		break;
	case 3:
		for (int i = 0; i < step_distance1; i++)
		{
			digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(10, HIGH); digitalWrite(11, HIGH);
			delayMicroseconds(step_speed1);
			digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(10, LOW); digitalWrite(11, LOW);
			delayMicroseconds(step_speed1);
		}
		break;
	case 6:
		for (int i = 0; i < step_distance1; i++)
		{
			digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(10, HIGH); digitalWrite(11, HIGH);
			delayMicroseconds(step_speed1);
			digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(10, LOW); digitalWrite(11, LOW);
			delayMicroseconds(step_speed1);
		}
		break;
	case 9:
		for (int i = 0; i < step_distance1; i++)
		{
			digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(10, HIGH); digitalWrite(11, HIGH);
			delayMicroseconds(step_speed1);
			digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(10, LOW); digitalWrite(11, LOW);
			delayMicroseconds(step_speed1);
		}
		break;
	case 333:
		for (int i = 0; i < step_distance1; i++)
		{
			digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(10, HIGH); digitalWrite(11, HIGH);
			delayMicroseconds(step_speed1);
			digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(10, LOW); digitalWrite(11, LOW);
			delayMicroseconds(step_speed1);
		}
		break;
	case 999:
		for (int i = 0; i < step_distance1; i++)
		{
			digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(10, HIGH); digitalWrite(11, HIGH);
			delayMicroseconds(step_speed1);
			digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(10, LOW); digitalWrite(11, LOW);
			delayMicroseconds(step_speed1);
		}
		break;
	case 15:
		for (int i = 0; i < step_distance1; i++)
		{
			digitalWrite(2, HIGH);  digitalWrite(11, HIGH);
			delayMicroseconds(step_speed1);
			digitalWrite(2, LOW);  digitalWrite(11, LOW);
			delayMicroseconds(step_speed1);
		}
		break;
	case 45:
		for (int i = 0; i < step_distance1; i++)
		{
			digitalWrite(3, HIGH); digitalWrite(10, HIGH);
			delayMicroseconds(step_speed1);
			digitalWrite(3, LOW); digitalWrite(10, LOW);
			delayMicroseconds(step_speed1);
		}
		break;
	case 75:
		for (int i = 0; i < step_distance1; i++)
		{
			digitalWrite(2, HIGH); digitalWrite(11, HIGH);
			delayMicroseconds(step_speed1);
			digitalWrite(2, LOW); digitalWrite(11, LOW);
			delayMicroseconds(step_speed1);
		}
		break;
	case 105:
		for (int i = 0; i < step_distance1; i++)
		{
			digitalWrite(3, HIGH); digitalWrite(10, HIGH);
			delayMicroseconds(step_speed1);
			digitalWrite(3, LOW); digitalWrite(10, LOW);
			delayMicroseconds(step_speed1);
		}
		break;
	case 33:
		for (int i = 0; i < step_distance1; i++)
		{
			digitalWrite(2, HIGH); digitalWrite(10, HIGH);
			delayMicroseconds(step_speed1);
			digitalWrite(2, LOW); digitalWrite(10, LOW);
			delayMicroseconds(step_speed1);
		}
		break;
	case 99:
		for (int i = 0; i < step_distance1; i++)
		{
			digitalWrite(2, HIGH);  digitalWrite(10, HIGH);
			delayMicroseconds(step_speed1);
			digitalWrite(2, LOW); digitalWrite(10, LOW);
			delayMicroseconds(step_speed1);
		}
		break;
	}


}

void step::n_run(int s, int distance)
{
	step_speed1 = s; step_speed2 = s; step_speed3 = s; step_speed4 = s;
	step_distance1 = distance; step_distance2 = distance; step_distance3 = distance; step_distance4 = distance;

	for (int i = 0; i < step_distance1; i++)
	{
		digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(10, HIGH); digitalWrite(11, HIGH);
		delayMicroseconds(step_speed1);
		digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(10, LOW); digitalWrite(11, LOW);
		delayMicroseconds(step_speed1);
	}
}

///Acceleration mode
void step::a_setparameter(uint16_t acceleration, uint16_t max_speed, AccelStepper& stepper_motor1, AccelStepper& stepper_motor2, AccelStepper& stepper_motor3, AccelStepper& stepper_motor4)
{
	stepper_motor1.setMaxSpeed(acceleration);
	stepper_motor1.setAcceleration(max_speed);


	stepper_motor2.setMaxSpeed(acceleration);
	stepper_motor2.setAcceleration(max_speed);


	stepper_motor3.setMaxSpeed(acceleration);
	stepper_motor3.setAcceleration(max_speed);

	stepper_motor4.setMaxSpeed(acceleration);
	stepper_motor4.setAcceleration(max_speed);

}

void step::a_run(int distance, AccelStepper& stepper_motor1, AccelStepper& stepper_motor2, AccelStepper& stepper_motor3, AccelStepper& stepper_motor4)
{
	switch (*dir)
	{
	case 0:
		stepper_motor1.moveTo(-distance);
		stepper_motor2.moveTo(-distance);
		stepper_motor3.moveTo(distance);
		stepper_motor4.moveTo(distance);

		while (stepper_motor1.distanceToGo() != 0 && stepper_motor2.distanceToGo() != 0 && stepper_motor3.distanceToGo() != 0 && stepper_motor4.distanceToGo() != 0)
		{
			stepper_motor1.run();
			stepper_motor2.run();
			stepper_motor3.run();
			stepper_motor4.run();
		}
		break;
	case 3:
		stepper_motor1.moveTo(-distance);
		stepper_motor2.moveTo(distance);
		stepper_motor3.moveTo(-distance);
		stepper_motor4.moveTo(distance);

		while (stepper_motor1.distanceToGo() != 0 && stepper_motor2.distanceToGo() != 0 && stepper_motor3.distanceToGo() != 0 && stepper_motor4.distanceToGo() != 0)
		{
			stepper_motor1.run();
			stepper_motor2.run();
			stepper_motor3.run();
			stepper_motor4.run();
		}
		break;
	case 6:
		stepper_motor1.moveTo(distance);
		stepper_motor2.moveTo(distance);
		stepper_motor3.moveTo(-distance);
		stepper_motor4.moveTo(-distance);

		while (stepper_motor1.distanceToGo() != 0 && stepper_motor2.distanceToGo() != 0 && stepper_motor3.distanceToGo() != 0 && stepper_motor4.distanceToGo() != 0)
		{
			stepper_motor1.run();
			stepper_motor2.run();
			stepper_motor3.run();
			stepper_motor4.run();
		}
		break;
	case 9:
		stepper_motor1.moveTo(distance);
		stepper_motor2.moveTo(-distance);
		stepper_motor3.moveTo(distance);
		stepper_motor4.moveTo(-distance);

		while (stepper_motor1.distanceToGo() != 0 && stepper_motor2.distanceToGo() != 0 && stepper_motor3.distanceToGo() != 0 && stepper_motor4.distanceToGo() != 0)
		{
			stepper_motor1.run();
			stepper_motor2.run();
			stepper_motor3.run();
			stepper_motor4.run();
		}
		break;

	case 333:
		stepper_motor1.moveTo(-distance);
		stepper_motor2.moveTo(-distance);
		stepper_motor3.moveTo(-distance);
		stepper_motor4.moveTo(-distance);

		while (stepper_motor1.distanceToGo() != 0 && stepper_motor2.distanceToGo() != 0 && stepper_motor3.distanceToGo() != 0 && stepper_motor4.distanceToGo() != 0)
		{
			stepper_motor1.run();
			stepper_motor2.run();
			stepper_motor3.run();
			stepper_motor4.run();
		}
		break;
	case 999:
		stepper_motor1.moveTo(distance);
		stepper_motor2.moveTo(distance);
		stepper_motor3.moveTo(distance);
		stepper_motor4.moveTo(distance);

		while (stepper_motor1.distanceToGo() != 0 && stepper_motor2.distanceToGo() != 0 && stepper_motor3.distanceToGo() != 0 && stepper_motor4.distanceToGo() != 0)
		{
			stepper_motor1.run();
			stepper_motor2.run();
			stepper_motor3.run();
			stepper_motor4.run();
		}
		break;


	case 15:
		stepper_motor1.moveTo(-distance);
		//stepper_motor2.moveTo(-distance);
		//stepper_motor3.moveTo(distance);
		stepper_motor4.moveTo(distance);

		while (stepper_motor1.distanceToGo() != 0 && stepper_motor2.distanceToGo() != 0 && stepper_motor3.distanceToGo() != 0 && stepper_motor4.distanceToGo() != 0)
		{
			stepper_motor1.run();
			stepper_motor2.run();
			stepper_motor3.run();
			stepper_motor4.run();
		}
		break;
	case 45:
		//stepper_motor1.moveTo(distance);
		stepper_motor2.moveTo(distance);
		stepper_motor3.moveTo(-distance);
		//stepper_motor4.moveTo(-distance);

		while (stepper_motor1.distanceToGo() != 0 && stepper_motor2.distanceToGo() != 0 && stepper_motor3.distanceToGo() != 0 && stepper_motor4.distanceToGo() != 0)
		{
			stepper_motor1.run();
			stepper_motor2.run();
			stepper_motor3.run();
			stepper_motor4.run();
		}
		break;
	case 75:
		stepper_motor1.moveTo(distance);
		//stepper_motor2.moveTo(distance);
		//stepper_motor3.moveTo(-distance);
		stepper_motor4.moveTo(-distance);

		while (stepper_motor1.distanceToGo() != 0 && stepper_motor2.distanceToGo() != 0 && stepper_motor3.distanceToGo() != 0 && stepper_motor4.distanceToGo() != 0)
		{
			stepper_motor1.run();
			stepper_motor2.run();
			stepper_motor3.run();
			stepper_motor4.run();
		}
		break;
	case 105:
		//stepper_motor1.moveTo(-distance);
		stepper_motor2.moveTo(-distance);
		stepper_motor3.moveTo(+distance);
		//stepper_motor4.moveTo(+distance);

		while (stepper_motor1.distanceToGo() != 0 && stepper_motor2.distanceToGo() != 0 && stepper_motor3.distanceToGo() != 0 && stepper_motor4.distanceToGo() != 0)
		{
			stepper_motor1.run();
			stepper_motor2.run();
			stepper_motor3.run();
			stepper_motor4.run();
		}
		break;
	case 33:
		stepper_motor1.moveTo(-distance);
		//stepper_motor2.moveTo(-distance);
		stepper_motor3.moveTo(-distance);
		//stepper_motor4.moveTo(-distance);

		while (stepper_motor1.distanceToGo() != 0 && stepper_motor2.distanceToGo() != 0 && stepper_motor3.distanceToGo() != 0 && stepper_motor4.distanceToGo() != 0)
		{
			stepper_motor1.run();
			stepper_motor2.run();
			stepper_motor3.run();
			stepper_motor4.run();
		}
		break;
	case 99:
		stepper_motor1.moveTo(+distance);
		//stepper_motor2.moveTo(+distance);
		stepper_motor3.moveTo(+distance);
		//stepper_motor4.moveTo(+distance);

		while (stepper_motor1.distanceToGo() != 0 && stepper_motor2.distanceToGo() != 0 && stepper_motor3.distanceToGo() != 0 && stepper_motor4.distanceToGo() != 0)
		{
			stepper_motor1.run();
			stepper_motor2.run();
			stepper_motor3.run();
			stepper_motor4.run();
		}
		break;

	}
}




//pwm mode
void step::change_frequency(int f)
{
	/*this code is controlling internal register!!*/
	switch (f)
	{
	case 30:
	{
		TCCR3B = TCCR4B & B11111000 | B00000101;    // for PWM frequency of 30.64 Hz
		TCCR2B = TCCR2B & B11111000 | B00000111;  // for PWM frequency of 30.64 Hz
		TCCR1B = TCCR1B & B11111000 | B00000101;   // for  PWM frequency of 30.64 Hz
		break;
	}
	case 122:
	{
		TCCR3B = TCCR4B & B11111000 | B00000100;  // for PWM frequency of 122.55 Hz
		TCCR2B = TCCR2B & B11111000 | B00000110;  // for PWM frequency of 122.55 Hz
		TCCR1B = TCCR1B & B11111000 | B00000100;  // for for PWM frequency of 122.55 Hz
		break;
	}
	case 490:
	{
		TCCR3B = TCCR4B & B11111000 | B00000011;  // for PWM frequency of 490.20 Hz
		TCCR2B = TCCR2B & B11111000 | B00000100;  // for PWM frequency of 490.20 Hz
		TCCR1B = TCCR1B & B11111000 | B00000011;  // for PWM frequency of 490.20 Hz
		break;
	}
	case 3921:
	{
		TCCR3B = TCCR3B & B11111000 | B00000010;  // for PWM frequency of 3921.16 Hz
		TCCR2B = TCCR2B & B11111000 | B00000010;  // for  PWM frequency of 3921.16 Hz
		TCCR1B = TCCR1B & B11111000 | B00000010;  // for PWM frequency of 3921.16 Hz
		break;
	}
	}

}

void step::p_run()
{
	switch (*dir)
	{

		///basic movement
	case 0:
		analogWrite(2, 124); analogWrite(3, 124); analogWrite(10, 124); analogWrite(11, 124);
		break;
	case 3:
		analogWrite(2, 124); analogWrite(3, 124); analogWrite(10, 124); analogWrite(11, 124);
		break;
	case 6:
		analogWrite(2, 124); analogWrite(3, 124); analogWrite(10, 124); analogWrite(11, 124);
		break;
	case 9:
		analogWrite(2, 124); analogWrite(3, 124); analogWrite(10, 124); analogWrite(11, 124);
		break;
	case 333:
		analogWrite(2, 124); analogWrite(3, 124); analogWrite(10, 124); analogWrite(11, 124);
		break;
	case 666:
		analogWrite(2, 124); analogWrite(3, 124); analogWrite(10, 124); analogWrite(11, 124);
		break;

		/// additional movement
	case 15:
		analogWrite(2, 124); analogWrite(3, 0); analogWrite(10, 0); analogWrite(11, 124);
		break;
	case 45:
		analogWrite(2, 0); analogWrite(3, 124); analogWrite(10, 124); analogWrite(11, 0);
		break;
	case 75:
		analogWrite(2, 124); analogWrite(3, 0); analogWrite(10, 0); analogWrite(11, 124);
		break;
	case 105:
		analogWrite(2, 0); analogWrite(3, 124); analogWrite(10, 124); analogWrite(11, 0);
		break;
	case 33:
		analogWrite(2, 124); analogWrite(3, 0); analogWrite(10, 124); analogWrite(11, 0);
		break;
	case 99:
		analogWrite(2, 124); analogWrite(3, 0); analogWrite(10, 124); analogWrite(11, 0);
		break;
	}


}

void step::p_stop()
{
	analogWrite(2, 0); analogWrite(3, 0); analogWrite(10, 0); analogWrite(11, 0);
}
