#include "binsearch.h"


int BinSearch::binsearch(uint32_t key, int a, int b) const {
    while (a <= b) {
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

    return -1;
}
