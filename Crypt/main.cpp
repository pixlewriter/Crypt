#include <iostream>
#include <vector>
#include <conio.h>
#include <stdio.h>
#include <format>
#include "CeaserCypher.h"
#include "Matrix.h"

using namespace std;


enum Encryptions {
    CEASER_CYPHER = 1,
    MATRIX
};

void printEncryptionMenu(int current ,const char* names[], const int size) {
    string cursor = "";
    for (int i = 1; i < size + 1; i++) {
        if (current == i) {
            cursor = "> ";
        }
        else {
            cursor = "- ";
        }
        cout << cursor << i << ". " << names[i - 1] << endl;
       
    }
}

int validateChoice(const int enumSize) {
    int choice = 0;
    cin >> choice;
    while (choice < 0 || choice > enumSize) {
        cin >> choice;
    }
    return choice;
}

int displayMenu(const char* names[], const int size) {
    //This string return the cursor to the start of the menu by moving the cursor up by the number of options \x1B[{number of lines}A
    //then return the cursor to the start of the line \r
    string returnString = format("\x1B[{}A\r", size);
    int current = 1;
    printEncryptionMenu(current, names, size);

    while (true) {
        if (_kbhit()) { // Check if a key has been pressed
            char key = _getch(); // Get the key character
            if (key == -32 || key == 0) {
                key = _getch();
                switch (key) {
                    case 72:
                        current = ((current++) % size)+1;
                        cout << returnString;
                        printEncryptionMenu(current, names, size);
                        break;
                    case 80:
                        if (current <= 1) current = size;
                        else current--;
                        cout << returnString;
                        printEncryptionMenu(current, names, size);
                        break;
                    default:
                        break;
                }
            }
            else if (key == 13) {
                return current;
            }
            else {
                cout << key << "=" << (int) key << endl;
            }
            
        }
    }
    return 0;
}

int main() {
    const char* encryptionNames[] = {
      "Ceaser Cypher",
      "Matrix"
    };
    const int NAMESIZE = 2;

    cout << "How would you like to encrypt your message? " << endl;

    int choice = displayMenu(encryptionNames, NAMESIZE);

    Encryption* encryptionMethod = nullptr;

    switch (choice) {
    case Encryptions::CEASER_CYPHER:
        encryptionMethod = new CeaserCypher;
        break;
    case Encryptions::MATRIX:
        encryptionMethod = new Matrix;
        break;
    default:
        cout << choice;
    }

    if (encryptionMethod != nullptr) {
        encryptionMethod->setSettings();
        cout << "Your encrypted message is \"" << encryptionMethod->encrypt() << "\"";
    }

}