//magnetorquer code

//no interrupts to start with, might put some in later

//3 steps:
//read desired gyroscope location from comms system
//read actual gyroscope location from imu
//change magnotorquer appropriately

//different function for each of these things

//IMU HEADERS
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_L3GD20_U.h>
#include <Adafruit_9DOF.h>

/* Assign a unique ID to the sensors */
Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(20);

//Global integers
int loc_fin; //integer containing the final location
int loc_cur; //integer containing the current location
int * loc; //make pointer

void setup(void){  
  //IMU Setup
  Serial.begin(9600); //enable debugging, sending data back to computer
  Serial.println("Gyroscope Test"); Serial.println("");
  
  /* Enable auto-ranging */
  gyro.enableAutoRange(true);
  
  /* Initialise the sensor */
  if(!gyro.begin())
  {
    /* There was a problem detecting the L3GD20 ... check your connections */
    Serial.println("Ooops, no L3GD20 detected ... error!");
    while(1); //hang code
  }
}

void loop(void){
  //find location to go to
  //make pointer
  loc = &loc_fin;
  checkcomms(loc);
  //check current location
  loc = &loc_cur; //change pointer to loc_current
  readimu(loc);
  //move the cubesat to look in that direction
  changemag(loc_fin - loc_cur);
  //arbitrary delay so that the magnotorquer has a chance to change things
  delay(300);
}

void checkcomms (int * loc){
  int a = 1; //dummy variable to make the code compile
  *loc = a; //location from comms
}

void readimu(int * loc){
  /* Get a new sensor event */ 
  sensors_event_t event; 
  gyro.getEvent(&event);
 
  /* Display the results for debugging(speed is measured in rad/s) */
  Serial.print("X: "); Serial.print(event.gyro.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.gyro.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.gyro.z); Serial.print("  ");
  Serial.println("rad/s ");
  //transform x,y,z data into a heading
  int a = 5;
  int heading = a; //data from previous program
  *loc = heading; //heading from the IMU
  
  //can also get rotation rate if you need
}

void changemag(int diff){
  //nothing code
  int a = 0;
  diff = a;
}


