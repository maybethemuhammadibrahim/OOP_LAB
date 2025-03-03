#include <iostream>
#include <string>
using namespace std;

void stringRev(string *strings, int n){
    char tempC;
    string temp;
    int counter;
    for(int i = 0; i < n; i++){
        int len = strings[i].length();
        // cout << len;
        for(int j = len - 1; j >= 0; j--){
            cout << strings[i][j];
            // cout << *(*(strings + i) + j);  
        }
        cout << endl;
    }
}

void wordVowelFinder(string *strings, int n) {
    int vowelCounter = 0, vowelCounterTemp = 0, index = -1; 
    for (int i = 0; i < n; i++) {
        vowelCounterTemp = 0; 
        for (int j = 0; j < strings[i].length(); j++) {
            if (strings[i][j] == 'a' || strings[i][j] == 'e' || strings[i][j] == 'i' || strings[i][j] == 'o' || strings[i][j] == 'u' ||
                strings[i][j] == 'A' || strings[i][j] == 'E' || strings[i][j] == 'I' || strings[i][j] == 'O' || strings[i][j] == 'U') {
                vowelCounterTemp++;
            }
        }
        
        if (vowelCounterTemp > vowelCounter) {
            vowelCounter = vowelCounterTemp;
            index = i; 
        }
    }

    
    if (index != -1) {
        cout << "The Word with the most vowels is " << strings[index] << endl;
    } else {
        cout << "No Word Found" << endl;
    }
}


void avgLengthFinder(string *strings, int n){
    float sum=0; 
    for(int i=0 ; i<n ; i++){
        sum += strings[i].length();
    }
    cout << "The average length of all the strings is "<< sum/n;
}

int main(){
    int n=3;
   
    cout << "Enter number of strings ";
    
    cin >> n;
    cin.ignore();
    string *strings = new string[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter String "<<i+1;
        getline(cin, strings[i]);
    }

    stringRev(strings,n);
    wordVowelFinder(strings, n);
    avgLengthFinder(strings, n);

    delete[] strings;
    
    
    
}