#include <iostream>
#include <cmath>

using namespace std;

double dif_finita(double x1, double y1, double x2, double y2) {
  return (y2 - y1)/(x2 - x1);
}

void newton(double *x, double *y, int n, double value) {

	cout << "T\tO(T)\n=============" << endl;
	for(int i = 0; i < n; i++){
		cout << x[i] << "\t" << y[i] << endl;
	}
	cout << "\nNewton\n" << "==============================" << endl;
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

  cout << endl << "Polynomial\n==============================" << endl;

  cout << "f(x) = ";
  for(int i = 0; i < n; i++){
	  cout << _final[i];
	  for(int j = 0; j < i; j++){
		  cout << "(x - " << x[j] <<  ")";
	  }
	  if(i < n - 1){
		  cout << " + ";
	  }
  }
  cout << endl << endl << "==============================" << endl;

  cout << "O("<< value <<") = " << y_aprox << endl;

  double real = 7.986;

  cout << "Real Value = " << real << endl;
  cout << "Approximated Value = " << y_aprox << endl;
  cout << "Error = " << abs((real - y_aprox)/real)*100  << "%" << endl;
}

int main() {
  int n = 6;
  //double x[] = {1, 2, 2.5, 4, 7};
  double x[] = {0, 8, 16, 24, 32, 40};
  //double y[] = {1, 0.5, 0.4, 0.25, 0.14};
  double y[] = {14.621, 11.843, 9.870, 8.418, 7.305, 6.413};

  newton(x, y, n, 27);

  return 0;
}
