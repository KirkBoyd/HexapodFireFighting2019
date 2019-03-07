void soundLED(boolean state){
  if (state){digitalWrite (soundLEDport, HIGH);}
  else{digitalWrite (soundLEDport, LOW);}
}
void flameLED(boolean state){
  if (state){digitalWrite (flameLEDport, HIGH);}
  else{digitalWrite (flameLEDport, LOW);}
}
void videoLED(boolean state){
  if (state){digitalWrite (videoLEDport, HIGH);}
  else{digitalWrite (videoLEDport, LOW);}
}

