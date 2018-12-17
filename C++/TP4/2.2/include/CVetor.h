#ifndef CVETOR_H
#define CVETOR_H

#include <iostream>
namespace DataStructures
{
class CVetor
{
private:
    int *pointerElements;   //Ponteiro para os elementos
    int Size; //Tamanho alocado para o vetor

public:
    void printElements();
    int getSize() const;
    void insertElement(int element, int position);
    CVetor(int numberElementsAlloc = 0);
    CVetor(const CVetor& copyObject);
    int getElement(int i) const;

    //Sobrecarga de Operadores
    CVetor operator+ (const CVetor& sumVector) const;
    CVetor operator- (const CVetor& subVector) const;
    int operator* (const CVetor& multiVector) const;
    CVetor operator/ (const CVetor& divVector) const;
    CVetor operator= (const CVetor& attVector);
    CVetor operator% (const CVetor& multiVector) const;
    CVetor operator%= (const CVetor& multiVector);
    CVetor operator+= (const CVetor& sumVector) const;
    CVetor operator-= (const CVetor& subVector) const;
    CVetor operator/= (const CVetor& divVector) const;
    int& operator[] (const int i) const;
    int& operator() (const int i) const;
    friend std::ostream& operator<<(std::ostream& output, const CVetor& flowOut);
    friend std::istream& operator>>(std::istream& input, CVetor& flowIn);
    //-----
    ~CVetor();

private:
    bool allocVector(int numberElements);
    bool reallocVector(int numberElements);
    bool reallocVectorNull(int numberElements);

};
}
#endif // CVETOR_H
