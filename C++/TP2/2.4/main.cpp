#include <iostream>
#include "include/CWindowSingleton.h"

using namespace std;

int main()
{
    CWindowingleton *instancePointer;

    //Cria o objeto usando o construtor privado para setar os atributos
    instancePointer = CWindowingleton::Instance(10,20,30,40);

    //Invoca o método para imprimir os atributos do novo objeto
    instancePointer->show();

    //Mostra que após o objeto criado outro não pode ser instanciado
    CWindowingleton::Instance(99,99,99,99)->show();

    //Mostra que não é criado um novo objeto e seus atributos não são resetados pelo construtor
    CWindowingleton::Instance(0,0,0,0)->show();

    //Modifica atributos a partir de metodos "set"
    instancePointer->move(1,2);


    //Obtem os atributos a partir de metodos "get"
    cout << "Tipo de fonte do canvas: " << CWindowingleton::Instance()->getCanvasFontType();

    return 0;
}
