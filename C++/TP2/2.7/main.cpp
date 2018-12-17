#include <iostream>
#include <fstream>
#include "include/Stack.h"

using namespace std;

int main()
{
    Stack lista;
    ofstream outputFile("test1.txt");
    ifstream inputFile("test2.txt");

    cout << "Insercao de elementos repetidos: " << "[65 1 1 1 0 0]" << endl;
    lista.insertElementOrdened(65);
    lista.insertElementOrdened(1);
    lista.insertElementOrdened(1);
    lista.insertElementOrdened(1);
    lista.insertElementOrdened(0);
    lista.insertElementOrdened(0);

    cout << endl << "Elementos na lista: " << endl;
    if(!lista.ostreamData(cout)) cout << "Lista vazia!";

    cout << endl << "Procurando pelo elemento 999 na lista: " << endl;
    if(lista.searchElement(999) != -1) cout << "Encontrado!" << endl;
    else cout << "Nao Encontrado!" << endl;

    cout << endl << "Procurando pelo elemento 1 na lista: " << endl;
    if(lista.searchElement(1) != -1) cout << "Encontrado!" << endl;
    else cout << "Nao Encontrado!" << endl;

    cout << endl << "Removendo o elemento 1 da lista..." << endl;
    if(lista.removeElement(1)) cout << "Removido com sucesso!" << endl;
    else cout << "Erro ao tentar remover o elemento!" << endl;

    cout << endl << "Elementos na lista: " << endl;
    if(!lista.ostreamData(cout)) cout << "Lista vazia!";

    cout << endl << "Escrevendo em arquivo (test1.txt)..." << endl;
    lista.ostreamData(outputFile);

    cout << endl << "Lendo do arquivo (test2.txt)..." << endl;
    lista.ifstreamData(inputFile);

    cout << endl << "Elementos na lista: " << endl;
    if(!lista.ostreamData(cout)) cout << "Lista vazia!";

    cout << endl << "Entre com valores a serem inseridos na lista, pressiona qualquer letra para terminar: " << endl;
    lista.ifstreamData(cin);

    cout << endl << "Elementos na lista: " << endl;

    lista.ostreamData(cout);
    return 0;
}
