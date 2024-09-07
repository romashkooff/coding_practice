#include <iostream>

#include "seznam.h"
using namespace std;

void vytvor(seznam& s)
{
	s.hlava = s.zarazka = new prvek{ NULA, nullptr };
	s.velikost = 0;
}

void vloz_na_zacatek(seznam& s, T co)
{
	s.hlava = new prvek{ co, s.hlava };
	s.velikost++;
}

void vloz_na_konec(seznam& s, T co)
{
	s.zarazka->data = co;
	s.zarazka->dalsi = new prvek{ co, nullptr };
	s.zarazka = s.zarazka->dalsi;
	s.velikost++;
}

void odstran_prvni(seznam& s)
{
	auto pom = s.hlava;
	s.hlava = s.hlava->dalsi;
	delete pom;
	s.velikost--;
}

prvek* najdi(seznam* s, T co)
{
	s->zarazka->data = co;
	prvek* pom = s.hlava;
	while (pom->data != co)
	{
		pom = pom->dalsi;
	}
	if (pom == s->zarazka)
	{
		return nullptr;
	}
	else
	{
		return pom;
	}
}

void vloz_za(seznam& s, T co, prvek* za_ktery)
{
	za_ktery->dalsi = new prvek{ co, za_ktery->dalsi };
}

void vypis(seznam& s)
{
	for (prvek* pom = s.hlava; pom != s.zarazka; pom = pom->dalsi)
	{
		cout << pom->data << ", ";
	}
	cout << endl;
}

void odstran_za(seznam& s, prvek* za_kterym)
{
	auto odstranovany = za_kterym->dalsi;
	za_kterym->dalsi = odstranovany->dalsi;
	delete odstranovany;
}

void odstran(seznam& s, prvek* ktery)
{
	if (ktery->dalsi == s.zarazka) //n Je-li odstranovan posledni prvek
	{
		s.zarazka = ktery;
		delete ktery->dalsi;
		ktery->dalsi = nullptr;
	}
	else
	{
		ktery->data = ktery->dalsi->data;
		odstran_za(s.ktery);
	}
}

void najdi_nejmensi(seznam& s)
{
	prvek* nejmensi = s.hlava;
	T hodnota = nejmensi->data;
	prvek* pom = s.hlava;
	while (pom != s.zarazka)
	{
		if (pom->data < hodnota)
		{
			nejmensi = pom;
			hodnota = nejmensi->data;
		}
		pom = pom->dalsi;
	}
	return nejmensi;
}
