#include "../include/IntegerSet.h"

namespace Matematica
{
using namespace std;


//Uniao
IntegerSet IntegerSet::Union(const IntegerSet& setA) const
{
    IntegerSet resultSet;

    for(int i = 0; i<sizeof(Set)/sizeof(bool); i++)
    {
        if(Set[i]== true || setA.Set[i] == true) resultSet.Set[i] = true;
    }
    return resultSet;
}

//Intercessao
IntegerSet IntegerSet::Intersection(const IntegerSet& setA) const
{
    IntegerSet resultSet;

    for(int i = 0; i<sizeof(Set)/sizeof(bool); i++)
    {
        if(Set[i]== true && setA.Set[i] == true) resultSet.Set[i] = true;
    }
    return resultSet;
}

//Insere elemento
void IntegerSet::insertElement(const int element)
{
    Set[element] = true;
}


//remove elemento
void IntegerSet::removeElement(const int element)
{
    Set[element] = false;
}

//Leitura de arquivo
void IntegerSet::readFileElements(const string fileName)
{
    int element;

    ifstream inFile(fileName.c_str());
    while(inFile >> element)
    {
        insertElement(element);
    }
}

//Verifica se e igual
bool IntegerSet::equalElements(const IntegerSet& setA) const
{
    if (equal(Set, Set + sizeof(Set)/sizeof (*Set), setA.Set)) return true;  //Compara os elementos do veotr
    else return false;
}

//Sobrecarga do operador de adicao, faz a uniao de 2 conjuntos
const IntegerSet IntegerSet::operator+ (const IntegerSet& unionSet) const
{
    return Union(unionSet);
}

//Sobrecarga de operador, faz a intercessao de 2 conjuntos
const IntegerSet IntegerSet::operator& (const IntegerSet& intersectionSet) const
{
    return Intersection(intersectionSet);
}

//Sobrecarga de operador, insere um elemento no conjunto
const IntegerSet& IntegerSet::operator+= (const int newElement)
{
    insertElement(newElement);
    return *this;
}

//Sobrecarga de operador, remove um elemento do conjunto
const IntegerSet& IntegerSet::operator-= (const int Element)
{
    removeElement(Element);
    return *this;
}

//Sobrecarga de operador, verifica se 2 conjuntos sao iguais
bool IntegerSet::operator== (const IntegerSet& compareSet) const
{
    return equalElements(compareSet);
}

//Sobrecarga do operador de fluxo de entrada
const ostream& operator<<(ostream& output, const IntegerSet& flowOut)
{

    for(int i = 0; i<sizeof(flowOut.Set)/sizeof(bool); i++)
    {
        if(flowOut.Set[i]==true) output << i << " ";
    }
    cout << endl;
    return output;
}

//sobrecarga do operador de fluxo de saida
const istream& operator>>(istream& input, IntegerSet& flowIn)
{

    int tempElement;

    while(input >> tempElement) if(tempElement>=0 || tempElement<=0) flowIn.insertElement(tempElement);

    return input;
}

//Destrutor
IntegerSet::~IntegerSet()
{
    //dtor
}
}
