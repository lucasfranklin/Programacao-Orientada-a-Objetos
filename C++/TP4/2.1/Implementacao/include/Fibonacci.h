#ifndef FIBONACCI_H
#define FIBONACCI_H

#include "Seq.h"


class Fibonacci : public Seq
{
private:
    //Sequencia
    static std::vector<unsigned long int> elements;

public:
    Fibonacci();
    Fibonacci(int i);
    virtual ~Fibonacci();

protected:
    void gen_elements(int i);
    int fibonacciSeq(int n) const;
    //Retorna a referencia para a sequencia
    const std::vector<unsigned long int>& returnPoniterElement();

private:
};

#endif // FIBONACCI_H
