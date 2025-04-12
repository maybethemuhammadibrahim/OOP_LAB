/*
An E-commerce website provides multiple ways to calculate the total price of a customer&#39;s
order based on the type of product. There are two main product categories:
1. Electronics: Tax rate 15%
2. Clothing: Tax rate 5%
The website supports different discount methods based on the type of user (Regular or
Premium). Additionally, the website allows combining multiple carts and applying arithmetic
operations to calculate total prices dynamically.
Task Requirements:
1. Create a base class Product with attributes like productID, price, and a virtual function
calculatePrice().
2. Implement two derived classes:
o Electronics (Applies 15% tax)
o Clothing (Applies 5% tax)
3. Overload the applyDiscount method to handle different discount types:
o Percentage discount (e.g., 10% off)
o Fixed discount (e.g., $20 off)
o Buy One Get One Free
4. Override the calculatePrice method to apply category-specific tax rates.
5. Implement operator overloading for the ShoppingCart class:
o + to merge two shopping carts
o - to remove an item from the cart
o * to apply bulk discounts
o / to split cart total among multiple users
6. Create objects for Electronics and Clothing categories, demonstrate method overloading,
overriding, and operator overloading by simulating an online shopping experience.
*/
#include <iostream>
using namespace std;

class Product
{
protected:
    string productID;
    double price;

public:
    Product(string productID = "", double price = 0) : productID(productID), price(price) {}

    virtual double calculatePrice() = 0;

    void applyDiscount(const float &percentOFF)
    {
        if (percentOFF > 100)
        {
            cout << "Sorry, cannot apply discount greater than 100%" << endl;
            return;
        }

        price -= (price * (percentOFF / 100));
        cout << "Discount of " << (price * (percentOFF / 100)) << "applied" << endl;
    }

    void applyDiscount(const int &fixedPrice)
    {
        price -= fixedPrice;
    }

    // buy one and "n" items free
    void applyDiscount(string &n)
    {
        cout << "Buy One, Get " << n << " applied" << endl;
    }

    string getProductID() const { return productID; }
    double getPrice() const { return price; }
};

class Electronics : public Product
{
private:
    float tax;

public:
    Electronics(string productID = "", double price = 0) : Product(productID, price), tax(0.15) {}

    double calculatePrice() override
    {
        return (price + (price + tax));
    }

    friend ostream &operator<<(ostream &output, Electronics &e)
    {
        output << "Item ID->" << e.getProductID() << "\nPrice After Tax(15%)" << e.calculatePrice() << endl;
        return output;
    }
};

class Clothing : public Product
{
private:
    float tax;

public:
    Clothing(string productID = "", double price = 0) : Product(productID, price), tax(0.05) {}

    double calculatePrice() override
    {
        return (price + (price + tax));
    }

    friend ostream &operator<<(ostream &output, Clothing &e)
    {
        output << "Item ID->" << e.getProductID() << "\nPrice After Tax(5%)" << e.calculatePrice() << endl;
        return output;
    }
};

class ShoppingCart
{
private:
    Electronics *e;
    int noOfe;

    Clothing *c;
    int noOfc;

public:
    ShoppingCart(Electronics *e = nullptr, int noOfe = 0, Clothing *c = nullptr, int noOfc = 0)
        : noOfe(noOfe), noOfc(noOfc)
    {
        this->e = (noOfe > 0) ? new Electronics[noOfe] : nullptr;
        if (e && noOfe > 0)
        {
            for (int i = 0; i < noOfe; i++)
                this->e[i] = e[i];
        }

        this->c = (noOfc > 0) ? new Clothing[noOfc] : nullptr;
        if (c && noOfc > 0)
        {
            for (int i = 0; i < noOfc; i++)
                this->c[i] = c[i];
        }
    }

