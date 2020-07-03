// Student: Yaowei Deng
// Assignment: Project 2
// Class: CS 202.1001, Christos Papachristos, Spring 2019

#include <iostream>
#include <fstream>

using namespace std;

const int maxcars = 100; // sets max to 100, used for input/output file container
struct RentalCar { 
    int year;
    char make[10];
    char model[10];
    float price;
    bool available;
};

void getInfo (RentalCar cars[]);
void printInfo (RentalCar cars[]);
void outputInfo (RentalCar cars[]);
void sortPrices (RentalCar cars[]);
void carEstimate (RentalCar cars[]);
void rentCar (RentalCar cars[]);

int main () 
{
    RentalCar cars[5];
    int option;

    do { // do while loop employed for user menu
        cout << endl;
        cout << "Please select an option:" << endl;
        cout << "1) Import car rental file" << endl;
        cout << "2) Print car rental info" << endl;
        cout << "3) Export car rental info into file" << endl;
        cout << "4) Sort cars by price" << endl;
        cout << "5) Car price estimate" << endl;
        cout << "6) Rent a car" << endl;
        cout << "7) Exit program" << endl;
        cout << endl << "Enter corresponding option number: "; // prompts user for option number
        cin >> option;

        if (option == 1){
            getInfo (cars);
        }
        else if (option == 2){
            printInfo (cars);
        }
        else if (option == 3){
            outputInfo (cars);
        }
        else if (option == 4){
            sortPrices (cars);
        }
        else if (option == 5){
            carEstimate (cars);
        }
        else if (option == 6){
            rentCar (cars);
        }
        else if (option == 7){ // if user chooses to exit program, break loop
            break;
        }
        else if (option != 1 || option != 2 || option != 3 || option != 4 || option != 5 || option != 6 || option != 7){
            cout << endl << "Invalid. Please enter a valid option." << endl;
        }
    }
    while (option != 7);

    return 0;
}

void getInfo (RentalCar cars[]){ // reads in user-inputted file and stores into array of structs
    char inputFile[maxcars];
    ifstream inputStream (inputFile);

    cout << "Enter input filename.txt: ";
    cin >> inputFile;
    inputStream.open(inputFile);
    for (int i = 0; i < 5; i++){
        inputStream >> cars[i].year >> cars[i].make >> cars[i].model >> cars[i].price >> cars[i].available;
    }
    if ( !inputStream.eof() ){
		inputStream.close();
	}
}

void printInfo (RentalCar cars[]){ // prints list of rental cars, prefixed by their index in the array
    cout << endl;
    for (int i = 0; i < 5; i++){
        cout << "[" << i << "]: ";
        cout << cars[i].year << " ";
        cout << cars[i].make << " ";
        cout << cars[i].model << ", ";
        cout << "$" << cars[i].price << " per day" << ", ";
        cout << "Available: " << boolalpha << cars[i].available;
        cout << endl << endl;
    }
}

void outputInfo (RentalCar cars[]){ // outputs rental car info into file in the same format as the input file
    char outputFile[maxcars];
    ofstream outputStream;

    cout << "Enter output filename.txt: ";
	cin >> outputFile;
	outputStream.open(outputFile);
	for (int i = 0; i < 5; i++){
		outputStream << cars[i].year << " " << cars[i].make << " " << cars[i].model << " " << cars[i].price << " " << cars[i].available << endl;
	}
	outputStream.close();
}

void sortPrices (RentalCar cars[]){ // sorts the array of structs by each car's price in ascending order, then prints sorted list
    RentalCar carPrice[5];
    RentalCar temp;

    for (int i = 0; i < 5; i++){
        carPrice[i] = cars[i];
    }
    for (int j = 0; j < 4; j++){
        for (int i = 0; i < 4; i++){
            if (carPrice[i].price > carPrice[i+1].price){
            temp = carPrice[i];
			carPrice[i] = carPrice[i+1];
            carPrice[i+1] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++){
        cars[i] = carPrice[i];
    }
}

void carEstimate (RentalCar cars[]){ // prompts user how many days they would like to rent, then prints only available
    int days;
    float cost = 0.0;

    sortPrices (cars);
    cout << "How many days would you like to rent a car?: "; // prompts user for how many days they'd like to rent
    cin >> days;
    for (int i = 0; i < 5; i++){
        cost = cars[i].price * days;

        if (cars[i].available == 1){ // outputs the available cars with the total cost of each
            cout << endl;
            cout << "[" << i << "]: ";
            cout << cars[i].year << " ";
            cout << cars[i].make << " ";
            cout << cars[i].model << ", ";
            cout << "total cost: $" << cost;
            cout << endl;
        }
    }
}

void rentCar (RentalCar cars[]){ // allows user to rent car
    char yn;
    int index;
    int days;
    float cost = 0.0;

    cout << "Would you like to see your options? (y/n): "; // prompts user if they'd like to see list to choose from
    cin >> yn;
    if (yn == 'y'){
        printInfo (cars);
    }
    cout << "Which car would you like to rent? Please enter its index number: "; // prompts user which car they'd like to rent
    cin >> index;
    if (cars[index].available == 0){ // if user-inputted car is not available, return to menu
        cout << endl << cars[index].year << " " << cars[index].make << " " << cars[index].model << " is not available." << endl;
    }
    if (cars[index].available == 1){ // if user-inputted car is available, prompt user for how many days they'd like to rent
        cout << "How many days would you like to rent " << cars[index].year << " " << cars[index].make << " " << cars[index].model << "? Please enter a number: ";
        cin >> days;
        cost = cars[index].price * days;
        cars[index].available = 0; // changes availability status of the rented car
        cout << "================================================================";
        cout << endl << "Congratulations! You have rented " << cars[index].year << " " << cars[index].make << " " << cars[index].model << " " << "for $" << cost << "." << endl;
        cout << "================================================================" << endl;
    }
}