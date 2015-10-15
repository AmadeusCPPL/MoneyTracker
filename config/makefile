CPP = g++
AR = ar crf
CPPFLAGS = -Wall

GTEST_DIR=C:\gtest-1.7.0\gtest-1.7.0
GTEST_LIB=$(GTEST_DIR)\make\gtest_main.a
GTEST_INC=-isystem $(GTEST_DIR)\include

HEADERS =\
	inc\Errors.h\
	inc\ErrorTypes.h
	
Errors.a: src\Errors.o
	$(AR) Errors.a src\Errors.o
	
TestErrors.exe: tst\TestErrors.o src\Errors.o $(GTEST_LIB)
	$(CPP) -o tst\TestErrors.exe tst\TestErrors.o src\Errors.o $(GTEST_LIB)
		
src\Errors.o: src\Errors.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) -Iinc -o src\Errors.o -c src\Errors.cpp
	
tst\TestErrors.o: $(HEADERS) tst\TestErrors.cpp
	$(CPP) $(CPPFLAGS) $(GTEST_INC) -Iinc -o tst\TestErrors.o -c tst\TestErrors.cpp 
	
	
clean:
	rm src\Errors.o
	rm Errors.a
	rm tst\TestErrors.o
	rm tst\TestErrors.exe