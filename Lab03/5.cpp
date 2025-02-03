
#include <iostream>
using namespace std;

class Calender {
    private:
    string months[12][31];
    const int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    public:
    Calender() {
        //initializing all days with no task
        for(int i = 0; i < 12; i++) {
            for(int j= 0; j < daysInMonths[i] ; j++) {
                months[i][j] = "No-Task";
            }
        }
    }

    void addTask(string taskDetails, int date, int month){

        if(date <= daysInMonths[month - 1]){
            months[month - 1][date - 1] = taskDetails;
        }
        else{
            cout << "In-Correct Inputs" << endl;
        }
        
    }

    void removeTask(int date, int month){

        if(date <= daysInMonths[month - 1]){
            months[month - 1][date - 1] = "No-Task";
        }
        else{
            cout << "In-Correct Inputs" << endl;
        }
        
    }

    void showTasks(){
        cout << "==============================" << endl;
        for(int i = 0; i < 12; i++) {
            cout << "Tasks For Month " << i + 1 << endl;
            cout << "===============" << endl;
            for(int j= 0; j < daysInMonths[i] ; j++) {
                if(months[i][j] != "No-Task"){
                    cout << j + 1 << "> " << months[i][j] << endl;
                }
            }
            cout << "===============" << endl;
            cout << "\n" << endl;
        }
        cout << "==============================" << endl;
    }
    
};

int main(){
    Calender year2025;
    year2025.addTask("Do This Task 01", 12, 1);
    year2025.addTask("Do This Task 02", 1, 2);
    year2025.addTask("Do This Task 03", 30, 3);
    year2025.addTask("Do This Task 04", 32, 4);//out of bounds , should not insert it
    year2025.addTask("Do This Task 05", 3, 12);
    year2025.addTask("Do This Task 06", 3, 11);
    year2025.showTasks();
    year2025.removeTask(12, 1);//removingfirst task
    year2025.showTasks();
}
