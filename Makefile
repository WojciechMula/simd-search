.SUFFIXES:

CC=g++
FLAGS=-std=c++11 -Wall -Wextra -pedantic -O3

all: demo

demo: demo.cpp sse-binsearch.o binsearch.o
	$(CC) $(FLAGS) demo.cpp sse-binsearch.o binsearch.o -o demo

sse-binsearch.o: sse-binsearch.cpp sse-binsearch.h common.h binsearch.h
	$(CC) $(FLAGS) -c sse-binsearch.cpp -o sse-binsearch.o

binsearch.o: binsearch.cpp binsearch.h common.h
	$(CC) $(FLAGS) -c binsearch.cpp -o binsearch.o

clean:
	rm -f demo *.o
