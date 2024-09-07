#include <iostream>
using namespace std;

void pozdrav()
{
	cout << "Nazdar" << endl;
}

int i = 3;

int main()
{
	// Prázdý příkaz
	// pozdrav; Také prázdý příkaz
	;
	{}
	(void)0;
	// Blok, lokální proměna
	cout << i << endl;
	int i = 8;
	{
		cout << i << endl;
		int i = 10;
		cout << i << endl;
		cout << ::i << endl;
	}
	cout << i << endl;
}