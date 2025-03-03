/*
Create a class called LoanHelper, which helps the user calculate their loan payments. The class
should have a variable that stores interest rate for the loan as a user defined constant value. Aside
from the that, it also stores the amount for the loan taken and amount of months that the user will
repay the loan in. The loan repayment should be calculated on a monthly basis, and the interest rate
should be applied over the monthly return amount. The output should be something like:
“You have to pay 999 every month for 12 monthsto repay your loan”
Note: first divide loan amount by number of months, then apply the interest rate on it. Interest rate
should be a value between 0-0.5%
*/

#include <iostream>
using namespace std;

float valueVerifier(float rate){
    if(rate>=0 && rate<=0.5) {
           return rate;
        }
        else {
            cout << "Wrong interest value" << endl;
            return -1;
        }
}
class LoanHelper {
    private:
    const float interestRate;
    float loanAmount;
    int months;
    public:
    LoanHelper() : interestRate(0) , loanAmount(0) , months(0) {}

    LoanHelper(float rate, float loanAmount, int months) : interestRate(valueVerifier(rate)) , loanAmount(loanAmount) , months(months) {}

    void calcLoan() {
        if(interestRate == -1){
            return ;
        }
        float monthlyRepayment=0 , loanWithInterest=0;
        monthlyRepayment = loanAmount/months;//no interest
        loanWithInterest = monthlyRepayment + (monthlyRepayment*(interestRate/100));//with interest
        cout << "You have to pay " << loanWithInterest << " every month for " << months << endl;
    }


}; 


int main() {
    LoanHelper l1(0.5, 10000, 10);
    l1.calcLoan();

}