#include <iostream>
#include <cmath>

using namespace std;

double fx(double y, double z, double w){
  return (20+3*y-z+w)/8;
}

double fy(double x, double z, double w){
  return (3+x+3*z-8*w)/20;
}

double fz(double x, double y, double w){
  return (3-x-y+w)/3;
}

double fw(double x, double y, double z){
  return (8-6*x+4*y-11*z)/15;
}

int main() {
  double x, y, z,w, tx, ty, tz,tw;
  double error = 0.000001;//pow(10, -12);
  int i = 0;
  x = y = z = 0.0;

  do {
    tx = fx(y, z,w);
    ty = fy(x, z,w);
    tz = fz(x, y,w);
    tw = fw(x,y,z);
    x=tx;
    y=ty;
    z=tz;
    w=tw;
    i++;
    cout << x << " | " << y << " | " << z << " | " << w << " | " << i << endl;
  }while(abs(8*x-3*y+z-w-20) > error || abs(-x+20*y-3*z+8*w-3) > error || abs(x+y+3*z-w-3) > error || abs(6*x-4*y+11*z+15*w-8) > error);

  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
  cout << "z = " << z << endl;
  cout << "w = " << w << endl;
  cout << "i = " << i << endl;
}
