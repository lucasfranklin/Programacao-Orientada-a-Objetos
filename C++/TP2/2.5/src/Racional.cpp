#include "../include/Racional.h"

using namespace std;

Racional::Racional(int newNumerator, int newDenominator)
{
    if(newNumerator!=0 && newDenominator!=0) simpliflyRacional(&newNumerator,&newDenominator);

    numerator = newNumerator;

    if(newDenominator!=0)
    {
        denominator = newDenominator;
    }
    else
    {
        denominator = 1;
        getSenominaroErrorMessage();
    }

}

void Racional::simpliflyRacional(int *simplifiedNumerator,int *simplifiedDenominator)
{
    int mCommonFactor;

    mCommonFactor = maxCommonFactor(*simplifiedNumerator,*simplifiedDenominator);

    *simplifiedNumerator = *simplifiedNumerator/mCommonFactor;
    *simplifiedDenominator = *simplifiedDenominator/mCommonFactor;
}

int Racional::maxCommonFactor(int& simplifiedNumerator, int& simplifiedDenominator)
{

    if(simplifiedNumerator==simplifiedDenominator) return simplifiedNumerator;

    int mCommonFactor;
    int minor;

    minor = fmin(simplifiedNumerator,simplifiedDenominator);

    for(int i = 1; i<=(minor); i++)
    {
        if((simplifiedNumerator%i==0) && (simplifiedDenominator%i==0))
        {
            mCommonFactor = i;
        }

    }

    return mCommonFactor;
}

int Racional::setSum(const Racional& racionalA, const Racional& racionalB)
{
    return racionalOperation(racionalA, racionalB, "sum");
}

int Racional::setSubtraction(const Racional& racionalA, const Racional& racionalB)
{
    return racionalOperation(racionalA, racionalB, "sub");
}

//Metodo geral para realização de soma ou subtração
int Racional::racionalOperation(const Racional& racionalA, const Racional& racionalB, const string operationType)
{

    int numeratorA, numeratorB,sumNumerator, sumDenominator;

    sumDenominator = racionalA.denominator*racionalB.denominator;
    numeratorA = (sumDenominator/racionalA.denominator)*racionalA.numerator;
    numeratorB = (sumDenominator/racionalB.denominator)*racionalB.numerator;

    if(operationType.compare("sum") == 0) sumNumerator = numeratorA+numeratorB;
    else if(operationType.compare("sub") == 0) sumNumerator = numeratorA-numeratorB;
    else return 0;

    simpliflyRacional(&sumNumerator, &sumDenominator);

    numerator = sumNumerator;
    denominator = sumDenominator;

    return 1;
}

//Metodo geral para realização de multiplicação e divisão
int Racional::racionalMultiplication(const int& numeratorA,const int& denominatorA, const int& numeratorB, const int& denominatorB)
{

    int multiNumerator, multiDenominator;

    multiNumerator = numeratorA*numeratorB;
    multiDenominator = denominatorA*denominatorB;

    simpliflyRacional(&multiNumerator, &multiDenominator);

    numerator = multiNumerator;
    denominator = multiDenominator;

    return 1;

}

int Racional::setMultiplication(Racional& racionalA, Racional& racionalB)
{
    return racionalMultiplication(racionalA.numerator,racionalA.denominator, racionalB.numerator, racionalB.denominator);
}

int Racional::setDivsion(Racional& racionalA, Racional& racionalB)
{
    return racionalMultiplication(racionalA.numerator,racionalA.denominator,racionalB.denominator,racionalB.numerator);
}

void Racional::getRacional() const
{
    cout << numerator << "/" << denominator << endl;
}

double Racional::getRacionalDouble() const
{
    double doubleRacional = (double)numerator/(double)denominator;
    cout << doubleRacional << endl;
    return doubleRacional;
}

void Racional::getSenominaroErrorMessage()
{
    cout << "Denominador invalido! O denonimador padrao sera adotado (1)" << endl;
}

Racional::~Racional()
{
    //Destructor
}
