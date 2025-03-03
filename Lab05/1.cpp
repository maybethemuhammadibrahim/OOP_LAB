
#include <iostream>
#include <limits.h>
using namespace std;

float CalcAverage(float *numbers, int n){
    float sum = 0;
    for(int i = 0; i < n ; i++){
        sum += *(numbers+i);
    }
    return sum/n;
}

float FindClosest(float *numbers, int n, float avg){
    float diff=INT_MAX,temp, numberClosest;
    for(int i = 0; i < n ; i++){
        temp = avg-*(numbers+i);
        temp = (temp<0)?temp*-1:temp*1;
        if(temp <= diff){
            diff = temp;
            numberClosest = *(numbers+i);
        }
    }
    return numberClosest;
}

int main(){
    int n;
    cout << "Enter the number(n) of elements you want to enter:" << endl;
    cin >> n;
    float *numbers = new float[n];
    for(int i=0 ; i<n ; i++){
        cout << "Enter Number " << i+1 <<" : ";
        cin >> *(numbers+i);
    }
    float avg = CalcAverage(numbers, n);
    cout<<"The Average of the numbers is "<<avg<<endl;
    float numberClosest = FindClosest(numbers, n , avg);
    cout<<"The Closest number to average is "<<numberClosest<<endl;


}