#include <iostream>
#include <cmath>
using namespace std;

const float PI = 3.14159;

/* int max(int a, int b)
    {
    if (a>b)
    {
        return a;
    }
    else
    {
        if (a<b)
        {
            cout << b << endl;
        }
        else
        {
            cout << "a=b" << endl;
        }
    }
}
*/
float mocnina(float x, int n) {
    float vysledek = 1.0;

    while (n > 0) {
        vysledek = vysledek * x;
        n--;
    }

    return vysledek;
}


float povrchKoule(float r) {
    float vysledek = 4 * PI * mocnina(r, 2);
    return vysledek;
}

float objemKoule(float r) {
    return 4.0 / 3.0 * PI * mocnina(r, 3);
}


int main()
{
    /* int x, y;
    cout << "Program pro vzpocet maximalneho cisla" << endl;
    cout << "Zadejte prosim cislo a: " << endl;
    cin >> x;
    cout << "Zadejte prosim cislo b: " << endl;
    cin >> y;
    int m = max(x,y);
    cout << m << endl;
    float x=0.0;
    while (abs (x-1.0) > 0.0001) {
        cout << x << endl;
        x = x+0.1;


    int i = 1;
    while (i <= 10)
    {
        cout << i << endl;
        i = i+1;
    } */

    float r; // polomer koule
    float s, v; // povrch a objem koule
    cout << "Program pro vzpocet objemu a povrchu koule" << endl;
    cout << "Zadejte prosim polomer koule [m]: " << endl;
    cin >> r;


    if (r >= 0)
    {
        s = povrchKoule(r);
        v = objemKoule(r);
        cout << "Povrch koule je " << v << "m2\n";
        cout << "Objem koule je " << s << "m3\n";
    }
    else
    {
        cout << "Uvedli jste spante cislo" << endl;
        return 1;
    }
    return 0;
}