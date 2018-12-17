#include "../include/IntegerSet.h"

using namespace std;

IntegerSet::IntegerSet()
{
    for(int i = 0; i < sizeof(Set)/sizeof(bool); i++)
    {
        Set[i] = false;
    }
}

void IntegerSet::Union(const IntegerSet& setA, const IntegerSet& setB)
{
    for(int i = 0; i<sizeof(Set)/sizeof(bool); i++)
    {
        if(setA.Set[i]== true || setB.Set[i] == true) Set[i] = true;
    }
}

void IntegerSet::Intersection(const IntegerSet& setA, const IntegerSet& setB)
{
    for(int i = 0; i<sizeof(Set)/sizeof(bool); i++)
    {
        if(setA.Set[i]== true && setB.Set[i] == true) Set[i] = true;
    }
}

void IntegerSet::insertElement(const int element)
{
    Set[element] = true;
}

void IntegerSet::removeElement(const int element)
{
    Set[element] = false;
}

void IntegerSet::getElements() const
{
    for(int i = 0; i<sizeof(Set)/sizeof(bool); i++)
    {
        if(Set[i]==true) cout << i << " ";
    }
}

void IntegerSet::readFileElements(const string fileName)
{

    int element;

    ifstream inFile(fileName.c_str());
    while(inFile >> element)
    {
        insertElement(element);
    }

}

bool IntegerSet::equalElements(const IntegerSet& setA, const IntegerSet& setB) const
{
    if (equal(setA.Set, setA.Set + sizeof(setA.Set)/sizeof (*setA.Set), setB.Set)) return true;  //Compara os elementos do veotr
    else return false;
}

IntegerSet::~IntegerSet()
{
    //dtor
}
