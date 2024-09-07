#include <iostream>
#include <cstdlib>

using namespace std;


// do prvku ulozi nahodna cisla z intervalu [1, 100]
void naplnPoleNahodnymiCisly(int* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		p[i] = rand() % 100 + 1;
	}
}

void vytiskniPole(int* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}

int indexNejmensihoPrvku(int* p, int n)
{
	int minIdx = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i] < p[minIdx])
		{
			minIdx = i;
		}
	}
	return minIdx;
}

int main()
{
	const int N = 10;
	int pole[N];
	int idx;
	srand(time(nullptr));
	naplnPoleNahodnymiCisly(pole, N);
	vytiskniPole(pole, N);
	idx = indexNejmensihoPrvku(pole, N);
	cout << "pole[" << idx << "]=" << pole[idx] << endl;
}