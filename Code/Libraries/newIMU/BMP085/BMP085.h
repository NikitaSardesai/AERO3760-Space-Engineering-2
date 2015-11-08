#ifndef BMP085_h
#define BMP085_h

//#include <WProgram.h> // for byte data type

// register addresses

#define BMP085_ADDRESS		   0x77

extern "C" {
  #include <stdlib.h>
  #include <string.h>
  #include <inttypes.h>
}

#define Wire Wire1

class BMP085
{
	public:
		
		int16_t temperature;
		int32_t pressure;


		void read(void);

		typedef struct vector
		{
			int16_t ac1, ac2, ac3, b1, b2, mb, mc, md;
			uint16_t ac4, ac5, ac6;
		} vector;

		const uint8_t OSS = 0;

		vector calibration; // mag readings
		
		int32_t b5;

		void Calibration(void);
		int16_t getTemp(uint16_t ut);
		int32_t getPressure(uint32_t up);


		uint16_t getTempU(void);
		uint32_t getPressureU(void);

	private:
		int8_t read1(uint8_t address);
		int16_t read2(uint8_t address);

};


#endif



