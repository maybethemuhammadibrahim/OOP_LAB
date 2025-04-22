/*
1. Prompt the user to enter:
○ string name
○ string email
○ int yearsOfExperience
○ string summary
2. Write this data to a file called resume.txt.
3. Use ofstream with ios::trunc to ensure that any previous contents are completely
deleted before writing new data.
4. After writing, read back and display the contents to confirm that the file only has the
latest entry.
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string tempString;
    int tempInt;

    ofstream out("resume.txt", ios::trunc);
    if (!out.is_open())
    {
        cerr << "Error opening File" << endl;
    }

    cout << "Enter Name Of User:" << endl;
    cin >> tempString;
    out << tempString << "\n";

    cout << "Enter Email Of User:" << endl;
    cin >> tempString;
    out << tempString << "\n";

    cout << "Enter Years Of Experience Of User:" << endl;
    cin >> tempInt;
    out << tempInt << "\n";

    cout << "Enter Summary Of User:" << endl;
    cin >> tempString;
    out << tempString << "\n";

    if (out.is_open())
    {
        out.close();
        cout << "File Closed!" << endl;
    }

    ifstream in("resume.txt");
    if (!out.is_open())
    {
        cerr << "Error opening File" << endl;
    }
    while (!in.eof())
    {
        in >> tempString;
        cout << tempString << "\n";
    }
    if (in.is_open())
    {
        in.close();
        cout << "File Closed!" << endl;
    }
}
