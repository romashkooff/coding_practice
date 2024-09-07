#include "seznam.h"

int main()
{
	seznam s1;
	vytvor(s1);
	vloz_na_zacatek(s1, 4);
	vloz_na_zacatek(s1, 5);
	vloz_na_konec(s1, 10);
	/* odstran_prvni(s1); */
	auto p = najdi(s1, 4);
	vloz_za(s1, 8, p);
	vypis(s1);
	p = najdi(s1, 4);
	odstran_za(s1, p);
	vypis(s1);
	
}