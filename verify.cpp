#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <sys/time.h>

#include "binsearch.h"
#include "linearsearch.h"
#include "binsearch-linear.h"
#include "sse-binsearch.h"
#include "sse-binsearch-block.h"
#include "sse-linearsearch.h"


bool verify(int size) {
    uint32vector_t data;

    data.resize(size);

    for (int i=0; i < size; i++) {
        data[i] = i;
    }

    LinearSearch        ls(data);
    SSELinearSearch     ls_sse(data);
    BinSearch           bs(data);
    BinSearchLinear     bs_lin(data);
    SSEBinSearch        bs_sse(data);
    SSEBinSearchBlock   bs_sse_block(data);

    for (int i=-100; i < size + 100; i++) {

        const auto reference  = ls.search(i);

        {   const auto result = ls_sse.search(i);
            if (result != reference) {
                printf("SSELinearSearch failed: expected %d, actual %d\n", reference, result);
                return false;
            }
        }

        {   const auto result = bs.search(i);
            if (result != reference) {
                printf("BinSearch failed: expected %d, actual %d\n", reference, result);
                return false;
            }
        }

        {   const auto result = bs_lin.search(i);
            if (result != reference) {
                printf("BinSearchLinear failed: expected %d, actual %d\n", reference, result);
                return false;
            }
        }

        {   const auto result = bs_sse.search(i);
            if (result != reference) {
                printf("SSEBinSearch failed: expected %d, actual %d\n", reference, result);
                return false;
            }
        }

        {   const auto result = bs_sse_block.search(i);
            if (result != reference) {
                printf("SSEBinSearchBlock failed: expected %d, actual %d\n", reference, result);
                return false;
            }
        }
    }

    return true;
}


int main() {

    std::vector<int> sizes = {
        3, 4, 5, 6, 7, 8, 9, 10,
        16,
        32,
        128,
        256,
    };

    for (int size: sizes) {
        if (!verify(size)) {
            printf("failed for input size = %d\n", size);
            return EXIT_FAILURE;
        }
    }

    puts("All OK");
    return EXIT_SUCCESS;
}


void print_help(const char* prog) {
    printf("%s size iteration_count\n", prog);
}
