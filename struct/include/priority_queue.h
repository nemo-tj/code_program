#pragma once

#include "typedef.h"

#include <vector>

namespace nemo {

  template <class T>
  class PQ {
    public:
      PQ(std::vector<T> &vec);
      ~PQ();

    public:
      void sort(std::vector<T> &vec) { sort(vec, vec.size()); }
      void sort(std::vector<T> &vec, uint64 N);
      void order();
      std::vector<T>& getPQ() { return pq; }

    public:
      bool isEmpty() { return 0 == N; }
      uint64 size() { return N; }
      void show();

      void insert(T key);
      T rmTop(); 

    private:
      void exch(std::vector<T> &vec, uint64 i, uint64 j);
      void swin(std::vector<T> &vec, uint64 k);
      void sink(std::vector<T> &vec, uint64 k, uint64 N);
      bool less(std::vector<T> &vec, uint64 i, uint64 j);

    private:
      std::vector<T> pq;
      uint64 N;
  };

} // end nemo namespace
