#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits.h>

template <class T>
void show_vec(const std::vector<T> &vec) {
  auto it = vec.begin();
  while (it != vec.end() ) {
    std::cout << *it << " ";
    ++it;
  }
  std::cout << std::endl;
}

template <class T>
void swap_val(T &a, T &b) {
  T t = a;
  a = b;
  b = t;
}
