#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
const int MAX_SIZE = 100;
const int TEST_SIZE = 10;
const int ARRAY_LEN_1 = 1000;
const int ARRAY_LEN_2 = 10000;
const int ARRAY_LEN_3 = 100000;
const int RANDOM_MAX_VALUE = 1000000;


void bubbleSort(int theArray[], int n)
{
    bool sorted = false; 
    int pass = 1;
    while (!sorted && (pass < n))
    {
        sorted = true;
        int index;
        for (index = 0; index < n-pass; index++)
        {
            int nextIndex = index + 1;
            if (theArray[index] > theArray[nextIndex])
            {
                swap(theArray[index], theArray[nextIndex]);
                sorted = false; 
            } 
        } 
        pass++;
    }
} 

void merge(int theArray[], int first, int mid, int last)
{
    int tempArray[MAX_SIZE];
    int first1 = first; 
    int last1 = mid; 
    int first2 = mid+1; 
    int last2 = last; 
    int index = first1; 
    while ((first1<=last1) && (first2 <=last2))
    {
        if (theArray[first1] <= theArray[first2])
        {
            tempArray[index] = theArray[first1];
            first1++;
        }
        else
        {
            tempArray[index] = theArray[first2];
            first2++;
        }
        index++;
    } 
    while (first1<=last1)
    {
        tempArray[index] = theArray[first1];
        first1++;
        index++;
    }
    while (first2<=last2)
    {
        tempArray[index] = theArray[first2];
        first2++;
        index++;
    } 
    for (index=first; index<=last; index++){
        theArray[index] = tempArray[index];
    }
}

void mergeSort(int theArray[], int first, int last)
{
    if (first < last)
    {  
        int mid = first + (last-first)/2;
        mergeSort(theArray,first,mid);
        mergeSort(theArray,mid+1,last);
        merge(theArray, first, mid, last);
    } 
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int *array1 = new int[ARRAY_LEN_1];
    int *array2 = new int[ARRAY_LEN_2];
    int *array3 = new int[ARRAY_LEN_3];
    
    for(int i = 0; i < 3; i++){
        if(i == 0){
            cout << "Filling Array 1" << endl;
            for(int k = 0; k < ARRAY_LEN_1; k++){
                    array1[k] = rand() % RANDOM_MAX_VALUE;
            }
        }
        if(i == 1){
            cout << "Filling Array 2" << endl;
            for(int k = 0; k < ARRAY_LEN_2; k++){
                    array2[k] = rand() % RANDOM_MAX_VALUE;
            }
        }
        if(i == 2){
            cout << "Filling Array 3" << endl;
            for(int k = 0; k < ARRAY_LEN_3; k++){
                    array3[k] = rand() % RANDOM_MAX_VALUE;
            }
        }
    }
    cout << "done" << endl;
    return 0;
}