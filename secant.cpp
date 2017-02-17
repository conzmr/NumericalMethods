#include <iostream>
#include <cmath>

using namespace std;

double error = 0.00001;

double f(double x){
  return log(x);
}

int main(){
  double x0, x1, fx0, fx1,division,x;
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
      i++;
  }while(abs(fx1) > error);

  cout<<"x = "<<x1<<" En: "<<i<<" iteraciones"<<endl;

  return 0;

}
