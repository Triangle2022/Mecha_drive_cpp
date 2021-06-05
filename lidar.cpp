#include "Wire.h"
extern "C" {
#include "utility/twi.h"  
}
#include "Adafruit_VL53L0X.h"
#include "lidar.h"

#define TCAADDR 0x70


void lidar_sensor::tcaselect(uint8_t i)
{
    if (i > 7) return;

    Wire.beginTransmission(TCAADDR);
    Wire.write(1 << i);
    Wire.endTransmission();
}
void lidar_sensor::tcasetup(Adafruit_VL53L0X& lox)
{
    while (!Serial);
    delay(500);
    Wire.begin();
    Serial.begin(9600);

    Serial.print("Start.");

    tcaselect(1);
    if (!lox.begin())
    {
        Serial.println(F("Failed to boot LIDAR_1"));
        while (1);
    }

    /*tcaselect(2);
    if (!lox.begin())
    {
        Serial.println(F("Failed to boot LIDAR_2"));
        while (1);
    }

    tcaselect(3);
    if (!lox.begin())
    {
        Serial.println(F("Failed to boot LIDAR_3"));
        while (1);
    }

    tcaselect(4);
    if (!lox.begin())
    {
        Serial.println(F("Failed to boot LIDAR_4"));
        while (1);
    }*/

    Serial.println(" End setup");
    delay(200);
}



int lidar_sensor::front_lidar(Adafruit_VL53L0X& lox)
{
    VL53L0X_RangingMeasurementData_t measure;

    tcaselect(1);
    lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

    if (measure.RangeStatus != 4) {  // phase failures have incorrect data

        int front_lidar_data = measure.RangeMilliMeter;


        return front_lidar_data;
    }
    else {
        return 0;
    }
}

int lidar_sensor::rear_lidar(Adafruit_VL53L0X& lox)
{
    VL53L0X_RangingMeasurementData_t measure;

    tcaselect(3);
    lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

    if (measure.RangeStatus != 4) {  // phase failures have incorrect data

        rear_lidar_data = measure.RangeMilliMeter;
        return rear_lidar_data;
    }
    else {
        return 0;
    }
}

int lidar_sensor::left_lidar(Adafruit_VL53L0X& lox)
{
    VL53L0X_RangingMeasurementData_t measure;

    tcaselect(2);
    lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

    if (measure.RangeStatus != 4) {  // phase failures have incorrect data

        left_lidar_data = measure.RangeMilliMeter;
        return left_lidar_data;
    }
    else {
        return 0;
    }
}

int lidar_sensor::right_lidar(Adafruit_VL53L0X& lox)
{
    VL53L0X_RangingMeasurementData_t measure;

    tcaselect(4);
    lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

    if (measure.RangeStatus != 4) {  // phase failures have incorrect data

        right_lidar_data = measure.RangeMilliMeter;
        return right_lidar_data;
    }
    else {
        return 0;
    }
}




