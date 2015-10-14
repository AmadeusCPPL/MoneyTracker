#include <iostream>
#include <cstring>
#include <ctime>
#include "WalletEntry.h"

using namespace std;

WalletEntry :: WalletEntry () 
{
	time_t now = time (0);
	timestamp_ = now;
}
long int WalletEntry :: getTimestamp () 
{
	return timestamp_;
}
