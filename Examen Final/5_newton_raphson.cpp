#include <iostream>
#include <cmath>

using namespace std;

//#define FUNCION pow(x,7)-3;
//#define DIFF 7*pow(x,6);

double error = 1;

double f(double x){
  return 4*pow(x,4) + 4*pow(x,2) - 1;
}

double ff(double x){
  return 16*pow(x,3) + 8*x;
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
	cout << "x1 = " << x0 << " ErrItPorcentual: " << errItP << endl;
    i++;
}while(errItP > error);

  cout << "Raiz en: " << x0 << endl;
  cout << "Obtenido en " << i << " iteraciones." << endl;

  return 0;
}
