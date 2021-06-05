
// Copyright First Technology2020.All right reserved.

/*
    Name:       integrated v2.ino
    Author:     First Techonology
*/

//include ros_related libraries
#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Int32.h>

//include arduino libraries
#include <Wire.h>
#include <Adafruit_VL53L0X.h>
#include <Servo.h>
#include <MultiStepper.h>
#include <AccelStepper.h>

//include custom libraries
#include "arm.h"
#include "drive.h"
#include "lidar.h"

const int step_pin1 = 2;
const int dir_pin1 = 14;

const int step_pin2 = 3;
const int dir_pin2 = 15;

const int step_pin3 = 10;
const int dir_pin3 = 16;

const int step_pin4 = 11;
const int dir_pin4 = 17;

Servo servo1; // servo motor1 init
Servo servo2; // servo motor2 init
Servo servo3; // servo motor3 init
Servo servo4; // servo motor4 init
Adafruit_VL53L0X lox = Adafruit_VL53L0X(); // lidar init
AccelStepper step1(AccelStepper::DRIVER, step_pin1, dir_pin1); //accelstepper motor1 init
AccelStepper step2(AccelStepper::DRIVER, step_pin2, dir_pin2); //accelstepper motor2 init
AccelStepper step3(AccelStepper::DRIVER, step_pin3, dir_pin3); //accelstepper motor3 init
AccelStepper step4(AccelStepper::DRIVER, step_pin4, dir_pin4); //accelstepper motor4 init

//custom libaray setup
lidar_sensor lidar;
robot_arm arm;
step drive;

ros::NodeHandle nh;
//int sped = 490;





void messageCa( const std_msgs::Int32& stepper){

  if(stepper.data == 12)
  {
    drive.g_microstepping(16);
    drive.change_frequency(0);
    drive.g_direction(0);
    drive.p_stop();
  }
  else if(stepper.data == 0)
  {
    drive.g_microstepping(8);
    drive.change_frequency(490);
    drive.g_direction(0);
    drive.p_run();
  }
  else if(stepper.data == 3)
  {
    drive.g_microstepping(16);
    drive.change_frequency(490);
    drive.g_direction(3);
    drive.p_run();
  }
  else if(stepper.data == 6)
  {
    drive.g_microstepping(16);
    drive.change_frequency(490);
    drive.g_direction(6);
    drive.p_run();
  }
   else if(stepper.data == 9)
  {
    drive.g_microstepping(16);
    drive.change_frequency(490);
    drive.g_direction(9);
    drive.p_run();
  }
   else if(stepper.data == 12)
  {
    drive.g_microstepping(16);
    drive.change_frequency(490);
    drive.g_direction(0);
    drive.p_run();
  }
  else if(stepper.data == 33)
  {
    drive.g_microstepping(8);
    drive.change_frequency(490);
    drive.g_direction(333);
    drive.p_run();
  }
  else if(stepper.data == 99)
  {
    drive.g_microstepping(8);
    drive.change_frequency(490);
    drive.g_direction(999);
    drive.p_run();
  }

  // turn right 
  else if (stepper.data == 110) // phase_1
  {
    drive.g_right_micro(16);
    drive.g_left_micro(8);
    drive.g_direction(0);
    drive.p_run();
  }
  else if (stepper.data == 120) // phase_2
  {
    drive.g_right_micro(16);
    drive.g_left_micro(4);
    drive.g_direction(0);
    drive.p_run();
  }
  else if (stepper.data == 130) // phase_3
  {
    drive.g_right_micro(16);
    drive.g_left_micro(2);
    drive.g_direction(0);
    drive.p_run();
  }

  //turn_left
    else if (stepper.data == 210) // phase_1
  {
    drive.g_right_micro(8);
    drive.g_left_micro(16);
    drive.g_direction(0);
    drive.p_run();
  }
  else if (stepper.data == 220) // phase_2
  {
    drive.g_right_micro(4);
    drive.g_left_micro(16);
    drive.g_direction(0);
    drive.p_run();
  }
  else if (stepper.data == 230) // phase_3
  {
    drive.g_right_micro(2);
    drive.g_left_micro(16);
    drive.g_direction(0);
    drive.p_run();
  }
  
}


void messageCb( const std_msgs::Int32& servo){

  if(servo.data == 0)
  {
    arm.grip_auto(0,servo4);
  }
  else if(servo.data == 1)
  {
    arm.grip_auto(1,servo4);
  }
  else
  {
    arm.height_mode(servo.data,servo1,servo2,servo3);
  }
}


ros::Subscriber<std_msgs::Int32> sub1("stepper_control", &messageCa );
ros::Subscriber<std_msgs::Int32> sub2("servo_control", &messageCb );


std_msgs::Int32 int_msg1;
ros::Publisher lidar1("front_lidar",&int_msg1);


