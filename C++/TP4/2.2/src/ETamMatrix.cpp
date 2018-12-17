#include "../include/ETamMatrix.h"
#include <iostream>

using namespace std;

void ETamMatrix::msg()
{
    cout << "Tratamento de Erro" << endl << "Tamanho de matrizes diferentes, erro na linha " << nLine << "." << endl << endl;
    return;
}


ETamMatrix::~ETamMatrix()
{
    //dtor
}
