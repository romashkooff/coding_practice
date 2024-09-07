#include <iostream>
#include <math.h>

using namespace std;

double fbig(double x, double y)
{
	return(x > y) ? x : y;
}

char fbig(char x, char y)
{
	return (x > y) ? x : y;
}

int main()
{
	char x = '7';
	char y = '5';
	char z = fbig(x, y);

	cout << "Vysledek je: " << z << endl;

	return 0;
}