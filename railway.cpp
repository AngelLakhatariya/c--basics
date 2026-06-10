#include <iostream>
using namespace std;

class train {
 private:
    int trainNumber;    
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
     
    static int trainCount;

 public:

    train() {
        trainNumber = 0;
        trainCount++;
    }

    ~train() {
        trainCount--;
    }

    int getTrainNumber() { return trainNumber; }
    void setTrainNumber(int num) { trainNumber = num; }

    void inputTrainDetails() {

        cout<< "Enter TrainNumber : ";
        cin>> trainNumber;

        cout<< "Enter TrainName : ";
        cin>> trainName;

        cout<< "Enter Source : ";
        cin>> source;

        cout<< "Enter Destination : ";
        cin>> destination;

        cout<< "Enter TrainTime : ";
        cin>> trainTime;
    }

    void displayTrainDetails() {
        cout<< "Train number : "<< trainNumber <<endl;
        cout<< "Train name : "<< trainName <<endl;
        cout<< "Source : "<< source <<endl;
        cout<< "Destination : "<< destination <<endl;
        cout<< "Train Time : "<< trainTime <<endl;
        cout << "-------------------------\n";
    }

    static int getTrainCount() {
        return trainCount;
    }
};

int train::trainCount = 0;

class RailwaySystem {
 private:
    train trains[100];
    int totalTrains;

 public:
    RailwaySystem() {
        totalTrains = 0;
    }
 
    void addTrain() {
        if (totalTrains >= 100){
            cout<< "System full!" <<endl;
            return;
        }
        trains[totalTrains].inputTrainDetails();
        totalTrains++;
    }
    
    void displayAllTrains() { 
        if (totalTrains == 0) {
            cout<< "No records found!" << endl;
            return;
        }
        for (int i = 0; i < totalTrains; i++) {
            cout<< "Train " << (i + 1) << " details:" << endl;
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int searchNum) { 
        int found = 0; 
        
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == searchNum) {
                cout << "\nTrain Found!" << endl;
                trains[i].displayTrainDetails();
                found = 1; 
            }
        }

        if (found == 0) {
            cout << "Train with number " << searchNum << " is not found" << endl;
        }
    }
};

int main() {
    RailwaySystem sys; 
    int choice = 0;

    cout << "Setup: Please enter 3 Initial Train Records" << endl; 
    for (int i = 0; i < 3; i++) {
        sys.addTrain();
    }

    while (choice != 4) {
        cout << "\n--- Railway Reservation System Menu ---" << endl; 
        cout << "1. Add New Train Record" << endl;                
        cout << "2. Display All Train Records" << endl;            
        cout << "3. Search Train by Number" << endl;                
        cout << "4. Exit" << endl;                                  
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            sys.addTrain();
            } 
        else if (choice == 2) {
            sys.displayAllTrains();
        } 
        else if (choice == 3) {
            int num;
            cout << "Enter Train Number to search: "; 
            cin >> num;
            sys.searchTrainByNumber(num);
        } 
        else if (choice == 4) {
            cout << "Exiting the system. Goodbye!" << endl; 
        } 
        else {
            cout << "Wrong choice entered. Try again!" << endl;
        }
    }
}


