#include "Arduino.h"
#include <Servo.h>
#include "arm.h"
#include <math.h>

void robot_arm::servo_speed(unsigned int speed_1, unsigned int speed_2, unsigned int speed_3, unsigned int speed_4)
{
    servo_speed_1 = speed_1;
    servo_speed_2 = speed_2;
    servo_speed_3 = speed_3;
    servo_speed_4 = speed_4;
}

void robot_arm::grip_auto(int grip, Servo& servo4)
{
    // auto grip setting
    if (grip == 1)
    {
        servo4_angle_O = 880;
    }
    else if (grip == 0)
    {
        servo4_angle_O = 2000;
    }

    // servo movement
    while (servo4_angle_P != servo4_angle_O)
    {
        if (servo4_angle_O > servo4_angle_P)
        {
            servo4_angle_P = servo4_angle_P + 1;
            servo4.writeMicroseconds(servo4_angle_P);
            delayMicroseconds(servo_speed_4);
        }
        else if (servo4_angle_O < servo4_angle_P)
        {
            servo4_angle_P = servo4_angle_P - 1;
            servo4.writeMicroseconds(servo4_angle_P);
            delayMicroseconds(servo_speed_4);
        }
        else if (servo4_angle_O = servo1_angle_P)
        {
            servo4.writeMicroseconds(servo4_angle_P);
            delayMicroseconds(servo_speed_4);
        }

    }
}

void robot_arm::grip_manual(int dist, Servo& servo4)
{
    //servo obejct setting
    servo4_angle_O = dist;

    while (servo4_angle_P != servo4_angle_O)
    {
        if (servo4_angle_O > servo4_angle_P)
        {
            servo4_angle_P = servo4_angle_P + 1;
            servo4.writeMicroseconds(servo4_angle_P);
            delayMicroseconds(servo_speed_4);
        }
        else if (servo4_angle_O < servo4_angle_P)
        {
            servo4_angle_P = servo4_angle_P - 1;
            servo4.writeMicroseconds(servo4_angle_P);
            delayMicroseconds(servo_speed_4);
        }
        else if (servo4_angle_O = servo1_angle_P)
        {
            servo4.writeMicroseconds(servo4_angle_P);
            delayMicroseconds(servo_speed_4);
        }

    }


}

void robot_arm::angle_mode(int servo1_input, int servo2_input, int servo3_input, Servo& servo1, Servo& servo2, Servo& servo3)
{

    int servo1_adjust = servo1_input -8;
    int servo2_adjust = servo2_input + 2;
    servo1_angle_O = map(servo1_adjust, 0, 300, 500, 2500);
    servo2_angle_O = map(servo2_adjust, 0, 300, 500, 2500);
    servo3_angle_O = map(servo3_input, 0, 300, 500, 2500);


    while (servo1_angle_P != servo1_angle_O || servo2_angle_P != servo2_angle_O || servo3_angle_P != servo3_angle_O)
    {


        // servo 1 move start 
        if (servo1_angle_O > servo1_angle_P)
        {
            servo1_angle_P = servo1_angle_P + 1;
            servo1.writeMicroseconds(servo1_angle_P);
            delayMicroseconds(servo_speed_1);
        }
        else if (servo1_angle_O < servo1_angle_P)
        {
            servo1_angle_P = servo1_angle_P - 1;
            servo1.writeMicroseconds(servo1_angle_P);
            delayMicroseconds(servo_speed_1);
        }
        else if (servo1_angle_O = servo1_angle_P)
        {
            servo1.writeMicroseconds(servo1_angle_P);
            delayMicroseconds(servo_speed_1);
        }
        // servo 1 move finish

        // servo 2 move start 
        if (servo2_angle_O > servo2_angle_P)
        {
            servo2_angle_P = servo2_angle_P + 1;
            servo2.writeMicroseconds(servo2_angle_P);
            delayMicroseconds(servo_speed_2);
        }
        else if (servo2_angle_O < servo2_angle_P)
        {
            servo2_angle_P = servo2_angle_P - 1;
            servo2.writeMicroseconds(servo2_angle_P);
            delayMicroseconds(servo_speed_2);
        }
        else if (servo2_angle_O = servo2_angle_P)
        {
            servo2.writeMicroseconds(servo2_angle_P);
            delayMicroseconds(servo_speed_2);
        }
        // servo 2 move finish

        // servo 3 move start 
        if (servo3_angle_O > servo3_angle_P)
        {
            servo3_angle_P = servo3_angle_P + 1;
            servo3.writeMicroseconds(servo3_angle_P);
            delayMicroseconds(servo_speed_3);

        }
        else if (servo3_angle_O < servo3_angle_P)
        {
            servo3_angle_P = servo3_angle_P - 1;
            servo3.writeMicroseconds(servo3_angle_P);
            delayMicroseconds(servo_speed_3);
        }
        else if (servo3_angle_O = servo3_angle_P)
        {
            servo3.writeMicroseconds(servo3_angle_P);
            delayMicroseconds(servo_speed_3);
        }
        // servo 3 move finish

    }

}

