#define flameMin 1015 //furthest a small IR phototransistor can be for consistent reading
#define flameMax 0  //closest a small IR phototransistor should be to extinguish the flame
/** NOTE ^^^ for above values, high == far away. low == very close. **/

#define uvTronMin 1010 //smallest value that we can say uvtron has seen the flame
#define uvTronMax 0  //oversaturated value for uvTron

int f1Read(){ //shortening the call to read one flame sensor
  return analogRead(flame1port);//returns int analog value from flame sensor 2
}
int f2Read(){ //shortening the call to read one flame sensor
  return analogRead(flame2port); //returns int analog value from flame sensor 2
}

/*
 * Logic for checking for the flame with the Hammamatsu uvTron
 */
void firstFlameCheck(){
  if(analogRead(uvTronPort) <= uvTronMin && !flameSeen){//if the flame has not been detected yet, and the readings show that a flame is now present, store the fact that a flame has been seen.
    flameSeen = true;
  }
  if(analogRead(uvTronPort) <= uvTronMax){//if the flame is oversaturating the uvTron, we can stop using it and aim with the IR phototransistors
    uvTronDone = true;
  }
  if(flameSeen && analogRead(uvTronPort)>= uvTronMin && !uvTronDone){ //if flame was spotted, but still too far for phototransistors, return true
    fwd();
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
  if(f1Read()<flameMin){//if the sensors are reading too low, do something [TBD]
    fwd();
  }
  if(f1Read() == f2Read() && f1Read < flameMax && f2Read < flameMax){ 
    aimed = true;
  }
  else if(f1Read() > f2Read()){//reading is higher on the LEFT turn LEFT
    turnSmL();
  }
  else if(f1Read() < f2Read()){//reading is higher on the RIGHT turn RIGHT
    turnSmR();
  }
}
void versaFire(){
  digitalWrite(versa, HIGH);
}

void uvTronCheck(){
  
}
