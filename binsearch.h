#ifndef BINSEARCH_H
#define BINSEARCH_H

#include "search_base.h"


class BinSearch: public SearchBase {
public:
    BinSearch(const uint32vector_t& data) : SearchBase(data) {}

    int search(uint32_t key) const {
        return binsearch(key, 0, data.size() - 1);
    }

protected:
    int binsearch(uint32_t key, int a, int b) const;
};


#endif
