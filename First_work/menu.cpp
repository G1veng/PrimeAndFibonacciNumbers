#include "body_of_program.h"
#include "input_output.h"
#include "work_with_files.h"

int menu_and_input(Interval* interval) {
	srand((unsigned)time(NULL));
	int choice = 0;
	cout << "Menu:\n1 - to manual input\n2 - to random input\n3 - to file input\n4 - to test program" << endl;
	choice = input_digit();
	switch (choice) {
	case manualInput: {
		cout << "Enter the interval from first point to second point" << endl;
		cout << "Enter first point" << endl;
		interval->first_point = input_digit();
		cout << "Enter second point" << endl;
		interval->second_point = input_digit();
		break;
	}
	case randomInput: {
		interval->first_point = rand() % (RAND_MINIMUM) + 1;
		interval->second_point = rand() % (RAND_MAXIMUM - RAND_MINIMUM + 1) + RAND_MINIMUM;
		cout << "From " << interval->first_point << " to " << interval->second_point << endl;
		break;
	}
	case fileInput: {
		input_from_file(interval);
		break;
	}
	case testOfProgram: {
		Interval interval = { 0 };
		int countOfError = 0;
		bool error[TEST_SIZE] = { 0 };
		bool anyErrors = false;
		string stringForResults = { 0 };
		ifstream file("test.txt", ios_base::in);
		if (!file.is_open()) {
			cout << "File is not existing" << endl;
			exit(fileIsNotExisting);
		}
		if(file.fail()) {
			cout << "File test is not existing" << endl;
			exit(fileIsNotExisting);
		}
		string someString = { 0 };
		for (int count = 0; count < TEST_SIZE; ++count) {
			error[count] = false;
		}
		for (int count = 0; count < TEST_SIZE; ++count) {
			file >> someString;
			interval.first_point = stoi(someString);
			file >> someString;
			interval.second_point = stoi(someString);
			stringForResults = main_finction_for_finding_sequence_and_simple_numbers(interval, testOfProgram);
			getline(file, someString);
			if (stringForResults.size() != (someString.size() + 1))
				error[count] = true;
			++countOfError;
		}
		for (int count = 0; count < TEST_SIZE; ++count) {
			if (error[count] == true) {
				cout << "Error in " << count + 1 << " test" << endl;
				anyErrors = true;
			}
		}
		if (anyErrors == false)
			cout << "All test succeeded" << endl;
		file.close();
		break;
	}
	default:
		cout << "There is no these choice, please try again" << endl;
	}
	return choice;
}