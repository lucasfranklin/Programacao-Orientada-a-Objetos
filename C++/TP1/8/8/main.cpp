/*
a) Os atributos necess�rios s�o: Numerador e Denominador.
   Esses atributos s�o a compiso��o de uma fra��o, do que elas s�o formadas, suas caracteristicas,
   por isso foram escolhidas como atributos.
b) M�todos:
   private: setFraction(int num, int den);
   public: getFraction();
   public: getQuot();
    Os m�todos que foram escolhidos como publicos tem a caracteristica de n�o interferir na consistencia ou integridade
    dos dados, os apresentados aqui apenas retornam resultados que foram gerados pelos m�todos privados.
c) A classe fraction � uma classe simples para representa��o de valores fracion�rios, depois de instanciada
   pode-se usar o m�todo setFraction() para setar o numerador e o denominador, nesse m�todo existe um tratamento
   para que n�o seja aceito o valor 0 (zero) no denominador, caso esse valor seja passado para o construtor, o denominador ser� 1.
*/


#include <iostream>

using namespace std;

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

Fraction::Fraction(int num, int den)
{
    Numerador = num;
    if(den>0) Denominador = den;
    else Denominador = 1;
}

Fraction::~Fraction()
{
}

void Fraction::setFraction(int num, int den){
    Numerador = num;
    if(den>0) Denominador = den;
    else Denominador = 1;
}

void Fraction::printFraction(){
    cout << Numerador << "/" << Denominador << endl;
}

double Fraction::getQuot(){
    double Quot = Numerador/Denominador;
    return Quot;
}

int main()
{
    Fraction f1(2,1);
    f1.printFraction();

    return 0;
}
