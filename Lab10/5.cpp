#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    fstream file("info.txt", ios::in | ios::out);
    if (!file)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    string searchWord, replacementWord, temp;
    streampos pos;
    bool found = false;

    cout << "Enter the word to replace -> ";
    cin >> searchWord;
    cout << "Enter the replacement word -> ";
    cin >> replacementWord;

    if (replacementWord.length() > searchWord.length())
    {
        cout << "Cutting down your replacement word as it is longer than the word it is going to replace." << endl;
        replacementWord = replacementWord.substr(0, searchWord.length());
    }
    else if (replacementWord.length() < searchWord.length())
    {
        int paddingNeeded = searchWord.length() - replacementWord.length();
        replacementWord.append(paddingNeeded, '_');
    }

    while (file >> temp)
    {
        pos = file.tellg();

        if (temp == searchWord)
        {
            file.seekp(pos - static_cast<streamoff>(temp.length()));

            file << replacementWord;

            found = true;
        }
    }

    file.close();

    if (found)
    {
        cout << "\nWord(s) replaced successfully. Updated file content:\n"
             << endl;
    }
    else
    {
        cout << "Word not found in the file." << endl;
    }

    return 0;
}
