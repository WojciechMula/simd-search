#include "binsearch-linear.h"
#include <cstdio>


int BinSearchLinear::binsearch(uint32_t key, int a, int b) const {
    while (b - a > 64/4) {
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
