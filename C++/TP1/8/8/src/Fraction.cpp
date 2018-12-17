#include "../include/Fraction.h"

Fraction::Fraction(int num, int den)
{
    Numerador = num;
    if(den>0) Denominador = den;
    else Denominador = 1;
}

Fraction::~Fraction()
{
}

void Fraction::setFraction(int num, int den){
    Numerador = num;
    if(den>0) Denominador = den;
    else Denominador = 1;
}

void Fraction::printFraction(){
    //cout << Numerador << "/" << Denominador << endl;
}

double Fraction::getQuot(){
    double Quot = Numerador/Denominador;
    return Quot;
}
