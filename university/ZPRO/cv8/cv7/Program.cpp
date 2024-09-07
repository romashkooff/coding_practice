#include <iostream>

using namespace std;

/*
// Predavani parametru hodnotou
void prohod(int a, int b)
{
	int c = a;
	a = b;
	a = c;
}

// Predavani parametru pomoci ukazatelu

void prohod(int* ua, int* ub)
{
	int c = *ua;
	*ua = *ub;
	*ub = c;
}

*/

void prohod(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

struct Koreny
{
	float x1, x2;
	bool realne;
};

/*
//test hloubky rekurze
void test(int x)
{
	int p[100];
	cout << x << endl;
	x++;
	test(x);
}
*/

void vytiskniKoreny(Koreny* uk)
{
	if (uk->realne)
	{
		cout << "x1 = " << uk->x1 << endl;
		cout << "x2 = " << uk->x2 << endl;
	}
	else
	{
		cout << "Rovnice name reseni!" << endl;
	}
}

void vytvorKoreny()
{
	Koreny* uk = new Koreny;
	//...
}

int main()
{
	// test(0);
	/*cout << sizeof(float) << endl;
	cout << sizeof(bool) << endl;
	cout << sizeof(Koreny) << endl;*/

	Koreny reseni = { 1,-1,true };
	vytiskniKoreny(&reseni);
	Koreny* uk = new(/*std::*/nothrow) Koreny; // vytvoreni dynamicke promenne
	if (!uk)
	{
		// alokace dynamicke promenne selhala
		return -1;
	}


	(*uk).x2 = 2;
	uk->x2 = 2;
	uk->x1 = 1;
	uk->realne = true;
	vytiskniKoreny(uk);
	vytvorKoreny();
	uk = new Koreny;

	delete uk;
	uk = nullptr;
	//vytiskniKoreny(uk);

	const int N = 10;

	int pole[N];
	// piuziti ukazatelove aritmetiky
	for (int* uk = pole; uk < &pole[N]; uk++)
	{
		*uk = 0;
	}

	for (auto i : pole)
	{
		cout << i << endl;
	}

	int x = 1;
	int y = 2;
	int& rx = x; // rx je reference/odkaz na x, cokoliv provedu s rx ve skutecnocti provadim s x
	int& ry = y;
	cout << "Pred prohozenim: x= " << x << ", y = " << y << endl;
//	prohod(&x, &y);
	prohod(x, y);
	cout << "Po prohozeni: x= " << x << ", y = " << y << endl;
	

	int a;
	int* ua = &a;
	*ua = 5;
	cout << a << endl;
	ua = nullptr; // nulovy ukazatel
	if (ua) // testujeme zda je ukazatel nenulovy
	{
		cout << *ua << endl; // deferece nuloveho ukazatele by zpusobila pad programu
	}
}