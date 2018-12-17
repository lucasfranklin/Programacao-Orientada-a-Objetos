#include "../include/Lucas.h"

using namespace std;

vector<unsigned long int> Lucas::elements(0);

Lucas::Lucas()
{
    gen_elements(0);
}

Lucas::Lucas(int i)
{
    gen_elements(i);
}

int Lucas::lucasSeq(int n) const
{
    if (n == 0)
        return 1;

    if (n == 1)
        return 3;

    return lucasSeq(n-1)+lucasSeq(n-2);
}

void Lucas::gen_elements(int i)
{
    i-=1;
    if(i==0) return;
    for(int j = elements.size(); j<=i; j++)
    {
        elements.push_back(lucasSeq(j));
    }

}

const vector<unsigned long int>& Lucas::returnPoniterElement()
{
    return elements;
}

Lucas::~Lucas()
{
    //dtor
}
