#include "../include/CVetor.h"

using namespace std;

namespace DataStructures{

//--------INICIO CONSTRUTORES----------

//Construtor, aloca apenas se o numero de elementos for igual a zero
CVetor::CVetor(int numberElementsAlloc)
{
        allocVector(numberElementsAlloc);
}

//Contrutor de copia, copia os atribibutos de um objeto para outro
CVetor::CVetor(const CVetor& copyObject)
{
    if(Size != copyObject.Size) reallocVectorNull(copyObject.Size);

    Size = copyObject.Size;
    for(int i = 0; i<Size; i++)  pointerElements[i] = copyObject[i];

}

//--------FIM CONSTRUTORES----------

bool CVetor::allocVector(int numberElements){

        Size = numberElements;
        pointerElements = new int[Size];

        if(pointerElements) return true;
        else return false;
}

bool CVetor::reallocVector(int numberElements){

        if(numberElements==0) return false;

        int *tempElements;
        int tempSize = Size;

        tempElements = new int[tempSize];

        for(int i = 0; i<tempSize; i++) tempElements[i] = pointerElements[i];

        delete[] pointerElements;

        Size = numberElements;

        pointerElements = new int[Size];

        for(int i = 0; i<tempSize; i++)  pointerElements[i] = tempElements[i];


        if(pointerElements) return true;
        else return false;
}

bool CVetor::reallocVectorNull(int numberElements){

        if(numberElements==0) return false;

        //delete[] pointerElements;

        Size = numberElements;

        pointerElements = new int[Size];

        if(pointerElements) return true;
        else return false;
}

//--------INICIO METODOS DE GET E SET----------

//Insere elemento no vetor
void CVetor::insertElement(int element, int position)
{
        pointerElements[position] = element;
}

//Imprime elementos na tela
void CVetor::printElements()
{
    for(int i = 0; i<Size; i++)
    {
        cout << pointerElements[i] << " ";
    }
    cout << endl;
}


//Retorna o tamanho do vetor
int CVetor::getSize() const
{
    return Size;
}

int CVetor::getElement(int i) const{
    return pointerElements[i];
}


//--------FIM METODOS DE GET E SET----------

//--------INICIO SOBRECARGA DE OPERADORES----------

//Sobrecarga do operador de adicao
CVetor CVetor::operator+ (const CVetor& sumVector) const
{
    if(Size==sumVector.Size)
    {
        CVetor resultObject(Size);
        for(int i = 0; i < Size; i++) resultObject[i] = pointerElements[i]+sumVector[i];
        return resultObject;
    }
    return NULL;
}

//Sobrecarga do operador de subtracao
CVetor CVetor::operator- (const CVetor& subVector) const
{
    if(Size==subVector.Size)
    {
        CVetor resultObject(Size);
        for(int i = 0; i < Size; i++) resultObject[i] = pointerElements[i]-subVector[i];
        return resultObject;
    }
    return NULL;
}

//Sobrecarga do operador de multiplicacao - Produto Escalar
int CVetor::operator* (const CVetor& multiVector) const
{
    int scalar = 0;

    if(Size==multiVector.Size)
    {

        for(int i = 0; i < Size; i++) scalar+= pointerElements[i]*multiVector[i];
        return scalar;
    }
    return 0;
}

//Sobrecarga do operador de divisao
CVetor CVetor::operator/ (const CVetor& divVector) const
{
    if(Size==divVector.Size)
    {
        CVetor resultObject(Size);
        for(int i = 0; i < Size; i++) resultObject[i] = pointerElements[i]/divVector[i];
        return resultObject;
    }
    return NULL;
}

//Sobrecarga do operador usado aqui como produto vetorial
CVetor CVetor::operator% (const CVetor& multiVector) const
{
    if(Size==3 && multiVector.Size==3)
    {
        CVetor resultObject(3);

        resultObject[0] = ((pointerElements[1]*multiVector[2]-multiVector[1]*pointerElements[2]));
        resultObject[1] = ((multiVector[0]*pointerElements[2]-pointerElements[0]*multiVector[2]));
        resultObject[2] = (pointerElements[0]*multiVector[1]-pointerElements[1]*multiVector[0]);

        return resultObject;
    }
    else return NULL;

}

//Sobrecarga do operador de atribuicao
CVetor CVetor::operator= (const CVetor& attVector)
{

    if(this == &attVector) return *this;

    if(Size != attVector.Size) reallocVectorNull(attVector.Size);

    Size = attVector.Size;

    for(int i = 0; i<attVector.Size; i++) pointerElements[i] = attVector[i];

    return *this;
}

//Sobrecarga do operador de atribuicao com adicao direta
CVetor CVetor::operator+= (const CVetor& sumVector) const
{
    if(Size==sumVector.Size)
    {
        for(int i = 0; i < Size; i++) pointerElements[i]+=sumVector[i];
        return *this;
    }
    return NULL;
}

//Sobrecarga do operador de atribuicao com subtracao direta
CVetor CVetor::operator-= (const CVetor& subVector) const
{
    if(Size==subVector.Size)
    {
        for(int i = 0; i < Size; i++) pointerElements[i]-=subVector[i];
        return *this;
    }
    return NULL;
}

//Sobrecarga do operador de atribuicao com divisao direta
CVetor CVetor::operator/= (const CVetor& divVector) const
{
    if(Size==divVector.Size)
    {
        for(int i = 0; i < Size; i++) pointerElements[i]/=divVector[i];
        return *this;
    }
    return NULL;
}

CVetor CVetor::operator%= (const CVetor& escalarMultiVector)
{
    if(Size==3 && escalarMultiVector.Size == 3)
    {

        pointerElements[0] = (pointerElements[1]*escalarMultiVector[2]-escalarMultiVector[1]*pointerElements[2]);
        pointerElements[1] = (escalarMultiVector[0]*pointerElements[2]-pointerElements[0]*escalarMultiVector[2]);
        pointerElements[2] = (pointerElements[0]*escalarMultiVector[1]-pointerElements[1]*escalarMultiVector[0]);

        return *this;
    }
    else return NULL;

}

//Sobrecarga do operador de fluxo de saida
ostream& operator<<(ostream& output, const CVetor& flowOut)
{

    for(int i = 0; i<flowOut.Size; i++) output << flowOut[i] << " ";

    output << endl;

    return output;

}

//Sobrecarga do operador de fluxo de entrada
istream& operator>>(istream& input, CVetor& flowIn)
{
    input >> flowIn.Size;

    delete[] flowIn.pointerElements;

    flowIn.pointerElements = new int[flowIn.Size];

    for (int i = 0; i < flowIn.Size; i++) input >> flowIn[i];

    return input;
}

int& CVetor::operator[] (const int i) const
{
    return getElement(i);
}

int& CVetor::operator() (const int i) const
{
    return getElement(i);
}

//--------FIM SOBRECARGA DE OPERADORES----------


CVetor::~CVetor()
{
    delete[] pointerElements;
}
}
