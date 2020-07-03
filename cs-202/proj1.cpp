// Student: Yaowei Deng
// Assignment: Project 1
// Class: CS 202.1001, Christos Papachristos, Spring 2019

#include <iostream>
#include <fstream>
#define max 100 // sets max to 100, used for input/output file container

using namespace std;

void myStringCopy (char destination [], const char source []);
int myStringLength (const char str []);
int myStringCompare (const char str1 [], const char str2 []);

int main ()
{
	char names[10][9];
	char namesLength[10][9];
	int ordersLength[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // array used to keep track of names' original order in the unsorted list
	char namesABC[10][9];
	int ordersABC[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char temp[9]; // temporary array used to store values during bubble sort
	int i = 0, j = 0;
	char inputFile[max];
	char outputFile[max];
	ifstream inputStream (inputFile);
	ofstream outputStream;
	
	cout << "enter input filename.txt: "; // prompts user for input file name
	cin >> inputFile;
	inputStream.open(inputFile);
	cout << "Unsorted Data (Original Input Order and Name)" << endl << "=============================================" << endl;
	for (i = 0; i < 10; i++){ // extracts names from user-inputted text file and stores into an array
		inputStream >> names[i];
		cout << i << " " << names[i] << "\n";	
	}
	cout << endl;
	
	for(i = 0; i < 10; i++){ // assigns NULL character at the end of each name, NULL character used for later functions
		while ((names[i][j] >= 'a' && names[i][j] <= 'z') || (names[i][j] >= 'A' && names[i][j] <= 'Z')) {
			j++;
		} 
		names[i][j] = '\0';
		j = 0;
	}

	if ( !inputStream.eof() ){
		inputStream.close();
	}

	for (int i = 0; i < 10; i++){ // copies names array into namesLength array for sorting
		myStringCopy (namesLength[i], names[i]);
	}
	for (int i = 0; i < 10; i++){ // performs a bubble sort of name lengths while simultaneously keeping the index for the original order
		for (int j = 0; j < 9; j++){
			if (myStringLength(namesLength[j]) > myStringLength(namesLength[j+1])){ // swaps if length is shorter than that preceding it
				myStringCopy (temp, namesLength[j]);
				myStringCopy (namesLength[j], namesLength[j+1]);
				myStringCopy (namesLength[j+1], temp);

				int temp = ordersLength[j+1]; // performs same bubble sort for index of original order
				ordersLength[j+1] = ordersLength[j];
				ordersLength[j] = temp;
			}
		}
	}
	cout << "Sorted-by-LengthData (Original Input Order and Name)" << endl << "====================================================" << endl;
	for (int i = 0; i < 10; i++){
		cout << ordersLength[i] << " " << namesLength[i] << endl;
	}
	cout << endl;
	cout << "enter output filename.txt for sorted by length: "; // prompts user for desired output file name of list sorted by length
	cin >> outputFile;
	outputStream.open(outputFile);
	for (int i = 0; i < 10; i++){
		outputStream << ordersLength[i] << " " << namesLength[i] << endl;
	}
	outputStream.close();

	for (int i = 0; i < 10; i++){ // copies names array into namesABC array for sorting
		myStringCopy (namesABC[i], names[i]);
	}
	for (int i = 0; i < 10; i++){ // performs a bubble sort alphabetically while simultaneously keeping the index for the original order
		for (int j = 0; j < 9; j++){
			if (myStringCompare(namesABC[j], namesABC[j+1]) == 1){ // swaps if compare function returns 1
				myStringCopy (temp, namesABC[j]);
				myStringCopy (namesABC[j], namesABC[j+1]);
				myStringCopy (namesABC[j+1], temp);

				int temp = ordersABC[j+1]; // performs same bubble sort for index of original order
				ordersABC[j+1] = ordersABC[j];
				ordersABC[j] = temp;
			}
		}
	}
	cout << "Alphabetically Sorted Data (Original Input Order and Name)" << endl << "==========================================================" << endl;
	for (int i = 0; i < 10; i++){
		cout << "" << ordersABC[i] << " " << namesABC[i] << endl;
	}
	cout << endl;
	cout << "enter output filename.txt for sorted alphabetically: "; // prompts user for desired output file name of list sorted alphabetically
	cin >> outputFile;
	outputStream.open(outputFile);
	for (int i = 0; i < 10; i++){
		outputStream << ordersABC[i] << " " << namesABC[i] << endl;
	}
	outputStream.close();

	return 0;
}

/*function name: myStringLength
pre-condition: character array of a list of names 
post-condition: counts how many characters in a given name, returns integer*/
int myStringLength (const char str []) // takes a "count" of each character in the array that is not a NULL character, returns count
{
	int i = 0, c = 0;
	while(str[i] != '\0') {
		c++;
		i++;
	}
	return c;
}

/*function name: myStringCopy
pre-condition: character array of destination, character array of source
post-condition: takes values stored in source array and copies them into destination array*/
void myStringCopy (char destination [], const char source []) // copies from source to destination for any non NULL characters
{
	int i = 0;
	while (source [i] != '\0'){
		destination [i] = source [i];
		i++;
	}
	destination [i] = '\0';
}

/*function name: myStringCompare
pre-condition: first character array for comparing letters, second character array for comparing letters
post-condition: compares letters of each name in the array, and returns an integer for each contingency*/
int myStringCompare (const char str1 [], const char str2 []) // compares character arrays, used for alphabetical sorting
{
	int a = 0, c;
	while (str1[a] != '\0' && str2[a] != '\0'){ // as long as neither character in an array is a NULL character, compare the two characters
		if (str1[a] > str2[a]){
			c = 1;
			return c;
		}
		if (str1[a] < str2[a]){
			c = -1;
			return c;
		}
		if (str1[a] == str2[a]){
			c = 0;
		}
		a++;
	}
	if (str1[a] == '\0' && str2[a] == '\0'){ // used in case two same-valued names have different lengths (i.e. "Dan" and "Danielle")
		c = 0;
	}
	else if (str1[a] == '\0'){
		c = -1;
	}
	else if (str2[a] == '\0'){
		c = 1;
	}
	return c;
}
