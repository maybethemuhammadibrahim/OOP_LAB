
/*
Imagine developing a comprehensive banking system simulator for a prominent financial
institution. In this system, a base class called Account encapsulates essential data members
such as accountNumber, balance, accountHolderName, and optionally accountType. It offers
‘member functions like deposit(amount) to add funds, withdraw(amount) to remove funds
with proper error checking, calculatelnterest() to compute interest based on varying rules,
printStatement() to output detailed transaction histories, and getAccountinfo() to retrieve
general account details.

Derived classes like SavingsAccount, CheckingAccount, and FixedDepositAccount extend
this structure by incorporating specialized data members—such as interestRate and
minimumBalance for SavingsAccount or maturityDate and fixedinterestRate for
FixedDepositAccount. These derived classes override key functions like calculatelnterest()
and printStatement() to provide account-type-specific functionalities. Additionally, the
withdraw() function is overridden in specific accounts to apply cifferent transaction rules,
ensuring that each account type follows realistic banking policies while maintaining
polymorphic behavior.
*/

#include <iostream>
using namespace std;

class Account {
protected:
    string accountNumber;
    string accountHolderName;
    float balance;

public:
    Account(string accNum, string accHolder, float initialBalance) {
        accountNumber = accNum;
        accountHolderName = accHolder;
        balance = initialBalance;
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    virtual void withdraw(float amount) {
        if (balance > amount && amount > 0 && balance != 0) {
            balance -= amount;
        }
    }

    virtual float calculateInterest(int months) {

    }; 

    virtual void printStatement() {
        cout << "Statement" << endl;
        cout << "=========" << endl;
        cout << "Your Balance is " << balance << endl;
    }

    void getAccountInfo() {
        cout << "Account Info" << endl;
        cout << "============" << endl;
        cout << "Account Number -> " << accountNumber << endl;
        cout << "Account Name -> " << accountHolderName << endl;
        cout << "Balance -> " << balance << endl;
    }
};

class SavingsAccount : public Account {
    float interestRate;
    float minimumBalance;

public:
    SavingsAccount(string accNum, string accHolder, float initialBalance, float rate, float minBal)
        : Account(accNum, accHolder, initialBalance), interestRate(rate), minimumBalance(minBal) {}

    float calculateInterest(int months) override {
        return balance * interestRate * (months / 12.0);
    }

    void printStatement() override {
        int month;
        cout << "Statement" << endl;
        cout << "=========" << endl;
        cout << "Your Balance is " << balance << endl;
        cout << "Your Interest Rate is " << interestRate << endl;
        cout << "Enter number of months: ";
        cin >> month;
        cout << "Your Interest is " << calculateInterest(month) << endl;
    }

    void withdraw(float amount) override {
        if (amount > 0 && (balance - amount) >= minimumBalance) {
            balance -= amount;
        } else {
            cout << "Withdrawal denied: Insufficient funds or below minimum balance." << endl;
        }
    }
};

class FixedDepositAccount : public Account {
    string maturityDate;
    float fixedInterestRate;

public:
    FixedDepositAccount(string accNum, string accHolder, float initialBalance, string matDate, float fixedRate)
        : Account(accNum, accHolder, initialBalance), maturityDate(matDate), fixedInterestRate(fixedRate) {}

    float calculateInterest(int months) override {
        return balance * fixedInterestRate * (months / 12.0);
    }

    void printStatement() override {
        int month;
        cout << "Statement" << endl;
        cout << "=========" << endl;
        cout << "Your Balance is " << balance << endl;
        cout << "Your Interest Rate is " << fixedInterestRate << endl;
        cout << "Enter number of months: ";
        cin >> month;
        cout << "Your Interest is " << calculateInterest(month) << endl;
    }
};

class CheckingAccount : public Account {
    float withdrawLimit;

public:
    CheckingAccount(string accNum, string accHolder, float initialBalance, float limit)
        : Account(accNum, accHolder, initialBalance), withdrawLimit(limit) {}

    void withdraw(float amount) override {
        if (amount > 0 && amount <= withdrawLimit && amount <= balance) {
            balance -= amount;
        } else {
            cout << "Withdrawal denied: Withdraw limit reached or insufficient balance." << endl;
        }
    }
};


int main() {
    
}