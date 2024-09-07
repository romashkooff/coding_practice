#include <iostream> 
#include<ctime> 

using namespace std;

void sortB(int cisla[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (cisla[j] > cisla[j + 1])
            {
                swap(cisla[j], cisla[j + 1]);
            }
        }            
    }        
}

void vypis(int cisla[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << cisla[i] << " ";
    cout << endl;
}



int main()
{
    srand(time(NULL));
    int cisla[10];
    for (int i = 0; i < 10; i++) 
    {
        cisla[i] = rand() % 100 + 10;
    }
    int s = sizeof(cisla) / sizeof(cisla[0]);
    sortB(cisla, s);
    cout << "Vysledek je " << endl;
    vypis(cisla, s);
}
