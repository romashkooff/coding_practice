#include <iostream>
#include <utility>
using namespace std;

int faktorial(int n)
{
	int vysledek = 1;
	for (int i = 2; i <= n; i++)
	{
		vysledek *= i;
	}
	return vysledek;
}

int A[]{ 1,2,3,4,5,6,7,8,9 };

void otoc_pole(int B[], int delka)
{
	for (int i = 0, j = delka -1; i < j; i++, j--)
	{
		/*int c = B[i];
		B[i] = B[j];
		B[j] = c;*/
		swap(B[i], B[j]);
	}
}

void vypis(int B[], int delka)
{
	for (int i = 0; i < delka; i++)
	{
		cout << B[i] << ", ";
	}
	cout << endl;
}

double e(double eps)
{
	double soucet = 2;
	int i = 1;
	double scitanec = 1;
	do
	{
		i++;
		scitanec /= i;
		soucet += scitanec;
	} while (scitanec > eps);
	return soucet;
}

int main()
{
	cout << faktorial(5) << endl;
	//vypis(A, sizeof(A) / sizeof(int));
	for (int i : A)
	{
		cout << A[i] << ", ";
	}
	cout << endl;
	otoc_pole(A, sizeof(A) / sizeof(int));
	vypis(A, sizeof(A) / sizeof(int));
	cout << e(1e-5) << endl;
}