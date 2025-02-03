/*
Problem Statement: Library Management System using OOP
A library management system should allow users to borrow and return books. The system should have the following functionalities:

Book Class: Each book should have a title, author, and availability status.
User Class: Users should be able to borrow and return books.
Library Class: The library should maintain a collection of books and track borrowed books.
*/

#include <iostream>
#include <vector>
using namespace std;

class Book {
    string title, author;
    bool available;
public:
    Book(string t, string a) : title(t), author(a), available(true) {}
    bool isAvailable() { return available; }
    void borrowBook() { available = false; }
    void returnBook() { available = true; }
    string getTitle() { return title; }
    string getStatus() { return available ? "Available" : "Borrowed"; }
};

class Library {
    vector<Book> books;
public:
    void addBook(Book b) { books.push_back(b); }
    void showBooks() {
        for (auto &b : books)
            cout << b.getTitle() << " - " << b.getStatus() << endl;
    }
    Book* getBook(string title) {
        for (auto &b : books)
            if (b.getTitle() == title && b.isAvailable()) return &b;
        return nullptr;
    }
};

class User {
    string name;
public:
    User(string n) : name(n) {}
    void borrowBook(Library &lib, string title) {
        Book *b = lib.getBook(title);
        if (b) {
            b->borrowBook();
            cout << name << " borrowed " << title << endl;
        } else {
            cout << title << " is not available\n";
        }
    }
    void returnBook(Book &b) {
        b.returnBook();
        cout << name << " returned " << b.getTitle() << endl;
    }
};

int main() {
    Library lib;
    lib.addBook(Book("C++ Basics", "Author A"));
    lib.addBook(Book("Data Structures", "Author B"));

    User user("Alice");

    lib.showBooks();
    user.borrowBook(lib, "C++ Basics");
    lib.showBooks();
    
    return 0;
}
