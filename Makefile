.SUFFIXES:

FLAGS=-std=c++11 -Wall -Wextra -pedantic -O3

OBJS=binsearch.o linearsearch.o binsearch-linear.o sse-binsearch.o sse-linearsearch.o sse-binsearch-block.o
all: demo verify

demo: demo.cpp $(OBJS)
	$(CXX) $(FLAGS) demo.cpp $(OBJS) -o $@

verify: verify.cpp $(OBJS)
	$(CXX) $(FLAGS) verify.cpp $(OBJS) -o $@

binsearch.o: binsearch.cpp binsearch.h search_base.h
	$(CXX) $(FLAGS) -c binsearch.cpp -o $@

linearsearch.o: linearsearch.cpp linearsearch.h search_base.h
	$(CXX) $(FLAGS) -c linearsearch.cpp -o $@

binsearch-linear.o: binsearch-linear.cpp binsearch-linear.h search_base.h
	$(CXX) $(FLAGS) -c binsearch-linear.cpp -o $@

sse-binsearch.o: sse-binsearch.cpp sse-binsearch.h search_base.h
	$(CXX) $(FLAGS) -c sse-binsearch.cpp -o $@

sse-binsearch-block.o: sse-binsearch-block.cpp sse-binsearch-block.h search_base.h
	$(CXX) $(FLAGS) -c sse-binsearch-block.cpp -o $@

sse-linearsearch.o: sse-linearsearch.cpp sse-linearsearch.h search_base.h
	$(CXX) $(FLAGS) -c sse-linearsearch.cpp -o $@

clean:
	rm -f demo verify $(OBJS)
