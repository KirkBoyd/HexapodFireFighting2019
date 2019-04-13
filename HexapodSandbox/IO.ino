boolean soundStart(){ // returns true when blue LED sound thingy is lit
 if(mic1()==0||mic2()==0){ 
   soundLED(true);
   delay(300);
   return true;
 }
 else{
   soundLED(false);
   return false;
 }
}
boolean startButton(){ // returns true when green start button is depressed
  if(digitalRead(startButtonPort) == LOW){ 
    started = true;
    return true;
  }
  else{return false;}
}
void lightCheck(){//unused. checks some LEDs
  if(flameSeen){flameLED(true);}
  else{flameLED(false);}
  if(babySeen){videoLED(true);}
  else{videoLED(false);}
}
void buzz(){
  digitalWrite(buzzer,LOW);
  delay(250);
  digitalWrite(buzzer,HIGH);
}
void printSharps(){
  int v1 = s1();
  int v2 = s2();
  int v3 = s3();
  int v4 = s4();
  Serial.print("s1: ");
  Serial.print(v1);
  Serial.print(" | s2: ");
  Serial.print(v2);
  Serial.print(" | s3: ");
  Serial.print(v3);
  Serial.print(" | s4: ");
  Serial.println(v4);
}
void printFlames(){
  int z1 = f1();
  int z2 = f2();
  int z3 = f3();
  Serial.print("f1: ");
  Serial.print(z1);
  Serial.print(" | f2: ");
  Serial.print(z2);
  Serial.print(" | f3: ");
  Serial.println(z3);
}
void printMics(){
  Serial.print("mic1: ");
  Serial.print(mic1());
  Serial.print(" | mic2: ");
  Serial.println(mic2());
}
/***********************SENSORS**********************************/
//shorter call for sharp readings
int s1(){return analogRead(sharp1port);}
int s2(){return analogRead(sharp2port);}
int s3(){return analogRead(sharp3port);}
int s4(){return analogRead(sharp4port);}
//shortening the call to read flame sensors
int f1(){return analogRead(flame1port);}
int f2(){return analogRead(flame2port);}
int f3(){return analogRead(flame3port);}
//shorten other sensor calls
int mic1(){return digitalRead(mic1port);}
int mic2(){return digitalRead(mic2port);}

boolean str(){//returns true when stripe sensor sees a line (white)
  if(digitalRead(stripePort)==0){return true;}
  else{return false;}
}
/*************************LED************************************/
void soundLED(boolean state){ // turns on blue LED when passed 'true'
  if (state){digitalWrite (soundLEDport, HIGH);}
  else{digitalWrite (soundLEDport, LOW);}
}
void flameLED(boolean state){ // turns on red LED when passed 'true'
  if (state){digitalWrite (flameLEDport, HIGH);}
  else{digitalWrite (flameLEDport, LOW);}
}
void videoLED(boolean state){ // turns on green LED when passed 'true'
  if (state){digitalWrite (videoLEDport, HIGH);}
  else{digitalWrite (videoLEDport, LOW);}
}
void runningLED(boolean state){ // turns on white LED when passed 'true'
  if (state){digitalWrite(runningLEDport, HIGH);}
  else{digitalWrite(runningLEDport, LOW);}
}
void pwrLED(boolean state){ // turns on yellow LED when passed 'true'
  if(state){digitalWrite(pwrLEDport,HIGH);}
  else{digitalWrite(pwrLEDport,LOW);}
}
void blinkLED(int LEDid){ //makes LED blink. LED stays on when finished
  digitalWrite(LEDid, HIGH);
  delay(50);
  digitalWrite(LEDid, LOW);
  delay(50);
  digitalWrite(LEDid, HIGH);
  delay(50);
  digitalWrite(LEDid, LOW);
  delay(50);
  digitalWrite(LEDid, HIGH);
  delay(50);
  digitalWrite(LEDid, LOW);
  delay(50);
  digitalWrite(LEDid, HIGH);
  delay(50);
}
