#include "../include/Pentagonal.h"
using namespace std;

vector<unsigned long int> Pentagonal::elements(0);

Pentagonal::Pentagonal()
{
    gen_elements(0);
}

Pentagonal::Pentagonal(int i)
{
    gen_elements(i);
}

int Pentagonal::pentagonalSeq(int n) const
{
    return ((n+1)*(3*n+2))/2;
}

void Pentagonal::gen_elements(int i)
{
    i-=1;
    if(i==0) return;
    for(int j = elements.size(); j<=i; j++)
    {
        elements.push_back(pentagonalSeq(j));
    }

}

const vector<unsigned long int>& Pentagonal::returnPoniterElement()
{
    return elements;
}

Pentagonal::~Pentagonal()
{
    //dtor
}
