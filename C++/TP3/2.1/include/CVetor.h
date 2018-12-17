#ifndef CVETOR_H
#define CVETOR_H

#include <iostream>

//Namespace
namespace DataStructures
{
class CVetor
{
private:
    int *pointerElements;   //Ponteiro para os elementos
    int Size;               //Tamanho alocado para o vetor

public:
    void printElements();   //Imprime os elementos na tela
    int getSize() const;    //Retorna o tamanho do vetor
    void insertElement(int element, int position);  //Insere elemento na posicao desejada
    int getElement(int i) const;                    //Retorna elemento em uma determinada posicao
    CVetor(int numberElementsAlloc = 0);            //Construtor
    CVetor(const CVetor& copyObject);               //Construtor de copia
    ~CVetor();                                      //Destrutor

    //Sobrecarga de Operadores
    const CVetor operator+ (const CVetor& sumVector) const;
    const CVetor operator- (const CVetor& subVector) const;
    const int operator* (const CVetor& multiVector) const;
    const CVetor operator/ (const CVetor& divVector) const;
    const CVetor operator= (const CVetor& attVector);
    const CVetor operator% (const CVetor& multiVector) const;
    const CVetor operator%= (const CVetor& multiVector);
    const CVetor operator+= (const CVetor& sumVector) const;
    const CVetor operator-= (const CVetor& subVector) const;
    const CVetor operator/= (const CVetor& divVector) const;
    int& operator[] (const int i) const;
    int& operator() (const int i) const;
    friend const std::ostream& operator<<(std::ostream& output, const CVetor& flowOut);
    friend const std::istream& operator>>(std::istream& input, CVetor& flowIn);
    //-----


private:
    bool allocVector(int numberElements);       //Metodo para alocar o CVetor
    bool reallocVector(int numberElements);     //Realoca o vetor mantendo os valores atuais
    bool reallocVectorNull(int numberElements); //Realoca o vetor setando tudo como NULL

};


//Metoso INLINE
inline CVetor::CVetor(int numberElementsAlloc)
{
    allocVector(numberElementsAlloc);   //Contrutor inline
}
inline int CVetor::getSize() const
{
    return Size;   //Retorna tamanho
}
inline int CVetor::getElement(int i) const
{
    return pointerElements[i];   //Retorna elemento
}

}
#endif // CVETOR_H
