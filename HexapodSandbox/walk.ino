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
  oddsDown();
  delay(tim);  //short as possible so feet are on the ground at all times
  evensUp();
  delay(tim);  //needed
  evensFwd();
  oddsBack();
  evensDown();
  delay(tim);  //short as possible so feet are on the ground at all times
}
void back(){
  oddsUp();
  delay(tim); //needed
  oddsBack();
  evensFwd();
  oddsDown();
  delay(tim);  //short as possible so feet are on the ground at all times
  evensUp();
  delay(tim);  //needed
  evensBack();
  oddsFwd();
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
void turnR(){//make small steps in place in circle to turn RIGHT
  evensUp();//femurs up
  evensSame();//
  delay(turnTim);
  evensDown();//femurs down
  delay(turnTim);
  oddsUp();
  evensSameRev();//with contact, move to pull itself 
  oddsSame();
  delay(turnTim);
  oddsDown();
  delay(turnTim);
  oddsSameRev();
}
void turnL(){//make small steps in place in circle to turn LEFT
  evensUp();//femurs up
  evensSameRev();//
  delay(turnTim);
  evensDown();//femurs down
  delay(turnTim);
  oddsUp();
  evensSame();//with contact, move to pull itself 
  oddsSameRev();
  delay(turnTim);
  oddsDown();
  delay(turnTim);
  oddsSame();
}
void turn90R(){//turns ~90 degrees to the right ON COMPETITION FLOOR SURFACE
  turnR();
  turnR();
  turnR();
  turnR();
  turnR();
  stand(50);
}
void turn90L(){//turns ~90 degrees to the right ON COMPETITION FLOOR SURFACE
  turnL();
  turnL();
  turnL();
  turnL();
  turnL();
  stand(50);
}
/******************EXP******SMALLER MOVES***************/
void fwdSm(){
  oddsUp();
  delay(tim); //needed
  oddsFwdSm();
  evensBackSm();
  oddsDown();
  delay(tim);  //short as possible so feet are on the ground at all times
  evensUp();
  delay(tim);  //needed
  evensFwdSm();
  oddsBackSm();
  evensDown();
  delay(tim);  //short as possible so feet are on the ground at all times
}
void turnSmR(){//make smaller steps in place in circle to turn RIGHT
  evensUp();//femurs up
  evensSameSm();//
  delay(tim);
  evensDown();//femurs down
  delay(tim);
  oddsUp();
  evensSameRev();//with contact, move to pull itself 
  oddsSameSm();
  delay(tim);
  oddsDown();
  delay(tim);
  oddsSameRevSm();
}
void turnSmL(){//make smaller steps in place in circle to turn LEFT
  evensUp();//femurs up
  evensSameRevSm();//
  delay(tim);
  evensDown();//femurs down
  delay(tim);
  oddsUp();
  evensSameSm();//with contact, move to pull itself 
  oddsSameRevSm();
  delay(tim);
  oddsDown();
  delay(tim);
  oddsSameSm();
}

void evensSameSm(){
  SetPosition(CMR,fullTrig(stepSm));
  SetPosition(CRL,fullTrig(stepSm));
  SetPosition(CFL,fullTrig(stepSm));
}
void evensSameRevSm(){
  SetPosition(CMR,fullTrig(-stepSm));
  SetPosition(CRL,fullTrig(-stepSm));
  SetPosition(CFL,fullTrig(-stepSm));
}
void oddsSameSm(){
  SetPosition(CML,fullTrig(stepSm));
  SetPosition(CRR,fullTrig(stepSm));
  SetPosition(CFR,fullTrig(stepSm));
}
void oddsSameRevSm(){
  SetPosition(CML,fullTrig(-stepSm));
  SetPosition(CRR,fullTrig(-stepSm));
  SetPosition(CFR,fullTrig(-stepSm));
}
void oddsFwdSm(){
  SetPosition(CML,fullTrig(stepSm));
  SetPosition(CRR,fullTrig(-stepSm));
  SetPosition(CFR,fullTrig(-stepSm));
}
void oddsBackSm(){
  SetPosition(CML,fullTrig(-stepSm));
  SetPosition(CRR,fullTrig(stepSm));
  SetPosition(CFR,fullTrig(stepSm));
}
void evensFwdSm(){
  SetPosition(CMR,fullTrig(-stepSm));
  SetPosition(CRL,fullTrig(stepSm));
  SetPosition(CFL,fullTrig(stepSm));
}
void evensBackSm(){
  SetPosition(CMR,fullTrig(stepSm));
  SetPosition(CRL,fullTrig(-stepSm));
  SetPosition(CFL,fullTrig(-stepSm));
}
/******************POSES(OLD)****************/
void stand(int t){
  SetPosition(1,512);
  SetPosition(2,512);
  SetPosition(3,512);
  SetPosition(4,512);
  SetPosition(5,512);
  SetPosition(6,512);
  SetPosition(7,680);
  SetPosition(8,680);
  SetPosition(9,680);
  SetPosition(10,680);
  SetPosition(11,680);
  SetPosition(12,680);
  delay(t);
}

void fetal(int t){
  SetPosition(1,512);
  SetPosition(2,512);
  SetPosition(3,512);
  SetPosition(4,512);
  SetPosition(5,512);
  SetPosition(6,512);
  SetPosition(7,200);
  SetPosition(8,200);
  SetPosition(9,200);
  SetPosition(10,200);
  SetPosition(11,200);
  SetPosition(12,200);
  delay(t);
}
void walkStance(int t){
  SetPosition(1,690);
  SetPosition(2,512);
  SetPosition(3,350);
  SetPosition(4,690);
  SetPosition(5,512);
  SetPosition(6,350);
  SetPosition(7,680);
  SetPosition(8,680);
  SetPosition(9,680);
  SetPosition(10,680);
  SetPosition(11,680);
  SetPosition(12,680);
  delay(t);
}
