#define radius 72
#define coxaL 30.31

long beta(long alpha){
  return 180-alpha-asin((radius-sin(alpha))/coxaL);
}
