#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
bool rot13Encrypt(string& fileName, bool encrypt);
bool rot13Decrypt(string& fileName);

int main()
{
    string fileName;
    int option;
    bool status;

    cout << "- Rot13 -" << endl << endl;

    cout << "Entre com o nome do arquivo(com a extensao): ";

    cin >> fileName;

    cout << endl << "1 - Emcrypt" << endl << "2 - Decrypt" << endl << endl << "Qualquer outra tecla para sair." << endl;
    cout << endl << "Opcao: ";

    cin >> option;

    if(option==1) status = rot13Encrypt(fileName, true);
    else if(option==2) status = rot13Decrypt(fileName);
    else exit(1);

    if(status) cout << "Sucesso!";
    else cout << "Erro inesperado! Verifique a existencia do arquivo.";

    return 0;
}

bool rot13Encrypt(string& fileName, bool encrypt)
{
    string line;
    ifstream inFile(fileName.c_str());

    if(!inFile) return false;

    if(encrypt) fileName.append(".crp");
    else
    {
        fileName.replace(fileName.begin()+fileName.size()-4,fileName.end(),".tzd");
    }

    ofstream outFile(fileName.c_str());

    while(getline(inFile,line))
    {
        for(int i = 0; i<=line.size(); i++)
        {
            if((line[i] > 'a' && line[i] < 'm') || (line[i] > 'A' && line[i] < 'M'))
            {
                line[i] = line[i]+13;
                outFile << (char)line[i];
            }
            else if((line[i] > 'n' && line[i] < 'z') || (line[i] > 'N' && line[i] < 'Z'))
            {
                line[i] = line[i]-13;
                outFile << (char)line[i];
            }
            else outFile << line[i];
        }
        outFile << endl;
    }

    return true;

}

bool rot13Decrypt(string& fileName)
{
    return rot13Encrypt(fileName, false);
}
