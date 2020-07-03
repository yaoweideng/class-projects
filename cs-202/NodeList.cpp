// Student: Yaowei Deng
// Assignment: Project 7
// Class: CS 202.1001, Christos Papachristos, Spring 2019

#include <iostream>
#include <cstring>
#include "NodeList.h"

using namespace std;

NodeList::NodeList(): // default constructor
m_head(NULL){}

NodeList::NodeList(size_t count, const DataType &value){ // parametrized constructor
}

NodeList::NodeList(const NodeList &other){ // copy constructor
}
    
NodeList::~NodeList(){ // destructor
    Node *curr = m_head;
    Node *prev = m_head;
    while(curr != NULL){
        curr = curr->m_next;
        delete prev;
        prev = curr;
    }
    m_head = NULL;
}

NodeList &NodeList::operator=(const NodeList &rhs){ // assignment operator
    if(this != &rhs){
        Node *temp_ptr1 = m_head;
        Node *temp_ptr2 = rhs.m_head;
        while (temp_ptr2->m_next != NULL){
            temp_ptr1->m_data = temp_ptr2->data();
            temp_ptr1 = temp_ptr1->m_next;
            temp_ptr2 = temp_ptr2->m_next;
        }
    }
    return *this;
}

Node *NodeList::front(){
}

Node *NodeList::back(){
}
	
Node *NodeList::find(const DataType &target, Node *&previous, const Node *start){
}
	
Node *NodeList::insertAfter(const DataType &target, const DataType &value){
}
    
Node *NodeList::insertBefore(const DataType &target, const DataType &value){
}
    
Node *NodeList::erase(const DataType &target){
}

DataType &NodeList::operator[](size_t position){
}

const DataType &NodeList::operator[](size_t position) const{
}
    
size_t NodeList::size() const{
}
    
bool NodeList::empty() const{ // checks to see if the list is empty
    if(m_head){
        return false;
    }
    return true;
}

void NodeList::clear(){ // clears the node list
    Node *curr = m_head;
    Node *prev = m_head;
    while(curr != NULL){
        curr = curr->m_next;
        delete prev;
        prev = curr;
    }
    m_head = NULL;
}

ostream &operator<<(ostream &os, const NodeList &nodeList){ // extraction operator
    for(size_t i = 0; i < nodeList.size(); i++){
        os << nodeList[i] << endl;
    }
    return os;
}

