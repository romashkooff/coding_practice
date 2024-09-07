#include <iostream>
#include <math.h>

using namespace std;

enum DruhReseni{Realne, Komplexni};

enum{a,b,c}; // Indexy koeficientů

DruhReseni ResKvadratickouRovnici(double koef[], double vysledek[])
{
	double d = koef[b] * koef[b] - 4 * koef[a] * koef[c];
	if (d >= 0)
	{
		d = sqrt(d);
		vysledek[0] = (-koef[b] + d) / (2 * koef[a]);
		vysledek[1] = (-koef[b] - d) / (2 * koef[a]);
		return Realne;
	}
	else
	{
		d = sqrt(-d);
		vysledek[0] = -koef[b] / 2 / koef[a];
		vysledek[1] = d / 2 / koef[a];
		return Komplexni;
	}
}

int main()
{
	double koeficienty[] = { 1,-2,1 };
	double vysledek[2]{};
	DruhReseni druh = ResKvadratickouRovnici(koeficienty, vysledek);
	if (druh == Realne)
	{
		cout << "x1 = " << vysledek[0] << endl;
		cout << "x2 = " << vysledek[1] << endl;
	}
	else
	{
		cout << "x1,2 = " << vysledek[0] << " +- i*" << vysledek[1] << endl;
	}
}