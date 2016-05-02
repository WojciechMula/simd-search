#ifndef BINSEARCH_LINEAR_H
#define BINSEARCH_LINEAR_H

#include "search_base.h"


class BinSearchLinear: public SearchBase {
public:
    BinSearchLinear(const uint32vector_t& data) : SearchBase(data) {}

    int search(uint32_t key) const {
        return binsearch(key, 0, data.size() - 1);
    }

protected:
    int binsearch(uint32_t key, int a, int b) const;
};


#endif
