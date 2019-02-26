boolean startButton(){ // returns true when green start button is depressed
  if(digitalRead (startButtonPort) == LOW){ return true;}
  else{return false;}
}
