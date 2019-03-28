void closedGoTo(int motor,int ang){//WIP WIP try to just write a system where the motors move on a closed loop
  while(GetPosition(motor) != fullTrig(ang)){
    SetPosition(1,fullTrig(3));
  }
}

void fwd(){
  oddsUp();
  delay(tim);
  oddsFwd();
  evensBack();
  delay(tim);
  oddsDown();
  delay(tim);
  evensUp();
  delay(tim);
  evensFwd();
  oddsBack();
  delay(tim);
  evensDown();
  delay(tim);
}


void evensFwd(){
  SetPosition(CMR,fullTrig(-5));
  SetPosition(CRL,fullTrig(5));
  SetPosition(CFL,fullTrig(5));
}
void evensBack(){
  SetPosition(CMR,fullTrig(5));
  SetPosition(CRL,fullTrig(-5));
  SetPosition(CFL,fullTrig(-5));
}
void oddsFwd(){
  SetPosition(CML,fullTrig(5));
  SetPosition(CRR,fullTrig(-5));
  SetPosition(CFR,fullTrig(-5));
}
void oddsBack(){
  SetPosition(CML,fullTrig(-5));
  SetPosition(CRR,fullTrig(5));
  SetPosition(CFR,fullTrig(5));
}
void evensUp(){//puts even numbered femurs up
  //while(GetPosition(FFL) != fUp){
    SetPosition(FMR,fUp);
    SetPosition(FRL,fUp);
    SetPosition(FFL,fUp);
  //}
}
void oddsUp(){//puts even numbered femurs up
  //while(GetPosition(FFR) != fUp){
    SetPosition(FML,fUp);
    SetPosition(FRR,fUp);
    SetPosition(FFR,fUp);
  //}
}
void evensDown(){//puts even numbered femurs up
  //while(GetPosition(FFL) != fDown){
    SetPosition(FMR,fDown);
    SetPosition(FRL,fDown);
    SetPosition(FFL,fDown);
  //}
}
void oddsDown(){//puts even numbered femurs up
  //while(GetPosition(FFR) != fDown){
    SetPosition(FML,fDown);
    SetPosition(FRR,fDown);
    SetPosition(FFR,fDown);
  //}
}
void turnFastR(){// make big steps in place in circle to turn RIGHT
  
}
void turnFastL(){//make big steps in place in circle to turn LEFT
  
}
void turnSlowR(){//make small steps in place in circle to turn RIGHT
  
}
void turnSlowL(){//make small steps in place in circle to turn LEFT
  
}



/*OLD
void axGo(int id, int pos)    //sets motor at given ID to given position then stalls until it gets there
  {
  while(GetPosition(id) != pos){};
}
void triadGo(int a, int posA, int b, int posB, int c, int posC)  //same as axGo, but takes three motor ID's and Positions at a time and stalls after all three are called
{  
  SetPosition(a,posA);
  SetPosition(b,posB);
  SetPosition(c,posC);
  while(GetPosition(a) != posA){};
  while(GetPosition(b) != posB){};
  while(GetPosition(c) != posC){};
}
void triadGo(int a, int posA, int b, int posB, int c, int posC, int d, int posD, int e, int posE, int f, int posF)//axGo for 6 motors
{
  SetPosition(a,posA);
  SetPosition(b,posB);
  SetPosition(c,posC);
  SetPosition(d,posD);
  SetPosition(e,posE);
  SetPosition(f,posF);
  while(GetPosition(a) != posA){};
  while(GetPosition(b) != posB){};
  while(GetPosition(c) != posC){};
  while(GetPosition(d) != posD){};
  while(GetPosition(e) != posE){};
  while(GetPosition(f) != posF){};
}
*/
