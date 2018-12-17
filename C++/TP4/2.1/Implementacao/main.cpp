#include <iostream>
#include <cstdlib>
#include "include/Fibonacci.h"
#include "include/Lucas.h"
#include "include/Pell.h"
#include "include/Triangular.h"
#include "include/Quadrados.h"
#include "include/Pentagonal.h"
#include "include/Container.h"

using namespace std;
void printSequence(Seq& object, int i, int j);
int menu();
void addSequence(Container* Sequencias);

int main()
{
    //Container de sequencias
    Container Sequencias;

    int opc;

    //Loop infinito para manutencao do menu
    while(true)
    {
        //Recebe o retorno com a opcao desejada
        opc = menu();
        system("cls");
        switch (opc)
        {
        case 1:
            addSequence(&Sequencias);
            system("cls");
            break;
        case 2:
            cout << "-Todas as sequencias" << endl << endl;
            Sequencias.print();
            system("pause");
            system("cls");
            break;
        case 3:
            int begin, end;

            cout << "-Intervalo para as sequencias" << endl << endl;

            cout << "Inicio: ";
            cin >> begin;
            cout << endl << "Fim: ";
            cin >> end;

            Sequencias.print(begin, end);
            system("pause");
            system("cls");
            break;
        case 4:
            int position;
            cout << "-Elemento das sequencias" << endl << endl;
            cout << "Posicao: ";
            cin >> position;

            Sequencias.printElement(position);
            system("pause");
            system("cls");

            break;
        case 5:
            exit(1);
            break;
        default:
            cout << endl << "\aOpcao Invalida" << endl;
            system("pause");
            system("cls");
            break;

        }
    }//while(opc<0 || opc>5)

    return 0;
}

//Imprime qualquer tipo de sequencia passando um intervalo
void printSequence(Seq& object, int i, int j)
{
    for(int k = i; k<=j; k++)
    {
        cout << object.elem(k) << " ";
    }
}

int menu()
{

    int opc;

    cout << "- Sequencias -" << endl << endl;
    cout << "1 - Adicionar Sequencia" << endl;
    cout << "2 - Imprimir Todas as Sequencias" << endl;
    cout << "3 - Imprimir Intervalo das Sequencias" << endl;
    cout << "4 - Imprimir Elemento das Sequencias" << endl;
    cout << endl << "5 - Sair" << endl;
    cout << endl << "Opcao: ";
    cin >> opc;

    return opc;
}


//Recebe o container por referencia
void addSequence(Container* Sequencias)
{

    int opcSeq, tam;

    do
    {
        do
        {
            cout << "-Adicionar Sequencia" << endl << endl;

            cout << "1 - Fibonacci" << endl;
            cout << "2 - Lucas" << endl;
            cout << "3 - Pell" << endl;
            cout << "4 - Triangular" << endl;
            cout << "5 - Quadrados" << endl;
            cout << "6 - Pentagonal" << endl;
            cout << endl << "7 - Sair desse menu" << endl;
            cout << endl << "Opcao: ";
            cin >> opcSeq;
            if(opcSeq<1 || opcSeq>7)
            {
                cout << endl << "Opcao Invalida!" << endl;
                system("pause");
                system("cls");
            }


        }
        while(opcSeq<1 || opcSeq>7);

        if(opcSeq==7) break;

        cout << endl << "Tamanho: ";
        cin >> tam;

        //Tipos de sequencias a serem adicionadas
        if(opcSeq == 1)
        {
            Fibonacci* seqFibonacci = new Fibonacci(tam);
            Sequencias->insert(*seqFibonacci);

        }
        else if(opcSeq == 2)
        {
            Lucas* seqLucas = new Lucas(tam);
            Sequencias->insert(*seqLucas);

        }
        else if(opcSeq == 3)
        {
            Pell* seqPell = new Pell(tam);
            Sequencias->insert(*seqPell);
        }
        else if(opcSeq == 4)
        {
            Triangular* seqTriangular = new Triangular(tam);
            Sequencias->insert(*seqTriangular);
        }
        else if(opcSeq == 5)
        {
            Quadrados* seqQuadrados = new Quadrados(tam);
            Sequencias->insert(*seqQuadrados);
        }
        else if(opcSeq == 6)
        {
            Pentagonal* seqPentagonal = new Pentagonal(tam);
            Sequencias->insert(*seqPentagonal);
        }

        //Reseta as opcoes para a proxima insercao
        opcSeq = 0;
        tam = 0;
        system("cls");

    }
    while(true);
    //Loop infinito de manutecao do menu

    return;
}
