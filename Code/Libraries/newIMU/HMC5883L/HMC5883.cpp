#include <HMC5883.h>
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

// Turns on the HMC5883 and places in continuous measurment mode
void HMC5883::enable(void)
{
  Wire.beginTransmission(HMC5883_ADDRESS); //open communication with HMC5883
  Wire.write(0x02); //select mode register
  Wire.write(0x00); //continuous measurement mode
  Wire.endTransmission();
}


// Reads the 3 mag channels and stores them in vector m
void HMC5883::read()
{
	uint16_t x,y,z;
	Wire.beginTransmission(HMC5883_ADDRESS);
	// assert the MSB of the address to get the gyro 
	// to do slave-transmit subaddress updating.
	Wire.write(0x03); //register 3, X MSB register
	Wire.endTransmission();

	Wire.requestFrom(HMC5883_ADDRESS, 6);

	if(6<=Wire.available()){
      x = Wire.read()<<8; //X msb
      x |= Wire.read(); //X lsb
      z = Wire.read()<<8; //Z msb
      z |= Wire.read(); //Z lsb
      y = Wire.read()<<8; //Y msb
      y |= Wire.read(); //Y lsb
    }
    m.x = x;
    m.y = y;
    m.z = z;
}
