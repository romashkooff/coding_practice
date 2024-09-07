#include <iostream>

using namespace std;

double sum2vec(double x[], double y[], int n1, int n2);

int main()
{
	double x[] = { 1.5,-3.1,4.2 };
	double y[] = { 2.5,1.1,-1.2 };
	int n1 = sizeof(x) / sizeof(x[0]);
	int n2 = sizeof(y) / sizeof(y[0]);
	double z = sum2vec(x, y, n1, n2);
	cout << "... " << z << endl;
	return 0;
}

double sum2vec(double x[], double y[], int n1, int n2)
{
	if (n1 != n2)
	{
		cout << "sum of these two vectors does not exist!" << endl;
		return -1;
	}
	else
	{
		double z[n1-1] = { 0 };
		for (int i = 0; i < n1; i++)
		{
			z[i] = x[i] + y[i];
		}
		return z;
	}
}