#include "../include/EPosMatrix.h"
#include <iostream>

using namespace std;

void EPosMatrix::msg()
{
    cout << "Tratamento de Erro" << endl << "Posicao nao existente, erro na linha " << nLine << "." << endl << endl;
    return;
}


EPosMatrix::~EPosMatrix()
{
    //dtor
}
