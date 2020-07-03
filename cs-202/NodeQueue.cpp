#include <iostream>
#include "NodeQueue.h"
using namespace std;

ostream &operator<<(ostream &os, const NodeQueue &nodeQueue){ // using the serialize operator for extraction operator overloading
    nodeQueue.serialize(os);
    return os;
}

NodeQueue::NodeQueue(){ // default constructor
    m_front = NULL;
    m_back = NULL;
}

NodeQueue::NodeQueue(size_t size, const DataType &value){ // parametrized constructor
    m_front = new Node(value);
    Node *curr = m_front;
    for(size_t i = 0; i < size; i++){
        curr->m_next = new Node(value);
        curr = curr->m_next;
        m_back = curr;
    }
}

NodeQueue::NodeQueue(const NodeQueue &other){ // copy constructor
    if(this != &other){
        Node *otherCurr = other.m_front;
        m_front = new Node(otherCurr->m_data);
        Node *curr = m_front;
        otherCurr = otherCurr->m_next;
        while(otherCurr != NULL){
            curr->m_next = new Node(otherCurr->m_data);
            curr = curr->m_next;
            m_back = curr;
            otherCurr = otherCurr->m_next;
        }
    }
}

NodeQueue::~NodeQueue(){ // destructor
    if(m_front != NULL){
        m_back = NULL;
        Node *Node_ptr = m_front;
        while(m_front != NULL){
            m_front = m_front->m_next;
            Node_ptr->m_next = NULL;
            delete Node_ptr;
            Node_ptr = m_front;
        }
    }
}

NodeQueue &NodeQueue::operator=(const NodeQueue &rhs){ // assignment operator, combines destructor + copy constructor
    if(this != &rhs){
        if(m_front != NULL){
            m_back = NULL;
            Node *Node_ptr = m_front;
            while(m_front != NULL){
                m_front = m_front->m_next;
                Node_ptr->m_next = NULL;
                delete Node_ptr;
                Node_ptr = m_front;
            }
        }
        Node *otherCurr = rhs.m_front;
        m_front = new Node(otherCurr->m_data);
        Node *curr = m_front;
        otherCurr = otherCurr->m_next;
        while(otherCurr != NULL){
            curr->m_next = new Node(otherCurr->m_data);
            curr = curr->m_next;
            m_back = curr;
            otherCurr = otherCurr->m_next;
        }
    }
    return *this;
}

DataType &NodeQueue::front(){ // returns front element
    return m_front->m_data;
}

const DataType &NodeQueue::front() const{
    return m_front->m_data;
}

DataType &NodeQueue::back(){ // returns back element
    return m_back->m_data;
}

const DataType &NodeQueue::back() const{
    return m_back->m_data;
}

void NodeQueue::push(const DataType &value){ // push method, adds an element to the back of the queue
    Node *Node_ptr = new Node(value);
    m_back->m_next = Node_ptr;
    m_back = Node_ptr;
    Node_ptr = NULL;
}

void NodeQueue::pop(){ // pop method, removes the first element 
    if(m_front != NULL){
        Node *Node_ptr = m_front;
        m_front = m_front->m_next;
        delete Node_ptr;
        Node_ptr = NULL;
    }
}

size_t NodeQueue::size() const{ // return size function
    size_t c = 0;
    if(m_front != NULL){
        Node *curr = m_front;
        while(curr != NULL){
            c++;
            curr = curr->m_next;
        }
    }
    return c;
}

bool NodeQueue::empty() const{ // checks to see if empty
    if(m_front != NULL){
        return false;
    }
    else{
        return true;
    }
}

bool NodeQueue::full() const{ // always returns false, since there are no bounds set
    return false;
}

void NodeQueue::clear(){ // clear method, same as destructor
    if(m_front != NULL){
        m_back = NULL;
        Node *Node_ptr = m_front;
        while(m_front != NULL){
            m_front = m_front->m_next;
            Node_ptr->m_next = NULL;
            delete Node_ptr;
            Node_ptr = m_front;
        }
    }
}

void NodeQueue::serialize(ostream &os) const{ // serialize (output) operator
    Node *curr = m_front;
    for(size_t i = 0; i < size(); i++){
        os << curr->m_data << endl;
        curr = curr->getNext();
    }
}