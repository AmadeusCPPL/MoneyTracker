#include "Errors.h"
#include <string>
#include <iostream>
#include <iomanip>

//initializing static variable "state" 
Success_E Success_C::state = IS_EMPTY;
Error_E Error_C::state = IS_OK;

//Success class methods 
void Success_C::SetSuccess(Success_E state)
{
	Success_C::state = state;
}
Success_E Success_C::GetSuccess()
{
	return state;
}
void Success_C::PrintSuccess(std::string walletName, char operation, 
								float amount)
{
	switch (Success_C::state)
	{
		case IS_EMPTY:
		std::cout << "";
		break;

		case FILE_CREATED_SUCC:
		if (amount !=0) {
			std::cout << walletName << " created with the initial amount of "<< 
			operation << std::fixed << std::setprecision(2) <<amount <<" RON\n";
		} else {
			std::cout << walletName << " created with the initial amount of "<< 
			operation << "00.00" <<" RON\n";
		}
		
		break;
		
		default:
		break;		
	}
}

//Error class methods 
void Error_C :: SetError(Error_E state)
{
	Error_C :: state = state;
}
		
Error_E Error_C :: GetError()
{
	return state;
}

void Error_C :: PrintError(std :: string walletName, std :: string amount)
{
	switch (Error_C :: state)
	{
		case IS_OK:
		std :: cout << "no error";
		break;

		case FILE_NAME_ERR:
		std :: cout << "error: wallet " << walletName << " already exists!\n";
		break;
		
		case AMOUNT_ERR:
		std :: cout << "error: " << amount << 
			" is not a valid initial amount.\n";
		std :: cout << "Creating " << walletName << " aborted.\n";
		break;
		
		case COMMAND_ERR:
		std :: cout << "error: invalid command\n";
		break;
		
		case NO_FILE_NAME_ERR:
		std :: cout << "error: at least filename should be specified.\n";
		break;
		
		case NEG_INCOME_ERR:
		std :: cout << "error: income should be higher than 0.\n";
		break;
		
		case INVALID_INCOME_ERR:
		std :: cout << "error: parameter for 'income' should be a positive number.\n";
		break;
		
		case  NO_AMOUNT_ERR:
		std :: cout << "error: no ammount specified for 'income'.\n";
		break;
		
		case OPEN_FILE_ERR:
		std :: cout << "error: could not open "<< "some.wallet" << 
				       "to register transaction\n";
		break;
		
		case INVALID_INITIAL_AMOUNT:
		std :: cout << "error: "<< walletName << " is not a valid initial ammount\n";
		break;
		
		default:
		break;		
	}
}