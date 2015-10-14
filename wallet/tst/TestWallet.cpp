#include <fstream>
#include <string>
#include "gtest/gtest.h"
#include "Wallet.h"

using namespace std;
//helper function
//reads from the file created and returns the content

std :: string readWallet(const std::string walletName)
{
	
	ifstream wallet(walletName.c_str());
	
	string walletContent;
	
	//read from the given file
	getline(wallet,walletContent);
	
	return walletContent;
}


void cleanUp (std :: string walletName) {
	Wallet wallet;
	if (wallet.fileExists(walletName.c_str())) {
		remove(walletName.c_str());
	}
}

TEST(CreateWalletTest, TestCreateWallet)
{
	//ARRANGE
	Wallet wallet;
	wallet.createNewWalletFile("my.wallet", '+', 1000);
	wallet.createNewWalletFile("other.wallet" , '+', 200);
	wallet.createNewWalletFile("yetother" , '-', 1021.23);
	wallet.createNewWalletFile("noinitial.wallet", '+', 00.00);
	wallet.createNewWalletFile("leading0.wallet" , '-', 00012.24);
	//ASSERT
	EXPECT_EQ("+1000.00 RON", readWallet("my.wallet"));
	EXPECT_EQ("+200.00 RON", readWallet("other.wallet"));
	EXPECT_EQ("-1021.23 RON", readWallet("yetother"));
	EXPECT_EQ("+00.00 RON", readWallet("noinitial.wallet"));
	EXPECT_EQ("-12.24 RON", readWallet("leading0.wallet"));
	//CLEANUP
	cleanUp("my.wallet");
	cleanUp("other.wallet");
	cleanUp("yetother");
	cleanUp("noinitial.wallet");
	cleanUp("leading0.wallet");
}

TEST(CreateWalletTest, TestCreateExistingWallet)
{
	//ARRANGE
	Wallet wallet;
	std :: string filename = "yetother";
	wallet.createNewWalletFile(filename, '+', 00.00);
	wallet.createNewWalletFile(filename, '+', 30.00);
	//ASSERT
	EXPECT_EQ("+00.00 RON", readWallet(filename));
	//CLEANUP
	cleanUp(filename);
} 
TEST(CreateWalletTest, TestCreateWithPath)
{
	//ARRANGE
	Wallet wallet;
	std :: string filename = "wallet\\tst\\file";
	wallet.createNewWalletFile(filename, '+', 00.00);
	//ASSERT
	EXPECT_EQ(1 , wallet.fileExists(filename));
	//CLEANUP
	cleanUp(filename);
}
