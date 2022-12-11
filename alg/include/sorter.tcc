#include "sorter.h"
#include "util.h"

namespace nemo {

  // BUB

  template <class T>
    void BubSorter<T>::sort(std::vector<T> &vec, int start, int end) {
      if (start >= end) return;
      for (int j = end - 1; j > start; --j) {
        for (int i = start; i < j; ++i) {
          if (vec[i] > vec[i+1]) {
            swap<T>(vec, i, i+1);
          }
        }
      }
    }


  // SELECTION

  template <class T>
    void SelectionSorter<T>::sort(std::vector<T> &vec, int start, int end) {
      for (int j = 0; j < end - 1; ++j) {
        T m = vec[j];
        int ix = j;
        for (int i = j + 1; i < end; ++i) {
          if (m > vec[i]) {
            ix = i;
            m = vec[ix];
          }
        }
        vec[ix] = vec[j];
        vec[j] = m;
      }
    }


  // INSERT

  template <class T>
    void InsertSorter<T>::sort(std::vector<T> &vec, int start, int end) {
      for (int i = start + 1; i < end; ++i) {
        T x = vec[i];
        int j = 0;
        while (vec[j] < x) {
          ++j;
        }
        for (int t = i; t > j; --t) {
          vec[t] = vec[t-1];
        }
        vec[j] = x;
      }
    }


  // QUICK

  template <class T>
    void QuickSorter<T>::sort(std::vector<T> &vec, int left, int right) {
      if (left >= right-1) return;
      int i = left, j = right-1;
      T v = vec[i];
      while (true) {
        while (vec[j] > v) {
          j--;
        }
        if (i >= j) break;
        vec[i] = vec[j];
        while (vec[i] <= v) {
          i++;
        }
        if (i >= j) break;
        vec[j] = vec[i];
      }
      vec[j] = v;
      sort(vec, left, j);
      sort(vec, j+1, right);
    }






} // end nemo namespace
