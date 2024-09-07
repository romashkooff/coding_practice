#include <iostream>
using namespace std;

using T = double;
const int HORNI_MEZ_PRO_FAKTORIAL = 12;

T faktorial(T n)
{
	T vysledek = 1;
	while (n > 1)
	{
		vysledek *= n--;
	}
	return vysledek;
}

int main()
{
	cout << "Zadej číslo: ";
	int n;
	cin >> n;
	if ((n >= 0) && (n <= HORNI_MEZ_PRO_FAKTORIAL))
	{
		cout << "Jeho faktoriál je " << faktorial(n) << endl;
	}
	else
	{
		cout << "Číslo je mimo dovolený rozsah" << endl;
	}
}