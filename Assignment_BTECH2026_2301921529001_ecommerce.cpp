*/
Problem Statement:
Design an Online Shopping System using Object-Oriented Programming (OOP) in C++. The system should allow users to browse products, add them to a cart, place orders, and track deliveries.

Requirements:
Classes & Objects:

User (Base class for customers and admins)
Customer (Derived class for shopping activities)
Admin (Manages inventory, updates products)
Product (Stores product details like name, price, stock)
Cart (Handles adding/removing items)
Order (Manages placed orders, payments, and tracking)
Key Features:

User Registration & Login
Product Catalog Browsing
Add to Cart & Remove from Cart
Order Placement & Payment Processing
Order Tracking & Delivery Updates
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Product Class
class Product {
public:
    int id;
    string name;
    double price;
    int stock;

    Product(int i, string n, double p, int s) : id(i), name(n), price(p), stock(s) {}
};

// User Class
class User {
protected:
    string username;
    string password;

public:
    User(string u, string p) : username(u), password(p) {}
    string getUsername() { return username; }
    bool login(string u, string p) { return (u == username && p == password); }
};

// Customer Class (Inherits User)
class Customer : public User {
private:
    vector<Product> cart;
    double balance;

public:
    Customer(string u, string p, double b) : User(u, p), balance(b) {}

    void addToCart(Product p) {
        if (p.stock > 0) {
            cart.push_back(p);
            cout << p.name << " added to cart.\n";
        } else {
            cout << "Product out of stock.\n";
        }
    }

    void viewCart() {
        cout << "\nYour Cart:\n";
        for (auto &p : cart) {
            cout << "- " << p.name << " ($" << p.price << ")\n";
        }
    }

    void checkout() {
        double total = 0;
        for (auto &p : cart) {
            total += p.price;
        }
        if (total > balance) {
            cout << "Insufficient balance!\n";
        } else {
            balance -= total;
            cart.clear();
            cout << "Order placed successfully! Remaining Balance: $" << balance << "\n";
        }
    }
};

// Admin Class (Inherits User)
class Admin : public User {
public:
    Admin(string u, string p) : User(u, p) {}

    void addProduct(vector<Product> &products, int id, string name, double price, int stock) {
        products.push_back(Product(id, name, price, stock));
        cout << "Product added: " << name << "\n";
    }
};

int main() {
    vector<Product> products;
    Admin admin("admin", "admin123");
    Customer customer("user1", "pass1", 100.0);

    // Admin adds products
    admin.addProduct(products, 1, "Laptop", 800.0, 5);
    admin.addProduct(products, 2, "Phone", 500.0, 10);
    admin.addProduct(products, 3, "Headphones", 50.0, 15);

    cout << "Welcome to Online Shopping System!\n";

    string username, password;
    cout << "Login as Customer\nUsername: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (customer.login(username, password)) {
        cout << "Login successful!\n";
        int choice;
        do {
            cout << "\n1. View Products\n2. Add to Cart\n3. View Cart\n4. Checkout\n5. Exit\nEnter choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "\nAvailable Products:\n";
                    for (auto &p : products) {
                        cout << p.id << ". " << p.name << " - $" << p.price << " (Stock: " << p.stock << ")\n";
                    }
                    break;
                case 2: {
                    int pid;
                    cout << "Enter Product ID: ";
                    cin >> pid;
                    for (auto &p : products) {
                        if (p.id == pid) {
                            customer.addToCart(p);
                        }
                    }
                    break;
                }
                case 3:
                    customer.viewCart();
                    break;
                case 4:
                    customer.checkout();
                    break;
                case 5:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 5);
    } else {
        cout << "Invalid login!\n";
    }
    return 0;
}

