#ifndef RACIONAL_H
#define RACIONAL_H

#include <cmath>
#include <iostream>
#include <string>

class Racional
{
private:
    int numerator;
    int denominator;

public:
    Racional(int newNumerator = 0, int newDenominator = 1);
    int setSum(const Racional& racionalA, const Racional& racionalB);
    int setSubtraction(const Racional& racionalA, const Racional& racionalB);
    int setMultiplication(Racional& racionalA, Racional& racionalB);
    int setDivsion(Racional& racionalA, Racional& racionalB);
    double getRacionalDouble() const;
    void getRacional() const;
    ~Racional();

private:
    void simpliflyRacional(int *simplifiedNumerator,int *simplifiedDenominator);
    int maxCommonFactor(int& simplifiedNumerator, int& simplifiedDenominator);
    int racionalOperation(const Racional& racionalA, const Racional& racionalB, const std::string operationType);
    int racionalMultiplication(const int& numeratorA,const int& denominatorA, const int& numeratorB, const int& denominatorB);
    void getSenominaroErrorMessage();
};

#endif // RACIONAL_H
