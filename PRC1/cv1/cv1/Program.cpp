#include <iostream>;
using namespace std;

int gcd(int a, int b) {
	int m = 0;
	while (b != 0) {
		m = a % b;
		a = b;
		b = m;
	}
	return a;
}

int main(){
	int x, y, g;
	cout << "Program pro vypocet nsd" << endl;
	cout << "Zadejte dve cisla: ";
	cin >> x >> y;
	g = gcd(x, y);
	cout << "nsd(" << x << ", " << y << ") = " << g << endl;
	return 0;
}