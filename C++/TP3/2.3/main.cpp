#include <iostream>
#include <vector>
#include "include\Racional.h"

using namespace std;
using namespace Matematica;

int main()
{
    Racional A(3,2), B(3,2), C;

    cout << "Racional A: " << A << endl;
    cout << "Racional B: "<< B << endl << endl;

    C = A+B;
    cout << "Adicao - C = A+B: "<< C << endl;
    C = A-B;
    cout << "Subtracao - C = A-B: "<< C << endl;
    C = A*B;
    cout << "Multiplicacao - C = A*B: "<< C << endl;
    C = A/B;
    cout << "Divisao - C = A/B: "<< C << endl;
    double  d = 2.5;
    Racional D(2.5);
    cout << "Conversao Double x Racional - double  d = 2.5: "<< (Racional)d << endl;
    cout << "Conversao Racional x Double - D(5/2): "<< (double)D << endl;



    return 0;
}

