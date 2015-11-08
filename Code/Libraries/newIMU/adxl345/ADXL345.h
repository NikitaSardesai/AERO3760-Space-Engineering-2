#ifndef ADXL345_h
#define ADXL345_h

//#include <WProgram.h> // for byte data type

// register addresses

#define ADXL345_ADDRESS		   (0xA7 >> 1)

#define Register_ID 0
#define Register_2D 0x2D //Power control reg
#define DATA_FORMAT 0x31
#define Register_X0 0x32
#define Register_X1 0x33
#define Register_Y0 0x34
#define Register_Y1 0x35
#define Register_Z0 0x36
#define Register_Z1 0x37

extern "C" {
  #include <stdlib.h>
  #include <string.h>
  #include <inttypes.h>
}

#define Wire Wire1

class ADXL345
{
	public:
		typedef struct vector{
			int16_t Xg, Yg, Zg;
		}vector;

		vector a;

		void enable(void);
		void read(void);

	private:
		int reading;
		int val;;
		uint16_t X0,X1,X_out;
		uint16_t Y0,Y1,Y_out;
		uint16_t Z1,Z0,Z_out;
};


#endif



