#include "util.h"

#include "alg.h"

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
        swap<T>(vec, j, ix);
      }
    }


  // INSERT

  template <class T>
    void InsertSorter<T>::sortV1(std::vector<T> &vec, int start, int end) {
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

  template <class T>
    void InsertSorter<T>::sort(std::vector<T> &vec, int start, int end) {
      Alg<T> *alg = Alg<T>::getInstance();
      for (int i = start + 1; i < end; ++i) {
        T v = vec[i];
        int j = alg->binSearch(vec, 0, i, v);
        for (int k = i; k > j; k--) {
          vec[k] = vec[k-1];
        }
        vec[j] = v;
      }
    }


  // QUICK

  template <class T>
    void QuickSorter<T>::sort(std::vector<T> &vec, int left, int right) {
      if (left >= right-1) return;
      int i = left, j = right;
      T v = vec[i];
      while (true) {
        while (vec[++i] <= v) if (i >= right-1) break;
        while (vec[--j] > v);
        if (i >= j) break;
        swap(vec, i, j);
      }
      swap(vec, left, j);
      sort(vec, left, j);
      sort(vec, j+1, right);
    }

  template <class T>
    void QuickSorter<T>::sortV1(std::vector<T> &vec, int left, int right) {
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


  // Heap

  template <class T>
    bool HeapSorter<T>::less(T &a, T &b) {
      return a < b;
    }

  template <class T>
    void HeapSorter<T>::exch(std::vector<T> &vec, int i, int j) {
      T t = vec[i];
      vec[i] = vec[j];
      vec[j] = t;
    }

  template <class T>
    void HeapSorter<T>::swin(std::vector<T> &vec, int s, int k) {
      int p = (k-1) / 2;
      while (k > 0 && less(vec[s + p], vec[s + k])) {
        exch(vec, s + p, s + k);
        k = p;
        p = (k-1) / 2;
      }
    }

  template <class T>
    void HeapSorter<T>::sink(std::vector<T> &vec, int s, int k, int N) {
      // k => 2k+1, 2k+2;
      int p = 2 * k + 1;
      while (s + p <= N) {
       if (s+p < N && less(vec[s+p], vec[s+p+1])) p++;
       if (less(vec[s+p], vec[s+k])) break;
       exch(vec, s+k, s+p);
       k = p;
       p = 2 * k + 1;
      }
      // swin(vec, s, k); 
    }

  template <class T>
    void HeapSorter<T>::sort(std::vector<T> &vec, int start, int end) {
      int sz = end - start;
      int N  = end - 1;
      for (int k = sz / 2; k >= 0; --k) {
        sink(vec, start, k, N);
      }
      while (N > start) {
        exch(vec, start, N--);
        sink(vec, start, 0, N);
      }
    }


} // end nemo namespace