int robot_arm::height_mode(double height, Servo& servo1, Servo& servo2, Servo& servo3)
//Arm_verticle = 150
//Arm_horizontal =60
//Arm_normal_height = 87mm
{
    if (height > 87)
    {
        double height_1 = height - 87;
        double angle_1 = height_1 / 109;
        double cal_1 = asin(angle_1) * (180 / 3.141592);
        int last_1 = int(cal_1) + 60;
        //double distance1 = 106 + (109 * (cos(cal_1)) * (180/3.141592));

        int distance1 = int(cos(cal_1 * (3.141592 / 180)) * 109 + 106);

        int servo1_adjust = 144;
        int servo2_adjust = last_1 + 4;
        int servo3_adjust = last_1 + 3;
        servo1_angle_O = map(servo1_adjust, 0, 300, 500, 2500);
        servo2_angle_O = map(servo2_adjust, 0, 300, 500, 2500);
        servo3_angle_O = map(servo3_adjust, 0, 300, 500, 2500);


        while (servo1_angle_P != servo1_angle_O || servo2_angle_P != servo2_angle_O || servo3_angle_P != servo3_angle_O)
        {


            // servo 1 move start 
            if (servo1_angle_O > servo1_angle_P)
            {
                servo1_angle_P = servo1_angle_P + 1;
                servo1.writeMicroseconds(servo1_angle_P);
                delayMicroseconds(servo_speed_1);
            }
            else if (servo1_angle_O < servo1_angle_P)
            {
                servo1_angle_P = servo1_angle_P - 1;
                servo1.writeMicroseconds(servo1_angle_P);
                delayMicroseconds(servo_speed_1);
            }
            else if (servo1_angle_O = servo1_angle_P)
            {
                servo1.writeMicroseconds(servo1_angle_P);
                delayMicroseconds(servo_speed_1);
            }
            // servo 1 move finish

            // servo 2 move start 
            if (servo2_angle_O > servo2_angle_P)
            {
                servo2_angle_P = servo2_angle_P + 1;
                servo2.writeMicroseconds(servo2_angle_P);
                delayMicroseconds(servo_speed_2);
            }
            else if (servo2_angle_O < servo2_angle_P)
            {
                servo2_angle_P = servo2_angle_P - 1;
                servo2.writeMicroseconds(servo2_angle_P);
                delayMicroseconds(servo_speed_2);
            }
            else if (servo2_angle_O = servo2_angle_P)
            {
                servo2.writeMicroseconds(servo2_angle_P);
                delayMicroseconds(servo_speed_2);
            }
            // servo 2 move finish

            // servo 3 move start 
            if (servo3_angle_O > servo3_angle_P)
            {
                servo3_angle_P = servo3_angle_P + 1;
                servo3.writeMicroseconds(servo3_angle_P);
                delayMicroseconds(servo_speed_3);

            }
            else if (servo3_angle_O < servo3_angle_P)
            {
                servo3_angle_P = servo3_angle_P - 1;
                servo3.writeMicroseconds(servo3_angle_P);
                delayMicroseconds(servo_speed_3);
            }
            else if (servo3_angle_O = servo3_angle_P)
            {
                servo3.writeMicroseconds(servo3_angle_P);
                delayMicroseconds(servo_speed_3);
            }
            // servo 3 move finish

        }
        return distance1;
        //int angle_1 = int(angle) + 60;

    }
    else if (height <= 87)
    {
        //Height calculation
        double height2 = 87 - height;
        double angle_2 = height2 / 109;
        double cal_2 = asin(angle_2) * (180 / 3.141592);
        int last_2 = 60 - int(cal_2);
        //Distance calculation
        int distance2 = int(cos(cal_2 * (3.141592 / 180)) * 109 + 106);
        //
        int servo1_adjust = 144;
        int servo2_adjust = last_2 + 6;
        int servo3_adjust = last_2 - 1;
        servo1_angle_O = map(servo1_adjust, 0, 300, 500, 2500);
        servo2_angle_O = map(servo2_adjust, 0, 300, 500, 2500);
        servo3_angle_O = map(servo3_adjust, 0, 300, 500, 2500);


        while (servo1_angle_P != servo1_angle_O || servo2_angle_P != servo2_angle_O || servo3_angle_P != servo3_angle_O)
        {


            // servo 1 move start 
            if (servo1_angle_O > servo1_angle_P)
            {
                servo1_angle_P = servo1_angle_P + 1;
                servo1.writeMicroseconds(servo1_angle_P);
                delayMicroseconds(servo_speed_1);
            }
            else if (servo1_angle_O < servo1_angle_P)
            {
                servo1_angle_P = servo1_angle_P - 1;
                servo1.writeMicroseconds(servo1_angle_P);
                delayMicroseconds(servo_speed_1);
            }
            else if (servo1_angle_O = servo1_angle_P)
            {
                servo1.writeMicroseconds(servo1_angle_P);
                delayMicroseconds(servo_speed_1);
            }
            // servo 1 move finish

            // servo 2 move start 
            if (servo2_angle_O > servo2_angle_P)
            {
                servo2_angle_P = servo2_angle_P + 1;
                servo2.writeMicroseconds(servo2_angle_P);
                delayMicroseconds(servo_speed_2);
            }
            else if (servo2_angle_O < servo2_angle_P)
            {
                servo2_angle_P = servo2_angle_P - 1;
                servo2.writeMicroseconds(servo2_angle_P);
                delayMicroseconds(servo_speed_2);
            }
            else if (servo2_angle_O = servo2_angle_P)
            {
                servo2.writeMicroseconds(servo2_angle_P);
                delayMicroseconds(servo_speed_2);
            }
            // servo 2 move finish

            // servo 3 move start 
            if (servo3_angle_O > servo3_angle_P)
            {
                servo3_angle_P = servo3_angle_P + 1;
                servo3.writeMicroseconds(servo3_angle_P);
                delayMicroseconds(servo_speed_3);

            }
            else if (servo3_angle_O < servo3_angle_P)
            {
                servo3_angle_P = servo3_angle_P - 1;
                servo3.writeMicroseconds(servo3_angle_P);
                delayMicroseconds(servo_speed_3);
            }
            else if (servo3_angle_O = servo3_angle_P)
            {
                servo3.writeMicroseconds(servo3_angle_P);
                delayMicroseconds(servo_speed_3);
            }
            // servo 3 move finish

        }
        return distance2;

    }
}
