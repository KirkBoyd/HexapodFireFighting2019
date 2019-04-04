#define flameMin 1023 //furthest a small IR phototransistor can be for consistent reading
#define flameMax 0  //closest a small IR phototransistor should be to extinguish the flame
/** NOTE ^^^ for above values, high == far away. low == very close. **/

#define uvTronMin 0 //smallest value that we can say uvtron has seen the flame
#define uvTronMax 1023  //oversaturated value for uvTron

int f1Read(){ //shortening the call to read one flame sensor
  return analogRead(flame1port);
}
int f2Read(){ //shortening the call to read one flame sensor
  return analogRead(flame2port);
}

/*
 * Logic for checking for the flame with the Hammamatsu uvTron
 */
boolean firstFlameCheck(){
  if(analogRead(uvTronPort) >= uvTronMin && !flameSeen){//if the flame has not been detected yet, and the readings show that a flame is now present, store the fact that a flame has been seen.
    flameSeen = true;
  }
  if(analogRead(uvTronPort) <= uvTronMax){//if the flame is oversaturating the uvTron, we can stop using it and aim with the IR phototransistors
    uvTronDone = true;
  }
  if(flameSeen && analogRead(uvTronPort)>= uvTronMin && !uvTronDone){ //if flame was spotted, but still too far for phototransistors, return true
    return true;
  }
  else{return false;}
}

/*
 * Logic for aiming at the flame using IR phototransistors
 */
boolean secondFlameCheck(){
  if(f1Read()<flameMin){//if the sensors are reading too low, do something [TBD]
    
  }
  if(f1Read() == f2Read()){ 
    aimed = true;
    return true;
  }
  else if(f1Read() > f2Read()){//reading is higher on the LEFT turn LEFT
    turnL();
    return false;
  }
  else{//correct to the RIGHT if previous statement was not triggered
    turnR();
    return false;
  }
 }

