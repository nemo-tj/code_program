#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>

#include <iostream>
#include <sstream>

namespace nemo {

  typedef long unsigned long uint64;

  typedef long unsigned int uint32;
  typedef unsigned long uint32;

  typedef unsigned int uint;

	template <class T>
		std::string to_string(T val) {
			std::stringstream ss;
			ss.str(" ");
			ss << val;
			return ss.str();
		}
  
#define LINE (std::cout << "\n---------------------" << std::endl);
#define INFO(x)(std::cout << "\n===== " << x << " =====" << std::endl);

}
