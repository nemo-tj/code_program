#pragma once
#include "comp/common.h"

namespace nemo {
  template <class T>
  class Func{
    public:
      void permute(std::vector<T> &vec, int k, int m); 
      int q(int n, int m); 
      int binarySearch(const std::vector<T> &vec, const T &t);
      std::vector<int> boundSearch(const std::vector<T> &vec, const T &t);
      double myPow(const T &x, int n);
      int sqrt(const int &n);
    public:
      void display();
    private:
      std::vector<std::vector<T> > p_results;

  }; // class Func
}
