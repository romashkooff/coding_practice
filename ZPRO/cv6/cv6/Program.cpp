#include <iostream>

using namespace std;

struct output { int index; double value; };

output sfindmax(double x[], int n);

int main()
{
	double x[] = { 1.5,5.1,9.0,8.5 };
	int n = sizeof(x) / sizeof(x[0]);
	output v = sfindmax(x, n);

	cout << ".... " << v.index << endl;
	return 0;
}

output sfindmax(double x[], int n)
{
	double maxx = x[0];
	int imax = 0;
	for (int i = 1; i < n; i++)
	{
		if (x[i] > maxx)
		{
			maxx = x[i];
			imax = i;
		}
	}
	imax = imax + 1;
	output v;
	v.index = imax;
	v.value = maxx;
	return v;
}