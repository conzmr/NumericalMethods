#include <iostream>
#include <cmath>

using namespace std;

double dif_finita(double x1, double y1, double x2, double y2){
  return (y2 - y1)/(x2 - x1);
}

void newton(double *x, double *y, int n, double value){
  double *res = new double[n - 1];
  double *final = new double[n - 1];


  for(int i = 0; i < n; i++){
    res[i] = y[i];
  }

  final[0] = res[0];

  cout << "b["<< 0 << "] = " << final[0] << endl;

  for(int j = 1; j < n; j++){

    //cout << "j: " << j << endl;

    for(int i = 0; i < n - j; i++){
      //cout << "\ti: "  << i << "\ti + j = " << i+j << "\tx["<< i <<"]=" << x[i] << " x[" << i + j << "] = " << x[i+j] << endl;
      //cout << "\tres[primero]= " << res[i] << " res[segundo]= " << res[i+1] << endl;
      res[i] = dif_finita(x[i], res[i], x[i+j], res[i+1]);
      //cout << "\tres["<< i << "] = " << res[i] << endl;
    }
    final[j] = res[0];
    cout << "b["<< j << "] = " << final[j] << endl;
  }

  double y_aprox = 0;
  double x_prod = 0;
  for(int i = 0; i < n; i++){
    x_prod = final[i];
    for(int j = 0; j < i; j++){
      x_prod *= (value - x[j]);
    }
    y_aprox += x_prod;
  }

  cout << "f("<< value <<") = " << y_aprox << endl;
}

int main(){
  int n = 3;
  double x[] = {1, 4, 6};
  double y[] = {0, 1.386294, 1.791759};

  newton(x, y, n, 5);

  return 0;
}
