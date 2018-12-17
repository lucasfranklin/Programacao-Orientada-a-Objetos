#ifndef List_H
#define List_H

#include <iostream>
#include <fstream>

namespace DataStructure
{

class List
{

    class Node
    {
    private:
        int data;
        Node* next;

    public:
        Node(int newData, Node* newNext);
        int getData() const;
        Node* getNext() const;
        void setData(int newData);
        void setNext(Node* newNext);
        ~Node();
    };

private:
    Node* Begin;
    Node* End;
    int Size;

public:
    List();
    List(const List& copyObject);
    bool insertElementOrdened(const int newData);
    bool printList() const;
    int searchElement(const int dado);
    bool removeElement(const int element);
    bool readElements(const std::string fileName);
    bool ostreamData(std::ostream& out) const;
    bool ifstreamData(std::istream& in);
    Node* getEnd() const;
    Node* getBegin() const;
    bool getElement(int pos);
    ~List();
    //Sobrecarga de operadores
    List operator=(List& attList);
    bool operator() (int position);
    const List operator+ (List& concatList);
    const List operator+= (const List& concatList);
    bool operator+= (const int newElement);
    bool operator-= (const int remElement);
    friend  std::istream& operator>>(std::istream& input, List& flowIn);
    friend std::ostream& operator<<(std::ostream& output, const List& flowOut);

private:
    int binarySearch(int searchBegin, int searchEnd,const int& searchData);
    bool removePosition(const int pos);
    void freeList();

};
}
#endif // List_H
