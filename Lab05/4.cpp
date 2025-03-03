/*
Create a BankAccount class. Which contains following details and functionalties:
Attributes: The BankAccount class has three private member variables: accountNumber,
accountHolderName, and balance.
Create Constructor: The class has a constructor that takes parameters to initialize the account
details (accountNumber, accountHolderName, and balance).
Create following Member Functions:
• deposit(double amount): Adds the specified amount to the account balance.
• withdraw(double amount): Subtracts the specified amount from the account balance, if
sufficient funds are available.
• display(): Displays the account details including the account number, account holder name,
and balance.
In the main() function, create an array accounts of BankAccount objects. The array contains three
elements, each representing a different bank account.
Initialize Each BankAccount object with specific account details such as account number, holder
name, and initial balance.
Perform following operations:
• Iterate through each account in the accounts array.
• For each account, display the account details using the display() function.
• Perform Two Transactions:
• Deposits 500.0 rupees into the account.
• Withdraws 200.0 rupees from the account.
• After each transaction, display the updated account details, including the new balance.
*/
#include <iostream>
using namespace std;

class BankAccount {
    private:
    string accountNumber;
    string name;
    float balance;

    public:
    BankAccount() : accountNumber(""), name("") , balance(0) {}

    BankAccount(string accountNumber, string name, float balance) : accountNumber(accountNumber), name(name) , balance(balance) {}

    void setAccountNumber(string accountNo) {
        this->accountNumber = accountNo;
    }

    void setName(string name) {
        this->name = name;
    }

    void setBalance(float balance) {
        this->balance = balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if(balance >= amount){
            balance -= amount;
        }
    }

    void displayDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance :" << balance << endl;
    }
};

int main () {
    BankAccount bank1[3];
    string tempStr;
    float temp;

    for(int i = 0; i < 3; i++) {
        cout << "Enter Account Number: " << endl;
        cin >> tempStr;
        bank1[i].setAccountNumber(tempStr);
        cout << "Enter Name: " << endl;
        cin >> tempStr;
        bank1[i].setName(tempStr);
        cout << "Enter Balance: " << endl;
        cin >> temp;
        bank1[i].setBalance(temp);
    }

    for(int i = 0; i < 3; i++) {
        cout << endl;
        bank1[i].displayDetails();
        cout << endl;
    }

    bank1[0].deposit(500);
    bank1[0].displayDetails();
    bank1[0].withdraw(600);
    bank1[0].displayDetails();



}