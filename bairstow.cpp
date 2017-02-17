#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int grado = 5;
  int i, ir , is;
  double o[] = {1.25,-3.875,2.125,2.75,-3.5,1};
  double r,s,rmul,smul,b[6];
  int h;

  r=-1;
  s=-1;

  for(i = grado; i >= 0; i--){
    ir = i+1;
    is = i+2;
    if(is <= grado){
      b[i]=b[ir]*r+b[is]*s+o[i];
    }
    else if(ir <= grado){
      b[i]=b[ir]*r+o[i];
    }
    else{
      b[i]=o[i];
    }
  }

  for(h = 0; h < 6; h++){
    cout<<b[h]<<"  ";
  }
  cout<<endl;
  return 0;

}
