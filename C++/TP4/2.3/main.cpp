#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;
void byName(vector<string>& data);
void byPhone(vector<string>& data);

int main()
{

    string line;
    vector<string> data;

    ifstream  file("file.txt");
    int opc;

    //Preenche o vetor com os dados no arquivo
    while(getline(file, line))
    {
        data.push_back(line);
    }

    //Menu
    do
    {
        cout << "- Lista Telefonica -" << endl << endl;

        cout << "1 - Busca por nome" << endl;
        cout << "2 - Busca por telefone" << endl;
        cout << "3 - Sair" << endl;
        cout << endl << "Opcao: ";
        cin >> opc;

        if(opc==1) byName(data);
        else if(opc==2) byPhone(data);
        else if(opc==3) exit(1);
        else
        {
            cout << "Opcao invalida!" << endl;
            system("pause");
            system("cls");
        }

    }
    while(true);

    return 0;
}

//Busca por nome
void byName(vector<string>& data)
{

    system("cls");

    string busca;
    multimap<string, string> m;
    //Armazena um par de valores de qualquer tipo, nesse caso 2 multimaps
    pair<multimap<string, string>::iterator, multimap<string, string>::iterator> ppp;

    for(int i = 0; i < data.size(); i++)
    {
        //data[i] - A chave do multimap, ou seja o nome da pessoa
        //data[i+1] e data[i+2] são os valores associados a essa chave
        // ou seja, o endereço e o telefone
        m.insert(pair<string, string>(data[i], data[i+1]));
        m.insert(pair<string, string>(data[i], data[i+2]));
        i = i+2;
    }

    cout << "Busca por nome: ";
    fflush(stdin);
    getline(cin , busca);
    //Busca o nome correspondente, apenas o nome completo
    ppp = m.equal_range(busca);

    for (multimap<string, string>::iterator it2 = ppp.first; it2 != ppp.second; ++it2)
    {
        //Impressao da busca
        cout << (*it2).second << endl;
    }
    system("pause");
    system("cls");
    return;
}

void byPhone(vector<string>& data)
{

    system("cls");

    map<string, string> m;
    string busca;

    for(int i = 0; i < data.size(); i++)
    {
        //insere as informacoes contidas em data, que veio do arquivo, no map
        //Como a chave e o numero de telefone, o nome e o endereco foram concatenados
        m.insert(pair<string,string>(data[i+2],data[i]+"\n"+data[i+1]));
        i = i+2;
    }

    cout << "Busca por telefone: ";
    fflush(stdin);
    getline(cin , busca);
    cout << m[busca] << endl;

    system("pause");
    system("cls");
    return;
}
