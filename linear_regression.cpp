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
  cout << "  x\t  y" << endl;
  for(int i = 0; inx && iny && i < n; i++){
    //string line;
    double x, y;
    inx >> x;
    iny >> y;

    sum_x += x;
    sum_y += y;
    sum_square_x += x*x;
    sum_prod += x*y;

    cout << x << "\t" << y << endl;
  }

  inx.close();
  iny.close();

  av_x = sum_x / n;
  av_y = sum_y / n;

  a1 = (n*sum_prod - sum_x*sum_y)/(n*sum_square_x - sum_x*sum_x);
  a0 = (av_y - a1*av_x);

  double y_medida, y_calculada, x_medida, error, st;

  ifstream iny2("y.txt");
  ifstream inx2("x.txt");
  for(int i = 0; i < n; i++){
    iny2 >> y_medida;
    inx2 >> x_medida;
    y_calculada = a0 + a1*x_medida;
    error += pow((y_medida - y_calculada),2);
    st += pow(y_medida-(av_y),2);
  }

  inx2.close();
  iny2.close();

  double ErrEstandar = sqrt(error/(n-2));
  double r = sqrt((st-error)/st);

  cout << "Sum x: " << sum_x << " | Sum y: " << sum_y << " | Sum square x: " << sum_square_x << " | Sum product x*y: " << sum_prod << endl;
  cout << "a1 = " << a1 << " | a0 = " << a0 << endl;
  cout << "y = " << a0 << " + " << a1 << "x" << endl;
  cout << "Error estandar: " <<  ErrEstandar << endl;
  cout << "Coeficiente de determinacion: " << r << endl;

  return 0;
}
