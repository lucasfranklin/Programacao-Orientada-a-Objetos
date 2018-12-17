#include <iostream>
#include "include/IntegerSet.h"

using namespace std;

int main()
{
    IntegerSet setA, setB, setC, setD, setE;

    setA.readFileElements("file1.txt");

    setB.readFileElements("file2.txt");

    cout << "Conjunto A: ";
    setA.getElements();

    cout << " - " << "Conjunto B: ";
    setB.getElements();

    cout << endl << endl << "Removendo o Elemento (1) do conjunto B: ";
    setB.removeElement(1);
    setB.getElements();

    cout << endl << "Inserindo o Elemento (1) no conjunto B: ";
    setB.insertElement(1);
    setB.getElements();

    cout << endl << endl << "Uniao de A e B: " << endl;
    setC.Union(setA,setB);
    setC.getElements();

    cout << endl << "Intersecao de A e B: " << endl;

    setD.Intersection(setA,setB);
    setD.getElements();

    cout << endl << "Comparacao de A com B: " << endl;

    if(setE.equalElements(setE,setA)) cout << "Sao iguais!" << endl;
    else cout << "Sao diferentes!" << endl;

    cout << "Comparacao de A com A: " << endl;

    if(setA.equalElements(setA,setA)) cout << "Sao iguais!" << endl;
    else cout << "Sao diferentes!" << endl;

    return 0;
}
