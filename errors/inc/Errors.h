#ifndef ERRORS_H
#define	ERRORS_H
#include <string>
#include "ErrorTypes.h"

//succes class used to manage succes messages
class Success_C
{
	private:
		static Success_E state;
		Success_C();
		
	public:	
		//get the success of Success_E type
		static Success_E GetSuccess();
		//set success 
		static void SetSuccess(Success_E state);	
		//print function for printing the success messages
		static void PrintSuccess(std :: string walletName = "", 
								char operation = '\0', float amount = 0);
};

//error class used to manage error messages
class Error_C
{
	private:
		static Error_E state;
		Error_C();
		
	public:	
		//get the error of Error_E type
		static Error_E GetError();
		//set error
		static void SetError(Error_E state);	
		//print function for printing the error messages
		static void PrintError(std :: string walletName = "",
							   std :: string amount = "");
};

#endif