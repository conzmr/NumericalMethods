#include <iostream>
#include <cmath>

using namespace std;

double error = 0.1;

int main(){
  int deg = 5;
  int i, ir , is;
  //double o[] = {1.25,-3.875,2.125,2.75,-3.5,1};
  double o[] = {1,-2,3,-4,1,-1};
  double r,s,dr,ds;
  int h;

  //r=-1;
  //s=-1;
  r = 0;
  s = 0;
  do{
    double b[deg+1];
    for(i = deg; i >= 0; i--){
      ir = i+1;
      is = i+2;
      if(is <= deg){
        b[i]=b[ir]*r+b[is]*s+o[i];
      }
      else if(ir <= deg){
        b[i]=b[ir]*r+o[i];
      }
      else{
        b[i]=o[i];
      }
    }
    double c[deg+1];
    for(i = deg; i >= 0; i--){
      ir = i+1;
      is = i+2;
      if(is <= deg){
        c[i]=c[ir]*r+c[is]*s+b[i];
      }
      else if(ir <= deg){
        c[i]=c[ir]*r+b[i];
      }
      else{
        c[i]=b[i];
      }
    }
/*
    cout << "Array b: ";
    for(i = 0; i < deg+1; i++){
        cout << b[i] << " ";
    }
    cout << endl;

    cout << "Array c: ";
    for(i = 0; i < deg+1; i++){
        cout << c[i] << " ";
    }
    cout << endl;
*/
    dr = ((-b[deg-1])*c[deg-2]-(-b[deg])*(c[deg-3]))/(c[deg-2]*c[deg-2]-c[deg-1]*c[deg-3]);
    ds = (c[deg-2]*(-b[deg])-c[deg-1]*(-b[deg-1]))/(c[deg-2]*c[deg-2]-c[deg-1]*c[deg-3]);

    r = r+dr;
    s = s+ds;
  }while(abs(dr/r) > error || abs(ds/s) > error);

  double number = pow(r,2)+4*s;
  cout << "\nNumber: " << number << endl;
  if(number >= 0){
    double x1 = (r + sqrt(number))/2;
    double x2 = (r - sqrt(number))/2;
    cout << endl << "x1: " << x1 << "\nx2: " << x2 << endl;
  }
  else{
    double x1 = (r + sqrt(abs(number)))/2;
    double x2 = (r - sqrt(abs(number)))/2;
    cout << endl << "x1: " << x1 << "i\nx2: " << x2 << "i" << endl;
  }



  return 0;

}
