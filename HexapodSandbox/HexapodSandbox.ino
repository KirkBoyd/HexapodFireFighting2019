/**********************************************************************
*  Test code for hexapod bits and bobs
*  Evan Neu, Hunter Badey, Kirk Boyd, Mark Morales, and Evan Neu.
*  Board: https://learn.trossenrobotics.com/arbotix/arbotix-getting-started/38-arbotix-m-hardware-overview
*  Last edit: 03/26/2019 KB
**********************************************************************/
/**LIBRARIES**/
#include <ax12.h> //library for controlling Dynamixel AX12-A Servo
#include <math.h> //extra functions like inverse trig needed

/****I/O****/
#define soundLEDport 2 //blue LED
#define flameLEDport 3 //red LED
#define videoLEDport 4 //green LED
#define pwrLEDport 5 //yellow LED
#define runningLEDport 6 //white LED. indicates the code is running and started
#define startButtonPort 7 //green button
#define versa 16//port for versa valve solenoid
#define joyX 0//(PURP)analog A0 for joystick
#define joyY 1//(GREY)analog A1 for joystick

/****SENSORS****/
#define mic1port 17 //1st mic for start sequence
#define mic2port 18 //2nd mic for start sequence
#define flameSensor1port 3 //ANALOG; (GRN)port for flame sensor 1, on the left from robot's perspective
#define flameSensor2port 2 //ANALOG; (BLU)2nd flame sensor port, opposite side from above ^
#define sharp1port 7 //ANALOG; (too close>350)?sharp sensor 1 port for navigation
#define sharp2port 6 //ANALOG; (too close>350)sharp sensor 2 port for navigation
#define sharp3port 5 //ANALOG; (too close>300)straight forward facing sharp sensor 3 port for navigation
#define sharp4port 1 //ANALOG; 
#define uvTronPort 4 //ANALOG; (YLW)port for Hammamatsu UVtron sensor
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
#define fDown 680 //femur down to support weight servo value
#define fUp 600  //femur up to move coxa, servo value

/**CHECKS**/
boolean started = false; //boolean for keeping an LED on while code is running
boolean flameSeen = false; //boolean for checking if hammamatsu has seen a the room with the flame in it
boolean babySeen = false;  //boolean for checking if baby was detected with vision
boolean uvTronDone = false; //boolean for indicating completed use of uvTron
boolean aimed = false; //this should be true when the nozzle is aimed on center with the candle
boolean didThatOneTurn = false;
/**TRIG**/
float alpha = 0;  //RADIANS; angle of deflection from center of circle to default leg position to new angle
float r = 30.31;  //(in mm) length of coxa from outer circle of base to outside of motor clip
float D = 72; //(in mm) radius of the base from center to outermost circle 
float delta; //RADIANS; angle opposite length D in triangle
float B; //(in mm)third leg of triangle. changes in length as angle phi increases (or beta decreases)
float beta; //RADIANS; third angle in trangle, opposite length B, decreases as phi increases (supplementary angles)
float phi;
int dynum;
#define numSteps 1023 //max value to set AX-12A servos could possibly reach
#define centered 512  //centered position of AX-12A
#define dynaMax 804 //maximum allowed position of AX-12A for current Hexapod
#define dynaMin 292 //minimum allowed position of AX-12A for current Hexapod

/**GAIT CONTROL**/
#define tim 150 //this is the time delay (ms) between servo moves. we want it as low as possible so it moves the fastest
#define timLg 250 //large value of above
#define turnTim 100
#define stepSm 3//DEGREES; smaller value of below for turning
#define stepSize 5//DEGREES; sets the alpha value for how much to step

/**MAIN**/
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
  pinMode(flameSensor1port,INPUT);
  pinMode(flameSensor2port,INPUT);
  pinMode(uvTronPort,INPUT);
  pinMode(mic1port,INPUT);
  pinMode(mic2port,INPUT);
  stand(3000);
      //  while(!soundSystem()){}
      
  /*TEST ONE TIME AT INIT*/
}
boolean startButton(){ // returns true when green start button is depressed
  if(digitalRead(startButtonPort) == LOW){ 
    started = true;
    return true;
  }
  else{return false;}
}
void joystick(){//control the hexapod via joystick
  if(analogRead(joyX) >= 1022){
      fwd();
  }
  if(analogRead(joyX) <= 1){
      back();
  }
  if(analogRead(joyY) >= 1022){
      turnSlowR();
  }
  if(analogRead(joyY) <= 0){
      turnSlowL();
  }
}
void navigate(){//use the sharp sensors to search the maze by avoiding walls 
  if(analogRead(sharp3port)> 270){turn90R();}//if something is too close in front, turn right
  else if(analogRead(sharp1port)> 300){turnSlowR();}
  else if(analogRead(sharp2port)> 300){turnSlowL();}
  else if(analogRead(sharp4port)<110){//if there is nothing close on left, turn towards opening
   digitalWrite(videoLEDport, HIGH);
   fwd();
   fwd();
   fwd();
   fwd();
   fwd();
   turn90L();
   fwd();
   fwd();
   fwd();
   fwd();
   fwd();
   fwd();
   fwd();
   fwd();
   fwd();
   digitalWrite(videoLEDport, LOW);
  }
  else if(analogRead(sharp4port)>110 &&analogRead(sharp4port)<155 && !didThatOneTurn){
    digitalWrite(soundLEDport, HIGH);
    digitalWrite(flameLEDport, HIGH);
    digitalWrite(runningLEDport, HIGH);
    fwd();
    fwd();
    fwd();
    fwd();
    fwd();
    fwd();
    turn90L();
    fwd();
    fwd();
    fwd();
    fwd();
    fwd();
    fwd();
    fwd();
    fwd();
    fwd();
    fwd();
    fwd();
    fwd();
    fwd();
    turn90L();
    fwd();
    fwd();
    fwd();
    fwd();
    fwd();
    fwd();
    fwd();
    fwd();
    fwd();
    digitalWrite(soundLEDport, LOW);
    didThatOneTurn = true;
  }
  else{fwd();}//if none of the sensors read too close, go straight fwd
}
void loop(){
  Serial.println(analogReadPort)); //for testing
  if(startButton()){//initiates code within loop at button press
    delay(500);//wait a half second to release the button
    while(!startButton()){//continues to execute this code until the button is pressed again
      /** PUT MAIN CODE HERE**/
      navigate();
      //joystick();
     // turnSlowR();
    }
    while(startButton()){}//wait with the button down until it goes back up
    delay(1000);//if button was pressed again wait to release it so the loop exits
  }
}
