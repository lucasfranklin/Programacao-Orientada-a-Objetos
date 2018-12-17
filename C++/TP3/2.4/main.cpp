#include <iostream>
#include "include/IntegerSet.h"

using namespace std;
using namespace Matematica;

int main()
{
    IntegerSet setA, setB, setC;

    ifstream inFile1("file1.txt");
    ifstream inFile2("file2.txt");

    inFile1 >> setA;
    inFile2 >> setB;

    cout << "Conjunto setA: ";
    cout << setA;

    cout << "Conjunto setB: ";
    cout << setB;


    setC = setA+setB;

    cout << "Uniao - C = setA+setB: " << setC;

    setC = setA&setB;

    cout << "Intercessao - C = setA&setB: " << setC;

    setC+=99;

    cout << "Insere elemento 99 em setC: " << setC;

    setC-=1;

    cout << "Remove elemento 1 em setC: " << setC;

    cout << "Compara setA==setB: ";

    if(setA==setB) cout  << "Equal!" << endl;
    else cout << "Diferente!" << endl;

    return 0;
}
