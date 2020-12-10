.DEFAULT_GOAL := all

CPPFLAGS = -Wall -c
CXX = g++
INCLUDES = -Ilib

all: lexer

lexer: lexer.o

.cpp.o:
	$(CXX) $(CPPFLAGS) $(INCLUDES) $^

clean:
	rm -f *.o
