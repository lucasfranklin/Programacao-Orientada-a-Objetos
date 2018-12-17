#ifndef CONTAINER_H
#define CONTAINER_H
#include "Seq.h"

class Container
{
private:
    //Vetor que aponta para qualquer tipo de sequencia
    std::vector<Seq*> Sequences;
    int Size;

public:
    Container();
    void insert(Seq& newSeq);
    //Imprime todas as sequencias ou em um intervalo
    void print(int begin = 1, int end = -1);
    //Imprime elemento
    void printElement(int position);
    virtual ~Container();

};

#endif // CONTAINER_H
