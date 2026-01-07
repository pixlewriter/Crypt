#include "Encryption.h"

#include <iostream>

using namespace std;

void Encryption::setInputMessage(string message) {
	settings["Input Message"] = message;
}

string Encryption::getInputMessage() {
	if (settings.contains("Input Message")) {
		return settings["Input Message"];
	}
	else {
		cout << "You have not set an input message yet.";
		return "";
	}
	
}

string Encryption::getEncryptedMessage() {
	if (settings.contains("Encrypted Message")) {
		return settings["Encrypted Message"];
	}
	else {
		cout << "You have not encrypted the message yet. ";
		return "";
	}
}