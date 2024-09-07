#include <iostream>

using namespace std;

// void flatterer();
int factorial(int n);

int main()
{
	int c;
	cout << "Zadej cislo n: ";
	cin >> c;
	cout << "Jeho faktorial je: " <<  factorial(c) << endl;
	return 0;
}

int factorial(int n)
{
	if (n == 0 || n == 1)
	{
		int f = 1;
	}
	else
	{
		int f = 1;
		int i = 1;
		while (i <= n)
		{
			f = f * i;
			i++;
		}
		return f;
	}
}

/*
void flatterer()
{
	string name;
	cout << "Enter your name: ";
	cin >> name;
	int age;
	cout << "Enter your age: ";
	cin >> age;
	if (age < 20)
	{
		cout << name << ", you are very young!" << endl;
	}
	else
	{
		cout << name << ", you are still very young!" << endl;
	}
}
*/