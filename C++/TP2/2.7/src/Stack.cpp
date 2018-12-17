#include "../include/Stack.h"

using namespace std;

Stack::Stack()
{
    End = Begin = NULL;
    Size = 0;
}

Stack::Node::Node(int newData, Node* newNext)
{
    data = newData;
    next = newNext;
}

int Stack::Node::getData() const
{
    return data;
}

Stack::Node* Stack::Node::getNext() const
{
    return next;
}

void Stack::Node::setData(int newData)
{
    data = newData;
}

void Stack::Node::setNext(Node* newNext)
{
    next = newNext;
}

bool Stack::insertElementOrdened(const int newData)
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

int Stack::binarySearch(int searchBegin, int searchEnd,const int& searchData)
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

int Stack::searchElement(const int searchData)
{
    return binarySearch(0,Size, searchData);
}

bool Stack::removeElement(int element)
{
    int pos = binarySearch(0,Size, element);
    if(pos>=0) return removePosition(pos);

    //Retorna false se a posicao não for valida
    return false;
}

bool Stack::removePosition(const int pos)
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

bool Stack::ostreamData(ostream& out) const
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

bool Stack::ifstreamData(istream& in)
{

    int element;

    while(in >> element)
    {
        //O cast garante que o que for lido vai ser do tipo int
        insertElementOrdened((int)element);
    }
}

Stack::~Stack()
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

Stack::Node::~Node()
{
    delete next;
}
