#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "heapsort.hpp"
#include "quicksort.hpp"
#include "utils.hpp"

#define RANDOM_SEED 10

void print_vect(std::vector<int> &vect) {
  for (auto el : vect) {
    std::cout << el << ' ';
  }
  std::cout << std::endl << std::endl;
}

std::vector<int> gen_vector(int n) {
  static std::mt19937 rng(RANDOM_SEED); // seeded once
  std::uniform_int_distribution<int> dist(0, 99);

  std::vector<int> items(n);
  std::generate(items.begin(), items.end(), [&] { return dist(rng); });

  return items;
}

void selection_sort(std::vector<int> &input, int l, int r) {
  if ((size_t)l > input.size() - 1 || (size_t)r > input.size() || l > r) {
    std::cout << "Invalid selection arguments" << std::endl;
    return;
  }

  for (int i = l; i <= r; i++) {
    int min = i;
    for (int j = i + 1; j < r; j++) {
      if (input[j] < input[min]) {
        min = j;
      }
    }
    swap(input[i], input[min]);
  }
}

void insertion_sort(std::vector<int> &input, int l, int r) {
  if ((size_t)l > input.size() - 1 || (size_t)r > input.size() || l > r) {
    std::cout << "Invalid selection arguments" << std::endl;
    return;
  }

  for (int i = l + 1; i <= r; i++) {
    int curr = input[i];
    int j;
    for (j = i - 1; j >= l; j--) {
      if (curr < input[j]) {
        input[j + 1] = input[j];
      } else {
        break;
      }
    }

    input[j + 1] = curr;
  }
}

template <typename T, typename Compare, std::input_iterator It>
void insertion_sort(std::vector<T> &input, It start, It end, Compare compare) {
  int l = std::distance(input.begin(), start);
  int r = std::distance(input.begin(), end);

  for (int i = l + 1; i <= r; i++) {
    int curr = input[i];
    int j;
    for (j = i - 1; j >= l; j--) {
      if (compare(curr, input[j]) < 0) {
        input[j + 1] = input[j];
      } else {
        break;
      }
    }

    input[j + 1] = curr;
  }
}

void bubble_sort(std::vector<int> &input, int l, int r) {
  for (int i = l; i <= r; i++) {
    for (int j = r - 1; j > i; j--) {
      if (input[j] < input[j - 1]) {
        swap(input[j], input[j - 1]);
      }
    }
  }
}

int main(void) {
  auto items = gen_vector(10);
  print_vect(items);

  auto items1 = items;
  selection_sort(items1, 0, items1.size() - 1);
  print_vect(items1);

  auto items2 = items;
  insertion_sort(items2, 0, items2.size() - 1);
  print_vect(items2);

  auto items3 = items;
  bubble_sort(items3, 0, items3.size() - 1);
  print_vect(items3);

  auto items4 = items;
  quick_sort(items4, items4.begin(), items4.end(), [](auto a, auto &b) {
    if (a == b)
      return 0;
    if (a < b)
      return -1;
    return 1;
  });
  print_vect(items4);
}