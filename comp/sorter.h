#pragma once
#include "comp/common.h"

namespace nemo {
  template <class T>
  class Sorter{
    public:
      void bub_sort(std::vector<T> &vec);
      void quick_sort(std::vector<T> &vec);
      void merge_sort(std::vector<T> &vec);
    private:
      void m_qsort(std::vector<T> &vec, int s, int e);
      void m_merge(const std::vector<T> &v1, const std::vector<T> &v2, std::vector<T> &vec, int pos);

  };

}
