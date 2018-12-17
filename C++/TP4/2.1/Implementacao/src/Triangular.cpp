#include "../include/Triangular.h"

using namespace std;

vector<unsigned long int> Triangular::elements(0);

Triangular::Triangular()
{
    gen_elements(0);
}

Triangular::Triangular(int i)
{
    gen_elements(i);
}


int Triangular::triangularSeq(int n) const
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return triangularSeq(n-1)+n;
}

void Triangular::gen_elements(int i)
{
    if(i==0) return;
    for(int j = elements.size(); j<=i; j++)
    {
        if(j!=0) elements.push_back(triangularSeq(j));
    }

}

const vector<unsigned long int>& Triangular::returnPoniterElement()
{
    return elements;
}


Triangular::~Triangular()
{
    //dtor
}
