COMP = g++ -Wall

LINK = g++ -o

HEADERS = \
	-Iinterpreter\inc\
	-Iwallet\inc\
	-Iconfig\inc

GTEST_DIR=C:\gtest-1.7.0\gtest-1.7.0

GTEST_LIB=$(GTEST_DIR)\make\gtest_main.a

GTEST_INC=-isystem $(GTEST_DIR)\include

TESTS=\
	config\tst\TestErrors.o\
	interpreter\tst\TestInterpreter.o\
	wallet\tst\TestWallet.o
	
OBJECTS = \
	config\src\Errors.o\
	wallet\src\Wallet.o\
	interpreter\src\Interpreter.o\
	wallet\src\WalletEntry.o
	
moneytracker: moneytracker.exe test.exe

moneytracker.exe: wallet\src\WalletEntry.o main\src\MoneyTracker.o wallet\src\Wallet.o interpreter\src\Interpreter.o config\src\Errors.o
	$(LINK) moneytracker.exe config\src\Errors.o wallet\src\WalletEntry.o wallet\src\Wallet.o interpreter\src\Interpreter.o main\src\MoneyTracker.o

main\src\MoneyTracker.o: main\src\MoneyTracker.cpp interpreter\src\Interpreter.cpp interpreter\inc\Interpreter.h
	$(COMP) $(HEADERS) -o main\src\MoneyTracker.o -c main\src\MoneyTracker.cpp

interpreter\src\Interpreter.o: interpreter\src\Interpreter.cpp interpreter\inc\interpreter.h interpreter\inc\ListOfCommands.h config\inc\Errors.h
	$(COMP)	$(HEADERS) -o interpreter\src\Interpreter.o -c interpreter\src\Interpreter.cpp

wallet\src\Wallet.o: wallet\src\Wallet.cpp wallet\src\WalletEntry.cpp wallet\inc\Wallet.h wallet\inc\WalletEntry.h config\inc\Errors.h
	$(COMP) $(HEADERS) -o wallet\src\Wallet.o -c wallet\src\Wallet.cpp 

wallet\src\WalletEntry.o: wallet\src\WalletEntry.cpp wallet\inc\WalletEntry.h
	$(COMP) $(HEADERS) -o wallet\src\WalletEntry.o -c wallet\src\WalletEntry.cpp
	
config\src\Errors.o: config\src\Errors.cpp config\inc\ErrorTypes.h config\inc\Errors.h
	$(COMP) -Iconfig\inc -o config\src\Errors.o -c config\src\Errors.cpp

	
#make tests

test.exe: $(OBJECTS) $(TESTS) $(GTEST_LIB)
	 $(LINK) test.exe $(TESTS) $(OBJECTS) $(GTEST_LIB)
	
interpreter\tst\TestInterpreter.o:interpreter\tst\TestInterpreter.cpp
	$(COMP) $(GTEST_INC) $(HEADERS) -o interpreter\tst\TestInterpreter.o -c interpreter\tst\TestInterpreter.cpp
	
config\tst\TestErrors.o:config\tst\TestErrors.cpp
	$(COMP) $(CPPFLAGS) $(HEADERS) $(GTEST_INC) -o config\tst\TestErrors.o -c config\tst\TestErrors.cpp
	
wallet\tst\TestWallet.o:wallet\tst\TestWallet.cpp
	$(COMP) $(CPPFLAGS) $(HEADERS) $(GTEST_INC) -o wallet\tst\TestWallet.o -c wallet\tst\TestWallet.cpp


clean:
	rm config\tst\TestErrors.o
	rm wallet\tst\TestWallet.o
	rm interpreter\tst\TestInterpreter.o 
	rm config\src\Errors.o
	rm wallet\src\WalletEntry.o
	rm wallet\src\Wallet.o
	rm interpreter\src\Interpreter.o
	rm main\src\MoneyTracker.o
	rm *.exe
