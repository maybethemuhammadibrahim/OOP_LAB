#include <iostream>
using namespace std;

class Currency
{
protected:
    float amount;
    string currencyCode;
    char currencySymbol;
    float exchangeRate; // exchange rate of the currency wrt USD

public:
    Currency(float amount = 0, string currencyCode = "null", char currencySymbol = '.', float exchangeRate = 0) : amount(amount), currencyCode(currencyCode), currencySymbol(currencySymbol), exchangeRate(exchangeRate) {}

    float getExchangeRate()
    {
        return exchangeRate;
    }

    virtual float convertToBase() // assuming base is USD
    {
        float baseAmount ;
        if(exchangeRate != 0) {
            baseAmount = (amount / exchangeRate);
        }
        
        // cout << "Amount " << currencySymbol << amount << "in USD is $" << baseAmount << endl;
        return baseAmount;
    }

    float convertTo(Currency& target)
    {
        // float targetInBase = target.convertToBase();
        float currentCurrencyinBase = convertToBase();
        float targetAmount = currentCurrencyinBase * target.getExchangeRate();
        return targetAmount;
    }

    virtual void displayDetails()
    {
        cout << "Amount: " << currencySymbol << amount << endl;
        cout << "Currency Code: " << currencyCode << endl;
        cout << "Currency Symbol: " << currencySymbol << endl;
        cout << "Exchange Rate: " << exchangeRate << endl;
    }
};

class Dollar : public Currency
{
private:
public:
    Dollar(float amount = 0, float exchangeRate = 1.0) : Currency(amount, "USD", '$', exchangeRate) {}

    float convertToBase() override
    {
        cout << "Currency already in Base" << endl;
        return amount;
    }

    void displayDetails() override {

    }
};

class Euro : public Currency
{
private:
public:
    Euro(float amount = 0, float exchangeRate = 1.1) : Currency(amount, "EUR", '€', exchangeRate) {}


    void displayDetails() override {
        
    }
};

class Rupee : public Currency
{
private:
public:
    Rupee(float amount = 0, float exchangeRate = 0.00357) : Currency(amount, "PKR", 'Rs', exchangeRate) {}
    

    void displayDetails() override {
        
    }
};

int main()
{
    Euro eur(50);
    Rupee pkr(1000);

    eur.displayDetails();
    pkr.displayDetails();

    cout << "50 EUR in INR: " << eur.convertTo(pkr) << "Rs" << endl;
    cout << "1000 INR in EUR: " << pkr.convertTo(eur) << " €" << endl;

    return 0;
}
