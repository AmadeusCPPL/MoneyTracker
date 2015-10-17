CPP = g++
COMP = g++ -Wall
CPPFLAGS = -Wall

GTEST_DIR=C:\gtest-1.7.0\gtest-1.7.0

GTEST_LIB=$(GTEST_DIR)\make\gtest_main.a

GTEST_INC=-isystem $(GTEST_DIR)\include

app:
	$(MAKE) -C main 
	$(MAKE) -C errors
	$(MAKE) -C interpreter
	$(MAKE) -C wallet
	$(MAKE) -C config
	$(MAKE) moneytracker.exe

test:
	$(MAKE) -C errors TestErrors.exe
	errors\tst\TestErrors.exe
	$(MAKE) -C interpreter TestInterpreter.exe
	interpreter\tst\TestInterpreter.exe
	$(MAKE) -C wallet TestWallet.exe
	wallet\tst\TestWallet.exe
	$(MAKE) -C config TestConfigData.exe
	config\tst\TestConfigData.exe

	
moneytracker.exe: main\moneytracker.a interpreter\Interpreter.a wallet\Wallet.a errors\Errors.a config\ConfigData.a
	$(CPP) -o moneytracker.exe main\moneytracker.a interpreter\Interpreter.a wallet\Wallet.a errors\Errors.a config\ConfigData.a
	
clean:
	$(MAKE) -C main clean
	$(MAKE) -C errors clean
	$(MAKE) -C interpreter clean
	$(MAKE) -C wallet clean
	$(MAKE) -C config clean
	$(RM) moneytracker.exe

