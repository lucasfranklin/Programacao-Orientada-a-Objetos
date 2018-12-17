#ifndef RACIONAL_H
#define RACIONAL_H

#include <cmath>
#include <iostream>
#include <string>

//Namespace matematica
namespace Matematica
{

class Racional
{
private:
    int numerator;      //Numerador
    int denominator;    //Denominador

public:
    Racional(int newNumerator = 0, int newDenominator = 1);     //Construtor
    Racional(const Racional& copyRacional);                     //Construtor de copia
    double getRacionalDouble() const;                           //Retorna o racional como double
    void printRacional() const;                                 //Imprime o racional

    explicit operator double();                                 //Operador de conversao, transforma Racional em Double
    explicit Racional(double valueToConvert);                   //Conversao Double para Racional
    ~Racional();

    //Sobrecarga de operadores
    const Racional operator+ (const Racional& sumRacional) const;
    const Racional operator- (const Racional& subRacional) const;
    const Racional operator* (const Racional& multiRacional) const;
    const Racional operator/ (const Racional& divRacional) const;
    const Racional operator+= (const Racional& sumRacional);
    const Racional operator-= (const Racional& subRacional);
    const Racional operator*= (const Racional& multiRacional);
    const Racional operator/= (const Racional& divRacional);
    const Racional operator=(const Racional& copyRacional);
    friend std::ostream& operator<<(std::ostream& output, const Racional& flowOut);
    //-----

private:
    void simpliflyRacional(int *simplifiedNumerator,int *simplifiedDenominator) const;  //Simplifica o Racional
    int maxCommonFactor(int& simplifiedNumerator, int& simplifiedDenominator) const;    //Maximo valor comum
    Racional racionalOperation(const Racional& opRacional, const std::string operationType) const;  //Operacoes de soma e subtracao entre Racional
    Racional racionalMultiplication(const int& numeratorA,const int& denominatorA, const int& numeratorB, const int& denominatorB) const;   //Metodo de multiplicacao de Racional
    void printDenominatorErrorMessage();
};

//Metodos INLINE

//Construtor de copia
inline Racional::Racional(const Racional& copyRacional)
{
    numerator = copyRacional.numerator;
    denominator = copyRacional.denominator;
}

//Imprime racional
inline void Racional::printRacional() const
{
    std::cout << numerator << "/" << denominator << std::endl;
}

//Retorna double
inline double Racional::getRacionalDouble() const
{
    double doubleRacional = (double)numerator/(double)denominator;
    return doubleRacional;
}

//Metodo que imprime erro
inline void Racional::printDenominatorErrorMessage()
{
    std::cout << "Denominador invalido! O denonimador padrao sera adotado (1)" << std::endl;
}

}
#endif // RACIONAL_H
