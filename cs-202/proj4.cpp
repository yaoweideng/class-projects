// Student: Yaowei Deng
// Assignment: Project 4
// Class: CS 202.1001, Christos Papachristos, Spring 2019

#include <iostream>
#include <fstream>
#include "Sensor.cpp"
#include "Car.cpp"
#include "Agency.cpp"

using namespace std;

char inputFile[maxnum];

int main()
{
    int option;
    Agency agency;

    do {
        cout << endl;
        cout << "Please select an option:" << endl;
        cout << "1) Input data from file" << endl;
        cout << "2) Print car agency info" << endl;
        cout << "3) Print total number of sensors info" << endl;
        cout << "4) Find the most expensive car" << endl;
        cout << "5) Exit program" << endl;
        cout << endl << "Enter corresponding option number: ";
        cin >> option;

        if (option == 1){
            cout << "Enter input filename.txt: ";
            cin >> inputFile;
            ifstream inputStream;
            inputStream.open(inputFile);
            agency.readAllData(inputStream);
            if ( !inputStream.eof() ){
		        inputStream.close();
	        }
            cout << endl << "Successfully imported." << endl;
        }
        else if (option == 2){
            agency.printAllData();
        }
        else if (option == 3){
        }
        else if (option == 4){
        }
        else if (option == 5){
            break;
        }
        else if (option != 1 || option != 2 || option != 3 || option != 4 || option != 5){
            cout << endl << "Invalid. Please enter a valid option." << endl;
        }
    }
    while (option != 5);

    return 0;
}
