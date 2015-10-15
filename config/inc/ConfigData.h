#ifndef CONFIGURATION_H
#define CONFIGURATION_H

class ConfigData
{
	private:
		std :: string wallet_;
		std :: string defaultCurrency_;
		std :: string defaultIncome_;
		std :: string defaultSpending_;
		std :: string currencies_;
		std :: map <string, float> rateType_;
		
	public:
		ConfigData();
		void updateFile(const std :: string key, const std :: string value);
		Configuration readFromFile();
		std :: string getWallet();
		std :: string getDefaultCurrency();
		std :: string getDefaultIncome();
		std :: string getDefaultSpending();
};

#endif