#ifndef UTILS_H
#define	UTILS_H
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <algorithm>

//function used to remove spaces from an input string
std::string removeSpaces(std::string input)
{
	std::string str = input;
	str.erase(std::remove(str.begin(),str.end(),' '),str.end());
	str.erase(std::remove(str.begin(),str.end(),'\t'),str.end());
	return str;
}

//function used to check if the amount is valid (does not contain ",")
/* bool isValidAmount(const std::string &amount)
{
	for(unsigned int i = 0; i < amount.length(); i++)
	{
		if(amount[i] == ',')
			return 0;
	}
	return true;
} */

//function used to return the operation "+" or "-"
/* char returnOperation(const std::string &amount)
{
	char operation = '\0';
	if(amount[0] == '-'){
		operation = '-';
	}
	else{
		operation = '+';
	}
	return operation;
} */

//function used to return the float round number with 2 decimals
/* float roundNumber (const char operation, const float number)
{
	if (operation == '+') {
		return roundf(number * 100) / 100;
	} else {
		return ceilf(number * 100) / 100;
	}
		
} */

//function used to check if a filename allready exists, returns a bool 
bool fileExists (const std::string &fileName) 
{
	std::ifstream f(fileName.c_str());
    if (f.good()) {
        f.close();
        return true;
    }
    f.close();
    return false;
}

#endif