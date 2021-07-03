#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

using std::cout;
using std::cin;

enum Errors {
	outOfMemory = -2,
	fileIsNotExisting,
	fileIsNotReserved,
	dataInFileIsIncorrect,
};

enum Work_with_files {
	userChooseFolder = 1,
};

void save_results_in_file(string stringForResults);
void input_from_file(Interval* interval);
void save_input_data(Interval* interval);