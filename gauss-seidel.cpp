#include <iostream>
#include <cmath>

using namespace std;

double error = 0.000001;

double function_x(double y, double z){
  return (7+y-z)/2;
}

double function_y(double x, double z){
  return (6-x+z)/2;
}

double function_z(double x, double y){
  return (12-x-y);
}

int main(){
  double x, y, z;
  int i = 0;
  x = y = z = 0;
  do{
    x = function_x(y,z);
    y = function_y(x,z);
    z = function_z(x,y);
    i++;
    cout << i << ". x = " << x << ". y = " << y << ". z = " << z << endl;
  }while(abs(x+y+z-12) > error || abs(2*x-y+z-7) > error);
}
