// Student: Yaowei Deng
// Assignment: Project 8
// Class: CS 202.1001, Christos Papachristos, Spring 2019

#include <iostream>
#include <cstring>
#include "ArrayList.h"

using namespace std;

ArrayList::ArrayList(): // default constructor
m_array(NULL), m_size(0), m_maxsize(0){}

ArrayList::ArrayList(size_t count, const DataType &value){ // parametrized constructor
    m_array = new DataType[count];
    m_size = count;
    m_maxsize = count;
    for(size_t i = 0; i < m_size; i++){
        m_array[i] = value;
    }
}

ArrayList::ArrayList(const ArrayList &other): // copy constructor
m_array(NULL){
    if(this != &other){
        m_array = new DataType[other.m_maxsize];
        m_size = other.m_size;
        m_maxsize = other.m_maxsize;
    }
    for(size_t i = 0; i < m_size; i++){
        m_array[i] = other.m_array[i];
    }
}

ArrayList::~ArrayList(){ // destructor
    if(m_array){
        delete [] m_array;
        m_array = NULL;
    }
    m_size = 0;
    m_maxsize = 0;
}

ArrayList &ArrayList::operator=(const ArrayList &rhs){ // assignment operator
    if(m_array){
        delete [] m_array;
        m_array = NULL;
    }
    m_size = 0;
    m_maxsize = 0;

    m_array = new DataType[rhs.m_maxsize];
    m_size = rhs.m_size;
    m_maxsize = rhs.m_maxsize;
    for(size_t i = 0; i < m_size; i++){
        m_array[i] = rhs.m_array[i];
    }

    return *this;
}

DataType *ArrayList::front(){ // finds the first valid element of the array
    DataType *array_ptr = m_array;
    if(array_ptr){
        return array_ptr;
    }
    else{
        return NULL;
    }
}

DataType *ArrayList::back(){ // finds the last valid element of the array
    DataType *array_ptr = m_array;
    if(array_ptr){
        for(size_t i = 0; i < m_size - 1; i++, array_ptr++){}
        return array_ptr;
    }
    else{
        return NULL;
    }
}
	
DataType *ArrayList::find(const DataType &target, DataType *&previous, const DataType *start){ // find method 
    DataType *array_ptr = m_array;
    if(array_ptr){
        for(size_t i = 0; i < m_size; i++){
            if(*array_ptr == target){
                array_ptr--;
                if(array_ptr){
                    previous = array_ptr;
                }
                else{
                    previous = NULL;
                }
                array_ptr++;
                return array_ptr;
            }
            array_ptr++;
        }
    }
    previous = NULL;
    return NULL;
}
	
DataType *ArrayList::insertAfter(const DataType &target, const DataType &value){ // insert after
    DataType *curr = m_array;
    while(curr != NULL){
        if(*curr == target){
            DataType *next = curr++;
            *next = value;
            resize(m_size + 1);
            return next;
        }
        curr++;
    }
}

DataType *ArrayList::insertBefore(const DataType &target, const DataType &value){ // insert before
    DataType *curr = m_array;
    while(curr != NULL){
        if(*curr == target){
            DataType *prev = curr--;
            *prev = value;
            resize(m_size - 1);
            return prev;
        }
        curr++;
    }
}

DataType *ArrayList::erase(const DataType &target){ // erase
    DataType *curr = m_array;
    while(curr != NULL){
        if(*curr == target){
            delete [] curr;
            return ++curr;
        }
        curr++;
    }
}
	
DataType &ArrayList::operator[](size_t position){ // position operator
    return m_array[position];
}
    
size_t ArrayList::size() const{ // size function
    return m_size;
}

bool ArrayList::empty() const{ // checking empty function
    if(m_array == NULL){
        if(m_size == 0){
            return true;
        }
    }
    return false;
}

void ArrayList::clear(){ // clear function - same as destructor
    if(m_array){
        delete [] m_array;
        m_array = NULL;
    }
    m_size = 0;
    m_maxsize = 0;
}

void ArrayList::resize(size_t count){ // resize function
    DataType *temp_ptr = new DataType[m_size];
    for(size_t i = 0; i < m_size; i++){ // copies the values to temp array
        temp_ptr[i] = m_array[i];
    }
    delete [] m_array;
    m_size = count;
    m_maxsize = count;
    m_array = new DataType[m_maxsize]; // creates a new object with the size of the passed value
    for(size_t i = 0; i < m_size; i++){ // copies the values from temp array to new object
        m_array[i] = temp_ptr[i];
    }
}

ostream &operator<<(ostream &os, const ArrayList &arrayList){ // extraction operator for array list
    for(size_t i = 0; i < arrayList.m_size; i++){
        os << arrayList.m_array[i] << endl;
    }
    
    return os;
}