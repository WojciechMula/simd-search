#ifndef SSE_BINSEARCH_H
#define SSE_BINSEARCH_H

#include "binsearch.h"


class SSEBinSearch: public BinSearch {
#define SIMD_ALIGN __attribute__((aligned(16)))
    uint32_t bounds[4] SIMD_ALIGN;
#undef SIMD_ALIGN

    struct pair_t {
        uint32_t a;
        uint32_t b;
    };

    pair_t indices[16];
public:
    SSEBinSearch(const uint32vector_t& data)
        : BinSearch(data) {

        prepare();
    }

    int search(uint32_t key) const;

private:
    void prepare();
};


#endif
