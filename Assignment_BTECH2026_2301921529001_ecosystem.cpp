/*
Problem Statement: Virtual Ecosystem Simulation
You are designing a virtual ecosystem where different species of animals interact. The simulation should include the following features:

Base class Animal: Represents generic animals with attributes like name, age, and energy. It should have methods to move(), eat(), and sleep().
Derived classes (Herbivore and Carnivore):
Herbivore (e.g., Deer) eats plants.
Carnivore (e.g., Lion) hunts and eats herbivores.
Polymorphism: Each derived class should override the eat() method.
Encapsulation: The animal's energy level should be private and only modified via class methods.
Operator Overloading: Implement an overloaded + operator to simulate reproduction between two animals of the same type.
Friend Function: Implement a function that allows a Carnivore to check if a Herbivore is available to hunt.
*/
#include <iostream>
#include <vector>
using namespace std;

// Base class: Animal
class Animal {
protected:
    string name;
    int age;
    int energy;

public:
    Animal(string n, int a) : name(n), age(a), energy(100) {}

    virtual void eat() = 0;  // Pure virtual function
    virtual void move() {
        if (energy > 10) {
            cout << name << " is moving.\n";
            energy -= 10;
        } else {
            cout << name << " is too tired to move.\n";
        }
    }

    void sleep() {
        cout << name << " is sleeping and regaining energy.\n";
        energy += 20;
    }

    int getEnergy() const { return energy; }
    
    friend class Carnivore;  // Allows Carnivore to check Herbivore's energy
};

// Derived class: Herbivore
class Herbivore : public Animal {
public:
    Herbivore(string n, int a) : Animal(n, a) {}

    void eat() override {
        cout << name << " (Herbivore) is eating plants.\n";
        energy += 15;
    }

    // Overloaded + operator for reproduction
    Herbivore operator+(const Herbivore& other) {
        return Herbivore("Baby " + name, 0);
    }
};

// Derived class: Carnivore
class Carnivore : public Animal {
public:
    Carnivore(string n, int a) : Animal(n, a) {}

    void eat() override {
        cout << name << " (Carnivore) is looking for food.\n";
    }

    void hunt(Herbivore &prey) {
        if (prey.energy > 30) {
            cout << name << " is hunting " << prey.name << "!\n";
            prey.energy -= 30;
            energy += 40;
        } else {
            cout << name << " decides not to hunt " << prey.name << " (too weak).\n";
        }
    }
};

int main() {
    Herbivore deer("Deer", 3);
    Carnivore lion("Lion", 5);

    deer.eat();
    deer.move();

    lion.hunt(deer);
    
    // Reproduction example
    Herbivore deer2("Deer2", 3);
    Herbivore babyDeer = deer + deer2;
    cout << "A new " << babyDeer.getEnergy() << "-energy baby deer is born!\n";

    return 0;
}
