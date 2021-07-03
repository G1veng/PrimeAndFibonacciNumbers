#include "body_of_program.h"
#include "input_output.h"
#include "work_with_files.h"

void save_results_in_file(string stringForResults) {
	string path = { 0 };
	cout << "If you want save results in file enter 1, else to deny" << endl;
	if(input_digit() == userChooseFolder) {
		do {
			path = get_string_txt();
			ofstream file(path, ios_base::out | ios_base::trunc);
			try {
				bool trueOrFalse = fs::is_regular_file(path);
			}
			catch (...) {
				cout << "Error, please try again" << endl;
				continue;
			}
			if ((file.is_open()) || !file.fail()) {
				file.close();
				break;
			}
		} while (true);
		ofstream file(path, ios_base::out | ios_base::trunc);
		file << stringForResults;
		file.close();
		cout << "Result saved" << endl;
	}
}

void input_from_file(Interval* interval) {
	string path = { 0 };
	do {
		path = get_string_txt();
		try {
			bool trueOrFalse = fs::is_regular_file(path);
		}
		catch (...) {
			cout << "Error, please try again" << endl;
			continue;
		}
		ifstream file(path, ios_base::out);
		if (!(file.is_open())) {
			cout << "File is not existing" << endl;
			file.close();
		}
		if((file.is_open()) || !file.fail()) {
			file.close();
			break;
		}
	} while (true);
	ifstream file(path, ios_base::in);
	file >> path;
	if (is_string_only_digits(path)) {
		interval->first_point = stoi(path);
	}
	else {
		cout << "Incorrect data in file" << endl;
		exit(dataInFileIsIncorrect);
	}
	file >> path;
	if (is_string_only_digits(path)) {
		interval->second_point = stoi(path);
	}	else {
		cout << "Incorrect data in file" << endl;
		exit(dataInFileIsIncorrect);
	}
	file.close();
	cout << "From " << interval->first_point << " to " << interval->second_point << endl;
}

void save_input_data(Interval* interval) {
	string path = { 0 };
	string outputIntFile = { 0 };
	cout << "If you want save entered data in file enter 1, else to deny" << endl;
	if (input_digit() == userChooseFolder){
		do {
			path = get_string_txt();
			ofstream file(path, ios_base::out | ios_base::trunc);
			try {
				bool trueOrFalse = fs::is_regular_file(path);
			}
			catch (...) {
				cout << "Error, please try again" << endl;
				continue;
			}
			if ((file.is_open()) || !file.fail()) {
				file.close();
				break;
			}
		} while (true);
		ofstream file(path, ios_base::out | ios_base::trunc);
		path = to_string(interval->first_point);
		outputIntFile = (path);
		file << outputIntFile << " ";
		path = to_string(interval->second_point);
		outputIntFile = (path);
		file << outputIntFile << " ";
		file.close();
		cout << "Result saved" << endl;
	}
}