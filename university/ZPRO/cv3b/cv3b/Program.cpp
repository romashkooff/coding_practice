#include <iostream>

using namespace std;

void findmax(double x[]);

int main()
{
	double x[] = { 1.5, 8.2, 9.5, 5, 7, 11.5, 4,3 };
	findmax(x);
	return 0;
}

void findmax(double x[])
{
	double max = x[0];
	int imax = 0;
	int n = sizeof(x[0]);
	for (int i = 1; i <= n; i++)
	{
		if (x[i] > max)
		{
			max = x[i];
			imax = i;
		}
	}
	cout << "Maximum je: " << max << " a je na " << imax + 1 << ". miste." << endl;
}
