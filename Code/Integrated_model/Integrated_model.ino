#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_L3GD20_U.h>
#include <PID_v1.h>


//Initialise the IMU and relevant sensors
/* Assign a unique ID to this sensor at the same time */
Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(20);
float yawAngleR;
float yawAngleD;
float dt;
float yawVel;


//Initialise the PID controller and relevant sensors
const int voltage = 9; // Voltage Ouput to a PWM Pin


//These are the main tuning parameters which will be set based on the simulink model
float Kp= 1.12256776547079; //Set Proportional Gain from Simulink Model
float Ki= 0.00108754475860273; //Set Integral Gain from Simulink Model
float Kd= 78.4340216040309; //Set Differential Gain from Simulink Model
double Setpoint, Input, Output; //These are just variables for storingvalue 

//This thing sends it through a function that is already set up.
PID myPID (&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
// This sets up our PDID Loop
//Input is our PV
//Output is our u(t)
//Setpoint is our SP
const int sampleRate = 1; // Variable that determines how fast our PID loop runs
// Communication setup
const long serialPing = 500; //This determines how often we ping our loop
// Serial pingback interval in milliseconds
unsigned long now = 0; //This variable is used to keep track of time
// placehodler for current timestamp
unsigned long lastMessage = 0; //This keeps track of when our loop last spoke to serial
// last message timestamp.


//Initialise the H-Bridge Controllor and Relevant Pins
// Initialise the pins for magnetorquer 1
int motor1Pin1 = 4; // pin 2 on L293D
int motor1Pin2 = 3; // pin 7 on L293D
int enablePin = 9; // pin 1 on L293D (Needs to be  PWM pin to be able to control motor speed)

// Initialise the pins for magnetorquer 2
int motor2Pin1 = 5; // pin 10 on L293D
int motor2Pin2 = 6; // pin 15 on L293D
int enablePin2 = 10; // pin 9 on L293D (Needs to be a PWM pin to be able to control motor speed)


void displaySensorDetails(void)
{
  sensor_t sensor;
  gyro.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" rad/s");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" rad/s");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" rad/s");  
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}


void setup() 
{
  //Setup code for IMU
  {
  Serial.begin(9600);
  Serial.println("Gyroscope Test"); Serial.println("");
  yawAngleR = 0;
        dt = 0.5;
  /* Enable auto-ranging */
  gyro.enableAutoRange(true);
  
  /* Initialise the sensor */
  if(!gyro.begin())
  {
    /* There was a problem detecting the L3GD20 ... check your connections */
    Serial.println("Ooops, no L3GD20 detected ... Check your wiring!");
    while(1);
  }
  
  /* Display some basic information on this sensor */
  displaySensorDetails();
}

  //Set up code for PID controller
  {
 //Set Input as current angle
 Input = yawAngleR;
 
 //This sets the angle that it the PID is aiming to converge to in radians
 Setpoint = 1.57;

 //Turon on the PID loop and set the sample rate
 myPID.SetMode(AUTOMATIC);
 myPID.SetSampleTime(sampleRate);
 myPID.SetOutputLimits(-255, 255);
 Serial.println("Begin"); // Hello World!
 lastMessage = millis(); // timestamp
}

  //Set up code for H-Bridge and magnetorquer control
  {
    
    // set all the other  magnetorquer 1 pins you're using as outputs:
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enablePin, OUTPUT);

    // set all the other magnetorquer 2 pins you're using as outputs:
    pinMode(motor2Pin2, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enablePin2, OUTPUT);

    // set the two enablePins to high so that both motors can turn on:
    digitalWrite(enablePin, HIGH);
    digitalWrite(enablePin2, HIGH);
  }
}


