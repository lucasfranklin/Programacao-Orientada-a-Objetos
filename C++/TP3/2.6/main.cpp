#include <iostream>
#include <fstream>
#include "include/List.h"

using namespace std;
using namespace DataStructure;

int main()
{
    List lista, lista2, lista3;
    ofstream outputFile("test1.txt");
    ifstream inputFile("test2.txt");

    cout << "Insercao de elementos repetidos: " << "[65 1 1 1 0 0]" << endl;
    lista+=65;
    lista+=1;
    lista+=1;
    lista+=1;
    lista+=0;
    lista+=0;


    inputFile >> lista2;
    lista3 = lista2;

    cout << "Lista1: " << endl << lista3 ;
    //cout << endl << "lista2: " << endl << lista2;


    return 0;
}
