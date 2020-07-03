#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int main()
{
    vector<int> v1;
    int b = 0;
    
    //generating the random values
    for(int i = 0; i < 100; i++){
        int a = rand() % 100 + 1;
        v1.push_back(a);
        b = b + a;
    }

    //finding the average value
    b = b / 100;

    //making the heap
    make_heap(v1.begin(), v1.end());

    //adding the average value
    v1.push_back(b);

    //removing the maximum value
    pop_heap(v1.begin(), v1.end());
    v1.pop_back();

    //sorting the heap
    sort_heap(v1.begin(), v1.end());

    //printing the heap to make sure everything is sorted
    cout << endl;
    for(int i = 0; i < 100; i++){
        cout << v1[i] << " ";
    }
    cout << endl << endl;

    return 0;
} 