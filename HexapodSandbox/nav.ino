void navigate(){//use the sharp sensors to search the maze by avoiding walls 
  if(s3()>= sharp3max){//if something is too close in front, turn right
    turn90R();
  }
  else if(s1()> sharp1max){
    diagRfwd();
  }
  else if(s2()> sharp2max){
    diagLfwd();
  }
//  else if(s4()<sharp4nothingThereLo){//if there is nothing close on left, turn towards opening
//   digitalWrite(videoLEDport, HIGH);
//   fwd();
//   fwd();
//   fwd();
//   fwd();
//   fwd();
//   turn90L();
//   fwd();
//   fwd();
//   fwd();
//   fwd();
//   fwd();
//   fwd();
//   fwd();
//   fwd();
//   fwd();
//   digitalWrite(videoLEDport, LOW);
//  }
//  else if(s4()>sharp4nothingThereLo &&s4()<sharp4nothingThereHi && !didThatOneTurn){
//    digitalWrite(soundLEDport, HIGH);
//    digitalWrite(flameLEDport, HIGH);
//    digitalWrite(runningLEDport, HIGH);
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    turn90L();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    turn90L();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    fwd();
//    digitalWrite(soundLEDport, LOW);
//    didThatOneTurn = true;
//  }
  else{fwd();}//if none of the sensors read too close, go straight fwd
}
void joystick(){//control the hexapod via joystick
  Serial.print("x = ");
  Serial.println(joyX);
  Serial.print("y = ");
  Serial.println(joyY);
  if(analogRead(joyX) >= 1022){
      fwdSm();
  }
  if(analogRead(joyX) <= 1){
      back();
  }
  if(analogRead(joyY) >= 1022){
    //turnR();  
    turnSmR();
  }
  if(analogRead(joyY) <= 0){
    //turnL();
    turnSmL();
  }
}
