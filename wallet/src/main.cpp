//============================================================================
// Name        : MainArgs.cpp
// Author      : AmadeusCPPL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Wallet.h"
#include "Errors.h"
using namespace std;

int main(int argc, char *argv[]) {
	
	if (argc <= 1) {
		cout << "There are no arguments:" << endl;
	} else {
		cout << "There are " << argc << " arguments:" << endl;
		for (int i = 0; i < argc; i++) {
			cout << i << " " << argv[i] << endl;
		}
	}


	Error_C :: SetError(IS_OK);		
	WalletEntry walletEntry;
	cout<<walletEntry.getTimestamp ()<<endl;
	Wallet wallet;
	//cout<<wallet.fileExists ("..\\wallet.txt");
	wallet.createNewWalletFile ("..\\fisier.txt", '+', 0);
	wallet.addIncome ("..\\fisier.txt", '-', 255.557);
	return 0;
}
