#pragma once

#include "common.h"

namespace nemo {

  template <class T>
    class Alg {
      private:
        Alg() {};
        Alg(const Alg<T>& alg) {};
        Alg& operator=(const Alg<T> &alg) {};
        ~Alg() {}

      private:
        static Alg *alg;
      public:
        static Alg* getInstance();
        int binSearch(std::vector<T> &vec, int s, int e, T target); // [s, e)
        void shuffleVec(std::vector<T> &vec);
    };

  template <class T>
    Alg<T>* Alg<T>::alg = new Alg<T>();

  template <class T>
    Alg<T>* Alg<T>::getInstance() { return alg; }

} // end nemo namespace

#include "alg.tcc"
