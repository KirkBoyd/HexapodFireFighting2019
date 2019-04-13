/***Checks for homing between moves***/
boolean fwdLast;
boolean fwdSmLast;
boolean backLast;
boolean backSmLast;
boolean turnRlast;
boolean turnLlast;
boolean diagRfwdLast;
boolean diagLfwdLast;
boolean strafe60last;
boolean strafe330last;

const int homTim = 50;
void resetAngChecks(){
  fwdLast = false;
  backLast = false;
  turnRlast = false;
  turnLlast = false;
  diagRfwdLast = false;
  diagLfwdLast = false;
}
void backHome(){//picks up feet and moves back home
  evensUp();
  delay(homTim);
  evensCenter();
  delay(homTim);
  evensDown();
  delay(homTim);
  oddsUp();
  delay(homTim);
  oddsCenter();
  delay(homTim);
  oddsDown();
  delay(homTim);
  resetAngChecks();
}
/***FORWARD***/
void fwd(){//walk straight forward//
  //if(!fwdLast){backHome();}
  evensUp();
  delay(tim); //needed
  evensFwd();
  oddsBack();
  delay(tim);
  evensDown();
  delay(tim);  //short as possible so feet are on the ground at all times
  oddsUp();
  delay(tim);  //needed
  oddsFwd();
  evensBack();
  delay(tim);
  oddsDown();
  delay(tim);  //short as possible so feet are on the ground at all times
  fwdLast = true;
}
void fwdSm(){//moves forward in smaller increments//
  evensUp();
  delay(timSm); //needed
  evensFwdSm();
  oddsBackSm();
  delay(timSm);
  evensDown();
  delay(timSm);  //short as possible so feet are on the ground at all times
  oddsUp();
  delay(timSm);  //needed
  oddsFwdSm();
  evensBackSm();
  delay(timSm);
  oddsDown();
  delay(timSm);  //short as possible so feet are on the ground at all times
}
/***RIGHT TURNS***/
void turnR(){//make small steps in place in circle to turn RIGHT
//  if(!turnRlast){backHome();}
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
void turnSmR(){//make smaller steps in place in circle to turn RIGHT
  evensUp();//femurs up
  delay(turnTimSm);
  oddsCenter();
  delay(turnTimSm);
  evensSame();//
  delay(turnTimSm);
  evensDown();//femurs down
  delay(turnTimSm);
  oddsUp();
  delay(turnTimSm);
  evensCenter();//with contact, move to pull itself 
  delay(turnTimSm);
  oddsSame();
  delay(turnTimSm);
  oddsDown();
  delay(turnTimSm);
}
void turn90R(){//turns ~90 degrees to the right ON COMPETITION FLOOR SURFACE
  turnR();
  flameCheck();
  turnR();
  flameCheck();
  turnR();
  flameCheck();
  turnR();
  flameCheck();
  turnR();
  flameCheck();
}
/***LEFT TURNS***/
void turnL(){//make small steps in place in circle to turn LEFT
//  if(!turnLlast){backHome();}
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
void turnSmL(){//make smaller steps in place in circle to turn LEFT
  evensUp();//femurs up
  delay(turnTimSm);
  oddsCenter();
  delay(turnTimSm);
  evensSameRev();//
  delay(turnTimSm);
  evensDown();//femurs down
  delay(turnTimSm);
  oddsUp();
  delay(turnTimSm);
  evensCenter();//with contact, move to pull itself 
  delay(turnTimSm);
  oddsSameRev();
  delay(turnTimSm);
  oddsDown();
  delay(turnTimSm);
}
void turn90L(){//turns ~90 degrees to the right ON COMPETITION FLOOR SURFACE
  turnL();
  flameCheck();
  turnL();
  flameCheck();
  turnL();
  flameCheck();
  turnL();
  flameCheck();
  turnL();
  flameCheck();
}
/***STRAFE***/
void diagRfwd(){ /*****************MAKE SURE EVENS MOVE FIRST**/
  if(!diagRfwdLast){backHome();} 
  SetPosition(FFL,fUp);
  SetPosition(FML,fUp);
  SetPosition(FMR,fUp);
  SetPosition(FRR,fUp);
  delay(timStrafe);
  SetPosition(CFL,fullTrig(stepSize));
  SetPosition(CML,fullTrig(stepSize));
  SetPosition(CMR,fullTrig(-stepSize));
  SetPosition(CRR,fullTrig(-stepSize));
  SetPosition(FFL,fDown);
  SetPosition(FML,fDown);
  SetPosition(FMR,fDown);
  SetPosition(FRR,fDown);
  delay(timStrafe);
  SetPosition(FFR,fUp);
  SetPosition(FRL,fUp);
  delay(timStrafe);
  SetPosition(CFL,fullTrig(-stepSize));
  SetPosition(CML,fullTrig(-stepSize));
  SetPosition(CMR,fullTrig(stepSize));
  SetPosition(CRR,fullTrig(stepSize));
  delay(timStrafe);
  SetPosition(FFR,fDown);
  SetPosition(FRL,fDown);
  delay(timStrafe);
  diagRfwdLast = true;
}
void diagLfwd(){
//  if(!diagLfwdLast){backHome();}
  SetPosition(FFR,fUp);
  SetPosition(FML,fUp);
  SetPosition(FMR,fUp);
  SetPosition(FRL,fUp);
  delay(timStrafe);
  SetPosition(CFR,fullTrig(-stepSize));
  SetPosition(CML,fullTrig(stepSize));
  SetPosition(CMR,fullTrig(-stepSize));
  SetPosition(CRL,fullTrig(stepSize));
  SetPosition(FFR,fDown);
  SetPosition(FML,fDown);
  SetPosition(FMR,fDown);
  SetPosition(FRL,fDown);
  delay(timStrafe);
  SetPosition(FFL,fUp);
  SetPosition(FRR,fUp);
  delay(timStrafe);
  SetPosition(CFR,fullTrig(stepSize));
  SetPosition(CML,fullTrig(-stepSize));
  SetPosition(CMR,fullTrig(stepSize));
  SetPosition(CRL,fullTrig(-stepSize));
  delay(timStrafe);
  SetPosition(FFL,fDown);
  SetPosition(FRR,fDown);
  delay(timStrafe);
  diagLfwdLast = true;
  
}
void strafe60(){///////////////WIP
  if(!strafe60last){backHome();}
  evensUp();
  delay(timSm);
  //evens forward
  SetPosition(2,fullTrig(-stepSize));
  SetPosition(4,fullTrig(-stepSize));
  SetPosition(6,fullTrig(stepSize));
  //odds back
  SetPosition(1,fullTrig(-stepSize));
  SetPosition(3,fullTrig(stepSize));
  SetPosition(5,fullTrig(-stepSize));
  delay(timSm);
  evensDown();
  delay(timSm);
  oddsUp();
  delay(timSm);
  //odds forward
  SetPosition(1,fullTrig(stepSize));
  SetPosition(3,fullTrig(-stepSize));
  SetPosition(5,fullTrig(stepSize));
  //evens back
  SetPosition(2,fullTrig(stepSize));
  SetPosition(4,fullTrig(stepSize));
  SetPosition(6,fullTrig(-stepSize));
  delay(timSm);
  oddsDown();
  delay(timSm); 
  strafe60last = true; 
}
void strafe330(){///////////////WIP
  if(!strafe330last){backHome();}
  evensUp();
  delay(timSm);
  //evens forward
  SetPosition(2,fullTrig(-stepSize));
  SetPosition(4,fullTrig(stepSize));
  SetPosition(6,fullTrig(-stepSize));
  //odds back
  SetPosition(1,fullTrig(stepSize));
  SetPosition(3,fullTrig(-stepSize));
  SetPosition(5,fullTrig(-stepSize));
  delay(timSm);
  evensDown();
  delay(timSm);
  oddsUp();
  delay(timSm);
  //odds forward
  SetPosition(1,fullTrig(-stepSize));
  SetPosition(3,fullTrig(stepSize));
  SetPosition(5,fullTrig(stepSize));
  //evens back
  SetPosition(2,fullTrig(stepSize));
  SetPosition(4,fullTrig(-stepSize));
  SetPosition(6,fullTrig(stepSize));
  delay(timSm);
  oddsDown();
  delay(timSm); 
  strafe330last = true; 
}
/***BACKWARD***/
void back(){//walk straight back//
  if(!backLast){backHome();}
  evensUp();
  delay(tim);  //needed
  evensBack();
  delay(tim);
  oddsFwd();
  delay(tim);
  evensDown();
  delay(tim);  //short as possible so feet are on the ground at all times
  oddsUp();
  delay(tim); //needed
  oddsBack();
  delay(tim);
  evensFwd();
  delay(tim);
  oddsDown();
  delay(tim);  //short as possible so feet are on the ground at all times
  backLast = true;
}
/********************GROUPED POSITIONS********/
void evensFwd(){
  SetPosition(CMR,fullTrig(-stepSize));
  SetPosition(CRL,fullTrig(stepSize));
  SetPosition(CFL,fullTrig(stepSize));
}
void evensFwdSm(){
  SetPosition(CMR,fullTrig(-stepSm));
  SetPosition(CRL,fullTrig(stepSm));
  SetPosition(CFL,fullTrig(stepSm));
}
void evensBack(){
  SetPosition(CMR,fullTrig(stepSize));
  SetPosition(CRL,fullTrig(-stepSize));
  SetPosition(CFL,fullTrig(-stepSize));
}
void evensBackSm(){
  SetPosition(CMR,fullTrig(stepSm));
  SetPosition(CRL,fullTrig(-stepSm));
  SetPosition(CFL,fullTrig(-stepSm));
}
void oddsFwd(){
  SetPosition(CML,fullTrig(stepSize));
  SetPosition(CRR,fullTrig(-stepSize));
  SetPosition(CFR,fullTrig(-stepSize));
}
void oddsFwdSm(){
  SetPosition(CML,fullTrig(stepSm));
  SetPosition(CRR,fullTrig(-stepSm));
  SetPosition(CFR,fullTrig(-stepSm));
}
void oddsBack(){
  SetPosition(CML,fullTrig(-stepSize));
  SetPosition(CRR,fullTrig(stepSize));
  SetPosition(CFR,fullTrig(stepSize));
}
void oddsBackSm(){
  SetPosition(CML,fullTrig(-stepSm));
  SetPosition(CRR,fullTrig(stepSm));
  SetPosition(CFR,fullTrig(stepSm));
}
void evensUp(){//puts even numbered femurs up
    SetPosition(FMR,fUp);
    SetPosition(FRL,fUp);
    SetPosition(FFL,fUp);
}
void oddsUp(){//puts even numbered femurs up
    SetPosition(FML,fUp);
    SetPosition(FRR,fUp);
    SetPosition(FFR,fUp);
}
void evensDown(){//even feet onto ground
    SetPosition(FMR,fDown);
    SetPosition(FRL,fDown);
    SetPosition(FFL,fDown);
}
void oddsDown(){//odd feet onto ground
    SetPosition(FML,fDown);
    SetPosition(FRR,fDown);
    SetPosition(FFR,fDown);
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
void evensSame(){//moves EVEN coxa CLOCKWISE (from above)
  SetPosition(CMR,fullTrig(stepSize));
  SetPosition(CRL,fullTrig(stepSize));
  SetPosition(CFL,fullTrig(stepSize));
}
void evensSameSm(){//moves EVEN coxa CLOCKWISE smaller increment
  SetPosition(CMR,fullTrig(stepSm));
  SetPosition(CRL,fullTrig(stepSm));
  SetPosition(CFL,fullTrig(stepSm));
}
void evensSameRev(){//moves EVEN coxa ANTICLOCKWISE
  SetPosition(CMR,fullTrig(-stepSize));
  SetPosition(CRL,fullTrig(-stepSize));
  SetPosition(CFL,fullTrig(-stepSize));
}
void evensSameRevSm(){//moves EVEN coxa ANTICLOCKWISE smaller increment
  SetPosition(CMR,fullTrig(-stepSm));
  SetPosition(CRL,fullTrig(-stepSm));
  SetPosition(CFL,fullTrig(-stepSm));
}
void oddsSame(){//moves ODD coxa CLOCKWISE
  SetPosition(CML,fullTrig(stepSize));
  SetPosition(CRR,fullTrig(stepSize));
  SetPosition(CFR,fullTrig(stepSize));
}
void oddsSameSm(){//moves ODD coxa CLOCKWISE smaller increment
  SetPosition(CML,fullTrig(stepSm));
  SetPosition(CRR,fullTrig(stepSm));
  SetPosition(CFR,fullTrig(stepSm));
}
void oddsSameRev(){//moves ODD coxa ANTICLOCKWISE
  SetPosition(CML,fullTrig(-stepSize));
  SetPosition(CRR,fullTrig(-stepSize));
  SetPosition(CFR,fullTrig(-stepSize));
}
void oddsSameRevSm(){//moves ODD coxa ANTICLOCKWISE smaller increment
  SetPosition(CML,fullTrig(-stepSm));
  SetPosition(CRR,fullTrig(-stepSm));
  SetPosition(CFR,fullTrig(-stepSm));
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

/*****************************UNUSED*******/
void closedGoTo(int motor,int ang){//WIP WIP try to just write a system where the motors move on a closed loop
  while(GetPosition(motor) != fullTrig(ang)){
    SetPosition(1,fullTrig(3));
  }
}
