/*
You are developing a Smart Drone Management System using Object-Oriented Programming (OOP) in C++.
The system should allow users to manage multiple drones, assign missions, track their status, and retrieve details dynamically.
*/

#include<iostream>

using namespace std;

class Drone{
public:
    int droneid;
    string model;
    int battery;
    int status;
    Drone(int droneid,string model,int battery,int status){
        this->droneid=droneid;
        this->model=model;
        this->battery=battery;
        this->status=status;
    }
    virtual void displayStatus()=0;
};

class SurveryDrones: public Drone{
public:
    int cameraResolution;
    int storage;
    SurveryDrones(int droneid,string model,int battery,int status,int cameraResolution,int storage):Drone(droneid,model,battery,status){

        this->cameraResolution=cameraResolution;
        this->storage=storage;
        
    }
    void displayStatus(){
        cout << "Survey Drone | Payload Capacity: " << cameraResolution << " kg\n";
    }
};
class DeliveryDrone : public Drone {
    int payloadCapacity;
public:
    DeliveryDrone(int id, string model, int battery, int status, int capacity) : Drone(id, model,battery,status){
        payloadCapacity = capacity;
    }
    void displayStatus(){
        cout << "Delivery Drone | Payload Capacity: " << payloadCapacity << " kg\n";
    }   
};

int main(){
    DeliveryDrone *Prime=new DeliveryDrone(1,"Prime",100,1,500);
    SurveryDrones *Survey=new SurveryDrones(2,"Survey",100,1,5,10);
    Prime->displayStatus();
    Survey->displayStatus();
}
