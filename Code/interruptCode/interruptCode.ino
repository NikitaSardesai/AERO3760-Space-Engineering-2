#include <DueTimer-master.h>

// With the arduino DUE we can use hardware interrupts with any of the pins
// There are 3 timing modules and 3 chanels each giving a total of 9 timer interrupts we could use


volatile void myTimedPrint();
volatile void myTimedPulse();

// Any variables used in interrupts need to be declared as volatile
volatile int counter;
volatile boolean l;

void setup() 
{
  Serial.begin(115200);
  
  
  pinMode(20,INPUT);  
  attachInterrupt(digitalPinToInterrupt(20), ISR_name, CHANGE); //an example of an interrupt on pin 20 that calls
                                                                // ISR_name when therre is a change in state
  
  pinMode(13,OUTPUT);
  counter = 0;
 
  // Start timer. Parameters are

  // TC1 : timer counter. Can be TC0, TC1 or TC2
  // 0   : channel. Can be 0, 1 or 2
  // TC3_IRQn: irq number. See table.
  // 2  : frequency (in Hz)
  // myTimedPrint : function pointer to the function you want executed (we probably wont need this)

  startTimer(TC1, 0, TC3_IRQn, 2, myTimedPrint); // this is setting up the 4th timer to be called twice every second

  // Paramters table:
  // TC0, 0, TC0_IRQn
  // TC0, 1, TC1_IRQn
  // TC0, 2, TC2_IRQn
  // TC1, 0, TC3_IRQn
  // TC1, 1, TC4_IRQn
  // TC1, 2, TC5_IRQn
  // TC2, 0, TC6_IRQn
  // TC2, 1, TC7_IRQn
  // TC2, 2, TC8_IRQn
  
  //Set pulse on a different timer
  startTimer(TC2, 0, TC6_IRQn, 5000, myTimedPulse); // this is setting up the 7th timer at 5000 Hz
}

void loop() 
{
  // This is the main loop that runs repeatedly in a loop
}

volatile void myTimedPrint()
{
  // random example of a function that can be called by an interrupt
}

volatile void myTimedPulse()
{
  // random example of a function that can be called by an interrupt
}

void ISR_name(){
  //interrupt code would go in here

}


