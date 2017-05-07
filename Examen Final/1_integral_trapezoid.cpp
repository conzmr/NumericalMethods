#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
  //return ( 0.2 + 25*x - 200*pow(x,2) + 675*pow(x,3) - 900*pow(x,4) + 400*pow(x,5) );
  return ( sin(2*x) - sin(x) );
}

double f_2(double x){
	return ( sin(x) - sin(2*x) );
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

double trapezoid_2(double a, double b, int n){
  double h = (b - a)/(n);
  double sum = 0;
  for(double i = a + h; i < b; i += h){
    sum += 2*f_2(i);
  }
  sum += f_2(b) + f_2(a);
  sum *= h/2;
  cout << "Trapezoid Approximation = " << sum << endl;
  return sum;
}

void porcentual_error(double real, double approx){
  cout << "Real Value = " << real << endl;
  cout << "Approximated Value = " << approx << endl;
  cout << "Error = " << abs((real - approx)/real)*100  << "%" << endl;
}

int main(){
  int number_of_rectangles;
  cout << "Number of Trapezoids: "; cin >> number_of_rectangles;
  double a = 0, b = M_PI/3;
  double c = M_PI/3, d = M_PI/2;
  double real = 0.5;
  porcentual_error( real, trapezoid(a,b,number_of_rectangles) + trapezoid_2(c, d, number_of_rectangles));
  return 0;
}
