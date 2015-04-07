#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <sys/time.h>

#include "binsearch.h"
#include "linearsearch.h"
#include "sse-binsearch.h"
#include "sse-linearsearch.h"


uint32_t get_time(void) {
    static struct timeval T;
    gettimeofday(&T, NULL);
    return (T.tv_sec * 1000000) + T.tv_usec;
}

volatile int result;


template <typename T>
double measure(const uint32vector_t& data, uint32_t count) {

    T b(data);

    const auto n = data.size();

    int k = 0;

    const auto t1 = get_time();
    for (auto j=0u; j < count; j++) {
        for (auto i=0u; i < n; i++) {
            k += b.search(i);
        }
    }
    const auto t2 = get_time();

    result = k;

    return (t2 - t1) / 1000000.0;
}


template <typename T>
void run(const uint32vector_t& data, uint32_t count) {

    const double dt = measure<T>(data, count);
    
    printf("\t%10.6f", dt);
}


int main(int argc, char* argv[]) {
    uint32vector_t data;
    const auto n = strtol(argv[1], nullptr, 10);
    const auto count = strtol(argv[2], nullptr, 10);
    data.resize(n);
    
    for (auto i=0; i < n; i++) {
        data[i] = i * 0.5;
    }

    printf("%ld", n);
    fflush(stdout);
 
    run<BinSearch>(data, count);
    run<LinearSearch>(data, count);
    run<SSEBinSearch>(data, count);
    run<SSELinearSearch>(data, count);

    putchar('\n');

    return EXIT_SUCCESS;
}
