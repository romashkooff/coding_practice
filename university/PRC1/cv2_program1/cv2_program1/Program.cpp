#include <iostream>

using namespace std;

void swapRef(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

void swapPtr(int* pa, int* pb) {
	int c = *pa;
	*pa = *pb;
	*pb = c;
}

int main() {
	int x = 1, y = 2;
	cout << "Pred vymenou: x = " << x << ", y = " << y << endl;
	swapPtr(&x, &y);
	cout << "Po vymene: x = " << x << ", y = " << y << endl;
	return 0;
}