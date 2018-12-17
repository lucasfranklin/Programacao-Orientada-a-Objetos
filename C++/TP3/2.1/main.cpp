#include <iostream>
#include "include/CVetor.h"

using namespace std;
using namespace DataStructures;

int main()
{
    CVetor A(3), B(3), C;
    int scalar;

    cout << "CVetor: " << endl << endl;

    A[0] = 1;
    A[1] = 2;
    A[2] = 3;

    B[0] = 2;
    B[1] = 4;
    B[2] = 6;

    cout << "Elementos A: " << A;
    cout << "Elementos B: " << B;

    C = A+B;

    cout << "Soma A+B: " << C;

    C = A-B;

    cout << "Subtracao A-B: " << C;

    scalar = A*B;

    cout << "Produto Escalar A*B: " << scalar << endl;

    C = A%B;

    cout << "Produto Vetorial A%B: " << C;

    C = B/A;

    cout << "Divisao B/A: " << C;

    return 0;
}
