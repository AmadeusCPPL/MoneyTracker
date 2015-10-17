#ifndef WALLET_H
#define WALLET_H

#include <vector>

#include "WalletEntry.h"

class Wallet
{
	private:
		//stores the initial sum of a wallet
		float initialSum_;
		
		//stores the current currency
		std :: string currency_;
		
		//stores a vector of WalletEntry elements
		//Input : a WalletEntry
		std::vector<WalletEntry> walletList_; 
	
	public:
		//Constructor with no arguments
		Wallet();
		
		//Creates a new wallet file 
		//Input : walletName , sign of the amount, amount
		void createNewWalletFile(const std :: string &wallet, 
								const char operation, const float amount);
								
		//Adds a WalletEntry to the walletList		
		//Input : walletName , sign of the amount, amount
		void addEntry(const char operation, const float amount, 
						const std::string &typeOfEntry);
						
		//check if a filename allready exists
		//returns a bool 
		bool fileExists (const std :: string &fileName);

		//std :: string SplitFilename (const std :: string &str);
};


#endif