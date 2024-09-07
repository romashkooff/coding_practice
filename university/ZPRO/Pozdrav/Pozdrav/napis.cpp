#include <iostream>
#include "napis.h"
using namespace std;

Napis::Napis(string _text)
{
	text = _text;
}

void Napis::vypis()
{
	cout << text << endl;
	cout << text.length() << endl;
}
