#include "Errors.h"
#include <string>
#include <iostream>
#include <iomanip>     
#include <time.h> 
#include <stdlib.h>
#include <math.h>

//function used to return the system time
std::string Success_C::GetTime()
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];

	time (&rawtime);
	timeinfo = localtime (&rawtime);

	strftime (buffer,80," %a, %d %b %Y %H:%M:%S GMT",timeinfo);
	std::string mystring = std::string(buffer);
	
	return mystring;	
}

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
		
		case INCOME_REG_SUCC:
			std::cout << "Income 'salary' in an amount of "<< 
						std::fixed << std::setprecision(2) << amount <<
						 " RON was registered.\n";
			std::cout << "Transaction time: "<< Success_C::GetTime();
		break;
		
		case SPEND_REG_SUCC:
			std::cout<<"Spending 'other' in an amount of "<< 
						std::fixed << std::setprecision(2) << amount <<
					   " RON was registered.\n";
			std::cout << "Transaction time: "<< Success_C::GetTime();
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
		std :: cout << "error: could not open "<< walletName << 
				       " to register transaction\n";
		break;
		
		case INVALID_INITIAL_AMOUNT:
		std :: cout << "error: "<< walletName << " is not a valid initial ammount\n";
		break;
		
		case OPEN_CONFIG_ERR:
		std::cout << "error: could not open configuration 'moneytracker.config'\n";
		break;
		
		case DEFAULT_WALL_CONFIG_ERR:
		std::cout << "error: no default wallet configured in 'moneytracker.config\n";
		break;
		
		case NEG_SPEND_ERR:
		std::cout << "error: spend should be higher than 0.\n";
		break;
		
		case INVALID_SPEND_ERR:
		std::cout << "error: parameter for 'spend' should be a positive number.\n";
		break;
		
		case NO_SPEND_ERR:
		std::cout << "error: no ammount specified for 'spend'.\n";
		default:
		break;		
	}
}
/* 
		float amountSum = atof(amount.c_str());
		std :: cout << "error: " << std::fixed << std::setprecision(2) << amountSum <<  
			" is not a valid initial amount.\n";
		std :: cout << "Creating " << walletName << " aborted.\n"; */