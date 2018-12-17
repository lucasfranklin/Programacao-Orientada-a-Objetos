#include <iostream>
#include <vector>
#include "include/Matriz.h"

using namespace std;
using namespace Matematica;
using namespace DataStructures;

int main()
{
    int a;
    Matriz<int> A("file.txt"), B("file.txt"), C("matrizC.txt"), D;
    /*vector<int> vet(6);
    vet[0] = 1;
    vet[1] = 2;
    vet[2] = 3;
    vet[3] = 15;
    vet[4] = 9;
    vet[5] = 4;

    vector<int>::iterator vetIterator = vet.begin();
*/
    //Iterator apontando para o inicio de A
    Matriz<int>::myIterator it = A.begin();

    cout << "Elementos da Matriz A: " << endl;
    while(it != A.end())
    {
        //Imprime A a partir do iterator
        cout << ++it << " ";
    }

    Matriz<int>::myIterator maxValueIterator = maxValue(A.begin(),A.end());
    cout << endl << "Maior valor na Matriz A: " << *maxValueIterator << endl << endl;
/*
    cout << "Elementos de um vetor: " << endl;
    for(vetIterator = vet.begin(); vetIterator != vet.end(); vetIterator++)
    cout << *vetIterator << " ";

    vector<int>::iterator maxVetIterator = maxValue(vet.begin(),vet.end());
    cout << endl << "Maior valor no vetor: " << *maxVetIterator;*/




        cout << "Matriz A: " << endl << A;
        cout << "Matriz B: " << endl << B;
        cout << "Matriz C: " << endl << C;

        cout << "D=A+B" << endl;
        try {
            D = A+B;
            cout << D;

        }
        catch(ETamMatrix e){
            e.msg();
        }

        cout << "D=A+C" << endl;
        try {
            D = A+C;
            cout  << D;

        }
        catch(ETamMatrix e){
            e.msg();
        }

        cout << "D+=B" << endl;
        try {
            D+=B;
            cout  << D;
        }
        catch(ETamMatrix e){
            e.msg();
        }

        cout << "D=A-B" << endl;
        try {
            D = A-B;
            cout << D;
        }
        catch(ETamMatrix e){
            e.msg();
        }

        cout << "D-=B" << endl;
        try {
            D-=B;
            cout  << D;
            }
        catch(ETamMatrix e){
            e.msg();
        }

        cout << "D=A*B" << endl;
        try {
            D = A*C;
            cout  << D;
            }
        catch(ECompMatrix e){
            e.msg();
        }

        cout << "Elemento (0,0) da Matriz A: ";
        try{cout << A(0,0) << endl ;}
        catch(EPosMatrix e){
            e.msg();
        }


    return 0;
}
