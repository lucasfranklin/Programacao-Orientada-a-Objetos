#include "../include/Racional.h"
#include <cmath>
#include <string>

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
    int  tempNumerator, tempDenominator;
    doubleToRacional(&tempNumerator, &tempDenominator, &valueToConvert);
    numerator = tempNumerator;
    denominator = tempDenominator;
}

void Racional::doubleToRacional(int *tempNumerator, int *tempDenominator, double* valueToConvert)
{

    double fractpart, intValue;

    int countTens = 0;

    fractpart = modf(*valueToConvert, &intValue);    //Pega a parte fracionaria de valueToConvert e coloca em fractpart
    //intValue recebe a parte inteira
    while(fractpart!=0)
    {
        countTens+=1;
        *valueToConvert*=10;
        fractpart = modf (*valueToConvert, &intValue);
        if(countTens==4) break;                         //Maximo de 4 casas convertidas
    }

    *tempNumerator = *valueToConvert;
    *tempDenominator = pow(10,countTens);

    simpliflyRacional(tempNumerator, tempDenominator);

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
    int mCommonFactor = 1, auxSimplifiedNumerator, auxSimplifiedDenominator;

    mCommonFactor = maxCommonFactor(*simplifiedNumerator,*simplifiedDenominator);

    if(mCommonFactor!=0)
    {
        *simplifiedNumerator = *simplifiedNumerator/mCommonFactor;
        *simplifiedDenominator = *simplifiedDenominator/mCommonFactor;
    }

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

    if(mCommonFactor!=0) return mCommonFactor;
    else return 1;
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
    return output;
}

//Sobrecarga do operador de fluxo de entrada
istream& operator>>(istream& input, Racional& flowIn)
{
    string line;
    int auxNumerator, auxDenominador;
    input >> line;
    //Dividindo uma string usando o substr no caractere / e transformando ele em int
    auxNumerator = atoi(line.substr(0,line.find("/")).c_str());
    auxDenominador = atoi(line.substr(line.find("/")+1,line.size()).c_str());

    flowIn.simpliflyRacional(&auxNumerator, &auxDenominador);

    flowIn.numerator = auxNumerator;
    flowIn.denominator = auxDenominador;
    return input;
}

//Diversos metodos de set
void Racional::setRacional(int newNumerator, int newDenominator)
{
    simpliflyRacional(&newNumerator, &newDenominator);
    numerator = newNumerator;
    denominator = newDenominator;
}

void Racional::setRacional(double newRacional)
{

    int  tempNumerator, tempDenominator;

    doubleToRacional(&tempNumerator, &tempDenominator, &newRacional);

    numerator = tempNumerator;

    denominator = tempDenominator;
}

void Racional::setRacional(string newracional)
{

    int auxNumerator, auxDenominador;

    auxNumerator = atoi(newracional.substr(0,newracional.find("/")).c_str());
    auxDenominador = atoi(newracional.substr(newracional.find("/")+1,newracional.size()).c_str());

    simpliflyRacional(&auxNumerator, &auxDenominador);

    numerator = auxNumerator;
    denominator = auxDenominador;
}


Racional::~Racional()
{
    //Destructor
}
}
