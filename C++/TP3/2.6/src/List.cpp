#include "../include/List.h"

using namespace std;
namespace DataStructure
{

List::List()
{
    End = Begin = NULL;
    Size = 0;
}
/*
List::List(const List& copyObject){

    Node *perc;
    int dataTemp;

    perc = copyObject.Begin;
    if(copyObject.Begin==NULL)
    {
        //Retorna false se a lista é vazia
        return output;
    }
    while(perc!=NULL)
    {
        dataTemp = perc->getData();
        insertElementOrdened(dataTemp);
        perc = perc->getNext();
    }
    return output;
}

List List::operator=(List& attList){

    freeList();

    Node *perc;
    int dataTemp;

    perc = attList.Begin;
    if(attList.Begin==NULL)
    {
        //Retorna false se a lista é vazia
        //return;
    }
    while(perc!=NULL)
    {
        dataTemp = perc->getData();
        insertElementOrdened(dataTemp);
        perc = perc->getNext();
    }
    //return;
}
*/
List::Node* List::getBegin() const
{
    return Begin;
}

List::Node* List::getEnd() const
{
    return End;
}

List::Node::Node(int newData, Node* newNext)
{
    data = newData;
    next = newNext;
}

int List::Node::getData() const
{
    return data;
}

List::Node* List::Node::getNext() const
{
    return next;
}

void List::Node::setData(int newData)
{
    data = newData;
}

void List::Node::setNext(Node* newNext)
{
    next = newNext;
}

bool List::insertElementOrdened(const int newData)
{
    //Retorna FALSE se o elemento já estiver na lista
    if(Size != 0) if(searchElement(newData)!=-1) return false;

    Node *aux, *perc;

    aux = new Node(newData,NULL);

    if(Begin==NULL)
    {
        Begin = End = aux;
        Size+=1;
        return true;
    }

    perc = Begin;

    if(newData <= Begin->getData())
    {
        aux->setNext(Begin);
        Begin = aux;
    }
    else if(newData >= End->getData())
    {
        End->setNext(aux);
        End = aux;
    }

    else
    {
        while(perc->getNext()->getData() < newData)
        {
            perc = perc->getNext();
        }
        aux->setNext(perc->getNext());
        perc->setNext(aux);
    }
    Size+=1;
    return true;

}

int List::binarySearch(int searchBegin, int searchEnd,const int& searchData)
{

    Node* perc;
    int Count=0;

    if(Begin->getData()==searchData) return Count;

    perc = Begin;

    while(Count < ((searchBegin+searchEnd)/2))
    {
        perc = perc->getNext();
        Count++;
    }

    //Retorna -1 se chagar ao fim da lista e não encontrar
    if(searchBegin==searchEnd) return -1;

    if(perc->getData()==searchData) return Count;

    else if(perc->getData() > searchData) return binarySearch(searchBegin, Count, searchData);

    else if(perc->getData() < searchData) return binarySearch(Count+1, searchEnd, searchData);

    //Retorna -1 se não foi encontrado
    return -1;
}

int List::searchElement(const int searchData)
{
    return binarySearch(0,Size, searchData);
}

bool List::removeElement(int element)
{
    int pos = binarySearch(0,Size, element);
    if(pos>=0) return removePosition(pos);

    //Retorna false se a posicao não for valida
    return false;
}

bool List::removePosition(const int pos)
{

    Node *perc1, *perc2;
    int cont = 0;

    if(Size==0)
    {
        Begin = End = NULL;
        return 0;
    }

    if(Begin == NULL || pos >= Size || pos < 0)
    {
        //Elemento não encontrado
        return false;
    }

    perc1 = perc2 = Begin;

    if(Begin == End && pos == 0)
    {
        Begin = End = NULL;
        Size--;
        delete perc1;
        return true;
    }

    while(perc1 != NULL && cont < pos)
    {
        perc2 = perc1;
        perc1 = perc1->getNext();
        cont++;
    }

    if(perc1 == Begin)
    {
        Begin = perc1->getNext();
        perc1->setNext(NULL);
    }

    else if(perc1 == End)
    {
        End = perc2;
        End->setNext(NULL);
    }

    else
    {
        perc2->setNext(perc1->getNext());
        perc1->setNext(NULL);
    }

    Size--;
    return true;
}

bool List::ostreamData(ostream& out) const
{

    Node *perc;

    perc = Begin;
    if(Begin==NULL)
    {
        //Retorna false se a lista é vazia
        return false;
    }
    while(perc!=NULL)
    {
        out << perc->getData() << endl;
        perc = perc->getNext();
    }
    return true;
}

bool List::ifstreamData(istream& in)
{

    int element;

    while(in >> element)
    {
        //O cast garante que o que for lido vai ser do tipo int
        insertElementOrdened((int)element);
    }
}

List::~List()
{
    int lastSize = Size;

    for(int i = 0; i<=lastSize; i++)
    {
        removePosition(0);
    }

    delete Begin;
    delete End;

    if(!ostreamData(cout)) cout << endl << "Lista Vazia!";
}

List::Node::~Node()
{
    delete next;
}


bool List::operator() (int position)
{

    if(position>=Size) return false;

    Node *perc;

    perc = Begin;

    while(position!=0)
    {
        perc = perc->getNext();
        position-=1;
    }
    cout << perc->getData() << endl;

}

bool List::operator+= (const int newElement)
{
    return insertElementOrdened(newElement);
}

bool List::operator-= (const int remElement)
{
    return removeElement(remElement);
}

ostream& operator<<(ostream& output, const List& flowOut)
{

    List::Node *perc;

    perc = flowOut.Begin;
    if(flowOut.Begin==NULL)
    {
        //Retorna false se a lista é vazia
        return output;
    }
    while(perc!=NULL)
    {
        output << perc->getData() << endl;
        perc = perc->getNext();
    }
    return output;
}

istream& operator>>(istream& input, List& flowIn)
{

    int element;

    while(input >> element)
    {
        //O cast garante que o que for lido vai ser do tipo int
        flowIn.insertElementOrdened((int)element);
    }
}
/*
const List List::operator+ (List& concatList){

    List auxList;
    int dataTemp;
    Node *perc;

    perc = Begin;
    while(perc!=NULL)
    {
        dataTemp = perc->getData();
        auxList.insertElementOrdened(dataTemp);
        perc = perc->getNext();
    }
    delete perc;
    perc = concatList.Begin;
    while(perc!=NULL)
    {
        dataTemp = perc->getData();
        auxList.insertElementOrdened(dataTemp);
        perc = perc->getNext();
    }

    auxList.printList();
    return auxList;
}

const List List::operator+= (const List& concatList){

    int dataTemp;
    Node *perc;

    perc = concatList.Begin;
    while(perc!=NULL)
    {
        dataTemp = perc->getData();
        insertElementOrdened(dataTemp);
        perc = perc->getNext();
    }


    //return *this;
}*/

void List::freeList(){
 int lastSize = Size;

    for(int i = 0; i<=lastSize; i++)
    {
        removePosition(0);
    }

    delete Begin;
    delete End;

    if(!ostreamData(cout)) cout << endl << "Lista Vazia!";
}

}
