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
void walkA(int t){//raised CFL, CMR, CRL
  SetPosition(1,700);
  SetPosition(2,512);
  SetPosition(3,470);//changed from 590 to 470
  SetPosition(4,600);//changed from 450 to 600
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
void walkB(int t){//2-4-6 fwd (down), 1-3-5 back (down)
  SetPosition(1,680);
  SetPosition(2,330);
  SetPosition(3,470);//changed from 590 to 470
  SetPosition(4,690);
  SetPosition(5,330);
  SetPosition(6,500);// changed from 600 to 500
  SetPosition(7,680);
  SetPosition(8,680);
  SetPosition(9,680);
  SetPosition(10,680);
  SetPosition(11,680);
  SetPosition(12,680);
  delay(t);
}
void walkC(int t){//1-3-5 back (up), 2-4-6 back (down)
  SetPosition(1,450);//changed from 650 to 450
  SetPosition(2,680);
  SetPosition(3,375);
  SetPosition(4,570);//changed from 450 to 570
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
void walkD(int t){//1-3-5 fwd (down), 2-4-6 back (down)
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
void walkE(int t){//1-3-5 back (down), 2-4-6 back (up)
  SetPosition(1,680);
  SetPosition(2,470);// changed from 680
  SetPosition(3,470);//changed from 590
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
