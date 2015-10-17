#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include "Interpreter.h"


using namespace std;

// bool Interpreter :: isValidCommand(const string &command)
// {
	// if(command == "create" || command == "income"){
		// return true;
	// }
	// return false;
// }

void Interpreter::setCommandState(const string comLine)
{
	if(comLine == "create"){
		Interpreter::command = CREATE;
	}
	else if(comLine == "income"){
		Interpreter::command = INCOME;
	}
	else if(comLine == "spend"){
		Interpreter::command = SPEND;
	}
	else{
		Interpreter::command = INVALID_COMMAND;
	}
}

Commands_C Interpreter::getCommand()
{
	return Interpreter::command;
}

bool Interpreter::isValidAmount(const string &amount)
{
	std::string result = amount;
	if (amount[0]=='+'||amount[0]=='-') {
		result = amount.substr(1);
		//cout<<"amount : "<<result<<endl;
	}
	return result.find_first_not_of("0123456789.") == string::npos;	
}

/* bool Interpreter::isValidAmount(const string &amount)
{
	for(unsigned int i = 0; i < amount.length(); i++){
		if(amount[i] == ',')
			return false;
	}
	return true;
} */

char Interpreter::returnOperation(const string &amount)
{
	char operation = '+';
	if(command == SPEND){
		operation = '-';
	} else if ((command == CREATE)&&(amount[0] == '-')) {
		operation = '-';
	}
	return operation;
}

void Interpreter::createWallet(string &fileName, string &amount)
{
	char operation = returnOperation(amount);
	//to do if this extension will be required
	//fileName = fileName + ".txt";
	float amountSum = 0;
	if(isValidAmount(amount) == false){
		Error_C :: SetError(AMOUNT_ERR);
		Error_C :: PrintError(fileName, amount);
	}
	else{
		amountSum = fabs(atof(amount.c_str())); 
		amountSum = roundNumber(operation, amountSum);
		wallet_.createNewWalletFile(fileName, operation, amountSum);
	}
}

void Interpreter::addEntry(string &amount, const string &typeOfEntry)
{
	float amountSum;
	if(isValidAmount(amount) == false){
		if (typeOfEntry == "salary") {
				Error_C :: SetError(INVALID_INCOME_ERR);
		} 
		else {
			Error_C :: SetError(INVALID_SPEND_ERR);
		}
		Error_C :: PrintError();
	}
/* 	else if(amount[0] == '-'){
		Error_C :: SetError(NEG_INCOME_ERR);
		Error_C :: PrintError();
	} */
	else{
		char operation = returnOperation(amount);
		amountSum = atof(amount.c_str());
		amountSum = roundNumber(operation, amountSum);
		if(amountSum <= 0){
			if (typeOfEntry == "salary") {
				Error_C :: SetError(NEG_INCOME_ERR);
			} 
			else {
				Error_C :: SetError(NEG_SPEND_ERR);
			}
			Error_C :: PrintError();
		}
		else{
			wallet_.addEntry(operation, amountSum, typeOfEntry);
		}
	}
}

float Interpreter::roundNumber (const char operation, const float number)
{
	if (operation == '+') {
		return roundf(number * 100) / 100;
	} else {
		return ceilf(number * 100) / 100;
	}
		
}


