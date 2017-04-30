#include <iostream>
#include <cmath>

using namespace std;

double dif_finita(double x1, double y1, double x2, double y2){
  return (y2 - y1)/(x2 - x1);
}

void newton(double *x, double *y, int n, double value){
  cout << "Newton\n" << "=====================" << endl;
  double *res = new double[n - 1];
  double *_final = new double[n - 1];


  for(int i = 0; i < n; i++){
    res[i] = y[i];
  }

  _final[0] = res[0];

  cout << "b["<< 0 << "] = " << _final[0] << endl;

  for(int j = 1; j < n; j++){
    for(int i = 0; i < n - j; i++){
      res[i] = dif_finita(x[i], res[i], x[i+j], res[i+1]);
    }
    _final[j] = res[0];
    cout << "b["<< j << "] = " << _final[j] << endl;
  }

  double y_aprox = 0;
  double x_prod = 0;
  for(int i = 0; i < n; i++){
    x_prod = _final[i];
    for(int j = 0; j < i; j++){
      x_prod *= (value - x[j]);
    }
    y_aprox += x_prod;
  }

  cout << "f("<< value <<") = " << y_aprox << endl;
}

int main(){
  int n = 5;
  double x[] = {1, 2, 2.5, 4, 7};
  double y[] = {1, 0.5, 0.4, 0.25, 0.14};

  newton(x, y, n, 3);

  return 0;
}
