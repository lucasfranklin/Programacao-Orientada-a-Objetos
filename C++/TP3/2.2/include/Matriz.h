#ifndef MATRIZ_H
#define MATRIZ_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../../2.1/include/CVetor.h"

namespace Matematica
{

class Matriz
{
private:
    double **matrix = NULL; //Matriz
    int numRows;    //Numero de linhas
    int numColumns; //Numero de colunas

public:
    Matriz(const int rows = 0,const  int columns = 0);  //Construtor convencional
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
    const Matriz operator* (const std::vector<double>& elements) const;
    const Matriz operator* (const DataStructures::CVetor& elements) const;
    const Matriz operator= (const Matriz& attMatrix);
    const Matriz operator+= (const Matriz& sumMatrix) const;
    const Matriz operator-= (const Matriz& subMatrix) const;
    const Matriz operator*= (const Matriz& multiMatrix);
    const Matriz operator*= (const std::vector<double>& elements);
    const Matriz operator*= (const DataStructures::CVetor& elements);
    double& operator()(const int i, const int j) const;
    const friend std::ostream& operator<<(std::ostream& output, const Matriz& flowOut);
    const friend std::istream& operator>>(std::istream& input, Matriz& flowIn);
    //-----

private:
    bool allocMatrix();
    void freeMatrix();
};

inline void Matriz::printMatrix(const Matriz copyObject) const
{
    copyObject.printMatrix();
}

}
#endif // MATRIZ_H
