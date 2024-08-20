#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "vehicle.hpp"

using namespace std;


int main() {
    vector<Vehicle*> vehicles;

    int option;
    do {
        cout << "UFSC VEHICLE MANAGER SYSTEM (UVMS)" << endl;
        cout << "-----------------------------------" << endl;
        cout << "1. Insert a new vehicle" << endl;
        cout << "2. Insert a route to a vehicle be executed" << endl;
        cout << "3. Show reports (summary)" << endl;
        cout << "4. Show history by vehicle" << endl;
        cout << "0. Quit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
        case 1: {
            int type;
            string plate, description;

            cout << "Choose vehicle type (1-Car, 2-Bus, 3-LightTruck, 4-HeavyTruck): ";
            cin >> type;

            cout << "Enter plate: ";
            cin >> plate;

            cout << "Enter description: ";
            cin.ignore();
            getline(cin, description);

            Vehicle* newVehicle = NULL;
            switch (type) {
            case 1:
                newVehicle = new Car(plate, description);
                break;
            case 2:
                newVehicle = new Bus(plate, description);
                break;
            case 3:
                newVehicle = new LightTruck(plate, description);
                break;
            case 4:
                newVehicle = new HeavyTruck(plate, description);
                break;
            default:
                cout << "Invalid vehicle type!" << endl;
                continue;
            }

            vehicles.push_back(newVehicle);
            cout << "Vehicle added successfully!" << endl;
            break;
        }
        case 2: {
            string plate;
            cout << "Enter the plate of the vehicle: ";
            cin >> plate;

            size_t i = 0;
            while (i < vehicles.size() && vehicles[i]->getPlate() != plate) {
                ++i;
            }

            if (i < vehicles.size()) {
                cout << "Enter the route details (enter '0' for both city and distance to finish):" << endl;

                vector<pair<string, float>> citiesAndDistances;
                string city;
                float distance;

                while (true) {
                    cout << "City (enter '0' to finish): ";
                    cin >> city;

                    if (city == "0") {
                        break;
                    }

                    cout << "Distance: ";
                    cin >> distance;

                    citiesAndDistances.push_back(make_pair(city, distance));
                }

                for (const pair<string, float>& route : citiesAndDistances) {
                    vehicles[i]->addRoute(route.first, route.second);
                }

                cout << "Route added successfully!" << endl;
            }
            else {
                cout << "Vehicle not found!" << endl;
            }
            break;
        }
        case 3: {
            for (size_t i = 0; i < vehicles.size(); ++i) {
                vehicles[i]->showSummary();
                cout << "-----------------------------------" << endl;
            }
            break;
        }
        case 4: {
            string plate;
            cout << "Enter the plate of the vehicle: ";
            cin >> plate;

            size_t i = 0;
            while (i < vehicles.size() && vehicles[i]->getPlate() != plate) {
                ++i;
            }

            if (i < vehicles.size()) {
                vehicles[i]->showRoutes();
            }
            else {
                cout << "Vehicle not found!" << endl;
            }
            break;
        }
        case 0:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }

    } while (option != 0);

   
    for (Vehicle* vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}
