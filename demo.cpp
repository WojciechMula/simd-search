#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <sys/time.h>

#include "binsearch.h"
#include "linearsearch.h"
#include "binsearch-linear.h"
#include "sse-binsearch.h"
#include "sse-binsearch-block.h"
#include "sse-linearsearch.h"


uint32_t get_time(void) {
    static struct timeval T;
    gettimeofday(&T, NULL);
    return (T.tv_sec * 1000000) + T.tv_usec;
}

volatile int result;


template <typename T>
double measure(const uint32vector_t& data, uint32_t iteration_count) {

    T b(data);

    const auto n = data.size();

    int k = 0;

    const auto t1 = get_time();
    for (auto j=0u; j < iteration_count; j++) {
        for (auto i=0u; i < n; i++) {
            k += b.search(i);
        }
    }
    const auto t2 = get_time();

    result = k;

    return (t2 - t1) / 1000000.0;
}


template <typename T>
void run(const uint32vector_t& data, uint32_t iteration_count) {

    const double dt = measure<T>(data, iteration_count);
    
    printf("\t%10.6f", dt);
    fflush(stdout);
}


void print_help(const char* prog);


int main(int argc, char* argv[]) {
    uint32vector_t data;

    if (argc != 3) {
        print_help(argv[0]);
        return EXIT_FAILURE;
    }

    const long size = strtol(argv[1], nullptr, 10);
    const long iteration_count = strtol(argv[2], nullptr, 10);
    
    if (size <= 0) {
        puts("size must be greater than 0");
        return EXIT_FAILURE;
    }
    
    if (iteration_count <= 0) {
        puts("iteration_count must be greater than 0");
        return EXIT_FAILURE;
    }

    data.resize(size);
    
    for (auto i=0; i < size; i++) {
        data[i] = i;
    }

    printf("%ld", size);
    fflush(stdout);
 
    run<BinSearch>(data, iteration_count);
    run<BinSearchLinear>(data, iteration_count);
    run<SSEBinSearch>(data, iteration_count);
    run<SSEBinSearchBlock>(data, iteration_count);
    run<LinearSearch>(data, iteration_count);
    run<SSELinearSearch>(data, iteration_count);

    putchar('\n');

    return EXIT_SUCCESS;
}


void print_help(const char* prog) {
    printf("%s size iteration_count\n", prog);
}
