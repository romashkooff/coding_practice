#include <iostream>

using namespace std;

using T = int;

const T NULA = T{};

struct prvek {
	T data;
	prvek* dalsi;
};

struct seznam {
	prvek* hlava;
	prvek* zarazka;
};

void vytvor(seznam& s) {
	s.hlava = s.zarazka = new prvek{ NULA, nullptr };
}

void vloz_na_zacatek(seznam& s, T co) {
	s.hlava = new prvek{ co, s.hlava};
}

void vypis(seznam& s) {
	for (prvek* pom = s.hlava; pom != s.zarazka; pom = pom->dalsi) {
		cout << pom->data << endl;
	}
}

void zmen_hodnotu(seznam& s, T puvodni, T novy) {
	for (prvek* pom = s.hlava; pom != s.zarazka; pom = pom->dalsi) {
		if (pom->data == puvodni) pom->data = novy;
		//break;
		//return;
	}

}

int najdi_velikost(seznam& s) {
	int n = 0;
	for (prvek* pom = s.hlava; pom != s.zarazka; pom = pom->dalsi) {
		n++;
	}
	return n;
}

void vloz_na_konec(seznam& s, T co) {
	s.zarazka = new prvek{ co,s.zarazka };
}

bool prazdny(seznam& s) {
	return s.hlava == s.zarazka;
}

void odstran_prvni(seznam& s) {
	if (!prazdny(s)) {
		prvek* pom = s.hlava;
		s.hlava = s.hlava->dalsi;
		delete pom;
	}
}

prvek* najdi_nejmensi(seznam& s) {
	if (prazdny(s)) return nullptr;
	prvek* nejmensi = s.hlava;
	for (prvek* pom = s.hlava; pom != s.zarazka; pom = pom->dalsi) {
		if (pom->data < nejmensi->data) {
			nejmensi = pom;
		}
	}
	return nejmensi;
}

// void odstran_posledni(seznam& s) {}

int main() {
	seznam s;
	vytvor(s);
	vloz_na_zacatek(s, 2);
	vloz_na_zacatek(s, 1);
	vloz_na_zacatek(s, 3);
	vloz_na_zacatek(s, 2);
	vypis(s);
	cout << "zmen_hodnotu" << endl;
	zmen_hodnotu(s, 2, 4);
	vypis(s);
	cout << "velikost = " << najdi_velikost(s) << endl;
	odstran_prvni(s);
	vypis(s);
	return 0;
}