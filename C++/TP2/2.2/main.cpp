#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
bool wordsFile(string& fileName);
void sortWordsFile(vector<string>& vectorWords);

int main()
{
    string fileName;
    int status;

    cout << "Entre com o nome do arquivo: ";
    cin >> fileName;

    status = wordsFile(fileName);

    if(!status)
    {
        cout << endl << "Erro inesperado! Verifique a existencia do arquivo." << endl;
    }

    return 1;

}

bool wordsFile(string& fileName)
{

    vector<string> vectorWords;
    string wordAUX;

    ifstream in(fileName.c_str());

    if(!in)
    {
        return false;
    }

    cout << endl<< "+ Palavras desordenadas: " << endl;
    while(in >> wordAUX)
    {
        cout << wordAUX << endl;
        vectorWords.push_back(wordAUX);
    }

    sortWordsFile(vectorWords);

    return true;
}

void sortWordsFile(vector<string>& vectorWords){

    sort(vectorWords.begin(),vectorWords.end());

    cout << endl << "+ Palavras Ordenadas: " << endl;
    for(int i = 0; i<vectorWords.size(); i++)
    {
        cout << vectorWords[i] << endl;
    }
    return;
}
