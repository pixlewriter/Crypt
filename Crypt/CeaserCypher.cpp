#include "CeaserCypher.h"

using namespace std;

void CeaserCypher::setSettings() {
	cout << "What is the input message? ";
	string input;
	getline(cin >> ws, input);
	setInputMessage(input);

	cout << "How much would you like to shift the letters by? (1-26) ";
	int shift;
	cin >> shift;
	while (shift < 1 || shift > 26) {
		cout << "Pick a number 1-26. ";
		cin >> shift;
	}
	settings["shift"] = to_string(shift);
}

string CeaserCypher::encrypt() {
	if (getInputMessage() == "") {
		setSettings();
	}

	int shift = stoi(settings["shift"]);
	settings["Encrypted Message"] = "";
	for (char letter : settings["Input Message"]) {

		//Lower Case letters
		if (letter >= 97 && letter <= 122 - shift) {
			settings["Encrypted Message"] += letter + shift;
		}
		else if (letter + shift > 122) {
			int wrapAmt = (letter + shift) % 122;
			char newLetter = 96 + wrapAmt;
			settings["Encrypted Message"] += newLetter;
		}
		//Upper Case Letters
		else if (letter >= 65 && letter <= 90 - shift) {
			settings["Encrypted Message"] += letter + shift;
		}
		else if (letter + shift > 90) {
			int wrapAmt = (letter + shift) % 90;
			char newLetter = 64 + wrapAmt;
			settings["Encrypted Message"] += newLetter;
		}
		//Everything else
		else {
			settings["Encrypted Message"] += letter;
		}
	}

	return settings["Encrypted Message"];
}

string CeaserCypher::decrypt() {
	return "";
}