/*
Problem Statement:
Design a Smart Fan Control System using OOP in C++. The fan should:

Have three speed levels (Low, Medium, High).
Allow users to turn the fan ON or OFF.
Adjust the speed based on temperature input.
*/


#include <iostream>
using namespace std;

class SmartFan {
private:
    bool isOn;
    string speed;

public:
    SmartFan() {
        isOn = false;
        speed = "Off";
    }

    void turnOn() {
        isOn = true;
        speed = "Low";
        cout << "Fan turned ON at Low speed." << endl;
    }

    void turnOff() {
        isOn = false;
        speed = "Off";
        cout << "Fan turned OFF." << endl;
    }

    void adjustSpeed(int temperature) {
        if (!isOn) {
            cout << "Fan is OFF. Turn it ON first." << endl;
            return;
        }

        if (temperature < 20)
            speed = "Low";
        else if (temperature >= 20 && temperature < 30)
            speed = "Medium";
        else
            speed = "High";

        cout << "Fan speed set to " << speed << " based on temperature " << temperature << "°C." << endl;
    }

    void getStatus() {
        cout << "Fan Status: " << (isOn ? "ON" : "OFF") << ", Speed: " << speed << endl;
    }
};

int main() {
    SmartFan fan;

    fan.getStatus();
    fan.turnOn();
    fan.adjustSpeed(25);
    fan.getStatus();
    fan.turnOff();

    return 0;
}
