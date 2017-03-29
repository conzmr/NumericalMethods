#include <iostream>
#include <cmath>

using namespace std;

double error = 5; //ERROR PARCIAL 2

double function_x(double y, double z){
  return (3+y+z)/6;
}

double function_y(double x, double z){
  return (40-6*x-z)/9;
}

double function_z(double x, double y){
  return (50-y+3*x)/(-12);
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
  }while(abs(3-(6*x-y-z))/3*100 > error || abs(40-(6*x+9*y+z))/40*100 > error || abs(50-(-3*x+y-12*z))/50*100 > error); //ERROR PARCIAL 2
}
