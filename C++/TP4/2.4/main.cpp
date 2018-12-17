#include <iostream>
#include <vector>
#include <fstream>
#include "include\Racional.h"
#include <iterator>
#include <algorithm>

using namespace std;
using namespace Matematica;

int main()
{
    Racional A;
    vector<Racional> Container; //Container de racionais

    ifstream file("file.txt");
    istream_iterator<Racional> my_it(file);     //istream_iterator para a leitura do arquivo
    ostream_iterator<Racional> out_it (cout,"\n");  //ostram_iterator para a saida das informacoes

    //Armazena os objetos gerados a partir do arquivo no Container
    for (; my_it != istream_iterator<Racional>(); my_it++)
        Container.push_back(*my_it);


    //Ordena o conteiner usando a function objetc, que é a sobrecarga do operator()
    sort(Container.begin(), Container.end(), A);

    cout << "Ordem Crescente: " << endl << endl;
    copy ( Container.begin(), Container.end(), out_it );

    //Inverte o vetor
    reverse(Container.begin(), Container.end());

    cout << endl << "Ordem Decrescente: " << endl << endl;
    copy ( Container.begin(), Container.end(), out_it );


    //-----Operacoes de Racionais do trabalho anterior-----
    //Estao comentado pelo fato de nao serem necessario para esse problema
    /*
    cout << "Racional A: " << A << endl;
    cout << "Racional B: "<< B << endl << endl;

    C = A+B;
    cout << "Adicao - C = A+B: "<< C << endl;
    C = A-B;
    cout << "Subtracao - C = A-B: "<< C << endl;
    C = A*B;
    cout << "Multiplicacao - C = A*B: "<< C << endl;
    C = A/B;
    cout << "Divisao - C = A/B: "<< C << endl;
    double  d = 2.5;
    Racional D(2.5);
    cout << "Conversao Double x Racional - double  d = 2.5: "<< (Racional)d << endl;
    cout << "Conversao Racional x Double - D(5/2): "<< (double)D << endl;

    */

    return 0;
}

