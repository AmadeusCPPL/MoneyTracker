CPP = g++
COMP = g++ -Wall
CPPFLAGS = -Wall

GTEST_DIR=C:\gtest-1.7.0\gtest-1.7.0
GTEST_LIB=$(GTEST_DIR)\make\gtest_main.a
GTEST_INC=-isystem $(GTEST_DIR)\include

AR = ar crf

HEADERS =\
	inc\ConfigData.h\
	inc\Utils.h\
	..\errors\inc\Errors.h\
	
ConfigData.a: src\ConfigData.o 
	$(AR) ConfigData.a src\ConfigData.o 
	
src\ConfigData.o: src\ConfigData.cpp $(HEADERS)
	$(COMP)	-Iinc -I..\errors\inc -o src\ConfigData.o -c src\ConfigData.cpp
		
TestConfigData.exe: tst\TestConfigData.o src\ConfigData.o $(GTEST_LIB)
	$(CPP) -o tst\TestConfigData.exe tst\TestConfigData.o src\ConfigData.o ..\errors\src\Errors.o $(GTEST_LIB)

tst\TestConfigData.o: $(HEADERS) tst\TestConfigData.cpp
	$(CPP) $(CPPFLAGS) $(GTEST_INC) -Iinc -o tst\TestConfigData.o -c tst\TestConfigData.cpp 
	
clean:
	rm src\ConfigData.o
	rm ConfigData.a
	rm tst\TestConfigData.o
	rm tst\TestConfigData.exe