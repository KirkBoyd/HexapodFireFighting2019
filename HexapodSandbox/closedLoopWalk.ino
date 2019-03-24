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

void turnFastR(){// make big steps in circle to turn RIGHT
  
}
void turnFastL(){//make big steps in circle to turn LEFT
  
}
void turnSlowR(){//make small steps in circle to turn RIGHT
  
}
void turnSlowL(){//make small steps in circle to turn LEFT
  
}

