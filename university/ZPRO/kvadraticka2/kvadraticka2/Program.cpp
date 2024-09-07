#include <iostream>
#include <math.h>
using namespace std;

enum struct Druh{Realne, Komplexni};
enum { a, b, c };

struct Vysledek
{
	Druh druh;
	double vysledek[2];
};

Vysledek ResKvadratickouRovnici(double koef[])
{
	double d = koef[b] * koef[b] * 4 * koef[a] * koef[c];
	Vysledek vysledek;
	if (d >= 0)
	{
		d = sqrt(d);
		vysledek.druh = Druh::Realne;
		vysledek.vysledek[0] = (-koef[b] + d) / 2 / koef[a];
		vysledek.vysledek[1] = (-koef[b] - d) / 2 / koef[a];
	}
	else
	{
		d = sqrt(-d);
		vysledek.druh = Druh::Komplexni;
		vysledek.vysledek[0] = -koef[b] / 2 / koef[a];
		vysledek.vysledek[1] =  d / 2 / koef[a];
	}
	return vysledek;
}

int main()
{
	double koeficienty = { 1,2,1 };
	Vysledek vysledek = ResKvadratickouRovnici(koeficienty);
	if (vysledek.druh == Druh::Realne)
	{
		cout << "x1 = " << vysledek.vysledek[0] << ", x2 = " endl;
	}
}