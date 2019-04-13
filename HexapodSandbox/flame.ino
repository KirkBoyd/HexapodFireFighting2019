#define f1Min 200 //closest a small IR phototransistor can be for consistent reading
#define f1Max 500  //furthest a small IR phototransistor should be to extinguish the flame
#define f2Min 200 //closest a small IR phototransistor can be for consistent reading
#define f2Max 500  //furthest a small IR phototransistor should be to extinguish the flame
#define f3Min 800//closest a small IR phototransistor can be for consistent reading
#define f3Max 1005   //furthest a small IR phototransistor should be to extinguish the flame
/** NOTE ^^^ for above values, high == far away. low == very close. **/
#define del 50
#define versaPulseTimHi  1500//how long the delay should be for versa to pulse properly
#define versaPulseTimLo  2000//how long the delay should be for versa to pulse properly
int f3Then;
int f3Now;
int f3CheckR;
int f3CheckL;
/*
 * Logic for checking for the flame with the Hammamatsu uvTron
 */
void fireCheck(){
  if(f3() <= f3Max&&!flameSeen){//if the flame has not been detected yet, and the readings show that a flame is now present, store the fact that a flame has been seen.
    flameSeen = true;
    flameLED(true);
  }
}
void firstFlameCheck(){
  
  fireCheck();
  if(flameSeen && !f3Done && f3()>=f3Min){
    secondFlameCheck();
    if(f3Then==0){f3Then = f3();}
    if(f3Now==0){
      turnSmR();
    }
    f3Now = f3();
    if(f3Then<f3Now){
      strafe330();
      f3Then = f3();
    }
    else{
      strafe60();
      f3Then = f3();
    }
    if(f3()<=f3Min){//TOO CLOSE TO FLAME?
      f3Done = true;//you're at the candle. STOP
    }
  }
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
