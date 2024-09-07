#include "seznam.h"

prvek* d = NULL;

void vytvor()
{
	d = vytvor_d();
	cout << "Denik byl vytvoren." << endl;
	cekani();
}

prvek* vytvor_d()
{
	prvek* d = new prvek();
	d->pred = NULL;
	d->dalsi = NULL;
	return d;
}

void uloz()
{
	if (d == NULL)
	{
		cout << "Denik neni vytvoren." << endl;
		cekani();
	}
	else
	{
		ofstream file;
		file.open("text.txt");
		while (d->dalsi != NULL)
		{
			file << d->autor << " " << d->titul << " " << d->pocet << " " << d->rok << " " << char(d->zanr);
			d = d->dalsi;
		}
		while (d->pred != NULL)
		{
			d = d->pred;
		}
		file.close();
		cekani();
	}
}

void nacti()
{
	zrus_denik();
	ifstream file;
	file.open("text.txt");
	d = vytvor_d();
	while (!(file.eof()))
	{
		d->dalsi = new prvek();
		d->dalsi->pred = d;
		char a;
		file >> d->autor >> d->titul >> d->pocet >> d->rok >> a;
		d->zanr = (zanr)a;
		d = d->dalsi;
	}
	d = d->pred;
	free(d->dalsi);
	d->dalsi = NULL;
	while (d->pred != NULL)
	{
		d = d->pred;
	}
	file.close();
	cekani();
}

void vloz()
{
	if (d == NULL)
	{
		cout << "Denik neni vytvoren." << endl;
		cekani();
	}
	else
	{
		while (d->dalsi != NULL)
		{
			d = d->dalsi;
		}
		prvek* zaznam = new prvek();
		zaznam->dalsi = NULL;
		zaznam->pred = d;
		cout << "Napiste, prosim, autora: ";
		cin >> d->autor;
		cout << "Napiste, prosim, titul knihy: ";
		cin >> d->titul;
		cout << "Napiste, prosim, rok vydani knihy: ";
		cin >> d->rok;
		cout << "Napiste, prosim, zanr knihy: " << endl;
		cout << "(Detektivky = 'D', Thrillery = 'T', Horory = 'H', Fantasy = 'F', Westerny = 'W')" << endl;
		char z;
		cin >> z;
		d->zanr = (zanr)z;
		cout << "Napiste, prosim, pocet stran v knize: ";
		cin >> d->pocet;
		d->dalsi = zaznam;
		while (d->pred != NULL)
		{
			d = d->pred;
		}
		cout << "Zaznam byl vlozen." << endl;
		cekani();
	}
}

void vypis()
{
	cout << endl;
	int i = 1;
	if (d == NULL)
	{
		cout << "Denik neni vytvoren." << endl;
		cekani();
	}
	else 
	{
		while (d->dalsi != NULL)
		{
			cout << "Autor: " << d->autor << endl;
			cout << "Titul: " << d->titul << endl;
			cout << "Zanr: " << char(d->zanr) << " (Detektivky = 'D', Thrillery = 'T', Horory = 'H', Fantasy = 'F', Westerny = 'W') " << endl;
			cout << "Rok vydani: " << d->rok << endl;
			cout << "Pocet stran: " << d->pocet << endl;
			cout << endl;
			i++;
			d = d->dalsi;
		}
		while (d->pred != NULL)
		{
			d = d->pred;
		}
		cekani();
	}
}

void hledej()
{
	if (d == NULL)
	{
		cout << "Denik neni vytvoren." << endl;
		cekani();
	}
	else
	{
		string autor, titul;
		cout << "Napiste, prosim, autora a titul knihy, kterou chcete vyhledavat: ";
		cin >> autor >> titul;
		int i = 1;
		while (d->dalsi != NULL)
		{
			if (d->autor == autor && d->titul == titul)
			{
				cout << "Autor: " << d->autor << endl;
				cout << "Titul: " << d->titul << endl;
				cout << "Zanr: " << char(d->zanr) << " (Detektivky = 'D', Thrillery = 'T', Horory = 'H', Fantasy = 'F', Westerny = 'W') " << endl;
				cout << "Rok vydani: " << d->rok << endl;
				cout << "Pocet stran: " << d->pocet << endl;
				cout << endl;
			}
			i++;
			d = d->dalsi;
		}
		cekani();
	}
}

void vymaz_zaznam() 
{
	if (d == NULL)
	{
		cout << "Denik neni vytvoren." << endl;
		cekani();
	}
	else
	{
		string atr, ttl;
		cout << "Napiste, prosim, autora a titul knihy, kterou chcete smazat: ";
		cin >> atr >> ttl;
		while (d->dalsi != NULL) 
		{
			if (d->autor == atr && d->titul == ttl)
			{
				if (d->pred == NULL && d->dalsi->dalsi== NULL)
				{
					free(d);
					d = new prvek();
					d->dalsi = NULL;
					d->pred = NULL;
					break;
				}
				if (d->pred == NULL && d->dalsi->dalsi != NULL)
				{
					d = d->dalsi;
					free(d->pred);
					d->pred = NULL;
				}
				if (d->dalsi->dalsi == NULL && d->pred != NULL)
				{
					free(d->dalsi);
					d = d->pred;
					d->dalsi = new prvek();
					d->dalsi->dalsi = NULL;
					d->dalsi->pred = d;
				}
				if (d->pred != NULL && d->dalsi->dalsi != NULL)
				{
					prvek* prom = d;
					d->pred->dalsi = d->dalsi;
					d->dalsi->pred = d->pred;
					d = d->dalsi;
					free(prom);
				}
			}
			if (d->dalsi != NULL)
			{
				d = d->dalsi;
			}
		}
		while (d->pred != NULL)
		{
			d = d->pred;
		}
		cout << "Zaznam byl smazan." << endl;
		cekani();
	}
}
void vymaz_vsechny_zaznamy()
{
	if (d == NULL)
	{
		cout << "Denik neni vytvoren." << endl;
		cekani();
	}
	else
	{
		zrus_denik();
		d = vytvor_d();
		cout << "Zaznamy byly smazany." << endl;
		cekani();
	}

}

void zrus_denik()
{
	if (d == NULL)
	{
		cout << "Denik neni vytvoren." << endl;
		cekani();
	}
	else
	{
		prvek* prom = d;
		while ((prom = d) != NULL)
		{
			d = d->dalsi;
			free(prom);
		}
	}
}

void cekani()
{
	cout << endl << "Stisknete, prosim, libovolne cislo...";
	_getch();
}