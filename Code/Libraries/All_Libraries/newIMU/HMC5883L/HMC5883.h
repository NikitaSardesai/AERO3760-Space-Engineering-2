#ifndef HMC5883_h
#define HMC5883_h

//#include <WProgram.h> // for byte data type

// register addresses

#define HMC5883_ADDRESS		   0x1E

extern "C" {
  #include <stdlib.h>
  #include <string.h>
  #include <inttypes.h>
}

#define Wire Wire1

class HMC5883
{
	public:
		typedef struct vector
		{
			int16_t x, y, z;
		} vector;
		
		vector m; // mag readings

		void enable(void);
		
		void writeReg(uint8_t reg, uint8_t value);
		uint8_t readReg(uint8_t reg);
		
		void read(void);
		
		// vector functions
		static void vector_cross(const vector *a, const vector *b, vector *out);
		static float vector_dot(const vector *a,const vector *b);
		static void vector_normalize(vector *a);
};

#endif



