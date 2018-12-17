#ifndef C_H
#define C_H

#include "A.h"
#include "B.h"


class C : public A
{
private:
    B b;

public:
    ~C();
private:
};

#endif // C_H
