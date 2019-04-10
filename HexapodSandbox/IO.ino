//boolean startButton(){ // returns true when green start button is depressed
//  if(digitalRead(startButtonPort) == LOW){ 
//    started = true;
//    return true;
//  }
//  else{return false;}
//}
//boolean soundSystem(){ // returns true when blue LED sound thingy is lit
// if((digitalRead (mic1port) == HIGH)||(digitalRead (mic2port) == HIGH)){ 
//   digitalWrite(soundLED, HIGH);
//   return true;
// }
// else{
//   digitalWrite(soundLED, LOW);
//   return false;
// }
//}

/** lightCheck() checks status of the system. Turns LED's on/off accordingly **/
void lightCheck(){
  /*if(started == true){
   *  digitalWrite(runningLED,HIGH);
   *}
   *else{
   *  digitalWrite(runningLED,LOW);
   *}
   */
  if(flameSeen){
    flameLED(true);
  }
  else{
    flameLED(false);
  }
  
  if(babySeen){
    videoLED(true);
  }
  else{
    videoLED(false);
  }
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
