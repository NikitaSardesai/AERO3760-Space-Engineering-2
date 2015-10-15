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
#include <math.h>

/* Assign a unique ID to the sensors */
Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(20);

//Global integers
float loc_fin; //integer containing the final location
float loc_cur; //integer containing the current location
float * loc; //make pointer

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
  
  //Magnetometer setup
  //state pin directions
  for (int i = 2; i<7;i++){    
    pinMode(i, OUTPUT);
  }
  pinMode(39, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(43, OUTPUT);
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

void checkcomms (float * loc){
  int a = 1; //dummy variable to make the code compile
  *loc = a; //location from comms
}

void readimu(float * loc){
  /* Get a new sensor event */ 
  sensors_event_t event; 
  gyro.getEvent(&event);
 
  /* Display the results for debugging(speed is measured in rad/s) */
  Serial.print("X: "); Serial.print(event.gyro.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.gyro.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.gyro.z); Serial.print("  ");
  Serial.println("rad/s ");
  //transform x,y,z data into a heading
  float heading = atan2(event.gyro.y,event.gyro.x); //gives heading in radians
  *loc = heading; //heading from the IMU
  
  //can also get rotation rate if you need
}

void changemag(float diff){
  //nothing code
  //take in a change of heading in radians and move to get to that position
  //if minus rotate clockwise and if plus rotate anticlockwise
  //as a rule try to use the magnotorquer most aligned with where you need to go to make the move less violent
  if (diff > 0){
    //rotate clockwise
  }
  else if (diff < 0){
    //rotate anticlockwise
  }
  //How to use Magnotorquers 
  
  //enable neccesary h bridge
  //turn turn appropriate signals on/off for forwards/backwards
  //can check this on eagle schematics
  
  //eg.
  
  //Mag 1
  //pin43 enable
  digitalWrite(43, HIGH);
  //pin2 and 3 control direction
  analogWrite(2, 0); //ground
  analogWrite(3, 100); //input at about 50% duty cycle
  //can swap them around to change directions
  
  //Mag 2
  //pin41 enable
    //pin43 enable
  digitalWrite(41, HIGH);
  //pin2 and 3 control direction
  analogWrite(4, 0); //ground
  analogWrite(5, 100); //input at about 50% duty cycle
  //can swap them around to change directions
  
  //Mag 3 
    //pin43 enable
  digitalWrite(43, HIGH);
  //pin2 and 3 control direction
  analogWrite(6, 0); //ground
  analogWrite(7, 100); //input at about 50% duty cycle
  //can swap them around to change directions
  //pin8 enable
  //pin 6 and 7 control direction
}


