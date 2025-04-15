#include <iostream>
using namespace std;

class PaymentMethod
{
protected:
public:
    virtual void processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod
{
protected:
    string cardNumber;

public:
    void processPayment(double amount) override
    {
        cout << "Payment of " << amount << " from card " << cardNumber << " has been verified" << endl;
    }
};

class DigitalWallet : public PaymentMethod
{
protected:
    double balance;

public:
    DigitalWallet(double amount = 0) : balance(amount) {}

    void processPayment(double amount) override
    {
        if ((balance - amount) > 0)
        {
            balance -= amount;
            cout << "Payment of " << amount << " has been verified and deducted" << endl;
        }
        else
        {
            cout << "You have insufficient funds to make the payment" << endl;
        }
    }
};

int main()
{
    CreditCard c;
    DigitalWallet d(200);
    PaymentMethod *p;
    p = &d;
    p->processPayment(220);
    p = &c;
    p->processPayment(220);
}
