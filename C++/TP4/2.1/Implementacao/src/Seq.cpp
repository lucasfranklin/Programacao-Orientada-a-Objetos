#include "../include/Seq.h"

using namespace std;

//Retorna o elemento na posicao i, primeiro elemento da sequencia: 1
const unsigned long int Seq::elem(int i)
{
    //Tramaneto para posicao <=0 da sequencia
    if(i<=0) return 0;
    if(returnPoniterElement().size() < i) gen_elements(i);
    //Tramaneto para posicao da sequencia
    i-=1;
    return returnPoniterElement()[i];
}


//Impressao de todos os elementos ou um intervalo
const ostream& Seq::print(ostream& os, int begin, int end )
{

    //Flag para impressao de todos os elementos
    if(end==-1) end = returnPoniterElement().size();

    //Tratamento de intervalo, quando fim for menor que o inicio, nao imprime nada
    if(end<begin) return os;

    for(int i = begin; i<end; i++)
    {
        //Acesso ao elemento a partir do metodo que retorna a referencia para a sequencia
        os << returnPoniterElement()[i] << " ";
    }
    return os;
}

const int Seq::length()
{
    return returnPoniterElement().size();
}

const ostream& operator<< (ostream& os, Seq& outObj)
{
    //Sobrecarga do operador de fluxo de saida invoca o metodo de impressao
    return outObj.print(os);
}

Seq::~Seq()
{
    //dtor
}
