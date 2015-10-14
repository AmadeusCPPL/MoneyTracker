#ifndef WALLETENTRY_H
#define WALLETENTRY_H

class WalletEntry
{
	private:
		long int timestamp_;
		char operation_;
		float amount_;
		std :: string amountType_;
		std :: string currencyType_;
		
	public:
		WalletEntry ();
		long int getTimestamp ();
		
};

#endif
