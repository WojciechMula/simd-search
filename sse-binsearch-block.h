#ifndef SSE_BINSEARCH_BLOCK_H
#define SSE_BINSEARCH_BLOCK_H

#include "search_base.h"


class SSEBinSearchBlock: public SearchBase {
public:
    SSEBinSearchBlock(const uint32vector_t& data)
        : SearchBase(data) {}

    int search(uint32_t key) const;
};


#endif
