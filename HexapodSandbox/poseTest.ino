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
void walkA(int t){//same as walkStance with raised CFL, CMR, CRL
  SetPosition(1,700);
  SetPosition(2,512);
  SetPosition(3,590);
  SetPosition(4,450);
  SetPosition(5,330);
  SetPosition(6,375);//
  SetPosition(7,680);//CFR down
  SetPosition(8,470);//CMR up
  SetPosition(9,680);//CRR down
  SetPosition(10,470);//CRL up
  SetPosition(11,680);//CML down
  SetPosition(12,470);//CFL up
  delay(t);
}
void walkB(int t){//
  SetPosition(1,680);
  SetPosition(2,330);
  SetPosition(3,590);
  SetPosition(4,690);
  SetPosition(5,330);
  SetPosition(6,600);
  SetPosition(7,680);
  SetPosition(8,680);
  SetPosition(9,680);
  SetPosition(10,680);
  SetPosition(11,680);
  SetPosition(12,680);
  delay(t);
}
void walkC(int t){//1 3 5 fwd 2 4 6 back 
  SetPosition(1,650);
  SetPosition(2,680);
  SetPosition(3,375);
  SetPosition(4,450);
  SetPosition(5,330);
  SetPosition(6,330);
  SetPosition(7,470);
  SetPosition(8,680);
  SetPosition(9,470);
  SetPosition(10,680);
  SetPosition(11,470);
  SetPosition(12,680);
  delay(t);
}
void walkD(int t){
  SetPosition(1,450);
  SetPosition(2,680);
  SetPosition(3,330);
  SetPosition(4,450);
  SetPosition(5,680);
  SetPosition(6,330);
  SetPosition(7,680);
  SetPosition(8,680);
  SetPosition(9,680);
  SetPosition(10,680);
  SetPosition(11,680);
  SetPosition(12,680);
  delay(t);
}
void walkE(int t){
  SetPosition(1,680);
  SetPosition(2,680);
  SetPosition(3,590);
  SetPosition(4,590);
  SetPosition(5,330);
  SetPosition(6,330);
  SetPosition(7,680);
  SetPosition(8,470);
  SetPosition(9,680);
  SetPosition(10,470);
  SetPosition(11,680);
  SetPosition(12,470);
  delay(t);
}
