/*
 IMU to SD to Arducam Logger
 	
 The circuit:
 SD
 * analog sensors on analog ins 0, 1, and 2
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 11
 
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
 ** CS - pin 10
 * 
 * 
 GPS
 *on Serial3 
 *TX - pin
 *RX - pin
 */

#include <SD.h>
#include <SPI.h>
#include <Time.h>
#include <math.h>

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
const int chipSelectSD = 11;
const int chipSelectArducam = 10;

//IMU HEADERS
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_L3GD20_U.h>
#include <Adafruit_9DOF.h>

//MAG CALC HEADERS

//Arducam Headers

#include <ArduCAM.h>
#include <memorysaver.h>

/* Assign a unique ID to the sensors */
//Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(20);
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(30301);
//Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(30302);

//GLOBAL VARS
// make a string for assembling the data to log:
//can write to this string from any function (if for example we need to use it to log GPS data)
String dataString = "";

ArduCAM myCAM(OV2640,chipSelectArducam);


//GPS HEADERS
byte GPSBuffer[82];
byte GPSIndex = 0;
unsigned int GPS_Satellites = 0;
unsigned int GPS_Altitude = 0;
unsigned int gpstime = 0;
unsigned int latitude = 0;
unsigned int longitude = 0;

void setup()
{
  // Open serial communications with computer for debugging purposes
  Serial.begin(9600);
  // Setup programs for each individual component go here
  sdcardsetup();
  arducamsetup();
  gpssetup();

  //  imusetup();
}

void gpssetup(void){
  Serial3.begin(9600);
  Serial.begin(9600);
  Serial.write("starting gps...");
}

void loop()
{
  delay(2000);
  //log IMU data
  //  imulog();
  delay(1000);
  capture();
  CheckGPS();
}


void sdcardsetup(void){
  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);
  pinMode(chipSelectSD, OUTPUT);

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelectSD)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
}

void arducamsetup(void){

  uint8_t vid,pid;
  uint8_t temp;

#if defined (__AVR__)
  Wire.begin(); 
#endif
#if defined(__arm__)
  Wire1.begin();
#endif 
  Serial.println("ArduCAM Start!"); 

  // set the SPI_CS as an output:
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(chipSelectArducam, OUTPUT);

  // initialize SPI:
  SPI.begin(); 
  //Check if the ArduCAM SPI bus is OK
  myCAM.write_reg(ARDUCHIP_TEST1, 0x55);
  temp = myCAM.read_reg(ARDUCHIP_TEST1);

  if(temp != 0x55)
  {
    Serial.println("SPI1 interface Error!");
    //while(1);
  }

  myCAM.set_mode(MCU2LCD_MODE);

  //Check if the camera module type is OV2640
  myCAM.rdSensorReg8_8(OV2640_CHIPID_HIGH, &vid);
  myCAM.rdSensorReg8_8(OV2640_CHIPID_LOW, &pid);

  if((vid != 0x26) || (pid != 0x42))
    Serial.println("Can't find OV2640 module!");
  else
    Serial.println("OV2640 detected.");

  //Change to JPEG capture mode and initialize the OV5642 module	
  myCAM.set_format(JPEG);
  myCAM.InitCAM();
  myCAM.OV2640_set_JPEG_size(OV2640_320x240);
  myCAM.clear_fifo_flag();
  myCAM.write_reg(ARDUCHIP_FRAMES,0x00);
  myCAM.set_bit(ARDUCHIP_GPIO,GPIO_PWDN_MASK);//enable low power
}

void imusetup(void){
  Serial.println("Gyroscope Test"); 
  Serial.println("");

  /* Enable auto-ranging */
//  gyro.enableAutoRange(true);

  /* Initialise the sensor */
//  if(!gyro.begin())
//  {
//    /* There was a problem detecting the L3GD20 ... check your connections */
//    Serial.println("Ooops, no L3GD20 detected ... error!");
//    while(1); //hang code
//  }
  if(!accel.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println(F("Ooops, no LSM303 detected ... Check your wiring!"));
    while(1);
  }
//  if(!mag.begin())
//  {
//    /* There was a problem detecting the LSM303 ... check your connections */
//    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
//    while(1);
//  }
}

