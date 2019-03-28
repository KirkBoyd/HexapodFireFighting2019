void closedGoTo(int motor,int ang){//WIP WIP try to just write a system where the motors move on a closed loop
  while(GetPosition(motor) != fullTrig(ang)){
    SetPosition(1,fullTrig(3));
  }
}

void fwd(){
  oddsUp();
  delay(tim); //needed
  oddsFwd();
  evensBack();
      //delay(tim); dont think we need a delay here
  oddsDown();
  delay(tim);  //short as possible so feet are on the ground at all times
  evensUp();
  delay(tim);  //needed
  evensFwd();
  oddsBack();
      //delay(tim);  dont think we need a delay here
  evensDown();
  delay(tim);  //short as possible so feet are on the ground at all times
}


void evensFwd(){
  SetPosition(CMR,fullTrig(-stepSize));
  SetPosition(CRL,fullTrig(stepSize));
  SetPosition(CFL,fullTrig(stepSize));
}
void evensBack(){
  SetPosition(CMR,fullTrig(stepSize));
  SetPosition(CRL,fullTrig(-stepSize));
  SetPosition(CFL,fullTrig(-stepSize));
}
void oddsFwd(){
  SetPosition(CML,fullTrig(stepSize));
  SetPosition(CRR,fullTrig(-stepSize));
  SetPosition(CFR,fullTrig(-stepSize));
}
void oddsBack(){
  SetPosition(CML,fullTrig(-stepSize));
  SetPosition(CRR,fullTrig(stepSize));
  SetPosition(CFR,fullTrig(stepSize));
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
void evensSame(){
  SetPosition(CMR,fullTrig(stepSize));
  SetPosition(CRL,fullTrig(stepSize));
  SetPosition(CFL,fullTrig(stepSize));
}
void evensSameRev(){
  SetPosition(CMR,fullTrig(-stepSize));
  SetPosition(CRL,fullTrig(-stepSize));
  SetPosition(CFL,fullTrig(-stepSize));
}
void oddsSame(){
  SetPosition(CML,fullTrig(stepSize));
  SetPosition(CRR,fullTrig(stepSize));
  SetPosition(CFR,fullTrig(stepSize));
}
void oddsSameRev(){
  SetPosition(CML,fullTrig(-stepSize));
  SetPosition(CRR,fullTrig(-stepSize));
  SetPosition(CFR,fullTrig(-stepSize));
}
void turnFastR(){// make big steps in place in circle to turn RIGHT
  
}
void turnFastL(){//make big steps in place in circle to turn LEFT
  
}
void turnSlowR(){//make small steps in place in circle to turn RIGHT
  evensUp();//femurs up
  //delay(tim);
  evensSame();//
  delay(tim);
  evensDown();//femurs down
  delay(tim);
  oddsUp();
  //delay(tim);
  evensSameRev();//with contact, move to pull itself 
  //delay(tim);
  oddsSame();
  delay(tim);
  oddsDown();
  delay(tim);
  oddsSameRev();
  //delay(tim);
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
