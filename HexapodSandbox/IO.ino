boolean startButton(){ // returns true when green start button is depressed
  if(digitalRead (startButtonPort) == LOW){ 
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
void lightCheck(){//checks status of the system. Turns LED's on/off accordingly
  if(started){digitalWrite(runningLED,HIGH);}
  else{digitalWrite(runningLED,LOW);}
  
  if(flameSeen){{digitalWrite(flameLED,HIGH);}
  else{digitalWrite(flameLED,LOW);}
  
  if(babySeen){{digitalWrite(videoLEDport,HIGH);}
  else{digitalWrite(videoLEDport,LOW);}
}

