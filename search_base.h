#ifndef SEARCH_BASE_H
#define SEARCH_BASE_H

#include <cstdint>
#include <vector>

typedef std::vector<std::uint32_t> uint32vector_t;

class SearchBase {
protected:
    const uint32vector_t& data;

    SearchBase(const uint32vector_t& data) : data(data) {}
};

#endif // SEARCH_BASE_H
