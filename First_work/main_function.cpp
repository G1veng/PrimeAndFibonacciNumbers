#include "body_of_program.h"

bool is_prime_numbers(int number) {
	for (int i = 2; i < number / 2; ++i) {
		if (i != number) {
			if (number % i == 0)
				return false;
		}
	}
	return true;
}

string main_finction_for_finding_sequence_and_simple_numbers(Interval& interval, int whichInput) {
	int temp = 0, prev = FIRST_NUMBER_SEQUENCE_OF_FIBONACCI, next = SECOND_NUMBER_SEQUENCE_OF_FIBONACCI;
	string stringForResults = { 0 };
	if (interval.first_point > interval.second_point) {
		if (whichInput == mainFunction)
			cout << "First point need to be lower than second, please try again" << endl;
		return stringForResults;
	}
	if (interval.second_point < 0) {
		if (whichInput == mainFunction)
			cout << "Second point need to be higher than 0, please try again" << endl;
		return stringForResults;
	}
	if (interval.first_point < 0)
		interval.first_point = 0;
	do {
		if (prev >= interval.first_point && prev <= interval.second_point) {
			if (is_prime_numbers(prev) == true) {
				stringForResults += to_string(prev);
				stringForResults = stringForResults + " ";
			}
		}
		temp = prev + next;
		prev = next;
		next = temp;
	} while (prev <= interval.second_point);
	return stringForResults;
}