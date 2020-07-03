#include <iostream>
#include "ArrayQueue.h"
using namespace std;

ostream &operator<<(ostream &os, const ArrayQueue &arrayQueue){ // extraction operator
    arrayQueue.serialize(os);
    return os;
}

ArrayQueue::ArrayQueue(){ // default constructor
    m_size = 0;
}

ArrayQueue::ArrayQueue(size_t count, const DataType &value){ // parametrized constructor
    m_size = count;
    for(size_t i = 0; i < m_size; i++){
        m_array[i] = value;
    }
}

ArrayQueue::ArrayQueue(const ArrayQueue &other){ // copy constructor
    if(this != &other){
        m_size = other.m_size;
        m_front = other.m_front;
        m_back = other.m_back;
    }
    for(size_t i = 0; i < m_size; i++){
        m_array[i] = other.m_array[i];
    }
}

ArrayQueue::~ArrayQueue(){ // destructor, same as clear method
    clear();
}

ArrayQueue &ArrayQueue::operator=(const ArrayQueue &rhs){ // assignment operator
    if(this != &rhs){
        clear();
        m_size = rhs.m_size;
        m_front = rhs.m_front;
        m_back = rhs.m_back;
        for(size_t i = 0; i < m_size; i++){
            m_array[i] = rhs.m_array[i];
        }
    }
    return *this;
}

DataType &ArrayQueue::front(){ // returns front element
    return m_array[m_front];
}

const DataType &ArrayQueue::front() const{ 
    return m_array[m_front];
}

DataType &ArrayQueue::back(){ // returns back element
    return m_array[m_back];
}

const DataType &ArrayQueue::back() const{
    return m_array[m_back];
}

void ArrayQueue::push(const DataType &value){ // inserts an element at the back
    if(m_size != ARRAY_MAX){
        m_back = (m_back + 1) % ARRAY_MAX;
        m_size++;
        m_array[m_back] = value;
    }
}

void ArrayQueue::pop(){ // removes the front element
    if(m_size != 0){
        m_front = (m_front + 1) % ARRAY_MAX;
        m_size--;
    }
}

size_t ArrayQueue::size() const{ // returns size 
    return m_size;
}

bool ArrayQueue::empty() const{ // checks to see if empty
    if(m_size == 0){
        return true;
    }
    else{
        return false;
    }
}

bool ArrayQueue::full() const{ // checks to see if full
    if(m_size == ARRAY_MAX){
        return true;
    }
    else{
        return false;
    }
}

void ArrayQueue::clear(){ // empties queue
    DataType x;
    for(size_t i = 0; i < m_size; i++){
        m_array[i] = x;
    }
}

void ArrayQueue::serialize(ostream &os) const{ // outputs all elements of the queue
    for(size_t i = 0; i < m_size; i++){
        os << m_array[i] << endl;
    }
}