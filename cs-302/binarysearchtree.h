#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include "binarynode.h"
#include "binarynodetree.h"
#include <memory>
#include <iostream>

using namespace std;

template<class ItemType>
class BinarySearchTree: public BinaryNodeTree<ItemType>{
	private: 
		BinaryNode<ItemType>* rootPtr;
	public:
		BinarySearchTree();
		BinarySearchTree(const ItemType& rootItem);
		BinarySearchTree(const BinarySearchTree<ItemType>& tree);
		virtual ~BinarySearchTree();
		bool isEmpty() const;
        void setRootData(const ItemType& data);
		int getHeight() const;
		int getNumberOfNodes() const;
		ItemType getRootData() const;
        ItemType getEntry(const ItemType& entry) const;
		bool add(const ItemType& entry);
		bool remove(const ItemType& target);
		void clear();
		bool contains(const ItemType& target) const;
		void preorderTraverse() const;
		void inorderTraverse() const;
		void postorderTraverse() const;
		BinarySearchTree<ItemType>& operator=(const BinarySearchTree<ItemType>& rhs);
        BinaryNode<ItemType>* placeNode(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode);
		BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful);
		BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>*nodePtr);
		BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType inorderSuccessor);
		BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType& target) const;
		void preorder(BinaryNode<ItemType>* treePtr) const;
		void inorder(BinaryNode<ItemType>* treePtr) const;
		void postorder(BinaryNode<ItemType>* treePtr) const;

};

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(){
    rootPtr = NULL;
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem){
	rootPtr = new BinaryNode<ItemType>(rootItem);
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree){
	rootPtr = copyTree(tree.rootPtr);
	
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree(){
	clear();
}


template<class ItemType>
void BinarySearchTree<ItemType>::preorder(BinaryNode<ItemType>* treePtr) const{
	if(treePtr != NULL){
		ItemType entry = treePtr->getItem();
		cout << entry << " ";
		preorder(treePtr->getRightChildPtr());
		preorder(treePtr->getLeftChildPtr());
	}
}
template<class ItemType>
void BinarySearchTree<ItemType>::inorder(BinaryNode<ItemType>* treePtr) const{
	if(treePtr != NULL){
		inorder(treePtr->getLeftChildPtr());
		ItemType entry = treePtr->getItem();
		cout << entry << " ";
		inorder(treePtr->getRightChildPtr());
	}
}
template<class ItemType>
void BinarySearchTree<ItemType>::postorder(BinaryNode<ItemType>* treePtr) const{
	if(treePtr != NULL){
		postorder(treePtr->getLeftChildPtr());
		postorder(treePtr->getRightChildPtr());
		ItemType entry = treePtr->getItem();
		cout << entry << " ";
	}
}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const{
	if(rootPtr == NULL){
        return true;
    } else {
        return false;
    }
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const{
	return (this -> getHeightH(rootPtr));
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const{
	return(this -> getNumberOfNodesH(rootPtr));
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const{
	rootPtr -> getItem();
}

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& data){
	if(isEmpty() == true){
		rootPtr = new BinaryNode<ItemType>(data);
	}
	else{
        rootPtr -> setItem(data);
    }
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& entry){
	BinaryNode<ItemType>* tempPtr = new BinaryNode<ItemType>(entry);
	rootPtr = placeNode(rootPtr, tempPtr);
	return true;
		
}

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target){
	bool success = false;
	rootPtr = removeValue(rootPtr, target, success);
	return success;
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear(){
	this -> rootPtr = NULL;
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& entry) const{
	BinaryNode<ItemType>* nodePtr;
	nodePtr = findNode(rootPtr, entry);
	if(nodePtr != NULL){
		return nodePtr->getItem();
	}
}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& target) const{
	BinaryNode<ItemType>* nodePtr;
	nodePtr = findNode(rootPtr, target);
	if(nodePtr != NULL){
		return true;
	}
	else return false;
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::placeNode(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode){
	if(subTreePtr == NULL){
		return newNode;
	}
	else{
		BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
		BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();
		if(subTreePtr -> getItem() > newNode -> getItem()){
			leftPtr = placeNode(leftPtr, newNode);
			subTreePtr -> setLeftChildPtr(leftPtr);
		}
		else{
			rightPtr = placeNode(rightPtr, newNode);
			subTreePtr -> setRightChildPtr(rightPtr);
		} 
		return subTreePtr;
	}
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful){
	BinaryNode<ItemType>* tempPtr;
	if(subTreePtr == NULL){
		isSuccessful = false;
		return NULL;
	}
	else if(subTreePtr -> getItem() == target){
		subTreePtr = removeNode(subTreePtr, target, isSuccessful);
		isSuccessful = true;
		return subTreePtr;
	}
	else if(subTreePtr -> getItem() > target){
		tempPtr = removeNode(subTreePtr->getLeftChildPtr(), target, isSuccessful);
		subTreePtr->setLeftChildPtr(tempPtr);
		return subTreePtr;
	}
	else{
		tempPtr = removeNode(subTreePtr->getRightChildPtr(), target, isSuccessful);
		subTreePtr -> setRightChildPtr(tempPtr);
		return subTreePtr;
	}		
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType>*nodePtr){
	BinaryNode<ItemType>* tempPtr;
	if(nodePtr -> getLeftChildPtr() == NULL){		
		tempPtr = nodePtr -> getRightChildPtr();
		delete nodePtr;
		nodePtr = NULL;
		return tempPtr;
	}
	else if(nodePtr -> getRightChildPtr() == NULL){
		tempPtr = nodePtr -> getLeftChildPtr();
		delete nodePtr;
		nodePtr = NULL;
		return tempPtr;
	}
	else{
		ItemType newNodeValue;
		tempPtr = removeLeftmostNode(nodePtr -> getRightChildPtr(), newNodeValue);
		nodePtr -> setRightChildPtr(tempPtr);
		nodePtr -> setItem(newNodeValue);
		return nodePtr;
	}
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType inorderSuccessor){
	BinaryNode<ItemType>* tempPtr;
	if(subTreePtr -> getLeftChildPtr() == NULL){
		inorderSuccessor = subTreePtr->getItem();
		return removeNode(subTreePtr);
	}
	else{
		tempPtr = removeLeftmostNode(subTreePtr->getLeftmostNode(), inorderSuccessor);
		subTreePtr -> setLeftChildPtr(tempPtr);
		return subTreePtr;
	}
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* treePtr, const ItemType& target) const{
	BinaryNode<ItemType>* tempPtr;
	tempPtr = treePtr;
	if(treePtr -> getItem() == target){
		return treePtr;
	}
	else if(treePtr -> getItem() > target){
		tempPtr = findNode(treePtr -> getLeftChildPtr(), target);
	}
	else{
		tempPtr = findNode(treePtr -> getRightChildPtr(), target);
	}
	return tempPtr;
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse() const{
	preorder(rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse() const{
	inorder(rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse() const{
	postorder(rootPtr);
}

template<class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType>& rhs){
	if(this != &rhs){
		if(rootPtr){
			clear();
			rootPtr = copyTree(rhs.rootPtr);
		}
	}
	return *this;
}

#endif