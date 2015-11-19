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
 SCL1 and SDA1 running off 3.3V

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
#include <ADXL345.h>
#include <HMC5883.h>
#include <L3G4200D.h>
#include <BMP085.h>

//and vals
L3G4200D gyro;
HMC5883 mag;
BMP085 tp;
ADXL345 accel;

//MAG CALC HEADERS

//Arducam Headers

#include <ArduCAM.h>
#include <memorysaver.h>

/* Assign a unique ID to the sensors */

//GLOBAL VARS
// make a string for assembling the data to log:
//can write to this string from any function (if for example we need to use it to log GPS data)
String dataString = "";

ArduCAM myCAM(OV2640, chipSelectArducam);


//GPS HEADERS
uint8_t GPSBuffer[82];
uint8_t GPSIndex = 0;
int16_t deleteFlag = 0;
char nextByte;
int transmission = 0;
uint16_t GPS_Satellites = 0;
uint16_t GPS_Altitude = 0;
uint16_t gpstime = 0;
uint16_t latitude = 0;
uint16_t longitude = 0;

void setup()
{
  // Open serial communications with computer for debugging purposes
  Serial.begin(9600);
  Serial1.begin(57600);
  // Setup programs for each individual component go here
  sdcardsetup();
  arducamsetup(); //starts wire1
  gpssetup();

  imusetup();
}

void gpssetup(void) {
  Serial3.begin(9600);
  Serial.begin(9600);
  Serial.write("starting gps...");
}

void updateMode(void){
  Serial.println("Message in buffer");
  nextByte = Serial1.read();
  if(nextByte == '#'){
      Serial.println("First Byte #");
      //Serial1.println(nextByte);
      while (Serial1.available()==0){}
      nextByte = Serial1.read();
      Serial.println(nextByte);
      //Serial1.println(nextByte);
      if(nextByte == 'e'){
        Serial.println("Second Byte e");
        while (Serial1.available()==0){}
        nextByte = Serial1.read();
        
        if(nextByte == '+'){
          transmission = 1;
          Serial.println("Transmission == On");
        }
        else if (nextByte == '&'){
          transmission = 0;
          Serial.println("Transmission == Off");
        }
        else if (nextByte == '-'){
            for(int i = 0; i<19;i++){
              //delTime[i] = Serial1.read();
            }
            deleteFlag = 1;
        }
      }
    }
}

void transmit(void){
    File dataFile = SD.open("accel.txt", FILE_READ);
    while(dataFile.available()){
      Serial1.write(dataFile.read());
    }
    dataFile.close();
    
    dataFile = SD.open("tp.txt", FILE_READ);
    while(dataFile.available()){
      Serial1.write(dataFile.read());
    }
    dataFile.close();

        
    dataFile = SD.open("gyro.txt", FILE_READ);
    while(dataFile.available()){
      Serial1.write(dataFile.read());
    }
    dataFile.close();

    dataFile = SD.open("gps.txt", FILE_READ);
    while(dataFile.available()){
      Serial1.write(dataFile.read());
    }
    dataFile.close();

    dataFile = SD.open("mag.txt", FILE_READ);
    while(dataFile.available()){
      Serial1.write(dataFile.read());
    }
    dataFile.close();
    Serial1.print("**");
}

void loop()
{
  if(Serial1.available()>0){
    updateMode();
  }
  if (transmission ==1){
    Serial1.println("Transmiting from satellite");
    transmit();
    transmission = 0;
  }
  delay(2000);
  //log IMU data
  imulog();
  delay(1000);
  capture();
  CheckGPS();
}


