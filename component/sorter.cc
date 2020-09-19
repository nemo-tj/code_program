#include "component/sorter.h"

namespace nemo {

  template <class T>
  void Sorter<T>::bub_sort(std::vector<T> &vec) {
    for (int i = vec.size() -1; i > 0; --i) {
      for (int j = 0; j < i; ++j) {
        if (vec[j] > vec[j+1]) swap_val(vec[j], vec[j+1]);
      }
    }
  }

  template <class T>
  void Sorter<T>::merge_sort(std::vector<T> &vec) {
    int step = 1;
    int max_step =  (1+vec.size()) / 2 + 1;
    while (step < max_step) {
      for (int i = 0; i + step < vec.size(); i+= 2 * step) {
        std::vector<T> a1(vec.begin() + i, vec.begin() + i + step);
        int max_len = std::min(i + 2 * step, (int)vec.size());
        std::vector<T> a2(vec.begin() + i + step, vec.begin() + max_len);
        m_merge(a1, a2, vec, i);
      }
      std::cout << "step:" << step << std::endl;
      show_vec(vec);
      step *= 2;
    }
  }

  template <class T>
  void Sorter<T>::m_merge(const std::vector<T> &v1, const std::vector<T> &v2, std::vector<T> &vec, int pos) {
    auto t1 = v1.begin();
    auto t2 = v2.begin();
    while (t1 != v1.end() && t2 != v2.end()) {
     if (*t1 < *t2) {
       vec[pos++] = (*t1);
       ++t1;
     } else {
       vec[pos++] = (*t2);
       ++t2;
     }
    }
    while (t1 != v1.end()) {
      vec[pos++] = *t1;
      ++t1;
    }
    while (t2 != v2.end()) {
      vec[pos++] = (*t2);
      ++t2;
    }
  }

  template <class T>
  void Sorter<T>::quick_sort(std::vector<T> &vec) {
    m_qsort(vec, 0, vec.size() -1);
  }
  
  template <class T>
  void Sorter<T>::m_qsort(std::vector<T> &vec, int s, int e) {
    if (s >= e) return;
    int i = s, j = e;
    int v = vec[i];
    while (i < j) {
      while (i < j && vec[j] > v) { --j;}
      if (i < j) vec[i] = vec[j];
      while (i < j && vec[i] <= v) { ++i;}
      if (i < j) vec[j] = vec[i];
    }
    vec[i] = v; // get the position of v;
    m_qsort(vec, s, i-1);
    m_qsort(vec, i+1, e);
  }

  // ===============
  // instantialize: explicitly declare
  #define _EXPLICIT_DEFINE(CT) template class Sorter<CT>
  _EXPLICIT_DEFINE(char);
  _EXPLICIT_DEFINE(int);
  _EXPLICIT_DEFINE(float);
  _EXPLICIT_DEFINE(double);
  #undef _EXPLICIT_DEFINE
}

