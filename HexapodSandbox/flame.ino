#define flameSmallMin 1023 //furthest a small IR phototransistor can be for consistent reading
#define flameSmallMax 0  //closest a small IR phototransistor should be to extinguish the flame
  /** NOTE ^^^ for above values, high == far away. low == very close. **/
#define uvtronMin 0 //smallest value that we can say uvtron has seen the flame
#define uvtronMax 1023  //chosen value for when we can stop checking with uvtron and move to IR phototransistors for aiming

bool firstFlame(){
  if(digitalRead(
}

