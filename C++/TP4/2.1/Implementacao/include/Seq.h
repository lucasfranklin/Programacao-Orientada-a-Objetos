#ifndef Seq_H
#define Seq_H

#include <iostream>
#include <vector>

//Classe generica para sequencias
class Seq
{

public:
    virtual const unsigned long int elem(int i);
    //Metodo geral de impresao, imprime todos os elemntos da sequencia ou um intervalo
    virtual const std::ostream& print(std::ostream& os, int begin = 0, int end = -1);
    virtual const int length();
    friend const std::ostream& operator<< (std::ostream& os, Seq& outObj);
    virtual ~Seq();

protected:
    //Metodo virtual puro que gera as sequencias
    virtual void gen_elements(int i) = 0;
    //Metodo virtual puro que retorna o ponteiro para a sequencia
    virtual const std::vector<unsigned long int>& returnPoniterElement() = 0;

};

#endif // Seq_H
