#include "../include/Racional.h"
#include <cmath>

using namespace std;
//Namespace matematica
namespace Matematica
{

//Operador de conversao, Racional para Double
Racional::operator double()
{
    return (double)numerator/(double)denominator;
}


//Conversao Double para Racional
Racional::Racional(double valueToConvert)
{

    int countTens = 0, tempNumerator, tempDenominator;
    double fractpart, intValue;

    fractpart = modf(valueToConvert, &intValue);    //Pega a parte fracionaria de valueToConvert e coloca em fractpart
    //intValue recebe a parte inteira
    while(fractpart!=0)
    {
        countTens+=1;
        valueToConvert*=10;
        fractpart = modf (valueToConvert, &intValue);
        if(countTens==4) break;                         //Maximo de 4 casas convertidas
    }

    tempNumerator = valueToConvert;
    tempDenominator = pow(10,countTens);

    simpliflyRacional(&tempNumerator, &tempDenominator);

    numerator = tempNumerator;
    denominator = tempDenominator;
}

//Construtor Racional
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
        printDenominatorErrorMessage();
    }

}

//Metodo para simplificacao do Racional
void Racional::simpliflyRacional(int *simplifiedNumerator,int *simplifiedDenominator) const
{
    int mCommonFactor;

    mCommonFactor = maxCommonFactor(*simplifiedNumerator,*simplifiedDenominator);

    *simplifiedNumerator = *simplifiedNumerator/mCommonFactor;
    *simplifiedDenominator = *simplifiedDenominator/mCommonFactor;
}

//Metodo que retorna o maximo fator comun
int Racional::maxCommonFactor(int& simplifiedNumerator, int& simplifiedDenominator) const
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

//Metodo geral para realização de soma ou subtração
Racional Racional::racionalOperation(const Racional& opRacional, const string operationType) const
{
    Racional resultRacional;

    int numeratorA, numeratorB,opNumerator, opDenominator;

    opDenominator = denominator*opRacional.denominator;
    numeratorA = (opDenominator/denominator)*numerator;
    numeratorB = (opDenominator/opRacional.denominator)*opRacional.numerator;

    if(operationType.compare("sum") == 0) opNumerator = numeratorA+numeratorB;
    else if(operationType.compare("sub") == 0) opNumerator = numeratorA-numeratorB;
    else return 0;

    simpliflyRacional(&opNumerator, &opDenominator);

    resultRacional.numerator = opNumerator;
    resultRacional.denominator = opDenominator;

    return resultRacional;
}

//Metodo geral para realização de multiplicação e divisão
Racional Racional::racionalMultiplication(const int& numeratorA, const int& denominatorA, const int& numeratorB, const int& denominatorB) const
{

    Racional resultRacional;

    int multiNumerator, multiDenominator;

    multiNumerator = numeratorA*numeratorB;
    multiDenominator = denominatorA*denominatorB;

    simpliflyRacional(&multiNumerator, &multiDenominator);

    resultRacional.numerator = multiNumerator;
    resultRacional.denominator = multiDenominator;

    return resultRacional;

}

//Sobrecarga do operador de adicao, soma dois Racionais
const Racional Racional::operator+(const Racional& sumRacional) const
{
    return racionalOperation(sumRacional, "sum");
}

//Sobrecarga do operador de atribuicao direta com adicao, soma um Racional ao objeto atual
const Racional Racional::operator+=(const Racional& sumRacional)
{
    Racional auxResult = racionalOperation(sumRacional, "sum");
    *this = auxResult;
    return *this;
}

//Sobrecarga do operador de atribuicao
const Racional Racional::operator=(const Racional& copyRacional)
{
    numerator = copyRacional.numerator;
    denominator = copyRacional.denominator;
    return *this;
}

//Sobrecarga do operador de subtracao, subtrai dois Racionais
const Racional Racional::operator-(const Racional& subRacional) const
{
    return racionalOperation(subRacional, "sub");
}

//Sobrecarga do operador de atribuicao direta com subtracao, subtrai um Racional ao objeto atual
const Racional Racional::operator-=(const Racional& subRacional)
{
    Racional auxResult = racionalOperation(subRacional, "sub");
    *this = auxResult;
    return *this;
}

//Sobrecarga do operador de multiplicacao, multiplica dois Racionais
const Racional Racional::operator* (const Racional& multiRacional) const
{
    return racionalMultiplication(numerator,denominator, multiRacional.numerator, multiRacional.denominator);
}
//Sobrecarga do operador de atribuicao direta com multiplicacao, multiplica um Racional ao objeto atual
const Racional Racional::operator*= (const Racional& multiRacional)
{
    Racional auxResult = racionalMultiplication(numerator,denominator, multiRacional.numerator, multiRacional.denominator);
    *this = auxResult;
    return *this;
}

//Sobrecarga do operador de divisao, multiplica dois Racionais
const Racional Racional::operator/(const Racional& divRacional) const
{
    return racionalMultiplication(numerator,denominator,divRacional.denominator,divRacional.numerator);
}

//Sobrecarga do operador de atribuicao direta com divisao, divide um Racional ao objeto atual
const Racional Racional::operator/=(const Racional& divRacional)
{
    Racional auxResult = racionalMultiplication(numerator,denominator,divRacional.denominator,divRacional.numerator);
    *this = auxResult;
    return *this;
}

//Sobrecarga do operador de fluxo de saida
ostream& operator<<(ostream& output, const Racional& flowOut)
{
    output <<  flowOut.numerator << "/" << flowOut.denominator;
}

Racional::~Racional()
{
    //Destructor
}
}
