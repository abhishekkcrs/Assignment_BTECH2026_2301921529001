#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(string accNumber, string accHolder, double initialBalance)
        : accountNumber(accNumber), accountHolder(accHolder), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    bool transfer(BankAccount &toAccount, double amount) {
        if (withdraw(amount)) {
            toAccount.deposit(amount);
            return true;
        }
        return false;
    }

    void displayDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account1("123456", "Sam", 5000);
    BankAccount account2("789012", "Prim", 3000);

    account1.deposit(2000);
    account2.withdraw(500);

    account1.transfer(account2, 1500);

    cout << "Account 1 Details:" << endl;
    account1.displayDetails();
    cout << endl;

    cout << "Account 2 Details:" << endl;
    account2.displayDetails();

    return 0;
}
