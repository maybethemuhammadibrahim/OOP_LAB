#include <iostream>
#include <conio.h>
using namespace std;

class TestClass {
    private:
    static int objectCount;
    int serialNo;
    public:
    //constructor
   TestClass(){
    serialNo = objectCount;
    objectCount++;
   }
    
   void getSerialNo(){
    cout << "My Serial Number is " << serialNo << endl;
   }

   void getObjectCount(){
    cout << "The total objects created till now is " << objectCount << endl;
   }
};

int TestClass::objectCount = 1;

int main() {
    TestClass o1;
    TestClass o2;
    TestClass o3;
    o1.getSerialNo();
    o2.getSerialNo();
    o3.getSerialNo();

}