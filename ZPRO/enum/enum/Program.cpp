#include <iostream>
#include <math.h>



using namespace std;

enum den {Pondeli, Utery, Streda, Ctvrtek, Patek, Sobota, Nedele};
enum {Sedm = 7, Osm, Devet, Deset};
//enum pokus {Sedm, Pondeli}; //Nelze

enum class ZpusobOtevreni{Cteni, Zapis, CteniZapis};
enum class Opravneni {Cteni, Zapis, Spusteni};

int main()
{
	den dnes = Pondeli;
	//dnes = Sedm;
	cout << (den)Sedm << endl;
	ZpusobOtevreni zo = ZpusobOtevreni::Cteni;
	cout << (int)zo << endl;
}