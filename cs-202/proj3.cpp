// Student: Yaowei Deng
// Assignment: Project 3
// Class: CS 202.1001, Christos Papachristos, Spring 2019

#include <iostream>
#include <fstream>
#include "RentalCar.cpp"

using namespace std;

const int maxnum = 100; // sets max to 100, used for input/output file container
struct RentalAgency {
    char name[256];
    int zipcode[5];
    RentalCar inventory[5];
};

void getInfo(RentalAgency *agencies);
void printAgency(RentalAgency *agencies);
void rentalEstimate(RentalAgency *agencies);
void mostExpensive(RentalAgency *agencies);
void outputInfo(RentalAgency *agencies);

int main()
{
    RentalAgency agencies[3];
    int option;

    do { // do while loop employed for user menu
        cout << endl;
        cout << "Please select an option:" << endl;
        cout << "1) Import car agency file" << endl;
        cout << "2) Print car agency info" << endl;
        cout << "3) Car price estimate" << endl;
        cout << "4) Find the most expensive car" << endl;
        cout << "5) Export file of available cars" << endl;
        cout << "6) Exit program" << endl;
        cout << endl << "Enter corresponding option number: "; // prompts user for option number
        cin >> option;

        if (option == 1){
            getInfo(agencies);
        }
        else if (option == 2){
            printAgency(agencies);
        }
        else if (option == 3){
            rentalEstimate(agencies);
        }
        else if (option == 4){
            mostExpensive(agencies);
        }
        else if (option == 5){
            outputInfo(agencies);
        }
        else if (option == 6){ // if user chooses to exit program, break loop
            break;
        }
        else if (option != 1 || option != 2 || option != 3 || option != 4 || option != 5 || option != 6){
            cout << endl << "Invalid. Please enter a valid option." << endl;
        }
    }
    while (option != 6);

    return 0;
}

void getInfo(RentalAgency *agencies){ // reads in user-inputted file into array of structs
    char inputFile[maxnum];
    ifstream inputStream(inputFile);
    RentalAgency *ptr_agency = agencies;
    int yeartemp;
    char maketemp[256];
    char modeltemp[256];
    float pricetemp;
    bool availabletemp;
    char zip;

    cout << "Enter input filename.txt: "; // prompts user for file input name
    cin >> inputFile;
    inputStream.open(inputFile);
    for (int i = 0; i < 3; i++){
        inputStream >> ptr_agency->name; // uses pointer to access name char array in agency struct
        inputStream.get(); // gets whitespace between name and zipcode
        int *ptr_zip = ptr_agency->zipcode; // uses pointer to access zipcode int array in agency struct
        for (int k = 0; k < 5; k++){
            zip = inputStream.get(); // gets ASCII value of each int and stores into an array, then subtracts "0" ASCII value
            *ptr_zip = zip - '0';
            ptr_zip++;
        }
        RentalCar *ptr_car = ptr_agency->inventory; // uses pointer to access inventory, stores first into temp, then sets to private data members
        for (int j = 0; j < 5; j++){
            inputStream >> yeartemp;
            inputStream >> maketemp;
            inputStream >> modeltemp;
            inputStream >> pricetemp;
            inputStream >> availabletemp;
            ptr_car->setYear(yeartemp);
            ptr_car->setMake(maketemp);
            ptr_car->setModel(modeltemp);
            ptr_car->setPrice(pricetemp);
            ptr_car->setAvailable(availabletemp);
            ptr_car++;
        }
        ptr_agency++;
    }
    if ( !inputStream.eof() ){
		inputStream.close();
	}
    cout << endl << "Successfully imported." << endl;
}

