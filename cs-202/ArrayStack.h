#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_
#include "DataType.h"
#include <iostream>
using namespace std;

const size_t MAX_STACKSIZE = 1000;

template <typename DataType>
class ArrayStack{
    friend ostream &operator<<(ostream &os, const ArrayStack &arrayStack);

    public:
        ArrayStack();
        ArrayStack(size_t count, const DataType &value);
        ArrayStack(const ArrayStack &other);
        ~ArrayStack();
        ArrayStack &operator=(const ArrayStack &rhs);
        DataType &top();
        const DataType &top() const;
        void push(const DataType &value);
        void pop();
        size_t size() const;
        bool empty() const;
        bool full() const;
        void clear();
        void serialize(ostream &os) const;
    private:
        DataType m_container[MAX_STACKSIZE];
        size_t m_top;
};

template <typename DataType>
ArrayStack<DataType>::ArrayStack(){
}

template <typename DataType>
ArrayStack<DataType>::ArrayStack(size_t count, const DataType &value){
    for(size_t i = 0; i < count; i++){
        top++;
        m_container[top] = value;
    }
}

template <typename DataType>
ArrayStack<DataType>::ArrayStack(const ArrayStack &other){
    if(this != &other){
        top = other.top;
        m_container = new DataType[top];
        for(size_t i = 0; i < top; i++){
            m_container[i] = other.m_container[i];
        }
    }
}

template <typename DataType>
ArrayStack<template<typename DataType>>::ArrayStack(){
}

template <typename DataType>
ArrayStack &ArrayStack<DataType>::operator=(const ArrayStack &rhs){
    
}


#endif