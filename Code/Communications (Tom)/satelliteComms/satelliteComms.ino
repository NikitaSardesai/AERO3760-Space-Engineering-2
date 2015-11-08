#include <SD.h>
#include <SPI.h>
#include <Time.h>
#include <math.h>



char nextByte;
char delTime[19];
char storedTime[19];
int deleteFlag = 0;
int TRANSMISSION = 0;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(57600);
  Serial.begin(9600);

}

void loop() {
  if(Serial1.available()>0){
    Serial.println("Message in buffer");
    nextByte = Serial1.read();
    if(nextByte == '#'){
      Serial.println("First Byte #");
      Serial1.println(nextByte);
      while (Serial1.available()==0){}
      nextByte = Serial1.read();
      Serial.println(nextByte);
      Serial1.println(nextByte);
      if(nextByte == 'e'){
        Serial.println("Second Byte c");
        while (Serial1.available()==0){}
        nextByte = Serial1.read();
        
        if(nextByte == '+'){
          TRANSMISSION = true;
          Serial.println("Transmission == On");
        }
        else if (nextByte == '&'){
          TRANSMISSION = false;
        }
        else if (nextByte == '-'){
            for(int i = 0; i<19;i++){
              delTime[i] = Serial1.read();
            }
            deleteFlag = 1;
        }
      }
    }
  }
  if(TRANSMISSION == true){
    //Serial1.write("**");
    //Serial.write("**");
    TRANSMISSION == false;
  }
}

// function to open the 4 files containing the 
// to start with just 
// need to expand to be able to start where last left off
// can use the idea of a pointer to a specific byte and cycle through
// that many bytes or just go straight to that location.
// end transmit with "**"
void transmit(void){
    File dataFile = SD.open("gps.txt", FILE_READ);
    while(dataFile.available()){
      Serial1.write(dataFile.read());
    }
    dataFile.close();
    
    dataFile = SD.open("imu.txt", FILE_READ);
    while(dataFile.available()){
      Serial1.write(dataFile.read());
    }
    dataFile.close();

        
    dataFile = SD.open("voltage.txt", FILE_READ);
    while(dataFile.available()){
      Serial1.write(dataFile.read());
    }
    dataFile.close();

    dataFile = SD.open("temp.txt", FILE_READ);
    while(dataFile.available()){
      Serial1.write(dataFile.read());
    }
    dataFile.close();
    Serial1.print("**");
}

/*
Everything that is stored should first have the date in the format:
  time_t t = now();
  dataString = "";
  dataString = String(year(t));
  dataString += "/";
  dataString += String(month(t));
  dataString += "/";
  dataString += String(day(t));
  dataString += "/";
  dataString += String(hour(t));
  dataString += "/";
  dataString += String(minute(t));
  dataString += "/";
  dataString += String(second(t));
*/


/*
// have to detect a new line and start storing information from there for 19 bytes
// after the new date is stored into a variable then compare the strings
// if stored one is older then keep going
// if the stored one is younger then stop from there, send the stored date plus the rest of the line
// to the new file. then copy the rest of the file over
// Then copy it back to the original name.
void deleteTime(void){
    File dataFile = SD.open("gps.txt", FILE_READ);
    File newFile = SD.open("gpsnew.txt", FILE_WRITE);
    int i = 0;
    int stop = 0;


    
    while(dataFile.available()){
      nextByte = Serial1.read();
      if (nextByte == '/n') // or ASCII for newline or carriage return{

        for(i = 0; i<19;i++){
          storedTime[i] = Serial1.read();
        }
        //strcmp storedTime to delTime
        for(i = 0; i<19;i++){
          if (storedTime[i] >delTime[i]){
            //we have just passed the point of delete and we want
            // to move everything including this date to a new file before
            // moving it back. Then we break from the loop
            for(i = 0; i<19;i++){
               newFile.write(storedTime[i]);
            }
            // should transfer all date
            while (dataFile.available()>0){
              newFile.write(dataFile.read());
            }
            newFile.close(); // reopen with read permission so it will start at the beginning
            // need to delete the old file and copy the new one accross
            // SD.remove gps.txt
            SD.remove("gps.txt"):


            break;
          }
        }
    }
    dataFile.close();
}
*/
