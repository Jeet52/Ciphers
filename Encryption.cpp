#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function prototypes
void printMenu();

int main() {
    string command;

    cout << "Welcome to Ciphers!" << endl;
    cout << "-------------------" << endl << endl;

    do {
        printMenu();
        cout << "\nEnter a command (case does not matter): ";
        getline(cin, command);
        cout << endl;

        // Caesar Encrypt
        if (command == "c" || command == "C") {
            string plainText;
            string numCharactersStr;
            int numCharacters;

            cout << "Enter the text to encrypt:" << endl;
            getline(cin >> ws, plainText);

            cout << "Enter the number of characters to rotate by:" << endl;
            getline(cin, numCharactersStr);
            try {
                numCharacters = stoi(numCharactersStr);
            } catch (...) {
                cout << "Invalid rotation number! Please enter an integer." << endl;
                continue;
            }
            numCharacters %= 26;  // Wrap around in case number > 26

            string encryptedText;
            for (char c : plainText) {
                if (isalpha(c)) {
                    char base = isupper(c) ? 'A' : 'a';
                    char encryptedChar = ((c - base + numCharacters) % 26) + base;
                    encryptedText += toupper(encryptedChar);  // Convert all to uppercase
                } else {
                    encryptedText += c;
                }
            }

            cout << "Encrypted text: " << encryptedText << endl;
        }

        // Vigenère Encrypt
        else if (command == "v" || command == "V") {
            string plainText, key, cleanKey;
            cout << "Enter text to encrypt:" << endl;
            getline(cin, plainText);

            // Convert plaintext to uppercase
            for (char &c : plainText)
                c = toupper(c);

            cout << "Enter the Vigenère key:" << endl;
            getline(cin >> ws, key);

            // Clean key: remove spaces and convert to uppercase
            for (char c : key)
                if (!isspace(c))
                    cleanKey += toupper(c);

            if (cleanKey.empty()) {
                cout << "Key cannot be empty." << endl;
                continue;
            }

            string encryptedText;
            int keyIndex = 0;

            for (char c : plainText) {
                if (isalpha(c)) {
                    int shift = cleanKey[keyIndex] - 'A';
                    char encryptedChar = ((c - 'A' + shift) % 26) + 'A';
                    encryptedText += encryptedChar;
                    keyIndex = (keyIndex + 1) % cleanKey.length();
                } else {
                    encryptedText += c;
                }
            }

            cout << "Encrypted text: " << encryptedText << endl;
        }

        // Caesar Decrypt Attempt (dictionary attack)
        else if (command == "d" || command == "D") {
            vector<string> dictionary;
            ifstream inFile("dictionary.txt");
            if (!inFile.is_open()) {
                cout << "Failed to open dictionary.txt! Make sure the file exists." << endl;
                continue;
            }

            string word;
            while (inFile >> word) {
                for (char &c : word)
                    c = toupper(c);
                dictionary.push_back(word);
            }
            inFile.close();

            cout << "Enter the text to Caesar-cipher decrypt:" << endl;
            string cipherText;
            getline(cin >> ws, cipherText);

            // Extract words and convert to uppercase
            vector<string> words;
            string buffer;
            for (char c : cipherText) {
                if (isalpha(c)) {
                    buffer += toupper(c);
                } else if (!buffer.empty()) {
                    words.push_back(buffer);
                    buffer.clear();
                }
            }
            if (!buffer.empty())
                words.push_back(buffer);

            bool foundAny = false;
            for (int rotation = 1; rotation <= 25; rotation++) {
                for (const string &word : words) {
                    string decryptedWord;
                    for (char c : word)
                        decryptedWord += ((c - 'A' + rotation) % 26) + 'A';

                    for (const string &dictWord : dictionary) {
                        if (dictWord == decryptedWord) {
                            cout << "Match found (rotation " << rotation << "): " << decryptedWord << endl;
                            foundAny = true;
                        }
                    }
                }
            }

            if (!foundAny) {
                cout << "No dictionary matches found for any Caesar rotations." << endl;
            }
        }

        // Exit
        else if (command == "x" || command == "X") {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }

        else {
            cout << "Invalid command. Please enter one of the options." << endl;
        }

        cout << endl;

    } while (true);

    return 0;
}

void printMenu() {
    cout << "Ciphers Menu" << endl;
    cout << "------------" << endl;
    cout << "C - Encrypt with Caesar Cipher" << endl;
    cout << "D - Decrypt Caesar Cipher" << endl;
    cout << "V - Encrypt with Vigenère Cipher" << endl;
    cout << "X - Exit Program" << endl;
}
