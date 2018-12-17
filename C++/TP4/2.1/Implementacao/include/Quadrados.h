#ifndef QUADRADOS_H
#define QUADRADOS_H

#include "Seq.h"


class Quadrados : public Seq
{
private:
    static std::vector<unsigned long int> elements;

public:
    Quadrados();
    Quadrados(int i);
    virtual ~Quadrados();
protected:
    void gen_elements(int i);
    int quadradosSeq(int n) const;
    const std::vector<unsigned long int>& returnPoniterElement();

private:
};

#endif // QUADRADOS_H
