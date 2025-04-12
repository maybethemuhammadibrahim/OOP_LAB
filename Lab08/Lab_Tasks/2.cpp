
#include <iostream>
using namespace std;

class Account {
    private:
        string accountNumber;
        string accountHolderName;
        double balance;

    public:
    Account(string accountNumber = "" , string accountHolderName = "", double balance = 0) : accountNumber(accountNumber), accountHolderName(accountHolderName), balance(balance) {}

    Account operator+(const Account& other) {
        Account temp;
        temp.balance = this->balance + other.balance;
        return (temp);
    }

    Account &operator-=(double amount) {
        balance -= amount;
        return(*this);
    }
    Account &operator+=(double amount) {
        balance += amount;
        return(*this);
    }

    bool operator>(const Account& other) {
        return (this->balance > other.balance);
    }
    //true if a1 balance is > a2 balance

    friend ostream &operator<<( ostream &output, const Account &a ) { 
        output << "Account Number: " << a.accountNumber <<"\nAccount Holder Name: " << a.accountHolderName << "\nBalance: " << a.balance << endl;
        return output;            
     }
    
};



int main() {
    Account a("A001", "Person1", 5000), b("A002", "Person2", 3000);

    Account c = a + b;
    cout << c;

    a -= 2000;//taking from a
    b += 2000;//transferring to b
    cout << a;
    cout << b;

    bool isAGreater = a>b;
    if(isAGreater)
        cout << "A has more balance" << endl;
    else
        cout << "B has more balance" << endl;
    

}

