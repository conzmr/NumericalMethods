#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
  return ( 0.2 + 25*x - 200*pow(x,2) + 675*pow(x,3) - 900*pow(x,4) + 400*pow(x,5) );
}

double f_individual_integral(double x){
  return ( 0.2*x + 25*pow(x,2)/2 - 200*pow(x,3)/3 + 675*pow(x,4)/4 - 900*pow(x,5)/5 + 400*pow(x,6)/6 );
}

double f_integral(double a, double b){
  double value = (f_individual_integral(b) - f_individual_integral(a));
  cout << "Real value of F(a, b) = " << value << endl;
  return value;
}

double trapezoid(double a, double b, int n){
  double h = (b - a)/(n);
  double sum = 0;
  for(double i = a + h; i < b; i += h){
    sum += 2*f(i);
  }
  sum += f(b) + f(a);
  sum *= h/2;
  cout << "Trapezoid Approximation = " << sum << endl;
  return sum;
}

double riemann_right(double a, double b, double cant){
  double delta = (b - a)/cant;
  double sum = 0;
  for(double i = a + delta; i <= b; i += delta){
    //cout << "\t" << i << endl;
    sum += f(i) * delta;
  }
  cout << "Riemann Right Rectangle Approximation = " << sum << endl;
  return sum;
}

double riemann_left(double a, double b, double cant){
  double delta = (b - a)/cant;
  double sum = 0;
  for(double i = a; i + delta <= b; i += delta){
    //cout << "\t" << i << endl;
    sum += f(i) * delta;
  }
  cout << "Riemann Left Rectangle Approximation = " << sum << endl;
  return sum;
}

void porcentual_error(double real, double approx){
  cout << "\tError = " << abs((real - approx)/real)*100  << "%" << endl;
}

int main(){
  int number_of_rectangles = 2;
  double real = f_integral(0,0.8);
  porcentual_error( real, riemann_right(0,0.8,number_of_rectangles) );
  porcentual_error( real, riemann_left(0,0.8,number_of_rectangles) );
  porcentual_error( real, trapezoid(0,0.8,number_of_rectangles) );
  return 0;
}
