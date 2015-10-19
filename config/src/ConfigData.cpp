#include <string>
#include <fstream>
#include <iostream>
#include "ConfigData.h"
#include "Errors.h"
#include "Utils.h"
using namespace std;

ConfigData::ConfigData()
{
}

std::string ConfigData::readFromFile(const std::string field, const std::string fileName) 
{
	//std::string fileName = "moneytracker.config";
	/* if (fileExists (fileName.c_str())) {
		fileName = "moneytracker.config";
	} else {
		fileName = "..\\moneytracker.config";
	} */
	bool flag = false;
	string lineContent = "";
	string result = "";
	if (fileExists (fileName.c_str())) {
		ifstream walletConfig(fileName.c_str());
		while (getline(walletConfig, lineContent)) {
			std::size_t found = lineContent.find(field);
			if (found!=std::string::npos) {
				//lineContent.erase(std::remove(lineContent.begin(),lineContent.end(),' '),lineContent.end()); 
				lineContent = removeSpaces(lineContent);
				size_t found = lineContent.find_last_of("=");
				result = lineContent.substr(found+1);
				//result = "..\\" + result;
				flag = true;
			} 
		}
		walletConfig.close();
		if (!flag) {
			Error_C::SetError(DEFAULT_WALL_CONFIG_ERR);
			Error_C::PrintError();
			//cout<<"ii de aici"<<endl;
		}
	} else {
		Error_C::SetError(OPEN_CONFIG_ERR);
		Error_C::PrintError();
	}
	return result;
}
/* void updateFile(const std :: string key, const std :: string value)
{
	
} */

std :: string ConfigData::getWallet() 
{
	string defaultWallet = "";
	defaultWallet = readFromFile("default_wallet");
	return defaultWallet;
}

/*std :: string getDefaultCurrency() {}
std :: string getDefaultIncome() {}
std :: string getDefaultSpending() {} */

/* bool ConfigData::fileExists (const std :: string &fileName) 
{
	ifstream f(fileName.c_str());
    if (f.good()) {
        f.close();
        return true;
    }
    f.close();
    return false;
} */

