#include <iostream>
#include <vector>
#include "include\Racional.h"

using namespace std;


int main()
{
    Racional fractionA(12,15);
    Racional fractionB(14,20);
    Racional fractionC;

    cout << "+Numeros Racionais" << endl << endl;
    cout << "A: ";
    fractionA.getRacional();
    cout << "B: ";
    fractionB.getRacional();

    cout << endl << "Soma:" << endl;
    fractionC.setSum(fractionA,fractionB);
    cout << "Fracao: ";
    fractionC.getRacional();
    cout << "Decimal: ";
    fractionC.getRacionalDouble();

    cout << endl << "Subtracao:" << endl;
    fractionC.setSubtraction(fractionA,fractionB);
    cout << "Fracao: ";
    fractionC.getRacional();
    cout << "Decimal: ";
    fractionC.getRacionalDouble();

    cout << endl << "Multiplicacao:" << endl;
    fractionC.setMultiplication(fractionA,fractionB);
    cout << "Fracao: ";
    fractionC.getRacional();
    cout << "Decimal: ";
    fractionC.getRacionalDouble();

    cout << endl << "Divisao:" << endl;
    fractionC.setDivsion(fractionA,fractionB);
    cout << "Fracao: ";
    fractionC.getRacional();
    cout << "Decimal: ";
    fractionC.getRacionalDouble();

    return 0;
}

