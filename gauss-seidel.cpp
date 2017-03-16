#include <iostream>
#include <cmath>

using namespace std;

double error = 0.000001;

double function_x(double y, double z, double w){
  return (20+3*y-z+w)/8;
}

double function_y(double x, double z, double w){
  return (3+x+3*z-8*w)/20;
}

double function_z(double x, double y, double w){
  return (3-x-y+w)/3;
}

double function_w(double x, double y, double z){
  return (8-6*x+4*y-11*z)/15;
}

int main(){
  double x, y, z, w;
  int i = 0;
  x = y = z = 0;
  do{
    x = function_x(y,z,w);
    y = function_y(x,z,w);
    z = function_z(x,y,w);
    w = function_w(x,y,z);
    i++;
    cout << i << ". x = " << x << ". y = " << y << ". z = " << z << ". w = " << w << endl;
  }while(abs(8*x-3*y+z-w-20) > error || abs(-x+20*y-3*z+8*w-3) > error || abs(x+y+3*z-w-3) > error || abs(6*x-4*y+11*z+15*w-8) > error);
}
