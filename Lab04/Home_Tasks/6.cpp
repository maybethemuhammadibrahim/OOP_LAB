
#include<iostream>
using namespace std;

class Account {
    private:
    string accountNumber;
    string accountHolderName;
    double balance;
    public:

    Account():balance(0.0) {}
    Account(string accountNumber, string accountHolderName, double balance):accountNumber(accountNumber), accountHolderName(accountHolderName), balance(balance) {}

    void deposit(double addBalance){
        balance += addBalance;
        cout << addBalance << " deposited into account " << accountNumber << endl;
    }

    void withdraw(double removeBalance){
        if(balance >= removeBalance){
            balance -= removeBalance;
            cout << removeBalance << " deducted from account " << accountNumber << endl;
        }
        else{
            cout << "Account Balance is unsufficient" << endl;
        }
        
    }

    void checkBalance() {
        cout << endl;
        cout << "Account Name -> " << accountHolderName << endl;
        cout << "Account Number -> " << accountNumber << endl;
        cout << "Account Balance -> " << balance << endl;
        cout << endl;

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