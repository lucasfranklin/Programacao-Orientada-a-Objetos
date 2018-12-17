#ifndef MATRIZ_H
#define MATRIZ_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Matriz
{
private:
    double **matrix = NULL;
    int numRows;
    int numColumns;

public:
    Matriz(const int rows = 0,const  int columns = 0);
    Matriz(const std::string fileName);
    bool getMatrix() const;
    void grava(const std::string& fileName) const;
    bool matrixSum(const Matriz& matrixA, const Matriz& matrixB);
    bool matrixMultiplication(const Matriz& matrixA, const std::vector<double>& elements);
    ~Matriz();

private:
    bool allocMatrix();
    void freeMatrix();
};

#endif // MATRIZ_H
