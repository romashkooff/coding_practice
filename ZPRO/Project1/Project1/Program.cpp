#include <iostream>
#include <utility>

using namespace std;

void prohod(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void prohod(int &&a, int &&b)
{

}

int main()
{
	int* p;
	p = new int{ 5 };
	cout << *p << endl;
	delete p;

	int n;
	n = 8;
	p = new int[n] {1, 2, 3, 4, 5};
	// int A[n];
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << ", ";
	}
	cout << endl;
	delete[] p;

	int(*q)[5] = new int[n][5]{ {1,2,3,4,5,},{},{} };
	delete[] q;

	////////////////////////

	int& r = n;
	r = 98;
	p = &r;
	*p = 100;

	int x = 8, y = 6;
	prohod(x, y);
	swap(x, y);

	int&& pr = 1 + x;
}