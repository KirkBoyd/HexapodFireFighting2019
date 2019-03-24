/*
 * All of the functions in this tab help shorten logic in other functions for the LEDs
 */
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

