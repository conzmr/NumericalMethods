#include <iostream>
#include <cmath>

using namespace std;
double error = 0.00001;

//Function
double f(double x){
	double result;
	result = pow(x,7)-0.9;
	return result;
}

int main(){
	double x0, x1,fx0,fx1,xm,fxm;
	int i = 0;
	cout << "Insert x0: ";
	cin >> x0;
	cout << "Insert x1: ";
	cin >> x1;

	fx0 = f(x0);
	fx1 = f(x1);

	//Only enter the loop if the results of the functions
	//are each in a difererent side of the x-axis.
	if(fx0*fx1 <= 0){
		do{
			//If one of the functions is already close to
			//zero, exit the loop.
			if(abs(fx0) <= error){
				xm = x0;
				break;
			}

			if(abs(fx1) <= error){
				xm = x1;
				break;
			}

			//Get the value of x between x0 and x1
			xm = (x0+x1)/2;
			fxm = f(xm);

			cout << "Iteraciones: " << i << " a=" << x0 << " b=" << x1 << " c=" << xm << " f(a)=" << fx0 << " f(b)=" << fx1 << " f(c)=" << fxm << endl;

			if(fx0*fxm < 0){
				fx1 = fxm;
				x1 = xm;
			}
			else if(fx1*fxm < 0){
				fx0 = fxm;
				x0 = xm;
			}
			i++;
			if(i > 1000){
				break;
			}
		}while(abs(fxm) > error);
	}
	else{
		cout << "f(x0) y f(x1) son del mismo signo" << endl;
		return 0;
	}

	cout << "Raíz en x = " << xm << endl;
	cout << "En " << i << " iteraciones" << endl;

	return 0;
}