void printAgency(RentalAgency *agencies){ // prints stored info from user-inputted file
    RentalCar *ptr_inventory;
    RentalAgency *ptr_a = agencies;

    cout << endl;
    for (int i = 0; i < 3; i++){
        ptr_inventory = ptr_a->inventory;
        cout << ptr_a->name << " ";
        int *ptr_zip = ptr_a->zipcode;
        for (int i = 0; i < 5; i++){
            cout << *ptr_zip++;
        }
        cout << endl;
        for (int j = 0; j < 5; j++){
            ptr_inventory->printCar(); // prints each car
            ptr_inventory++;
        }
        ptr_a++;
        cout << endl;
    }
}

void rentalEstimate(RentalAgency *agencies){
    RentalAgency *ptr_a = agencies;
    RentalCar *ptr_car;
    int agencyoption, caroption, rentdays;
    float cost;

    cout << "Enter agency number 0-2: ";
    cin >> agencyoption;
    cout << endl;
    cout << "Enter car number 0-4: ";
    cin >> caroption;
    cout << endl;
    cout << "Enter number of days to rent: ";
    cin >> rentdays;
    for (int i = 0; i < agencyoption; i++){ // pointer loops until reaches user desired option
        ptr_a++;
    }
    ptr_car = ptr_a->inventory;
    for (int i = 0; i < caroption; i++){ // pointer loops until reaches user desired option
        ptr_car++;
    }
    cost = ptr_car->carEstimate(rentdays);
    cout << endl << "Congratulations, you have rented for $" << cost << "!" << endl;
}

void mostExpensive(RentalAgency *agencies){
    float price = 0;
    RentalAgency *ptr_a = agencies;
    RentalCar *ptr_car;
    RentalCar mostExpensive;
    char tempmake[256], tempmodel[256];

    for (int i = 0; i < 3; i++){
        ptr_car = ptr_a->inventory;
        for (int j = 0; j < 5; j++){
            if (price < ptr_car->getPrice()){ // finds the most expensive car, then sets price equal to the pointer of the that car
                price = ptr_car->getPrice();
                mostExpensive.setPrice(ptr_car->getPrice());
                myStringCopy(tempmake, ptr_car->getMake()); // have to string copy into temp arrays first because char 
                myStringCopy(tempmodel, ptr_car->getModel());
                mostExpensive.setYear(ptr_car->getYear());
                mostExpensive.setAvailable(ptr_car->getAvailable());
            }
        }
    }
    mostExpensive.setMake(tempmake);
    mostExpensive.setModel(tempmodel);
    cout << endl << "The most expensive car is: ";
    cout << mostExpensive.getYear() << " ";
    cout << mostExpensive.getMake() << " ";
    cout << mostExpensive.getModel() << ", ";
    cout << "$" << mostExpensive.getPrice() << " per day, ";
    cout << "Available: " << boolalpha << mostExpensive.getAvailable();
    cout << endl;
}

void outputInfo(RentalAgency *agencies){ // literally almost the same as printAgency function
    char outputFile[maxnum];
    ofstream outputStream;
    RentalCar *ptr_inventory;
    RentalAgency *ptr_a = agencies;

    cout << "Enter output filename.txt: ";
	cin >> outputFile;
	outputStream.open(outputFile);
    for (int i = 0; i < 3; i++){
        outputStream << ptr_a->name << " ";
        int *ptr_zip = ptr_a->zipcode;
        for (int j = 0; j < 5; j++){
            outputStream << *ptr_zip++;
        }
        outputStream << endl;
        ptr_inventory = ptr_a->inventory;
        for (int k = 0; k < 5; k++){
            if (ptr_inventory->getAvailable() == 1){ // if bool value is true, prints the car 
                outputStream << ptr_inventory->getYear() << " ";
                outputStream << ptr_inventory->getMake() << " ";
                outputStream << ptr_inventory->getModel() << ", ";
                outputStream << "$" << ptr_inventory->getPrice() << " per day, ";
                outputStream << "Available: " << boolalpha << ptr_inventory->getAvailable();
                outputStream << endl;
            }
            ptr_inventory++;
        }
        ptr_a++;
    }
}

char *myStringCopy(char *destination, const char *source){
    while (*source != '\0'){
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return destination;
}
