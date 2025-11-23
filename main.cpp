#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * Generates valid test strings for the Turing Machine Coursework.
 * Format: [Sequence of Char1] [Sequence of Char2] *
 * Output: Writes directly to test.txt
 */
int main() {
    srand(static_cast<unsigned int>(time(0)));

    char char1, char2;
    int amount;


    cout << "Enter the first letter (e.g., d): ";
    cin >> char1;

    cout << "Enter the second letter (e.g., g): ";
    cin >> char2;

    cout << "How many test strings to generate? ";
    cin >> amount;


    ofstream outFile("test.txt");

    if (!outFile.is_open()) {
        cout << "Error: Could not create test.txt" << endl;
        return 1;
    }

    cout << "Generating " << amount << " test strings into test.txt..." << endl;

    for (int i = 0; i < amount; ++i) {
        int len1 = rand() % 3;
        int len2 = rand() % 3;


        if (len1 == 0 && len2 == 0) {
            if (rand() % 2 == 0) len1 = 1;
            else len2 = 1;
        }


        string testCase = "";
        for (int j = 0; j < len1; ++j) testCase += char1;
        for (int j = 0; j < len2; ++j) testCase += char2;

        testCase += '*';


        outFile << testCase << endl;
    }

    outFile.close();

    cout << "Success! " << amount << " test strings have been written to test.txt" << endl;

    return 0;
}
