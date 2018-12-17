#include "../include/CVetor.h"

using namespace std;

//Namespace DataStructures
namespace DataStructures
{

//Contrutor de copia, copia os atribibutos de um objeto para outro
CVetor::CVetor(const CVetor& copyObject)
{
    //Se o tamanho for diferente realoca o objrto atual com valores Null
    if(Size != copyObject.Size) reallocVectorNull(copyObject.Size);

    Size = copyObject.Size;
    //Copiando os elementos
    for(int i = 0; i<Size; i++)  pointerElements[i] = copyObject[i];

}

//Aloca Vetor
bool CVetor::allocVector(int numberElements)
{

    Size = numberElements;
    pointerElements = new int[Size];

    //Se alocado com sucesso retorna TRUE, senao FALSE
    if(pointerElements) return true;
    else return false;
}

//Realoca vetor mantendo os dados existentes
bool CVetor::reallocVector(int numberElements)
{

    //Se o novo tamanho do vetor for zero aborta a operacao
    if(numberElements==0) return false;

    int *tempElements;
    int tempSize = Size;

    tempElements = new int[tempSize];

    //Faz uma copia dos elementos
    for(int i = 0; i<tempSize; i++) tempElements[i] = pointerElements[i];

    delete[] pointerElements;

    Size = numberElements;

    pointerElements = new int[Size];

    //Copia os elementos antigos
    for(int i = 0; i<tempSize; i++)  pointerElements[i] = tempElements[i];

    //Retorna TRUE se alocado com sucesso, senão retorna FALSE
    if(pointerElements) return true;
    else return false;
}

//Realoca o vetor sem a permanencia dos dados antigos
bool CVetor::reallocVectorNull(int numberElements)
{

    //Se o novo tamanho do vetor for zero aborta a operacao
    if(numberElements==0) return false;

    Size = numberElements;

    pointerElements = new int[Size];

    //Retorna TRUE se alocado com sucesso, senão retorna FALSE
    if(pointerElements) return true;
    else return false;
}

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

//Sobrecarga do operador de adicao, soma 2 vetores
const CVetor CVetor::operator+ (const CVetor& sumVector) const
{
    if(Size==sumVector.Size)
    {
        CVetor resultObject(Size);
        for(int i = 0; i < Size; i++) resultObject[i] = pointerElements[i]+sumVector[i];
        return resultObject;
    }
    return NULL;
}

//Sobrecarga do operador de subtracao, subtrai dois vetores
const CVetor CVetor::operator- (const CVetor& subVector) const
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
const int CVetor::operator* (const CVetor& multiVector) const
{
    int scalar = 0;

    if(Size==multiVector.Size)
    {

        for(int i = 0; i < Size; i++) scalar+= pointerElements[i]*multiVector[i];
        return scalar;
    }
    return 0;
}

//Sobrecarga do operador de divisao, divide cada elemento entre dois vetores
const CVetor CVetor::operator/ (const CVetor& divVector) const
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
const CVetor CVetor::operator% (const CVetor& multiVector) const
{
    //Somente para vetores de tamanho 3
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

//Sobrecarga do operador de atribuicao, copia os dados de um vetor para outro
const CVetor CVetor::operator= (const CVetor& attVector)
{
    //Se o objeto atual for igual ao atribuido retorna ele proprio
    if(this == &attVector) return *this;

    if(Size != attVector.Size) reallocVectorNull(attVector.Size);

    Size = attVector.Size;

    for(int i = 0; i<attVector.Size; i++) pointerElements[i] = attVector[i];

    return *this;
}

//Sobrecarga do operador de atribuicao com adicao direta, adiciona o vetor atual com outro vetor
const CVetor CVetor::operator+= (const CVetor& sumVector) const
{
    if(Size==sumVector.Size)
    {
        for(int i = 0; i < Size; i++) pointerElements[i]+=sumVector[i];
        return *this;
    }
    return NULL;
}

//Sobrecarga do operador de atribuicao com subtracao direta, subtrai o vetor atual com outro vetor
const CVetor CVetor::operator-= (const CVetor& subVector) const
{
    if(Size==subVector.Size)
    {
        for(int i = 0; i < Size; i++) pointerElements[i]-=subVector[i];
        return *this;
    }
    return NULL;
}

//Sobrecarga do operador de atribuicao com divisao direta, divide o vetor atual com outro vetor
const CVetor CVetor::operator/= (const CVetor& divVector) const
{
    if(Size==divVector.Size)
    {
        for(int i = 0; i < Size; i++) pointerElements[i]/=divVector[i];
        return *this;
    }
    return NULL;
}

//Multiplicacao vetorial direta, multiplica vetorialmente o vetor atual com outro
const CVetor CVetor::operator%= (const CVetor& escalarMultiVector)
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
const ostream& operator<<(ostream& output, const CVetor& flowOut)
{

    for(int i = 0; i<flowOut.Size; i++) output << flowOut[i] << " ";

    output << endl;

    return output;

}

//Sobrecarga do operador de fluxo de entrada
const istream& operator>>(istream& input, CVetor& flowIn)
{
    input >> flowIn.Size;

    delete[] flowIn.pointerElements;

    flowIn.pointerElements = new int[flowIn.Size];

    for (int i = 0; i < flowIn.Size; i++) input >> flowIn[i];

    return input;
}


//Sobrecarga para acesso direto aos elementos do vetor, para get e set
int& CVetor::operator[] (const int i) const
{
    return pointerElements[i];
}

//Sobrecarga para acesso direto aos elementos do vetor, para get e set
int& CVetor::operator() (const int i) const
{
    return pointerElements[i];
}

//Destrutor
CVetor::~CVetor()
{
    delete[] pointerElements;
}
}
