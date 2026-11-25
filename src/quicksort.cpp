#include "quicksort.hpp"
#include "utils.hpp"

template <typename T, std::random_access_iterator It>
It partition(std::vector<T> &input, It start, It end,
             std::type_identity_t<Comparator<T>> compare) {
  int l = std::distance(input.begin(), start);
  int r = std::distance(input.begin(), end) - 1;

  int key = (l + r) / 2;
  swap(*(end - 1), input[key]);
  T value = *(end - 1);

  int i = std::distance(input.begin(), start);
  int j = std::distance(input.begin(), end) - 2;
  while (true) {
    while (i < r && compare(input[i], value) <= 0)
      i++;
    while (j > l && compare(input[j], value) > 0)
      j--;

    if (i >= j) {
      break;
    }

    swap(input[i], input[j]);
  }

  swap(input[i], *(end - 1));

  return input.begin() + i;
}

template <typename T, std::random_access_iterator It>
void quick_sort(std::vector<T> &input, It start, It end,
                std::type_identity_t<Comparator<T>> compare) {
  if (end - start < 2) {
    return;
  }
  It res = partition(input, start, end, compare);
  quick_sort(input, start, res, compare);
  quick_sort(input, res + 1, end, compare);
}

template void quick_sort(std::vector<int> &, std::vector<int>::iterator,
                         std::vector<int>::iterator, Comparator<int>);