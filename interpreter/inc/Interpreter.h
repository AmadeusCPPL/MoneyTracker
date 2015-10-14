#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Errors.h"
#include "Wallet.h"
//#include "ListOfCommands.h"

class Interpreter
{
	private:
		Wallet wallet_;
		
	public:
		bool isValidCommand(const std :: string &command);
		void createWallet(std :: string &fileName, std :: string &amount);
		void addIncome(const std :: string &fileName, std :: string &amount);
		char returnOperation(const std :: string &amount);
		bool isValidAmount(const std :: string &amount);
		float roundNumber (const char operation, const float number);
};

#endif
