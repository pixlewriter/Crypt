#include "Matrix.h"

using namespace std;

void Matrix::setSettings() {
	cout << "What is the input message? ";
	string input;
	getline(cin >> ws, input);
	setInputMessage(input);

	for (char letter : input) {
		if (letter >= 48 && letter <= 57) {
			cout << "Would you like to encode numbers as well? (if no, numbers will remain numbers, and will make it impossible to decrypt. ";
			getline(cin >> ws, input);
			settings["Encoded Numbers"] = input;
			break;
		}
	}

	cout << "How many rows does this matrix have? ";
	int rows;
	cin >> rows;
	settings["Matrix Rows"] = to_string(rows);

	cout << "How many columns does this matrix have? ";
	int columns;
	cin >> columns;
	settings["Matrix Columns"] = to_string(columns);

	settings["Key"] = "";

	cout << "Type in " << rows * columns << " numbers. (Hit Enter after each number). " << endl;
	for (int i = 0; i < rows * columns; i++) {
		int num;
		cin >> num;
		settings["Key"] += to_string(num);
	}
	
}

string Matrix::encrypt() {
	Eigen::MatrixXd keyMatrix(stoi(settings["Matrix Rows"]), stoi(settings["Matrix Columns"]));

	for (int i = 0; i < stoi(settings["Matrix Rows"]); i++) {
		for (int j = 0; j < stoi(settings["Matrix Columns"]); j++) {
			keyMatrix(i, j) = settings["Key"][i + j] - '0';
		}
	}


	int size = 0;
	
	string message = "";
	for (int i = 0; i < settings["Input Message"].size(); i++) {
		// Make letters lowercase
		char letter = tolower(settings["Input Message"][i]);
		// Turn all letters to 1-26
		if (letter >= 97 && letter <= 122) {
			message += to_string(letter - 96) + ' ';
			size++;
		}
		// Turn spaces to 0 or 27
		else if (letter == ' ') {
			message += "27";
			message += ' ';
			size++;
		}
		// Add the escape operator infront of every other character
		else {
			message += '~';
			message += letter;
			message += ' ';
		}
	}

	int padding = (size % stoi(settings["Matrix Rows"]));

	for (int i = 0; i < padding; i++) {
		message += "27";
		message += ' ';
	}
	
	vector<Eigen::MatrixXd> matrices;
	int rowAmt = stoi(settings["Matrix Rows"]);
	Eigen::MatrixXd currentMatrix = *(new Eigen::MatrixXd(rowAmt, 1));

	int charIndex = 0;
	for(int i =0; i <message.size();i++) {
		string character;
		for (; message[i] != ' '; i++) {
			character += message[i];
		}
		if (character[0] == '~') {
			continue;
		}
		currentMatrix(charIndex % rowAmt,0) = stoi(character);
		charIndex++;
		if (charIndex % rowAmt == 0) {
			matrices.push_back(currentMatrix);
			currentMatrix = *(new Eigen::MatrixXd(rowAmt, 1));
		}
	}
	
	for (int i = 0; i < matrices.size(); i++) {
		matrices[i] = keyMatrix * matrices[i];
	}

	currentMatrix = matrices[0];
	charIndex = 0;
	string newMessage;
	for (int i = 0; i < message.size(); i++) {
		string character;
		for (; message[i] != ' '; i++) {
			character += message[i];
		}
		if (character[0] == '~') {
			newMessage += character.substr(1) + ' ';
			continue;
		}
		newMessage += to_string((int) currentMatrix(charIndex % rowAmt, 0)) + ' ';
		charIndex++;
		if (charIndex % rowAmt == 0 && charIndex/rowAmt != matrices.size()) {
			currentMatrix = matrices[charIndex/rowAmt];
		}
	}

	return newMessage;

	
}

string Matrix::decrypt() {
	return "";
}