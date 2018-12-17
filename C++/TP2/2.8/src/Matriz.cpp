#include "../include/Matriz.h"

using namespace std;

Matriz::Matriz(const int rows, const int columns)
{
    numRows = rows;
    numColumns = columns;

    if(rows !=0 && columns != 0)
    {
        if(allocMatrix())
        {
            for(int i = 0; i<numRows; i++)
            {
                for(int j = 0; j<numColumns; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}

Matriz::Matriz(const string fileName)
{
    int rows, columns;

    ifstream inFile(fileName.c_str());

    if(inFile)
    {
        inFile >> rows >> columns;
        numRows = rows;
        numColumns = columns;

        if(rows !=0 && columns != 0)
        {
            if(allocMatrix())
            {
                for(int i = 0; i<numRows; i++)
                {
                    for(int j = 0; j<numColumns; j++)
                    {
                        inFile >> matrix[i][j];
                    }
                }
            }
        }
        inFile.close();
    }
    else cout << "Arquivo nao encontrado";
}

bool Matriz::allocMatrix()
{
    matrix = new double*[numRows];

    for(int i = 0; i<numRows; i++)
    {
        matrix[i] = new double[numColumns];
    }

    if(matrix == NULL) return false;
    else return true;

}

void Matriz::freeMatrix()
{
    if(matrix)
    {
        for(int i = 0; i<numRows; i++)
        {
            if(matrix[i]) delete[] matrix[i];
        }
        delete[] matrix;
    }
}

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

bool Matriz::matrixSum(const Matriz& matrixA,const  Matriz& matrixB)
{
    if((matrixA.numRows == matrixB.numRows) && (matrixA.numColumns == matrixB.numColumns))
    {

        //Desaloca a matriz atual caso ele ja esteja alocado
        if(matrix) freeMatrix();

        //Seta as linhas e colunas da matriz
        numRows = matrixA.numRows;
        numColumns = matrixA.numColumns;

        //Aloca a matriz
        if(allocMatrix())
        {
            for(int i = 0; i<numRows; i++)
            {
                for(int j = 0; j<numColumns; j++)
                {
                    matrix[i][j] = matrixA.matrix[i][j]+matrixB.matrix[i][j];
                }
            }
        }
    }
    else return false;
    return true;
}

bool Matriz::matrixMultiplication(const Matriz& matrixA, const vector<double>& elements)
{
    double elementsSum = 0;

    //Desaloca a matriz atual caso ele ja esteja alocado
    if(matrix) freeMatrix();

    //Seta as linhas e colunas da matriz
    numRows = matrixA.numRows;
    numColumns = 1;

    //Aloca a matriz
    if(matrixA.numColumns==elements.size() && allocMatrix())
    {
        for(int i = 0; i<matrixA.numRows; i++)
        {
            for(int j = 0; j<matrixA.numColumns; j++)
            {
                elementsSum += matrixA.matrix[i][j]*elements[j];
            }
            matrix[i][0] = elementsSum;
            elementsSum = 0;
        }
    }
    else return false;
    return true;
}

bool Matriz::getMatrix() const
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

Matriz::~Matriz()
{
    freeMatrix();
}
