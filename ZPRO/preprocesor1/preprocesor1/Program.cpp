#include <iostream>

using namespace std;

#define mocnina(x) ((x)*(x))

#define TISK(x) cout << "Funkce: " << __func__ << " " #x " = " << x << endl

#define DATUM(typ) struct datum_ ## typ {typ den, mesic, rok;}

DATUM(int);

//#undef mocnina

/*#define N 0;

#if (N > 5) && (N < 10)
void ladeni()
{
	cout << "ladime" << endl;
}
#elif N < 5
void ladeni(){}
#else
void ladeni() { cout << "Trhni si nohou" << endl; }
#endif */

int moc(int x)
{
	TISK(x);
	return x * x;
}

int main()
{
	ladeni();
	int a = 5;
	TISK(a);
	cout << mocnina(a+1) << endl;
	TISK(a + 1);
	// cout << 5 * 5 << endl;
	cout << mocnina(++a) << endl;
	a = 5;
	cout << moc(++a) << endl;
	TISK(a);
}