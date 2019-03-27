boolean startButton(){ // returns true when green start button is depressed
  if(digitalRead(startButtonPort) == LOW){ 
    started = true;
    return true;
  }
  else{return false;}
}
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

