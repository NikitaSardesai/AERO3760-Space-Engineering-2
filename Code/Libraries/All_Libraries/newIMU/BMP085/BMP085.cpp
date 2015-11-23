#include <BMP085.h>
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

// Public Methods //////////////////////////////////////////////////////////////
void BMP085::read(void){
  temperature = getTemp(getTempU());
  pressure = getPressure(getPressureU());
}
void BMP085::Calibration(void){
  calibration.ac1 = read2(0xAA);
  calibration.ac2 = read2(0xAC);
  calibration.ac3 = read2(0xAE);
  calibration.ac4 = read2(0xB0);
  calibration.ac5 = read2(0xB2);
  calibration.ac6 = read2(0xB4);
  calibration.b1 = read2(0xB6);
  calibration.b2 = read2(0xB8);
  calibration.mb = read2(0xBA);
  calibration.mc = read2(0xBC);
  calibration.md = read2(0xBE);
}

short BMP085::getTemp(uint16_t ut){
  int32_t x1, x2;
  
  x1 = (((int32_t)ut - (int32_t)calibration.ac6)*(int32_t)calibration.ac5) >> 15;
  x2 = ((int32_t)calibration.mc << 11)/(x1 + calibration.md);
  b5 = x1 + x2;

  return ((b5 + 8)>>4);  
}

int32_t BMP085::getPressure(uint32_t up){
  int32_t x1, x2, x3, b3, b6, p;
  uint32_t b4, b7;
  
  b6 = b5 - 4000;
  // Calculate B3
  x1 = (calibration.b2 * (b6 * b6)>>12)>>11;
  x2 = (calibration.ac2 * b6)>>11;
  x3 = x1 + x2;
  b3 = (((((int32_t)calibration.ac1)*4 + x3)<<OSS) + 2)>>2;
  
  // Calculate B4
  x1 = (calibration.ac3 * b6)>>13;
  x2 = (calibration.b1 * ((b6 * b6)>>12))>>16;
  x3 = ((x1 + x2) + 2)>>2;
  b4 = (calibration.ac4 * (uint32_t)(x3 + 32768))>>15;
  
  b7 = ((uint32_t)(up - b3) * (50000>>OSS));
  if (b7 < 0x80000000)
    p = (b7<<1)/b4;
  else
    p = (b7/b4)<<1;
    
  x1 = (p>>8) * (p>>8);
  x1 = (x1 * 3038)>>16;
  x2 = (-7357 * p)>>16;
  p += (x1 + x2 + 3791)>>4;
  
  return p;
}

int8_t BMP085::read1(uint8_t address){
  uint8_t data;
  
  Wire.beginTransmission(BMP085_ADDRESS);
  Wire.write(address);
  Wire.endTransmission();
  
  Wire.requestFrom(BMP085_ADDRESS, 1);
  while(!Wire.available());
  return Wire.read();
}

int16_t BMP085::read2(uint8_t address){
  uint8_t msb, lsb;
  
  Wire.beginTransmission(BMP085_ADDRESS);
  Wire.write(address);
  Wire.endTransmission();
  
  Wire.requestFrom(BMP085_ADDRESS, 2);
  while(Wire.available()<2)
    ;
  msb = Wire.read();
  lsb = Wire.read();
  
  return (int16_t) msb<<8 | lsb;
}

uint16_t BMP085::getTempU(void){
  
  uint16_t ut;
  
  // Write 0x2E into Register 0xF4
  // This requests a temperature reading
  Wire.beginTransmission(BMP085_ADDRESS);
  Wire.write(0xF4);
  Wire.write(0x2E);
  Wire.endTransmission();
  
  // Wait at least 4.5ms
  delay(5);
  
  // Read two bytes from registers 0xF6 and 0xF7
  ut = read2(0xF6);
  return ut;
}

uint32_t BMP085::getPressureU(void){
  uint8_t msb, lsb, xlsb;
  uint32_t up = 0;
  
  // Write 0x34+(OSS<<6) into register 0xF4
  // Request a pressure reading w/ oversampling setting
  Wire.beginTransmission(BMP085_ADDRESS);
  Wire.write(0xF4);
  Wire.write(0x34 + (OSS<<6));
  Wire.endTransmission();
  
  // Wait for conversion, delay time dependent on OSS
  delay(2 + (3<<OSS));
  
  // Read register 0xF6 (MSB), 0xF7 (LSB), and 0xF8 (XLSB)
  Wire.beginTransmission(BMP085_ADDRESS);
  Wire.write(0xF6);
  Wire.endTransmission();
  Wire.requestFrom(BMP085_ADDRESS, 3);
  
  // Wait for data to become available
  while(Wire.available() < 3)
    ;
  msb = Wire.read();
  lsb = Wire.read();
  xlsb = Wire.read();
  
  up = (((uint32_t) msb << 16) | ((uint32_t) lsb << 8) | (uint32_t) xlsb) >> (8-OSS);
  
  return up;
}
