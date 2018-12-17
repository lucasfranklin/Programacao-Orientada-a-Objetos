/*
a) Os atributos necessários são: Numerador e Denominador.
   Esses atributos são a compisoção de uma fração, do que elas são formadas, suas caracteristicas,
   por isso foram escolhidas como atributos.
b) Métodos:
   private: setFraction(int num, int den);
   public: getFraction();
   public: getQuot();
    Os métodos que foram escolhidos como publicos tem a caracteristica de não interferir na consistencia ou integridade
    dos dados, os apresentados aqui apenas retornam resultados que foram gerados pelos métodos privados.
c) A classe fraction é uma classe simples para representação de valores fracionários, depois de instanciada
   pode-se usar o método setFraction() para setar o numerador e o denominador, nesse método existe um tratamento
   para que não seja aceito o valor 0 (zero) no denominador, caso esse valor seja passado para o construtor, o denominador será 1.
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
