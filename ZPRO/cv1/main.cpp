#include <iostream>

using namespace std;

int main()
{
    int i = 1;
    int imax = 10;
    int f = 2;
    while (i <= imax)
    {
        f= f*i;
        i++;
    }

    cout << "10 factorial je " << f << endl;


    /* string name;
    cout << "zadej jmeno tohot cloveka: " << endl;
    getline(cin, name);
    cout << "Ahoj, " << name << endl;

    string name = "Petr";
    string asw1 = ", mas hezky vek.";
    string asw2 = ", na 20 nevzpadas, mas hezky vek.";
    int age = 20;

    cout << "Jsem " << name << " a je mi " << age << " let." << endl;
    cout << name << asw2 << endl; */
    /* double x;
    double y;
    cout << "Vkladej x = " << endl;
    cin >> x;
    cout << "Vkladej y = " << endl;
    cin >> y;
    double z = x / y;

    cout << "Podil x a y je " << z << endl; */

    // cout << "Hello world!" << endl;
    // cout << "Hello world!" << endl;
    // cout << "Hello world!" << endl;
    return 0;
}
