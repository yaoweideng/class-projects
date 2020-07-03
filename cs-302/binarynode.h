#ifndef BINARY_NODE_
#define BINARY_NODE_

#include<iostream>
#include <memory>

using namespace std;

template <class ItemType>
class BinaryNode{
	private: 
		ItemType item;
		BinaryNode<ItemType> *leftChildPtr;
		BinaryNode<ItemType> *rightChildPtr;
	public:
		BinaryNode();
		BinaryNode(const ItemType& itemA);
		BinaryNode(const ItemType& itemA, BinaryNode<ItemType> *leftPtr, BinaryNode<ItemType> *rightPtr);
		void setItem(const ItemType& itemA);
		ItemType getItem() const;
        void setLeftChildPtr(BinaryNode<ItemType> *leftPtr);
		void setRightChildPtr(BinaryNode<ItemType> *rightPtr);
		BinaryNode<ItemType>* getLeftChildPtr() const;
		BinaryNode<ItemType>* getRightChildPtr() const;
};

template <class ItemType>
BinaryNode<ItemType>::BinaryNode(){
	item = NULL;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}

template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& itemA){
	setItem(itemA);
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}

template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& itemA, BinaryNode<ItemType> *leftPtr, BinaryNode<ItemType> *rightPtr){
	setItem(itemA);
	leftChildPtr = leftPtr;
	rightChildPtr = rightPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& itemA){
	item = itemA;
}

template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const{
	return item;
}

template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType> *leftPtr){
	leftChildPtr = leftPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType> *rightPtr){
	rightChildPtr = rightPtr;
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const{
	return leftChildPtr;
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const{
	return rightChildPtr;
}

#endif
