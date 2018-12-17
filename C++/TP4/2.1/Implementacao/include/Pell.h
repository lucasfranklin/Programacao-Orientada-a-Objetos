#ifndef PELL_H
#define PELL_H

#include "Seq.h"


class Pell : public Seq
{
private:
    static std::vector<unsigned long int> elements;

public:
    Pell();
    Pell(int i);
    virtual ~Pell();

protected:
    void gen_elements(int i);
    int pellSeq(int n) const;
    const std::vector<unsigned long int>& returnPoniterElement();

private:
};

#endif // PELL_H
