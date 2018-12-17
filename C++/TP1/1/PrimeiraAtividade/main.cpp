#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    string word;

    do
    {
        cout << "Entre com uma palavra: ";
        getline(cin, word);
        if(word.size() < 6)
        {
            cout << "Por favor, entre com uma palavra com mais de cinco (5) caracteres!";
            system("pause>null");
        }
        system("cls");
    }
    while(word.size() < 6);

    cout << word << endl;

    system("pause");
    return 0;
}