void setup()
{
  Serial.begin(9600); //serial baudrate setup for Lidar communication with computer
  lidar.tcasetup(lox);
  servo1.attach(6);
  servo2.attach(7);
  servo3.attach(8);
  servo4.attach(9);
  arm.angle_mode(150, 150, 150, servo1, servo2, servo3);
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub1);
  nh.subscribe(sub2);

  nh.advertise(lidar1);

}

void loop()
{
  int lidar1_val = lidar.front_lidar(lox);
  int_msg1.data = lidar1_val;
  lidar1.publish(&int_msg1);


  nh.spinOnce();
  delay(1);
}



//#include <Wire.h>
//#include <Adafruit_VL53L0X.h>
//#include <Servo.h>
//#include <MultiStepper.h>
//#include <AccelStepper.h>
//
////incldue custom libraries
//#include "arm.h"
//#include "drive.h"
//#include "lidar.h"
//
//const int step_pin1 = 2;
//const int dir_pin1 = 14;
//
//const int step_pin2 = 3;
//const int dir_pin2 = 15;
//
//const int step_pin3 = 10;
//const int dir_pin3 = 16;
//
//const int step_pin4 = 11;
//const int dir_pin4 = 17;
//
//Servo servo1; // servo motor1 init
//Servo servo2; // servo motor2 init
//Servo servo3; // servo motor3 init
//Servo servo4; // servo motor4 init
//Adafruit_VL53L0X lox = Adafruit_VL53L0X(); // lidar init
//AccelStepper step1(AccelStepper::DRIVER, step_pin1, dir_pin1); //accelstepper motor1 init
//AccelStepper step2(AccelStepper::DRIVER, step_pin2, dir_pin2); //accelstepper motor2 init
//AccelStepper step3(AccelStepper::DRIVER, step_pin3, dir_pin3); //accelstepper motor3 init
//AccelStepper step4(AccelStepper::DRIVER, step_pin4, dir_pin4); //accelstepper motor4 init
//
//
////custom libaray setup
//lidar_sensor lidar;
//robot_arm arm;
//step drive;
//
//
////infomation
//
////lidar name = lox
////step_motor1 name = step1
////step_motor2 name = step2
////step_motor3 name = step3
////step_motor4 name = step4
////servo_motor1 name = servo1;
////servo_motor2 name = servo2;
////servo_motor3 name = servo3;
////servo_motor4 name = servo4;
//
//boolean stage1 = false;
//boolean stage2 = false;
//int lidar_value;
//
//void setup()
//{
//    Serial.begin(9600); //serial baudrate setup for Lidar communication with computer
//    lidar.tcasetup(lox);
//    servo1.attach(6);
//    servo2.attach(7);
//    servo3.attach(8);
//    servo4.attach(9);
//    arm.angle_mode(150, 150, 150, servo1, servo2, servo3);
//}
//
//void loop()
//{
//   int a1 = lidar.front_lidar(lox);
//   Serial.println(a1);
//    if(stage1 == false && stage2 == false)
//        if (Serial.available() > 0)
//        {
//            
//            long coordinate_x = Serial.parseInt();
//            // From the short distance.
//            if (coordinate_x > 403 && coordinate_x <= 440)
//            {
//                drive.g_microstepping(8);
//                drive.change_frequency(30);
//                drive.g_direction(3);
//                drive.g_direction(3);
//                drive.p_run();
//                coordinate_x = Serial.parseInt();
//            }
//            else if (coordinate_x < 397 && coordinate_x > 360)
//            {
//                drive.g_microstepping(8);
//                drive.change_frequency(30);
//                drive.g_direction(9);
//                drive.g_direction(9);
//                drive.p_run();
//                coordinate_x = Serial.parseInt();
//            }
//            // From the long distance 
//            else if (coordinate_x > 440 && coordinate_x <= 800)
//            {
//                drive.g_microstepping(16);
//                drive.change_frequency(490);
//                drive.g_direction(3);
//                drive.g_direction(3);
//                drive.p_run();
//                coordinate_x = Serial.parseInt();
//            }
//            else if (coordinate_x < 360 && coordinate_x > 0)
//            {
//                drive.g_microstepping(16);
//                drive.change_frequency(490);
//                drive.g_direction(9);
//                drive.g_direction(9);
//                drive.p_run();
//                coordinate_x = Serial.parseInt();
//            }
//            
//            //Right infront of
//            else if (coordinate_x >= 397 && coordinate_x < 403)
//            {
//                drive.p_stop();
//                stage1 = true;
//            }
//        }
//    if (stage1 == true && stage2 == false)
//    {
//        lidar_value = lidar.front_lidar(lox);
//        if (lidar_value > 100)
//        {
//            drive.g_microstepping(16);
//            drive.change_frequency(490);
//            drive.g_direction(0);
//            drive.g_direction(0);
//            drive.p_run();
//        }
//        else if (lidar_value < 180)
//        {
//            drive.p_stop();
//            arm.angle_mode(150, 150, 150, servo1, servo2, servo3);
//            arm.grip_auto(1,servo4);
//            delay(1000);
//            arm.angle_mode(150, 150, 110, servo1, servo2, servo3);
//
//        }
//    }
//}
