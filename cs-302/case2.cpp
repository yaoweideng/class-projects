#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
const int MAX_SIZE = 100;
const int ARRAY_LEN_1 = 1000;
const int ARRAY_LEN_2 = 10000;
const int ARRAY_LEN_3 = 100000;
const int RANDOM_MAX_VALUE = 1000000;
int bcount = 0;
int mcount = 0;
int bswaps = 0;
int mswaps = 0;

void bubbleSort(int theArray[], int n)
{
    bool sorted = false; 
    int pass = 1;
    while (!sorted && (pass < n))
    {
        sorted = true;
        int index;
        for (index = 0; index < n - pass; index++)
        {
            int nextIndex = index + 1;
            if (theArray[index] > theArray[nextIndex])
            {
                swap(theArray[index], theArray[nextIndex]);
                sorted = false; 
                bswaps++;
            } 
        } 
        pass++;
        bcount += index;
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
            mcount++;
            mswaps++;
        }
        else
        {
            tempArray[index] = theArray[first2];
            first2++;
            mcount++;
            mswaps++;
        }
        index++;
    } 
    while (first1<=last1)
    {
        tempArray[index] = theArray[first1];
        first1++;
        index++;
        mswaps++;
    }
    while (first2<=last2)
    {
        tempArray[index] = theArray[first2];
        first2++;
        index++;
        mswaps++;
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
    double t, t1, t2;
    double v, v1, v2;
    int *array1 = new int[ARRAY_LEN_1];
    int *array2 = new int[ARRAY_LEN_2];
    int *array3 = new int[ARRAY_LEN_3];
    
	for(int i = 0; i < ARRAY_LEN_1; i++){
		array1[i] = rand() % RANDOM_MAX_VALUE;
	}
	for(int i = 0; i < ARRAY_LEN_2; i++){
		array2[i] = rand() % RANDOM_MAX_VALUE;
	}
	for(int i = 0; i < ARRAY_LEN_3; i++){
		array3[i] = rand() % RANDOM_MAX_VALUE;
	}
    bubbleSort(array1, ARRAY_LEN_1);
	bubbleSort(array2, ARRAY_LEN_2);
	bubbleSort(array3, ARRAY_LEN_3);
	mergeSort(array1, 0, ARRAY_LEN_1 - 1);
	mergeSort(array2, 0, ARRAY_LEN_2 - 1);
	mergeSort(array3, 0, ARRAY_LEN_3 - 1);

    for(int i = 0; i < 3; i++){
        bcount = 0;
        mcount = 0;
        bswaps = 0;
        mswaps = 0;
        for(int j = 0; j < 10; j++){
            if(i == 0){
                t1 = clock();
                bubbleSort(array1, ARRAY_LEN_1);
                t2 = clock();
                t += (t2 - t1);
                v1 = clock();
                mergeSort(array1, 0, ARRAY_LEN_1);
                v2 = clock();
                v += (v2 = v1);
            }
            if(i == 1){
                t1 = clock();
                bubbleSort(array2, ARRAY_LEN_2);
                t2 = clock();
                t += (t2 - t1);
                v1 = clock();
                mergeSort(array2, 0, ARRAY_LEN_2);
                v2 = clock();
                v += (v2 = v1);
            }
            if(i == 2){
                t1 = clock();
                bubbleSort(array3, ARRAY_LEN_3);
                t2 = clock();
                t += (t2 - t1);
                v1 = clock();
                mergeSort(array3, 0, ARRAY_LEN_3);
                v2 = clock();
                v += (v2 = v1);
            }
        }
        if(i == 0){
            cout << "FOR 1000 RANDOM INTEGERS" << endl;
            cout << "Average CPU Time for Bubble Sort: " << t / 10 << endl;
            cout << "Average Number of Comparisons for Bubble Sort: " << bcount / 10 << endl;
            cout << "Average Number of Swaps for Bubble Sort: " << bswaps / 10 << endl;
            cout << "Average Number of Comparisons for Merge Sort: " << mcount / 10 << endl;
            cout << "Average Number of Swaps for Merge Sort: " << mswaps / 10 << endl;
        }
        if(i == 1){
            cout << "FOR 10000 RANDOM INTEGERS" << endl;
            cout << "Average CPU Time for Bubble Sort: " << t / 10 << endl;
            cout << "Average Number of Comparisons for Bubble Sort: " << bcount / 10 << endl;
            cout << "Average Number of Swaps for Bubble Sort: " << bswaps / 10 << endl;
            cout << "Average Number of Comparisons for Merge Sort: " << mcount / 10 << endl;
            cout << "Average Number of Swaps for Merge Sort: " << mswaps / 10 << endl;
        }
        if(i == 2){
            cout << "FOR 100000 RANDOM INTEGERS" << endl;
            cout << "Average CPU Time for Bubble Sort: " << t / 10 << endl;
            cout << "Average Number of Comparisons for Bubble Sort: " << bcount / 10 << endl;
            cout << "Average Number of Swaps for Bubble Sort: " << bswaps / 10 << endl;
            cout << "Average Number of Comparisons for Merge Sort: " << mcount / 10 << endl;
            cout << "Average Number of Swaps for Merge Sort: " << mswaps / 10 << endl;
        }
    }
    return 0;
}