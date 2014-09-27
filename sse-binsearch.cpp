#include <cstdio>
#include "sse-binsearch.h"

void SSEBinSearch::prepare() {
    const auto a  = 0;
    const auto b  = data.size() - 1;

    const auto i0 = a + 1*(b - a)/5;
    const auto i1 = a + 2*(b - a)/5;
    const auto i2 = a + 3*(b - a)/5;
    const auto i3 = a + 4*(b - a)/5;

    keys[0] = data[i0];
    keys[1] = data[i1];
    keys[2] = data[i2];
    keys[3] = data[i3];

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

    uint32_t mask;

    __asm__ __volatile__(
        "movdqa     %2,     %%xmm0          \n"
        "movd       %1,     %%xmm1          \n"
        "pshufd     $0,     %%xmm1, %%xmm1  \n"
        "pcmpgtd    %%xmm0, %%xmm1          \n"
        "movmskps   %%xmm1, %0              \n"
        : "=r" (mask)
        : "r" (key),
          "m" (keys)
    );

    //return BinSearch::search(key);
    return binsearch(key, indices[mask].a, indices[mask].b);
}

