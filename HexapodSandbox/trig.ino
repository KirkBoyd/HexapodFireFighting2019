/*
 * HexapodTrig
 * Created: 03/16/2019 KB
 * Last Edit: 03/17/2019 KB    
 * Notes: see image(s) that should accompany this sketch for visual representation of the triangle
 */
 
#include <math.h> //import additional math functions for the inverse trig functions
float alpha = 0;  //angle of deflection from center of circle to default leg position to new angle
int r = 30.31;  //in mm
int D = 72; //in mm

float delta; //angle opposite length D in triangle
float Bpos; //length opposite angle beta (equals r+D when leg is not rotated, and decreases as leg turns further) *positive value from quadratic formula*
float Bneg; //length opposite angle beta (equals r+D when leg is not rotated, and decreases as leg turns further) *negative value from quadratic formula*
float beta; //third angle in trangle, opposite length B

float toDeg(float ang){ //converts radian float values to degree float values
  return ang*57296/1000; //for calculation speed (avoiding decimals) use this fraction to approximate pi
}
float toRad(float ang){ //converts degree float values to radian float values
  return ang*1000/57296;  //for calculation speed (avoiding decimals) use this fraction to approximate pi
}
float getBeta(float ang){ //UNIT: RADIANS takes an alpha float value
  delta = asin((D*sin(alpha))/r);
  Bpos = sqrt((D*D)-(r*r)+(D*D)*(cos(delta)*cos(delta)) + D*cos(delta));
  Bneg = Bpos*(-1);
  if(Bpos>0){
    beta = asin((Bpos*sin(delta)/D));
    return beta;
  }
  else{
    beta = asin((Bneg*sin(delta)/D));
    return beta;
  }
}

//void setup() { //this can be put into the arduino loop to test an alpha angle of 10 degrees
//  Serial.begin(9600);
//}
//
//void loop() {
//  alpha = toRad(10);
//  getBeta(alpha);
//  Serial.println(toDeg(beta));
//  delay(5000);
//}
