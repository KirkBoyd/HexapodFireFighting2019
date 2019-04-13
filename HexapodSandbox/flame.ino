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

void flameCheck(){
  if(f3() <= f3Max&&!flameSeen){//if the flame has not been detected yet, and the readings show that a flame is now present, store the fact that a flame has been seen.
    flameSeen = true;
    flameLED(true);
  }
}
void aim(){
  if(flameSeen){//found flame but not ready to fire
    if(f3()>=f3Max){//not very close to flame because the most sensitive sensor is not saturated
      if(f3()>=f3Min){turn90R();}//if the flame isn't seen anymore, turn right till its found again
      else if(f1()<f2() && f1()>f1Min && f2()>f2Min){//if f1 is farther and they both arent close enough
        turnSmR();
        fwd();
      }
      else if(f1()>f2() && f1()>f1Min && f2()>f2Min){//if f2 is farther and they both arent close enough
        turnSmL();
        fwd();
      }
      else if(f1()<f2()){//if one is saturated, take a shot then turn to try and even them out
        versaFire();
        turnSmR();
      }
      else if(f1()>f2()){//if one is saturated, take a shot then turn to try and even them out
        versaFire();
        turnSmL();
      }
      else{
        versaFire();
        fwd();
      }
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
