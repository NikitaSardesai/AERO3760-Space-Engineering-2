#include <SD.h>
#include <SPI.h>

const int chipSelectSD = 11;

void setup() {
  // setup serial to 9600
  Serial.begin(9600);
  // set up the SD card to store the data
}

void loop() {
  // put your main code here, to run repeatedly:
    File dataFile = SD.open("snapSat.txt", FILE_WRITE);
    char nextByte;
    delay(10000);
    Serial.write("#a+");
    while(1){
      if(Serial.available()>0){
        nextByte = Serial.read();
        if(nextByte == '*'){
          nextByte = Serial.read();
          if(nextByte == '*'){ // transmission is complete
            dataFile.println("");
            dataFile.println("End of transmission");
            dataFile.close();
          }
        }
      dataFile.print(nextByte);
      }
     
    }
  

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
