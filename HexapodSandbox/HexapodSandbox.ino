/**********************************************************************
*  Test code for hexapod bits and bobs
*  Evan Neu, Hunter Badey, Kirk Boyd, Mark Morales, and Evan Neu.
*  Last edit: 03/26/2019 KB
**********************************************************************/
#include <ax12.h> //library for controlling Dynamixel AX12-A Servo
#include <math.h> //extra functions like inverse trig needed

/****I/O****/
#define soundLEDport 2 //blue LED
#define flameLEDport 3 //red LED
#define videoLEDport 4 //green LED
#define pwrLEDport 5 //yellow LED
#define runningLEDport 6 //white LED. indicates the code is running and started
#define startButtonPort 7 //green button
#define button2 8 //undefined button for future functionality
#define button3 9 //undefined button for future functionality
#define button4 10 //undefined button for future functionality
#define button5 11  //undefined button for future functionality
#define versa 16//port for versa valve solenoid

/****SENSORS****/
#define mic1port 17 //1st mic for start sequence
#define mic2port 18 //2nd mic for start sequence
#define flameSensor1port 19 //port for flame sensor 1, on the left from robot's perspective
#define flameSensor2port 20 //2nd flame sensor port, opposite side from above ^
#define sharp1port 21 //sharp sensor 1 port for navigation
#define sharp2port 22 //sharp sensor 2 port for navigation
#define uvTronPort 23 //port for Hammamatsu UVtron sensor
#define vidPort 12 //for now unused port, but dedicated to the video detection for later

/****JOINTS****/
#define CFR 1 //ID num for Coxa Front Right Dynamixel AX12-A Servo
#define CMR 2 //ID num for Coxa Middle Right Dynamixel AX12-A Servo
#define CRR 3 //ID num for Coxa Rear Right Dynamixel AX12-A Servo
#define CRL 4 //ID num for Coxa Rear Left Dynamixel AX12-A Servo
#define CML 5 //ID num for Coxa Middle Left Dynamixel AX12-A Servo
#define CFL 6 //ID num for Coxa Front Left Dynamixel AX12-A Servo
#define FFR 7 //ID num for Femur Front Right Dynamixel AX12-A Servo
#define FMR 8 //ID num for Femur Middle Right Dynamixel AX12-A Servo
#define FRR 9 //ID num for Femur Rear Right Dynamixel AX12-A Servo
#define FRL 10 //ID num for Femur Rear Left Dynamixel AX12-A Servo
#define FML 11 //ID num for Femur Middle Left Dynamixel AX12-A Servo
#define FFL 12 //ID num for Femur Front Left Dynamixel AX12-A Servo

boolean started = false; //boolean for keeping an LED on while code is running
boolean flameSeen = false; //boolean for checking if hammamatsu has seen a the room with the flame in it
boolean babySeen = false;  //boolean for checking if baby was detected with vision
boolean uvTronDone = false; //boolean for indicating completed use of uvTron
boolean aimed = false; //this should be true when the nozzle is aimed on center with the candle

void setup() {
  Serial.begin(9600);
  pinMode(soundLEDport,OUTPUT);
  digitalWrite(soundLEDport,LOW);
  pinMode(flameLEDport,OUTPUT);
  digitalWrite(flameLEDport,LOW);
  pinMode(videoLEDport,OUTPUT);
  digitalWrite(videoLEDport,LOW);
  pinMode(pwrLEDport,OUTPUT);
  digitalWrite(pwrLEDport,HIGH);
  pinMode(startButtonPort,INPUT);
  stand(1000);
  Serial.println("init");
//  while(!soundSystem()){
//  }
}

void loop() {
  if (startButton()){
    
  }
}

/* Main walk (add back later after testing new trig and such if desired) */
//    walkStance(1000);
//    walkA(500);
//    delay(1000);
//    while(!startButton()){
//      walkB(500);
//      walkC(500);
//      walkD(500);
//      walkE(500);
//    }
