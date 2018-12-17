#ifndef LUCAS_H
#define LUCAS_H

#include "Seq.h"


class Lucas : public Seq
{
private:
    static std::vector<unsigned long int> elements;

public:
    Lucas();
    Lucas(int i);
    virtual ~Lucas();
protected:
    void gen_elements(int i);
    int lucasSeq(int n) const;
    const std::vector<unsigned long int>& returnPoniterElement();
private:
};

#endif // LUCAS_H
