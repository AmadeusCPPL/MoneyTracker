COMPILE = g++
CFLAGS = -Wall -c -I..\inc -I..\..\config\inc

all: main

main : WalletEntry.o Wallet.o ..\..\config\inc\Errors.o main.o 
	$(COMPILE) -o main.exe main.o WalletEntry.o Wallet.o ..\..\config\inc\Errors.o
	main.exe
	
main.o : main.cpp ..\inc\WalletEntry.h ..\inc\Wallet.h ..\..\config\inc\Errors.h ..\..\config\inc\ErrorTypes.h
	$(COMPILE) $(CFLAGS) main.cpp 
	
WalletEntry.o : ..\inc\WalletEntry.h WalletEntry.cpp
	$(COMPILE) $(CFLAGS) WalletEntry.cpp 

Wallet.o : ..\inc\Wallet.h Wallet.cpp ..\..\config\inc\Errors.h ..\..\config\inc\ErrorTypes.h
	$(COMPILE) $(CFLAGS) Wallet.cpp 
	
Errors.o : ..\..\config\inc\Errors.cpp ..\..\config\inc\Errors.h ..\..\config\inc\ErrorTypes.h
	$(COMPILE) $(CFLAGS) C:\learn\Project\MoneyTracker\config\inc\Errors.cpp
		
clean: 
	del *.o
	del *.exe

