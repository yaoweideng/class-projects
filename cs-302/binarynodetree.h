#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE

#include "binarynode.h"
#include <iostream>

using namespace std;

template<class ItemType>

class BinaryNodeTree{
	private:
		BinaryNode<ItemType>* rootPtr;

	public:
		BinaryNodeTree();
		BinaryNodeTree(const ItemType& itemR);
		BinaryNodeTree(const ItemType& itemR, const BinaryNodeTree<ItemType>* leftTreePtr, const BinaryNodeTree<ItemType>* rightTreePtr);
		BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr);
		virtual ~BinaryNodeTree();
		bool isEmpty() const;
        void setRootData(const ItemType& data);
		int getHeight() const;
		int getNumberOfNodes() const;
		ItemType getRootData() const;
        ItemType getEntry(const ItemType& entry) const;
        int getHeightH(BinaryNode<ItemType>* subTreePtr) const;
		int getNumberOfNodesH(BinaryNode<ItemType>* subTreePtr) const;
		bool add(const ItemType& data);
		bool remove(const ItemType& data);
		void clear();
		bool contains(const ItemType& entry) const;
		BinaryNodeTree& operator=(const BinaryNodeTree& rhs);
		void destroyTree(BinaryNode<ItemType>* subTreePtr);
		BinaryNode<ItemType>* balancedAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);
		BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success);
		BinaryNode<ItemType>* moveValuesUpTree(BinaryNode<ItemType>* subTreePtr);
		BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const;
		BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* treePtr) const;

};

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightH(BinaryNode<ItemType>* subTreePtr) const{
    int height;
	if(subTreePtr == NULL){
		height = 0;
	}
	else{
        if(getHeightH(subTreePtr->getLeftChildPtr()) > getHeightH(subTreePtr->getRightChildPtr())){
            height = getHeightH(subTreePtr -> getLeftChildPtr());
        } else{
            height = getHeightH(subTreePtr -> getRightChildPtr());
        }
	}
    return height + 1;
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesH(BinaryNode<ItemType>* subTreePtr) const{
	if(subTreePtr == NULL){
		return 0;
	}
	else{
		return 1 + getNumberofNodesH(subTreePtr -> getLeftChildPtr()) + getNumberofNodesH(subTreePtr -> getRightChildPtr());
	}
}

template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr){
	if(subTreePtr != NULL){
		destroyTree(subTreePtr -> getLeftChildPtr());
		destroyTree(subTreePtr -> getRightChildPtr());
		delete subTreePtr;
	}
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(){
	rootPtr = NULL;
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& itemR){
	rootPtr = new BinaryNode<ItemType>(itemR);
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& itemR, const BinaryNodeTree<ItemType>* leftTreePtr, const BinaryNodeTree<ItemType>* rightTreePtr){
	rootPtr = new BinaryNode<ItemType>(itemR, copyTree(leftTreePtr -> rootPtr), copyTree(rightTreePtr -> rootPtr));
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr){
		rootPtr = copyTree(treePtr.rootPtr);
}

template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree(){
	destroyTree(rootPtr);
}

template<class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const{
	if(rootPtr == NULL){
		return true;
	}
	else{
        return false;
    }
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const{
	return getHeightH(rootPtr);
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const{
	return getNumberofNodesH(rootPtr);
}

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const{
	return rootPtr -> getItem();
}

template<class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& data){
	if(isEmpty() == true){
		rootPtr = new BinaryNode<ItemType>(data, NULL, NULL);
	}
	else{
		rootPtr -> setItem(data);
	}
}

template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& data){
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(data, NULL, NULL);
	rootPtr = balancedAdd(rootPtr, newNodePtr);
	return true;
}

template<class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& data){
	bool success = false;
	rootPtr = removeValue(rootPtr, data, success);
	return success;
}

template<class ItemType>
void BinaryNodeTree<ItemType>::clear(){
	destroyTree(rootPtr);
	rootPtr -> reset();
}

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& entry) const{
	bool success = false;
	BinaryNode<ItemType>* nodePtr = findNode(rootPtr, entry, success);
	if(success == true){
		return nodePtr -> getItem();
	}
}

template<class ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType& entry) const{
	bool success = false;
	findNode(rootPtr, entry, success);
	return success;
}

template<class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree& rhs){
	if(this != &rhs){
		if(rootPtr != NULL){
			clear();
			rootPtr = copyTree(rhs.rootPtr);
		}
	}
	return *this;
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::balancedAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr){
	BinaryNode<ItemType> *leftPtr = subTreePtr->getLeftChildPtr();
	BinaryNode<ItemType> *rightPtr = subTreePtr->getRightChildPtr();
	if(getHeightH(leftPtr) > getHeightH(rightPtr)){
		rightPtr = balancedAdd(rightPtr, newNodePtr);
		subTreePtr->setRightChildPtr(rightPtr);
	}
	else{
		leftPtr = balancedAdd(leftPtr, newNodePtr);
		subTreePtr->setLeftChildPtr(leftPtr);
	}
	return subTreePtr;
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success){
	if(subTreePtr -> getItem() == target){
		subTreePtr = moveValuesUpTree(subTreePtr);
		success = true;
		return subTreePtr;
	} else{		
        BinaryNode<ItemType>* targetNodePtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
		subTreePtr -> setLeftChildPtr(targetNodePtr);
		if(success == false){
			targetNodePtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
			subTreePtr -> setRightChildPtr(targetNodePtr);
		}
		return subTreePtr;
	}
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::moveValuesUpTree(BinaryNode<ItemType>* subTreePtr){
	BinaryNode<ItemType>* leftPtr = subTreePtr -> getLeftChildPtr();
	BinaryNode<ItemType>* rightPtr = subTreePtr -> getRightChildPtr();
	int HeightL = getHeightH(leftPtr);
	int HeightR = getHeightH(rightPtr);
	if(HeightL > HeightR){
		subTreePtr -> setItem(leftPtr -> getItem());
		leftPtr = moveValuesUpTree(leftPtr);
		subTreePtr -> setLeftChildPtr(leftPtr);
		return subTreePtr;
	}
	else{
		if(rightPtr != NULL){
			subTreePtr -> setItem(rightPtr -> getItem());
			rightPtr = moveValuesUpTree(rightPtr);
			subTreePtr -> setRightChildPtr(rightPtr);
			return subTreePtr;
		}
		else{
			return NULL;
		}
	}
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::findNode(BinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const{
	if(treePtr -> getItem() == target){
		success = true;
		return treePtr;
	}
	else{
		BinaryNode<ItemType>* targetNodePtr = findNode(treePtr -> getLeftChildPtr(), target, success);
		if(success == false){
			targetNodePtr = findNode(treePtr->getRightChildPtr(), target, success);
		}
		return targetNodePtr;
	}
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const{
	BinaryNode<ItemType>* newPtr;
	if(treePtr != NULL){
		newPtr = new BinaryNode<ItemType>(treePtr->getItem(), NULL, NULL);
		newPtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
		newPtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
	}
	return newPtr;
}

#endif
