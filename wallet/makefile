CPP = g++
COMP = g++ -Wall
CPPFLAGS = -Wall

GTEST_DIR=C:\gtest-1.7.0\gtest-1.7.0
GTEST_LIB=$(GTEST_DIR)\make\gtest_main.a
GTEST_INC=-isystem $(GTEST_DIR)\include

AR = ar crf

HEADERS =\
	inc\Wallet.h\
	inc\WalletEntry.h\
	..\errors\inc\Errors.h\
	..\interpreter\inc\Interpreter.h\
	..\config\inc\ConfigData.h\
	..\config\inc\Utils.h
	
Wallet.a: src\Wallet.o src\WalletEntry.o 
	$(AR) Wallet.a src\Wallet.o src\WalletEntry.o
	
src\Wallet.o: src\Wallet.cpp $(HEADERS)
	$(COMP)	-Iinc -I..\errors\inc -I..\config\inc -o src\Wallet.o -c src\Wallet.cpp

src\WalletEntry.o: src\WalletEntry.cpp $(HEADERS)
	$(COMP) -Iinc -o src\WalletEntry.o -c src\WalletEntry.cpp
	
	
TestWallet.exe: tst\TestWallet.o src\Wallet.o $(GTEST_LIB)
	$(CPP) -o tst\TestWallet.exe tst\TestWallet.o src\Wallet.o ..\errors\src\Errors.o ..\config\src\ConfigData.o ..\wallet\src\WalletEntry.o $(GTEST_LIB)

tst\TestWallet.o: $(HEADERS) tst\TestWallet.cpp
	$(CPP) $(CPPFLAGS) $(GTEST_INC) -Iinc -I..\config\inc -o tst\TestWallet.o -c tst\TestWallet.cpp 
	
clean:
	rm src\Wallet.o
	rm src\WalletEntry.o
	rm Wallet.a
	rm tst\TestWallet.o
	rm tst\TestWallet.exe