void imulog(void){
  /* Get a new sensor event */
//  sensors_event_t gyro_event; 
  sensors_event_t accel_event;
//  sensors_event_t mag_event;

//  gyro.getEvent(&gyro_event);
  accel.getEvent(&accel_event);
//  mag.getEvent(&mag_event);

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

void capture(void){
  uint8_t temp,temp_last;
  uint8_t start_capture = 0;
  bool is_header = false;
  int total_time = 0;

  temp = 0x10;

  Serial.println("CAM1 start single shot.");
  myCAM.clear_bit(ARDUCHIP_GPIO,GPIO_PWDN_MASK);//disable low power

  delay(800);
  myCAM.flush_fifo();
  myCAM.clear_fifo_flag();	 
  //Start capture
  myCAM.start_capture();
  start_capture = 0;

  while(!(myCAM.get_bit(ARDUCHIP_TRIG, CAP_DONE_MASK)));

  if(myCAM.get_bit(ARDUCHIP_TRIG, CAP_DONE_MASK))
  {
    myCAM.set_bit(ARDUCHIP_GPIO,GPIO_PWDN_MASK);
    Serial.println("CAM Capture Done!");

    uint32_t length = 0;
    length = myCAM.read_fifo_length();
    Serial.println(length);
    if(length >= 393216 )  // 384kb
    {
      Serial.println("Over size.");
      myCAM.clear_fifo_flag();
      return;
    }

    if(length == 0 )  //0 kb
    {
      Serial.println("Size is 0.");
      myCAM.clear_fifo_flag();
      return;
    }

    temp = 0;

    //Construct a file name
    File dataFile;
    char str[8];
    byte buf[256];
    static int i = 0;
    static int k = 0;
    static int n = 0;

    k = k + 1;
    itoa(k, str, 10); 
    strcat(str,".jpg");
    //Open the new file  
    dataFile = SD.open(str,O_WRITE | O_CREAT | O_TRUNC);

    //
    // if the file is available, write to it:

    total_time = millis();
    i = 0;
    temp = myCAM.read_fifo();
    //Write first image data to buffer
    buf[i++] = temp;

    //Read JPEG data from FIFO
    while( (temp != 0xD9) | (temp_last != 0xFF) )
    {
      temp_last = temp;
      temp = myCAM.read_fifo();
      //Write image data to buffer if not full
      if(i < 256)
        buf[i++] = temp;
      else
      {
        //Write 256 bytes image data to file
        dataFile.write(buf,256);
        i = 0;
        buf[i++] = temp;
      }
    }
    //Write the remain bytes in the buffer
    if(i > 0)
      dataFile.write(buf,i);
      
    
    //Close the file 
    dataFile.close(); 
    total_time = millis() - total_time;
    Serial.print("Total time used:");
    Serial.print(total_time, DEC);
    Serial.println(" millisecond"); 
    
    //Clear the capture done flag 
    myCAM.clear_fifo_flag();

    is_header = false;
  } 
}


//GPS CODE HERE
void CheckGPS()
{
  int inByte;
  while (Serial3.available() > 0)
  {
    inByte = Serial3.read();

    if ((inByte == '$') || (GPSIndex >= 80))
    {
      GPSIndex = 0;
    }

    if (inByte != '\r')
    {
      GPSBuffer[GPSIndex++] = inByte;
    }

    if (inByte == '\n')
    {
      ProcessGPSLine();
      GPSIndex = 0;
    }
  }
}
void ProcessGPSLine()
{
  if ((GPSBuffer[1] == 'G') && (GPSBuffer[2] == 'N') && (GPSBuffer[3] == 'G') && (GPSBuffer[4] == 'G') && (GPSBuffer[5] == 'A'))
  {
    Serial.println("GNGGA Detected!");
    ProcessGNGGACommand();
    Serial.println("Timestamp :");
    Serial.println(gpstime);
    Serial.print("Latitude :");
    Serial.println(latitude);
    Serial.print("Longitude :");
    Serial.println(longitude);
    Serial.print("Altitude :");
    Serial.println(GPS_Altitude);
    Serial.print("Satellites :");
    Serial.println(GPS_Satellites);

    
  }
  else
  {
    //    Serial.println("It was something else!");
    //    int i;
    //    for (i=1;i<10;i++){
    //      Serial.println(GPSBuffer[i]);
    //    }
  }
}

void ProcessGNGGACommand() {

  int i, j, k, IntegerPart;
  unsigned int Altitude;
  unsigned int timestamp;
  unsigned int latstamp;
  unsigned int longstamp;

  // $GNGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47
  //                                               =====  <-- altitude in field 8

  IntegerPart = 1;
  GPS_Satellites = 0;
  Altitude = 0;
  timestamp = 0;
  latstamp = 0;
  longstamp = 0;

  for (i = 7, j = 0, k = 0; (i < GPSIndex) && (j < 9); i++) // We start at 7 so we ignore the '$GNGGA,'
  {
    if (GPSBuffer[i] == ',')
    {
      j++;    // Segment index
      k = 0;  // Index into target variable
      IntegerPart = 1;
    }
    else
    {
      if (j == 0)
      {
        //timestamp
        if ((GPSBuffer[i] >= '0') && (GPSBuffer[i] <= '9'))
        {
          timestamp = timestamp * 10;
          timestamp += (unsigned int)(GPSBuffer[i] - '0');
        }   
      }
      else if (j == 2){
        //lat
        if ((GPSBuffer[i] >= '0') && (GPSBuffer[i] <= '9'))
        {
          latstamp = latstamp * 10;
          latstamp += (unsigned int)(GPSBuffer[i] - '0');
        }  
      }
      else if (j == 3){
        //long
        if ((GPSBuffer[i] >= '0') && (GPSBuffer[i] <= '9'))
        {
          longstamp = longstamp * 10;
          longstamp += (unsigned int)(GPSBuffer[i] - '0');
        }
      }
      else if (j == 6)
      {
        // Satellite Count
        if ((GPSBuffer[i] >= '0') && (GPSBuffer[i] <= '9'))
        {
          GPS_Satellites = GPS_Satellites * 10;
          GPS_Satellites += (unsigned int)(GPSBuffer[i] - '0');
        }
      }
      else if (j == 8)
      {
        // Altitude
        if ((GPSBuffer[i] >= '0') && (GPSBuffer[i] <= '9') && IntegerPart)
        {
          Altitude = Altitude * 10;
          Altitude += (unsigned int)(GPSBuffer[i] - '0');
        }
        else
        {
          IntegerPart = 0;
        }
      }
    }
    GPS_Altitude = Altitude;
    gpstime = timestamp;
    latitude = latstamp;
    longitude = longstamp;
  }
}
