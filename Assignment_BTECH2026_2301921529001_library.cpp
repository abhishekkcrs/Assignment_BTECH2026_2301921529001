/*
Problem Statement:
Design a Library Management System where users can add books, borrow books, return books, and check book availability. 
Each book has a unique ID, title, and availability status. The system should support multiple books and allow users to borrow and return them.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Book {
private:
    int bookID;
    string title;
    bool isAvailable;

public:
    Book(int id, string name) : bookID(id), title(name), isAvailable(true) {}

    bool borrowBook() {
        if (!isAvailable) return false;
        isAvailable = false;
        return true;
    }

    void returnBook() { isAvailable = true; }

    bool checkAvailability() const { return isAvailable; }

    string getTitle() const { return title; }
};

class Library {
private:
    unordered_map<int, Book> books;

public:
    void addBook(int id, string name) {
        books[id] = Book(id, name);
    }

    bool borrowBook(int id) {
        if (books.find(id) == books.end()) return false;
        return books[id].borrowBook();
    }

    bool returnBook(int id) {
        if (books.find(id) == books.end()) return false;
        books[id].returnBook();
        return true;
    }

    bool isAvailable(int id) {
        if (books.find(id) == books.end()) return false;
        return books[id].checkAvailability();
    }
};

int main() {
    Library library;
    library.addBook(1, "1984");
    library.addBook(2, "To Kill a Mockingbird");

    library.borrowBook(1);
    cout << "Is '1984' available? " << (library.isAvailable(1) ? "Yes" : "No") << endl;

    library.returnBook(1);
    cout << "Is '1984' available? " << (library.isAvailable(1) ? "Yes" : "No") << endl;

    return 0;
}


