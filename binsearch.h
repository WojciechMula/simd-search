#ifndef BINSEARCH_H
#define BINSEARCH_H

#include "common.h"


class BinSearch {
protected:
    const uint32vector_t& data;

public:
    BinSearch(const uint32vector_t& data) : data(data) {}

    int search(uint32_t key) const {
        return binsearch(key, 0, data.size() - 1);
    }

protected:
    int binsearch(uint32_t key, int a, int b) const;
};


#endif
