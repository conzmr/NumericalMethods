#include <iostream>
#include <cmath>

using namespace std;

#define FUNCION cos(3*x)-x;
#define DIFF -1*3*sin(3*x)-1;

double error = 0.00001;

double f(double x){
  return (double) FUNCION;
}

double ff(double x){
  return (double) DIFF;
}

int main(){
  double x0, x1, m;
  int i = 0;
  double errIt,errItR, errItP;
  cout << "Insert x0: ";
  cin >> x0;

  do{
    m = f(x0)/ff(x0);
    x1 = x0 - m;
    errIt = abs(x1-x0);
    errItR = errIt/abs(x1);
    errItP = errItR*100;
    x0 = x1;
	cout << "x1 = " << x0 << " ErrItR: " << errItR << " ErrItP: " << errItP << " ErrItAbs: " << errIt << endl;
    i++;
  }while(abs(m) > error);

  cout << "Raiz en: " << x0 << endl;
  cout << "Obtenido en " << i << " iteraciones." << endl;

  return 0;
}
