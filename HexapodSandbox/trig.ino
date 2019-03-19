/*
 * HexapodTrig
 * Created: 03/16/2019 KB
 * Last Edit: 03/17/2019 KB    
 * Notes: see image(s) that should accompany this sketch for visual representation of the triangle
 */
 
#include <math.h> //import additional math functions for the inverse trig functions
float alpha = 0;  //RADIANS; angle of deflection from center of circle to default leg position to new angle
int r = 30.31;  //(in mm) length of coxa from outer circle of base to outside of motor clip
int D = 72; //(in mm) radius of the base from center to outermost circle 

float delta; //RADIANS; angle opposite length D in triangle
float B; //(in mm)third leg of triangle. changes in length as angle phi increases (or beta decreases)
float beta; //RADIANS; third angle in trangle, opposite length B, decreases as phi increases (supplementary angles)

float toDeg(float ang){ //converts RADIAN float values to DEGREE float values
  return ang*57296/1000; //for calculation speed (avoiding decimals) use this fraction to approximate pi
}
float toRad(float ang){ //converts DEGREE float values to RADIAN float values
  return ang*1000/57296;  //for calculation speed (avoiding decimals) use this fraction to approximate pi
}
float getBeta(float ang){ //RADIANS; takes an alpha float value
  delta = asin((D*sin(alpha))/r); //law of sines to find delta
  beta = toRad(180) - alpha - delta; //property of triangles (sum == 180) to find beta
  B = (r*sin(beta)/sin(alpha); //law of sines to find B
}
float getPhi(float ang){ //RADIANS; takes beta as parameter to use literally 180 - beta; finds angle that we want to set the leg to
  return 180 - ang;
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
/*************************************************************************/
#define numSteps 1023 //max value to set AX-12A servos could possibly reach
#define centered 512  //centered position of AX-12A
#define dynaMax 804 //maximum allowed position of AX-12A for current Hexapod
#define dynaMin 292 //minimum allowed position of AX-12A for current Hexapod














