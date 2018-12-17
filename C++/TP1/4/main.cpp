#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;
int multiplicaMatrix(vector< vector<double> > &matrix1, vector<vector< double> > &matrix2, vector< vector<double> > &newMatrix);
int readFile(string& file, vector< vector<double> > &matrix1, vector<vector< double> > &matrix2);
int writeFile(vector< vector<double> > &newMatrix);

int main()
{
    vector< vector<double> > matrix1, matrix2,newMatrix;
    int i,j, statusMult, statusWrite, statusRead;
    string file;

    cout << "Entre com o nome do arquivo: ";
    cin >> file;
    statusRead = readFile(file,matrix1,matrix2);

    if(statusRead == 0)
    {
        cout << endl << "Erro na leitura do arquivo, o programa sera encerrado!" << endl << "Pressione qualquer tecla para terminar...";
        system("pause>null");
    }

    statusMult = multiplicaMatrix(matrix1,matrix2,newMatrix);

    if(statusMult == 0) cout << endl << "Erro, matrizes incompatives!" << endl;
    else if(statusMult == 1) statusWrite = writeFile(newMatrix);

    if(statusWrite == 1) cout << endl << "Resultado gravado com sucesso!" << endl ;
    else if(statusWrite == 0) cout << endl << "Erro na gravacao!";

    return 0;
}

int multiplicaMatrix(vector< vector<double> > &matrix1, vector<vector< double> > &matrix2, vector< vector<double> > &newMatrix)
{

    if(matrix1[0].size() != matrix2.size()) return 0;

    int i,j,k;
    double sum = 0;
    newMatrix.resize(matrix1.size());

    for(i=0; i<matrix1.size(); i++)
    {
        newMatrix[i].resize(matrix2[0].size());
        for(j=0; j<matrix2[0].size(); j++)
        {
            for(k=0; k<matrix2.size(); k++)
            {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            newMatrix[i][j] = sum;
            sum = 0;
        }
    }

    return 1;
}

int readFile(string& file, vector< vector<double> > &matrix1, vector<vector< double> > &matrix2)
{

    int line1, line2, column1, column2,i,j;

    ifstream in(file.c_str());

    if(in)
    {

        in >> line1 >> column1 >> line2 >> column2;

        matrix1.resize(line1);
        matrix2.resize(line2);
        //Matrix 1
        for(i=0; i<line1; i++)
        {
            matrix1[i].resize(column1);
            for(j=0; j<column1; j++)
            {
                in >> matrix1[i][j];
            }
        }
        //Matrix 2
        for(i=0; i<line2; i++)
        {
            matrix2[i].resize(column2);
            for(j=0; j<column2; j++)
            {
                in >> matrix2[i][j];
            }
        }

        return 1;

    }

    else return 0;

}

int writeFile(vector< vector<double> > &newMatrix)
{
    int i,j;
    ofstream out("matrizMultiplicada.txt");
    out << newMatrix.size() << " " << newMatrix[0].size() << endl;
    for(i=0; i<newMatrix.size(); i++)
    {
        for(j=0; j<newMatrix[0].size(); j++)
        {
            out << newMatrix[i][j] << " ";
        }
        out << endl;
    }

    out.close();

    if(out.bad()) return 0;
    else return 1;
}
