
#include <iostream>
#include <math.h>
using namespace std;

class Balance
{
private:
    double amount;

public:
    Balance(double amount = 0) : amount(amount) {}

    void operator+(const double &amount)
    {
        this->amount += amount;
    }
    void operator-(const double &amount)
    {
        this->amount -= amount;
    }
    void operator*(const float &multiplier)
    {
        this->amount *= multiplier;
    }
    void operator/(const float &divider)
    {
        this->amount /= divider;
    }

    double getAmount() const { return amount; }
};

class Account
{
protected:
    string accountNumber;
    string accountHolderName;
    Balance balance;

public:
    Account(string accountNumber = "", string accountHolderName = "", double balance = 0) : accountNumber(accountNumber), accountHolderName(accountHolderName)
    {
        this->balance + balance;
    }

    virtual double calculateInterest() = 0;

    virtual void withdraw(const double &amount) = 0;

    // for cash deposit
    void deposit(double amount)
    {
        balance + amount;
        cout << amount << " has been deposited into " << accountNumber << endl;
    }
    // for check deposit
    void deposit(string check)
    {
        // for simplicity assuming that the string will come in as "1000" etc and not "one thousand"
        double amount;
        int temp;
        for (int i = 0; i < check.length(); i++)
        {
            char c = check[i];
            if (c == ' ' || c < '0' || c > '9')
            {
                cout << "Error" << endl;
                return;
            }
            temp = (int)c;
            amount = temp * pow(10, i);
        }
        balance + amount;
        cout << amount << " has been deposited into " << accountNumber << endl;
    }

    // online transfer
    void deposit(double amount, bool isVerified)
    {
        // for simplicity assuming that through online transfer there is an additional check that verifies the payment
        if (isVerified){
            balance + amount;
            cout << amount << " has been deposited into " << accountNumber << endl;
        }
        else
            cout << "Payment not Verified" << endl;
    }

    void display() {
        cout << "Account Number: " << accountNumber << "\nBalance: " << balance.getAmount() << endl;
    }
};

class SavingsAccount : public Account
{
private:
    float interestRate; // per Year

public:
    SavingsAccount(string accountNumber = "", string accountHolderName = "", double balance = 0) : Account(accountNumber, accountHolderName, balance), interestRate(0.05) {}

    double calculateInterest() override
    { // calculates interest for one year
        return (balance.getAmount() * interestRate);
    }

    void withdraw(const double &amount) override
    {
        if (balance.getAmount() > 500)
        {
            balance - amount;
            cout << amount << " has been withdrawn from " << accountNumber << endl;
        }
        else
        {
            cout << "Cannot withdraw amount" << endl;
        }
    }
};

class CurrentAccount : public Account
{
private:
public:
    CurrentAccount(string accountNumber = "", string accountHolderName = "", double balance = 0) : Account(accountNumber, accountHolderName, balance) {}

    double calculateInterest() override
    { // calculates interest for one year
        return 0;
    }

    void withdraw(const double &amount) override
    {
        if(balance.getAmount() >= -1000) {
            balance - amount;
            cout << amount << " has been withdrawn from " << accountNumber << endl;
        }
        else {
            cout << "OverDraft limit reached" << endl;
        }
    }
};

int main() {
    // Create Savings and Current Account objects
    SavingsAccount sa("1001", "Person1[savings]", 1000);
    CurrentAccount ca("1002", "Person1[current]", 400);

    cout << "--- Initial Account States ---\n";
    sa.display();
    ca.display();

    // Demonstrate method overloading (deposit via different methods)
    cout << "\n--- Deposits ---\n";
    sa.deposit(200.0);                        // Cash
    sa.deposit("300");               // Check
    ca.deposit(500 ,true);              // Online transfer

    // Demonstrate method overriding (withdraw with rules)
    cout << "\n--- Withdrawals ---\n";
    sa.withdraw(600);  // Allowed (balance >= 500 after withdrawal)
    sa.withdraw(1000); // Not allowed (would drop below 500)
    ca.withdraw(1200); // Allowed (within overdraft limit)

    // Final state
    cout << "\n--- Final Account States ---\n";
    sa.display();
    ca.display();

    return 0;
}
