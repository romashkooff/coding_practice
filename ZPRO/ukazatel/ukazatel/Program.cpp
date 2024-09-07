#include <iostream>

using namespace std;

void vypis(int u, int v);

// Nefunguje
void prohod0(int x, int y)
{
	vypis(x, y);
	int z = x;
	x = y;
	y = z;
	vypis(x, y);
}

void prohod(int* x, int* y)
{
	int z = *x;
	*x = *y;
	*y = z;
}

void vypis(int u, int v)
{
	cout << u << ", " << v << endl;
}

int main()
{
	int a = 5, b = 6;
	/* int* ui, * uj;
	ui = &a;
	*ui = 50;
	ui = nullptr;
	*ui = 9; */

	vypis(a, b);
	//prohod0(a, b);
	prohod(&a, &b);
	vypis(a, b);


}