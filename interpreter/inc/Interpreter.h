#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Errors.h"
#include "Wallet.h"
//#include "Utils.h"
enum Commands_C
{
	CREATE,
	INCOME,
	SPEND,
	INVALID_COMMAND
};

class Interpreter
{
	private:
		Wallet wallet_;
		Commands_C command;
		
	public:
	
		//bool isValidCommand(const std :: string &command);
		
		Commands_C getCommand();
		
		void setCommandState(const std::string comLine);
		
		void createWallet(std :: string &fileName, std :: string &amount);
		
		void addEntry(std::string &amount, const std::string &typeOfEntry);
						
		char returnOperation(const std :: string &amount);
		
		bool isValidAmount(const std :: string &amount);
		
		float roundNumber (const char operation, const float number);
};

#endif
