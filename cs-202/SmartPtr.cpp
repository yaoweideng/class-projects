// Student: Yaowei Deng
// Assignment: Project X
// Class: CS 202.1001, Christos Papachristos, Spring 2019

#include <iostream>
#include <cstring>
#include "SmartPtr.h"

using namespace std;

SmartPtr::SmartPtr(){ // default constructor 
    m_ptr = new DataType; 
    m_refcount = new size_t;
    *m_refcount = 1;

    cout << "SmartPtr Default Constructor for new allocation, RefCount= " << *m_refcount << endl;
}

SmartPtr::SmartPtr(DataType *data){ // parametrized constructor 
    m_ptr = data;
    m_refcount = new size_t;
    if (m_ptr){ // if m_ptr is not NULL 
        *m_refcount = 1;
    }
    else {
        *m_refcount = 0;
    }

    cout << "SmartPtr Parametrized Constructor from data pointer, RefCount= " << *m_refcount << endl;
}

SmartPtr::SmartPtr(const SmartPtr &other){ // copy constructor 
    m_ptr = other.m_ptr;
    if (other.m_ptr){ // if m_ptr of the passed parameter is not NULL
        m_refcount = other.m_refcount;
        (*m_refcount)++;
    }
    else { // if m_ptr of the passed parameter is NULL
        m_refcount = new size_t;
        *m_refcount = 0;
    }

    cout << "SmartPtr Copy Constructor, RefCount= " << *m_refcount << endl;
}

SmartPtr::~SmartPtr(){ // destructor 
    if (m_ptr){
        (*m_refcount)--;
    }

    cout << "SmartPtr Destructor, RefCount= " << *m_refcount << endl;

    if (*m_refcount == 0){
        delete m_refcount;
        m_ptr = NULL;
        delete m_ptr;
        *m_refcount = 0;
    }
}

SmartPtr &SmartPtr::operator=(const SmartPtr &rhs){ // assignment operator
    if (m_refcount){ // frees memory first 
        (*m_refcount)--;
    }
    if (*m_refcount == 0){
        delete m_refcount;
        m_ptr = NULL;
        delete m_ptr;
        *m_refcount = 0;
    }

    m_ptr = rhs.m_ptr; // assigns pointers to those of rhs
    if (rhs.m_ptr){
        m_refcount = rhs.m_refcount;
        (*m_refcount)++;
    }
    else {
        m_refcount = new size_t;
        *m_refcount = 0;
    }

    cout << "SmartPtr Copy Assignment, RefCount= " << *m_refcount << endl;
    return *this;
}

DataType &SmartPtr::operator*(){ // dereference operator
    return *m_ptr;
}

DataType *SmartPtr::operator->(){ // member access operator 
    return m_ptr;
}