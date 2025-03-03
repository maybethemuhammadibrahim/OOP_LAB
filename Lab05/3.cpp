/*
Create a class called ValidateString. The purpose of this class will be check if the given characters in a
string are alphabet only. Numbers and symbols will mean that the string is invalid. By using a
parameterized constructor, create multiple objects for your class that accept different strings. Create a
constant function that checks whether the string variable is valid or not.
What happens if you do not make your function constant? Add a comment right above your function
explaining why we make a function constant.
*/
#include <iostream>
using namespace std;

class ValidateString {
    private:
    string str;

    string checkStr(string str) {
        for(int i = 0; i < str.length(); i++) {
            // cout << str[i];
            if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))) {
                cout << "String not Validated" << endl;
                return "error";
            }
        }
        return str;
    }

    public:
    ValidateString(string input) {
        str = checkStr(input);
    }
};

int main() {
    ValidateString s("st32");
    ValidateString s2("st");
}
