#include <cstdio>
#include <cstring>
#include <sys/time.h>

#include "binsearch.h"
#include "sse-binsearch.h"


uint32_t get_time(void) {
    static struct timeval T;
    gettimeofday(&T, NULL);
    return (T.tv_sec * 1000000) + T.tv_usec;
}


template <typename T>
void measure(const uint32vector_t& data) {

    T b(data);

    const auto n = data.size();

    const auto t1 = get_time();
    for (auto j=0; j < 1; j++)
    for (auto i=0; i < n; i++) {
        b.search(i);
    }
    const auto t2 = get_time();

    std::printf("time %.4f\n", (t2-t1)/10000000.0);
}


int main(int argc, char* argv[]) {
    uint32vector_t data;
    const auto n = 10000000;
    data.resize(n);
    
    for (auto i=0; i < n; i++) {
        data[i] = i * 0.5;
    }

    if (argc > 1 && std::strcmp(argv[1], "sse") == 0) {
        measure<SSEBinSearch>(data);
    } else if (argc > 1 && std::strcmp(argv[1], "bin") == 0) {
        measure<BinSearch>(data);
    }
}
