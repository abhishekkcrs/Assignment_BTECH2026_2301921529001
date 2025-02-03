/*
Problem Statement: ATM Simulation using OOP
An ATM system should allow users to check their balance, deposit money, and withdraw money. The system should have the following functionalities:

Account Class: Each user should have an account with an account number, balance, and methods to deposit and withdraw money.
ATM Class: The ATM should provide options to check balance, deposit, and withdraw money.
*/

#include <iostream>
using namespace std;

class Account {
    string accountNumber;
    double balance;
public:
    Account(string accNo, double bal) : accountNumber(accNo), balance(bal) {}
    double getBalance() { return balance; }
    void deposit(double amount) { balance += amount; }
    bool withdraw(double amount) {
        if (amount > balance) return false;
        balance -= amount;
        return true;
    }
};

class ATM {
public:
    void checkBalance(Account &acc) {
        cout << "Balance: $" << acc.getBalance() << endl;
    }
    void depositMoney(Account &acc, double amount) {
        acc.deposit(amount);
        cout << "Deposited: $" << amount << endl;
    }
    void withdrawMoney(Account &acc, double amount) {
        if (acc.withdraw(amount))
            cout << "Withdrawn: $" << amount << endl;
        else
            cout << "Insufficient balance" << endl;
    }
};

int main() {
    Account userAcc("123456", 500);
    ATM atm;
    
    atm.checkBalance(userAcc);
    atm.depositMoney(userAcc, 200);
    atm.withdrawMoney(userAcc, 100);
    atm.withdrawMoney(userAcc, 700);

    return 0;
}
 Assignment_BTECH2026_2301921529001_Library.cpp
