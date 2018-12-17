#include "../include/Matriz.h"
#include "../../2.1/src/CVetor.cpp"

using namespace std;
using namespace DataStructures; //Namespace referente ao CVetor

//Namespace Matematica
namespace Matematica
{

//Constroi a matriz a partir do numero de linhas e colunas
Matriz::Matriz(const int rows, const int columns)
{
    numRows = rows;
    numColumns = columns;

    if(rows !=0 && columns != 0)    //Procede com a construcao apenas se o numero de linhas e colunas for diferente de 0
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

//Constroi a matriz a partir de um arquivo
Matriz::Matriz(const string fileName)
{
    int rows, columns;

    ifstream inFile(fileName.c_str());

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
    else cout << "Arquivo nao encontrado";  //Se o arquivo nao existir exibe a frase
}

//Construtor de copia
Matriz::Matriz(const Matriz& copyObject)
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
bool Matriz::allocMatrix()
{
    matrix = new double*[numRows];

    for(int i = 0; i<numRows; i++)
    {
        matrix[i] = new double[numColumns];
    }

    //Se alocado retorna TRUE, senao retorna FALSE
    if(matrix == NULL) return false;
    else return true;
}

//Desaloca a matriz
void Matriz::freeMatrix()
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
void Matriz::grava(const string& fileName) const
{
    if(matrix)
    {
        ofstream outFile(fileName.c_str());

        outFile << numRows << " " << numColumns << endl << endl;


        for(int i = 0; i<numRows; i++)
        {
            for(int j = 0; j<numColumns; j++)
            {
                outFile << matrix[i][j] << " ";
            }
            outFile << endl;
        }
        outFile.close();
    }
}

//Imprime a matriz
bool Matriz::printMatrix() const
{
    if(matrix)
    {
        for(int i = 0; i<numRows; i++)
        {
            for(int j = 0; j<numColumns; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else return false;
    return true;
}

//Sobrecarrega o operador de atribuicao
const Matriz Matriz::operator= (const Matriz& attMatrix)
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
double& Matriz::operator()(const int i, const int j) const
{
    return matrix[i][j];
}

//Sobrecarga do operador de adicao, soma duas matrizes de mesmo tamanho
const Matriz Matriz::operator+ (const Matriz& sumMatrix) const
{
    if((numRows == sumMatrix.numRows) && (numColumns == sumMatrix.numColumns))
    {
        Matriz resultMatrix(numRows, numColumns);
        for(int i = 0; i<numRows; i++)
            for(int j = 0; j<numColumns; j++)
                resultMatrix.matrix[i][j] = matrix[i][j]+sumMatrix(i,j);
        return resultMatrix;
    }
    return NULL;
}

//Sobrecarga do operador de atribuicao com adicao direta, soma a matriz atual com outra, se forem do mesmo tamanho
const Matriz Matriz::operator+= (const Matriz& sumMatrix) const
{
    if((numRows == sumMatrix.numRows) && (numColumns == sumMatrix.numColumns))
    {
        for(int i = 0; i<numRows; i++)
            for(int j = 0; j<numColumns; j++)
                matrix[i][j] += sumMatrix(i,j);
        return *this;
    }
    return NULL;
}

//Sobrecarga do operador de subtracao, subtrai duas matrizes de mesmo tamanho
const Matriz Matriz::operator- (const Matriz& subMatrix) const
{
    if((numRows == subMatrix.numRows) && (numColumns == subMatrix.numColumns))
    {
        Matriz resultMatrix(numRows, numColumns);
        for(int i = 0; i<numRows; i++)
            for(int j = 0; j<numColumns; j++)
                resultMatrix.matrix[i][j] = matrix[i][j]-subMatrix(i,j);
        return resultMatrix;
    }
    return NULL;
}

//Sobrecarga do operador de atribuicao com subtracao direta, subtrai a matriz atual com outra, se forem do mesmo tamanho
const Matriz Matriz::operator-= (const Matriz& subMatrix) const
{
    if((numRows == subMatrix.numRows) && (numColumns == subMatrix.numColumns))
    {
        for(int i = 0; i<numRows; i++)
            for(int j = 0; j<numColumns; j++)
                matrix[i][j] -= subMatrix(i,j);

        return *this;
    }
    return NULL;
}

//Sobrecarga do operador de multiplicacao, multiplica duas matrizes, se compativel
const Matriz Matriz::operator* (const Matriz& multiMatrix) const
{
    if(numColumns == multiMatrix.numRows)
    {
        double sum = 0;
        Matriz resultMatrix(numRows, multiMatrix.numColumns);

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
    return NULL;
}

//Sobrecarga do operador de atribuicao com multiplicacao direta, multiplica a matriz atual com outra, se forem compativel
const Matriz Matriz::operator*= (const Matriz& multiMatrix)
{
    if(numColumns == multiMatrix.numRows)
    {
        double sum = 0;

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
    return NULL;
}

//Sobrecarga do operador de multiplicacao, multiplica uma matriz por um vetor, se compativel
const Matriz Matriz::operator* (const vector<double>& elements) const
{
    if(numColumns==elements.size())
    {
        double elementsSum = 0;
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
    return NULL;
}

//Sobrecarga do operador de multiplicacao, multiplica uma matriz por um CVetor, se compativel
const Matriz Matriz::operator* (const CVetor& elements) const
{
    int elementSize = elements.getSize();

    if(numColumns==elementSize)
    {
        double elementsSum = 0;
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
    return NULL;
}

//Sobrecarga do operador de atribuicao com multiplicacao direta, multiplica a matriz atual com um vetor, se forem compativel
const Matriz Matriz::operator*= (const vector<double>& elements)
{

    if(numColumns==elements.size())
    {
        double elementsSum = 0;
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
    return NULL;
}

//Sobrecarga do operador de atribuicao com multiplicacao direta, multiplica a matriz atual com um CVetor, se forem compativel
const Matriz Matriz::operator*= (const CVetor& elements)
{
    int elementSize = elements.getSize();

    if(numColumns==elementSize)
    {
        double elementsSum = 0;
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
    return NULL;
}

//Sobrecarga do operator de fluxo de saida
const ostream& operator<<(std::ostream& output, const Matriz& flowOut)
{

    for(int i = 0; i<flowOut.numRows; i++)
    {
        for(int j = 0; j<flowOut.numColumns; j++)
        {
            output << flowOut(i,j) << " ";
        }
        output << endl;
    }
    output << endl;

    return output;
}

//Sobrecarga do operador de fluxo de entrada
const istream& operator>>(istream& input, Matriz& flowIn)
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

//Destrutor
Matriz::~Matriz()
{
    freeMatrix();
}
}
