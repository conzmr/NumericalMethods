#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void polynomial_regression(double x[], double y[], const int degree, const int n) {
  double sum_x = 0, sum_xy = 0;

  int size_of_row = degree + 1;

  double linear_equations[size_of_row][size_of_row];
  double sol_vector[size_of_row];

  cout << "\nConstructing system of linear equations..." << endl << "------------------------------------------" << endl;
  for(int i = 0; i < size_of_row; i++) {
    sum_xy = 0;

    for(int j = 0; j < n; j++) {
      sum_xy += pow(x[j],i)*y[j];
    }
    sol_vector[i] = sum_xy;

    for (int j = 0; j < size_of_row; j++) {
      sum_x = 0;
      if (i == 0 && j == 0) {
        linear_equations[i][j] = n;
      }
      else {
        //Calculate the sum of x to a certain power.
        for (int h = 0; h < n; h++) {
          sum_x += pow(x[h],(j+i));
        }
        linear_equations[i][j] = sum_x;
      }
    }
  }
  for(int i = 0; i < size_of_row; i++){
    for(int j = 0; j < size_of_row; j++){
      cout << linear_equations[i][j] << "\t";
    }
    cout << "=\t" << sol_vector[i];
    cout << endl;
  }
}

int main() {
  int n, degree;
  cout << "n: ";
  cin >> n;
  cout << "degree: ";
  cin >> degree;

  ifstream inx("x.txt");
  ifstream iny("y.txt");

  if(!inx || !iny){
    cout << "Error" << endl;
  }

  double X[n], Y[n];

  cout << "\n  x\t  y" << endl << "-------------" << endl;
  for(int i = 0; inx && iny && i < n; i++) {
    inx >> X[i];
    iny >> Y[i];

    cout << X[i] << "\t" << Y[i] << endl;
  }

  inx.close();
  iny.close();

  polynomial_regression(X,Y,degree,n);

  return 0;
}

//Error estandar de estimación Sy/x = sqrt(sr/(n-(m+1)))
//r^2 = (st-sr)/st
