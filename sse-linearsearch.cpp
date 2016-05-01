#include <cstdio>
#include <smmintrin.h>
#include "sse-linearsearch.h"


int SSELinearSearch::search(uint32_t key) const {

    const __m128i keys = _mm_set1_epi32(key);

    const auto n = data.size();
    const auto rounded = 8 * (n/8);

    for (size_t i=0; i < rounded; i += 8) {

        const __m128i vec1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&data[i]));
        const __m128i vec2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&data[i + 4]));

        const __m128i cmp1 = _mm_cmpeq_epi32(vec1, keys);
        const __m128i cmp2 = _mm_cmpeq_epi32(vec2, keys);

        const __m128i tmp  = _mm_packs_epi32(cmp1, cmp2);
        const uint32_t mask = _mm_movemask_epi8(tmp);

        if (mask != 0) {
            return i + __builtin_ctz(mask)/2;
        }
    }

    for (size_t i = rounded; i < n; i++) {
        if (data[i] == key) {
            return i;
        }
    }

    return -1;
}

