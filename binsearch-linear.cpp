#include "binsearch-linear.h"
#include <cstdio>


int BinSearchLinear::binsearch(uint32_t key, int a, int b) const {

    const size_t cache_line_size = 64; // in bytes
    const size_t key_size        = sizeof(uint32_t);

    while (b - a > int(cache_line_size/key_size)) {
        const int c = (a + b)/2;

        if (data[c] == key) {
            return c;
        }

        if (key < data[c]) {
            b = c - 1;
        } else {
            a = c + 1;
        }
    }

    for (int i=a; i <= b; i++) {
        if (data[i] == key) {
            return i;
        }
    }

    return -1;
}
