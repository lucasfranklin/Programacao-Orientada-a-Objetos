#ifndef TRIANGULAR_H
#define TRIANGULAR_H

#include "Seq.h"


class Triangular : public Seq
{
private:
    static std::vector<unsigned long int> elements;

public:
    Triangular();
    Triangular(int i);
    virtual ~Triangular();

protected:
    void gen_elements(int i);
    int triangularSeq(int n) const;
    const std::vector<unsigned long int>& returnPoniterElement();

private:
};

#endif // TRIANGULAR_H
