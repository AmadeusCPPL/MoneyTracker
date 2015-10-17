#include <fstream>
#include <string>
#include <stdio.h>
#include <windows.h>
#include "gtest/gtest.h"
#include "ConfigData.h"

using namespace std;
//helper function
//reads from the file created and returns the content

std :: string readFile(const std::string fileName)
{
	
	ifstream file(fileName.c_str());
	
	string fileContent;
	
	//read from the given file
	getline(file,fileContent);
	
	return fileContent;
}

//helper function
//removes a file created for testing purpose

/* void cleanUp (std :: string walletName) {
	if (fileExists(walletName.c_str())) {
		remove(walletName.c_str());
	}
} */

TEST(ConfigDataTest, TestMain)
{
	//ARRANGE
	cout<<endl<<endl;
	
	
	ConfigData configData;
	string file = configData.getWallet();
	cout<<"fisierul config este : "<<file<<endl;
	
	cout<<endl<<endl;
	//ASSERT
	
	//EXPECT_EQ("-12.24 RON", readWallet("leading0.wallet"));
	//CLEANUP
}
