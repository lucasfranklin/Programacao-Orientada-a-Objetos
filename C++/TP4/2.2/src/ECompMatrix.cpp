#include "../include/ECompMatrix.h"
#include <iostream>

using namespace std;

void ECompMatrix::msg()
{
    cout << "Tratamento de Erro" << endl << "Matrizes incompativeis, erro na linha " << nLine << "." << endl << endl;
    return;
}

ECompMatrix::~ECompMatrix()
{
    //dtor
}
