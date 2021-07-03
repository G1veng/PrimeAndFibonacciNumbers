#include "input_output.h"

int input_digit(void) {
	string buffer = { 0 };
	int i = 0;
	bool end = false;
	do {
		end = true;
		cin >> buffer;
		i = 0;
		do {
			if ((buffer[i] > CHAR_NINE || buffer[i] < CHAR_ZERO) && buffer[i] != CHAR_MINUS) {
				cout << "Error, please enter number" << endl;
				while (getchar() != '\n');
				end = false;
				break;
			}
			++i;
		} while (buffer[i] != '\0');
	} while (end != true);
	while (getchar() != '\n');
	i = stoi(buffer);
	return i;
}

bool end_the_program(void) {
	string buffer = { 0 };
	int i = 0;
	cin >> buffer;
	do {
		if ((buffer[i] > CHAR_NINE || buffer[i] < CHAR_ZERO) && buffer[i] != CHAR_MINUS) {
			while (getchar() != '\n');
			return false;
		}
		++i;
	} while (buffer[i] != '\0');
	while (getchar() != '\n');
	return true;
}

string get_string_txt(void) {
	string path;
	cout << "Enter way to folder please:" << endl;
	cin >> path;
	while (getchar() != '\n');
	return path;
}

bool is_string_only_digits(string someString) {
	size_t sizeOfString = someString.size();
	for (unsigned int i = 0; i < sizeOfString; ++i) {
		if (someString[i] > CHAR_NINE || someString[i] < CHAR_ZERO)
		return false;
	}
	return true;
}