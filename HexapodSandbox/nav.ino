/****VISION****/
      /**not in use**/
#define sharp1max 230//updated 04/11/19 9pm
#define sharp1a  285//(plusminus 7) closest it can be to the wall (on it's left)while parallel
#define sharp1b 632//(plusminus 10) closest it could ever be to the wall, sharp 1 right in front
#define sharp1c 230//(delta )almost too close to the wall on the left
#define sharp1d 100//(delta )almost too far from the wall on the left
#define sharp1e 155//good distance from wall on left
#define sharp1delta 9//average variance of sharp 1
#define sharp2max 260//updated 04/11/19 9pm
#define sharp2a 360//(plusminus 7)closest it can be to the wall(on it's right) while parallel
#define sharp2b 637//(plusminus 10)closest it could ever be to the wall, sharp 1 right in front
#define sharp2c 232//(delta )almost too close to the wall on the right
#define sharp2d 145//(delta )almost too far from the wall on the right (parallel
#define sharp2e 189//good distance from wall on right
#define sharp2delta 17//average variance of sharp 2
#define sharp4nothingThereLo 110
#define sharp4nothingThereHi 155

    /**in use**/
    #define sharp3max 350//updated 04/11/19 1233
    #define sharp4min 120//open space on the left
    #define sharp4b 300//farthest from wall we want to be (increased 1220)
    #define sharp4max 425//
    
int val1;
int val2;
int val3;
int val4;
boolean turned;

void avoid(){//dodges walls if something else is going on
  if(s4()>sharp4max){turnR();}
  if(s1()>sharp1c){turnR();}
}
void navigate(){//use the sharp sensors to search the maze by avoiding walls
  val1 = s1();
  val2 = s2();
  val3 = s3();
  val4 = s4();
  flameCheck();
  //roomCheck();
  /**left wall follow**/
  if(val4>=sharp4max){
    turnR();
    turned = true;
  }//too close to left wall
  
  else if(val4<=sharp4b && val1<=sharp1e){
    turnL();
    fwd();
    fwd();
    turned = false;
  }//too far from left wall
  
  /**check in front**/
  if(val3>= sharp3max){//if something is too close in front, check sides
    /**seek open space to the left.**/
    if(val4<=sharp4min){
      turn90L();
      turned = true;
    }//something in front, nothing on left
    /**no space, go right**/
    else{
      turn90R();
      turned = true;
    }//something in front, something on left
  }
  /**if this doesn't work add forward as an else if(){}**/
  printSharps();
  /**now you can walk**/
  if(!turned){//if these one of the cases above were met, it should loop again before it goes forward
    fwd();
  }
  turned = false;
}
void leftWallEnd(){
  soundLED(true);
  while(val4>300&&val1<120){//while s1 sees open space, but s4 still sees a wall
      val1 = s1();
      val4 = s4();
      if(s1()>=sharp1c){turnR();}
      else if(s4()>=500){turnR();}
      else{fwd();}
  }
  if(val1<120&&val4<300){
      turn90L();
      fwd();
      fwd();
      turn90L();
  }
  while(s4()<290){
      fwd();
  }
  soundLED(false);
}
boolean inRoom(){
  if(str()){
    strCount++;
    return true;
  }
  else{return false;}
}
void roomCheck(){
  Serial.print("strCount: ");
  Serial.print(strCount);
  Serial.print("inRoom: ");
  Serial.println(inRoom());
  if(inRoom()){
    numRooms++;
    fwd();
    fwd();
    fwd();
    fwd();
    flameCheck();
    if(!flameSeen){
      turn90R();
      flameCheck();
    }
    if(!flameSeen){
      turn90L();
      flameCheck();
    }
    if(!flameSeen){
      turn90R();
      flameCheck();
        if(!flameSeen){
          turn90R();
          fwd();
          fwd();
          fwd();
          fwd();
          fwd();
          fwd();
          fwd();
          fwd();
          fwd();
          turnL();
          turnL();
          fwd();
          fwd();
          fwd();
          fwd();
          fwd();
          fwd();
        }//end if(!flameSeen)
        if(numRooms>5){numRooms = 0;}
    }//end if(!flameSeen)
  }
}
void joystick(){//control the hexapod via joystick
  Serial.print("x = ");
  Serial.println(joyX);
  Serial.print("y = ");
  Serial.println(joyY);
  if(analogRead(joyX) >= 1022){fwdSm();}
  if(analogRead(joyX) <= 1){ back();}
  if(analogRead(joyY) >= 1022){turnSmR();}
  if(analogRead(joyY) <= 0){turnSmL();}
}
