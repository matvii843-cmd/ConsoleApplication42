#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Task 4. Function that returns string length without strlen()
int customLength(const string& str) {
    int count = 0;
    for (char c : str) {
        if (c != '\0') {
            count++;
        }
    }
    return count;
}

// Task 5. Function that removes a specified character and returns a new string
string removeCharacter(const string& str, char target) {
    string result = "";
    for (char c : str) {
        if (c != target) {
            result += c;
        }
    }
    return result;
}

int main() {
    int choice;

    do {
        cout << "\nMENU:\n";
        cout << "1. Count 'a' vs 'o' (Cyrillic)\n";
        cout << "2. Count Latin letters, digits, and spaces\n";
        cout << "3. Swap uppercase and lowercase letters\n";
        cout << "4. Get string length without strlen()\n";
        cout << "5. Remove a specified character\n";
        cout << "6. String statistics (whitespaces, vowels, consonants, punctuation)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear input buffer before using getline
        cin.ignore();

        switch (choice) {
        case 1: {
            string str;
            cout << "Enter a string: ";
            getline(cin, str);

            int countA = 0, countO = 0;
            for (char c : str) {
                if (c == 'а' || c == 'А' || c == 'a' || c == 'A') countA++;
                if (c == 'о' || c == 'О' || c == 'o' || c == 'O') countO++;
            }

            cout << "Count of 'а': " << countA << endl;
            cout << "Count of 'о': " << countO << endl;
            if (countA > countO) {
                cout << "There are more 'а' letters." << endl;
            }
            else if (countO > countA) {
                cout << "There are more 'о' letters." << endl;
            }
            else {
                cout << "Both letters appear equally." << endl;
            }
            break;
        }
        case 2: {
            string str;
            cout << "Enter a string: ";
            getline(cin, str);

            int latinCount = 0, digitCount = 0, spaceCount = 0;
            for (char c : str) {
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                    latinCount++;
                }
                else if (c >= '0' && c <= '9') {
                    digitCount++;
                }
                else if (isspace(c)) {
                    spaceCount++;
                }
            }

            cout << "Latin letters: " << latinCount << endl;
            cout << "Digits: " << digitCount << endl;
            cout << "Spaces: " << spaceCount << endl;
            break;
        }
        case 3: {
            string str;
            cout << "Enter a string: ";
            getline(cin, str);

            for (char& c : str) {
                if (islower(c)) {
                    c = toupper(c);
                }
                else if (isupper(c)) {
                    c = tolower(c);
                }
            }

            cout << "Swapped string: " << str << endl;
            break;
        }
        case 4: {
            string str;
            cout << "Enter a string: ";
            getline(cin, str);

            cout << "Length of the string: " << customLength(str) << endl;
            break;
        }
        case 5: {
            string str;
            cout << "Enter a string: ";
            getline(cin, str);

            char target;
            cout << "Enter the character to remove: ";
            cin >> target;

            string newStr = removeCharacter(str, target);
            cout << "Original string: " << str << endl;
            cout << "New string: " << newStr << endl;
            break;
        }
        case 6: {
            string str;
            cout << "Enter an English string: ";
            getline(cin, str);

            int whitespaces = 0, vowels = 0, consonants = 0, punctuation = 0;
            for (char c : str) {
                if (isspace(c)) {
                    whitespaces++;
                }
                else if (ispunct(c)) {
                    punctuation++;
                }
                else if (isalpha(c)) {
                    char lower = tolower(c);
                    if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                        vowels++;
                    }
                    else {
                        consonants++;
                    }
                }
            }

            cout << "Whitespaces: " << whitespaces << endl;
            cout << "Vowels: " << vowels << endl;
            cout << "Consonants: " << consonants << endl;
            cout << "Punctuation marks: " << punctuation << endl;
            break;
        }
        case 0: {
            cout << "Exiting program." << endl;
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}