#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vehicle {
protected:
    string plate;
    string description;
    vector<pair<string, float>> routes; 

public:
    Vehicle(const string& plate, const string& description)
        : plate(plate), description(description) {}

    virtual ~Vehicle() {}

    virtual float getFuelEfficiency() const = 0;

    const string& getPlate() const {
        return plate;
    }

    void addRoute(const string& city, float distance) {
        routes.push_back(make_pair(city, distance));
    }

    float calculateTotalDistance() const {
        float totalDistance = 0.0;
        for (size_t i = 0; i < routes.size(); ++i) {
            totalDistance += routes[i].second;
        }
        return totalDistance;
    }

    virtual void showSummary() const {
        cout << "Plate: " << plate << ", Description: " << description << endl;
        cout << "Total Distance: " << calculateTotalDistance() << " km" << endl;
        cout << "Estimated Fuel Consumption: " << calculateTotalDistance() / getFuelEfficiency() << " liters" << endl;
    }

    void showRoutes() const {
        cout << "Routes for vehicle with plate " << plate << ":" << endl;
        for (size_t i = 0; i < routes.size(); ++i) {
            cout << "City: " << routes[i].first << ", Distance: " << routes[i].second << " km" << endl;
        }
    }
};

class Car : public Vehicle {
public:
    Car(const string& plate, const string& description)
        : Vehicle(plate, description) {}

    float getFuelEfficiency() const {
        return 12.0;
    }
};

class Bus : public Vehicle {
public:
    Bus(const string& plate, const string& description)
        : Vehicle(plate, description) {}

    float getFuelEfficiency() const {
        return 7.0; 
    }
};

class LightTruck : public Vehicle {
public:
    LightTruck(const string& plate, const string& description)
        : Vehicle(plate, description) {}

    float getFuelEfficiency() const {
        return 4.0; 
    }
};

class HeavyTruck : public Vehicle {
public:
    HeavyTruck(const string& plate, const string& description)
        : Vehicle(plate, description) {}

    float getFuelEfficiency() const {
        return 2.0; 
    }
};