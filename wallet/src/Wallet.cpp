#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "Wallet.h"
#include "Errors.h"

using namespace std;

Wallet :: Wallet () 
{
	//cout<<"ceapa lui de wallet";
}

void Wallet :: createNewWalletFile (const std :: string &wallet, 
									const char operation, const float amount) 
{
	/*cout<<"OHOOOOOO "<<wallet<<endl;
	cout<<"OHOOOOOO "<<operation<<endl;
	cout<<"OHOOOOOO "<<amount<<endl; */
	string fileName = wallet;
	if (fileExists (fileName.c_str())) {
		Error_C :: SetError(FILE_NAME_ERR);	
		Error_C :: PrintError(fileName);
	} else {
		ofstream workFile;
		workFile.open(fileName.c_str());
		if (!workFile.good()) {
		Error_C :: SetError(OPEN_FILE_ERR);	
		Error_C :: PrintError(fileName);
		workFile.close();
		} else {
			workFile << operation;
			if (amount != 0) {
				workFile << fixed << setprecision(2) <<amount; 
			} else {
				workFile << "00.00"; 
			}
			workFile << " " <<"RON\n"; 
			if (workFile.good()) {
				workFile.close();
			 	Success_C :: SetSuccess(FILE_CREATED_SUCC);
				Success_C :: PrintSuccess(fileName, operation, amount);
			}
		}
	}
}

void Wallet :: addIncome(const std :: string &wallet, const char operation, 
				const float amount) 
{
	string fileName = wallet;
	if (fileExists (fileName.c_str())) {
		ofstream workFile;
		//output.open( filename.c_str(), ios::out | ios::app );
		WalletEntry walletEntry;
		workFile.open(fileName.c_str(), ios::app);
		workFile << walletEntry.getTimestamp () << ";" << operation << ";";
		if (amount != 0) {
			workFile << fixed << setprecision(2) << amount << ";"; 
		} else {
			workFile << "00.00" << ";";
		}
		workFile <<"RON \n"; 
		workFile.close();
	} else {
		//cout<<"Error the wallet file does not exist : "<<endl;
		Error_C :: SetError(OPEN_FILE_ERR);
	}
}

bool Wallet :: fileExists (const std :: string &fileName) 
{
	ifstream f(fileName.c_str());
    if (f.good()) {
        f.close();
        return true;
    }
    f.close();
    return false;
}


/* std :: string Wallet :: SplitFilename (const std :: string &str)
{
	size_t found = str.find_last_of("\\/");
	string result = str.substr(found+1);
	size_t found = str.rfind(".txt");
	cout<<str.c_str()<<endl;
	string result = str.substr(0, found);
	return  str;
}  */

