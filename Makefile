makefile:
.DEFAULT_GOAL := all
CC=g++
DEBUG_FLAGS=-g
COMPILE_FLAGS=-I ./src -std=c++11

all: clean alltests

clean:
	rm -rf *.o testssll

alltests: testssll
	./testssll

alltestv: testssll
	./testssll -s

testssll: test_main.o test_SSLL.o
	$(CC) $(DEBUG_FLAGS) -o testssll test_main.o test_SSLL.o

test_SSLL.o: test/test_SSLL.cpp
	$(CC) -c $(DEBUG_FLAGS) $(COMPILE_FLAGS) test/test_SSLL.cpp

test_main.o: test/test_main.cpp
	$(CC) -c $(DEBUG_FLAGS) $(COMPILE_FLAGS) test/test_main.cpp