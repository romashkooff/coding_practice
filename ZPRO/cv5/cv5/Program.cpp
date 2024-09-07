#include <iostream>
using namespace std;

/*
int main()
{
	for (int i = 0; i <= 20; i++)
	{
		if (i % 3 == 0)
		{
			continue;
		}
		cout << i << endl;
	}
} 
*/

/*
bool JeSude(int n);
bool Prvocislo(int n);

int main()
{
	int n;
	cout << "Enter an integer n = ";
	cin >> n;
	JeSude(n);
	if (Prvocislo(n) == false)
	{
		cout << "Je prvocislo" << endl;
	}
}

bool JeSude(int n)
{
	if (n % 2 == 0)
	{
		cout << "n je sude" << endl;
		return true;
	}
	else
	{
		cout << "n je liche" << endl;
		return false;
	}
}

bool Prvocislo(int n)
{
	for(int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return true;
		}
		else
		{		
			return false;
			break;
		}
	}
}

*/

/*
int main()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;
	switch(n)
	{
	case 1:
		cout << "Monday" << endl;
		break;
	case 2:
		cout << "Tuesday" << endl;
		break;
	case 3:
		cout << "Wednesday" << endl;
		break;
	case 4:
		cout << "Thursday" << endl;
		break;
	case 5:
		cout << "Friday" << endl;
		break;
	case 6:
		cout << "Saturday" << endl;
		break;
	case 7:
		cout << "Sunday" << endl;
		break;
	default:
		cout << "No such a day exists!";
		break;
	}
	return 0;
}
*/

int main()
{
	char c;
	cout << "Enter a letter: ";
	cin >> c;
	if (('a' <= c) && (c <= 'z'))
	{
		cout << "You have inserted small letter" << endl;
	}
	else if (('A' <= c) && (c <= 'Z'))
	{
		cout << "You have inserted capital letter" << endl;
	}
	else if (('0' <= c) && (c <= '9'))
	{
			cout << "You have inserted a number" << endl;
	}
	cout << "ASCII code of inserted character " << (int)c << endl;
}