void sdcardsetup(void) {
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

void arducamsetup(void) {

  uint8_t vid, pid;
  uint8_t temp;

  Wire1.begin();
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

  if (temp != 0x55)
  {
    Serial.println("SPI1 interface Error!");
    //while(1);
  }

  myCAM.set_mode(MCU2LCD_MODE);

  //Check if the camera module type is OV2640
  myCAM.rdSensorReg8_8(OV2640_CHIPID_HIGH, &vid);
  myCAM.rdSensorReg8_8(OV2640_CHIPID_LOW, &pid);

  if ((vid != 0x26) || (pid != 0x42))
    Serial.println("Can't find OV2640 module!");
  else
    Serial.println("OV2640 detected.");

  //Change to JPEG capture mode and initialize the OV5642 module
  myCAM.set_format(JPEG);
  myCAM.InitCAM();
  myCAM.OV2640_set_JPEG_size(OV2640_320x240);
  myCAM.clear_fifo_flag();
  myCAM.write_reg(ARDUCHIP_FRAMES, 0x00);
  myCAM.set_bit(ARDUCHIP_GPIO, GPIO_PWDN_MASK); //enable low power
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
  time_t t = now();
  // append to the string
  dataString = String(day(t));
  dataString += "/";
  dataString += String(hour(t));
  dataString += "/";
  dataString += String(minute(t));
  dataString += "/";
  dataString += String(second(t));
  dataString += "/";
  //get acceleration values
  accel.read();
  dataString += "A: ";
  dataString += "X: ";
  dataString += String((float)accel.a.Xg / 13.1);
  dataString += " ";
  dataString += "Y: ";
  dataString += String((float)accel.a.Yg / 13.1);
  dataString += " ";
  dataString += "Z: ";
  dataString += String((float)accel.a.Zg / 13);
  dataString += " g";
  dataString += "\n"; //newline

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("accel.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.print(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening accel.txt");
  }

  //gyro log
  t = now();
  // append to the string
  dataString = String(day(t));
  dataString += "/";
  dataString += String(hour(t));
  dataString += "/";
  dataString += String(minute(t));
  dataString += "/";
  dataString += String(second(t));
  dataString += "/";
  //get gyro values
  gyro.read();
  dataString += "G: ";
  dataString += "X: ";
  dataString += String(gyro.g.x);
  dataString += " ";
  dataString += "Y: ";
  dataString += String(gyro.g.y);
  dataString += " ";
  dataString += "Z: ";
  dataString += String(gyro.g.z);
  dataString += " dps";
  dataString += "\n"; //newline

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  dataFile = SD.open("gyro.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.print(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening gyro.txt");
  }

  //mag log
  t = now();
  // append to the string
  dataString = String(day(t));
  dataString += "/";
  dataString += String(hour(t));
  dataString += "/";
  dataString += String(minute(t));
  dataString += "/";
  dataString += String(second(t));
  dataString += "/";
  //get mag values
  mag.read();
  dataString += "M: ";
  dataString += "X: ";
  dataString += String((float)mag.m.x);
  dataString += " ";
  dataString += "Y: ";
  dataString += String((float)mag.m.y);
  dataString += " ";
  dataString += "Z: ";
  dataString += String((float)mag.m.z);
  dataString += " gauss";
  dataString += "\n"; //newline

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  dataFile = SD.open("mag.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.print(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening mag.txt");
  }

  //temperature and pressure
  t = now();
  // append to the string
  dataString = String(day(t));
  dataString += "/";
  dataString += String(hour(t));
  dataString += "/";
  dataString += String(minute(t));
  dataString += "/";
  dataString += String(second(t));
  dataString += "/";
  //get imu values
  tp.read();
  dataString += "Temperature: ";
  dataString += String(tp.temperature);
  dataString += " K";
  dataString += " Pressure: ";
  dataString += String(tp.pressure);
  dataString += " Pa";
  dataString += "\n"; //newline

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  delay(10);
  dataFile = SD.open("tp.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.print(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening tp.txt");
  }

}

void capture(void) {
  uint8_t temp, temp_last;
  uint8_t start_capture = 0;
  bool is_header = false;
  int total_time = 0;

  temp = 0x10;

  Serial.println("CAM1 start single shot.");
  myCAM.clear_bit(ARDUCHIP_GPIO, GPIO_PWDN_MASK); //disable low power

  delay(800);
  myCAM.flush_fifo();
  myCAM.clear_fifo_flag();
  //Start capture
  myCAM.start_capture();
  start_capture = 0;

  while (!(myCAM.get_bit(ARDUCHIP_TRIG, CAP_DONE_MASK)));

  if (myCAM.get_bit(ARDUCHIP_TRIG, CAP_DONE_MASK))
  {
    myCAM.set_bit(ARDUCHIP_GPIO, GPIO_PWDN_MASK);
    Serial.println("CAM Capture Done!");

    uint32_t length = 0;
    length = myCAM.read_fifo_length();
    Serial.println(length);
    if (length >= 393216 ) // 384kb
    {
      Serial.println("Over size.");
      myCAM.clear_fifo_flag();
      return;
    }

    if (length == 0 ) //0 kb
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
    strcat(str, ".jpg");
    //Open the new file
    dataFile = SD.open(str, O_WRITE | O_CREAT | O_TRUNC);

    //
    // if the file is available, write to it:

    total_time = millis();
    i = 0;
    temp = myCAM.read_fifo();
    //Write first image data to buffer
    buf[i++] = temp;

    //Read JPEG data from FIFO
    while ( (temp != 0xD9) | (temp_last != 0xFF) )
    {
      temp_last = temp;
      temp = myCAM.read_fifo();
      //Write image data to buffer if not full
      if (i < 256)
        buf[i++] = temp;
      else
      {
        //Write 256 bytes image data to file
        dataFile.write(buf, 256);
        i = 0;
        buf[i++] = temp;
      }
    }
    //Write the remain bytes in the buffer
    if (i > 0)
      dataFile.write(buf, i);


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
  uint8_t inByte;
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
    dataString = "Timestamp :";
    dataString += String(gpstime);
    dataString += "Latitude :";
    dataString += String(latitude);
    dataString += "Longitude :";
    dataString += String(longitude);
    dataString += "Altitude :";
    dataString += String(GPS_Altitude);
    dataString += "Satellites :";
    dataString += String(GPS_Satellites);
    dataString += "\n";

    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    File dataFile = SD.open("gps.txt", FILE_WRITE);

    // if the file is available, write to it:
    if (dataFile) {
      dataFile.print(dataString);
      dataFile.close();
      // print to the serial port too:
      Serial.println(dataString);
    }
    // if the file isn't open, pop up an error:
    else {
      Serial.println("error opening gps.txt");
    }

  }
}

void ProcessGNGGACommand() {

  int16_t i, j, k, IntegerPart;
  uint16_t Altitude;
  uint16_t timestamp;
  uint16_t latstamp;
  uint16_t longstamp;

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
      else if (j == 2) {
        //lat
        if ((GPSBuffer[i] >= '0') && (GPSBuffer[i] <= '9'))
        {
          latstamp = latstamp * 10;
          latstamp += (unsigned int)(GPSBuffer[i] - '0');
        }
      }
      else if (j == 3) {
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
