#include <cstdio>
#include <smmintrin.h>
#include "sse-binsearch.h"

void SSEBinSearch::prepare() {
    const auto a  = 0;
    const auto b  = data.size() - 1;

    const auto i0 = a + 1*(b - a)/5;
    const auto i1 = a + 2*(b - a)/5;
    const auto i2 = a + 3*(b - a)/5;
    const auto i3 = a + 4*(b - a)/5;

    bounds[0] = data[i0];
    bounds[1] = data[i1];
    bounds[2] = data[i2];
    bounds[3] = data[i3];

    for (int i=0; i < 16; i++) {
        indices[i].a = a;
        indices[i].b = b;
    }

    indices[0x00].a = a;
    indices[0x00].b = i0;

    indices[0x01].a = i0;
    indices[0x01].b = i1;

    indices[0x03].a = i1;
    indices[0x03].b = i2;

    indices[0x07].a = i2;
    indices[0x07].b = i3;

    indices[0x0f].a = i3;
    indices[0x0f].b = b;
}


int SSEBinSearch::search(uint32_t key) const {

    const __m128i vecbnd = _mm_loadu_si128(reinterpret_cast<const __m128i*>(bounds));
    const __m128i keys   = _mm_set1_epi32(key);
    const __m128i cmp    = _mm_cmpgt_epi32(keys, vecbnd);

    const auto mask = _mm_movemask_ps((__m128)(cmp));

    return binsearch(key, indices[mask].a, indices[mask].b);
}

