CPP = g++
COMP = g++ -Wall
CPPFLAGS = -Wall

AR = ar crf

GTEST_DIR=C:\gtest-1.7.0\gtest-1.7.0
GTEST_LIB=$(GTEST_DIR)\make\gtest_main.a
GTEST_INC=-isystem $(GTEST_DIR)\include

HEADERS =\
	inc\Interpreter.h\
	inc\ListOfCommands.h\
	..\wallet\inc\Wallet.h\
	..\wallet\inc\WalletEntry.h\
	..\config\inc\Errors.h
	
HEADERS2 = \
	-Iinc\
	-I..\wallet\inc\
	-I..\config\inc
	
Interpreter.a: src\Interpreter.o
	$(AR) Interpreter.a src\Interpreter.o
	
TestInterpreter.exe: tst\TestInterpreter.o src\Interpreter.o $(GTEST_LIB)
	$(CPP) -o tst\TestInterpreter.exe tst\TestInterpreter.o src\Interpreter.o ..\config\src\Errors.o ..\wallet\src\Wallet.o ..\wallet\src\WalletEntry.o $(GTEST_LIB)
	
src\Interpreter.o: src\Interpreter.cpp $(HEADERS)
	$(COMP)	-Iinc -I..\wallet\inc -I..\config\inc -o src\Interpreter.o -c src\Interpreter.cpp

tst\TestInterpreter.o:tst\TestInterpreter.cpp $(HEADERS)
	$(COMP) $(GTEST_INC) $(HEADERS2) -o tst\TestInterpreter.o -c tst\TestInterpreter.cpp
	
clean:
	rm src\Interpreter.o
	rm Interpreter.a
	rm tst\TestInterpreter.exe
	rm tst\TestInterpreter.o
