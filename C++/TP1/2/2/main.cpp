#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    string file, word, _search;
    int counter = 0;

    cout << "Entre com o nome do arquivo: ";
    cin >> file;
    ifstream in(file.c_str());
    cout << "Entre com uma palavra a ser procurada: ";
    cin >> _search;

    while(in >> word)
    {
        if(_search == word) counter+=1;
    }

    cout << "Numero de ocorrencias da palavra " << _search << " no arquivo: " << counter << endl;

    in.close();

    return 0;
}
