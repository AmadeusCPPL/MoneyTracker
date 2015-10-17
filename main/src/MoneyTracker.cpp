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
	
	if (argc < 2) {
		cout << "error: No command specified."<<endl;
	}
	else if (argc == 2) {
			std::string str = argv[1]; 
			interpreter.setCommandState(str.c_str());
			Commands_C command = interpreter.getCommand();
			switch (command)
			{
				case CREATE: 
					Error_C :: SetError(NO_FILE_NAME_ERR);	
					Error_C :: PrintError();
				break;
				case INCOME: 
					Error_C :: SetError(NO_AMOUNT_ERR);	
					Error_C :: PrintError();
				break;
				
				case SPEND: 
					Error_C :: SetError(NO_SPEND_ERR);	
					Error_C :: PrintError();
				break;
				
				default:
				break;
			}
		}
		//return 0;
	 else {
		int i = 1;
		std::string str = argv[i]; 
		interpreter.setCommandState(str.c_str());
		Commands_C command = interpreter.getCommand();
		
		switch(command){
			case CREATE: {
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
				break;
			} 
			case INCOME: {
				string amount = "00.00";
				i++;
				if (i < argc) {
					amount = argv[i];
				}
				string typeOfEntry = "salary";
				interpreter.addEntry(amount, typeOfEntry);
				break;
			}
			case SPEND: {
				string amount = "00.00";
				i++;
				if (i < argc) {
					amount = argv[i];
				}
				string typeOfEntry = "other";
				interpreter.addEntry(amount, typeOfEntry);
				break;
			}
			default:{
				Error_C::SetError(COMMAND_ERR);
				break;
			}
		}
		
	}
	
	/* for (int i = 0; i < argc; i++) {
		cout <<endl<< i << " " << argv[i] << endl;
	} */
	return 0;
}
