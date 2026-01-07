#include <iostream>
#include <vector>
#include "CeaserCypher.h"
#include "Matrix.h"

using namespace std;


enum Encryptions {
    CEASER_CYPHER = 1,
    MATRIX
};

void printEncryptionMenu(const char* names[], const int size) {
    for (int i = 1; i < size + 1; i++) {
        cout << i << ". " << names[i - 1] << endl;
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


int main() {
    const char* encryptionNames[] = {
      "Ceaser Cypher",
      "Matrix"
    };
    const int NAMESIZE = 2;

    cout << "How would you like to encrypt your message? " << endl;

    printEncryptionMenu(encryptionNames, NAMESIZE);

    int choice = validateChoice(NAMESIZE);

    Encryption* encryptionMethod = nullptr;

    switch (choice) {
    case Encryptions::CEASER_CYPHER:
        encryptionMethod = new CeaserCypher;
        break;
    case Encryptions::MATRIX:
        encryptionMethod = new Matrix;
        break;
    }

    if (encryptionMethod != nullptr) {
        encryptionMethod->setSettings();
        cout << "Your encrypted message is \"" << encryptionMethod->encrypt() << "\"";
    }

}