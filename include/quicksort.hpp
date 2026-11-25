#ifndef INCLUDE_QUICKSORT
#define INCLUDE_QUICKSORT

#include <vector>

template <typename T> using Comparator = int (*)(const T &a, const T &b);

template <typename T, std::random_access_iterator It>
void quick_sort(std::vector<T> &input, It start, It end,
                std::type_identity_t<Comparator<T>> compare);

#endif /* INCLUDE_QUICKSORT */
