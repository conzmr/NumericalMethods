#include <iostream>
#include <cmath>

using namespace std;

double error = 0.1; //ERROR PARCIAL 2

double f(double x){
  return 9*exp(-1*0.7*x)*cos(4*x)-3.5;
}

int main(){
  double x0, x1, fx0, fx1,division,x, porcentual = 0;
  int i=0;

  cout<<"Insert value for"<<endl<<"x0: ";
  cin>>x0;
  cout<<"x1: ";
  cin>>x1;

  do{
      fx0 = f(x0);
      fx1 = f(x1);
      division = fx1*(x0-x1)/(fx0-fx1);
      cout<<"x0="<<x0<<" x1="<<x1<<" Division="<<division<<endl;
      x = x1 - division;
      x0=x1;
      x1=x;
      porcentual = abs(x1-x0)/x0*100; //ERROR PARCIAL 2
      cout << "Error porcentual = " << porcentual << endl;
      i++;
  }while(abs(porcentual) > error);

  cout<<"x = "<<x1<<" En: "<<i<<" iteraciones"<<endl;
  cout << "Error porcentual final = " << porcentual << endl;

  return 0;

}
