// Student: Yaowei Deng
// Assignment: Project 7
// Class: CS 202.1001, Christos Papachristos, Spring 2019

#include <iostream>
#include <cstring>
#include "MyString.h"

using namespace std;

MyString::MyString(){ // Default Constructor
    m_buffer = NULL;
    m_size = 0;
}

MyString::MyString(const char *str): // Parametrized Constructor
m_buffer(NULL) // Initializer List
{
    size_t size = strlen(str) + 1;
    m_size = size;
    buffer_allocate(size);
    strcpy(m_buffer, str);
}

MyString::MyString(const MyString & other_myStr): // Copy Constructor
m_buffer(NULL)
{
    if (this != &other_myStr){
        buffer_allocate(other_myStr.size()); // Allocates memory based on a pass size
        m_size = other_myStr.m_size; // Copies the size from the passed class object
        strcpy(m_buffer, other_myStr.m_buffer);
    }
}

MyString::~MyString(){ // Default Destructor
    delete [] m_buffer;
}

size_t MyString::size() const{ // Size Function 
    return m_size;
}

size_t MyString::length() const{ // Length Function 
    return m_size - 1; 
}

const char *MyString::c_str() const{
    return m_buffer;
}

bool MyString::operator==(const MyString &other_myStr) const{ // Checking equality of the class objects 
    if (this != &other_myStr){
        return false;
    }

    return true;
}

MyString &MyString::operator=(const MyString &other_myStr){ // Equal operator to take string from passed class object and copies them into m_buffer
    this->buffer_deallocate();
    this->buffer_allocate(other_myStr.m_size);
    for(size_t i = 0; i < other_myStr.m_size; i++){
        (*this)[i] = other_myStr[i];
    }
    return *this;
}

MyString MyString::operator+(const MyString &other_myStr) const{ // Addition operator to concatenate two strings of different strings
    size_t size2 = other_myStr.m_size + m_size;
    char *newbuffer;

    newbuffer = new char[size2];
    for(size_t i = 0; i < m_size - 1; i++){
        newbuffer[i] = m_buffer[i];
    }
    for(size_t i = m_size - 1; i < size2; i++){
        newbuffer[i] = other_myStr.m_buffer[i-(m_size-1)];
    }

    return MyString(newbuffer);
}

char &MyString::operator[](size_t index){ // returns passed index of the m_buffer string
    return m_buffer[index];
}

const char &MyString::operator[](size_t index) const{ // returns passed index of the m_buffer string as a const qualifier
    return m_buffer[index];
}

ostream &operator<<(ostream &os, const MyString &myStr){ // extraction operator
    os << myStr.m_buffer;
    return os;
}

void MyString::buffer_deallocate(){ // deallocate method; if the memory of the string has not already been deallocated, deletes 
    if(m_buffer != NULL){
        m_size = 0;
        delete [] m_buffer;
        m_buffer = NULL;
    }
}

void MyString::buffer_allocate(size_t size){ // frees memory of the m_buffer private class member
    try{
        m_size = size;
        m_buffer = new char[size];
    }
    catch(const bad_alloc &e){
        delete [] m_buffer;
    }
}
