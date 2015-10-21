/*
 IMU to SD to Arducam Logger
 	
 The circuit:
 SD
 * analog sensors on analog ins 0, 1, and 2
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 10
 
 IMU
 SCL - pin A5
 SDA - pin A4
 
 created  19 Oct 2015
 by Penelope Player
 	 
 Arducam
  * analog sensors on analog ins 0, 1, and 2
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 9
 */

#include <SD.h>
#include <SPI.h>
#include <Time.h>

// On the Ethernet Shield, CS is pin 4. Note that even if it's not
// used as the CS pin, the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD library
// functions will not work.

// change this to match your SD shield or module;
// Arduino Ethernet shield: pin 4
// Adafruit SD shields and modules: pin 10
// Sparkfun SD shield: pin 8
// Teensy audio board: pin 10
// Wiz820+SD board: pin 4
// Teensy 2.0: pin 0
// Teensy++ 2.0: pin 20
const int chipSelectSD = 10;
const int chipSelectArducam = 9;

//IMU HEADERS
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_L3GD20_U.h>
#include <Adafruit_9DOF.h>

//MAG CALC HEADERS
#include <math.h>

//Arducam Headers
#include <HW_AVR_SPI_defines.h>
#include <UTFT_SPI.h>

#include <ArduCAM.h>
#include <memorysaver.h>
#include <mt9d111_regs.h>
#include <mt9d112_regs.h>
#include <mt9m001_regs.h>
#include <mt9m112_regs.h>
#include <mt9t112_regs.h>
#include <mt9v111_regs.h>
#include <ov2640_regs.h>
#include <ov3640_regs.h>
#include <ov5640_regs.h>
#include <ov5642_regs.h>
#include <ov7660_regs.h>
#include <ov7670_regs.h>
#include <ov7675_regs.h>
#include <ov7725_regs.h>

/* Assign a unique ID to the sensors */
Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(20);
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(30301);
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(30302);

//GLOBAL VARS
// make a string for assembling the data to log:
//can write to this string from any function (if for example we need to use it to log GPS data)
String dataString = "";

void setup()
{
  // Open serial communications with computer for debugging purposes
  Serial.begin(9600);
  // Setup programs for each individual component go here
  sdcardsetup();
  arducamsetup();
  imusetup();
}

void loop()
{
  delay(2000);
  //log IMU data
  imulog();
}

void sdcardsetup(void){
  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
}

void arducamsetup(void){
  Serial.print("Initializing Arducam...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(9, OUTPUT);

void imusetup(void){
  Serial.println("Gyroscope Test"); 
  Serial.println("");

  /* Enable auto-ranging */
  gyro.enableAutoRange(true);

  /* Initialise the sensor */
  if(!gyro.begin())
  {
    /* There was a problem detecting the L3GD20 ... check your connections */
    Serial.println("Ooops, no L3GD20 detected ... error!");
    while(1); //hang code
  }
  if(!accel.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println(F("Ooops, no LSM303 detected ... Check your wiring!"));
    while(1);
  }
  if(!mag.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }
}

void imulog(void){
  /* Get a new sensor event */
  sensors_event_t gyro_event; 
  sensors_event_t accel_event;
  sensors_event_t mag_event;
  
  gyro.getEvent(&gyro_event);
  accel.getEvent(&accel_event);
  mag.getEvent(&mag_event);
  
  time_t t = now();
  // append to the string
  dataString = String(day(t));
  dataString += ",";
  dataString += String(hour(t));
  dataString += ",";
  dataString += String(minute(t));
  dataString += ",";
  dataString += String(second(t));
  dataString += ",";
  dataString += String(accel_event.acceleration.x);
  dataString += ",";
  dataString += String(accel_event.acceleration.y);
  dataString += ",";
  dataString += String(accel_event.acceleration.z);
  dataString += "\n"; //newline

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("accel.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
  
}
