#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>

class Stack
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
    Stack();
    bool insertElementOrdened(const int newData);
    bool printStack() const;
    int searchElement(const int dado);
    bool removeElement(const int element);
    bool readElements(const std::string fileName);
    bool ostreamData(std::ostream& out) const;
    bool ifstreamData(std::istream& in);
    ~Stack();

private:
    int binarySearch(int searchBegin, int searchEnd,const int& searchData);
    bool removePosition(const int pos);
};

#endif // STACK_H
