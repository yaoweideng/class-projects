#include <iostream>
#include <cstdlib>
#include "binarysearchtree.h"

const int NUM_RAND = 100;

using namespace std;

int main(){

    int tvals[NUM_RAND];

    for(int i = 0; i < NUM_RAND; i++){
        bool unique = false;
        int temp;
	    while(unique == false){
		    unique = true;
		    temp = (rand() % 200) + 1; 
		    for(int j = 0; j < i; j++){
			    if(temp == tvals[j]){
				    unique = false;
			    }
		    }
	    }
	    tvals[i] = temp;
    }

    BinarySearchTree<int> theTree;
    for(int i = 0; i < NUM_RAND; i++){
	    theTree.add(tvals[i]);
    }

    cout << "---------------------------------------------------------" << endl;
    cout << endl << "HEIGHT: " << theTree.getHeight() << endl << endl;
    cout << "------------IN ORDER------------" << endl; 
    theTree.inorderTraverse(); 
    cout << endl << endl << "------------PRE ORDER------------" << endl;
    theTree.preorderTraverse();
    cout << endl << endl << "------------POST ORDER------------" << endl;
    theTree.postorderTraverse();
    cout << endl << endl;
}

