#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

int faktorial(int n)
{
	if (n < 0)
	{
		throw out_of_range("Záporná hodnota parametru faktoriálu");
	}
	int vysledek = 1;
	while (n > 1)
	{
		vysledek *= n--;
	}
	return vysledek;
}

int main()
{
	try
	{
		cout << faktorial(-6) << endl;
		cout << "Spočteno" << endl;
	}
	catch (...)
	{
		cout << "Neznáma chyba" << endl;
	}
	cout << "Ferda Mravenec, práce všeho druhu" << endl;
}