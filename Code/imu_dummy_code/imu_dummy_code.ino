/*
 IMU Dummy Code
 
 Libraries:
 remember to include the 4 extra liraries ADXL345 - accelerometer, HMC5883 - mag, L3G5200D - gyro and BMP085 - temp and pressure
 
 The circuit:

 IMU
 SCL1 and SDA1 running off 3.3V

 created 6 Nov 2015
 by Penelope Player
 */


#include <math.h>

//IMU HEADERS
#include <Wire.h>
#include <ADXL345.h>
#include <HMC5883.h>
#include <L3G4200D.h>
#include <BMP085.h>

//define global variables
L3G4200D gyro;
HMC5883 mag;
BMP085 tp;
ADXL345 accel;


void setup()
{
  // Open serial communications with computer for debugging purposes
  Serial.begin(9600);
  imusetup();
}


void loop()
{
  //log IMU data
  imulog();
  delay(1000);
}

void imusetup(void) {
  Serial.println("Gyroscope Test");
  Serial.println("");

  gyro.enableDefault();
  mag.enable();
  tp.Calibration();
  accel.enable();
}

void imulog(void) {

  //acceleration
  //get acceleration values
  accel.read(); //measures acceleration in m/s^2, change the divide by 13.1 to calibrate more accurately.
  Serial.print( "A: X:");
  Serial.print((float)accel.a.Xg / 13.1);
  Serial.print(" Y: ";
  Serial.print((float)accel.a.Yg / 13.1);
  Serial.print += " Z: ";
  Serial.print((float)accel.a.Zg / 13);
  Serial.print(" g\n"); //newline

  //gyro log
  gyro.read(); //measure movement in degrees per second
  Serial.print( "G: X:");
  Serial.print(gyro.g.x);
  Serial.print(" Y: ";
  Serial.print(gyro.g.x);
  Serial.print += " Z: ";
  Serial.print(gyro.g.x);
  Serial.print(" dps\n"); //newline

  //mag log
  mag.read(); //measures magnetic field in Gauss I think, am not really sure
  Serial.print( "M: X:");
  Serial.print((float)mag.m.x);
  Serial.print(" Y: ";
  Serial.print((float)mag.m.y);
  Serial.print += " Z: ";
  Serial.print((float)mag.m.z);
  Serial.print(" Gauss\n"); //newline

}
