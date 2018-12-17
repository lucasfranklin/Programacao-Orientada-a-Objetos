#ifndef INTEGERSET_H
#define INTEGERSET_H

#include <string>
#include <iostream>
#include <fstream>

class IntegerSet
{
private:
    bool Set[101];

public:
    IntegerSet();
    void Union(const IntegerSet& setA, const IntegerSet& setB);
    void Intersection(const IntegerSet& setA, const IntegerSet& setB);
    void insertElement(const int element);
    void removeElement(const int element);
    void getElements() const;
    void readFileElements(const std::string fileName);
    bool equalElements(const IntegerSet& setA, const IntegerSet& setB) const;
    ~IntegerSet();
};

#endif // INTEGERSET_H
