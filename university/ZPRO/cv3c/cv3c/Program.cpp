#include <iostream>

using namespace std;

int main()
{
	/*
	double x[] = {1.1, 8.1, 9.5, 5.5, 7.8, 11.5, 8.9};
	int n = sizeof(x) / sizeof(x[0]);
	double temp = x[1];
	x[1] = x[n - 1];
	x[n - 1] = temp;
	cout << x[n - 1] << endl;
	*/

	double x[] = { 1.1, 8.1, 9.5, 5.5, 7.8, 11.5, 8.9 };
	int n = sizeof(x) / sizeof(x[0]);
	double S = x[0];
	for (int i = 1; i <= n - 1; i++)
	{
		S = S + x[i];
	}
	cout << "Soucet vsech prvku vektoru x je S = " << S << endl;
	return 0;	
}