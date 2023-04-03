#include "priority_queue.h"

namespace nemo {

  template <class T>
    PQ<T>::PQ(std::vector<T> &vec): N(0) {
      // build a heap with swin
      while (N < vec.size()) {
        insert(vec.at(N));
      }
    }

  template <class T>
    PQ<T>::~PQ() {
      std::cout << "destroying... ";
      while (N > 0) {
        std::cout << rmTop() << " ";
      }
      std::cout << std::endl;
    }

  template <class T>
    T PQ<T>::rmTop() {
      T top = pq[1];
      pq[1] = pq[N];
      sink(pq, 1, --N);
      return top;
    }

  template <class T>
    void PQ<T>::order() {
      // self sort
      if (N <= 1) return;
      pq.resize(N+1);
      while (N > 0) {
        exch(pq, 1, N--);
        sink(pq, 1, N);
      }
      N = pq.size() - 1;
    }

  template <class T>
    void PQ<T>::show() {
      for (uint64 i = 1; i <= N; ++i) {
        std::cout << pq[i] << " ";
      }
      std::cout << std::endl;
    }


  // v[1],v[2],v[3]...v[N]
  template <class T>
    void PQ<T>::sort(std::vector<T> &vec, uint64 N) {
      if (N <= 1) return;
      if (vec.size() >= N) vec.resize(1+N);
      vec[N] = vec[0]; vec[0] = 0;
      for (uint64 k = N / 2; k >= 1; --k) {
        sink(vec, k, N);
      }
      while (N > 1) {
        exch(vec, 1, N--);
        sink(vec, 1, N);
      }
    }

  template <class T>
    void PQ<T>::insert(T key) {
      if (1+N >= pq.size()) {
        pq.resize(2+2*N);
      }
      pq[++N] = key;
      swin(pq, N);
    }


  // private function

  template <class T>
    void PQ<T>::exch(std::vector<T> &vec, uint64 i, uint64 j) {
      T t = vec[i];
      vec[i] = vec[j];
      vec[j] = t;
    }

  template <class T>
    bool PQ<T>::less(std::vector<T> &vec, uint64 i, uint64 j) {
      return vec[i] < vec[j];
    }

  template <class T>
    void PQ<T>::swin(std::vector<T> &vec, uint64 k) {
      while (k > 1 && less(vec, k/2, k)) {
        exch(vec, k/2, k);
        k /= 2;
      }
    }

  template <class T>
    void PQ<T>::sink(std::vector<T> &vec, uint64 k, uint64 N) {
      while (2 * k <= N) {
        uint64 j = 2 * k;
        if (j < N && less(vec, j, j+1)) ++j;
        if (less(vec, j, k)) break;
        exch(vec, k, j);
        k = j;
      }
    }

  // ===============
  // instantialize: explicitly declare
  #define _EXPLICIT_DEFINE(CT) template class PQ<CT>
  _EXPLICIT_DEFINE(char);
  _EXPLICIT_DEFINE(int);
  _EXPLICIT_DEFINE(float);
  _EXPLICIT_DEFINE(double);
  #undef _EXPLICIT_DEFINE

} // end nemo namespace
