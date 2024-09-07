#include <iostream>

using namespace std;

void sum2vec(double x[], double y[], double z[], int size)
{
	for (int i = 0; i < size; i++)
	{
		z[i] = x[i] + y[i];
	}
}
const int N = 5;

int main()
{
	double x[N] = { 1.1, 1.2, 1.8, 3.1, 5.1 };
	double y[N] = { 2.1, 1.5, 3.8, 2.5, 4.2 };
	double z[N];
	sum2vec(x, y, z, N);
	for (int i = 0; i < N; i++)
	{
		cout << z[i] << " ";
	}
	cout << "\n";
}