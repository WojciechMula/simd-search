#ifndef SSE_LINEARSEARCH_H
#define SSE_LINEARSEARCH_H

#include "binsearch.h"


class SSELinearSearch: public BinSearch {
public:
    SSELinearSearch(const uint32vector_t& data)
        : BinSearch(data) {
    }

    int search(uint32_t key) const;
};


#endif

