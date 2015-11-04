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
    ProcessGNGGACommand();
    Serial.println("Timestamp :");
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
