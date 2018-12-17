#include "../include/Fibonacci.h"
#include <vector>

using namespace std;

//Inicialização do atributo estatico
vector<unsigned long int> Fibonacci::elements(0);

Fibonacci::Fibonacci()
{
    gen_elements(0);
}

Fibonacci::Fibonacci(int i)
{
    gen_elements(i);
}

//Gera sequencia de Fibonacci recursivamente
int Fibonacci::fibonacciSeq(int n) const
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacciSeq(n-1)+fibonacciSeq(n-2);
}

void Fibonacci::gen_elements(int i)
{
    if(i==0) return;
    for(int j = elements.size(); j<=i; j++)
    {
        //Tratamento para o fibonacci de 0
        if(j!=0) elements.push_back(fibonacciSeq(j));
    }

}

//Retorna a referencia para a sequencia de Fibonnaci
const vector<unsigned long int>& Fibonacci::returnPoniterElement()
{
    return elements;
}

Fibonacci::~Fibonacci()
{
    //dtor
}
