#include <iostream>
#include <vector>
#include "include/Matriz.h"

using namespace std;

int main()
{
    vector<double> vetTest(3);
    vetTest[0] = 1;
    vetTest[1] = 2;
    vetTest[2] = 3;

    string nomeArquivo = "matrizC.txt";

    Matriz A("file.txt");
    Matriz B;
    Matriz C;

    cout << "Matriz A(2x3):" << endl;
    if(!A.getMatrix()) cout << "Matriz nao alocada!" << endl;

    cout << endl << "Multiplicacao - A(2x3) x vetTest[1,2,3](3x1): " << endl;
    B.matrixMultiplication(A, vetTest);
    if(!B.getMatrix()) cout << "Matriz nao alocada!" << endl;

    cout << endl << "Soma - A(2x3) + A(2x3):" << endl;
    C.matrixSum(A,A);
    if(!C.getMatrix()) cout << "Matriz nao alocada!" << endl;

    cout << endl << "Gravando matriz em arquivo..." << endl;
    C.grava(nomeArquivo);

    return 0;
}
