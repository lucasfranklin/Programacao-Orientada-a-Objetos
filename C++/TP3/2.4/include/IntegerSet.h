#ifndef INTEGERSET_H
#define INTEGERSET_H

#include <string>
#include <iostream>
#include <fstream>

namespace Matematica
{

class IntegerSet
{
private:
    bool Set[101];      //Elementos

public:
    IntegerSet();
    IntegerSet(const IntegerSet& copyObject);
    IntegerSet Union(const IntegerSet& setA) const;
    IntegerSet Intersection(const IntegerSet& setA) const;
    void insertElement(const int element);
    void removeElement(const int element);
    void printElements() const;
    void readFileElements(const std::string fileName);
    bool equalElements(const IntegerSet& setA) const;

    //Sobrecarga de operadores
    const IntegerSet operator+ (const IntegerSet& unionSet) const;
    const IntegerSet operator& (const IntegerSet& intersectionSet) const;
    const IntegerSet& operator-= (const int Element);
    bool operator== (const IntegerSet& compareSet) const;
    const IntegerSet& operator+= (const int newElement);
    const IntegerSet operator= (const int attIntegerSet);
    const friend std::ostream& operator<<(std::ostream& output, const IntegerSet& flowOut);
    const friend std::istream& operator>>(std::istream& input, IntegerSet& flowIn);
    ~IntegerSet();
};
//Metodos INLINE

//Construtor
inline IntegerSet::IntegerSet()
{
    for(int i = 0; i < sizeof(Set)/sizeof(bool); i++)
    {
        Set[i] = false;
    }
}

//Imprime os elementos
inline void IntegerSet::printElements() const
{
    for(int i = 0; i<sizeof(Set)/sizeof(bool); i++)
    {
        if(Set[i]==true) std::cout << i << " ";
    }
}

}
#endif // INTEGERSET_H
