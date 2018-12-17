#include "../include/Pell.h"

using namespace std;

vector<unsigned long int> Pell::elements(0);

Pell::Pell()
{
    gen_elements(0);
}

Pell::Pell(int i)
{
    gen_elements(i);
}


int Pell::pellSeq(int n) const
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return 2*pellSeq(n-1)+pellSeq(n-2);
}

void Pell::gen_elements(int i)
{
    if(i==0) return;
    for(int j = elements.size(); j<=i; j++)
    {
        if(j!=0) elements.push_back(pellSeq(j));
    }

}

const vector<unsigned long int>& Pell::returnPoniterElement()
{
    return elements;
}


Pell::~Pell()
{
    //dtor
}
