#include <iostream>
#include <string>

using namespace std;

string decohex(int dec) { 
    string hex = "";

    if (dec == 0) 
    {
        return "0";
    }

    char hex_znaky[] = "0123456789ABCDEF";

    while (dec > 0) 
    {
        int zbytek = dec % 16;
        hex = hex_znaky[zbytek] + hex;
        dec = dec / 16;
    }
    return hex;
}

int main() {
    int dec_in;

    cout << "Napiste, prosim, cele cislo (v desitkove soustave): ";
    cin >> dec_in;

    string hex_out = decohex(dec_in);
    cout << "Hexadecimal: 0x" << hex_out << endl;
}
