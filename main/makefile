CPP = g++
COMP = g++ -Wall
CPPFLAGS = -Wall

AR = ar crf


HEADERS = \
	..\interpreter\inc\Interpreter.h\
	..\wallet\inc\Wallet.h\
	..\config\inc\Errors.h

moneytracker.a: moneytracker.o
	$(AR) moneytracker.a moneytracker.o

moneytracker.o: src\MoneyTracker.cpp $(HEADERS)
	$(CPP) -I..\wallet\inc -I..\config\inc -I..\interpreter\inc -c src\MoneyTracker.cpp

clean:
	rm moneytracker.o
	rm moneytracker.a