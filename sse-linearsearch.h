#ifndef SSE_LINEARSEARCH_H
#define SSE_LINEARSEARCH_H

#include "search_base.h"


class SSELinearSearch: public SearchBase {
public:
    SSELinearSearch(const uint32vector_t& data) : SearchBase(data) {}

    int search(uint32_t key) const;
};


#endif

