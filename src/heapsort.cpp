#include "heapsort.hpp"
#include "utils.hpp"

static void fix_heap(std::vector<int> &input, int l, int r) {
  for (int i = l; i < r; i += i + 2) {
    int child1_idx = 2 * i;
    int child2_idx = child1_idx + 1;

    int min = input[i];
    int min_idx = i;
    if (child1_idx < r && input[child1_idx] < min) {
      min = input[child1_idx];
      min_idx = child1_idx;
    }
    if (child2_idx < r && input[child2_idx] < min) {
      min = input[child2_idx];
      min_idx = child2_idx;
    }

    if (i != min_idx) {
      swap(input[i], input[min_idx]);
    }
  }
}

void heap_sort(std::vector<int> &input) {
  int offset = 0;
  while (offset < input.size() - 2) {
    fix_heap(input, 1, input.size() - offset);
    swap(input[1], input[input.size() - 1 - offset]);
    offset++;
  }
}