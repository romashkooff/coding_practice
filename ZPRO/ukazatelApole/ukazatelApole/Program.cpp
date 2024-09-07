#include <iostream>

using namespace std;

struct datum
{
	int den, mesic, rok;
};

void vypis(int *A, int delka)
{
	for (int i = 0; i < delka; i++)
	{
		cout << A[i] << ", ";
	} 
	cout << endl;
}

char txt[] = "Ahoj";
const char* p = "Nazdar";

size_t delka(const char* p)
{
	char* pom = (char*)p;
	while (*pom)
	{
		pom++;
	}
	return pom - p;
}

void nastav(datum* d)
{
	(*d).den = 1;
	d->mesic = 1;
	d->rok = 2000;
}

int main()
{
	void* pv;
	datum d;
	nastav(&d);
	pv = &d;
	(datum*)pv = d;
	int A[]{ 1,2,3,4 };
	for (int i : A)
	{
		cout << i << ", ";
	}
	cout << endl;
	vypis(A, sizeof(A) / sizeof(int));
	cout << delka(txt) << endl;
	cout << delka(p) << endl;
}