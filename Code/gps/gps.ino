#define STATUSLED 13

byte GPSBuffer[82];
byte GPSIndex = 0;
unsigned int GPS_Satellites = 0;
unsigned int GPS_Altitude = 0;
unsigned int gpstime = 0;
unsigned int latitude = 0;
unsigned int longitude = 0;

void setup() {
  pinMode(STATUSLED, OUTPUT);
  Serial3.begin(9600);
  Serial.begin(9600);
  Serial.write("starting gps...");
  setGPS_DynamicModel6();
}

void loop()
{
  delay(1000);
  CheckGPS();
}

void CheckGPS()
{
  int inByte;
  while (Serial3.available() > 0)
  {
    inByte = Serial3.read();
    Serial.print(Serial3.read());
    if ((inByte == '$') || (GPSIndex >= 80))
    {
      GPSIndex = 0;
    }

    if (inByte != '\r')
    {
      GPSBuffer[GPSIndex++] = inByte;
    }

    if (inByte == '\n')
    {
      ProcessGPSLine();
      GPSIndex = 0;
    }
  }
}
void ProcessGPSLine()
{
  if ((GPSBuffer[1] == 'G') && (GPSBuffer[2] == 'N') && (GPSBuffer[3] == 'G') && (GPSBuffer[4] == 'G') && (GPSBuffer[5] == 'A'))
  {
    Serial.println("GNGGA Detected!");
//    int a=0;
//    for (a=0;a<81;a++){
//      Serial.print(GPSBuffer[a]);
//    }
    ProcessGNGGACommand();
    Serial.print("Timestamp :");
    Serial.println(gpstime);
    Serial.print("Latitude :");
    Serial.println(latitude);
    Serial.print("Longitude :");
    Serial.println(longitude);
    Serial.print("Altitude :");
    Serial.println(GPS_Altitude);
    Serial.print("Satellites :");
    Serial.println(GPS_Satellites);

    
  }
  else
  {
    //    Serial.println("It was something else!");
    //    int i;
    //    for (i=1;i<10;i++){
    //      Serial.println(GPSBuffer[i]);
    //    }
  }
}

void ProcessGNGGACommand() {

  int i, j, k, IntegerPart;
  unsigned int Altitude;
  unsigned int timestamp;
  unsigned int latstamp;
  unsigned int longstamp;

  // $GNGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47
  //                                               =====  <-- altitude in field 8

  IntegerPart = 1;
  GPS_Satellites = 0;
  Altitude = 0;
  timestamp = 0;
  latstamp = 0;
  longstamp = 0;

  for (i = 7, j = 0, k = 0; (i < GPSIndex) && (j < 9); i++) // We start at 7 so we ignore the '$GNGGA,'
  {
    if (GPSBuffer[i] == ',')
    {
      j++;    // Segment index
      k = 0;  // Index into target variable
      IntegerPart = 1;
    }
    else
    {
      if (j == 0)
      {
        //timestamp
        if ((GPSBuffer[i] >= '0') && (GPSBuffer[i] <= '9'))
        {
          timestamp = timestamp * 10;
          timestamp += (unsigned int)(GPSBuffer[i] - '0');
        }   
      }
      else if (j == 2){
        //lat
        if ((GPSBuffer[i] >= '0') && (GPSBuffer[i] <= '9'))
        {
          latstamp = latstamp * 10;
          latstamp += (unsigned int)(GPSBuffer[i] - '0');
        }  
      }
      else if (j == 3){
        //long
        if ((GPSBuffer[i] >= '0') && (GPSBuffer[i] <= '9'))
        {
          longstamp = longstamp * 10;
          longstamp += (unsigned int)(GPSBuffer[i] - '0');
        }
      }
      else if (j == 6)
      {
        // Satellite Count
        if ((GPSBuffer[i] >= '0') && (GPSBuffer[i] <= '9'))
        {
          GPS_Satellites = GPS_Satellites * 10;
          GPS_Satellites += (unsigned int)(GPSBuffer[i] - '0');
        }
      }
      else if (j == 8)
      {
        // Altitude
        if ((GPSBuffer[i] >= '0') && (GPSBuffer[i] <= '9') && IntegerPart)
        {
          Altitude = Altitude * 10;
          Altitude += (unsigned int)(GPSBuffer[i] - '0');
        }
        else
        {
          IntegerPart = 0;
        }
      }
    }
    GPS_Altitude = Altitude;
    gpstime = timestamp;
    latitude = latstamp;
    longitude = longstamp;
  }
}

void setGPS_DynamicModel6()
{
 int gps_set_sucess=0;
 uint8_t setdm6[] = {
 0xB5, 0x62, 0x06, 0x24, 0x24, 0x00, 0xFF, 0xFF, 0x06,
 0x03, 0x00, 0x00, 0x00, 0x00, 0x10, 0x27, 0x00, 0x00,
 0x05, 0x00, 0xFA, 0x00, 0xFA, 0x00, 0x64, 0x00, 0x2C,
 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0xDC };
 while(!gps_set_sucess)
 {
 sendUBX(setdm6, sizeof(setdm6)/sizeof(uint8_t));
 gps_set_sucess=getUBX_ACK(setdm6);
 }
}
void sendUBX(uint8_t *MSG, uint8_t len) {
 Serial.flush();
 Serial.write(0xFF);
 delay(500);
 for(int i=0; i<len; i++) {
 Serial.write(MSG[i]);
 }
}
boolean getUBX_ACK(uint8_t *MSG) {
 uint8_t b;
 uint8_t ackByteID = 0;
 uint8_t ackPacket[10];
 unsigned long startTime = millis();
 
// Construct the expected ACK packet
 ackPacket[0] = 0xB5; // header
 ackPacket[1] = 0x62; // header
 ackPacket[2] = 0x05; // class
 ackPacket[3] = 0x01; // id
 ackPacket[4] = 0x02; // length
 ackPacket[5] = 0x00;
 ackPacket[6] = MSG[2]; // ACK class
 ackPacket[7] = MSG[3]; // ACK id
 ackPacket[8] = 0; // CK_A
 ackPacket[9] = 0; // CK_B
 
// Calculate the checksums
 for (uint8_t ubxi=2; ubxi<8; ubxi++) {
 ackPacket[8] = ackPacket[8] + ackPacket[ubxi];
 ackPacket[9] = ackPacket[9] + ackPacket[8];
 }
 
while (1) {
 
// Test for success
 if (ackByteID > 9) {
 // All packets in order!
 return true;
 }
 
// Timeout if no valid response in 3 seconds
 if (millis() - startTime > 3000) {
 return false;
 }
 
// Make sure data is available to read
 if (Serial.available()) {
 b = Serial.read();
 
// Check that bytes arrive in sequence as per expected ACK packet
 if (b == ackPacket[ackByteID]) {
 ackByteID++;
 }
 else {
 ackByteID = 0; // Reset and look again, invalid order
 }
 }
 }
}
