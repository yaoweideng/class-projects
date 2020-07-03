#ifndef NODESTACK_H_
#define NODESTACK_H_
#include "DataType.h"
#include <iostream>
using namespace std;

class NodeStack{
    friend ostream &operator<<(ostream &os, const NodeStack &nodeStack){}

    public:
        NodeStack(){}
        NodeStack(size_t count, const DataType &value){}
        NodeStack(const NodeStack &other){}
        ~NodeStack(){}
        NodeStack &operator=(const NodeStack &rhs){}
        DataType &top(){}
        const DataType &top() const{}
        void push(const DataType &value){}
        void pop(){}
        size_t size() const{}
        bool empty() const{}
        bool full() const{}
        void clear(){}
        void serialize(ostream &os) const{}
    private:
        Node *m_top;
};

class Node{
    friend class NodeStack;

    public:
        Node(){}
        Node(const DataType &data, Node *next = NULL){}
        DataType &data(){}
        const DataType &data() const{}
    private:
        Node *m_next;
        DataType m_data;
};

#endif