/*
Problem Statement: Smart Home Automation System using OOP
A smart home automation system allows users to control various appliances like lights, fans, and ACs using an object-oriented approach. The system should have the following functionalities:

Devices: Each appliance (light, fan, AC) should be a class with attributes like status (ON/OFF) and powerConsumption.
User Control: A user should be able to turn appliances ON/OFF.
Room Management: The system should support multiple rooms, each having multiple devices.
Power Consumption Calculation: The system should provide total power consumption of all devices.
*/

#include <iostream>
#include <vector>
using namespace std;

class Appliance {
protected:
    string name;
    bool status;
    double powerConsumption;
public:
    Appliance(string n, double p) : name(n), powerConsumption(p), status(false) {}
    void turnOn() { status = true; }
    void turnOff() { status = false; }
    double getPowerUsage() { return status ? powerConsumption : 0; }
    string getStatus() { return status ? "ON" : "OFF"; }
    string getName() { return name; }
};

class Room {
    string name;
    vector<Appliance> appliances;
public:
    Room(string n) : name(n) {}
    void addAppliance(Appliance a) { appliances.push_back(a); }
    double getTotalPowerUsage() {
        double total = 0;
        for (auto &a : appliances) total += a.getPowerUsage();
        return total;
    }
    void showStatus() {
        cout << "Room: " << name << endl;
        for (auto &a : appliances)
            cout << a.getName() << " is " << a.getStatus() << endl;
    }
};

int main() {
    Room livingRoom("Living Room");
    Appliance light("Light", 10), fan("Fan", 50), ac("AC", 200);
    
    livingRoom.addAppliance(light);
    livingRoom.addAppliance(fan);
    livingRoom.addAppliance(ac);

    light.turnOn();
    fan.turnOn();
    
    livingRoom.showStatus();
    cout << "Total Power Usage: " << livingRoom.getTotalPowerUsage() << "W" << endl;

    return 0;
}
