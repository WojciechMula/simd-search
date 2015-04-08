.SUFFIXES:

CC=g++
FLAGS=-std=c++11 -Wall -Wextra -pedantic -O3

OBJS=binsearch.o linearsearch.o sse-binsearch.o sse-linearsearch.o
all: demo

demo: demo.cpp $(OBJS)
	$(CC) $(FLAGS) demo.cpp $(OBJS) -o demo

binsearch.o: binsearch.cpp binsearch.h search_base.h
	$(CC) $(FLAGS) -c binsearch.cpp -o binsearch.o

linearsearch.o: linearsearch.cpp linearsearch.h search_base.h
	$(CC) $(FLAGS) -c linearsearch.cpp -o linearsearch.o

sse-binsearch.o: sse-binsearch.cpp sse-binsearch.h search_base.h
	$(CC) $(FLAGS) -c sse-binsearch.cpp -o sse-binsearch.o

sse-linearsearch.o: sse-linearsearch.cpp sse-linearsearch.h search_base.h
	$(CC) $(FLAGS) -c sse-linearsearch.cpp -o sse-linearsearch.o

clean:
	rm -f demo $(OBJS)
