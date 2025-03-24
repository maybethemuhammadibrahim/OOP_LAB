#include <iostream>
using namespace std;

// 2
class Test {
    private:
    int data;

    public:
    Test(int data=0) : data(data) {}

    friend Test operator+(Test& obj, const int iData);
};
//nonmember operator requires a parameter with class or enum typeC/C++(898)
Test operator+(Test obj, const int iData) {
    return Test(obj.data + iData);
}

// class Test {
//     private:
//     int data;
//     public:

//     friend int testFunc(); 
// };

// int testFunc() {
//  return data;
// }
// // no instance of overloaded function "data" matches the required type
// //yes
// //no
// int main() {

// }
