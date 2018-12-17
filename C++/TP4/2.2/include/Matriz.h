#ifndef MATRIZ_H
#define MATRIZ_H

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include "CVetor.h"
#include "ETamMatrix.h"
#include "ECompMatrix.h"
#include "EPosMatrix.h"

using namespace DataStructures;

namespace Matematica
{

template <class T> class Matriz
{
private:
    T **matrix = NULL; //Matriz
    int numRows;    //Numero de linhas
    int numColumns; //Numero de colunas

public:
        Matriz(const int rows = 0,const  int columns = 0):numRows(rows), numColumns(columns)
    {
        initializeMatrix();
    };  //Construtor convencional
    Matriz(const std::string fileName);                 //Construtor a partir de um arquivo
    Matriz(const Matriz& copyObject);                   //Construtor de copia
    bool printMatrix() const;                           //Imprime matriz
    void printMatrix(const Matriz copyObject) const;    //Sobrecarga do printMatrix, somente para teste
    void grava(const std::string& fileName) const;
    ~Matriz();

    //Sobrecarga de Operadores
    const Matriz operator+ (const Matriz& sumMatrix) const;
    const Matriz operator- (const Matriz& subMatrix) const;
    const Matriz operator* (const Matriz& multiMatrix) const;
    const Matriz operator* (const std::vector<T>& elements) const;
    const Matriz operator* (const DataStructures::CVetor& elements) const;
    const Matriz operator= (const Matriz& attMatrix);
    const Matriz operator+= (const Matriz& sumMatrix) const;
    const Matriz operator-= (const Matriz& subMatrix) const;
    const Matriz operator*= (const Matriz& multiMatrix);
    const Matriz operator*= (const std::vector<T>& elements);
    const Matriz operator*= (const DataStructures::CVetor& elements);
    T& operator()(const int i, const int j) const;
    template <class U> const friend std::ostream& operator<< (std::ostream& output, Matriz& flowOut);
    template <class U> const friend std::istream& operator>> (std::istream& input, Matriz& flowIn);
    const std::ostream& outstream(std::ostream& output);
    //-----
    class myIterator;

    myIterator begin();
    myIterator end();

    //Metodo para o iterator
    friend class myIterator;
    class myIterator
    {
    private:
        Matriz& mat;
        int Rows;    //Numero de linhas
        int Columns; //Numero de colunas
    public:
        //Begin
        myIterator(Matriz& newMat) : mat(newMat), Rows(0), Columns(0) {}
        //End
        myIterator(Matriz& newMat, bool) : mat(newMat), Rows(mat.numRows), Columns(mat.numColumns) {}
        T& operator++(int);  // i++
        T& operator*() const;
        T& operator++();   // ++i
        myIterator& operator+=(int amount);
        bool operator==(const myIterator& comp) const;
        myIterator& operator= (myIterator& comp);
        bool operator!=(const myIterator& comp);
        friend std::ostream& operator<<(std::ostream& os, const myIterator& it)
        {
            return os << *it;
        }
    };

private:
    void initializeMatrix();
    bool allocMatrix();
    void freeMatrix();


};
//--------------------ITERATOR--------------------
template <class T>
T& Matriz<T>::myIterator::operator++(int)  // i++
{
    T aux = mat.matrix[Rows][Columns++];
    if(Columns==mat.numColumns)
    {
        Columns = 0;
        Rows++;
    }

    return aux;
}

template <class T>
T& Matriz<T>::myIterator::operator*() const
{
    return mat.matrix[Rows][Columns];
}

template <class T>
T& Matriz<T>::myIterator::operator++()   // ++i
{

    T aux = mat.matrix[Rows][Columns++];
    if(Columns==mat.numColumns)
    {
        Columns = 0;
        Rows++;
    }

    return aux;
}

template <class T>
typename Matriz<T>::myIterator& Matriz<T>::myIterator::operator+=(int amount)
{
    if(Columns + amount >= mat.numColumns*mat.numRows)
    {
        return *this;
    }
    Columns += amount;

    if(Columns >= mat.numColumns)
    {
        int position = Columns;
        while(position >= mat.numColumns)
        {
            position = position - mat.numColumns;
            Rows++;
        }
        Columns = position;
    }
    else
    {
        Rows = 0;

    }

    return *this;
}

template <class T>
bool Matriz<T>::myIterator::operator==(const myIterator& comp) const
{
    return (Rows==comp.Rows && Columns==comp.Columns);
}

template <class T>
typename Matriz<T>::myIterator& Matriz<T>::myIterator::operator= (myIterator& comp)
{
    mat = comp.mat;
    Columns = comp.Columns;
    Rows = comp.Rows;

    return *this;
}

template <class T>
bool Matriz<T>::myIterator::operator!=(const myIterator& comp)
{
    return ((Rows!=comp.Rows) && (Columns!=comp.Columns));
}
//--------------------FIM ITERATOR--------------------

//Constroi a matriz a partir de um arquivo
template <class T>
Matriz<T>::Matriz(const std::string fileName)
{
    int rows, columns;

    std::ifstream inFile(fileName.c_str());

    if(inFile)  //Se o arquivo existir, prossegue com a criacao
    {
        inFile >> rows >> columns;
        numRows = rows;
        numColumns = columns;

        if(rows !=0 && columns != 0)    //Se o numero de linhas e colunas for diferente de 0, prossegue com a criacao
        {
            if(allocMatrix())   //Se a alocacao ocorreu corretamente
            {
                for(int i = 0; i<numRows; i++)
                {
                    for(int j = 0; j<numColumns; j++)
                    {
                        inFile >> matrix[i][j]; //Atribui a matriz os valores do arquivo
                    }
                }
            }
        }
        inFile.close(); //Fecha o arquivo
    }
    else std::cout << "Arquivo nao encontrado";  //Se o arquivo nao existir exibe a frase
}

//Construtor de copia
template <class T>
Matriz<T>::Matriz(const Matriz& copyObject)
{
    numRows = copyObject.numRows;
    numColumns = copyObject.numColumns;

    allocMatrix();

    for(int i = 0; i<numRows; i++)
    {
        for(int j = 0; j<numColumns; j++)
        {
            matrix[i][j] = copyObject.matrix[i][j];
        }
    }
}

//Aloca a matriz
template <class T>
void Matriz<T>::initializeMatrix()
{
    if(numRows !=0 && numColumns != 0)    //Procede com a construcao apenas se o numero de linhas e colunas for diferente de 0
    {
        if(allocMatrix())   //Se a alocacao ocorrer
        {
            for(int i = 0; i<numRows; i++)
            {
                for(int j = 0; j<numColumns; j++)
                {
                    matrix[i][j] = 0;   //Inicializa a matriz com 0's
                }
            }
        }
    }
}
template <class T>
bool Matriz<T>::allocMatrix()
{
    matrix = new T*[numRows];

    for(int i = 0; i<numRows; i++)
    {
        matrix[i] = new T[numColumns];
    }

    //Se alocado retorna TRUE, senao retorna FALSE
    if(matrix == NULL) return false;
    else return true;
}

//Desaloca a matriz
template <class T>
void Matriz<T>::freeMatrix()
{
    if(matrix)
    {
        for(int i = 0; i<numRows; i++)
        {
            if(matrix[i]) delete[] matrix[i];
        }
        delete matrix;
    }
}

//Grava dados da matriz em um arquivo
template <class T>
void Matriz<T>::grava(const std::string& fileName) const
{
    if(matrix)
    {
        std::ofstream outFile(fileName.c_str());

        outFile << numRows << " " << numColumns << std::endl << std::endl;


        for(int i = 0; i<numRows; i++)
        {
            for(int j = 0; j<numColumns; j++)
            {
                outFile << matrix[i][j] << " ";
            }
            outFile << std::endl;
        }
        outFile.close();
    }
}

//Imprime a matriz
template <class T>
bool Matriz<T>::printMatrix() const
{

    if(matrix)
    {
        for(int i = 0; i<numRows; i++)
        {
            for(int j = 0; j<numColumns; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    else return false;
    return true;

}

//Sobrecarrega o operador de atribuicao
template <class T>
const Matriz<T> Matriz<T>::operator= (const Matriz& attMatrix)
{

    if(this == &attMatrix) return *this;

    numColumns = attMatrix.numColumns;
    numRows = attMatrix.numRows;

    allocMatrix();

    for(int i = 0; i<numRows; i++)
    {
        for(int j = 0; j<numColumns; j++)
        {
            matrix[i][j] = attMatrix.matrix[i][j];
        }
    }

    return *this;
}


//Sobrecarga de operador para acesso direto aos elementos da matriz
template <class T>
T& Matriz<T>::operator()(const int i, const int j) const
{
    if(i>=numRows || j>=numColumns) throw(EPosMatrix(__LINE__));
    return matrix[i][j];
}

//Sobrecarga do operador de adicao, soma duas matrizes de mesmo tamanho
template <class T>

const Matriz<T> Matriz<T>::operator+ (const Matriz<T>& sumMatrix) const
{

    if((numRows != sumMatrix.numRows) || (numColumns != sumMatrix.numColumns)) throw (ETamMatrix(__LINE__));

    Matriz resultMatrix(numRows, numColumns);

    for(int i = 0; i<numRows; i++)
        for(int j = 0; j<numColumns; j++)
            resultMatrix.matrix[i][j] = matrix[i][j]+sumMatrix(i,j);

    return resultMatrix;

    return NULL;

}

//Sobrecarga do operador de atribuicao com adicao direta, soma a matriz atual com outra, se forem do mesmo tamanho
template <class T>
const Matriz<T> Matriz<T>::operator+= (const Matriz<T>& sumMatrix) const
{

    if((numRows != sumMatrix.numRows) || (numColumns != sumMatrix.numColumns)) throw (ETamMatrix(__LINE__));

    for(int i = 0; i<numRows; i++)
        for(int j = 0; j<numColumns; j++)
            matrix[i][j] += sumMatrix(i,j);
    return *this;

}

//Sobrecarga do operador de subtracao, subtrai duas matrizes de mesmo tamanho
template <class T>
const Matriz<T> Matriz<T>::operator- (const Matriz& subMatrix) const
{

    if((numRows != subMatrix.numRows) || (numColumns != subMatrix.numColumns)) throw (ETamMatrix(__LINE__));

    Matriz resultMatrix(numRows, numColumns);

    for(int i = 0; i<numRows; i++)
        for(int j = 0; j<numColumns; j++)
            resultMatrix.matrix[i][j] = matrix[i][j]-subMatrix(i,j);

    return resultMatrix;

}

//Sobrecarga do operador de atribuicao com subtracao direta, subtrai a matriz atual com outra, se forem do mesmo tamanho
template <class T>
const Matriz<T> Matriz<T>::operator-= (const Matriz& subMatrix) const
{

    if((numRows != subMatrix.numRows) || (numColumns != subMatrix.numColumns)) throw (ETamMatrix(__LINE__));

    for(int i = 0; i<numRows; i++)
        for(int j = 0; j<numColumns; j++)
            matrix[i][j] -= subMatrix(i,j);

    return *this;

}

//Sobrecarga do operador de multiplicacao, multiplica duas matrizes, se compativel
template <class T>
const Matriz<T> Matriz<T>::operator* (const Matriz& multiMatrix) const
{

    if(numColumns != multiMatrix.numRows) throw (ECompMatrix(__LINE__));

    Matriz resultMatrix(numRows, multiMatrix.numColumns);

    T sum = 0;

    for(int i=0; i<numRows; i++)
    {
        for(int j=0; j<multiMatrix.numColumns; j++)
        {
            for(int k=0; k<multiMatrix.numRows; k++)
            {
                sum += matrix[i][k] * multiMatrix(k,j);
            }
            resultMatrix.matrix[i][j] = sum;
            sum = 0;
        }
    }
    return resultMatrix;

}

//Sobrecarga do operador de atribuicao com multiplicacao direta, multiplica a matriz atual com outra, se forem compativel
template <class T>
const Matriz<T> Matriz<T>::operator*= (const Matriz& multiMatrix)
{

    if(numColumns != multiMatrix.numRows) throw (ECompMatrix(__LINE__));

    T sum = 0;

    Matriz auxMatrix(numRows, multiMatrix.numColumns);

    for(int i=0; i<numRows; i++)
    {
        for(int j=0; j<multiMatrix.numColumns; j++)
        {
            for(int k=0; k<multiMatrix.numRows; k++)
            {
                sum += matrix[i][k] * multiMatrix(k,j);
            }
            auxMatrix.matrix[i][j] = sum;
            sum = 0;
        }
    }

    freeMatrix();

    numRows = auxMatrix.numRows;
    numColumns = multiMatrix.numColumns;

    allocMatrix();

    matrix = auxMatrix.matrix;

    return *this;
}

//Sobrecarga do operador de multiplicacao, multiplica uma matriz por um vetor, se compativel
template <class T>
const Matriz<T> Matriz<T>::operator* (const std::vector<T>& elements) const
{
    if(numColumns!=elements.size()) throw (ECompMatrix(__LINE__));

    T elementsSum = 0;
    Matriz resultMatrix(numRows,1);

    for(int i = 0; i<numRows; i++)
    {
        for(int j = 0; j<numColumns; j++)
        {
            elementsSum += matrix[i][j]*elements[j];
        }
        resultMatrix.matrix[i][0] = elementsSum;
        elementsSum = 0;
    }
    return resultMatrix;

}

//Sobrecarga do operador de multiplicacao, multiplica uma matriz por um CVetor, se compativel
template <class T>
const Matriz<T> Matriz<T>::operator* (const CVetor& elements) const
{
    int elementSize = elements.getSize();

    if(numColumns==elementSize) throw (ECompMatrix(__LINE__));

    T elementsSum = 0;
    Matriz resultMatrix(numRows,1);

    for(int i = 0; i<numRows; i++)
    {
        for(int j = 0; j<numColumns; j++)
        {
            elementsSum += matrix[i][j]*elements[j];
        }
        resultMatrix.matrix[i][0] = elementsSum;
        elementsSum = 0;
    }

    return resultMatrix;


}

//Sobrecarga do operador de atribuicao com multiplicacao direta, multiplica a matriz atual com um vetor, se forem compativel
template <class T>
const Matriz<T> Matriz<T>::operator*= (const std::vector<T>& elements)
{

    if(numColumns==elements.size())  throw (ECompMatrix(__LINE__));

    T elementsSum = 0;
    Matriz auxMatrix(numRows, 1);

    for(int i = 0; i<numRows; i++)
    {
        for(int j = 0; j<numColumns; j++)
        {
            elementsSum += matrix[i][j]*elements[j];
        }
        auxMatrix.matrix[i][0] = elementsSum;
        elementsSum = 0;
    }

    freeMatrix();

    numRows = auxMatrix.numRows;
    numColumns = 1;

    allocMatrix();

    matrix = auxMatrix.matrix;

    return *this;
}

//Sobrecarga do operador de atribuicao com multiplicacao direta, multiplica a matriz atual com um CVetor, se forem compativel
template <class T>
const Matriz<T> Matriz<T>::operator*= (const CVetor& elements)
{
    int elementSize = elements.getSize();

    if(numColumns==elementSize) throw (ECompMatrix(__LINE__));

    T elementsSum = 0;
    Matriz auxMatrix(numRows, 1);

    for(int i = 0; i<numRows; i++)
    {
        for(int j = 0; j<numColumns; j++)
        {
            elementsSum += matrix[i][j]*elements[j];
        }
        auxMatrix.matrix[i][0] = elementsSum;
        elementsSum = 0;
    }

    freeMatrix();

    numRows = auxMatrix.numRows;
    numColumns = 1;

    allocMatrix();

    matrix = auxMatrix.matrix;

    return *this;

}

//Sobrecarga do operator de fluxo de saida
template <class T>
const std::ostream& operator<<(std::ostream& output, Matriz<T>& flowOut)
{

    return flowOut.outstream(output);

}

template <class T>
const std::ostream& Matriz<T>::outstream(std::ostream& output)
{
    for(int i = 0; i<numRows; i++)
    {
        for(int j = 0; j<numColumns; j++)
        {
            output << matrix[i][j] << " ";
        }
        output << std::endl;
    }
    output << std::endl;

    return output;
}

//Sobrecarga do operador de fluxo de entrada
template <class T>
const std::istream& operator>>(std::istream& input, Matriz<T>& flowIn)
{

    input >> flowIn.numRows >> flowIn.numColumns;

    if(flowIn.numRows !=0 && flowIn.numColumns != 0)    //Se o numero de linhas e colunas for diferente de 0, prossegue com a criacao
    {
        if(flowIn.allocMatrix())   //Se a alocacao ocorreu corretamente
        {
            for(int i = 0; i<flowIn.numRows; i++)
            {
                for(int j = 0; j<flowIn.numColumns; j++)
                {
                    input >> flowIn.matrix[i][j]; //Atribui a matriz os valores do arquivo
                }
            }
        }
    }

}
template <class T>
typename Matriz<T>::myIterator Matriz<T>::begin()
{
    return myIterator(*this);
}

template <class T>
typename Matriz<T>::myIterator Matriz<T>::end()
{
    return myIterator(*this, true);
}

//Destrutor
template <class T>
Matriz<T>::~Matriz()
{
    freeMatrix();
}

}

template <typename Iterator>
Iterator maxValue(Iterator begin, Iterator end)
{
    Iterator be = begin;
    Iterator maximo = begin;

    while(be != end)
    {

        if((be++) > *maximo)
        {
            maximo = be;
        }


    }
    return maximo;
}


#endif // MATRIZ_H
