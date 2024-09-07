#include "seznam.h"

int main()
{	
	bool vychod = false;
	while (!vychod)
	{
		system("cls");
		cout << "1. Vytvorit novy denik" << endl;
		cout << "2. Denik ulozit do souboru" << endl;
		cout << "3. Denik nacist ze souboru" << endl;
		cout << "4. Vlozit novy zaznam" << endl;
		cout << "5. Hledat zaznam podle autora a titulu" << endl;
		cout << "6. Vymazat zaznam podle autora a titulu" << endl;
		cout << "7. Vymazat vsechi zaznamy" << endl;
		cout << "8. Zcela zrusit denik" << endl;
		cout << "9. Ukoncit program" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			vytvor();
			break;
		case 2:
			uloz();
			break;
		case 3:
			nacti();
			break;
		case 4:
			vloz();
			break;
		case 5:
			hledej();
			break;
		case 6:
			vymaz_zaznam();
			break;
		case 7:
			vymaz_vsechny_zaznamy();
			break;
		case 8:
			zrus_denik();
			break;
		case 9:
			vychod = true;
			break;
		case 777:
			vypis();
			break;
		default:
			cout << "Napiste, prosim, cislo od 1 do 9." << endl;
			cekani();
		}
	}
}