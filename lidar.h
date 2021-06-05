#ifndef lidar_h
#define lidar_h

class lidar_sensor {
private:
	int front_lidar_data;
	int left_lidar_data;
	int right_lidar_data;
	int rear_lidar_data;

public:

	int front_lidar(Adafruit_VL53L0X& lox); //update and output front lidar data.
	int rear_lidar(Adafruit_VL53L0X& lox); // update and output rear lidar data.
	int left_lidar(Adafruit_VL53L0X& lox); // update and output left lidar data.
	int right_lidar(Adafruit_VL53L0X& lox);  //update and output right lidar data.

	void tcaselect(uint8_t i);
	void tcasetup(Adafruit_VL53L0X& lox);
};

#endif
