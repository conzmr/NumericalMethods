#include <iostream>
#include <cmath>

using namespace std;

void lineal(){
  double x1, x2, y1, y2, x, y;
  cout << "x1: ";
  cin >> x1;
  cout << "y1: ";
  cin >> y1;
  cout << "x2: ";
  cin >> x2;
  cout << "y2: ";
  cin >> y2;
  cout << "x: ";
  cin >> x;
  y = y1 + (y2 - y1)/(x2 - x1) * (x - x1);
  cout << "y = " << y1 << " + (" << y2 - y1 << ") / (" << x2 - x1 << ") * ( x - "  << x1 << " )" << endl;
  cout << "Approximated value of y = " << y << endl;

  double real = 7.986;

  cout << "Real Value = " << real << endl;
  cout << "Approximated Value = " << y << endl;
  cout << "Error = " << abs((real - y)/real)*100  << "%" << endl;
}

int main(){
  lineal();
  return 0;
}
