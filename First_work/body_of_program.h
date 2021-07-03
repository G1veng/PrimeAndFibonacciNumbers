#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

using std::cout;
using std::cin;

const int RAND_MINIMUM = 50;
const int RAND_MAXIMUM = 1000;
const int FIRST_NUMBER_SEQUENCE_OF_FIBONACCI = 2;
const int SECOND_NUMBER_SEQUENCE_OF_FIBONACCI = 3;
const int TEST_SIZE = 6;

struct Interval {
	int first_point;
	int second_point;
};

enum Inputs {
	mainFunction,
	manualInput,
	randomInput,
	fileInput,
	testOfProgram,
};

int menu_and_input(Interval*);
string main_finction_for_finding_sequence_and_simple_numbers(Interval& interval, int whichInput);
bool is_prime_numbers(int number);