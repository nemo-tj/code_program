#pragma once

#include "common.h"
#include "util.h"

void perm(std::string &str, int k) {
  if (k == str.size()) {
    std::cout << str << std::endl;
    return;
  }
  for (int i = k; i < str.size(); ++i) {
    if (i != k && str[i-1] == str[i]) continue; 
    swap(str, k, i);
    perm(str, k + 1);
    swap(str, k, i);
  }
}

void perm(std::string str) {
  perm(str, 0);
}

