#define TRUE 1
#define FALSE 0

unsigned char byteReceived = 0x93;
unsigned char ID = 2;
char isItMySat(char received);
char qe;

boolean TRANSMISSION = 0; //boolean of whether we're transmitting or not

String dataString = "";

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  checkping();
  printdata();
}

void checkping(void){
  //check serial
  if (Serial1.available() > 0){
    byteReceived = Serial1.read();
    Serial.println(byteReceived); //send byte to computer for debugging
  }
  
  //check if it is calling our sat
  qe = isItMySat(byteReceived);
  //if it is reply
  if (qe){
    char i;
    for (i=0;i<2;i++){ //print out byteReceived three times
      Serial1.println(byteReceived);
      Serial.println(byteReceived);
    }
    TRANSMISSION = true;
  }
}


char isItMySat(char received)
{
  char hello = (received >> 6) & 0x03;
  if (hello == ID)
  {
    //Serial.println("h");
    return TRUE;
  }
  else
  {
    //Serial.println("f=");
    return FALSE;
  }
}

void printdata(void){
  //start printing data off sd card
}