void loop(void) 
{
  //Actual loop to determine the yaw angle from the IMU
  {
  /* Get a new sensor event */ 
  sensors_event_t event; 
  gyro.getEvent(&event);
  
 yawVel   = event.gyro.z + 0.02;
 yawAngleR = (yawAngleR + yawVel*dt);
 Serial.print("YawAngel: "); Serial.print(yawAngleR); Serial.println("  ");
  delay(dt*1000);
  }

  //Use the yaw angle in the PID to output a voltage
  {
     // Read the setpoint in radians
 Setpoint = 1.57;
 
 // Read the current angle 
 Input = yawAngleR;

 
 myPID.Compute(); //Run the PID loop
 
 analogWrite(voltage, Output); //Write out the output from the PID loop to our PWM Voltage Pin
 analogWrite(10, Output);
 Serial.print("Voltage: "); Serial.print(5*Output/255); Serial.println("  ");

 now = millis(); //Keep track of time
 if(now - lastMessage > serialPing) { //If it has been long enough give us some info on serial
 // this should execute less frequently
 // send a message back to the mother ship
 Serial.print("Setpoint = ");
 Serial.print(Setpoint);
 Serial.print(" Input = ");
 Serial.print(Input);
 Serial.print(" Output = ");
 Serial.print(Output);
 Serial.print("\n");
 if (Serial.available() > 0) { //If we sent the program a command deal with it
 for (int x = 0; x < 4; x++) {
 switch (x) {
 case 0:
 Kp = Serial.parseFloat();
 break;
 case 1:
 Ki = Serial.parseFloat();
 break;
 case 2:
 Kd = Serial.parseFloat();
 break;
 case 3:
 for (int y = Serial.available(); y == 0; y--) {
 Serial.read(); //Clear out any residual junk
 }
 break;
 }
 }
 Serial.print(" Kp,Ki,Kd = ");
 Serial.print(Kp);
 Serial.print(",");
 Serial.print(Ki);
 Serial.print(",");
 Serial.println(Kd); //Let us know what we just received
 myPID.SetTunings(Kp, Ki, Kd); //Set the PID gain constants and start running
 }

 lastMessage = now;
 //update the time stamp. 

 }
}

//Running the H-Bridge Code
  {
    // Initial the Serial Interface
    if (Output >= 0){
    // Motor's forward
    // If Output is positve put current through the magnetorquers to spin SnapSat
    analogWrite(enablePin, Output); //Sets speed variable for magnetorquer 1 via PWM
    digitalWrite(motor1Pin1, LOW); // set pin 2 on L293D low
    digitalWrite(motor1Pin2, HIGH); // set pin 7 on L293D high

    analogWrite(enablePin2, Output); //Sets speed variable for magnetorquer 2 via PWM
    digitalWrite(motor2Pin1, LOW); //set pin 10 on L293D low
    digitalWrite(motor2Pin2, HIGH); //set pin 15 on L293D high
    Serial.println("Both Magnetorquers Forward");
    Serial.println("    ");
    }
    
    else {
      Output = - Output;
    //Motor's Reverse
    // If Output is negative it reverses the current in the magnetorquer's using the H-Bridge
    analogWrite(enablePin, Output); //Sets speed variable for magnetorquer 1 via PWM
    digitalWrite(motor1Pin1, HIGH); // set pin 2 on L293D high
    digitalWrite(motor1Pin2, LOW); // set pin 7 on L293D low

    analogWrite(enablePin2, Output); //Sets speed variable for magnetorquer 2 via PWM
    digitalWrite(motor2Pin1, HIGH); // set pin 10 on L293D high
    digitalWrite(motor2Pin2, LOW); //set pin 15 on L293D low
    Serial.println("Both Magnetorquers Reverse");
    Serial.println("    ");
  
    }

    //else  (Output == 0); {
    //Motor's Stop  
    // If Ouput is zero the Motors will stop
    //analogWrite(enablePin, Output); //Sets speed variable for magnetorquer 1 via PWM
    //digitalWrite(motor1Pin1, HIGH); // set pin 2 on L293D high
    //digitalWrite(motor1Pin2, HIGH); // set pin 7 on L293D low

    //analogWrite(enablePin2, Output); //Sets speed variable for magnetorquer 2 via PWM
    //digitalWrite(motor2Pin1, HIGH); // set pin 10 on L293D high
    //digitalWrite(motor2Pin2, LOW); //set pin 15 on L293D low
    //Serial.println("Both Magnetorquers Stop");
    //Serial.println("    ");
  
    //}
  }
}
