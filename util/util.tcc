#pragma once

template <class T>
void display(const std::vector<T> &vec) {
  for (auto &it : vec) {
    std::cout << it << " ";
  }
  std::cout << std::endl;
}

template <class T>
void swap(std::vector<T> &vec, int i, int j) {
  T x = vec[i];
  vec[i] = vec[j];
  vec[j] = x;
}

void swap(std::string &str, int i, int j) {
  char x = str[i];
  str[i] = str[j];
  str[j] = x;
}
