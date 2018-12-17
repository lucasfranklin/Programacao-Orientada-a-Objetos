#include "../include/Container.h"

using namespace std;

Container::Container()
{
    Sequences.resize(0);
    Size = 0;
}

void Container::print(int begin, int end)
{
    for(int i = 0; i<Sequences.size(); i++)
    {
        Sequences[i]->print(cout,begin-1,end);
        cout << endl;
    }
}

void Container::printElement(int position)
{
    for(int i = 0; i<Sequences.size(); i++)
    {
        cout << Sequences[i]->elem(position);
        cout << endl;
    }
}

void Container::insert(Seq& newSeq)
{
    Sequences.push_back(&newSeq);
}

Container::~Container()
{
    //destructor
}
