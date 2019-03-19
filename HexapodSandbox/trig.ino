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
float B; //third leg of triangle. changes in length as angle phi increases (or beta decreases)
float beta; //third angle in trangle, opposite length B

float toDeg(float ang){ //converts radian float values to degree float values
  return ang*57296/1000; //for calculation speed (avoiding decimals) use this fraction to approximate pi
}
float toRad(float ang){ //converts degree float values to radian float values
  return ang*1000/57296;  //for calculation speed (avoiding decimals) use this fraction to approximate pi
}
float getBeta(float ang){ //UNIT: RADIANS takes an alpha float value
  delta = asin((D*sin(alpha))/r);
  beta = toRad(180) - alpha - delta;
  B = (r*sin(beta)/sin(alpha);
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
