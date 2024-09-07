#include <iostream>
using namespace std;

void pozdrav(int n)
{
	switch (n)
	{
	case 1:
	case 2:
		cout << "Ahoj" << endl;
		break;
	case 22:
		cout << "Nazdar" << endl;
		break;
	case 3:
		cout << "Uctivá poklona" << endl;
		break;
	default:
		cout << "Dobrý den" << endl;
	}
}

int main()
{
	pozdrav(2);
}