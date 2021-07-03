#include "body_of_program.h"
#include "input_output.h"
#include "work_with_files.h"

int main(void) {
	int choice = 0;
	Interval interval = { 0 };
	string stringForResults = { 0 };
	cout << "Welcome. Laborator work number 1 by student of 403 group: Shishko Daniil Yerevich" << endl;
	cout << "Aim of program: find a numbers in range, which is respond to sequence of the Fibonacci and simple numbers" << endl;
	do {
		choice = menu_and_input(&interval);
		if (choice != testOfProgram) {
			stringForResults = main_finction_for_finding_sequence_and_simple_numbers(interval, choice);
			save_input_data(&interval);
			cout << "Prime numbers belonging to the sequence of the Fibonacci:" << endl;
			cout << stringForResults << endl;
			save_results_in_file(stringForResults);
		}
		cout << "Enter number, if you want continue the program" << endl;
	} while (end_the_program());
	return 0;
}