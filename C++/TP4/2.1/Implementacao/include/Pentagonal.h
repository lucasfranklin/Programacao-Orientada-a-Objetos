#ifndef PENTAGONAL_H
#define PENTAGONAL_H

#include "Seq.h"


class Pentagonal : public Seq
{
private:
    static std::vector<unsigned long int> elements;

public:
    Pentagonal();
    Pentagonal(int i);
    virtual ~Pentagonal();
protected:
    void gen_elements(int i);
    int pentagonalSeq(int n) const;
    const std::vector<unsigned long int>& returnPoniterElement();
private:
};

#endif // PENTAGONAL_H
