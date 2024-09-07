#ifndef __SEZNAM_H__
#define __SEZNAM_H__

#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <fstream>
#include <stdlib.h>
using namespace std;
enum zanr { Detektivky = 'D', Thrillery = 'T', Horory = 'H', Fantasy = 'F', Westerny = 'W' };

struct prvek
{
	string autor;
	string titul;
	zanr zanr;
	string rok;
	int pocet;
	prvek* dalsi;
	prvek* pred;
};

void vytvor();	// 1. Vytváří nový deník 
prvek* vytvor_d(); 
void uloz(); // 2. Deník ukládá do souboru
void nacti(); // 3.	Deník načítá ze souboru
void vloz(); // 4. Vkládat jednotlivé záznamy
void hledej(); // 5. Vyhledává záznamy podle autora a titulu
void vymaz_zaznam(); // 6. Maže záznamy podle autora a titulu
void vymaz_vsechny_zaznamy();	// 7. Vymazuje všechny záznamy
void zrus_denik(); // 8. Zcela zrušit deník
void cekani();
void vypis();

#endif // !__SEZNAM_H__