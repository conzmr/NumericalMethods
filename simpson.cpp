#include <iostream>

using namespace std;

double simpson_third(double *values, double a, double b, int n) {
  double segments = n - 1;
  double h = (b - a)/segments/3.0;
  cout << "h: " << h << endl;
  double sum = values[0];

  for(int i = 1; i < n - 1; i += 2) {
    sum += 4*values[i];
    if(i < n - 2)
      sum += 2*values[i+1];
  }
  sum += values[n-1];
  sum *= h;

  return sum;
}

double simpson_eighth(double *values, double a, double b) {
  return ( (b - a)/8.0 ) * (values[0] + 3*values[1] + 3*values[2] + values[3]);
}

int main(){
  double a[] = {1, 4, 9, 16, 25};
  double b[] = {1,4,9,16};
  cout << "Simpson 1/3 multiple: " << simpson_third(a, 1, 5, 5) << endl;
  cout << "Simpson 3/8: " << simpson_eighth(b, 1, 4) << endl;
  return 0;
}
