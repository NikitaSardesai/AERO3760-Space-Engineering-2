#include <ADXL345.h>
#include <Wire.h>
#include <math.h>

extern "C" {
  #include <stdlib.h>
  #include <string.h>
  #include <inttypes.h>
}

#define Wire Wire1

// Defines ////////////////////////////////////////////////////////////////

// The Arduino two-wire interface uses a 7-bit number for the address, 
// and sets the last bit correctly based on reads and writes
#define ADXL345_ADDRESS      (0xA7 >> 1)

// Public Methods //////////////////////////////////////////////////////////////
void ADXL345::enable(void){
  Wire.beginTransmission(ADXL345_ADDRESS);
  //Wire.write(DATA_FORMAT);
  //Wire.write(0x01); //Put the ADXL345 into +/- 4G range 
  Wire.write(Register_2D);
  Wire.write(0x08);                //measuring enable
  Wire.endTransmission();     // stop transmitting

  reading = 0;
  val = 0; //initialize private variables
}

void ADXL345::read(void){
  //--------------X
  Wire.beginTransmission(ADXL345_ADDRESS); // transmit to device
  Wire.write(Register_X0);
  Wire.write(Register_X1);
  Wire.endTransmission();
  Wire.requestFrom(ADXL345_ADDRESS,2); 
  if(Wire.available()<=2)   
  {
    X0 = Wire.read();
    X1 = Wire.read(); 
    X1=X1<<8;
    X_out=X0+X1;   
  }

  //------------------Y
  Wire.beginTransmission(ADXL345_ADDRESS); // transmit to device
  Wire.write(Register_Y0);
  Wire.write(Register_Y1);
  Wire.endTransmission();
  Wire.requestFrom(ADXL345_ADDRESS,2); 
  if(Wire.available()<=2)   
  {
    Y0 = Wire.read();
    Y1 = Wire.read(); 
    Y1=Y1<<8;
    Y_out=Y0+Y1;
  }
  //------------------Z
  Wire.beginTransmission(ADXL345_ADDRESS); // transmit to device
  Wire.write(Register_Z0);
  Wire.write(Register_Z1);
  Wire.endTransmission();
  Wire.requestFrom(ADXL345_ADDRESS,2); 
  if(Wire.available()<=2)   
  {
    Z0 = Wire.read();
    Z1 = Wire.read(); 
    Z1=Z1<<8;
    Z_out=Z0+Z1;
  }
  //
  a.Xg=X_out;//*(0.0078);
  a.Yg=Y_out;//*(0.0078);
  a.Zg=Z_out;//*(0.0078);
}