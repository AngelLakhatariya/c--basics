#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    int vehicleID;
    string manufacture;
    string model;
    int year;

public:
    static int totalVehicles;

    Vehicle() {
        vehicleID = 0;
        manufacture = "Unknown";
        model = "Unknown";
        year = 0;
    }

    ~Vehicle() {}

    void setVehicle(int id, string manu, string mod, int y) {
        vehicleID = id;
        manufacture = manu;
        model = mod;
        year = y;
    }

    int getID() {
        return vehicleID;
    }

    void displayVehicle() {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Manufacturer: " << manufacture << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

class Car : virtual public Vehicle {
protected:
    string fueltype;
public:
    void setCar(int id, string manu, string mod, int y, string fuel) {
        setVehicle(id, manu, mod, y);
        fueltype = fuel;
    }

    void displayCar() {
        displayVehicle();
        cout << "Fuel Type: " << fueltype << endl;
    }
};

class ElectricCar : public Car {
protected:
    int batterycapacity;
public:
    void setElectricCar(int id, string manu, string mod, int y, string fuel, int battery) {
        setCar(id, manu, mod, y, fuel);
        batterycapacity = battery;
    }

    void displayElectricCar() {
        displayCar();
        cout << "Battery Capacity: " << batterycapacity << " kWh" << endl;
    }
};

class Sportscar : public ElectricCar {
protected:
    int topspeed;
public:
    void setSportsCar(int id, string manu, string mod, int y, string fuel, int battery, int speed) {
        setElectricCar(id, manu, mod, y, fuel, battery);
        topspeed = speed;
    }

    void displaySportsCar() {
        displayElectricCar();
        cout << "Top Speed: " << topspeed << " km/h" << endl;
    }
};

class Sedan : public Car {
public:
    void setSedan(int id, string manu, string mod, int y, string fuel) {
        setCar(id, manu, mod, y, fuel);
    }

    void displaySedan() {
        displayCar();
    }
};

class Suv : public Car {
public:
    void setSuv(int id, string manu, string mod, int y, string fuel) {
        setCar(id, manu, mod, y, fuel);
    }

    void displaySuv() {
        displayCar();
    }
};

class Aircraft : virtual public Vehicle {
protected:
    int flightrange;
public:
    void setAircraft(int id, string manu, string mod, int y, int range) {
        setVehicle(id, manu, mod, y);
        flightrange = range;
    }

    void displayAircraft() {
        displayVehicle();
        cout << "Flight Range: " << flightrange << " miles" << endl;
    }
};

class FlyingCar : public Car, public Aircraft {
public:
    void setFlyingCar(int id, string manu, string mod, int y, string fuel, int range) {
        setCar(id, manu, mod, y, fuel);
        flightrange = range;
    }

    void displayFlyingCar() {
        displayCar();
        cout << "Flight Range: " << flightrange << " miles" << endl;
    }
};

int main() {

    ElectricCar cars[100];     
    Sportscar sportscars[100]; 
    Sedan sedans[100];     
    Suv suvs[100];  
    Aircraft crafts[100];  
    FlyingCar flyingCars[100]; 

    int carscount = 0, sportscount = 0, sedancount = 0, suvcount = 0, craftcount = 0, flyingcount = 0;
    int choice;

    cars[carscount++].setElectricCar(101, "Tesla", "Model3", 2022, "Electric", 75);
    Vehicle::totalVehicles++;

    sportscars[sportscount++].setSportsCar(201, "Porsche", "Taycan", 2023, "Electric", 93, 260);
    Vehicle::totalVehicles++;

    sedans[sedancount++].setSedan(301, "Toyota", "Camry", 2021, "Petrol");
    Vehicle::totalVehicles++;

    do {
        cout << "\n===== VEHICLE REGISTRY SYSTEM =====\n";
        cout << "Total Registered Vehicles Status: " << Vehicle::totalVehicles << "\n-----------------------------------\n";
        cout << "1. Add Electric Car\n";
        cout << "2. Add Electric Sports Car\n";
        cout << "3. Add Sedan Car\n";
        cout << "4. Add SUV Car\n";
        cout << "5. Add Aircraft\n";
        cout << "6. Add Flying Car\n";
        cout << "7. View All Vehicles\n";
        cout << "8. Search Vehicle by ID\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int id, year, battery, speed, range;
        string manu, model, fuel;

        switch (choice) {
        case 1:
            cout << "Enter Vehicle ID: "; cin >> id;
            cout << "Enter Manufacturer: "; cin >> manu;
            cout << "Enter Model: "; cin >> model;
            cout << "Enter Year: "; cin >> year;
            cout << "Enter Fuel Type: "; cin >> fuel;
            cout << "Enter Battery Capacity: "; cin >> battery;
            
            cars[carscount].setElectricCar(id, manu, model, year, fuel, battery);
            carscount++;
            Vehicle::totalVehicles++;
            cout << "Vehicle added successfully!\n";
            break;

        case 2:
            cout << "Enter Vehicle ID: "; cin >> id;
            cout << "Enter Manufacturer: "; cin >> manu;
            cout << "Enter Model: "; cin >> model;
            cout << "Enter Year: "; cin >> year;
            cout << "Enter Fuel Type: "; cin >> fuel;
            cout << "Enter Battery Capacity: "; cin >> battery;
            cout << "Enter Top Speed: "; cin >> speed;

            sportscars[sportscount].setSportsCar(id, manu, model, year, fuel, battery, speed);
            sportscount++;
            Vehicle::totalVehicles++;
            cout << "Vehicle added successfully!\n";
            break;

        case 3:
            cout << "Enter Vehicle ID: "; cin >> id;
            cout << "Enter Manufacturer: "; cin >> manu;
            cout << "Enter Model: "; cin >> model;
            cout << "Enter Year: "; cin >> year;
            cout << "Enter Fuel Type: "; cin >> fuel;

            sedans[sedancount].setSedan(id, manu, model, year, fuel);
            sedancount++;
            Vehicle::totalVehicles++;
            cout << "Vehicle added successfully!\n";
            break;

        case 4:
            cout << "Enter Vehicle ID: "; cin >> id;
            cout << "Enter Manufacturer: "; cin >> manu;
            cout << "Enter Model: "; cin >> model;
            cout << "Enter Year: "; cin >> year;
            cout << "Enter Fuel Type: "; cin >> fuel;

            suvs[suvcount].setSuv(id, manu, model, year, fuel);
            suvcount++;
            Vehicle::totalVehicles++;
            cout << "Vehicle added successfully!\n";
            break;

        case 5:
            cout << "Enter Vehicle ID: "; cin >> id;
            cout << "Enter Manufacturer: "; cin >> manu;
            cout << "Enter Model: "; cin >> model;
            cout << "Enter Year: "; cin >> year;
            cout << "Enter Flight Range: "; cin >> range;

            crafts[craftcount].setAircraft(id, manu, model, year, range);
            craftcount++;
            Vehicle::totalVehicles++;
            cout << "Vehicle added successfully!\n";
            break;

        case 6:
            cout << "Enter Vehicle ID: "; cin >> id;
            cout << "Enter Manufacturer: "; cin >> manu;
            cout << "Enter Model: "; cin >> model;
            cout << "Enter Year: "; cin >> year;
            cout << "Enter Fuel Type: "; cin >> fuel;
            cout << "Enter Flight Range: "; cin >> range;

            flyingCars[flyingcount].setFlyingCar(id, manu, model, year, fuel, range);
            flyingcount++;
            Vehicle::totalVehicles++;
            cout << "Vehicle added successfully!\n";
            break;

        case 7:
            if (Vehicle::totalVehicles == 0) {
                cout << "No vehicles available.\n";
            } else {
                for (int i = 0; i < carscount; i++) {
                    cout << "\n--- Electric Car " << i + 1 << " ---\n";
                    cars[i].displayElectricCar();
                }
                for (int i = 0; i < sportscount; i++) {
                    cout << "\n--- Sports Car " << i + 1 << " ---\n";
                    sportscars[i].displaySportsCar();
                }
                for (int i = 0; i < sedancount; i++) {
                    cout << "\n--- Sedan Car " << i + 1 << " ---\n";
                    sedans[i].displaySedan();
                }
                for (int i = 0; i < suvcount; i++) {
                    cout << "\n--- SUV Car " << i + 1 << " ---\n";
                    suvs[i].displaySuv();
                }
                for (int i = 0; i < craftcount; i++) {
                    cout << "\n--- Aircraft " << i + 1 << " ---\n";
                    crafts[i].displayAircraft();
                }
                for (int i = 0; i < flyingcount; i++) {
                    cout << "\n--- Flying Car " << i + 1 << " ---\n";
                    flyingCars[i].displayFlyingCar();
                }
            }
            break;

        case 8: {
            int searchID;
            bool found = false;
            cout << "Enter Vehicle ID to search: ";
            cin >> searchID;

            for (int i = 0; i < carscount; i++) {
                if (cars[i].getID() == searchID) {
                    cout << "\nVehicle Found:\n"; cars[i].displayElectricCar();
                    found = true; break;
                }
            }
            for (int i = 0; i < sportscount; i++) {
                if (sportscars[i].getID() == searchID) {
                    cout << "\nVehicle Found:\n"; sportscars[i].displaySportsCar();
                    found = true; break;
                }
            }
            for (int i = 0; i < sedancount; i++) {
                if (sedans[i].getID() == searchID) {
                    cout << "\nVehicle Found:\n"; sedans[i].displaySedan();
                    found = true; break;
                }
            }
            for (int i = 0; i < suvcount; i++) {
                if (suvs[i].getID() == searchID) {
                    cout << "\nVehicle Found:\n"; suvs[i].displaySuv();
                    found = true; break;
                }
            }
            for (int i = 0; i < craftcount; i++) {
                if (crafts[i].getID() == searchID) {
                    cout << "\nVehicle Found:\n"; crafts[i].displayAircraft();
                    found = true; break;
                }
            }
            for (int i = 0; i < flyingcount; i++) {
                if (flyingCars[i].getID() == searchID) {
                    cout << "\nVehicle Found:\n"; flyingCars[i].displayFlyingCar();
                    found = true; break;
                }
            }

            if (!found) {
                cout << "Vehicle not found!\n";
            }
            break;
        }

        case 9:
            cout << "Exited successfully.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 9);

}