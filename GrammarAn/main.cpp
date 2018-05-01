//
//  main.cpp
//  Re-decGrammarAnalysis
//
//  Created by Logan Lin on 2018/4/30.
//  Copyright © 2018年 Logan Lin. All rights reserved.
//

#include "main.hpp"
#include <stdlib.h>

int main() {
	GrammarAn grammarAn = GrammarAn();
	grammarAn.scan_file("in1.txt");
	grammarAn.scan_file("in2.txt");
	grammarAn.scan_file("in3.txt");
	grammarAn.scan_file("in4.txt");

	system("pause");
	return 0;
}