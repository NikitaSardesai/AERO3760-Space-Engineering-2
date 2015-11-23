#include <SD.h>
#include <SPI.h>

const int chipSelectSD = 11;
char nextByte;

// If this serial isn't working, change the connections to Serial1 but it should be fine

void setup() {
  // setup serial to 9600
  Serial1.begin(9600); // this should probably be changed to 57600 as this is what comms is set to
  Serial.begin(9600); // this should probably be changed to 57600 as this is what comms is set to
  // set up the SD card to store the data
}

void loop() {
    //File dataFile = SD.open("snapSat.txt", FILE_WRITE);


    Serial1.write("#c+");
    while(1){
      if(Serial1.available()>0){
        // Serial.write("Serial is available");
        nextByte = Serial1.read();

        if(nextByte == '*'){
          Serial.print(nextByte);
          nextByte = Serial1.read();
          Serial.println("Got first star");
          if(nextByte == '*'){ // transmission is complete
            Serial.print(nextByte);
            Serial.println("");
            Serial.println("End of transmission");
            //dataFile.println("");
            //dataFile.println("End of transmission");
            //dataFile.close();
          }
        }
      Serial.print(nextByte);
      //dataFile.print(nextByte);
      }
     
    }
  

}

/*
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
*/
