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
  cout << "Approximated value of y = " << y << endl;
}

int main(){

  lineal();

  return 0;
}

//Determinar el polinomio de grado n que se ajuste a n+1 puntos.
//n puntos = función de grado n-1

/*
Interpolación Lineal
(y-y1)/(y2-y1) = (x-x1)/(x2-x1)

y = y1 + (y2-y1)/(x2-x1) * (x-x1)

f(x) = b2 x^2 + (b1 - b2 x1 - b2 x0) * x + (b0 - b1 x0 + b2 x0 x1)
*/
