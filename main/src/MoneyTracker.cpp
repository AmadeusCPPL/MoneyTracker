//============================================================================
// Name        : MoneyTracker.cpp
// Author      : AmadeusCPPL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "Interpreter.h"

using namespace std;

int main(int argc, char *argv[]) {
	Interpreter interpreter;
	if (argc <= 2) {
		Error_C :: SetError(NO_FILE_NAME_ERR);	
		Error_C :: PrintError();
		return 0;
	} else {
		int i = 1;
		//cout<<argv[i]<<endl;
		if (interpreter.isValidCommand(argv[i])){
			if (string(argv[i]) == "create") {
				i++;
				if (i < argc) {
					string fileName = argv[i];
					string amount = "+00.00";
					i++;
					if (i < argc) {
						amount = argv[i];
					}
					interpreter.createWallet(fileName, amount);
				}
			} else if (string(argv[i]) == "income") {
				string fileName = "file.txt";
				string amount = "+00.00";
				i++;
				if (i < argc) {
					amount = argv[i];
				}
				interpreter.addIncome(fileName, amount);
			}
		
		}
	}
	
	/* for (int i = 0; i < argc; i++) {
		cout <<endl<< i << " " << argv[i] << endl;
	} */
	return 0;
}
