#define f1Min 200 //closest a small IR phototransistor can be for consistent reading
#define f1Max 500  //furthest a small IR phototransistor should be to extinguish the flame
#define f2Min 200 //closest a small IR phototransistor can be for consistent reading
#define f2Max 500  //furthest a small IR phototransistor should be to extinguish the flame
#define f3Min 500//closest a small IR phototransistor can be for consistent reading
#define f3Max 1015   //furthest a small IR phototransistor should be to extinguish the flame
/** NOTE ^^^ for above values, high == far away. low == very close. **/
#define del 50
#define versaPulseTimHi  1500//how long the delay should be for versa to pulse properly
#define versaPulseTimLo  2000//how long the delay should be for versa to pulse properly
//#define uvTronMin 1010 //smallest value that we can say uvtron has seen the flame
//#define uvTronMax 0  //oversaturated value for uvTron

int f3Then;
int f3Now;
int f3CheckR;
int f3CheckL;



/*
 * Logic for checking for the flame with the Hammamatsu uvTron
 */
void firstFlameCheck(){
  if(f3() <= f3Max && !flameSeen){//if the flame has not been detected yet, and the readings show that a flame is now present, store the fact that a flame has been seen.
    flameSeen = true;
    flameLED(true);
    runningLED(true);
  }
  if(flameSeen && !f3Done && f3()>=f3Min){
    if(f3Then==0){f3Then = f3();}
    if(f3Now==0){
      turnSmR();
    }
    f3Now = f3();
    if(f3Then<f3Now){
      diagLfwd();
      f3Then = f3();
    }
    else{
      diagRfwd();
      f3Then = f3();
    }
//    if(f3CheckL > f3Max && f3CheckR > f3Max){//TOO FAR? if neither side is showing flame values less than a detected flame, turn 90deg and check again
//      turn90R();
//    }
    if(f3()<=f3Min){//TOO CLOSE TO FLAME?
      f3Done = true;//you're at the candle. STOP
    }
//    else if(f3CheckR < f3CheckL){//CLOSER ON RIGHT?
//      diagLfwd();
//    }
//    else if(f3CheckL < f3CheckR){//CLOSER ON LEFT?
//      diagRfwd();
//    }
//    else{//if somehow left and right read the same and it wasn't too far, go fwd i guess
//      //this would mean somehow that both sides read the same values, but it wasn't too far from the flame
//      //because we already checked for that first
//      //fwd();
//      blinkLED(soundLEDport);
//      blinkLED(soundLEDport);//u screwed up
//      blinkLED(soundLEDport);
//      blinkLED(soundLEDport);
//      blinkLED(soundLEDport);
//    }
  }
  else{ f3Done = true;}
  //this just prints if the cable is plugged in for debugging
  Serial.println(f3());
  Serial.print("flameSeen : ");
  Serial.println(flameSeen);
}

/*
 * Logic for aiming at the flame using front two small IR phototransistors
 */
void secondFlameCheck(){
  Serial.print("f1 : ");
  Serial.print(f1());
  Serial.print("     f2 : ");
  Serial.println(f2());
  if(f1() > f2()){//reading is higher on the LEFT turn LEFT //////analogRead(sharp2port)>sharp2max
    turnSmL();
  }
  else if(f1() < f2()){//reading is higher on the RIGHT turn RIGHT/////// || analogRead(sharp1port)>sharp1max
    turnSmR();
  }
  else if((f1() <= f2()+del)&&(f1() >= f2()-del)){//if f1 and f2 are within a tolerance of 50 integers apart
    if(f1() <= f1Max && f2() <= f2Max){// if they are both below our chosen saturation value as close enough
      aimed = true;
      blinkLED(soundLEDport);
    }
    else{fwdSm();}
  }
  else{
    //if it gets here, it is probably bad news
    back();
    back();
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
