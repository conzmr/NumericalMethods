#include <iostream>

using namespace std;

double L(double *x, int i, double value, int n){
  double product = 1;
  for(int j = 0; j < n; j++){
    if(i != j)
      product *= (value - x[j])/(x[i] - x[j]);
  }
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
  int n = 3;
  double x[] = {1, 4, 6};
  double y[] = {0, 1.386294, 1.791759};

  cout << "Lagrange\n" << "=====================" << endl;
  lagrange(x, y, 5, n);
}
