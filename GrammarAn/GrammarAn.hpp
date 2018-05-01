//
//  GrammarAn.hpp
//  Re-decGrammarAnalysis
//
//  Created by Logan Lin on 2018/4/30.
//  Copyright © 2018年 Logan Lin. All rights reserved.
//

#ifndef GrammarAn_hpp
#define GrammarAn_hpp

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class GrammarAn {
private:
    // Indicate where the current position is.
    int scan_index;
    // File pointer for input file.
    FILE * fin;
    
    // Array for storing inputed binary formula.
	vector<int> inputs = vector<int>();
    // Turing a line of lexical output to coding vector
	vector<int> row2codings(string line);
	// Turing the content of whole file into coding vector
	void file2codings();

	// Return the integer at current position
	int current();
    
    // Recursive subroutine representing non-terminal symbols.
	bool A();
	bool V();
	bool E_();
	bool T();
	bool T_();
	bool F();
	bool M();
	bool V();
public:
	// Scan the input file and give out result.
	void scan_file();
	void scan_file(const char file_name[]);
};

#endif /* GrammarAn_hpp */
