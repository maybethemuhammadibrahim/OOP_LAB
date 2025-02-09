
#include<iostream>
using namespace std;

class StationaryShop {
    private:
    string *items;
    float *prices;
    int noOfItems;

    public:
    StationaryShop() : items(nullptr), prices(nullptr), noOfItems(0) {}


    ~StationaryShop() {
        delete[] items;
        delete[] prices;
    }

    void addItem(string item, float price){
        
        // string *newItems;
        string *newItems = new string[noOfItems + 1];
        float *newPrices = new float[noOfItems + 1];

        for (int i = 0; i < noOfItems; i++)
        {
            newItems[i] = items[i];
            newPrices[i] = prices[i];
        }

        newItems[noOfItems] = item;
        newPrices[noOfItems] = price;

        delete[] items;
        delete[] prices;

        items = newItems;
        prices = newPrices;
        noOfItems++;
    }
    

    void listItems() {
        cout << "Listing all items with prices" << endl;
        for (int i = 0; i < noOfItems; i++) {
            cout << i+1 << "=>" << items[i] << "=>" << prices[i] << endl;
        }
    }

    void editPrice(string item, float newPrice) {
        bool itemFound = false;
        for (int i = 0; i < noOfItems; i++) {
            if(item == items[i]) {
                prices[i] = newPrice;
                itemFound = true;
                break;
            }
            else {
                itemFound = false;
            }
        }
        if(!itemFound){
            cout << "Item not found" << endl;
        }
    }
};

int main()
{
    StationaryShop s1;
    cout << "Stationary Shop Management System" << endl;
    cout << "=================================" << endl;
    cout << "add->to add item\nedit->to edit price of an item\nlist->to display all items\nexit->to exit program" << endl;
    string input = "NULL";
    do{
        cout << ">";
        cin >> input;
        if(input == "add") {
            string tempName; float tempPrice;
            cout << "Enter the name of the item" << endl;
            cin >> tempName;
            cout << "Enter the price of the item" << endl;
            cin >> tempPrice;
            s1.addItem(tempName, tempPrice);
        }
        else if(input == "edit") {
            string tempName; float tempPrice;
            cout << "Enter the name of the item of which you want to edit the price" << endl;
            cin >> tempName;
            cout << "Enter the new price of the item" << endl;
            cin >> tempPrice;
            s1.editPrice(tempName, tempPrice);
        }
        else if(input == "list") {
            s1.listItems();
        }
        else if(input == "exit") {
            break;
        }
        else {
            cout << "Enter an appropriate command" << endl;
        }

    }while(input != "exit");
    return 0;
}
