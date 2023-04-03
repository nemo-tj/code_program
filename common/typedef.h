#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>

#include <iostream>

namespace nemo {

  typedef long unsigned long uint64;

  typedef long unsigned int uint32;
  typedef unsigned long uint32;

  typedef unsigned int uint;
  
#define LINE (std::cout << "\n---------------------" << std::endl);
#define INFO(x)(std::cout << "\n===== " << x << " =====" << std::endl);

}
