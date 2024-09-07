#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstring>

using namespace std;

/*
int main()
{
    ifstream file;
    string line;
    file.open("text.txt");
    if (!file.eof())
    {
        getline(file, line);
    }
    int counter = 0;
    int max_word = -1;
    int len = line.length(); 
    string max = " ";
    string counter_word = " ";

    for (int i = 0; i < len; i++)
    {
        if (line[i] != ' ')
        {
            counter++;
        }

        if (line[i] == ' ' || i == len - 1)
        {
            if (counter > max_word)
            {
                max_word = counter;
                
                if (i == len - 1)
                    max = line.substr(i + 1 - max_word, max_word);
                else
                    max = line.substr(i - max_word, max_word);
            }
            counter = 0;
        }
    }
    cout << max << endl;
}
*/

/*int main()
{
    ifstream file;
    string line;
    file.open("text.txt");
    istringstream input("A a a a b b b c c c c c c c c");
    map<string, int> kolik;
    string slovo;
    decltype(kolik)::const_iterator nejfrequent;
    while (input >> slovo)
    {
        auto iterator = kolik.emplace(slovo, 0).first;
        ++iterator->second;
        if (kolik.size() == 1 || iterator->second > nejfrequent->second)
            nejfrequent = iterator;
    }
    cout << "Slovo '" << nejfrequent->first << "' je nejfrekquentejsi" << endl;
    file.close();
}*/

int main()
{
    ifstream file;
    string line;
    int lines = 1, words = 1, chars = 1, max = 0;
    char ch, f1[50], f2[50];
    file.open("text.txt");
    while (!file.eof())
    {
        getline(file, line);
        cout << line << endl;
    }
    file.close();
    file.open("text.txt");
    file.get(ch);
    while (file) 
    {
        if (ch == '\n')
        {
            lines++;
        }
        else if (ch == ' ')
        {
            words++;
        }
        else
        {
            chars++;
        }
        file.get(ch);
    }
    /*while (file)
    {
        file >> f1;
        if (max < strlen(f1))
        {
            max = strlen(f1);
            strcpy(f2, f1);
        }
    }*/
    file.close();
    cout << lines << endl;
    cout << words << endl;
    cout << chars << endl;
//    cout << f2 << endl;
}