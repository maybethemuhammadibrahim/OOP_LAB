/*You are building a bank account management system. Create a class `Account` to manage bank
accounts.
Requirements:
1. Attributes:
 `accountNumber` (string)
 `accountHolderName` (string)
 `balance` (double)
2. Define a default constructor that initializes `balance` to `0.0`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
 `deposit(double amount)`: Adds the amount to the balance.
 `withdraw(double amount)`: Deducts the amount from the balance (if sufficient funds are
available).
 `checkBalance()`: Displays the current balance.
5. Create a few `Account` objects and test the methods.*/

#include<iostream>
using namespace std;

class Account {
    private:
    string accountNumber;
    string accountHolderName;
    double balance;
    public:

    Account() {
        this->balance = 0.0; 
    }
    Account(string accountNumber, string accountHolderName, double balance) {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    void deposit(double incomingBalance){
        balance += incomingBalance;
        cout << incomingBalance << " deposited into account " << accountNumber << endl;
    }

    void withdraw(double outgoingBalance){
        if(balance >= outgoingBalance){
            balance -= outgoingBalance;
            cout << outgoingBalance << " deducted from account " << accountNumber << endl;
        }
        else{
            cout << "Account Balance is unsufficient" << endl;
        }
        
    }

    void checkBalance() {
        // cout << "Account Name -> " << accountHolderName << endl;
        // cout << "Account Number -> " << accountNumber << endl;
        cout << "Account Balance of " << accountNumber << " -> " << balance << endl;

    }


};

int main() {
    Account a1("1111", "Person 1", 20),a2a1("1112", "Person 2", 23);
    a1.checkBalance();
    a1.deposit(10);
    a1.checkBalance();
    a1.withdraw(5);
    a1.checkBalance();
}