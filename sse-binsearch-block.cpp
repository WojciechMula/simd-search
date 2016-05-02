#include <cstdio>
#include <smmintrin.h>
#include "sse-binsearch-block.h"


int SSEBinSearchBlock::search(uint32_t key) const {

    const __m128i keys = _mm_set1_epi32(key);
    __m128i v;

    int limit = data.size() - 1;
    int a = 0;
    int b = limit;

    while (a <= b) {
        const int c = (a + b)/2;

        if (data[c] == key) {
            return c;
        }

        if (key < data[c]) {
            b = c - 1;

            if (b >= 4) {
                v = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&data[b - 4]));
                v = _mm_cmpeq_epi32(v, keys);
                const uint16_t mask = _mm_movemask_epi8(v);
                if (mask) {
                    return b - 4 + __builtin_ctz(mask)/4;
                }
            }
        } else {
            a = c + 1;

            if (a + 4 < limit) {
                v = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&data[a]));
                v = _mm_cmpeq_epi32(v, keys);
                const uint16_t mask = _mm_movemask_epi8(v);
                if (mask) {
                    return a + __builtin_ctz(mask)/4;
                }
            }
        }
    }

    return -1;
}

