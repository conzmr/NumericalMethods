#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
  double n;
  double sum_x, sum_y, sum_square_x, sum_prod, av_x, av_y, a0, a1;
  cout << "Enter value of n: ";
  cin >> n;

  ifstream inx("x.txt");
  ifstream iny("y.txt");

  if(!inx || !iny){
    cout << "Error" << endl;
  }
  for(int i = 0; inx && iny && i < n; i++){
    string line;
    double x, y;
    inx >> x;
    iny >> y;

    sum_x += x;
    sum_y += y;
    sum_square_x += x*x;
    sum_prod += x*y;

    cout << x << " " << y << endl;
  }

  inx.close();
  iny.close();

  av_x = sum_x / n;
  av_y = sum_y / n;

  a1 = (n*sum_prod - sum_x*sum_y)/(n*sum_square_x - sum_x*sum_x);
  a0 = (av_y - a1*av_x);

  cout << "Sum x: " << sum_x << " | Sum y: " << sum_y << " | Sum square x: " << sum_square_x << " | Sum product x*y: " << sum_prod << endl;
  cout << "a1 = " << a1 << " | a0 = " << a0 << endl;
  cout << "y = " << a0 << " + " << a1 << "x" << endl;
}