    ~ShoppingCart()
    {
        delete[] e;
        delete[] c;
    }
    void displayShoppingCart()
    {
        cout << "Electronic Items" << endl;
        for (int i = 0; i < noOfe; i++)
        {
            cout << e[i];
        }
        cout << "Clothing Items" << endl;
        for (int i = 0; i < noOfc; i++)
        {
            cout << c[i];
        }
    }
    friend ShoppingCart operator+(const ShoppingCart &s1, const ShoppingCart &s2)
    {
        ShoppingCart toReturn;

        Electronics *elec = new Electronics[s1.noOfe + s2.noOfe];

        int tempIndex;
        for (int i = 0; i < s1.noOfe; i++)
        {
            elec[i] = s1.e[i];
            tempIndex = i;
        }
        int j = 0;
        for (int i = 0; i < s1.noOfe + s2.noOfe; i++)
        {
            elec[i + s1.noOfe] = s2.e[j++];
        }
        toReturn.noOfe = s1.noOfe + s2.noOfe;
        toReturn.e = elec;

        tempIndex = 0;
        Clothing *cloth = new Clothing[s1.noOfc + s2.noOfc];
        for (int i = 0; i < s1.noOfc; i++)
        {
            cloth[i] = s1.c[i];
            tempIndex = i;
        }
        j = 0;
        for (int i = 0; i < s1.noOfc + s2.noOfc; i++)
        {
            cloth[i + s1.noOfc] = s2.c[j++];
        }
        toReturn.noOfc = s1.noOfc + s2.noOfc;
        toReturn.c = cloth;

        return toReturn;
    }

    void operator-(const Product &p)
    {
        bool matchFound = false;
        for (int i = 0; i < noOfe; i++)
        {
            if (e[i].getProductID() == p.getProductID())
            {
                cout << "Match Found in e" << endl;
                matchFound = true;
                break;
            }
            else
            {
                matchFound = false;
            }
        }

        for (int i = 0; i < noOfc; i++)
        {
            if (c[i].getProductID() == p.getProductID())
            {
                cout << "Match Found in c" << endl;
                matchFound = true;
                break;
            }
            else
            {
                matchFound = false;
            }
        }

        if (matchFound == false)
        {
            cout << "Product not found" << endl;
        }
    }

    // will calculate only discount (savings)on all taxed items of shopping cart
    double operator*(float discount)
    {
        double totalDiscount = 0;

        for (int i = 0; i < noOfe; i++)
        {
            totalDiscount += (e[i].calculatePrice() * discount);
        }
        for (int i = 0; i < noOfc; i++)
        {
            totalDiscount += (c[i].calculatePrice() * discount);
        }
        return totalDiscount;
    }

    double operator/(int noOfCustomers)
    {
        double total = 0;

        for (int i = 0; i < noOfe; i++)
        {
            total += (e[i].calculatePrice());
        }
        for (int i = 0; i < noOfc; i++)
        {
            total += (c[i].calculatePrice());
        }
        return total / noOfCustomers;
    }
};

int main()
{
    // Create some electronics and clothing products
    Electronics e1("E101", 1000);
    Electronics e2("E102", 1500);
    Clothing c1("C201", 500);
    Clothing c2("C202", 800);

    // Apply different discounts
    e1.applyDiscount(10.0f); // 10% off
    e2.applyDiscount(100);   // $100 off
    string bogo = "One Free";
    c1.applyDiscount(bogo); // Buy one get one

    // Create arrays for the shopping carts
    Electronics electronics1[] = {e1};
    Clothing clothing1[] = {c1};
    ShoppingCart cart1(electronics1, 1, clothing1, 1);

    Electronics electronics2[] = {e2};
    Clothing clothing2[] = {c2};
    // ShoppingCart cart2(electronics2, 1, clothing2, 1);

    // Merge both carts
    // ShoppingCart mergedCart = cart1 + cart2;

    // cout << "\n--- Merged Shopping Cart ---" << endl;
    // mergedCart.displayShoppingCart();

    // Remove a product
    // cout << "\n--- Trying to Remove Product E101 ---" << endl;
    // mergedCart - e1;

    // cout << "\n--- Trying to Remove Product C999 (non-existent) ---" << endl;
    // Clothing fake("C999", 100);
    // mergedCart - fake;

    // Calculate discount value on all items
    // double discountAmount = mergedCart * 0.10; // 10% discount
    // cout << "\nTotal Discount on All Items (10%): $" << discountAmount << endl;

    // Split total price among 4 customers
    // double splitAmount = mergedCart / 4;
    // cout << "\nEach Customer Pays: $" << splitAmount << endl;

    return 0;
}
