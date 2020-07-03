#include <iostream>
#include <ctime>
#include <cmath>
#include "llrbt.h"

using namespace std;

int main()
{
    LLRBT<int> tree;
    int A[10];

    for (int i = 0; i < 10; i++) {
        int value = rand() % 100;
        cout << "Inserting Value: " << value << endl;
        A[i] = value;
        tree.insert(value);
        if (i > 0){
            cout << endl;
            tree.printParent(value);
        }
    }

    cout << "Resulting tree: " << endl;
    tree.print();

    tree.remove(A[3]);

    cout << endl << "Tree after removal of " << A[3] << ": " << endl;
    tree.print();

    cout << endl << "DONE" << endl << endl;

    return 0;
}