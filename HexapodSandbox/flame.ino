/** NOTE ^^^ for above values, high == far away. low == very close. **/
#define del 50
#define versaPulseTimHi  500//how long the delay should be for versa to pulse properly
#define versaPulseTimLo  500//how long the delay should be for versa to pulse properly
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
      if(f3()<f1()&&f3()<f2()&&f3()<950){fwd();}
      else if(f3()<1000){
        if(f1()>1000&&f2()>1000){
          Serial.println("case1");
          if(f1()>f2()){turnSmR();}
          else if(f1()<f2()){turnSmL();}
        }
        else if(f3()<775){
          Serial.println("case2");
          versaFire();
          if(f1()>f2()-10){turnSmR();}
          else if(f1()<f2()+10){turnSmR();}
        }
        else if(f2()>f1() && f2()>f3()){
           Serial.println("case3");
           versaFire();
           turnSmL();
        }
        else if(f1()>f2() && f1()>f3()){
           Serial.println("case4");
           versaFire();
           turnSmR();
        }
      }    
      else{fwd();}
  }
}
void versaFire(){
  digitalWrite(versa, HIGH);
  delay(versaPulseTimHi);
  digitalWrite(versa, LOW);
  delay(versaPulseTimLo);
//  digitalWrite(versa, HIGH);
//  delay(versaPulseTimHi);
//  digitalWrite(versa, LOW);
//  delay(versaPulseTimLo);
}
