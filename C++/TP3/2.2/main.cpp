#include <iostream>
#include <vector>
#include "include/Matriz.h"

using namespace std;
using namespace Matematica;
using namespace DataStructures;

int main()
{
    int a;
    Matriz A("file.txt"), B("file.txt"), C("matrizC.txt"), D;
    CVetor cVetor(2);
    cVetor[0] = 2;
    cVetor[1] = 2;
    vector<double> vetor(2);
    vetor[0] = 0;
    vetor[1] = 0;

    cout << "Matriz A: " << endl << A;
    cout << "Matriz B: " << endl << B;
    cout << "Matriz C: " << endl << C;
    cout << "CVetor: " << endl << cVetor;
    cout << endl << "Vetor: " << endl << vetor[0] << " " << vetor[1] << endl << endl;

    D = A+B;

    cout << "D=A+B" << endl << D;

    D+=B;

    cout << "D+=B" << endl << D;

    D = A-B;

    cout << "D=A-B" << endl << D;

    D-=B;

    cout << "D-=B" << endl << D;

    D = A*C;

    cout << "D = A*C" << endl << D;

    D = A*cVetor;

    cout << "D = A*cVetor" << endl << D;

    D = A*vetor;

    cout << "D = A*vetor" << endl << D;

    cout << "Elemento (0,0) da Matriz A: " << A(0,0) << endl ;

    cout << endl << "Matriz A passado por copia:" << endl;
    D.printMatrix(A);

    return 0;
}
