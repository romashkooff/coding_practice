#include <iostream>
#include "float.h"
using namespace std;

int main()
{
	/* 
	int a = 100'000;
	short b = a;
	cout << a << " " << b << endl;
	unsigned c = -1;
	cout << c << endl;
	int ab = 056;
	int cd = 0x5a;
	int ef = 0b1010101; 
	*/

	double x = 0;
	double delta = 0.1;
	/* 
	while (x != 1.0)
	{
		x += delta;
		cout << x << endl;
	} 
	*/
	// cout << 1 - 10 * delta << endl;
	/* 
	while (x <= 1.0)
	{
		cout << x << endl;
		x += delta;
	} 
	*/
	/* 
	while (!((x >= 1.0 - 1.0e-5) && (x <= 1 + 1e-5)))
	{
		cout << x << endl;
		x += delta;
	}
	*/

	int xx = INT_MAX;
	cout << xx << endl;
	xx++;
	cout << xx << endl;
	char znak = 'a';
	wchar_t vz = L'k';
}