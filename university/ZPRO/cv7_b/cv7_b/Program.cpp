#include <iostream>

using namespace std;

int main()
{
	double x[5] = { 1.1,2.5,1.8,3.1,5.1 };
	int N = sizeof(x) / sizeof(x[0]);
	for (int i = 0; i < N - 1; i++)
	{
		int p = 0;
		for (int j = 0; j < N - 1; j++)
		{
			if (x[j] > x[j + 1])
			{
				double temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
				p = p + 1;
			}
		}
		if (p == 0)
		{
			break;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << x[i] << " ";
	}
}