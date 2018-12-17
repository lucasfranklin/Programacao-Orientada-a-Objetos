#ifndef FRACTION_H
#define FRACTION_H


class Fraction
{
    private: int Numerador;
    private: int Denominador;
    public:
        Fraction(int num, int den);
        ~Fraction();
        void printFraction();
        double getQuot();
    private:
        void setFraction(int num, int den);
};

#endif // FRACTION_H
