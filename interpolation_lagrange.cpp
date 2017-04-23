#include <iostream>

using namespace std;

double L(double *x, int i, double value, int n){
  double product = 1;
  for(int j = 0; j < n; j++){
    if(i != j)
      product *= (value - x[j])/(x[i] - x[j]);
  }
  cout << "L(" << i << ") = " << product << endl;
  return product;
}

void lagrange(double *x, double *y, double value, int n){
  double sum = 0;
  for(int i = 0; i < n; i++){
    sum += L(x, i, value, n) * y[i];
  }
  cout << "f(" << value << ") = " << sum << endl;
}

int main(){
  int n = 5;
  double x[] = {1, 2, 2.5, 4, 7};
  double y[] = {1, 0.5, 0.4, 0.25, 0.14};

  cout << "Lagrange\n" << "=====================" << endl;
  lagrange(x, y, 3, n);
}
