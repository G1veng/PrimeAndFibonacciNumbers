#pragma once

#include <iostream>
#include <string>

using namespace std;

using std::cout;
using std::cin;

const int CHAR_NINE = 57;
const int CHAR_ZERO = 48;
const int CHAR_MINUS = 45;

int input_digit(void);
bool end_the_program(void);
string get_string_txt(void);
bool is_string_only_digits(string someString);