/** NOTE ^^^ for above values, high == far away. low == very close. **/
#define del 50
#define versaPulseTimHi  1500//how long the delay should be for versa to pulse properly
#define versaPulseTimLo  2000//how long the delay should be for versa to pulse properly
int f3Then;
int f3Now;
int f3CheckR;
int f3CheckL;
int q1;
int q2;
int q3;
void flameCheck(){
  if(f3() <= f3Max&&!flameSeen){//if the flame has not been detected yet, and the readings show that a flame is now present, store the fact that a flame has been seen.
    Serial.println("flame seen");
    flameSeen = true;
    flameLED(true);
  }
}
void aim(){
  Serial.println("aiming... ");
  printFlames();
  if(flameSeen){//found flame but not ready to fire
    q1 = f1();
    q2 = f2();
    q3 = f3();
      if(f3()>=f3Max){turnR();}//if the flame isn't seen anymore, turn right till its found again
      else if(f1()<f2() && f1()>f1Min && f2()>f2Min){//if f1 is farther and they both arent close enough
        turnSmR();
        fwd();
        fwd();
        fwd();
        fwd();
      }
      else if(f1()>f2() && f1()>f1Min && f2()>f2Min){//if f2 is farther and they both arent close enough
        turnSmL();
        fwd();
        fwd();
        fwd();
        fwd();
      }
      else if(f1()>f2()){//if one is saturated, take a shot then turn to try and even them out
        versaFire();
        turnL();
      }
      else if(f1()<f2()){//if one is saturated, take a shot then turn to try and even them out
        versaFire();
        turnR();
      }
      else{
        versaFire();
        fwd();
        fwd();
      }
    
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
