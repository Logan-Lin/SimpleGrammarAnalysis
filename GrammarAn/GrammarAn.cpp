//
//  GrammarAn.cpp
//  Re-decGrammarAnalysis
//
//  Created by Logan Lin on 2018/4/30.
//  Copyright © 2018年 Logan Lin. All rights reserved.
//

#include "GrammarAn.hpp"

vector<int> GrammarAn::row2codings(string line) {
	vector<int> result = vector<int>();

	int pos = 0;
	int aggregate_pos = 0;
	while (aggregate_pos <= line.length() - 1) {
		string temp_str = line.substr(aggregate_pos);
		int start_pos = temp_str.find("(");
		int end_pos = temp_str.find(")");
		int comma_pos = temp_str.find(",");
		string coding_string = temp_str.substr(start_pos + 1, comma_pos - start_pos - 1);
		result.push_back(stoi(coding_string));

		pos = end_pos + 1;
		aggregate_pos += pos;
	}
    
    return result;
}

void GrammarAn::file2codings()
{
	inputs.clear();
	int length = 0;
	char line_buffer[1024];
	while (fgets(line_buffer, 1024, fin) != NULL) {
		string line = string(line_buffer);
		line = line.substr(0, line.length() - 1);
		if (line.length() == 0)
			continue;
		vector<int> row_vector = row2codings(line);
		inputs.insert(inputs.end(), row_vector.begin(), row_vector.end());
	}
	inputs.push_back(-1);
}

int GrammarAn::current()
{
	return inputs[scan_index];
}

bool GrammarAn::A()
{
	if (current() == 48 || current() == 49) {
		if (!V())
			return false;
		scan_index++;
		if (!(current() == 33))
			return false;
		scan_index++;
		if (!E()) 
			return false;
		return true;
	}
	else if (current() == 22) {
		return true;
	}
	else if (current() == 23) {
		return true;
	}
	else {
		return false;
	}
}

bool GrammarAn::E()
{
	if (current() == 48 || current() == 49 || current() == 28) {
		if (!T())
			return false;
		scan_index++;
		if (!E_())
			return false;
		return true;
	}
	else {
		return false;
	}
}

bool GrammarAn::E_()
{
	if (current() == 22 || current() == 23 || current() == 48 || current() == 49) {
		if (!A())
			return false;
		scan_index++;
		if (!T())
			return false;
		scan_index++;
		if (!E_())
			return false;
		return true;
	}
	else {
		scan_index--;
		return true;
	}
}

bool GrammarAn::T()
{
	if (current() == 28 || current() == 48 || current() == 49) {
		if (!F())
			return false;
		scan_index++;
		if (!T_())
			return false;
		return true;
	}
	else {
		return false;
	}
}

bool GrammarAn::T_()
{
	if (current() == 24 || current() == 25) {
		if (!M())
			return false;
		scan_index++;
		if (!F())
			return false;
		scan_index++;
		if (!T_())
			return false;
		return true;
	}
	else {
		scan_index--;
		return true;
	}
}

bool GrammarAn::F()
{
	if (current() == 28) {
		scan_index++;
		if (!E())
			return false;
		scan_index++;
		if (!(current() == 29))
			return false;
		return true;
	}
	else if (current() == 48 || current() == 49) {
		return true;
	}
	else {
		return false;
	}
}

bool GrammarAn::M()
{
	if (current() == 24) {
		return true;
	}
	else if (current() == 25) {
		return true;
	}
	else {
		return false;
	}
}

bool GrammarAn::V()
{
	if (current() == 48 || current() == 49) {
		return true;
	}
	else {
		return false;
	}
}

void GrammarAn::scan_file()
{
	scan_file("in.txt");
}

void GrammarAn::scan_file(const char file_name[])
{
	fin = fopen(file_name, "r");
	if (fin == NULL) {
		cout << "Unable to open file!";
		exit(1);
	}
	file2codings();
	scan_index = 0;
	cout << "File " << file_name << ": ";
	if (A()) {
		cout << "Valid input!\n";
	}
	else {
		cout << "Invalid input!" << endl;
		cout << "Error at position " << scan_index + 1 << " where coding is " << inputs[scan_index] << endl;
	}
}
