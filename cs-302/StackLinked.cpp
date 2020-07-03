#include <iostream>
#include "StackLinked.h"

using namespace std;

const int max_number = 50;

template<typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber) : top(NULL){
}

template<typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked<DataType> &other){
    StackNode *curr = top;
    StackNode *curr2 = other.top;
    while(curr2 != NULL){
        curr = new StackNode(curr2->dataItem, curr2->next);
        if(top == NULL){
            top = curr;
        }
        curr = curr->next;
        curr2 = curr2->next;
    }
}

template<typename DataType>
StackLinked<DataType> &StackLinked<DataType>::operator=(const StackLinked<DataType> &other){
    if(this != &other){
        StackNode *curr = top;
        StackNode *curr2 = other.top;
        while(curr2 != NULL){
            curr = new StackNode(curr2->dataItem, curr2->next);
            if(top == NULL){
                top = curr;
            }
            curr = curr->next;
            curr2 = curr2->next;
        }
    }
    return *this;
}

template<typename DataType>
StackLinked<DataType>::~StackLinked(){
    clear();
}

template<typename DataType>
void StackLinked<DataType>::push(const DataType &newDataItem) throw (logic_error){
    if(isFull()){
        throw logic_error("stack is full");
    }

    StackNode *node = new StackNode(newDataItem, top);
    top = node;
}

template<typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error){
    if(isEmpty()){
        throw logic_error("stack is empty");
    }

    DataType dt = top->dataItem;
    top = top->next;
    return dt;
}

template<typename DataType>
void StackLinked<DataType>::clear(){
    while(top){
        delete top;
        top = NULL;
    }
}

template<typename DataType>
bool StackLinked<DataType>::isEmpty() const{
    if(top == NULL){
        return true;
    } else {
        return false;
    }
}

template<typename DataType>
bool StackLinked<DataType>::isFull() const{
    int c = 0;
    StackNode *curr = top;
    while(curr){
        curr = curr->next;
        c++;
    }
    if(c == max_number){
        return true;
    } else {
        return false;
    }
}

template<typename DataType>
void StackLinked<DataType>::showStructure() const{
    if(!isEmpty()){
        StackNode *curr = top;
        while(curr){
            cout << curr->dataItem << endl;
            curr = curr->next;
        }
    } else {
        cout << "stack is empty" << endl;
    }
}

template<typename DataType> // parametrized constructor - gets rid of linker error
StackLinked<DataType>::StackNode::StackNode(const DataType &nodeData, StackNode *nextPtr){
    dataItem = nodeData;
    next = nextPtr;
}
