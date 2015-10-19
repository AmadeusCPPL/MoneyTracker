#ifndef CONFIGDATA_H
#define CONFIGDATA_H

#include <string>

class ConfigData
{
	private:
		std :: string wallet_;
/* 		std :: string defaultCurrency_;
		std :: string defaultIncome_;
		std :: string defaultSpending_;
		std :: string currencies_;
		std :: map <string, float> rateType_; */
		//bool fileExists (const std :: string &fileName);
		
	public:
		ConfigData();
		std::string readFromFile(const std::string field, 
			const std::string fileName = "moneytracker.config");
		std :: string getWallet();
		/* void updateFile(const std :: string key, const std :: string value);
		std :: string getDefaultCurrency();
		std :: string getDefaultIncome();
		std :: string getDefaultSpending();*/
};

#endif