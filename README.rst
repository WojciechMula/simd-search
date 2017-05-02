========================================================================
    SIMD-ized searching in unique constant dictionary
========================================================================

Sample programs for article http://0x80.pl/articles/simd-search.html

Type ``make`` then ``./demo size iterations_count``. Parameters set
dictionary size and iteration count; program prints:

* size,
* execution time of following algorithms:

  * binary search,
  * linear search,
  * SIMD-ized binary search,
  * SIMD-ized linear search,
  * binary search with fallback to linear search,
  * binary search using SIMD-equal op around pivot.
