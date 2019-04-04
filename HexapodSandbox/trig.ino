/*
 * HexapodTrig
 * Created: 03/16/2019 KB
 * Last Edit: 03/17/2019 KB    
 * Notes: see image(s) that should accompany this sketch for visual representation of the triangle
 */

/**CONVERSIONS**/
float toDeg(float ang){ //converts RADIAN float values to DEGREE float values
  return ang*(180/M_PI);    
    //return ang*57296/1000; //for calculation speed (avoiding decimals) use this fraction to approximate pi
}
float toRad(float ang){ //converts DEGREE float values to RADIAN float values
  return ang*(M_PI/180);
    //return ang*1000/57296;  //for calculation speed (avoiding decimals) use this fraction to approximate pi
}
float toDynum(float ang){ //converts DEGREE float values of Phi to DYNUM, which can be written to the servo
  dynum = (ang/0.2929)+512;
  return (ang/0.2929)+512;  //one integer value of Dynum corresponds to 0.2929 degrees
}

/**MAIN TRIG**/
float getBeta(float ang){ //RADIANS; takes an alpha float value
  //Serial.print("alpha: ");  //for debug only
  //Serial.println(toDeg(ang));  //for debug only
  delta = asin((D*sin(alpha))/r); //law of sines to find delta
  //Serial.print("delta: ");  //for debug only
  //Serial.println(toDeg(delta));  //for debug only
  beta = toRad(180) - alpha - delta; //property of triangles (sum == 180) to find beta
  //Serial.print("beta: ");  //for debug only
  //Serial.println(toDeg(beta));  //for debug only
  B = (r*sin(beta)/sin(alpha)); //law of sines to find B
  //Serial.print("B: ");  //for debug only
  //Serial.println(B);  //for debug only
  return beta;
}
float getPhi(float ang){ //RADIANS; takes beta as parameter to use literally 180 - beta; finds angle that we want to set the leg to
  phi = M_PI - ang;
  return M_PI - ang;
}
int fullTrig(float ang){ //DEGREES --> dynum; takes alpha (in DEGREES) and calculates to needed dynum
  alpha = toRad(ang);
  getBeta(alpha);
  getPhi(beta);
  toDynum(toDeg(phi));
  return dynum;
}

void printAngles(){
  Serial.println("ANGLES...");
  Serial.print("alpha: ");
  Serial.println(toDeg(alpha));
  Serial.print("delta: ");
  Serial.println(toDeg(delta));
  Serial.print("B: ");
  Serial.println(B);
  Serial.print("beta: ");
  Serial.println(toDeg(beta));
  Serial.print("phi: ");
  Serial.println(toDeg(phi));
  Serial.print("dynum: ");
  Serial.println(dynum);
  Serial.println();
}
/*************************************************************************/

