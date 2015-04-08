#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include "search_base.h"

class LinearSearch: public SearchBase {

public:
    LinearSearch(const uint32vector_t& data) : SearchBase(data) {}

    int search(uint32_t key) const {

        const unsigned n = data.size();

        for (unsigned i=0; i < n; i++) {
            if (key == data[i]) {
                return i;
            }
        }

        return -1;
    }
};

#endif
