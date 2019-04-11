boolean fwdLast;
boolean backLast;
boolean turnRlast;
boolean turnLlast;
boolean diagRfwdLast;
boolean diagLfwdLast;
const int homTim = 50;
void resetAngChecks(){
  fwdLast = false;
  backLast = false;
  turnRlast = false;
  turnLlast = false;
  diagRfwdLast = false;
  diagLfwdLast = false;
}
void closedGoTo(int motor,int ang){//WIP WIP try to just write a system where the motors move on a closed loop
  while(GetPosition(motor) != fullTrig(ang)){
    SetPosition(1,fullTrig(3));
  }
}
void backHome(){//picks up feet and moves back home
  oddsUp();
  delay(homTim);
  oddsCenter();
  delay(homTim);
  oddsDown();
  delay(homTim);
  evensUp();
  delay(homTim);
  evensCenter();
  delay(homTim);
  evensDown();
  delay(homTim);
  resetAngChecks();
}
void fwd(){
  if(!fwdLast){backHome();}
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
  fwdLast = true;
}
void back(){
  if(!backLast){backHome();}
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
  backLast = true;
}
void turnR(){//make small steps in place in circle to turn RIGHT
  if(!turnRlast){backHome();}
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
  turnRlast = true;
}
void turnL(){//make small steps in place in circle to turn LEFT
  if(!turnLlast){backHome();}
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
  turnLlast = true;
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
void diagRfwd(){
  if(!diagRfwdLast){backHome();}
  evensCenter();
  oddsCenter();
  delay(timSm);
  SetPosition(FFL,fUp);
  SetPosition(FML,fUp);
  SetPosition(FMR,fUp);
  SetPosition(FRR,fUp);
  delay(timSm);
  SetPosition(CFL,fullTrig(stepSize));
  SetPosition(CML,fullTrig(stepSize));
  SetPosition(CMR,fullTrig(-stepSize));
  SetPosition(CRR,fullTrig(-stepSize));
  //delay(timSm);
  SetPosition(FFL,fDown);
  SetPosition(FML,fDown);
  SetPosition(FMR,fDown);
  SetPosition(FRR,fDown);
  delay(timSm);
  SetPosition(FFR,fUp);
  SetPosition(FRL,fUp);
  delay(timSm);
  SetPosition(CFL,fullTrig(-stepSize));
  SetPosition(CML,fullTrig(-stepSize));
  SetPosition(CMR,fullTrig(stepSize));
  SetPosition(CRR,fullTrig(stepSize));
  delay(timSm);
  SetPosition(FFR,fDown);
  SetPosition(FRL,fDown);
  delay(timSm);
  diagRfwdLast = true;
}
void diagLfwd(){
  if(!diagLfwdLast){backHome();}
  evensCenter();
  oddsCenter();
  delay(timSm);
  SetPosition(FFR,fUp);
  SetPosition(FML,fUp);
  SetPosition(FMR,fUp);
  SetPosition(FRL,fUp);
  delay(timSm);
  SetPosition(CFR,fullTrig(-stepSize));
  SetPosition(CML,fullTrig(stepSize));
  SetPosition(CMR,fullTrig(-stepSize));
  SetPosition(CRL,fullTrig(stepSize));
  SetPosition(FFR,fDown);
  SetPosition(FML,fDown);
  SetPosition(FMR,fDown);
  SetPosition(FRL,fDown);
  delay(timSm);
  SetPosition(FFL,fUp);
  SetPosition(FRR,fUp);
  delay(timSm);
  SetPosition(CFR,fullTrig(stepSize));
  SetPosition(CML,fullTrig(-stepSize));
  SetPosition(CMR,fullTrig(stepSize));
  SetPosition(CRL,fullTrig(-stepSize));
  delay(timSm);
  SetPosition(FFL,fDown);
  SetPosition(FRR,fDown);
  delay(timSm);
  diagRfwdLast = true;
}
/********************GROUPED POSITIONS********/
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
void evensCenter(){//HOMES ALL EVEN COXA
  SetPosition(CMR,fullTrig(0));
  SetPosition(CRL,fullTrig(0));
  SetPosition(CFL,fullTrig(0));
}
void oddsCenter(){//HOMES ALL ODD COXA
  SetPosition(CML,fullTrig(0));
  SetPosition(CRR,fullTrig(0));
  SetPosition(CFR,fullTrig(0));
}
void evensSame(){//moves even coxa clockwise (from above)
  SetPosition(CMR,fullTrig(stepSize));
  SetPosition(CRL,fullTrig(stepSize));
  SetPosition(CFL,fullTrig(stepSize));
}
void evensSameRev(){//moves even coxa anticlockwise
  SetPosition(CMR,fullTrig(-stepSize));
  SetPosition(CRL,fullTrig(-stepSize));
  SetPosition(CFL,fullTrig(-stepSize));
}
void oddsSame(){//moves odd coxa clockwise
  SetPosition(CML,fullTrig(stepSize));
  SetPosition(CRR,fullTrig(stepSize));
  SetPosition(CFR,fullTrig(stepSize));
}
void oddsSameRev(){//moves odd coxa anticlockwise
  SetPosition(CML,fullTrig(-stepSize));
  SetPosition(CRR,fullTrig(-stepSize));
  SetPosition(CFR,fullTrig(-stepSize));
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
  evensSame();//
  delay(timSm);
  evensDown();//femurs down
  delay(timSm);
  oddsUp();
  evensCenter();//with contact, move to pull itself 
  oddsSame();
  delay(timSm);
  oddsDown();
  delay(timSm);
  oddsCenter();
}
void turnSmL(){//make smaller steps in place in circle to turn LEFT
  oddsUp();//femurs up
  oddsSameRev();//
  delay(timSm);
  oddsDown();//femurs down
  delay(timSm);
  evensUp();
  oddsCenter();//with contact, move to pull itself 
  evensSameRev();
  delay(timSm);
  evensDown();
  delay(timSm);
  evensCenter();
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
  SetPosition(7,300);
  SetPosition(8,300);
  SetPosition(9,300);
  SetPosition(10,300);
  SetPosition(11,300);
  SetPosition(12,300);
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
void standRand(int t){
  SetPosition(1,400);
  SetPosition(2,700);
  SetPosition(3,400);
  SetPosition(4,400);
  SetPosition(5,700);
  SetPosition(6,700);
  SetPosition(7,680);
  SetPosition(8,680);
  SetPosition(9,680);
  SetPosition(10,680);
  SetPosition(11,680);
  SetPosition(12,680);
  delay(t);
}
