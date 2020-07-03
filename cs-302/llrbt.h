#ifndef LLRBT_H
#define LLRBT_H
#include <iostream>

using namespace std;

template <typename DataType>
struct Node {
    DataType key;
    Node *left, *right;
    int n;
    bool color;
    Node(DataType k): key(k), left(0), right(0), n(1), color(true){}
    ~Node(){
        delete left; 
        delete right; 
    }
};

template <typename DataType>
class LLRBT
{
    public:
        LLRBT();
        ~LLRBT();
        void insert(const DataType key);
        void remove(const DataType key);
        void print();
        void printParent(const DataType key);
        void printParentN(Node<DataType> *root, const DataType key);
        void swap(Node<DataType> *x);
        bool is_red(const Node<DataType> *x);
        static void printN(const Node<DataType> *root);
        Node<DataType> *insertN(Node<DataType> *x, const DataType key);
        Node<DataType> *removeM(Node<DataType> *x);
        Node<DataType> *removeN(Node<DataType> *x, const DataType key);
        Node<DataType> *rotateL(Node<DataType> *x);
        Node<DataType> *rotateR(Node<DataType> *x);
        Node<DataType> *rotateT(Node<DataType> *x);
    private:
        Node<DataType> *root = nullptr;
};

template <typename DataType>
LLRBT<DataType>::LLRBT(){}

template <typename DataType>
LLRBT<DataType>::~LLRBT()
{
    delete root;
}

template <typename DataType>
void LLRBT<DataType>::insert(const DataType key) {
    root = insertN(root, key);
    if(root != nullptr) {
        root -> color = false;
    }
}

template <typename DataType>
Node<DataType> *LLRBT<DataType>::insertN(Node<DataType> *x, const DataType key) {
    if(x == NULL){
        return new Node<DataType>(key);
    }
    if(key < x -> key){
        x -> left = insertN(x -> left, key);
    } else{
        x -> right = insertN(x -> right, key);
    }
    ++x -> n;
    if(is_red(x -> right) == true && is_red(x -> left) == false){
        x = rotateL(x);
    }
    if(is_red(x -> left) == true && is_red(x -> left -> left) == true){
        x = rotateR(x);
    }
    if(is_red(x -> left) == true && is_red(x -> right) == true){
        swap(x);
    }
    return x;
}

template <typename DataType>
void LLRBT<DataType>::remove(const DataType key) {
    if(root != nullptr){
        root -> color = false;
    }
    root = removeN(root, key);
}

template <typename DataType>
Node<DataType> *LLRBT<DataType>::removeN(Node<DataType> *x, const DataType key) {
    if(key < x -> key){
        if(x -> left != NULL){
            if(is_red(x -> left) == false && is_red(x -> left -> left) == false){
                swap(x);
                if(x -> right != NULL && is_red(x -> right -> left) == true){
                    x -> right = rotateR(x -> right);
                    x = rotateL(x);
                    swap(x);
                }
            }
            x -> left = removeN(x -> left, key);
        }
    } else {
        if(x -> key == key && x -> right == NULL){
            delete x;
            return NULL;
        }
        if(is_red(x -> left) == true){
            x = rotateR(x);
        }
        if(x -> right != NULL){
            if(is_red(x -> right) == false && is_red(x -> right -> left) == false){
                swap(x);
                if(x -> left != NULL && is_red(x -> left -> left) == true){
                    x = rotateR(x);
                    swap(x);
                }
            }
            if(x -> key == key){
                x -> right = removeM(x -> right);
            } else{
                x -> right = removeN(x -> right, key);
            }
        }
    }

    return rotateT(x);
}

template <typename DataType>
Node<DataType> *LLRBT<DataType>::rotateL(Node<DataType> *x) {
    Node<DataType> *y = x -> right;
    x -> right = y -> left;
    y -> left = x;
    y -> color = y -> left -> color;
    y -> left -> color = true;
    return y;
}

template <typename DataType>
Node<DataType> *LLRBT<DataType>::rotateR(Node<DataType> *x) {
    Node<DataType> *y = x -> left;
    x -> left = y -> right;
    y -> right = x;
    y -> color = y -> right -> color;
    y -> right -> color = true;
    return y;
}

template <typename DataType>
Node<DataType> *LLRBT<DataType>::rotateT(Node<DataType> *x) {
    if(is_red(x -> right) == true){
        x = rotateL(x);
    }
    if(is_red(x -> left) == true && is_red(x -> left -> left) == true){
        x = rotateR(x);
    }
    if(is_red(x -> left) == true && is_red(x -> right) == true){
        swap(x);
    }
    return x;
}

template <typename DataType>
Node<DataType> *LLRBT<DataType>::removeM(Node<DataType> *x) {
    if(is_red(x -> left) == false && is_red(x -> left -> left) == false){
        swap(x);
        if(x -> right == NULL && is_red(x -> right -> left) == true){
            x -> right = rotateR(x -> right);
            x = rotateL(x);
            swap(x);
        }
    }
    x -> left = removeM(x -> left);
    return rotateT(x);
}

template <typename DataType>
void LLRBT<DataType>::swap(Node<DataType> *x) {
    bool temp;
    temp = x -> color;
    x -> color = !temp;
    if(x -> left != NULL){
        temp = x -> left -> color;
        x -> left -> color = !temp;
    }
    if (x -> right != NULL){
        temp = x -> right -> color;
        x -> right -> color = !temp;
    }
}

template <typename DataType>
bool LLRBT<DataType>::is_red(const Node<DataType> *x){
    return x ? x -> color : false;
}

template <typename DataType>
void LLRBT<DataType>::print(){
    printN(root);
}

template <typename DataType>
void LLRBT<DataType>::printParentN(Node<DataType> *root, const DataType key) {
    if(root -> left != NULL){
        if(root -> left -> key == key){
            cout << "PARENT: " << root -> key << ", ";
            if(is_red(root) == true){
                cout << "COLOR: Red" << endl << endl;
            } else{
                cout << "COLOR: Black" << endl << endl;
            }
        } else{
            printParentN(root -> left, key);
        }
    }
    if(root -> right != NULL){
        if(root -> right -> key == key){
            cout << "PARENT: " << root -> key << ", ";
            if(is_red(root) == true){
                cout << "COLOR: Red" << endl << endl;
            } else{
                cout << "COLOR: Black" << endl << endl;
            }
        } else{
            printParentN(root -> right, key);
        }
    }
}

template <typename DataType>
void LLRBT<DataType>::printParent(const DataType key){
    printParentN(root, key);
}


template <typename DataType>
void LLRBT<DataType>::printN(const Node<DataType> *root){
    if(root != NULL){
        printN(root -> right);  
        if (root -> color == true){
            cout << root -> key << "(red)" << endl;
        } else{
            cout << root -> key << endl;
        }
        printN(root -> left);
    }
}

#endif