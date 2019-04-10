#define f1Min 200 //closest a small IR phototransistor can be for consistent reading
#define f1Max 500  //furthest a small IR phototransistor should be to extinguish the flame
#define f2Min 200 //closest a small IR phototransistor can be for consistent reading
#define f2Max 500  //furthest a small IR phototransistor should be to extinguish the flame
#define f3Min 875//closest a small IR phototransistor can be for consistent reading
#define f3Max 1015   //furthest a small IR phototransistor should be to extinguish the flame
/** NOTE ^^^ for above values, high == far away. low == very close. **/
#define del 50
#define versaPulseTimHi  1500//how long the delay should be for versa to pulse properly
#define versaPulseTimLo  2000//how long the delay should be for versa to pulse properly
#define uvTronMin 1010 //smallest value that we can say uvtron has seen the flame
#define uvTronMax 0  //oversaturated value for uvTron

int f3CheckR;
int f3CheckL;

int f1Read(){ //shortening the call to read one flame sensor
  return analogRead(flame1port);//returns int analog value from flame sensor 2
}
int f2Read(){ //shortening the call to read one flame sensor
  return analogRead(flame2port); //returns int analog value from flame sensor 2
}
int f3Read(){ //shortening the call to read one flame sensor
  return analogRead(flame3port); //returns int analog value from flame sensor 2
}

/*
 * Logic for checking for the flame with the Hammamatsu uvTron
 */
void firstFlameCheck(){
  if(f3Read() <= f3Max && !flameSeen){//if the flame has not been detected yet, and the readings show that a flame is now present, store the fact that a flame has been seen.
    flameSeen = true;
    blinkLED(soundLEDport);
    flameLED(true);
  }
  if(flameSeen && !f3Done){
    turnSmR();
    delay(50);
    f3CheckR = f3Read();
    turnSmR();
    delay(50);
    f3CheckL = f3Read();
    if(f3CheckL > f3Max && f3CheckR > f3Max){//TOO FAR? if neither side is showing flame values less than a detected flame, turn 90deg and check again
      turn90R();
    }
    else if(f3Read()<f3Min){//TOO CLOSE TO FLAME?
      f3Done = true;
    }
    else if(f3CheckR < f3CheckL){//CLOSER ON RIGHT?
      turnSmR();
      fwd();
      fwd();
    }
    else if(f3CheckL < f3CheckR){//CLOSER ON LEFT?
      turnSmL();
      fwd();
      fwd();
    }
    else{//if somehow left and right read the same and it wasn't too far, go fwd i guess
      fwd();
    }
  }
  if(f3Read() <= f3Min){//if the flame is oversaturating the sensor, we can stop using it and aim with the IR phototransistors
    uvTronDone = true;
  }
  if(flameSeen && analogRead(uvTronPort)>= uvTronMin && !uvTronDone){ //if flame was spotted, but still too far for phototransistors, return true
    fwdSm();
  }
  Serial.println(analogRead(uvTronPort));
  Serial.print("flameSeen : ");
  Serial.println(flameSeen);
}

/*
 * Logic for aiming at the flame using IR phototransistors
 */
void secondFlameCheck(){
  Serial.print("f1 : ");
  Serial.print(f1Read());
  Serial.print("     f2 : ");
  Serial.println(f2Read());
  if(f1Read() > f2Read()){//reading is higher on the LEFT turn LEFT //////analogRead(sharp2port)>sharp2max
    turnSmL();
  }
  else if(f1Read() < f2Read()){//reading is higher on the RIGHT turn RIGHT/////// || analogRead(sharp1port)>sharp1max
    turnSmR();
  }
  else if(f1Read()<flameMin && f2Read()<flameMin){//if the sensors are reading too low, do something [TBD]
    fwdSm();
  }
  else if((f1Read() <= f2Read()+del)&&(f1Read() >= f2Read()-del)){//if f1 and f2 are within a tolerance of 50 integers apart
    if(f1Read() <= flameMax && f2Read() <= flameMax){// if they are both below our chosen saturation value as close enough
      aimed = true;
      blinkLED(soundLEDport);
    }
  }
  else{
    back();
  }  
}
void versaFire(){
  digitalWrite(versa, HIGH);
  delay(versaPulseTimHi);
  digitalWrite(versa, LOW);
  delay(versaPulseTimLo);
  digitalWrite(versa, HIGH);
  delay(versaPulseTimHi);
  digitalWrite(versa, LOW);
  delay(versaPulseTimLo);
  digitalWrite(versa, HIGH);
  delay(versaPulseTimHi);
  digitalWrite(versa, LOW);
  delay(versaPulseTimLo);
}

void uvTronCheck(){
  
}
