#include "../include/Quadrados.h"

using namespace std;

vector<unsigned long int> Quadrados::elements(0);

Quadrados::Quadrados()
{
    gen_elements(0);
}

Quadrados::Quadrados(int i)
{
    gen_elements(i);
}


int Quadrados::quadradosSeq(int n) const
{
    return (n+1)*(n+1);
}

void Quadrados::gen_elements(int i)
{
    i-=1;
    if(i==0) return;
    for(int j = elements.size(); j<=i; j++)
    {
        elements.push_back(quadradosSeq(j));
    }

}

const vector<unsigned long int>& Quadrados::returnPoniterElement()
{
    return elements;
}

Quadrados::~Quadrados()
{
    //dtor
}
