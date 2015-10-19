#include <fstream>
#include <string>
#include <stdio.h>
#include <windows.h>
#include "gtest/gtest.h"
#include "ConfigData.h"
#include "Errors.h"

using namespace std;


TEST(ConfigDataRead, ValidtstConfig1)
{
	ConfigData config;
	string fileName = "config\\tstConfig1.config";
	string existDefault = config.readFromFile("default_wallet", fileName);
	ASSERT_EQ(existDefault, "my.wallet");
}

TEST(ConfigDataRead, ValidtstConfig2)
{
	ConfigData config;
	string fileName = "config\\tstConfig2.config";
	string existDefault = config.readFromFile("default_wallet", fileName);
	ASSERT_EQ(existDefault, "my.wallet");
}

TEST(ConfigDataRead, ValidtstConfig4)
{
	ConfigData config;
	string existDefault = config.readFromFile("default_wallet", "config\\tstConfig4.config");
	ASSERT_EQ(existDefault, "my.wallet");
}

TEST(ConfigDataRead, InvalidtstConfig3)
{
	ConfigData config;
	string existDefault = config.readFromFile("default_wallet", "config\\tstConfig3.config");
	ASSERT_EQ(DEFAULT_WALL_CONFIG_ERR, Error_C::GetError());
}

TEST(ConfigDataRead, InvalidtstConfig5)
{
	ConfigData config;
	string existDefault = config.readFromFile("default_wallet", "config\\tstConfig5.config");
	ASSERT_EQ(DEFAULT_WALL_CONFIG_ERR, Error_C::GetError());
}

TEST(ConfigDataRead, InvalidtstConfig6)
{
	ConfigData config;
	string existDefault = config.readFromFile("default_wallet", "config\\tstConfig6.config");
	ASSERT_EQ(DEFAULT_WALL_CONFIG_ERR, Error_C::GetError());
}

TEST(ConfigDataRead, ConfigNotFound)
{
	ConfigData config;
	string existDefault = config.readFromFile("default_wallet", "config\\tstNotExist.config");
	ASSERT_EQ(OPEN_CONFIG_ERR, Error_C::GetError());
}

TEST(GetWallet, GetFileName)
{
	ConfigData config;
	string existDefault = config.getWallet();
	ASSERT_EQ(existDefault, "my.wallet");
}